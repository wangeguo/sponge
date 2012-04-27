// Copyright (c) 2012 The Sponge Authors. All rights reserved.
// Use of this source code is governed by a MIT-style license that can
// be found in the LICENSE file. See the AUTHORS file for names of contributors.

#include "sponge/storage/storage.h"

namespace sponge {
namespace storage {

Storage::~Storage() {}

std::string Storage::GetItem(const std::string &key) const {
    return storage_area->GetItem(key);
}

void Storage::SetItem(const std::string &key, const std::string &value) {
    storage_area_->SetItem(key, value);
}

void Storage::RemoveItem(const std::string &key) {
    storage_area->RemoveItem(key);
}

void Storage::Clear() {
    storage_area_->Clear();
}

bool Storage::Contains(const std::string &key) const {
    return storage_area_->Contains(key);
}

} } // namespace sponge::storage
