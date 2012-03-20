// Copyright (c) 2012 The Sponge Authors. All rights reserved.
// Use of this source code is governed by a MIT-style license that can
// be found in the LICENSE file. See the AUTHORS file for names of contributors.

#include "sponge/net/bootstrap/client-bootstrap.h"
#include "sponge/net/channel/channel-pipeline.h"

namespace sponge {
namespace net {
namespace bootstrap {

ChannelFuture ClientBootstrap::Connect(const std::string &remote_address,
                                       const std::string &local_address) {
    if (remote_address.empty())
        return NULL;

    ChannelPipeline *pipeline;
    pipeline = GetPipelineFactory()->GetPipeline();

    // Set the options.
    Channel *ch = GetFactory()->NewChannel(pipeline);
    bool success = false;

    try {
        ch->GetConfig()->SetOptions(GetOptions());
        success = true;
    } catch(...) {
        if (!success) {
            ch->Close();
        }
    }

    // Bind
    if (!local_address.empty()) 
        ch->Bind(local_address);

    // Connect
    return ch->Connect(remote_address);
}

} } } // namespace sponge::net::bootstrap
