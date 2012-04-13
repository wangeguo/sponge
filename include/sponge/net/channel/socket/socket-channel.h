// Copyright (c) 2012 The Sponge Authors. All rights reserved.
// Use of this source code is governed by a MIT-style license that can
// be found in the LICENSE file. See the AUTHORS file for names of contributors.

#ifndef SPONGE_NET_CHANNEL_SOCKET_SOCKET_CHANNEL_H_
#define SPONGE_NET_CHANNEL_SOCKET_SOCKET_CHANNEL_H_

#include <string>

namespace sponge {
namespace net {
namespace channel {

// Forward decleations.
class Channel;

namespace socket {

class SocketChannelConfig;

class SocketChannel : public Channel {
  public:
    virtual SocketChannelConfig* GetConfig() = 0;
    virtual std::string GetLocalAddress() = 0;
    virtual std::string GetRemoteAddress() = 0;
};

} } } } // namespace sponge::net::channel::socket

#endif // SPONGE_NET_CHANNEL_SOCKET_SOCKET_CHANNEL_H_
