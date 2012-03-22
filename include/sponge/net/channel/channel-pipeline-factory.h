// Copyright (c) 2012 The Sponge Authors. All rights reserved.
// Use of this source code is governed by a MIT-style license that can
// be found in the LICENSE file. See the AUTHORS file for names of contributors.

#ifndef SPONGE_NET_CHANNEL_CHANNEL_PIPELINE_FACTORY_H_
#define SPONGE_NET_CHANNEL_CHANNEL_PIPELINE_FACTORY_H_

namespace sponge {
namespace net {
namespace channel {

// Forward declarations.
class Channel;
class ChannelHandler;
class ChannelPipeline;

// Creates a new ChannelPipeline for a new Channel.
class ChannelPipelineFactory {
  public:
    // Returns a newly created ChannelPipeline.
    virtual ChannelPipeline GetPipeline() = 0;
};

} } } // namespace sponge::net::channel

#endif // SPONGE_NET_CHANNEL_CHANNEL_PIPELINE_FACTORY_H_
