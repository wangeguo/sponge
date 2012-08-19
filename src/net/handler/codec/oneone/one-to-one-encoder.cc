// Copyright (c) 2012 The Sponge Authors. All rights reserved.
// Use of this source code is governed by a MIT-style license that can
// be found in the LICENSE file. See the AUTHORS file for names of contributors.

#include "sponge/net/handler/codec/oneone/one-to-one-encoder.h"

namespace sponge {
namespace net {

void OneToOneEncoder::HandleDownstream(
    const ChannelHandlerContext *ctx, const ChannelEvent *evt) throw {
    if (typeid(evt) != typeid(MessageEvent)) {
        ctx->SendDownstream(evt);
        return;
    }

    MessageEvent e = static_cast<MessageEvent>(evt);
    void* original_message = e.GetMessage();
    void* encoded_message = Encode(ctx, e.GetChannel(), original_message);
    if (original_message == encoded_message)
        ctx->SendDownstream(evt);
    else if (encoded_message != NULL)
        Write(ctx, e.GetFuture(), encoded_message, e.GetRemoteAddress());
}

} } // namespace sponge::net
