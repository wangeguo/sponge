// Copyright (c) 2012 The Sponge Authors. All rights reserved.
// Use of this source code is governed by a MIT-style license that can
// be found in the LICENSE file. See the AUTHORS file for names of contributors.

#ifndef SPONGE_NET_CHANNEL_SOCKET_CLIENT_SOCKET_CHANNEL_FACTORY_H_
#define SPONGE_NET_CHANNEL_SOCKET_CLIENT_SOCKET_CHANNEL_FACTORY_H_

#include "sponge/net/channel/channel-factory.h"

namespace sponge {
namespace net {
namespace channel {
namespace socket {

// Forward declarations
class SocketChannel;
class ChannelPipeline;

// A ChannelFactory which creates a client-side SocketChannel.
class ClientSocketChannelFactory : public ChannelFactory {
  public:
    virtual SocketChannel* NewChannel(const ChannelPipeline *pipeline);
};

} } } } // namespace sponge::net::channel::socket

#endif // SPONGE_NET_CHANNEL_SOCKET_CLIENT_SOCKET_CHANNEL_FACTORY_H_
