// Copyright (c) 2012 The Sponge Authors. All rights reserved.
// Use of this source code is governed by a MIT-style license that can
// be found in the LICENSE file. See the AUTHORS file for names of contributors.

#ifndef SPONGE_NET_HANDLER_CODEC_PROTOBUF_PROTOBUF_DECODER_H_
#define SPONGE_NET_HANDLER_CODEC_PROTOBUF_PROTOBUF_DECODER_H_

namespace sponge {
namespace net {
namespace handler {
namespace codec {
namespace protobuf {

// Decodes a received ChannelBuffer into a Google Protocol Buffers
// Message and MessageLite. Please note that this decoder must be used
// with a proper FrameDecoder such as ProtobufVarint32FrameDecoder or
// LenghtFieldBasedFrameDecoder if you are using a stream-based
// transport such as TCP/IP.
class ProtobufDecoder : public OneToOneDecoder {
  public:
    ProtobufDecoder(const MessageLite &prototype)
            : ProtobufDecoder(prototype, NULL) {}

    ProtobufDecoder(const MessageLite &prototype,
                    const ExtensionRegistry &entension_registry);

  protected:
    void* Decode(const ChannelHandlerContext *ctx,
                 const Channel *channel, void* msg);

  private:
    const MessageLite _KPrototype;
    const ExtensionRegistry _kEntensionRegistry;
};

} } } } } // namespace sponge::net::handler::codec::protobuf

#endif // SPONGE_NET_HANDLER_CODEC_PROTOBUF_PROTOBUF_DECODER_H_
