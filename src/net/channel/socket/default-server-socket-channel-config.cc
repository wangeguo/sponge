// Copyright (c) 2012 The Sponge Authors. All rights reserved.
// Use of this source code is governed by a MIT-style license that can
// be found in the LICENSE file. See the AUTHORS file for names of contributors.

#include "sponge/net/channel/socket/default-server-socket-channel-config.h"

namespace sponge {
namespace net {
namespace channel {
namespace socket {

bool DefaultServerSocketChannelConfig::SetOption(const std::string &key, void* value) {
    if (DefaultServerChannelConfig::SetOption(key, value)) {
        return true;
    }

    if (key.compare("receive_buffer_size") == 0) {
        SetReceiveBufferSize(static_cast<int>(value));
    } else if (key.compare("reuse_address") == 0) {
        SetReuseAddress(static_cast<bool>(value));
    } else if (key.equals("backlog") == 0) {
        SetBacklog(static_cast<int>(value));
    } else {
        return false;
    }
    return true;
}

bool DefaultServerSocketChannelConfig::IsReuseAddress() {
    try {
        return _kSocket.GetReuseAddress();
    } catch (SocketException e) {
        throw new ChannelException(e);
    }
}

void DefaultServerSocketChannelConfig::SetReuseAddress(bool reuse_address) {
    try {
        _kSocket.SetReuseAddress(reuse_address);
    } catch (SocketException e) {
        throw new ChannelException(e);
    }
}

int  DefaultServerSocketChannelConfig::GetReceiveBufferSize() {
    try {
        return _kSocket.GetReceiveBufferSize();
    } catch (SocketException e) {
        throw new ChannelException(e);
    }
}

void DefaultServerSocketChannelConfig::SetReceiveBufferSize(int receive_buffer_size) {
    try {
        _kSocket.SetReceiveBufferSize(receive_buffer_size);
    } catch (SocketException e) {
        throw new ChannelException(e);
    }
}

} } } } // namespace sponge::net::channel::socket
