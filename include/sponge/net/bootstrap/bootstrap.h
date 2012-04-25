// Copyright (c) 2012 The Sponge Authors. All rights reserved.
// Use of this source code is governed by a MIT-style license that can
// be found in the LICENSE file. See the AUTHORS file for names of contributors.

#ifndef SPONGE_NET_BOOTSTRAP_BOOTSTRAP_H_
#define SPONGE_NET_BOOTSTRAP_BOOTSTRAP_H_

#include <map>
#include <string>
#include "sponge/net/channel/channels.h"

namespace sponge {
namespace net {

namespace channel {
// Forward declarations.
class ChannelFactory;
class ChannelPipeline;
class ChannelPipelineFactory;
class ChannelHandler;
} // namespace channel

namespace bootstrap {

// A helper class which initializes a Channel. This class provides the
// common data structure for its subclasses which actually initialize
// Channels and their child Channels using the common data
// structure. Please refer to ClientBootstrap, ServerBootstrap, and
// ConnectionlessBootstrap for client side, server-side, and
// connectionless (e.g. UDP) channel initialization respectively.
class Bootstrap /* : ExternalResourceReleasable */ {
  public:
    virtual ~Bootstrap();

    // Returns the ChannelFactory that will be used to perform an I/O operation.
    channel::ChannelFactory* GetFactory();

    // Sets the ChannelFactory that will be used to perform an I/O
    // operation. This method can be called only once and can't be
    // called at all if the factory was specified in the constructor.
    void SetFactory(const channel::ChannelFactory *factory);

    // Returns the default ChannelPipeline which is cloned when a new
    // Channel is created.
    const channel::ChannelPipeline* GetPipeline();

    // Sets the default ChannelPipeline which is cloned when a new
    // Channel is created.
    void SetPipeline(const channel::ChannelPipeline *pipeline);

    // Dependency injection friendly convenience method for
    // getPipeline() which returns the default pipeline of this
    // bootstrap as an ordered map.
    std::map<std::string, channel::ChannelHandler*> GetPipelineAsMap();

    void SetPipelineAsMap(const std::map<std::string, channel::ChannelHandler*> &pipeline_map);
    inline channel::ChannelPipelineFactory* GetPipelineFactory() {
        return pipeline_factory_; }

    inline void SetPipelineFactory(
        const channel::ChannelPipelineFactory *pipeline_factory) {
        pipeline_ = NULL;
        pipeline_factory_ = pipeline_factory;
    }
    inline std::map<std::string, void* > GetOptions() { return options_; }
    inline void SetOptions(std::map<std::string, void* > options) {
        options_ = options;
    }
    inline void* GetOption(std::string key) { return options_.find(key)->second; }
    inline void SetOption(std::string key, void* value) {
        if (value == NULL)
            options_.erase(key);
        else
            options_.insert(std::pair<std::string, void*>(key, value));
    }

  protected:
    // Creates a new instance with no ChannelFactory set.
    Bootstrap() : pipeline_(channel::Channels::Pipeline()),
                  pipeline_factory_(channel::Channels::PipelineFactory(pipeline_)) {}

    // Creates a new instance with the specified initial ChannelFactory.
    inline Bootstrap(const channel::ChannelFactory *channel_factory) {
        SetFactory(channel_factory);
    }

  private:
    volatile channel::ChannelFactory* factory_;
    volatile channel::ChannelPipeline* pipeline_;
    volatile channel::ChannelPipelineFactory* pipeline_factory_;
    volatile std::map< std::string, void* > options_;
};

} } } // namespace sponge::net::bootstrap

#endif // SPONGE_NET_BOOTSTRAP_BOOTSTRAP_H_
