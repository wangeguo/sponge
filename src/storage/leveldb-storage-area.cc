// Copyright (c) 2012 The Sponge Authors. All rights reserved.
// Use of this source code is governed by a MIT-style license that can
// be found in the LICENSE file. See the AUTHORS file for names of contributors.

#include "storage/leveldb-storage-area.h"

namespace sponge {
namespace storage {

LevelDBStorageArea::LevelDBStorageArea(const std::string &dbname) {
    leveldb::Options options;
    options.create_if_missing = true;
    leveldb::DB::Open(options, dbname, &db_);
}

LevelDBStorageArea::~LevelDBStorageArea() {
    delete db_;
    db_ = NULL;
}

std::string LevelDBStorageArea::GetItem(const std::string &key) {
    std::string value;
    leveldb::Status status = db_->Get(leveldb::ReadOptions(), key, &value);
    if (status.ok()) {
        return value;
    }
}

void LevelDBStorageArea::SetItem(const std::string &key, 
                                 const std::string &value) {
    db_->Put(leveldb::WriteOptions(), key, value);
}
void LevelDBStorageArea::RemoveItem(const std::string &key) {
    db_->Delete(leveldb::WriteOptions(), key);
}

bool LevelDBStorageArea::Clear() {
    return false;
}

bool LevelDBStorageArea::Contains(const std::string &key) {
    return false;
}

} } // namespace sponge::storage
