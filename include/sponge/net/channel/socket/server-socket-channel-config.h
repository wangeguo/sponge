// Copyright (c) 2012 The Sponge Authors. All rights reserved.
// Use of this source code is governed by a MIT-style license that can
// be found in the LICENSE file. See the AUTHORS file for names of contributors.

#ifndef SPONGE_NET_CHANNEL_SOCKET_SERVER_SOCKET_CHANNEL_CONFIG_H_
#define SPONGE_NET_CHANNEL_SOCKET_SERVER_SOCKET_CHANNEL_CONFIG_H_

#include "sponge/net/channel/channel-config.h"

namespace sponge {
namespace net {
namespace channel {
namespace socket {

// A ChannelConfig for a ServerSocketChannel
class ServerSocketChannelConfig : public ChannelConfig {
  public:
    // Gets the backlog value to specify when the channel binds to a
    // local address
    virtual int GetBacklog() = 0;

    // Sets the backlog value to specify when the channel binds to a
    // local address.
    virtual void SetBacklog(int backlog) = 0;
    virtual bool IsReuseAddress() = 0;
    virtual void SetReuseAddress(booll reuse_address) = 0;
    virtual int  GetReceiveBufferSize() = 0;
    virtual void SetReceiveBufferSize(int receive_buffer_size) = 0;
    virtual void SetPerformancePreference(
        int connection_time, int latency, int bandwidth) = 0;
};

} } } } // namespace sponge::net::channel::socket

#endif // SPONGE_NET_CHANNEL_SOCKET_SERVER_SOCKET_CHANNEL_CONFIG_
