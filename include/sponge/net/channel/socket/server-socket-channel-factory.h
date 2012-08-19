// Copyright (c) 2012 The Sponge Authors. All rights reserved.
// Use of this source code is governed by a MIT-style license that can
// be found in the LICENSE file. See the AUTHORS file for names of contributors.

#ifndef SPONGE_NET_CHANNEL_SOCKET_SERVER_SOCKET_CHANNEL_FACTORY_H_
#define SPONGE_NET_CHANNEL_SOCKET_SERVER_SOCKET_CHANNEL_FACTORY_H_

namespace sponge {
namespace net {

// Forward declarations.
class ChannelPipeline;
class ServerChannelFactory;
class ServerSocketChannel;

// A channelFactory which creates a ServerSocketChannel.
class ServerSocketChannelFactory : public ServerChannelFactory {
  public:
    virtual ServerSocketChannel* NewChannel(const ChannelPipeline *pipeline) = 0;
};

} } // namespace sponge::net

#endif // SPONGE_NET_CHANNEL_SOCKET_SERVER_SOCKET_CHANNEL_FACTORY_H_
