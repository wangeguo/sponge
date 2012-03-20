// Copyright (c) 2012 The Sponge Authors. All rights reserved.
// Use of this source code is governed by a MIT-style license that can
// be found in the LICENSE file. See the AUTHORS file for names of contributors.

#ifndef SPONGE_NET_CHANNEL_CHANNEL_HANDLER_CONTEXT_H_
#define SPONGE_NET_CHANNEL_CHANNEL_HANDLER_CONTEXT_H_

#include <string>

namespace sponge {
namespace net {
namespace channel {

// Forward declarations.
class Channel;
class ChannelHandler;
class ChannelPipeline;

// Enables a ChannelHandler to interact with its ChannelPipeline and
// other handlers. A handler can send a ChannelEvent upstream or
// downstream, modify the ChannelPipeline it belongs to dynamically.
class ChannelHandlerContext {
  public:
    // Returns the Channel that the ChannelPipeline belongs to. This
    // method is a shortcut to getPipeline().getChannel().
    virtual Channel GetChannel() = 0;

    // Returns the ChannelPipeline that the ChannelHandler belongs to.
    virtual const ChannelPipeline* GetPipeline() const = 0;

    // Returns the name of the ChannelHandler in the ChannelPipeline.
    virtual std::string GetName() = 0;

    // Returns the ChannelHandler that this context object is serving.
    virtual ChannelHandler GetHandler() = 0;

    //  Returns true if and only if the ChannelHandler is an instance
    //  of ChannelUpstreamHandler.
    virtual bool CanHandleUpstream() = 0;

    //  Returns true if and only if the ChannelHandler is an instance
    //  of ChannelDownstreamHandler.
    virtual bool CanHandleDownstream() = 0;

    // Sends the specified ChannelEvent to the ChannelUpstreamHandler
    // which is placed in the closest upstream from the handler
    // associated with this context.
    virtual void SendUpstream() = 0;

    // Sends the specified ChannelEvent to the
    // ChannelDownstreamHandler which is placed in the closest
    // downstream from the handler associated with this context.
    virtual void SendDownstream() = 0;

    // Retrieves an object which is attached to this context.
    virtual void* GetAttachment() = 0;

    // Attaches an object to this context to store a stateful
    // information specific to the ChannelHandler which is associated
    // with this context.
    virtual void SetAttachment(void* attachment);
};

}}} // namespace sponge::net::channel

#endif // SPONGE_NET_CHANNEL_CHANNEL_HANDLER_CONTEXT_H_
