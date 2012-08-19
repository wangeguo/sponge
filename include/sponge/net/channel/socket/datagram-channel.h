// Copyright (c) 2012 The Sponge Authors. All rights reserved.
// Use of this source code is governed by a MIT-style license that can
// be found in the LICENSE file. See the AUTHORS file for names of contributors.

#ifndef SPONGE_NET_CHANNEL_SOCKET_DATAGRAM_CHANNEL_H_
#define SPONGE_NET_CHANNEL_SOCKET_DATAGRAM_CHANNEL_H_

#include <string>

namespace sponge {
namespace net {

// Forward declaratioins
class DatagramChannelConfig;

// A UPD/IP channel which is created by DatagramChannelFactory
class DatagramChannel : public Channel {
  public:
    virtual DatagramChannelConfig* GetConfig() = 0;
    virtual std::string GetLocalAddress() = 0;
    virtual std::string GetRemoteAddress() = 0;

    // Joins a multicast group.
    virtual void JoinGroup(const std::string &multicast_address) = 0;
    virtual void JoinGroup(const std::string &multicast_address, void* network_interface) = 0;
    // Leaves a multicast group
    virtual void LeaveGroup(const std::string &multicast_address) = 0;
    virtual void LeaveGroup(const std::string &multicast_address, void* network_interface) = 0;
};

} } // namespace sponge::net

#endif // SPONGE_NET_CHANNEL_SOCKET_DATAGRAM_CHANNEL_H_
