// Copyright (c) 2012 The Sponge Authors. All rights reserved.
// Use of this source code is governed by a MIT-style license that can
// be found in the LICENSE file. See the AUTHORS file for names of contributors.

#ifndef SPONGE_NET_CHANNEL_CHANNEL_EVENT_H_
#define SPONGE_NET_CHANNEL_CHANNEL_EVENT_H_

namespace sponge {
namespace net {
namespace channel {

// Forward declarations.
class Channel;
class ChannelFuture;

// An I/O event or I/O request associated with a Channel.  A
// ChannelEvent is handled by a series of ChannelHandlers in a
// ChannelPipeline.
class ChannelEvent {
  public:
    // Returns the Channel which is associated with this event.
    virtual *Channel GetChannel() = 0;

    // Returns the ChannelFuture which is associated with this
    // event. If this event is an upstream event, this method will
    // always return a SucceededChannelFuture because the event has
    // occurred already. If this event is a downstream event (i.e. I/O
    // request), the returned future will be notified when the I/O
    // request succeeds or fails.
    virtual ChannelFuture GetFuture() = 0;
};

} } } // namespace sponge::net::channel

#endif // SPONGE_NET_CHANNEL_CHANNEL_EVENT_H_
