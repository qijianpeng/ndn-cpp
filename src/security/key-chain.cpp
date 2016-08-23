/* -*- Mode:C++; c-file-style:"gnu"; indent-tabs-mode:nil -*- */
/**
 * Copyright (C) 2013-2016 Regents of the University of California.
 * @author: Yingdi Yu <yingdi@cs.ucla.edu>
 * @author: Jeff Thompson <jefft0@remap.ucla.edu>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version, with the additional exemption that
 * compiling, linking, and/or using OpenSSL is allowed.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 * A copy of the GNU Lesser General Public License is in the file COPYING.
 */

#include "../util/logging.hpp"
#include <ndn-cpp/lite/util/crypto-lite.hpp>
#include <ndn-cpp/lite/util/crypto-lite.hpp>
#include <ndn-cpp/security/security-exception.hpp>
#include <ndn-cpp/security/policy/policy-manager.hpp>
#include <ndn-cpp/security/policy/no-verify-policy-manager.hpp>
#include <ndn-cpp/sha256-with-rsa-signature.hpp>
#include <ndn-cpp/hmac-with-sha256-signature.hpp>
#include <ndn-cpp/security/key-chain.hpp>

INIT_LOGGER("ndn.KeyChain");

using namespace std;
using namespace ndn::func_lib;

namespace ndn {

const RsaKeyParams KeyChain::DEFAULT_KEY_PARAMS;

KeyChain::KeyChain
  (const ptr_lib::shared_ptr<IdentityManager>& identityManager,
   const ptr_lib::shared_ptr<PolicyManager>& policyManager)
: identityManager_(identityManager), policyManager_(policyManager),
  face_(0)
{
}

KeyChain::KeyChain(const ptr_lib::shared_ptr<IdentityManager>& identityManager)
: identityManager_(identityManager),
  policyManager_(ptr_lib::make_shared<NoVerifyPolicyManager>()),
  face_(0)
{
}

KeyChain::KeyChain()
: identityManager_(ptr_lib::make_shared<IdentityManager>()),
  policyManager_(ptr_lib::make_shared<NoVerifyPolicyManager>()),
  face_(0)
{
}

void
KeyChain::signByIdentity(Data& data, const Name& identityName, WireFormat& wireFormat)
{
  Name signingCertificateName;

  if (identityName.size() == 0) {
    Name inferredIdentity = policyManager_->inferSigningIdentity(data.getName());
    if (inferredIdentity.size() == 0)
      signingCertificateName = identityManager_->getDefaultCertificateName();
    else
      signingCertificateName = identityManager_->getDefaultCertificateNameForIdentity(inferredIdentity);
  }
  else
    signingCertificateName = identityManager_->getDefaultCertificateNameForIdentity(identityName);

  if (signingCertificateName.size() == 0)
    throw SecurityException("No qualified certificate name found!");

  if (!policyManager_->checkSigningPolicy(data.getName(), signingCertificateName))
    throw SecurityException("Signing Cert name does not comply with signing policy");

  identityManager_->signByCertificate(data, signingCertificateName, wireFormat);
}

ptr_lib::shared_ptr<Signature>
KeyChain::signByIdentity(const uint8_t* buffer, size_t bufferLength, const Name& identityName)
{
  Name signingCertificateName = identityManager_->getDefaultCertificateNameForIdentity(identityName);

  if (signingCertificateName.size() == 0)
    throw SecurityException("No qualified certificate name found!");

  return identityManager_->signByCertificate(buffer, bufferLength, signingCertificateName);
}

void
KeyChain::verifyData
  (const ptr_lib::shared_ptr<Data>& data, const OnVerified& onVerified, const OnVerifyFailed& onVerifyFailed, int stepCount)
{
  _LOG_TRACE("Enter Verify");

  if (policyManager_->requireVerify(*data)) {
    ptr_lib::shared_ptr<ValidationRequest> nextStep = policyManager_->checkVerificationPolicy
      (data, stepCount, onVerified, onVerifyFailed);
    if (nextStep)
      face_->expressInterest
        (*nextStep->interest_,
         bind(&KeyChain::onCertificateData, this, _1, _2, nextStep),
         bind(&KeyChain::onCertificateInterestTimeout, this, _1, nextStep->retry_, onVerifyFailed, data, nextStep));
  }
  else if (policyManager_->skipVerifyAndTrust(*data)) {
    try {
      onVerified(data);
    } catch (const std::exception& ex) {
      _LOG_ERROR("KeyChain::verifyData: Error in onVerified: " << ex.what());
    } catch (...) {
      _LOG_ERROR("KeyChain::verifyData: Error in onVerified.");
    }
  }
  else {
    try {
      onVerifyFailed(data);
    } catch (const std::exception& ex) {
      _LOG_ERROR("KeyChain::verifyData: Error in onVerifyFailed: " << ex.what());
    } catch (...) {
      _LOG_ERROR("KeyChain::verifyData: Error in onVerifyFailed.");
    }
  }
}

void
KeyChain::verifyInterest
  (const ptr_lib::shared_ptr<Interest>& interest,
   const OnVerifiedInterest& onVerified,
   const OnVerifyInterestFailed& onVerifyFailed, int stepCount,
   WireFormat& wireFormat)
{
  _LOG_TRACE("Enter Verify");

  if (policyManager_->requireVerify(*interest)) {
    ptr_lib::shared_ptr<ValidationRequest> nextStep =
      policyManager_->checkVerificationPolicy
        (interest, stepCount, onVerified, onVerifyFailed, wireFormat);
    if (nextStep)
      face_->expressInterest
        (*nextStep->interest_,
         bind(&KeyChain::onCertificateData, this, _1, _2, nextStep),
         bind(&KeyChain::onCertificateInterestTimeoutForVerifyInterest, this,
              _1, nextStep->retry_, onVerifyFailed, interest, nextStep));
  }
  else if (policyManager_->skipVerifyAndTrust(*interest)) {
    try {
      onVerified(interest);
    } catch (const std::exception& ex) {
      _LOG_ERROR("KeyChain::verifyInterest: Error in onVerified: " << ex.what());
    } catch (...) {
      _LOG_ERROR("KeyChain::verifyInterest: Error in onVerified.");
    }
  }
  else {
    try {
      onVerifyFailed(interest);
    } catch (const std::exception& ex) {
      _LOG_ERROR("KeyChain::verifyInterest: Error in onVerifyFailed: " << ex.what());
    } catch (...) {
      _LOG_ERROR("KeyChain::verifyInterest: Error in onVerifyFailed.");
    }
  }
}

#if NDN_CPP_HAVE_LIBCRYPTO
void
KeyChain::signWithHmacWithSha256
  (Data& data, const Blob& key, WireFormat& wireFormat)
{
  // Encode once to get the signed portion.
  SignedBlob encoding = data.wireEncode(wireFormat);

  ptr_lib::shared_ptr<vector<uint8_t>> signatureBits
    (new vector<uint8_t>(ndn_SHA256_DIGEST_SIZE));
  CryptoLite::computeHmacWithSha256
    (key, encoding.getSignedPortionBlobLite(), &signatureBits->front());
  data.getSignature()->setSignature(Blob(signatureBits, false));

  // Encode again to include the signature.
  data.wireEncode(wireFormat);
}

bool
KeyChain::verifyDataWithHmacWithSha256
  (const Data& data, const Blob& key, WireFormat& wireFormat)
{
  // wireEncode returns the cached encoding if available.
  SignedBlob encoding = data.wireEncode(wireFormat);

  vector<uint8_t> newSignatureBits(ndn_SHA256_DIGEST_SIZE);
  CryptoLite::computeHmacWithSha256
    (key, encoding.getSignedPortionBlobLite(), &newSignatureBits.front());

  // Use the vector equals operator.
  return newSignatureBits == *data.getSignature()->getSignature();
}
#endif

void
KeyChain::onCertificateData(const ptr_lib::shared_ptr<const Interest> &interest, const ptr_lib::shared_ptr<Data> &data, ptr_lib::shared_ptr<ValidationRequest> nextStep)
{
  // Try to verify the certificate (data) according to the parameters in nextStep.
  verifyData(data, nextStep->onVerified_, nextStep->onVerifyFailed_, nextStep->stepCount_);
}

void
KeyChain::onCertificateInterestTimeout
  (const ptr_lib::shared_ptr<const Interest> &interest, int retry, const OnVerifyFailed& onVerifyFailed, const ptr_lib::shared_ptr<Data> &data,
   ptr_lib::shared_ptr<ValidationRequest> nextStep)
{
  if (retry > 0)
    // Issue the same expressInterest as in verifyData except decrement retry.
    face_->expressInterest
      (*interest,
       bind(&KeyChain::onCertificateData, this, _1, _2, nextStep),
       bind(&KeyChain::onCertificateInterestTimeout, this, _1, retry - 1, onVerifyFailed, data, nextStep));
  else {
    try {
      onVerifyFailed(data);
    } catch (const std::exception& ex) {
      _LOG_ERROR("KeyChain::onCertificateInterestTimeout: Error in onVerifyFailed: " << ex.what());
    } catch (...) {
      _LOG_ERROR("KeyChain::onCertificateInterestTimeout: Error in onVerifyFailed.");
    }
  }
}

void
KeyChain::onCertificateInterestTimeoutForVerifyInterest
  (const ptr_lib::shared_ptr<const Interest> &interest, int retry,
   const OnVerifyInterestFailed& onVerifyFailed,
   const ptr_lib::shared_ptr<Interest>& originalInterest,
   ptr_lib::shared_ptr<ValidationRequest> nextStep)
{
  if (retry > 0)
    // Issue the same expressInterest as in verifyInterest except decrement retry.
    face_->expressInterest
      (*interest,
       bind(&KeyChain::onCertificateData, this, _1, _2, nextStep),
       bind(&KeyChain::onCertificateInterestTimeoutForVerifyInterest, this,
            _1, retry - 1, onVerifyFailed, originalInterest, nextStep));
  else {
    try {
      onVerifyFailed(originalInterest);
    } catch (const std::exception& ex) {
      _LOG_ERROR("KeyChain::onCertificateInterestTimeoutForVerifyInterest: Error in onVerifyFailed: " << ex.what());
    } catch (...) {
      _LOG_ERROR("KeyChain::onCertificateInterestTimeoutForVerifyInterest: Error in onVerifyFailed.");
    }
  }
}

Name
KeyChain::prepareDefaultCertificateName()
{
  ptr_lib::shared_ptr<IdentityCertificate> signingCertificate =
    identityManager_->getDefaultCertificate();
  if (!signingCertificate) {
    setDefaultCertificate();
    signingCertificate = identityManager_->getDefaultCertificate();
  }

  return signingCertificate->getName();
}

void
KeyChain::setDefaultCertificate()
{
  if (!identityManager_->getDefaultCertificate()) {
    Name defaultIdentity;
    try {
      defaultIdentity = identityManager_->getDefaultIdentity();
    } catch (SecurityException&) {
      // Create a default identity name.
      uint8_t randomComponent[4];
      ndn_Error error;
      if ((error = CryptoLite::generateRandomBytes
           (randomComponent, sizeof(randomComponent))))
        throw runtime_error(ndn_getErrorString(error));
      defaultIdentity = Name();
      defaultIdentity.append("tmp-identity")
        .append(Blob(randomComponent, sizeof(randomComponent)));
    }

    createIdentityAndCertificate(defaultIdentity);
    identityManager_->setDefaultIdentity(defaultIdentity);
  }
}

}
