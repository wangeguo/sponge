// Copyright (c) 2012 The Sponge Authors. All rights reserved.
// Use of this source code is governed by a MIT-style license that can
// be found in the LICENSE file. See the AUTHORS file for names of contributors.

#ifndef SPONGE_NET_CHANNEL_SOCKET_DEFAULT_DATAGRAM_CHANNEL_CONFIG_H_
#define SPONGE_NET_CHANNEL_SOCKET_DEFAULT_DATAGRAM_CHANNEL_CONFIG_H_

namespace sponge {
namespace net {
namespace channel {
namespace socket {

// The default DatagramChannelConfig implementation.
class DefaultDatagramChannelConfig
        : public DefaultChannelConfig, public DatagramChannelConfig {
  public:
    DefaultDatagramChannelConfig(const DatagramSocket &socket)
            : kSocket_(socket), predictor_factory_(kDefaultPredictorFactory_) {}

    bool SetOption(const std::string &key, void* value);
    bool IsBroadcast();
    void SetBroadcast(bool broadcast);
    std::string GetInterface();
    void SetInterface(const std::string &interface_address);
    bool IsLoopbackModeDisabled();
    void SetLoopbackModeDisabled(bool loopback_mode_disabled);
    std::string GetNetworkInterface();
    void SetNetworkInterface(const std::string &network_interface);
    bool IsReuseAddress();
    void SetReuseAddress(bool reuse_address);
    int  GetReceiveBufferSize();
    void SetReceiveBufferSize(int receive_buffer_size);
    int  GetSendBufferSize();
    void SetSendBufferSize(int send_buffer_size);
    int  GetTimeToLive();
    void SetTimeToLove(int ttl);
    int  GetTrafficClass();
    void SetTrafficClass(int traffic_class);
    ReceiveBufferSizePredictor GetReceiveBufferSizePredictor();
    void SetReceiveBufferSizePredictor(
        const ReceiveBufferSizePredictor &predictor);

    inline ReceiveBufferSizePredictorFactory
    GetReceiveBufferSizePredictorFactory() {
        return predictor_factory_;
    }

    void SetReceiveBufferSizePredictorFactory(
        const ReceiveBufferSizePredictorFactory &predictor_factory);

  private:
    static const ReceiveBufferSizePredictorFactory kDefaultPredictorFactory_;
    const DatagramSocket kSocket_;
    volatile ReceiveBufferSizePredictor predictor_;
    volatile ReceiveBufferSizePredictorFactory predictor_factory_;
}


} } } } // namespace sponge::net::channel::socket

#endif // SPONGE_NET_CHANNEL_SOCKET_DEFAULT_DATAGRAM_CHANNEL_CONFIG_H_
