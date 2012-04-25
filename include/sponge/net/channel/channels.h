// Copyright (c) 2012 The Sponge Authors. All rights reserved.
// Use of this source code is governed by a MIT-style license that can
// be found in the LICENSE file. See the AUTHORS file for names of contributors.

#ifndef SPONGE_NET_CHANNEL_CHANNELS_H_
#define SPONGE_NET_CHANNEL_CHANNELS_H_


namespace sponge {
namespace net {
namespace channel {

// Fowrard declarations
class ChannelPipeline;
class DefaultChannelPipeline;

// A helper class which provides various convenience methods related
// with Channel, ChannelHandler, and ChannelPipeline.
class Channels {
  public:
    // pipeline factory methods

    // Creates a new ChannelPipeline
    inline static ChannelPipeline* Pipeline() {
        return new DefaultChannelPipeline();
    }

    // @TODO Channels other methods
};

} } } // namespace sponge::net::channel

#endif // SPONGE_NET_CHANNEL_CHANNELS_H_
