// Copyright (c) 2012 The Sponge Authors. All rights reserved.
// Use of this source code is governed by a MIT-style license that can
// be found in the LICENSE file. See the AUTHORS file for names of contributors.

#ifndef SPONGE_NET_HANDLER_CODEC_PROTOBUF_PROTOBUF_VARINT32_FRAME_DECODER_H_
#define SPONGE_NET_HANDLER_CODEC_PROTOBUF_PROTOBUF_VARINT32_FRAME_DECODER_H_

namespace sponge {
namespace net {
namespace handler {
namespace codec {
namespace protobuf {

// A decoder that splits the received ChannelBuffers dynamically by
// the value of the Google Protocol Buffers Base 128 Varints integer
// length field in the message. For example:
// BEFORE DECODE (302 bytes)       AFTER DECODE (300 bytes)
// +--------+---------------+      +---------------+
// | Length | Protobuf Data |----->| Protobuf Data |
// | 0xAC02 |  (300 bytes)  |      |  (300 bytes)  |
// +--------+---------------+      +---------------+
class ProtobufVarint32FrameDecoder : public FrameDecoder {
  public:
    ProtobufVarint32FrameDecoder() : FrameDecoder() {}

  protected:
    void* Decode(const ChannelHandlerContext *ctx,
                 const Channel *channel, const ChannelBuffer *buffer);
};

} } } } } // namespace sponge::net::handler::codec::protobuf

#endif // SPONGE_NET_HANDLER_CODEC_PROTOBUF_PROTOBUF_VARINT32_FRAME_DECODER_H_
