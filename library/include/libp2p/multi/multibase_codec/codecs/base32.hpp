/**
 * Copyright Soramitsu Co., Ltd. All Rights Reserved.
 * SPDX-License-Identifier: Apache-2.0
 */

#ifndef LIBP2P_BASE32_HPP
#define LIBP2P_BASE32_HPP

#include "base_error.hpp"

#include <vocab/expected.h>
#include <libp2p/common/types.hpp>

/**
 * Encode/decode to/from base32 format
 * Implementation is taken from
 * https://github.com/mjg59/tpmtotp/blob/master/base32.c
 */
namespace libp2p::multi::detail {

/**
 * Encode bytes to base32 uppercase string
 * @param bytes to be encoded
 * @return encoded string
 */
std::string encodeBase32Upper(ipfs::ByteView bytes);
/**
 * Encode bytes to base32 lowercase string
 * @param bytes to be encoded
 * @return encoded string
 */
std::string encodeBase32Lower(ipfs::ByteView bytes);

/**
 * Decode base32 uppercase to bytes
 * @param string to be decoded
 * @return decoded bytes in case of success
 */
ipfs::expected<common::ByteArray, BaseError> decodeBase32Upper(
    std::string_view string);

/**
 * Decode base32 lowercase string to bytes
 * @param string to be decoded
 * @return decoded bytes in case of success
 */
ipfs::expected<common::ByteArray, BaseError> decodeBase32Lower(
    std::string_view string);

}  // namespace libp2p::multi::detail

#endif  // LIBP2P_BASE32_HPP
