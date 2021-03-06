// Copyright (c) 2012 The Sponge Authors. All rights reserved.  Use of
// this source code is governed by a MIT-style license that can be
// found in the LICENSE file. See the AUTHORS file for names of contributors.

#ifndef SPONGE_NET_BOOTSTRAP_SERVER_BOOTSTRAP_H_
#define SPONGE_NET_BOOTSTRAP_SERVER_BOOTSTRAP_H_

namespace sponge {
namespace net {

// Forward declarations
class Channel;
class ChannelFactory;
class ChannelHandler;

// Forward declarations.
class Bootstrap;

// A helper class which creates a new server-side Channel and accepts
// incoming connections.** Only for connection oriented transports**
// This bootstrap is for connection oriented transports only such
// as TCP/IP and local transport. Use ConnectionlessBootstrap instead
// for connectionless transports. Do not use this helper if you are
// using a connectionless transport such as UDP/IP which does not
// accept an incoming connection but receives messages by itself
// without creating a child channel.
class ServerBootstrap : public Bootstrap {
  private:
    class Binder;    // Foward decelrations
    
  public:
    // Creates a new instance with no ChannelFactory set.
    // ServerBootstrap() : Bootstrap() {}

    // Create a new instance with the specified inital ChannelFactory.
    ServerBootstrap(const ChannelFactory *channel_factory)
            : Bootstrap(channel_factory) {}
    inline void SetFactory(const ChannelFactory *factory) {
        Bootstrap::SetFactory(factory);
    }
    inline ChannelHandler* GetParentHandler() { return parent_handler_; }
    inline void SetParentHandler(ChannelHandler *parent_handler) {
        parent_handler_ = parent_handler;
    }
    
    //  Creates a new channel which is bound to the local address
    //  which was specified in the current "localAddress" option.
    inline Channel* Bind() {
        std::string local_address = GetOption("local_address");
        if (!local_address.empty())
            return Bind(local_address);
    }
    Channel* Bind(const std::string &local_address);
    void Bind(int port);
    
  private:
    ChannelHandler* parent_handler_;
};

} } // namespace sponge::net

#endif // SPONGE_NET_BOOTSTRAP_SERVER_BOOTSTRAP_H_
