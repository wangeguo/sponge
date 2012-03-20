// Copyright (c) 2012 The Sponge Authors. All rights reserved.
// Use of this source code is governed by a MIT-style license that can
// be found in the LICENSE file. See the AUTHORS file for names of contributors.

#include "sponge/net/bootstrap/bootstrap.h"

namespace sponge {
namespace net {
namespace bootstrap {

ChannelFactory Bootstrap::GetFactory() {
    ChannelFactory factory = factory_;
    return factory;
}

void Bootstrap::SetFactory(const ChannelFactory &factory) {
    factory_ = factory;
}

ChannelPipeline Bootstrap::GetPipeline() {
    ChannelPipeline pipeline = pipeline_;
    return pipeline;
}

void Bootstrap::SetPipeline(const ChannelPipeline &pipeline) {
    if (pipeline != NULL) {
        pipeline_ = pipeline;
        pipeline_factory_ = Channels::PipelineFactory(pipeline);
    }
}

std::map<std::string, ChannelHandler> Bootstrap::GetPipelineAsMap() {
    ChannelPipeline pipeline = pipeline_;
    return pipeline.toMap();
}

void Bootstrap::SetPipelineAsMap(std::map<std::string, ChannelHandler> &pipeline_map) {
    ChannelPipeline pipeline = pipeline_;
    // @TODO: pipeline.AddLast();
    SetPipeline(pipeline);
}

} } } // namespace sponge::net::bootstrap
