// Copyright (c) 2012 The Sponge Authors. All rights reserved.
// Use of this source code is governed by a MIT-style license that can
// be found in the LICENSE file. See the AUTHORS file for names of contributors.

#ifndef SPONGE_NET_CHANNEL_CHANNEL_UPSTREAM_HANDLER_H_
#define SPONGE_NET_CHANNEL_CHANNEL_UPSTREAM_HANDLER_H_

#include "sponge/net/channel/channel-handler.h"

namespace sponge {
namespace net {
namespace channel {

// Forward declaration
class ChannelHandlerContext;
class ChannelEvent;

// Handles or intercepts an upstream ChannelEvent, and sends a
// ChannelEvent} to the next handler in a ChannelPipeline.
class ChannelUpstreamHandler : public ChannelHandler {
  public:
    // Handles the specified upstream event.
    virtual void HandleUpstream(const ChannelHandlerContext *ctx,
                                const ChannelEvent *e);
};

} } } // namespace sponge::net::channel

#endif // SPONGE_NET_CHANNEL_CHANNEL_UPSTREAM_HANDLER_H_
