// Copyright (c) 2012 The Sponge Authors. All rights reserved.
// Use of this source code is governed by a MIT-style license that can
// be found in the LICENSE file. See the AUTHORS file for names of contributors.

#include "sponge/net/handler/codec/oneone/one-to-to-decoder.h"

namespace sponge {
namespace net {
namespace handler {
namespace codec {
namespace oneone {

void OneToOneDecoder::HandleUpstream(
    const ChannelHandlerContext *ctx, const ChannelEvent *evt) throw {
    if (typeid(evt) != typeid(MessageEvent)) {
        ctx->SendUpstream(evt);
        return;
    }

    MessageEvent e = static_cast<MessageEvet>(evt);
    void* original_message = e.GetMessage();
    void* decoded_message = Decode(ctx, e.GetChannel(), original_message);
    if (original_message == decoded_message)
        ctx->SendUpstream(evt);
    else if (decoded_message != NULL)
        FireMessageReceived(ctx, decoded_message, e.GetRemoteAddress());
}

} } } } } // namespace sponge::net::handler::codec::oneone
