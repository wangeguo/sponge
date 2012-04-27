// Copyright (c) 2012 The Sponge Authors. All rights reserved.
// Use of this source code is governed by a MIT-style license that can
// be found in the LICENSE file. See the AUTHORS file for names of contributors.

#ifndef SPONGE_STORAGE_STORAGE_AREA_H_
#define SPONGE_STORAGE_STORAGE_AREA_H_

#include <string>

namespace sponge {
namespace storage {

class StorageArea {
  public:
    virtual ~StorageArea() {}

    virtual std::string GetItem(const std::string &key) const = 0;
    virtual void SetItem(const std::string &key, const std::string &value) = 0;
    virtual void RemoveItem(const std::string &key) = 0;
    virtual bool Clear() = 0;
    virtual bool Contains(const std::string &key) const = 0;
};

} } // namespace sponge::storage

#endif // SPONGE_STORAGE_STORAGE_AREA_H_
