// Copyright (c) 2012 The Sponge Authors. All rights reserved.
// Use of this source code is governed by a MIT-style license that can
// be found in the LICENSE file. See the AUTHORS file for names of contributors.

#ifndef SPONGE_NET_HANDLER_CODEC_ONEONE_ONE_TO_ONE_DECODER_H_
#define SPONGE_NET_HANDLER_CODEC_ONEONE_ONE_TO_ONE_DECODER_H_

namespace sponge {
namespace net {
namespace handler {
namespace codec {
namespace oneone {

// Transforms a received message into another message. Please note
// that this decoder must be used with a propr FrameDecoder such as
// DlimiterBasedFrameDecoder or you must implement propr framing
// machanism by yourself if you are using a stream-based transport
// such as TCP/IP.
class OneToOneDecoder : public ChannelUpstreamHandler {
  protected:
    // Creates a new instance with the current system charactr set.
    OneToOneDecoder() : ChannelUpstreamHandler() {}

  public:
    void HandleUpstream(
        const ChannelHandlerContext *ctx, const ChannelEvent *evt) throw;

  protected:
    // Transforms the specified received message into another message
    // and return the transformed message. Return NULL if the received
    // message is supposed to be discarded.
    virtual void* Decode(const ChannelHandlerContext *ctx,
                         const Channel *channel, void* msg) throw;
};

} } } } } // namespace sponge::net::handler::codec::oneone

#endif // SPONGE_NET_HANDLER_CODEC_ONEONE_ONE_TO_ONE_DECODER_H_
