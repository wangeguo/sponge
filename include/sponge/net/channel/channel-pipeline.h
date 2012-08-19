// Copyright (c) 2012 The Sponge Authors. All rights reserved.
// Use of this source code is governed by a MIT-style license that can
// be found in the LICENSE file. See the AUTHORS file for names of contributors.

#ifndef SPONGE_NET_CHANNEL_CHANNEL_PIPELINE_H_
#define SPONGE_NET_CHANNEL_CHANNEL_PIPELINE_H_

#include <map>
#include <set>
#include <string>

namespace sponge {
namespace net {

// Forward declarations.
class Channel;
class ChannelEvent;
class ChannelHandler;
class ChannelHandlerContext;
class ChannelSink;

class ChannelPipeline {
  public:
    virtual void AddFirst(const std::string &name,
                          const ChannelHandler &handler) = 0;
    virtual void AddLast(const std::string &name,
                         const ChannelHandler &handler) = 0;
    virtual void AddBefore(const std::string &base_name,
                           const std::string &name,
                           const ChannelHandler &handler) = 0;
    virtual void AddAfter(const std::string &base_name,
                          const std::string &name,
                          const ChannelHandler &handler) = 0;
    virtual void Remove(const ChannelHandler &handler) = 0;
    virtual ChannelHandler Remove(const std::string &name) = 0;
    virtual ChannelHandler* Remove(const ChannelHandler *handle_type) = 0;
    virtual ChannelHandler RemoveFirst() = 0;
    virtual ChannelHandler RemoveLast() = 0;
    virtual void Replace(const ChannelHandler &old_handler,
                         const std::string &new_name,
                         const ChannelHandler &new_handler) = 0;
    virtual ChannelHandler Replace(const std::string &old_name,
                                   const std::string &new_name,
                                   const ChannelHandler &new_handler) = 0;
    virtual ChannelHandler* Replace(const ChannelHandler *old_handler_type,
                                    const std::string &new_name,
                                    const ChannelHandler &new_handler) = 0;
    virtual ChannelHandler GetFirst() = 0;
    virtual ChannelHandler GetLast() = 0;
    virtual ChannelHandler Get(const std::string &name) = 0;
    virtual ChannelHandler* Get(const ChannelHandler *handler_type);
    virtual ChannelHandlerContext* GetContext(const ChannelHandler &handler) = 0;
    virtual ChannelHandlerContext* GetContext(const std::string &name) = 0;
    virtual ChannelHandlerContext* GetContext(const ChannelHandler *handler_type) = 0;
    virtual void SendUpstream(const ChannelEvent *e) = 0;
    virtual void SendDownstream(const ChannelEvent *e) = 0;
    virtual Channel* GetChannel() = 0;
    virtual ChannelSink GetSink() = 0;
    virtual void Attach(const Channel &channel, const ChannelSink &sink) = 0;
    virtual bool IsAttached() = 0;
    virtual std::set<std::string> GetNames() = 0;
    virtual std::map<std::string, ChannelHandler*> ToMap() = 0;
};

} } // namespace sponge::net

#endif // SPONGE_NET_CHANNEL_CHANNEL_PIPELINE_H_
