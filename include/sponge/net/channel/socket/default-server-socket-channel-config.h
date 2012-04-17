// Copyright (c) 2012 The Sponge Authors. All rights reserved.
// Use of this source code is governed by a MIT-style license that can
// be found in the LICENSE file. See the AUTHORS file for names of contributors.

#ifndef SPONGE_NET_CHANNEL_SOCKET_DEFAULT_SERVER_SOCKET_CHANNEL_CONFIG_H_
#define SPONGE_NET_CHANNEL_SOCKET_DEFAULT_SERVER_SOCKET_CHANNEL_CONFIG_H_

#include <string>
#include "sponge/net/channel/default-server-channel-config.h"

namespace sponge {
namespace net {
namespace channel {
namespace socket {

// The default ServerSocketChannelConfig implementation.
class DefaultServerSocketChannelConfig
        : public DefaultServerChannelConfig,
          public ServerSocketChannelConfig {
  public:
    DefaultServerSocketChannelConfig(const ServerSocket &socket)
            : _socket(socket) {}
    
    bool SetOption(const std::string &key, void* value);
    bool IsReuseAddress();
    void SetReuseAddress(bool reuse_address);
    int  GetReceiveBufferSize();
    void SetReceiveBufferSize(int receive_buffer_size);

    inline void SetPerformancePreference(
        int connection_time, int latency, int bandwidth) {
        _socket.SetPerformancePreference(connction_time, latency, bandwidth);
    }

    inline int GetBacklog() { return _backlog; }
    void void SetBacklog(int backlog) { _backlog = backlog; }

  private:
    const ServerSocket _socket;
    volatile int _backlog;
};
    
} } } } // namespace sponge::net::channel::socket

#endif // SPONGE_NET_CHANNEL_SOCKET_DEFAULT_SERVER_SOCKET_CHANNEL_CONFIG_H_
