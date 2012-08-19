// Copyright (c) 2012 The Sponge Authors. All rights reserved.
// Use of this source code is governed by a MIT-style license that can
// be found in the LICENSE file. See the AUTHORS file for names of contributors.

#ifndef SPONGE_NET_CHANNEL_SOCKET_SERVER_SOCKET_CHANNEL_CONFIG_H_
#define SPONGE_NET_CHANNEL_SOCKET_SERVER_SOCKET_CHANNEL_CONFIG_H_

#include "sponge/net/channel/channel-config.h"

namespace sponge {
namespace net {

// A ChannelConfig for a SocketChannel
class SocketChannelConfig : public ChannelConfig {
  public:
    virtual bool IsTcpNoDelay() = 0;
    virtual void SetTcpNoDelay(bool tcp_no_delay) = 0;
    virtual int  GetSoLinger() = 0;
    virtual void SetSoLinger(int solinger) = 0;
    virtual int  GetSendBufferSize() = 0;
    virtual void SetSendBufferSize(int send_buffer_size) = 0;
    virtual int  GetReceiveBufferSize() = 0;
    virtual void SetReceiveBufferSize( int receive_buffer_size) = 0;
    virtual bool IsKeepAlive() = 0;
    virtual bool SetKeepAlive() = 0;
    virtual int  GetTrafficClass() = 0;
    virtual void SetTrafficClass(int traffic_class) = 0;
    virtual bool IsReuseAddress() = 0;
    virtual void SetReuseAddress(bool reuse_address) = 0;
    virtual void SetPerformancePreferences(
        int connection_time, int latency, int bandwidth) = 0;
};

} } // namespace sponge::net

#endif // SPONGE_NET_CHANNEL_SOCKET_SERVER_SOCKET_CHANNEL_CONFIG_H_
