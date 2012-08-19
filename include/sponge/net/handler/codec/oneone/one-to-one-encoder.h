// Copyright (c) 2012 The Sponge Authors. All rights reserved.
// Use of this source code is governed by a MIT-style license that can
// be found in the LICENSE file. See the AUTHORS file for names of contributors.

#ifndef SPONGE_NET_HANDLER_CODEC_ONEONE_ONE_TO_ONE_ENCODER_H_
#define SPONGE_NET_HANDLER_CODEC_ONEONE_ONE_TO_ONE_ENCODER_H_

namespace sponge {
namespace net {

// Transforms a write request into another write request.
class OneToOneEncoder : public ChannelDownstreamHandler {
  protected:
    OneToOneEncoder() : ChannelDownstreamHandler() {}

  public:
    void HandleDownsream(
        const ChannelHandlerContext *ctx, const ChannelEvent *evt) throw;

  protected:
    // Transforms the specified message into another message and
    // return the transformed message. Note that you can not return
    // NULL, unlike you can in OneToOneDecoder#Decode(const
    // ChannelHandlerContext *, const Channel *, void *) you must
    // return something, at least ChannelBuffer#EMPTY_BUFFER.
    virtual void* Encode(const ChannelHandleContext *ctx,
                         const Channel *channel, void* msg) throw;
};

} } // namespace sponge::net

#endif // SPONGE_NET_HANDLER_CODEC_ONEONE_ONE_TO_ONE_ENCODER_H_
