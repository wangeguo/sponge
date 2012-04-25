// Copyright (c) 2012 The Sponge Authors. All rights reserved.
// Use of this source code is governed by a MIT-style license that can
// be found in the LICENSE file. See the AUTHORS file for names of contributors.

#ifndef SPONGE_NET_CHANNEL_SERVER_CHANNEL_FACTORY_H_
#define SPONGE_NET_CHANNEL_SERVER_CHANNEL_FACTORY_H_

#include "sponge/net/channel/channel-factory.h"

namespace sponge {
namespace net {
namespace channel {

// Forward declarations.
class ChannelPipeline;
class ServerChannel;

// A ChannelFactory that creates a ServerChannel
class ServerChannelFactory : public ChannelFactory {
  public:
    virtual ServerChannel* NewChannel(const ChannelPipeline *pipeline) = 0;
};

} } } // namespace sponge::net::channel

#endif // SPONGE_NET_CHANNEL_SERVER_CHANNEL_FACTORY_H_
