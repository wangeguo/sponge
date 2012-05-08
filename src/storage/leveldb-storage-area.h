// Copyright (c) 2012 The Sponge Authors. All rights reserved.
// Use of this source code is governed by a MIT-style license that can
// be found in the LICENSE file. See the AUTHORS file for names of contributors.

#ifndef SPONGE_STORAGE_LEVELDB_STORAGE_AREA_H_
#define SPONGE_STORAGE_LEVELDB_STORAGE_AREA_H_

#include <string>
#include <leveldb/db.h>
#include "sponge/storage/storage-area.h"

namespace sponge {
namespace storage {

// StorageArea LevelDB Implemention
class LevelDBStorageArea : public StorageArea {
  public:
    LevelDBStorageArea() : db_(NULL) {}
    LevelDBStorageArea(const std::string &dbname);
    virtual ~LevelDBStorageArea();

    virtual std::string GetItem(const std::string &key) const;
    virtual void SetItem(const std::string &key, const std::string &value);
    virtual void RemoveItem(const std::string &key);
    virtual bool Clear();
    virtual bool Contains(const std::string &key) const;

  private:
    std::string dbpath_;
    leveldb::DB *db_;
};

} } // namespace sponge::storage

#endif // SPONGE_STORAGE_LEVELDB_STORAGE_AREA_H_
