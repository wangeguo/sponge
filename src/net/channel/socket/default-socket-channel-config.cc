// Copyright (c) 2012 The Sponge Authors. All rights reserved.
// Use of this source code is governed by a MIT-style license that can
// be found in the LICENSE file. See the AUTHORS file for names of contributors.

#include "sponge/net/channel/socket/default-socket-channel-config.h"

namespace sponge {
namespace net {
namespace channel {
namespace socket {

bool DefaultSocketChannelConfig::SetOption(const std::string &key, void* value) {
    if (DefaultChannelConfig::SetOption(key, value)) {
        return true;
    }

    if (key.compare("receive_buffer_size") == 0) {
        SetReceiveBufferSize(static_cast<int>(value));
    } else if (key.compare("send_buffer_size") == 0) {
        SetSendBufferSize(static_cast<int>(value));
    } else if (key.compare("tcp_no_delay") == 0) {
        SetTcpNoDelay(static_cast<bool>(value));
    } else if (key.compare("keep_alive") == 0) {
        SetKeepAlive(static_cast<bool>(value));
    } else if (key.compare("reuse_address") == 0) {
        SetReuseAddress(static_cast<bool>(value));
    } else if (key.compare("so_linger") == 0) {
        SetSoLinger(static_cast<int>(value));
    } else if (key.compare("traffic_class") == 0) {
        SetTrafficClass(static_cast<int>(value));
    } else {
        return false;
    }
    return true;
}

int DefaultSocketChannelConfig::GetReceiveBuffeSize() {
    try {
        return _kSocket.GetReceiveBufferSize();
    } catch (SocketException e) {
        throw new ChannelException(e);
    }
}

int DefaultSocketChannelConfig::GetSendBufferSize() {
    try {
        return _kSocket.GetSendBufferSize();
    } catch (SocketException e) {
        throw new ChannelException(e);
    }
}

int DefaultSocketChannelConfig::GetSoLinger() {
    try {
        return _kSocket.GetSoLinger();
    } catch (SocketException e) {
        throw new ChannelException(e);
    }
}

int DefaultSocketChannelConfig::GetTrafficClass() {
    try {
        return _kSocket.GetTrafficClass();
    } catch (SocketException e) {
        throw new ChannelException(e);
    }
}

bool DefaultSocketChannelConfig::IsKeepAlive() {
    try {
        return _kSocket.GetKeepAlive();
    } catch (SocketException e) {
        throw new ChannelException(e);
    }
}

bool DefaultSocketChannelConfig::IsReuseAddress() {
    try {
        return _kSocket.GetReuseAddress();
    } catch (SocketException e) {
        throw new ChannelException(e);
    }
}

bool DefaultSocketChannelConfig::IsTcpNoDelay() {
    try {
        return _kSocket.GetTcpNoDelay();
    } catch (SocketException e) {
        throw new ChannelException(e);
    }
}

void DefaultSocketChannelConfig::SetKeepAlive(bool keep_alive) {
    try {
        _kSocket.SetKeepAlive(keep_alive);
    } catch (SocketException e) {
        throw new ChannelException(e);
    }
}

void DefaultSocketChannelConfig::SetReceiveBufferSize(int receive_buffer_size) {
    try {
        _kSocket.SetReceiveBufferSize(receive_buffer_size);
    } catch (SocketException e) {
        throw new ChannelException(e);
    }
}

void DefaultSocketChannelConfig::SetReuseAddress(bool reuse_address) {
    try {
        _kSocket.SetReuseAddress(reuse_address);
    } catch (SocketException e) {
        throw new ChannelException(e);
    }
}

void DefaultSocketChannelConfig::SetSendBufferSize(int send_buffer_size) {
    try {
        _kSocket.SetSendBufferSize(send_buffer_size);
    } catch (SocketException e) {
        throw new ChannelException(e);
    }
}

void DefaultSocketChannelConfig::SetSoLinger(int so_linger) {
    try {
        if (so_linger < 0) {
            _kSocket.SetSoLinger(false, 0);
        } else {
            _kSocket.SetSoLinger(true, so_linger);
        }
    } catch (SocketException e) {
        throw new ChannelException(e);
    }
}

void DefaultSocketChannelConfig::SetTcpNoDelay(bool tcp_no_delay) {
    try {
        _kSocket.SetTcpNoDelay(tcp_no_delay);
    } catch (SocketException e) {
        throw new ChannelException(e);
    }
}

void DefaultSocketChannelConfig::SetTrafficClass(int traffic_class) {
    try {
        _kSocket.SetTrafficClass(traffic_class);
    } catch (SocketException e) {
        throw new ChannelException(e);
    }
}

} } } } // namespace sponge::net::channel::socket
