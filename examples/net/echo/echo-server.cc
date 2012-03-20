// Copyright (c) 2012 The Sponge Authors. All rights reserved.
// Use of this source code is governed by a MIT-style license that can
// be found in the LICENSE file. See the AUTHORS file for names of contributors.

#include "sponge/net/bootstrap/bootstrap.h"
#include "sponge/net/bootstrap/server-bootstrap.h"
#include "sponge/net/channel/channel-event.h"
#include "sponge/net/channel/channel-handler-context.h"
#include "sponge/net/channel/channel-pipeline.h"
#include "sponge/net/channel/message-event.h"

using namespace sponge::net::bootstrap;
using namespace sponge::net::channel;

class EchoServerHandler : public SimpleChannelUpstreamHandler {
  public:
    void MessageReceived(
        const ChannelHandlerContext *ctx, const MessageEvent *e) {
        e->GetChannel().Write(e->GetMessage());
    }
};

class EchoServerPipelineFactory : public ChannelPipelineFactory {
  public:
    ChannelPipeline* GetPipeline() {
        return Channels.pipeline(new EchoServerHandler());
    }
};

int main(int argc, char *argv[]) {
    int port;
    port = (argc > 1) ? atoi(argv[1]) : 8080;

    // Configure the server.
    ServerBootstrap *bootstrap = new ServerBootstrap(
        new ServerSocketChannelFactory(
            Executors.NewCachedThreadPool(),
            Executors.NewCachedThreadPool()));

    // Set up the pipeline factory.
    bootstrap->SetPipelineFactory(new EchoServerPipelineFactory());

    // Bind and start to accept incoming connections.
    bootstrap->Bind(port);
}
