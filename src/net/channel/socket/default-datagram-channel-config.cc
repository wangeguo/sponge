// Copyright (c) 2012 The Sponge Authors. All rights reserved.
// Use of this source code is governed by a MIT-style license that can
// be found in the LICENSE file. See the AUTHORS file for names of contributors.

#include "sponge/net/channel/socket/default-datagram-channel-config.h"

namespace sponge {
namespace net {
namespace channel {
namespace socket {

// Init kDefaultPredictorFactory_
DefaultDatagramChannelConfig::kDefaultPredictorFactory_(
    FixedReceiveBufferSizePredictorFactory(768));

bool DefaultDatagramChannelConfig::SetOption(
    const std::string &key, void* value) {
    if (DefaultChannelConfig::SetOption(key, value)) {
        return true;
    }

    if (key.compare("broadcast") == 0) {
        SetBroadcast(static_cast<bool>(value));
    } else if (key.compare("receive_buffer_size") == 0) {
        SetReceiveBufferSize(static_cast<int>(value));
    } else if (key.compare("send_buffer_size") == 0) {
        SetSendBufferSize(static_cast<int>(value));
    } else if (key.compare("receive_buffer_size_predictor_factory") == 0) {
        SetReceiveBufferSizePredictorFactory(
            static_cast<ReceiveBufferSizePredictorFactory>(value));
    } else if (key.compare("receive_buffer_size_predictor") == 0) {
        SetReceiveBufferSizePredictor(
            static_cast<ReceiveBufferSizePredictor>(value));
    } else if (key.compare("reuse_address")) {
        SetReuseAddress(static_cast<bool>(value));
    } else if (key.compare("loopback_mode_disabled")) {
        SetLoopbackModeDisabled(static_cast<bool>(value));
    } else if (key.compare("interface") == 0) {
        SetInterface(static_cast<std::string>(value));
    } else if (key.compare("network_interface") == 0) {
        SetNetworkInterface(static_cast<std::string>(value));
    } else if (key.compare("time_to_live") == 0) {
        SetTimeToLive(static_cast<int>(value));
    } else if (key.compare("traffic_class") == 0) {
        SetTrafficClass(static_cast<int>(value));
    } else {
        return false;
    }
    return true;
}
bool DefaultDatagramChannelConfig::IsBroadcast() {
    try {
        return kSocket_.GetBroadcast();
    } catch (SocketException e) {
        throw new ChannelException(e);
    }
}

void DefaultDatagramChannelConfig::SetBroadcast(bool broadcast) {
    try {
        kSocket_.SetBroadcast(broadcast);
    } catch (SocketException e) {
        throw new ChannelException(e);
    }
}

std::string DefaultDatagramChannelConfig::GetInterface() {
    if (typeid(kSocket_) == typeid(MulticastSocket)) {
        try {
            (static_cast<MulticastSocket>(kSocket_)).GetInterface();
        } catch (IOException e) {
            throw new ChannelException(e);
        }
    } else {
        throw new UnsupportedOperationException();
    }
}

void DefaultDatagramChannelConfig::SetInterface(
    const std::string &interface_address) {
    if (typeid(kSocket_) == typeid(MulticastSocket)) {
        try {
            (static_cast<MulticastSocket>(kSocket_)).SetInterface(interface_address);
        } catch (IOException e) {
            throw new ChannelException(e);
        }
    } else {
        throw new UnsupportedOperationException();
    }
}

bool DefaultDatagramChannelConfig::IsLoopbackModeDisabled() {
    if (typeid(kSocket_) == typeid(MulticastSocket)) {
        try {
            (static_cast<MulticastSocket>(kSocket_)).GetLoopbackMode();
        } catch (IOException e) {
            throw new ChannelException(e);
        }
    } else {
        throw new UnsupportedOperationException();
    }
}

void DefaultDatagramChannelConfig::SetLoopbackModeDisabled(
    bool loopback_mode_disabled) {
    if (typeid(kSocket_) == typeid(MulticastSocket)) {
        try {
            (static_cast<MulticastSocket>(kSocket_)).SetLoopbackModeDisabled(
                loopback_mode_disabled);
        } catch (IOException e) {
            throw new ChannelException(e);
        }
    } else {
        throw new UnsupportedOperationException();
    }
}

std::string DefaultDatagramChannelConfig::GetNetworkInterface() {
    if (typeid(kSocket_) == typeid(MulticastSocket)) {
        try {
            (static_cast<MulticastSocket>(kSocket_)).GetNetworkInterface();
        } catch (IOException e) {
            throw new ChannelException(e);
        }
    } else {
        throw new UnsupportedOperationException();
    }
}

void DefaultDatagramChannelConfig::SetNetworkInterface(
    const std::string &network_interface) {
    if (typeid(kSocket_) == typeid(MulticastSocket)) {
        try {
            (static_cast<MulticastSocket>(kSocket_)).SetNetworkInterface(network_interface);
        } catch (IOException e) {
            throw new ChannelException(e);
        }
    } else {
        throw new UnsupportedOperationException();
    }
}

bool DefaultDatagramChannelConfig::IsReuseAddress() {
    try {
        return kSocket_.GetReuseAddress();
    } catch (SocketException e) {
        throw new ChannelException(e);
    }
}

void DefaultDatagramChannelConfig::SetReuseAddress(bool reuse_address) {
    try {
        kSocket_.SetReuseAddress(reuse_address);
    } catch (SocketException e) {
        throw new ChannelException(e);
    }
}

int  DefaultDatagramChannelConfig::GetReceiveBufferSize() {
    try {
        return kSocket_.GetReceiveBufferSize();
    } catch (SocketException e) {
        throw new ChannelException(e);
    }
}

void DefaultDatagramChannelConfig::SetReceiveBufferSize(
    int receive_buffer_size) {
    try {
        kSocket_.SetReceiveBufferSize(receive_buffer_size);
    } catch (SocketException e) {
        throw new ChannelException(e);
    }
}

int  DefaultDatagramChannelConfig::GetSendBufferSize() {
    try {
        return kSocket_.GetSendBufferSize();
    } catch (SocketException e) {
        throw new ChannelException(e);
    }
}

void DefaultDatagramChannelConfig::SetSendBufferSize(int send_buffer_size) {
    try {
        kSocket_.SetSendBufferSize(send_buffer_size);
    } catch (SocketException e) {
        throw new ChannelException(e);
    }
}

int  DefaultDatagramChannelConfig::GetTimeToLive() {
    if (typeid(kSocket_) == typeid(MulticastSocket)) {
        try {
            (static_cast<MulticastSocket>(kSocket_)).GetTimeToLive();
        } catch (IOException e) {
            throw new ChannelException(e);
        }
    } else {
        throw new UnsupportedOperationException();
    }
}

void DefaultDatagramChannelConfig::SetTimeToLove(int ttl) {
    if (typeid(kSocket_) == typeid(MulticastSocket)) {
        try {
            (static_cast<MulticastSocket>(kSocket_)).SetTimeToLive(ttl);
        } catch (IOException e) {
            throw new ChannelException(e);
        }
    } else {
        throw new UnsupportedOperationException();
    }
}

int  DefaultDatagramChannelConfig::GetTrafficClass() {
    try {
        return kSocket_.GetTrafficClass();
    } catch (SocketException e) {
        throw new ChannelException(e);
    }
}

void DefaultDatagramChannelConfig::SetTrafficClass(int traffic_class) {
    try {
        kSocket_.SetTrafficClass(traffic_class);
    } catch (SocketException e) {
        throw new ChannelException(e);
    }
}

ReceiveBufferSizePredictor
DefaultDatagramChannelConfig::GetReceiveBufferSizePredictor() {
    ReceiveBufferSizePredictor predictor(predictor_);
    if (predictor == NULL) {
        try {
            predictor_ = predictor = GetReceiveBufferSizePredictorFactory().GetPredictor();
        } catch (Exception e) {
            throw new ChannelException(
                "Failed to create a new ReceiveBufferSizePredictor", e);
        }
    }
    return predictor;
}

void DefaultDatagramChannelConfig::setReceiveBufferSizePredictor(
    const ReceiveBufferSizePredictor &predictor) {
    if (predictor == NULL) {
        throw new NullPointerException("predictor");
    }
    predictor_ = predictor;
}

void DefaultDatagramChannelConfig::SetReceiveBufferSizePredictorFactory(
    const ReceiveBufferSizePredictorFactory &predictor_factory) {
    if (predictor_factory == NULL) {
        throw new NullPointerException("predictor_factory");
    }
    predictor_factory_ = predictor_factory;
}


} } } } // namespace sponge::net::channel::socket
