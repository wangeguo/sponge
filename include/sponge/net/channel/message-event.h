// Copyright (c) 2012 The Sponge Authors. All rights reserved.
// Use of this source code is governed by a MIT-style license that can
// be found in the LICENSE file. See the AUTHORS file for names of contributors.

#ifndef SPONGE_NET_CHANNEL_MESSAGE_EVENT_H_
#define SPONGE_NET_CHANNEL_MESSAGE_EVENT_H_

namespace sponge {
namespace net {
namespace channel {

// Forward declarations.
class ChannelEvent;

// A ChannelEvent which represents the transmission or reception of a
// message. It can mean the notification of a received message or the
// request for writing a message, depending on whether it is an
// upstream event or a downstream event respectively. Please refer to
// the ChannelEvent documentation to find out what an upstream event
// and a downstream event are and what fundamental differences they
// have.
class MessageEvent : ChannelEvent {
  public:
    // Returns the message
    virtual void* GetMessage() = 0;

    // Returns the remote address of the message
    virtual std::string GetRemoteAddress() = 0;
};

} } } // namespace sponge::net::channel

#endif // SPONGE_NET_CHANNEL_MESSAGE_EVENT_H_
