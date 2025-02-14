/**
 * Copyright Soramitsu Co., Ltd. All Rights Reserved.
 * SPDX-License-Identifier: Apache-2.0
 */

#ifndef LIBP2P_MULTIHASH_HPP
#define LIBP2P_MULTIHASH_HPP

#include "vocab/byte_view.h"
#include "vocab/expected.h"

#include <cstdint>
#include <string>
#include <utility>

#include <libp2p/common/types.hpp>
#include <libp2p/multi/hash_type.hpp>

namespace libp2p::multi {

/**
 * Special format of hash used in Libp2p. Allows to differentiate between
 * outputs of different hash functions. More
 * https://github.com/multiformats/multihash
 */
class Multihash {
 public:
  Multihash(const Multihash& other);

  Multihash& operator=(const Multihash& other) = default;

  Multihash(Multihash&& other) noexcept;

  Multihash& operator=(Multihash&& other) noexcept = default;

  ~Multihash() noexcept;

  static constexpr uint8_t kMaxHashLength = 127;

  enum class Error {
    ZERO_INPUT_LENGTH = 1,
    INPUT_TOO_LONG,
    INPUT_TOO_SHORT,
    INCONSISTENT_LENGTH,
    INVALID_HEXADECIMAL_INPUT
  };

  /**
   * @brief Creates a multihash from hash type and the hash itself. Note that
   * the max hash length is 127
   * @param type - numerical code of the hash type.
   * @param hash - binary buffer with the hash
   * @return result with the multihash in case of success
   */
  static ipfs::expected<Multihash, Error> create(HashType type,
                                                 ipfs::ByteView hash);

  /**
   * @brief Creates a multihash from a string, which represents a binary
   * buffer in hexadecimal form. The first byte denotes the hash type, the
   * second one contains the hash length, and the following are the hash
   * itself
   * @param hex - the string with hexadecimal representation of the multihash
   * @return result with the multihash in case of success
   */
  static ipfs::expected<Multihash, Error> createFromHex(std::string_view hex);

  /**
   * @brief Creates a multihash from a binary
   * buffer. The first byte denotes the hash type, the
   * second one contains the hash length, and the following are the hash
   * itself
   * @param b - the buffer with the multihash
   * @return result with the multihash in case of success
   */
  static ipfs::expected<Multihash, Error> createFromBytes(ipfs::ByteView b);

  /**
   * @return the info about hash type
   */
  const HashType& getType() const;

  /**
   * @return the hash stored in this multihash
   */
  ipfs::ByteView getHash() const;

  /**
   * @return a string with hexadecimal representation of the multihash
   */
  std::string toHex() const;

  /**
   * @return a buffer with the multihash, including its type, length and hash
   */
  std::vector<ipfs::Byte> const& toBuffer() const;

  /**
   * @return Pre-calculated hash for std containers
   */
  size_t stdHash() const;

  bool operator==(const Multihash& other) const;

  bool operator!=(const Multihash& other) const;

  bool operator<(const Multihash& other) const;

 private:
  /**
   * Header consists of hash type and hash size, both 1 byte or 2 hex digits
   * long, thus 4 hex digits long in total
   */
  static constexpr uint8_t kHeaderSize = 4;

  /**
   * Constructs a multihash from a type and a hash. Inits length_ with the
   * size of the hash. Does no checks on the validity of provided data, in
   * contrary to public fabric methods
   * @param type - the info about the hash type
   * @param hash - a binary buffer with the hash
   */
  Multihash(HashType type, ipfs::ByteView hash);

  /**
   * Contains a one byte hash type, a one byte hash length, and the stored
   * hash itself
   */
  struct Data {
    // TODO(artem): move to small_vector<const uint8_t, some_size>
    // as soon as toBuffer() -> span<const uint8_t> is acceptable
    std::vector<ipfs::Byte> bytes;
    uint8_t hash_offset{};  ///< size of non-hash data from the beginning
    HashType type;
    size_t std_hash;  ///< Hash for unordered containers

    Data(HashType t, ipfs::ByteView h);

    ~Data() noexcept;
  };

  const Data& data() const;

  std::shared_ptr<const Data> data_;
};

std::string to_string(Multihash::Error);

}  // namespace libp2p::multi

namespace std {
template <>
struct hash<libp2p::multi::Multihash> {
  size_t operator()(const libp2p::multi::Multihash& x) const {
    return x.stdHash();
  }
};
}  // namespace std

#endif  // LIBP2P_MULTIHASH_HPP
