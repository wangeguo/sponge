// Copyright (c) 2012 The Sponge Authors. All rights reserved.
// Use of this source code is governed by a MIT-style license that can
// be found in the LICENSE file. See the AUTHORS file for names of contributors.

#ifndef SPONGE_NET_BOOTSTRAP_CLIENT_BOOTSTRAP_H_
#define SPONGE_NET_BOOTSTRAP_CLIENT_BOOTSTRAP_H_

#include <string>

namespace sponge {
namespace net {

//Forward declarations
class ChannelFactory;
class ChannelFuture;

// Forward declarations.
class Bootstrap;

// A helper class which creates a new client-side Channel and makes a
// connection attempt.
class ClientBootstrap : public Bootstrap {
  public:
    // Creates a new instance with the specified initial ChannelFactory.
    ClientBootstrap(const ChannelFactory *channel_factory)
            : Bootstrap(channel_factory) {}

    // Attempts a new connection with the current "remote_address" and
    // "local_address" option.
    inline ChannelFuture* Connect() {
        std::string remote_address = GetOption("remote_address");
        if (!remote_address.empty())
            return Connect(remote_address);
    }

    // Attempts a new connection with the specified remote_address and
    // the current "local_address" option.
    inline ChannelFuture* Connect(const std::string &remote_address) {
        std::string local_address = static_cast<std::string>(GetOption("local_address"));
        return Connect(remote_address, local_address);
    }

    // Attempts a new connection with the specified remote_address and
    // the specified local_address.
    ChannelFuture* Connect(const std::string &remote_address,
                          const std::string &local_address);
};

} } // namespace sponge::net

#endif // SPONGE_NET_BOOTSTRAP_CLIENT_BOOTSTRAP_H_
