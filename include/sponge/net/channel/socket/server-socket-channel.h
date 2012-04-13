// Copyright (c) 2012 The Sponge Authors. All rights reserved.
// Use of this source code is governed by a MIT-style license that can
// be found in the LICENSE file. See the AUTHORS file for names of contributors.

#ifndef SPONGE_NET_CHANNEL_SOCKET_SERVER_SOCKET_CHANNEL_H_
#define SPONGE_NET_CHANNEL_SOCKET_SERVER_SOCKET_CHANNEL_H_

#include <string>
#include "sponge/net/channel/server-channel.h"

namespace sponge {
namespace net {
namespace channel {
namespace socket {

// Forward declarations.
class ServerSocketChannelConfig;

// A TCP/IP ServerChannel wich accepts incoming TCP/IP connections
class ServerSocketChannel : public ServerChannel {
  public:
    virtual ServerSocketChannelConfig GetConfig() = 0;
    virtual std::string GetLocalAddress() = 0;
    virtual std::string GetRemoteAddress() = 0;
};

} } } } // namespace sponge::net::channel::socket

#endif // SPONGE_NET_CHANNEL_SOCKET_SERVER_SOCEKT_CHANNEL_H_
