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

// Forward declarations.
class ChannelFactory;
class ChannelPipeline;
class ChannelPipelineFactory;
class ChannelHandler;

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
    ChannelFactory* GetFactory();

    // Sets the ChannelFactory that will be used to perform an I/O
    // operation. This method can be called only once and can't be
    // called at all if the factory was specified in the constructor.
    void SetFactory(const ChannelFactory *factory);

    // Returns the default ChannelPipeline which is cloned when a new
    // Channel is created.
    const ChannelPipeline* GetPipeline();

    // Sets the default ChannelPipeline which is cloned when a new
    // Channel is created.
    void SetPipeline(const ChannelPipeline *pipeline);

    // Dependency injection friendly convenience method for
    // getPipeline() which returns the default pipeline of this
    // bootstrap as an ordered map.
    std::map<std::string, ChannelHandler*> GetPipelineAsMap();

    void SetPipelineAsMap(const std::map<std::string, ChannelHandler*> &pipeline_map);
    inline ChannelPipelineFactory* GetPipelineFactory() {
        return pipeline_factory_; }

    inline void SetPipelineFactory(
        const ChannelPipelineFactory *pipeline_factory) {
        pipeline_ = NULL;
        pipeline_factory_ = pipeline_factory;
    }
	/*
	inline std::map<std::string, std::string> GetOptions() { return options_; }
    inline void SetOptions(std::map<std::string, std::string> options) {
		options_ = options;
	}
	*/
    inline std::string GetOption(const std::string &key) { return options_.find(key)->second; }
	/*
    inline void SetOption(const std::string &key, const std::string &value) {
        if (value.empty())
            options_.erase(key);
        else
            options_.insert(std::pair<std::string, std::string>(key, value));
    }
	*/

  protected:
    // Creates a new instance with no ChannelFactory set.
    Bootstrap() : pipeline_(Channels::Pipeline()),
                  pipeline_factory_(Channels::PipelineFactory(pipeline_)) {}

    // Creates a new instance with the specified initial ChannelFactory.
    inline Bootstrap(const ChannelFactory *channel_factory) {
        SetFactory(channel_factory);
    }

  private:
    volatile ChannelFactory* factory_;
    volatile ChannelPipeline* pipeline_;
    volatile ChannelPipelineFactory* pipeline_factory_;
    volatile std::map< std::string, std::string> options_;
};

} } // namespace sponge::net

#endif // SPONGE_NET_BOOTSTRAP_BOOTSTRAP_H_
