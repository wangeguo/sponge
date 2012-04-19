// Copyright (c) 2012 The Sponge Authors. All rights reserved.
// Use of this source code is governed by a MIT-style license that can
// be found in the LICENSE file. See the AUTHORS file for names of contributors.

#ifndef SPONGE_NET_HANDLER_CODEC_PROTOBUF_PROTOBUF_ENCODER_H_
#define SPONGE_NET_HANDLER_CODEC_PROTOBUF_PROTOBUF_ENCODER_H_

namespace sponge {
namespace net {
namespace handler {
namespace codec {
namespace protobuf {

// Encodes the requested Google Protocol Buffers Message and
// MessageLite into a ChannelBuffer.
class ProtobufEncoder : public OneToOneEncoder {
  public:
    ProtobufEncoder() : OneToOneEncoder() {}

  protected:
    void* Encode(const ChannelHandlerContext *ctx,
                 const Channel *channel, void* msg);
};

} } } } } // namespace sponge::net::handler::codec::protobuf

#endif // SPONGE_NET_HANDLER_CODEC_PROTOBUF_PROTOBUF_ENCODER_H_
