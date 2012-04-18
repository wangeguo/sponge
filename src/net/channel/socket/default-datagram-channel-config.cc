// Copyright (c) 2012 The Sponge Authors. All rights reserved.
// Use of this source code is governed by a MIT-style license that can
// be found in the LICENSE file. See the AUTHORS file for names of contributors.

#include "sponge/net/channel/socket/default-datagram-channel-config.h"

namespace sponge {
namespace net {
namespace channel {
namespace socket {

// Init _kDefaultPredictorFactory
DefaultDatagramChannelConfig::_kDefaultPredictorFactory(
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
        return _kSocket.GetBroadcast();
    } catch (SocketException e) {
        throw new ChannelException(e);
    }
}

void DefaultDatagramChannelConfig::SetBroadcast(bool broadcast) {
    try {
        _kSocket.SetBroadcast(broadcast);
    } catch (SocketException e) {
        throw new ChannelException(e);
    }
}

std::string DefaultDatagramChannelConfig::GetInterface() {
    if (typeid(_kSocket) == typeid(MulticastSocket)) {
        try {
            (static_cast<MulticastSocket>(_kSocket)).GetInterface();
        } catch (IOException e) {
            throw new ChannelException(e);
        }
    } else {
        throw new UnsupportedOperationException();
    }
}

void DefaultDatagramChannelConfig::SetInterface(
    const std::string &interface_address) {
    if (typeid(_kSocket) == typeid(MulticastSocket)) {
        try {
            (static_cast<MulticastSocket>(_kSocket)).SetInterface(interface_address);
        } catch (IOException e) {
            throw new ChannelException(e);
        }
    } else {
        throw new UnsupportedOperationException();
    }
}

bool DefaultDatagramChannelConfig::IsLoopbackModeDisabled() {
    if (typeid(_kSocket) == typeid(MulticastSocket)) {
        try {
            (static_cast<MulticastSocket>(_kSocket)).GetLoopbackMode();
        } catch (IOException e) {
            throw new ChannelException(e);
        }
    } else {
        throw new UnsupportedOperationException();
    }
}

void DefaultDatagramChannelConfig::SetLoopbackModeDisabled(
    bool loopback_mode_disabled) {
    if (typeid(_kSocket) == typeid(MulticastSocket)) {
        try {
            (static_cast<MulticastSocket>(_kSocket)).SetLoopbackModeDisabled(
                loopback_mode_disabled);
        } catch (IOException e) {
            throw new ChannelException(e);
        }
    } else {
        throw new UnsupportedOperationException();
    }
}

std::string DefaultDatagramChannelConfig::GetNetworkInterface() {
    if (typeid(_kSocket) == typeid(MulticastSocket)) {
        try {
            (static_cast<MulticastSocket>(_kSocket)).GetNetworkInterface();
        } catch (IOException e) {
            throw new ChannelException(e);
        }
    } else {
        throw new UnsupportedOperationException();
    }
}

void DefaultDatagramChannelConfig::SetNetworkInterface(
    const std::string &network_interface) {
    if (typeid(_kSocket) == typeid(MulticastSocket)) {
        try {
            (static_cast<MulticastSocket>(_kSocket)).SetNetworkInterface(network_interface);
        } catch (IOException e) {
            throw new ChannelException(e);
        }
    } else {
        throw new UnsupportedOperationException();
    }
}

bool DefaultDatagramChannelConfig::IsReuseAddress() {
    try {
        return _kSocket.GetReuseAddress();
    } catch (SocketException e) {
        throw new ChannelException(e);
    }
}

void DefaultDatagramChannelConfig::SetReuseAddress(bool reuse_address) {
    try {
        _kSocket.SetReuseAddress(reuse_address);
    } catch (SocketException e) {
        throw new ChannelException(e);
    }
}

int  DefaultDatagramChannelConfig::GetReceiveBufferSize() {
    try {
        return _kSocket.GetReceiveBufferSize();
    } catch (SocketException e) {
        throw new ChannelException(e);
    }
}

void DefaultDatagramChannelConfig::SetReceiveBufferSize(
    int receive_buffer_size) {
    try {
        _kSocket.SetReceiveBufferSize(receive_buffer_size);
    } catch (SocketException e) {
        throw new ChannelException(e);
    }
}

int  DefaultDatagramChannelConfig::GetSendBufferSize() {
    try {
        return _kSocket.GetSendBufferSize();
    } catch (SocketException e) {
        throw new ChannelException(e);
    }
}

void DefaultDatagramChannelConfig::SetSendBufferSize(int send_buffer_size) {
    try {
        _kSocket.SetSendBufferSize(send_buffer_size);
    } catch (SocketException e) {
        throw new ChannelException(e);
    }
}

int  DefaultDatagramChannelConfig::GetTimeToLive() {
    if (typeid(_kSocket) == typeid(MulticastSocket)) {
        try {
            (static_cast<MulticastSocket>(_kSocket)).GetTimeToLive();
        } catch (IOException e) {
            throw new ChannelException(e);
        }
    } else {
        throw new UnsupportedOperationException();
    }
}

void DefaultDatagramChannelConfig::SetTimeToLove(int ttl) {
    if (typeid(_kSocket) == typeid(MulticastSocket)) {
        try {
            (static_cast<MulticastSocket>(_kSocket)).SetTimeToLive(ttl);
        } catch (IOException e) {
            throw new ChannelException(e);
        }
    } else {
        throw new UnsupportedOperationException();
    }
}

int  DefaultDatagramChannelConfig::GetTrafficClass() {
    try {
        return _kSocket.GetTrafficClass();
    } catch (SocketException e) {
        throw new ChannelException(e);
    }
}

void DefaultDatagramChannelConfig::SetTrafficClass(int traffic_class) {
    try {
        _kSocket.SetTrafficClass(traffic_class);
    } catch (SocketException e) {
        throw new ChannelException(e);
    }
}

ReceiveBufferSizePredictor
DefaultDatagramChannelConfig::GetReceiveBufferSizePredictor() {
    ReceiveBufferSizePredictor predictor(_predictor);
    if (predictor == NULL) {
        try {
            _predictor = predictor = GetReceiveBufferSizePredictorFactory().GetPredictor();
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
    _predictor = predictor;
}

void DefaultDatagramChannelConfig::SetReceiveBufferSizePredictorFactory(
    const ReceiveBufferSizePredictorFactory &predictor_factory) {
    if (predictor_factory == NULL) {
        throw new NullPointerException("predictor_factory");
    }
    _predictor_factory = predictor_factory;
}


} } } } // namespace sponge::net::channel::socket
