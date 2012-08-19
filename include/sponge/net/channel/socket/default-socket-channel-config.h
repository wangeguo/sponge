// Copyright (c) 2012 The Sponge Authors. All rights reserved.
// Use of this source code is governed by a MIT-style license that can
// be found in the LICENSE file. See the AUTHORS file for names of contributors.

#ifndef SPONGE_NET_CHANNEL_SOCKET_DEFAULT_SOCKET_CHANNEL_CONFIG_H_
#define SPONGE_NET_CHANNEL_SOCKET_DEFAULT_SOCKET_CHANNEL_CONFIG_H_

namespace sponge {
namespace net {

// The default SocketChannelConfig implementation
class DefaultSocketChannelConfig
        : public DefaultChannelConfig, public SocketChannelConfig {
  public:
    DefaultSocketChannelConfig(const Socket &socket) : kSocket_(socket) {}

    bool SetOption(const std::string &key, void* value);
    int  GetReceiveBufferSize();
    int  GetSendBufferSize();
    int  GetSoLinger();
    int  GetTrafficClass();
    bool IsKeepAlive();
    bool IsReuseAddress();
    bool IsTcpNoDelay();
    void SetKeepAlive(bool keep_alive);

    inline void SetPerformancePreferences(
        int connection_time, int latency, int bandwidth) {
        kSocket_.SetPerformancePreferences(connection_time, latency, bandwidth);
    }

    void SetReceiveBufferSize(int receive_buffer_size);
    void SetReuseAddress(bool reuse_address);
    void SetSendBufferSize(int send_buffer_size);
    void SetSoLinger(int so_linger);
    void SetTcpNoDelay(bool tcp_no_delay);
    void SetTrafficClass(int traffic_class);

  private:
    const Socket kSocket_;
};

} } // namespace sponge::net

#endif // SPONGE_NET_CHANNEL_SOCKET_DEFAULT_SOCKET_CHANNEL_CONFIG_H_
