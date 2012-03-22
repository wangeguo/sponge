// Copyright (c) 2012 The Sponge Authors. All rights reserved.
// Use of this source code is governed by a MIT-style license that can
// be found in the LICENSE file. See the AUTHORS file for names of contributors.

#ifndef SPONGE_NET_CHANNEL_SIMPLE_CHANNEL_UPSTREAM_HANDLER_H_
#define SPONGE_NET_CHANNEL_SIMPLE_CHANNEL_UPSTREAM_HANDLER_H_

#include "sponge/net/channel/channel-upstream-handler.h"

namespace sponge {
namespace net {
namespace channel {

// Forward declarations.
class ChannelEvent;
class ChannelHandlerContext;
class ChannelStateEvent;
class ChildChannelStateEvent;
class ExceptionEvent;
class MessageEvent;
class WriteCompletionEvent;

class SimpleChannelUpstreamHandler : public ChannelUpstreamHandler {
  public:
    // Down-casts the received upstream event into more meaningful
    // sub-type event and calls an appropriate handler method with the
    // down-casted event.
    void HandleUpstream(const ChannelHandlerContext &ctx,
                        const ChannelEvent &e);

    // Invoked when a message object (e.g: ChannelBuffer) was received
    // from a remote peer.
    inline void MessageReceived(const ChannelHandlerContext &ctx,
                                const MessageEvent &e) {
        ctx.SendUpstream(e);
    }

    // Invoked when an exception was raised by an I/O thread or a
    // ChannelHandler.
    inline void ExceptionCaught(const ChannelHandlerContext &ctx,
                                const ExceptionEvent &e) {
        ctx.SendUpstream(e);
    }

    // Invoked when a Channel is open, but not bound nor connected.
    inline void ChannelOpen(const ChannelHandlerContext &ctx,
                            const ChannelStateEvent &e) {
        ctx.SendUpstream(e);
    }

    // Invoked when a Channel is open and bound to a local address.
    inline void ChannelBound(const ChannelHandlerContext &ctx,
                             const ChannelStateEvent &e) {
        ctx.SendUpstream(e);
    }

    // Invoked when a channel is open, bound to a local address, and
    // connected to a remote address.
    inline void ChannelConnected(const ChannelHandlerContext &ctx,
                                 const ChannelStateEvent &e) {
        ctx.SendUpstream(e);
    }

    // Invoked when a Channel's Channel#GetInterestOps() interestOps
    // was changed.
    inline void ChannelInterestChanged(const ChannelHandlerContext &ctx,
                                       const ChannelStateEvent &e) {
        ctx.SendUpstream(e);
    }


    // Invoked when a Channel was disconnected from its remote peer.
    inline void ChannelDisconnected(const ChannelHandlerContext &ctx,
                                    const ChannelStateEvent &e) {
        ctx.SendUpstream(e);
    }

    // Invoked when a Channel was unbound from the current local address.
    inline  void ChannelUnbound(const ChannelHandlerContext &ctx,
                                const ChannelStateEvent &e) {
        ctx.SendUpstream(e);
    }

    // Invoked when a Channel was closed and all its related
    // resources were released.
    inline void ChannelClosed(const ChannelHandlerContext &ctx,
                              const ChannelStateEvent &e) {
        ctx.SendUpstream(e);
    }

    // Invoked when something was written into a Channel.
    inline void WriteComplete(const ChannelHandlerContext &ctx,
                              const WriteCompletionEvent &e) {
        ctx.SendUpstream(e);
    }

    //Invoked when a child Channel was open. (e.g. a server channel
    //accepted a connection)
    inline void ChildChannelOpen(const ChannelHandlerContext &ctx,
                                 const ChildChannelStateEvent &e) {
        ctx.SendUpstream(e);
    }

    // Invoked when a child Channel was closed. (e.g. the accepted
    // connection was closed)
    inline void ChildChannelClosed(const ChannelHandlerContext &ctx,
                                   const ChildChannelStateEvent &e) {
        ctx.SendUpstream(e);
    }
};

} } } // namespace sponge::net::channel

#endif // SPONGE_NET_CHANNEL_SIMPLE_CHANNEL_UPSTREAM_HANDLER_H_
