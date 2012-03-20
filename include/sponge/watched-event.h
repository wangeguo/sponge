// Copyright (c) 2012 The Sponge Authors. All rights reserved.
// Use of this source code is governed by a MIT-style license that can
// be found in the LICENSE file. See the AUTHORS file for names of contributors.

#ifndef SPONGE_WATCHED_EVENT_H_
#define SPONGE_WATCHED_EVENT_H_

#include <string>

namespace sponge {

// A WatchedEvent represents a change on the Sponge that a Watcher is
// able to respond to. The WatchedEvent includes exactly what happend,
// the current state of the Sponge, and the path of the node that was
// involved in the event.
// @TODO: update node name in comment
struct WatchedEvent {
    // Create a WatchedEvent with specified type, state and path
    WatchedEvent(EventType type, KeeperState state, const string &path)
            : keeper_state_(state), event_type_(type), path_(path) {}
    KeeperState state;
    EventType type;
    string path;
};

} // namespace sponge

#endif // SPONGE_WATCHED_EVENT_H_
