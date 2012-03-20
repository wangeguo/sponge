#include <iostream>
#include <string>

using namespace std;

class EchoClientHandler : SimpleChannelUpstreamHandler {
  public:
    EchoClientHandler(int first_message_size) : transferred_bytes_() {
        if (first_message_size <= 0)
            return;
        first_message_ = ChannelBuffers.buffer(first_message_size);
        for (int i = 0; i < first_message_.Capacity(); i++) {
            first_message_.WriteByte(i);
        }
    }

    void ChannelConnected(
        const ChannelHandlerContext &ctx, const ChannelStateEvent &e) {
        e.GetChannel().Write(first_message_);
    }

    void MessageReceived(
        const ChannelHandlerContext &ctx, const MessageEvent &e) {
        transferred_byres_.AddAndGet(
            ((ChannelBuffer) e.GetMessage()).ReadableBytes());
        e.GetChannel().Write(e.GetMessage());
    }

  private:
    ChannelBuffer first_message_;
    AtomicLong transferred_bytes_;
};

class EchoClientPipelineFactory : ChannelPipelineFactory {
  public:
    EchoClientPipelineFactory(int first_message_size)
            : first_message_size_(first_message_size) {}
    
    inline ChannelPipeline GetPipeline() {
        return Channels.pipeline(new EchoClientHandler(first_message_size_));
    }

  private:
    int first_message_size_;
};

int main(int argc, char *argv[]) {
    if (argc < 2 || argc > 3) {
        cout << "Usage: echo-server <host> <port> [<first message size>]\n";
        return;
    }

    string host(argv[1]);
    int port = argv[2];
    int first_message_size;
    if (argc == 3) {
        first_message_size = argv[3];
    } else {
        first_message_size = 256;
    }

    // Configure the client.
    ClientBootstrap bootstrap = new ClientBootstrap(
        new ClientSocketChannelFactory(
            Excutors.NewCachedThreadPool(),
            Excutors.NewCachedThreadPool()));

    // Set up the pipeline factory.
    bootstrap->SetPipelineFactory(
        new EchoClientPipelineFactory(first_message_size));

    // Start the connection attempt.
    ChannelFuture future = bootstrap->connect(host, port);

    // Wait until the connection is closed or the connection attempt fails.
    future.GetChannel().GetCloseFuture().AwaitUninterruptibly();

    // Shut down thread pools and exit.
    bootstrap->ReleaseExternalResources();
    
}
