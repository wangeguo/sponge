// Copyright (c) 2012 The Sponge Authors. All rights reserved.
// Use of this source code is governed by a MIT-style license that can
// be found in the LICENSE file. See the AUTHORS file for names of contributors.

#ifndef SPONGE_NET_CHANNEL_SOCKET_DEFAULT_SERVER_SOCKET_CHANNEL_CONFIG_H_
#define SPONGE_NET_CHANNEL_SOCKET_DEFAULT_SERVER_SOCKET_CHANNEL_CONFIG_H_

#include <string>
#include "sponge/net/channel/default-server-channel-config.h"

namespace sponge {
namespace net {

// The default ServerSocketChannelConfig implementation.
class DefaultServerSocketChannelConfig
        : public DefaultServerChannelConfig,
          public ServerSocketChannelConfig {
  public:
    DefaultServerSocketChannelConfig(const ServerSocket &socket)
            : kSocket_(socket) {}
    
    bool SetOption(const std::string &key, void* value);
    bool IsReuseAddress();
    void SetReuseAddress(bool reuse_address);
    int  GetReceiveBufferSize();
    void SetReceiveBufferSize(int receive_buffer_size);

    inline void SetPerformancePreference(
        int connection_time, int latency, int bandwidth) {
        kSocket_.SetPerformancePreference(connction_time, latency, bandwidth);
    }

    inline int GetBacklog() { return backlog_; }
    void void SetBacklog(int backlog) { backlog_ = backlog; }

  private:
    const ServerSocket kSocket_;
    volatile int backlog_;
};
    
} } // namespace sponge::net

#endif // SPONGE_NET_CHANNEL_SOCKET_DEFAULT_SERVER_SOCKET_CHANNEL_CONFIG_H_
