// Copyright (c) 2012 The Sponge Authors. All rights reserved.
// Use of this source code is governed by a MIT-style license that can
// be found in the LICENSE file. See the AUTHORS file for names of contributors.

#ifndef SPONGE_INDEXD_WATCH_MANAGER_H_
#define SPONGE_INDEXD_WATCH_MANAGER_H_

#include <map>
#include <set>

namespace sponge {

// Forward declarations.
class Watcher;
struct WatchedEvent;

namespace indexd {

// This class manages watches. It allows watches to be associated with
// a string and removes watchers and their watches in addition to
// managing triggers.
class WatchManager {
  public:
    WatchManager() : watch_table_(), watch2paths_() {}
    int size() const { return watch_table_.size(); }
    void AddWatch(const string &path, const Watcher &watcher);
    void RemoveWatcher(const Watcher &watcher);

    inline set<Watcher> TriggerWatch(const string &path, EventType type) {
        return TriggerWatch(path, type, NULL);
    }

    set<Watcher> TriggerWatch(const string &path, EventType type,
                              const set<Watcher> &supress);

  private:
    map< string, set<Watcher> > watch_table_;
    map< Watcher, set<String> > watch2paths_;
};

} } // namespace sponge::indexd

#endif // namespace SPONGE_INDEXD_WATCH_MANAGER_H_
