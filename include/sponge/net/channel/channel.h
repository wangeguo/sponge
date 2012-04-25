// Copyright (c) 2012 The Sponge Authors. All rights reserved.
// Use of this source code is governed by a MIT-style license that can
// be found in the LICENSE file. See the AUTHORS file for names of contributors.

#ifndef SPONGE_NET_CHANNEL_CHANNEL_H_
#define SPONGE_NET_CHANNEL_CHANNEL_H_

#include <stdint.h>
#include <string>

namespace sponge {
namespace net {
namespace channel {

// Forward declarations.
class ChannelFactory;
class ChannelFuture;

// A nexus to a network socket or a component which is capable of I/O
// operations such as read, write, connect, and bind.
class Channel {
  public:
    // The interestOps value which tells that only read operation has
    // been suspended.
    static const int OP_NONE = 0;
    
    // The interestOps value which tells that neither read nor write
    // operation has been suspended.
    static const int OP_READ = 1;

    // The interestOps value which tells that both read and write
    // operation has been suspended.
    static const int OP_WRITE = 4;

    // The interestOps value which tells that only write operation has
    // been suspended.
    static const int OP_READ_WRITE = OP_READ | OP_WRITE;

    // Returns the unique integer ID of this channel.
    virtual int64_t GetId() = 0;

    // Returns the ChannelFactory which created this channel.
    virtual ChannelFactory* GetFactory() = 0;

    // Returns the parent of this channel, NULL mean not have parent channel.
    virtual Channel* GetParent() = 0;

    // Returns the configuration of this channel.
    virtual ChannelConfig GetConfig() = 0;

    // Returns the ChannelPipeline wich handles ChannelEvents
    // associated with this channel.
    virtual ChannelPipeline* GetPipeline() = 0;

    // Returns true is and only if this channel is open.
    virtual bool IsOpen() = 0;

    // Returns true if and only if this channel is bound to a local address.
    virtual bool IsBound() = 0;

    // Returns true if and only if this channel is connected to a remote address.
    virtual bool IsConnected() = 0;

    // Returns the local address where this channel is bound to.
    virtual std::string GetLocalAddress() = 0;

    // Returns the remote address where this channel is connected to.
    virtual std::string GetRemoteAddress() = 0;

    // Sends a message to this channel asynchronously.
    virtual ChannelFuture Write(void* message) = 0;

    // Sends a message to this channel asynchronously.  It has an
    // additional parameter that allows a user to specify where to
    // send the specified message instead of this channel's current
    // remote address.
    virtual ChannelFuture Write(void* message, const std::string &remote_address) = 0;

    // Binds this channel to the specified local address
    // asynchronously.
    virtual ChannelFuture Bind(const std::string &local_address);

    // Connectes this channel to the specified remote address
    // asynchronously.
    virtual ChannelFutue Connect(const std::string &remote_address);

    // Disconnects this channel from the current remote address
    // asynchronously.
    virtual ChannelFuture Disconnect() = 0;

    // Unbinds this channel from the current local address
    // asynchronously.
    virtual ChannelFuture Unbind() = 0;

    // Closes this channel asynchronously.  If this channel is bound
    // or connected, it will be disconnected and unbound first.  Once
    // a channel is closed, it can not be open again.  Calling this
    // method on a closed channel has no effect.  Please note that
    // this method always returns the same future instance.
    virtual ChannelFuture Close() = 0;

    // Returns the ChannelFuture which will be notified when this
    // channel is closed. This method always returns the same future
    // instance.
    virtual ChannelFuture GetCloseFuture() = 0;

    // Returns the current interestOps of this channel.
    virtual int GetInterestOps() = 0;

    // Returns true if and only the I/O thread will read a message
    // from this channel.
    virtual bool IsReadable() = 0;

    // Returns true if and only if the I/O thread will perform the
    // requested write operation immediately.  Any write requests made
    // when this method returns false are queued until the I/O thread
    // is ready to process the queued write requests.
    virtual bool IsWritable() = 0;

    virtual ChannelFuture SetInterestOps(int interest_ops) = 0;
    virtual ChannelFuture SetReadable(bool readable) = 0;
};

} } } // namespace sponge::net::channel

#endif // SPONGE_NET_CHANNEL_CHANNEL_H_
