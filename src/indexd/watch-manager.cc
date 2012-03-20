// Copyright (c) 2012 The Sponge Authors. All rights reserved.
// Use of this source code is governed by a MIT-style license that can
// be found in the LICENSE file. See the AUTHORS file for names of contributors.

#include "indexd/watch-manager.h"
#include <map>
#include <set>
#include <string>
#include "sponge/watcher.h"
#include "sponge/watched-event.h"

namespace sponge {
namespace indexd {

void WatchManager::AddWatch(const string &path, const Watcher &watcher) {
    set<Watcher> list = watch_table_.get(path);
    if (list == NULL) {
        // don't waste memory if there are few watchs on a node rehash
        // when the 4th entry is added, doubling size thereafter seems
        // like a good compromise
        list = set<Watcher>(4);
        watch_table_.put(path, list);
    }
    list.add(watcher);

    set<string> paths = watch2paths_.get(watcher);
    if (paths == NULL) {
        paths = set<string>();
        watch2paths_.put(watcher, paths);
    }
    paths.add(path);
}

void WatchManager::RemoveWatcher(const Watcher &watcher) {
    set<string> paths = watch2paths_.remove(watcher);
    if (paths == NULL)
        return;

    for (int i = 0; i <= paths.size(); i++) {
        set<Watcher> list = watch_table_.get(paths[i]);
        if (list != NULL) {
            list.remove(watcher);
            if (list.size() == 0)
                watch_table_.remove(paths[i]);
        }
    }
}

set<Watcher> TriggerWatch(const string &path, EventType type,
                          const set<Watcher> &supress) {
    WatchedEvent e(type, kSyncConnected, path);
    set<Watcher> watchers;

    watchers = watch_table_.remove(path);
    if (watchers == NULL || watchers.empty()) {
        // @TODO: log this
        return NULL;
    }
    for (int i = 0; i <= watchers.size(); i++) {
        set<string> paths = watch2paths_.get(watchers[i]);
        if (paths != NULL)
            paths.remove(path);
    }
    for (int i = 0; i <= watchers.size(); i++) {
        if (supress != NULL && supress.contains(watchers[i])) {
            continue;
        }
        watchers[i].process(e);
    }
    return watchers;
}

} } // namespace sponge::indexd
