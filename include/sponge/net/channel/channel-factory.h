// Copyright (c) 2012 The Sponge Authors. All rights reserved.
// Use of this source code is governed by a MIT-style license that can
// be found in the LICENSE file. See the AUTHORS file for names of contributors.

#ifndef SPONGE_NET_CHANNEL_CHANNEL_FACTORY_H_
#define SPONGE_NET_CHANNEL_CHANNEL_FACTORY_H_

namespace sponge {
namespace net {
namespace channel {

// Forward declarations.
class Channel;
class ChannelPipeline;

// The main interface to a transport that creates a Channel associated
// with a certain communication entity such as a network socket.
class ChannelFactory /*: public ExternalResourceReleasable */{
  public:
    // Creates and opens a new Channel and attaches the specified
    // ChannelPipeline to the new Channel.
    virtual Channel* NewChannel(const ChannelPipeline *pipeline) = 0;

    // Releases the external resources that this factory depends on to
    // function. An external resource is a resource that this factory
    // didn't create by itself. For example, Executors that you
    // specified in the factory constructor are external
    // resources. You can call this method to release all external
    // resources conveniently when the resources are not used by this
    // factory or any other part of your application. An unexpected
    // behavior will be resulted in if the resources are released when
    // there's an open channel which is managed by this factory.
    virtual void ReleaseExternalResources() = 0;
};

} } } // namespace sponge::net::channel

#endif // SPONGE_NET_CHANNEL_CHANNEL_FACTORY_H_
