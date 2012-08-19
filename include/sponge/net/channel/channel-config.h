// Copyright (c) 2012 The Sponge Authors. All rights reserved.
// Use of this source code is governed by a MIT-style license that can
// be found in the LICENSE file. See the AUTHORS file for names of contributors.

#ifndef SPONGE_NET_CHANNEL_CHANNEL_CONFIG_H_
#define SPONGE_NET_CHANNEL_CHANNEL_CONFIG_H_

#include <map>
#include <string>

namespace sponge {
namespace net {

// Forward declarations.
class ChannelBufferFactory;
class ChannelPipelineFactory;

// A set of configuration properties of a Channel
class ChannelConfig {
  public:
    // Set the configuration properties from the specified Map
    virtual void SetOptions(std::map<std::string, void*> options) = 0;

    // Sets a configuration property with the specified name and
    // value.
    virtual bool SetOption(std::string name, void* value) = 0;

    // Returns the default ChannelBufferFactory used to create a new
    // ChannelBuffer. The default is HeapChannelBufferFactory. You can
    // specify a different factory to change the default ByteOrder for
    // example.
    virtual ChannelBufferFactory* GetBufferFactory() = 0;

    virtual void SetBufferFactory(const ChannelBufferFactory *buffer_factory) = 0;
    // Returns the ChannelPipelineFactory which will be used when a
    // child channel is created. If the Channel does not create a
    // child channel, this property is not used at all, and therefore
    // will be ignored.
    virtual ChannelPipelineFactory* GetPipelineFactory();

    virtual void SetPipelineFactory(const ChannelPipelineFactory *pipeline_factory) = 0;

    // Returns the connect timeout of the channel in milliseconds.
    virtual int GetConnectTimeoutMillis() = 0;

    virtual int SetConnectTimeoutMillis(int connect_timeout_millis) = 0;
};

} } // namespace sponge::net

#endif // SPONGE_NET_CHANNEL_CHANNEL_CONFIG_H_
