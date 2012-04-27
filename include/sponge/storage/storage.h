// Copyright (c) 2012 The Sponge Authors. All rights reserved.
// Use of this source code is governed by a MIT-style license that can
// be found in the LICENSE file. See the AUTHORS file for names of contributors.

#ifndef SPONGE_STORAGE_STORAGE_H_
#define SPONGE_STORAGE_STORAGE_H_

#include <string>

namespace sponge {
namespace storage {

// Forward declarations
class StorageArea;

class Storage {
  public:
    Storage(const StorageArea *storage_area) : storage_area_(storage_area) {}
    ~Storage();

    std::string GetItem(const std::string &key) const;
    void SetItem(const std::string &key, const std::string &value);
    void RemoveItem(const std::string &key);
    void Clear();

    bool Contains(const std::string &key) const;

  private:
    StorageArea *storage_area_;
};

} } // namespace sponge::storage

#endif // SPONGE_STORAGE_STORAGE_H_
