/**
 * Copyright Soramitsu Co., Ltd. All Rights Reserved.
 * SPDX-License-Identifier: Apache-2.0
 */

#include <libp2p/multi/multibase_codec/multibase_codec_impl.hpp>

#include "log_macros.h"

#include <unordered_map>

#include <libp2p/multi/multibase_codec/codecs/base16.h>
#include <libp2p/multi/multibase_codec/codecs/base32.hpp>
#include <libp2p/multi/multibase_codec/codecs/base36.hpp>
#include <libp2p/multi/multibase_codec/codecs/base58.hpp>

namespace {
using namespace libp2p::multi;          // NOLINT
using namespace libp2p::multi::detail;  // NOLINT

/**
 * Get the encoding by a character
 * @param ch of encoding
 * @return related encoding, if character stands for one of them, none
 * otherwise
 */
std::optional<MultibaseCodec::Encoding> encodingByChar(char ch) {
  switch (ch) {
    case 'f':
      return MultibaseCodec::Encoding::BASE16_LOWER;
    case 'F':
      return MultibaseCodec::Encoding::BASE16_UPPER;
    case 'b':
      return MultibaseCodec::Encoding::BASE32_LOWER;
    case 'B':
      return MultibaseCodec::Encoding::BASE32_UPPER;
    case 'k':
      return MultibaseCodec::Encoding::BASE36;
    case 'z':
      return MultibaseCodec::Encoding::BASE58;
    case 'm':
      return MultibaseCodec::Encoding::BASE64;
    default:
      return std::nullopt;
  }
}

struct CodecFunctions {
  using EncodeFuncType = decltype(encodeBase58);
  using DecodeFuncType = decltype(decodeBase58);

  EncodeFuncType* encode;
  DecodeFuncType* decode;
};


/// all available codec functions
const std::unordered_map<MultibaseCodec::Encoding, CodecFunctions> codecs{
    {MultibaseCodec::Encoding::BASE16_UPPER,
     CodecFunctions{&ipfs::base16::encodeUpper, &ipfs::base16::decode}},
    {MultibaseCodec::Encoding::BASE16_LOWER,
     CodecFunctions{&ipfs::base16::encodeLower, &ipfs::base16::decode}},
    {MultibaseCodec::Encoding::BASE32_UPPER,
     CodecFunctions{&encodeBase32Upper, &decodeBase32Upper}},
    {MultibaseCodec::Encoding::BASE32_LOWER,
     CodecFunctions{&encodeBase32Lower, &decodeBase32Lower}},
    {MultibaseCodec::Encoding::BASE36,
     CodecFunctions{&encodeBase36Lower, &decodeBase36}},
    {MultibaseCodec::Encoding::BASE58,
     CodecFunctions{&encodeBase58, &decodeBase58}}
    //,    {MultibaseCodec::Encoding::BASE64,CodecFunctions{&todo_encode,
    //    &todo_decode}}
};
}  // namespace

namespace libp2p::multi {
using common::ByteArray;

std::string MultibaseCodecImpl::encode(const ByteArray& bytes,
                                       Encoding encoding) const {
  if (bytes.empty()) {
    return "";
  }

  return static_cast<char>(encoding) + codecs.at(encoding).encode(bytes);
}

auto MultibaseCodecImpl::decode(std::string_view string) const
    -> FactoryResult {
  if (string.length() < 2) {
    return ipfs::unexpected<Error>{Error::INPUT_TOO_SHORT};
  }

  auto encoding_base = encodingByChar(string.front());
  if (!encoding_base) {
    return ipfs::unexpected<Error>{Error::UNSUPPORTED_BASE};
  }
  auto codec = codecs.find(*encoding_base);
  if (codecs.end() == codec) {
    return ipfs::unexpected<Error>{Error::UNSUPPORTED_BASE};
  }
  auto result = codec->second.decode(string.substr(1));
  if (result.has_value()) {
    return result.value();
  } else {
    return ipfs::unexpected<Error>{Error::BASE_CODEC_ERROR};
  }
}
}  // namespace libp2p::multi

bool libp2p::multi::case_critical(MultibaseCodec::Encoding e) {
  using E = MultibaseCodec::Encoding;
  switch (e) {
    case E::BASE16_LOWER:
    case E::BASE16_UPPER:
    case E::BASE32_LOWER:
    case E::BASE32_UPPER:
    case E::BASE36:
      return false;
    case E::BASE58:
    case E::BASE64:
      return true;
  }
  LOG(FATAL) << "TODO implement encode for this multibase encoding "
             << static_cast<char>(e);
  return false;
}
