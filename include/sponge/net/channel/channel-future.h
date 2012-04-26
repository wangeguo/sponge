// Copyright (c) 2012 The Sponge Authors. All rights reserved.
// Use of this source code is governed by a MIT-style license that can
// be found in the LICENSE file. See the AUTHORS file for names of contributors.

#ifndef SPONGE_NET_CHANNEL_CHANNEL_FUTURE_H_
#define SPONGE_NET_CHANNEL_CHANNEL_FUTURE_H_

namespace sponge {
namespace net {
namespace channel {

// Forward declarations
class Channel;

// The result of and asynchronous Channel I/O operation
class ChannelFuture {
  public:
    // Returns a channel where the I/O operation associated with this
    // future takes place
    virtual Channel* GetChannel() = 0;

    // Returns true if and only if this future is complate, regardless
    // of whether the operation was successful, failed, or cancelled
    virtual bool IsDone() = 0;

    // Returns true if and only if this future was cancelled by a
    // Cancel() method
    virtual bool IsCancelled() = 0;

    // Returns ture if and only if the I/O operation was complated
    // successfully
    virtual bool IsSuccess() = 0;

    // Returns the cause of the failed I/O operation if the I/O
    // operation has failed
    virtual void* GetCause() = 0;

    // Cancels the I/O operation associated with this future and
    // notifies all listensers if canceled successfully
    virtual bool Cancel() = 0;

    // Make this future as a success and notifies all listensers
    virtual bool SetSuccess() = 0;

    // Marks this future as a failure and notifies all listeners.
    virtual bool SetFailure(void* cause) = 0;

    // Notifies the progress of the operation to the listeners that
    // implements ChannelFutureProgressListener. Please note that this
    // method will not do anything and return false if this future is
    // complate already.
    virtual bool SetProgress(long amount, long current, long total) = 0;

    // Adds the specified listenser to this future. The specified
    // listener is notified when the future is IsDone() done. If the
    // future is already complated, the specified listener is notified
    // immediately.
    virtual void AddListener(const ChannelFutureListener *listener) = 0;

    // Removes the specified listener from this future
    virtual void RemoveListener(const ChannelFutureListener *listener) = 0;

    // Rethrows the exception that caused this future fail if this
    // future is complete and failed.
    virtual ChannelFuture* RethrowIfFailed() = 0;

    // Waits for this future to be completed.
    virtual ChannelFuture* Await()  = 0;

    // Waits for this future to be completed without interruption.
    // This method catches an InterruptedException} and discards it
    // silently.
    virtual ChannelFuture* AwaitUninterruptibly() = 0;
    
    // Waits for this future to be completed within the specified time limit.
    virtual bool Await(long timeout, int unit) = 0;

    // Waits for this future to be completed within the specified time limit.
    virtual bool Await(long timeoutMillis) = 0;

    // Waits for this future to be completed within the specified time
    // limit without interruption.  This method catches an
    // InterruptedException and discards it silently.
    virtual bool AwaitUninterruptibly(long timeout, int unit) = 0;

    // Waits for this future to be completed within the specified time
    // limit without interruption.  This method catches an
    // InterruptedException and discards it silently.
    virtual bool AwaitUninterruptibly(long timeoutMillis) = 0;
};

} } } // namespace sponge::net::channel

#endif // SPONGE_NET_CHANNEL_CHANNEL_FUTURE_H_
