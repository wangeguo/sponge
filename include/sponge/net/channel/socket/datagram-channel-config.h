// Copyright (c) 2012 The Sponge Authors. All rights reserved.
// Use of this source code is governed by a MIT-style license that can
// be found in the LICENSE file. See the AUTHORS file for names of contributors.

#ifndef SPONGE_NET_CHANNEL_SOCKET_DATAGRAM_CHANNEL_CONFIG_H_
#define SPONGE_NET_CHANNEL_SOCKET_DATAGRAM_CHANNEL_CONFIG_H_

#include <string>
#include "sponge/net/channel/channel-config.h"

namespace sponge {
namespace net {

// A ChannelConfig for a DatagramChannel
class DatagramChannelConfig : public ChannelConfig {
  public:
    virtual int  GetSendBufferSize() = 0;
    virtual void SetSendBufferSize(int send_buffer_size) = 0;
    virtual int  GetReceiveBufferSize() = 0;
    virtual void SetReceiveBufferSize(int receive_buffer_size) = 0;
    virtual int  GetTrafficClass() = 0;
    virtual void SetTrafficClass(int traffic_class) = 0;
    virtual bool IsReuseAddress() = 0;
    virtual void SetReuseAddress(bool reuse_address) = 0;
    virtual bool IsBroadcast() = 0;
    virtual void SetBroadcast(bool broadcast) = 0;

    // Gets the settings for local loopback of multicast datagram
    virtual bool IsLoopbackModeDisabled() = 0;
    virtual void SetLoopbackModeDisabled(bool loopback_mode_disabled) = 0;

    // Gets the default time-to-live for multicast packets sent out on
    // the socket
    virtual int  GetTimeToLive() = 0;
    virtual void SetTimeToLive(int ttl) = 0;
    virtual std::string GetInterface() = 0;
    virtual void SetInterface(const std::string &interfaceAddress) = 0;
    virtual void GetNetworkInterface() = 0;
    virtual void SetNetworkInterface(void* networkInterface) = 0;


    // @TODO: ReceiveBufferPredictor & it's factory
    //virtual ReceiveBufferSizePredictor GetReceiveBufferSizePredictor() = 0;
    //virtual void SetReceiveBufferSizePredictor(ReceiveBufferSizePredictor predictor) = 0;
    //virtual ReceiveBufferSizePredictorFactory GetReceiveBufferSizePredictorFactory() = 0;

    //virtual void SetReceiveBufferSizePredictorFactory(
    //    ReceiveBufferSizePredictorFactory predictorFactory) = 0;
};

} } // namespace sponge::net

#endif // SPONGE_NET_CHANNEL_SOCKET_DATAGRAM_CHANNEL_CONFIG_H_
