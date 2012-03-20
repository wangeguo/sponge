// Copyright (c) 2012 The Sponge Authors. All rights reserved.
// Use of this source code is governed by a MIT-style license that can
// be found in the LICENSE file. See the AUTHORS file for names of contributors.

#ifndef SPONGE_WATCHER_H_
#define SPONGE_WATCHER_H_

namespace sponge {

// Forward declarations.
struct WatchedEvent;

// This interface specifies the public interface an event handler
// class must implement. A Sponge client will get various events from
// the Sponge server it connects to. An application using such a
// client handles these events by registering a callback object with
// the client. The callback object is expected to be an instance of a
// class that implements Watcher interface.
class Watcher {
  public:
    // This interface defines the possible states on Event may
    // represent
    class Event {
        // Enumeration of states the Sponge may be at the event
        enum KeeperState {
            // The client is in the disconnected state - it is not
            // connected to any server in the ensemble.
            kDisconnected = 0,

            // The client is in the connected state - it is connected
            // to a server in the ensemble (one of the servers
            // specified in the host connection paramter during Sponge
            // client creation).
            kSyncConnected = 3,

            // Auth failed state
            kAuthFailed = 4,

            // The serving cluster has expired this session. The
            // Sponge client connection (the session) is no longer
            // valid. You must create a new client connection
            // (instantiate a new Sponge instance) if you with to
            // access the ensemble.
            kExpired = -112,
        };

        // Enumeration of types of events that may occur on the Sponge
        enum EventType {
            kNone = -1,
            kNodeCreated = 1,
            kNodeDeleted = 2,
            kNodeDataChanged = 3,
            kNodeChildrenChanged = 4,
        };
    };
    
    virtual void process(const WatchedEvent &event) = 0;
};

} // namespace sponge

#endif // SPONGE_WATCHER_H_
