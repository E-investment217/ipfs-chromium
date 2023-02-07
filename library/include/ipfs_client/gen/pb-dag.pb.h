// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: pb-dag.proto

#ifndef GOOGLE_PROTOBUF_INCLUDED_pb_2ddag_2eproto
#define GOOGLE_PROTOBUF_INCLUDED_pb_2ddag_2eproto

#include <limits>
#include <string>

#include <google/protobuf/port_def.inc>
#if PROTOBUF_VERSION < 3019000
#error This file was generated by a newer version of protoc which is
#error incompatible with your Protocol Buffer headers. Please update
#error your headers.
#endif
#if 3019004 < PROTOBUF_MIN_PROTOC_VERSION
#error This file was generated by an older version of protoc which is
#error incompatible with your Protocol Buffer headers. Please
#error regenerate this file with a newer version of protoc.
#endif

#include <google/protobuf/port_undef.inc>
#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/arena.h>
#include <google/protobuf/arenastring.h>
#include <google/protobuf/generated_message_table_driven.h>
#include <google/protobuf/generated_message_util.h>
#include <google/protobuf/metadata_lite.h>
#include <google/protobuf/generated_message_reflection.h>
#include <google/protobuf/message.h>
#include <google/protobuf/repeated_field.h>  // IWYU pragma: export
#include <google/protobuf/extension_set.h>  // IWYU pragma: export
#include <google/protobuf/unknown_field_set.h>
// @@protoc_insertion_point(includes)
#include <google/protobuf/port_def.inc>
#define PROTOBUF_INTERNAL_EXPORT_pb_2ddag_2eproto
PROTOBUF_NAMESPACE_OPEN
namespace internal {
class AnyMetadata;
}  // namespace internal
PROTOBUF_NAMESPACE_CLOSE

// Internal implementation detail -- do not use these members.
struct TableStruct_pb_2ddag_2eproto {
  static const ::PROTOBUF_NAMESPACE_ID::internal::ParseTableField entries[]
    PROTOBUF_SECTION_VARIABLE(protodesc_cold);
  static const ::PROTOBUF_NAMESPACE_ID::internal::AuxiliaryParseTableField aux[]
    PROTOBUF_SECTION_VARIABLE(protodesc_cold);
  static const ::PROTOBUF_NAMESPACE_ID::internal::ParseTable schema[2]
    PROTOBUF_SECTION_VARIABLE(protodesc_cold);
  static const ::PROTOBUF_NAMESPACE_ID::internal::FieldMetadata field_metadata[];
  static const ::PROTOBUF_NAMESPACE_ID::internal::SerializationTable serialization_table[];
  static const uint32_t offsets[];
};
extern const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable descriptor_table_pb_2ddag_2eproto;
class PBLink;
struct PBLinkDefaultTypeInternal;
extern PBLinkDefaultTypeInternal _PBLink_default_instance_;
class PBNode;
struct PBNodeDefaultTypeInternal;
extern PBNodeDefaultTypeInternal _PBNode_default_instance_;
PROTOBUF_NAMESPACE_OPEN
template<> ::PBLink* Arena::CreateMaybeMessage<::PBLink>(Arena*);
template<> ::PBNode* Arena::CreateMaybeMessage<::PBNode>(Arena*);
PROTOBUF_NAMESPACE_CLOSE

// ===================================================================

class PBLink final :
    public ::PROTOBUF_NAMESPACE_ID::Message /* @@protoc_insertion_point(class_definition:PBLink) */ {
 public:
  inline PBLink() : PBLink(nullptr) {}
  ~PBLink() override;
  explicit constexpr PBLink(::PROTOBUF_NAMESPACE_ID::internal::ConstantInitialized);

  PBLink(const PBLink& from);
  PBLink(PBLink&& from) noexcept
    : PBLink() {
    *this = ::std::move(from);
  }

  inline PBLink& operator=(const PBLink& from) {
    CopyFrom(from);
    return *this;
  }
  inline PBLink& operator=(PBLink&& from) noexcept {
    if (this == &from) return *this;
    if (GetOwningArena() == from.GetOwningArena()
  #ifdef PROTOBUF_FORCE_COPY_IN_MOVE
        && GetOwningArena() != nullptr
  #endif  // !PROTOBUF_FORCE_COPY_IN_MOVE
    ) {
      InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }

  inline const ::PROTOBUF_NAMESPACE_ID::UnknownFieldSet& unknown_fields() const {
    return _internal_metadata_.unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(::PROTOBUF_NAMESPACE_ID::UnknownFieldSet::default_instance);
  }
  inline ::PROTOBUF_NAMESPACE_ID::UnknownFieldSet* mutable_unknown_fields() {
    return _internal_metadata_.mutable_unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>();
  }

  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* descriptor() {
    return GetDescriptor();
  }
  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* GetDescriptor() {
    return default_instance().GetMetadata().descriptor;
  }
  static const ::PROTOBUF_NAMESPACE_ID::Reflection* GetReflection() {
    return default_instance().GetMetadata().reflection;
  }
  static const PBLink& default_instance() {
    return *internal_default_instance();
  }
  static inline const PBLink* internal_default_instance() {
    return reinterpret_cast<const PBLink*>(
               &_PBLink_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    0;

  friend void swap(PBLink& a, PBLink& b) {
    a.Swap(&b);
  }
  inline void Swap(PBLink* other) {
    if (other == this) return;
  #ifdef PROTOBUF_FORCE_COPY_IN_SWAP
    if (GetOwningArena() != nullptr &&
        GetOwningArena() == other->GetOwningArena()) {
   #else  // PROTOBUF_FORCE_COPY_IN_SWAP
    if (GetOwningArena() == other->GetOwningArena()) {
  #endif  // !PROTOBUF_FORCE_COPY_IN_SWAP
      InternalSwap(other);
    } else {
      ::PROTOBUF_NAMESPACE_ID::internal::GenericSwap(this, other);
    }
  }
  void UnsafeArenaSwap(PBLink* other) {
    if (other == this) return;
    GOOGLE_DCHECK(GetOwningArena() == other->GetOwningArena());
    InternalSwap(other);
  }

  // implements Message ----------------------------------------------

  PBLink* New(::PROTOBUF_NAMESPACE_ID::Arena* arena = nullptr) const final {
    return CreateMaybeMessage<PBLink>(arena);
  }
  using ::PROTOBUF_NAMESPACE_ID::Message::CopyFrom;
  void CopyFrom(const PBLink& from);
  using ::PROTOBUF_NAMESPACE_ID::Message::MergeFrom;
  void MergeFrom(const PBLink& from);
  private:
  static void MergeImpl(::PROTOBUF_NAMESPACE_ID::Message* to, const ::PROTOBUF_NAMESPACE_ID::Message& from);
  public:
  PROTOBUF_ATTRIBUTE_REINITIALIZES void Clear() final;
  bool IsInitialized() const final;

  size_t ByteSizeLong() const final;
  const char* _InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) final;
  uint8_t* _InternalSerialize(
      uint8_t* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const final;
  int GetCachedSize() const final { return _cached_size_.Get(); }

  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const final;
  void InternalSwap(PBLink* other);

  private:
  friend class ::PROTOBUF_NAMESPACE_ID::internal::AnyMetadata;
  static ::PROTOBUF_NAMESPACE_ID::StringPiece FullMessageName() {
    return "PBLink";
  }
  protected:
  explicit PBLink(::PROTOBUF_NAMESPACE_ID::Arena* arena,
                       bool is_message_owned = false);
  private:
  static void ArenaDtor(void* object);
  inline void RegisterArenaDtor(::PROTOBUF_NAMESPACE_ID::Arena* arena);
  public:

  static const ClassData _class_data_;
  const ::PROTOBUF_NAMESPACE_ID::Message::ClassData*GetClassData() const final;

  ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadata() const final;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  enum : int {
    kHashFieldNumber = 1,
    kNameFieldNumber = 2,
    kTsizeFieldNumber = 3,
  };
  // optional bytes Hash = 1;
  bool has_hash() const;
  private:
  bool _internal_has_hash() const;
  public:
  void clear_hash();
  const std::string& hash() const;
  template <typename ArgT0 = const std::string&, typename... ArgT>
  void set_hash(ArgT0&& arg0, ArgT... args);
  std::string* mutable_hash();
  PROTOBUF_NODISCARD std::string* release_hash();
  void set_allocated_hash(std::string* hash);
  private:
  const std::string& _internal_hash() const;
  inline PROTOBUF_ALWAYS_INLINE void _internal_set_hash(const std::string& value);
  std::string* _internal_mutable_hash();
  public:

  // optional string Name = 2;
  bool has_name() const;
  private:
  bool _internal_has_name() const;
  public:
  void clear_name();
  const std::string& name() const;
  template <typename ArgT0 = const std::string&, typename... ArgT>
  void set_name(ArgT0&& arg0, ArgT... args);
  std::string* mutable_name();
  PROTOBUF_NODISCARD std::string* release_name();
  void set_allocated_name(std::string* name);
  private:
  const std::string& _internal_name() const;
  inline PROTOBUF_ALWAYS_INLINE void _internal_set_name(const std::string& value);
  std::string* _internal_mutable_name();
  public:

  // optional uint64 Tsize = 3;
  bool has_tsize() const;
  private:
  bool _internal_has_tsize() const;
  public:
  void clear_tsize();
  uint64_t tsize() const;
  void set_tsize(uint64_t value);
  private:
  uint64_t _internal_tsize() const;
  void _internal_set_tsize(uint64_t value);
  public:

  // @@protoc_insertion_point(class_scope:PBLink)
 private:
  class _Internal;

  template <typename T> friend class ::PROTOBUF_NAMESPACE_ID::Arena::InternalHelper;
  typedef void InternalArenaConstructable_;
  typedef void DestructorSkippable_;
  ::PROTOBUF_NAMESPACE_ID::internal::HasBits<1> _has_bits_;
  mutable ::PROTOBUF_NAMESPACE_ID::internal::CachedSize _cached_size_;
  ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr hash_;
  ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr name_;
  uint64_t tsize_;
  friend struct ::TableStruct_pb_2ddag_2eproto;
};
// -------------------------------------------------------------------

class PBNode final :
    public ::PROTOBUF_NAMESPACE_ID::Message /* @@protoc_insertion_point(class_definition:PBNode) */ {
 public:
  inline PBNode() : PBNode(nullptr) {}
  ~PBNode() override;
  explicit constexpr PBNode(::PROTOBUF_NAMESPACE_ID::internal::ConstantInitialized);

  PBNode(const PBNode& from);
  PBNode(PBNode&& from) noexcept
    : PBNode() {
    *this = ::std::move(from);
  }

  inline PBNode& operator=(const PBNode& from) {
    CopyFrom(from);
    return *this;
  }
  inline PBNode& operator=(PBNode&& from) noexcept {
    if (this == &from) return *this;
    if (GetOwningArena() == from.GetOwningArena()
  #ifdef PROTOBUF_FORCE_COPY_IN_MOVE
        && GetOwningArena() != nullptr
  #endif  // !PROTOBUF_FORCE_COPY_IN_MOVE
    ) {
      InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }

  inline const ::PROTOBUF_NAMESPACE_ID::UnknownFieldSet& unknown_fields() const {
    return _internal_metadata_.unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(::PROTOBUF_NAMESPACE_ID::UnknownFieldSet::default_instance);
  }
  inline ::PROTOBUF_NAMESPACE_ID::UnknownFieldSet* mutable_unknown_fields() {
    return _internal_metadata_.mutable_unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>();
  }

  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* descriptor() {
    return GetDescriptor();
  }
  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* GetDescriptor() {
    return default_instance().GetMetadata().descriptor;
  }
  static const ::PROTOBUF_NAMESPACE_ID::Reflection* GetReflection() {
    return default_instance().GetMetadata().reflection;
  }
  static const PBNode& default_instance() {
    return *internal_default_instance();
  }
  static inline const PBNode* internal_default_instance() {
    return reinterpret_cast<const PBNode*>(
               &_PBNode_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    1;

  friend void swap(PBNode& a, PBNode& b) {
    a.Swap(&b);
  }
  inline void Swap(PBNode* other) {
    if (other == this) return;
  #ifdef PROTOBUF_FORCE_COPY_IN_SWAP
    if (GetOwningArena() != nullptr &&
        GetOwningArena() == other->GetOwningArena()) {
   #else  // PROTOBUF_FORCE_COPY_IN_SWAP
    if (GetOwningArena() == other->GetOwningArena()) {
  #endif  // !PROTOBUF_FORCE_COPY_IN_SWAP
      InternalSwap(other);
    } else {
      ::PROTOBUF_NAMESPACE_ID::internal::GenericSwap(this, other);
    }
  }
  void UnsafeArenaSwap(PBNode* other) {
    if (other == this) return;
    GOOGLE_DCHECK(GetOwningArena() == other->GetOwningArena());
    InternalSwap(other);
  }

  // implements Message ----------------------------------------------

  PBNode* New(::PROTOBUF_NAMESPACE_ID::Arena* arena = nullptr) const final {
    return CreateMaybeMessage<PBNode>(arena);
  }
  using ::PROTOBUF_NAMESPACE_ID::Message::CopyFrom;
  void CopyFrom(const PBNode& from);
  using ::PROTOBUF_NAMESPACE_ID::Message::MergeFrom;
  void MergeFrom(const PBNode& from);
  private:
  static void MergeImpl(::PROTOBUF_NAMESPACE_ID::Message* to, const ::PROTOBUF_NAMESPACE_ID::Message& from);
  public:
  PROTOBUF_ATTRIBUTE_REINITIALIZES void Clear() final;
  bool IsInitialized() const final;

  size_t ByteSizeLong() const final;
  const char* _InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) final;
  uint8_t* _InternalSerialize(
      uint8_t* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const final;
  int GetCachedSize() const final { return _cached_size_.Get(); }

  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const final;
  void InternalSwap(PBNode* other);

  private:
  friend class ::PROTOBUF_NAMESPACE_ID::internal::AnyMetadata;
  static ::PROTOBUF_NAMESPACE_ID::StringPiece FullMessageName() {
    return "PBNode";
  }
  protected:
  explicit PBNode(::PROTOBUF_NAMESPACE_ID::Arena* arena,
                       bool is_message_owned = false);
  private:
  static void ArenaDtor(void* object);
  inline void RegisterArenaDtor(::PROTOBUF_NAMESPACE_ID::Arena* arena);
  public:

  static const ClassData _class_data_;
  const ::PROTOBUF_NAMESPACE_ID::Message::ClassData*GetClassData() const final;

  ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadata() const final;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  enum : int {
    kLinksFieldNumber = 2,
    kDataFieldNumber = 1,
  };
  // repeated .PBLink Links = 2;
  int links_size() const;
  private:
  int _internal_links_size() const;
  public:
  void clear_links();
  ::PBLink* mutable_links(int index);
  ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField< ::PBLink >*
      mutable_links();
  private:
  const ::PBLink& _internal_links(int index) const;
  ::PBLink* _internal_add_links();
  public:
  const ::PBLink& links(int index) const;
  ::PBLink* add_links();
  const ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField< ::PBLink >&
      links() const;

  // optional bytes Data = 1;
  bool has_data() const;
  private:
  bool _internal_has_data() const;
  public:
  void clear_data();
  const std::string& data() const;
  template <typename ArgT0 = const std::string&, typename... ArgT>
  void set_data(ArgT0&& arg0, ArgT... args);
  std::string* mutable_data();
  PROTOBUF_NODISCARD std::string* release_data();
  void set_allocated_data(std::string* data);
  private:
  const std::string& _internal_data() const;
  inline PROTOBUF_ALWAYS_INLINE void _internal_set_data(const std::string& value);
  std::string* _internal_mutable_data();
  public:

  // @@protoc_insertion_point(class_scope:PBNode)
 private:
  class _Internal;

  template <typename T> friend class ::PROTOBUF_NAMESPACE_ID::Arena::InternalHelper;
  typedef void InternalArenaConstructable_;
  typedef void DestructorSkippable_;
  ::PROTOBUF_NAMESPACE_ID::internal::HasBits<1> _has_bits_;
  mutable ::PROTOBUF_NAMESPACE_ID::internal::CachedSize _cached_size_;
  ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField< ::PBLink > links_;
  ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr data_;
  friend struct ::TableStruct_pb_2ddag_2eproto;
};
// ===================================================================


// ===================================================================

#ifdef __GNUC__
  #pragma GCC diagnostic push
  #pragma GCC diagnostic ignored "-Wstrict-aliasing"
#endif  // __GNUC__
// PBLink

// optional bytes Hash = 1;
inline bool PBLink::_internal_has_hash() const {
  bool value = (_has_bits_[0] & 0x00000001u) != 0;
  return value;
}
inline bool PBLink::has_hash() const {
  return _internal_has_hash();
}
inline void PBLink::clear_hash() {
  hash_.ClearToEmpty();
  _has_bits_[0] &= ~0x00000001u;
}
inline const std::string& PBLink::hash() const {
  // @@protoc_insertion_point(field_get:PBLink.Hash)
  return _internal_hash();
}
template <typename ArgT0, typename... ArgT>
inline PROTOBUF_ALWAYS_INLINE
void PBLink::set_hash(ArgT0&& arg0, ArgT... args) {
 _has_bits_[0] |= 0x00000001u;
 hash_.SetBytes(::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, static_cast<ArgT0 &&>(arg0), args..., GetArenaForAllocation());
  // @@protoc_insertion_point(field_set:PBLink.Hash)
}
inline std::string* PBLink::mutable_hash() {
  std::string* _s = _internal_mutable_hash();
  // @@protoc_insertion_point(field_mutable:PBLink.Hash)
  return _s;
}
inline const std::string& PBLink::_internal_hash() const {
  return hash_.Get();
}
inline void PBLink::_internal_set_hash(const std::string& value) {
  _has_bits_[0] |= 0x00000001u;
  hash_.Set(::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, value, GetArenaForAllocation());
}
inline std::string* PBLink::_internal_mutable_hash() {
  _has_bits_[0] |= 0x00000001u;
  return hash_.Mutable(::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, GetArenaForAllocation());
}
inline std::string* PBLink::release_hash() {
  // @@protoc_insertion_point(field_release:PBLink.Hash)
  if (!_internal_has_hash()) {
    return nullptr;
  }
  _has_bits_[0] &= ~0x00000001u;
  auto* p = hash_.ReleaseNonDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), GetArenaForAllocation());
#ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
  if (hash_.IsDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited())) {
    hash_.Set(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), "", GetArenaForAllocation());
  }
#endif // PROTOBUF_FORCE_COPY_DEFAULT_STRING
  return p;
}
inline void PBLink::set_allocated_hash(std::string* hash) {
  if (hash != nullptr) {
    _has_bits_[0] |= 0x00000001u;
  } else {
    _has_bits_[0] &= ~0x00000001u;
  }
  hash_.SetAllocated(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), hash,
      GetArenaForAllocation());
#ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
  if (hash_.IsDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited())) {
    hash_.Set(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), "", GetArenaForAllocation());
  }
#endif // PROTOBUF_FORCE_COPY_DEFAULT_STRING
  // @@protoc_insertion_point(field_set_allocated:PBLink.Hash)
}

// optional string Name = 2;
inline bool PBLink::_internal_has_name() const {
  bool value = (_has_bits_[0] & 0x00000002u) != 0;
  return value;
}
inline bool PBLink::has_name() const {
  return _internal_has_name();
}
inline void PBLink::clear_name() {
  name_.ClearToEmpty();
  _has_bits_[0] &= ~0x00000002u;
}
inline const std::string& PBLink::name() const {
  // @@protoc_insertion_point(field_get:PBLink.Name)
  return _internal_name();
}
template <typename ArgT0, typename... ArgT>
inline PROTOBUF_ALWAYS_INLINE
void PBLink::set_name(ArgT0&& arg0, ArgT... args) {
 _has_bits_[0] |= 0x00000002u;
 name_.Set(::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, static_cast<ArgT0 &&>(arg0), args..., GetArenaForAllocation());
  // @@protoc_insertion_point(field_set:PBLink.Name)
}
inline std::string* PBLink::mutable_name() {
  std::string* _s = _internal_mutable_name();
  // @@protoc_insertion_point(field_mutable:PBLink.Name)
  return _s;
}
inline const std::string& PBLink::_internal_name() const {
  return name_.Get();
}
inline void PBLink::_internal_set_name(const std::string& value) {
  _has_bits_[0] |= 0x00000002u;
  name_.Set(::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, value, GetArenaForAllocation());
}
inline std::string* PBLink::_internal_mutable_name() {
  _has_bits_[0] |= 0x00000002u;
  return name_.Mutable(::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, GetArenaForAllocation());
}
inline std::string* PBLink::release_name() {
  // @@protoc_insertion_point(field_release:PBLink.Name)
  if (!_internal_has_name()) {
    return nullptr;
  }
  _has_bits_[0] &= ~0x00000002u;
  auto* p = name_.ReleaseNonDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), GetArenaForAllocation());
#ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
  if (name_.IsDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited())) {
    name_.Set(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), "", GetArenaForAllocation());
  }
#endif // PROTOBUF_FORCE_COPY_DEFAULT_STRING
  return p;
}
inline void PBLink::set_allocated_name(std::string* name) {
  if (name != nullptr) {
    _has_bits_[0] |= 0x00000002u;
  } else {
    _has_bits_[0] &= ~0x00000002u;
  }
  name_.SetAllocated(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), name,
      GetArenaForAllocation());
#ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
  if (name_.IsDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited())) {
    name_.Set(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), "", GetArenaForAllocation());
  }
#endif // PROTOBUF_FORCE_COPY_DEFAULT_STRING
  // @@protoc_insertion_point(field_set_allocated:PBLink.Name)
}

// optional uint64 Tsize = 3;
inline bool PBLink::_internal_has_tsize() const {
  bool value = (_has_bits_[0] & 0x00000004u) != 0;
  return value;
}
inline bool PBLink::has_tsize() const {
  return _internal_has_tsize();
}
inline void PBLink::clear_tsize() {
  tsize_ = uint64_t{0u};
  _has_bits_[0] &= ~0x00000004u;
}
inline uint64_t PBLink::_internal_tsize() const {
  return tsize_;
}
inline uint64_t PBLink::tsize() const {
  // @@protoc_insertion_point(field_get:PBLink.Tsize)
  return _internal_tsize();
}
inline void PBLink::_internal_set_tsize(uint64_t value) {
  _has_bits_[0] |= 0x00000004u;
  tsize_ = value;
}
inline void PBLink::set_tsize(uint64_t value) {
  _internal_set_tsize(value);
  // @@protoc_insertion_point(field_set:PBLink.Tsize)
}

// -------------------------------------------------------------------

// PBNode

// repeated .PBLink Links = 2;
inline int PBNode::_internal_links_size() const {
  return links_.size();
}
inline int PBNode::links_size() const {
  return _internal_links_size();
}
inline void PBNode::clear_links() {
  links_.Clear();
}
inline ::PBLink* PBNode::mutable_links(int index) {
  // @@protoc_insertion_point(field_mutable:PBNode.Links)
  return links_.Mutable(index);
}
inline ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField< ::PBLink >*
PBNode::mutable_links() {
  // @@protoc_insertion_point(field_mutable_list:PBNode.Links)
  return &links_;
}
inline const ::PBLink& PBNode::_internal_links(int index) const {
  return links_.Get(index);
}
inline const ::PBLink& PBNode::links(int index) const {
  // @@protoc_insertion_point(field_get:PBNode.Links)
  return _internal_links(index);
}
inline ::PBLink* PBNode::_internal_add_links() {
  return links_.Add();
}
inline ::PBLink* PBNode::add_links() {
  ::PBLink* _add = _internal_add_links();
  // @@protoc_insertion_point(field_add:PBNode.Links)
  return _add;
}
inline const ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField< ::PBLink >&
PBNode::links() const {
  // @@protoc_insertion_point(field_list:PBNode.Links)
  return links_;
}

// optional bytes Data = 1;
inline bool PBNode::_internal_has_data() const {
  bool value = (_has_bits_[0] & 0x00000001u) != 0;
  return value;
}
inline bool PBNode::has_data() const {
  return _internal_has_data();
}
inline void PBNode::clear_data() {
  data_.ClearToEmpty();
  _has_bits_[0] &= ~0x00000001u;
}
inline const std::string& PBNode::data() const {
  // @@protoc_insertion_point(field_get:PBNode.Data)
  return _internal_data();
}
template <typename ArgT0, typename... ArgT>
inline PROTOBUF_ALWAYS_INLINE
void PBNode::set_data(ArgT0&& arg0, ArgT... args) {
 _has_bits_[0] |= 0x00000001u;
 data_.SetBytes(::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, static_cast<ArgT0 &&>(arg0), args..., GetArenaForAllocation());
  // @@protoc_insertion_point(field_set:PBNode.Data)
}
inline std::string* PBNode::mutable_data() {
  std::string* _s = _internal_mutable_data();
  // @@protoc_insertion_point(field_mutable:PBNode.Data)
  return _s;
}
inline const std::string& PBNode::_internal_data() const {
  return data_.Get();
}
inline void PBNode::_internal_set_data(const std::string& value) {
  _has_bits_[0] |= 0x00000001u;
  data_.Set(::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, value, GetArenaForAllocation());
}
inline std::string* PBNode::_internal_mutable_data() {
  _has_bits_[0] |= 0x00000001u;
  return data_.Mutable(::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr::EmptyDefault{}, GetArenaForAllocation());
}
inline std::string* PBNode::release_data() {
  // @@protoc_insertion_point(field_release:PBNode.Data)
  if (!_internal_has_data()) {
    return nullptr;
  }
  _has_bits_[0] &= ~0x00000001u;
  auto* p = data_.ReleaseNonDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), GetArenaForAllocation());
#ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
  if (data_.IsDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited())) {
    data_.Set(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), "", GetArenaForAllocation());
  }
#endif // PROTOBUF_FORCE_COPY_DEFAULT_STRING
  return p;
}
inline void PBNode::set_allocated_data(std::string* data) {
  if (data != nullptr) {
    _has_bits_[0] |= 0x00000001u;
  } else {
    _has_bits_[0] &= ~0x00000001u;
  }
  data_.SetAllocated(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), data,
      GetArenaForAllocation());
#ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
  if (data_.IsDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited())) {
    data_.Set(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), "", GetArenaForAllocation());
  }
#endif // PROTOBUF_FORCE_COPY_DEFAULT_STRING
  // @@protoc_insertion_point(field_set_allocated:PBNode.Data)
}

#ifdef __GNUC__
  #pragma GCC diagnostic pop
#endif  // __GNUC__
// -------------------------------------------------------------------


// @@protoc_insertion_point(namespace_scope)


// @@protoc_insertion_point(global_scope)

#include <google/protobuf/port_undef.inc>
#endif  // GOOGLE_PROTOBUF_INCLUDED_GOOGLE_PROTOBUF_INCLUDED_pb_2ddag_2eproto
