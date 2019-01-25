/* -*- Mode:C++; c-file-style:"gnu"; indent-tabs-mode:nil -*- */
/**
 * Copyright (C) 2018-2019 Regents of the University of California.
 * @author: Jeff Thompson <jefft0@remap.ucla.edu>
 * @author: From ndn-cxx security https://github.com/named-data/ndn-cxx/blob/master/ndn-cxx/security/command-interest-signer.cpp
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

#include <ndn-cpp/security/command-interest-signer.hpp>

using namespace std;

namespace ndn {

CommandInterestSigner::CommandInterestSigner(KeyChain& keyChain)
: keyChain_(keyChain)
{}

ptr_lib::shared_ptr<Interest>
CommandInterestSigner::makeCommandInterest
  (const Name& name, const SigningInfo& params, WireFormat& wireFormat)
{
  // This copies the Name.
  ptr_lib::shared_ptr<Interest> commandInterest(new Interest(name));

  prepareCommandInterestName(*commandInterest, wireFormat);
  keyChain_.sign(*commandInterest, params, wireFormat);

  return commandInterest;
}

}
