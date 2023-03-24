#include <ipfs_client/ipns_record.h>

#include <libp2p/multi/content_identifier_codec.hpp>
#include <libp2p/multi/multibase_codec.hpp>
#include <libp2p/peer/peer_id.hpp>

#include <gtest/gtest.h>

TEST(IpnsRecordTest, AKnownKuboRecord) {
  std::array<std::uint8_t, 400> xxd{
      0x0a, 0x41, 0x2f, 0x69, 0x70, 0x66, 0x73, 0x2f, 0x62, 0x61, 0x66, 0x79,
      0x62, 0x65, 0x69, 0x67, 0x35, 0x37, 0x74, 0x32, 0x64, 0x70, 0x34, 0x33,
      0x35, 0x61, 0x75, 0x70, 0x74, 0x74, 0x69, 0x6c, 0x69, 0x6d, 0x64, 0x36,
      0x37, 0x36, 0x37, 0x6b, 0x70, 0x70, 0x66, 0x65, 0x62, 0x61, 0x61, 0x33,
      0x67, 0x6e, 0x75, 0x6e, 0x6d, 0x71, 0x64, 0x65, 0x6e, 0x36, 0x36, 0x64,
      0x67, 0x6b, 0x68, 0x75, 0x67, 0x77, 0x69, 0x12, 0x40, 0xba, 0xde, 0xd1,
      0xdb, 0x61, 0xc6, 0x41, 0x84, 0xfb, 0x62, 0x8b, 0xff, 0x2d, 0x1d, 0x24,
      0x33, 0xb9, 0x25, 0x95, 0xe0, 0x27, 0x27, 0x59, 0x8b, 0x32, 0xae, 0x61,
      0x70, 0x79, 0x94, 0xd2, 0x79, 0xb7, 0x58, 0x46, 0x1e, 0x18, 0x12, 0xb5,
      0xaa, 0xcf, 0x6c, 0x09, 0x7b, 0xf7, 0xad, 0xd0, 0xbe, 0xa7, 0x76, 0x49,
      0x02, 0x6a, 0xd3, 0x82, 0x3b, 0xc8, 0x18, 0x45, 0xc6, 0x35, 0x22, 0xd3,
      0x0d, 0x18, 0x00, 0x22, 0x1e, 0x32, 0x30, 0x32, 0x33, 0x2d, 0x30, 0x33,
      0x2d, 0x32, 0x34, 0x54, 0x30, 0x35, 0x3a, 0x31, 0x30, 0x3a, 0x30, 0x32,
      0x2e, 0x31, 0x36, 0x31, 0x31, 0x36, 0x32, 0x33, 0x32, 0x31, 0x5a, 0x28,
      0x80, 0x03, 0x30, 0x80, 0xb0, 0x9d, 0xc2, 0xdf, 0x01, 0x42, 0x40, 0xfc,
      0x7f, 0xa0, 0x06, 0xe8, 0x36, 0x03, 0xef, 0x1b, 0x5d, 0x3d, 0x9a, 0x57,
      0x74, 0xcf, 0xce, 0x92, 0x83, 0x3d, 0xc6, 0x2b, 0x93, 0x54, 0x11, 0x6e,
      0x7e, 0xcb, 0x1e, 0x2c, 0x8b, 0xc6, 0x09, 0x8e, 0xe3, 0xb6, 0xb0, 0x0e,
      0xaa, 0x2a, 0x3f, 0xee, 0xe1, 0x29, 0xe4, 0x6d, 0x4f, 0xf7, 0x40, 0x8f,
      0x1c, 0x89, 0x05, 0x01, 0x9a, 0x67, 0xf0, 0xa5, 0x7c, 0x34, 0xf0, 0xe3,
      0xb8, 0xb0, 0x0c, 0x4a, 0x9a, 0x01, 0xa5, 0x63, 0x54, 0x54, 0x4c, 0x1b,
      0x00, 0x00, 0x00, 0x0d, 0xf8, 0x47, 0x58, 0x00, 0x65, 0x56, 0x61, 0x6c,
      0x75, 0x65, 0x58, 0x41, 0x2f, 0x69, 0x70, 0x66, 0x73, 0x2f, 0x62, 0x61,
      0x66, 0x79, 0x62, 0x65, 0x69, 0x67, 0x35, 0x37, 0x74, 0x32, 0x64, 0x70,
      0x34, 0x33, 0x35, 0x61, 0x75, 0x70, 0x74, 0x74, 0x69, 0x6c, 0x69, 0x6d,
      0x64, 0x36, 0x37, 0x36, 0x37, 0x6b, 0x70, 0x70, 0x66, 0x65, 0x62, 0x61,
      0x61, 0x33, 0x67, 0x6e, 0x75, 0x6e, 0x6d, 0x71, 0x64, 0x65, 0x6e, 0x36,
      0x36, 0x64, 0x67, 0x6b, 0x68, 0x75, 0x67, 0x77, 0x69, 0x68, 0x53, 0x65,
      0x71, 0x75, 0x65, 0x6e, 0x63, 0x65, 0x19, 0x01, 0x80, 0x68, 0x56, 0x61,
      0x6c, 0x69, 0x64, 0x69, 0x74, 0x79, 0x58, 0x1e, 0x32, 0x30, 0x32, 0x33,
      0x2d, 0x30, 0x33, 0x2d, 0x32, 0x34, 0x54, 0x30, 0x35, 0x3a, 0x31, 0x30,
      0x3a, 0x30, 0x32, 0x2e, 0x31, 0x36, 0x31, 0x31, 0x36, 0x32, 0x33, 0x32,
      0x31, 0x5a, 0x6c, 0x56, 0x61, 0x6c, 0x69, 0x64, 0x69, 0x74, 0x79, 0x54,
      0x79, 0x70, 0x65, 0x00};
  ipfs::ByteView known_record{reinterpret_cast<ipfs::Byte const*>(xxd.data()),
                              xxd.size()};
  //  auto my_name_res = libp2p::peer::PeerId::FromMultibase(
  //      "bafzaajaiaejcaxykhmgsz2mhscluhm6bkliibattya2l2lld7scqr64c4ine2u7c");
  //    libp2p::peer::PeerId::FromMultibase("k51qzi5uqu5dijv526o4z2z10ejylnel0bfvrtw53itcmsecffo8yf0zb4g9gi");
  auto c = libp2p::multi::ContentIdentifierCodec::fromString(
      "bafzaajaiaejcaxykhmgsz2mhscluhm6bkliibattya2l2lld7scqr64c4ine2u7c");
  EXPECT_TRUE(c.has_value());
  auto& ci = c.value();
  EXPECT_TRUE(ci.version == libp2p::multi::ContentIdentifier::Version::V1);
  EXPECT_TRUE(ci.content_type ==
              libp2p::multi::MulticodecType::Code::LIBP2P_KEY);
  //  EXPECT_TRUE(ci.content_address.getType() ==
  //  libp2p::multi::HashType::sha256); auto hash =
  //  ci.content_address.getHash();
  auto my_name_res = libp2p::peer::PeerId::fromHash(ci.content_address);

  //  auto my_name_res =
  //  libp2p::peer::PeerId::fromBase58("12D3KooWGDMwwqrpcYKpKCgxuKT2NfqPqa94QnkoBBpqvCaiCzWd");
  ASSERT_TRUE(my_name_res.has_value());
  auto& my_name = my_name_res.value();
  auto result = ipfs::ValidateIpnsRecord(known_record, my_name);
  std::string_view expected{
      "/ipfs/bafybeig57t2dp435aupttilimd6767kppfebaa3gnunmqden66dgkhugwi"};
  EXPECT_EQ(result, expected);
}
