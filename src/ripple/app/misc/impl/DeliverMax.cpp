//------------------------------------------------------------------------------
/*
    This file is part of rippled: https://github.com/ripple/rippled
    Copyright (c) 2023 Ripple Labs Inc.

    Permission to use, copy, modify, and/or distribute this software for any
    purpose  with  or without fee is hereby granted, provided that the above
    copyright notice and this permission notice appear in all copies.

    THE  SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES
    WITH  REGARD  TO  THIS  SOFTWARE  INCLUDING  ALL  IMPLIED  WARRANTIES  OF
    MERCHANTABILITY  AND  FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR
    ANY  SPECIAL ,  DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES
    WHATSOEVER  RESULTING  FROM  LOSS  OF USE, DATA OR PROFITS, WHETHER IN AN
    ACTION  OF  CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF
    OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
*/
//==============================================================================

#include <ripple/app/misc/DeliverMax.h>

#include <ripple/protocol/jss.h>

namespace ripple {
namespace RPC {

void
insertDeliverMax(
    Json::Value& tx_json,
    std::uint16_t txnType,
    unsigned int apiVersion)
{
    if (tx_json.isMember(jss::Amount))
    {
        if (txnType == ttPAYMENT)
        {
            tx_json[jss::DeliverMax] = tx_json[jss::Amount];
            if (apiVersion > 1)
                tx_json.removeMember(jss::Amount);
        }
    }
}

}  // namespace RPC
}  // namespace ripple
