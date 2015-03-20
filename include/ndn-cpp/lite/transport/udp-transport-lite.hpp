/* -*- Mode:C++; c-file-style:"gnu"; indent-tabs-mode:nil -*- */
/**
 * Copyright (C) 2015 Regents of the University of California.
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

#ifndef NDN_UDP_TRANSPORT_LITE_HPP
#define NDN_UDP_TRANSPORT_LITE_HPP

#include "../../c/errors.h"
#include "../../c/transport/transport-types.h"

namespace ndn {

class UdpTransportLite : private ndn_UdpTransport {
public:
  /**
   * Create an UdpTransport with default values for no connection yet and to use
   * the given buffer for the ElementReader. Note that the ElementReader is not
   * valid until you call connect.
   * @param buffer A pointer to a ndn_DynamicUInt8Array struct which is used to
   * save data before calling the elementListener (see connect).
   * The struct must remain valid during the entire life of this object.
   * If the buffer->realloc function pointer is 0, its array must be large
   * enough to save a full element, perhaps MAX_NDN_PACKET_SIZE bytes.
   */
  UdpTransportLite(struct ndn_DynamicUInt8Array *buffer);

  /**
   * Connect with UDP to the host:port.
   * @param host The host to connect to.
   * @param port The port to connect to.
   * @param elementListener The ElementListener used by processEvents, which
   * remain valid during the life of this object or until replaced by the next
   * call to connect.
   * @return 0 for success, else an error code.
   */
  ndn_Error
  connect(char* host, unsigned short port, ndn_ElementListener& elementListener);

  /**
   * Send data to the socket.
   * @param data A pointer to the buffer of data to send.
   * @param dataLength The number of bytes in data.
   * @return 0 for success, else an error code.
   */
  ndn_Error
  send(const uint8_t* data, size_t dataLength);

  /**
   * Close the socket.
   * @return 0 for success, else an error code.
   */
  ndn_Error
  close();

  /**
   * Upcast the reference to the ndn_UdpTransport struct to a UdpTransportLite.
   * @param transport A reference to the ndn_UdpTransport struct.
   * @return The same reference as UdpTransportLite.
   */
  static UdpTransportLite&
  upCast(ndn_UdpTransport& transport) { return *(UdpTransportLite*)&transport; }

  static const UdpTransportLite&
  upCast(const ndn_UdpTransport& transport) { return *(UdpTransportLite*)&transport; }
};

}

#endif
