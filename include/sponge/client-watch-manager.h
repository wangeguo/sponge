// Copyright (c) 2012 The Sponge Authors. All rights reserved.
// Use of this source code is governed by a MIT-style license that can
// be found in the LICENSE file. See the AUTHORS file for names of contributors.

#ifndef SPONGE_CLIENT_WATCH_MANAGER_H_
#define SPONGE_CLIENT_WATCH_MANAGER_H_

#include <set>

namespace sponge {

// Forward declarations.
class Watcher;

// Return a set of watchers that should be notified of the event. The
// manager must not notify the watcher(s), however it will update it's
// internal structure as if the watches had triggered. The intent
// being that the callee is now responsible for notifying the watchers
// of the event, possibly at some later time.
class ClientWatchManager {
  public:
    virtual set<Watcher> materialize(Watcher.Event.KeeperState state,
                                     Watcher.Event.EventType type,
                                     const string &path) = 0;
};

} // namespace sponge

#endif // SPONGE_CLIENT_WATCH_MANAGER_H_
