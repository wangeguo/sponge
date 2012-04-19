// Copyright (c) 2012 The Sponge Authors. All rights reserved.
// Use of this source code is governed by a MIT-style license that can
// be found in the LICENSE file. See the AUTHORS file for names of contributors.

#ifndef SPONGE_NET_HANDLER_CODEC_PROTOBUF_PROTOBUF_VARINT32_LENGTH_FIELD_PREENDER_H_
#define SPONGE_NET_HANDLER_CODEC_PROTOBUF_PROTOBUF_VARINT32_LENGTH_FIELD_PREENDER_H_

namespace sponge {
namespace net {
namespace handler {
namespace codec {
namespace protobuf {

// An encoder that prepends the Google Protocol Buffers Base 128
// Varints integer length field. For example:
//  BEFORE DECODE (300 bytes)       AFTER DECODE (302 bytes)
//  +---------------+               +--------+---------------+
//  | Protobuf Data |-------------->| Length | Protobuf Data |
//  |  (300 bytes)  |               | 0xAC02 |  (300 bytes)  |
//  +---------------+               +--------+---------------+
class ProtobufVarint32LengthFieldPrepender : public OneToOneEncoder {
  public:
    ProtobufVarint32LengthFieldPrepender() : OneToOneEncoder() {}

  protected:
    void* Encode(const ChannelHandlerContext *ctx,
                 const Channel *channel, void *msg);
};

} } } } } // namespace sponge::net::handler::codec::protobuf

#endif // SPONGE_NET_HANDLER_CODEC_PROTOBUF_PROTOBUF_VARINT32_LENGTH_FIELD_PREENDER_H_
