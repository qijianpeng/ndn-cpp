// Only compile if ndn-cpp-config.h defines NDN_CPP_HAVE_PROTOBUF = 1.
// This will disappear if someone runs protoc again, but then assume we have Protobuf.
#include <ndn-cpp/ndn-cpp-config.h>
#if NDN_CPP_HAVE_PROTOBUF

// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: sync-state.proto

#define INTERNAL_SUPPRESS_PROTOBUF_FIELD_DEPRECATION
#include "sync-state.pb.h"

#include <algorithm>

#include <google/protobuf/stubs/common.h>
#include <google/protobuf/stubs/once.h>
#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/wire_format_lite_inl.h>
#include <google/protobuf/descriptor.h>
#include <google/protobuf/generated_message_reflection.h>
#include <google/protobuf/reflection_ops.h>
#include <google/protobuf/wire_format.h>
// @@protoc_insertion_point(includes)

namespace Sync {

namespace {

const ::google::protobuf::Descriptor* SyncState_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  SyncState_reflection_ = NULL;
const ::google::protobuf::Descriptor* SyncState_SeqNo_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  SyncState_SeqNo_reflection_ = NULL;
const ::google::protobuf::EnumDescriptor* SyncState_ActionType_descriptor_ = NULL;
const ::google::protobuf::Descriptor* SyncStateMsg_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  SyncStateMsg_reflection_ = NULL;

}  // namespace


void protobuf_AssignDesc_sync_2dstate_2eproto() {
  protobuf_AddDesc_sync_2dstate_2eproto();
  const ::google::protobuf::FileDescriptor* file =
    ::google::protobuf::DescriptorPool::generated_pool()->FindFileByName(
      "sync-state.proto");
  GOOGLE_CHECK(file != NULL);
  SyncState_descriptor_ = file->message_type(0);
  static const int SyncState_offsets_[3] = {
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(SyncState, name_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(SyncState, type_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(SyncState, seqno_),
  };
  SyncState_reflection_ =
    new ::google::protobuf::internal::GeneratedMessageReflection(
      SyncState_descriptor_,
      SyncState::default_instance_,
      SyncState_offsets_,
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(SyncState, _has_bits_[0]),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(SyncState, _unknown_fields_),
      -1,
      ::google::protobuf::DescriptorPool::generated_pool(),
      ::google::protobuf::MessageFactory::generated_factory(),
      sizeof(SyncState));
  SyncState_SeqNo_descriptor_ = SyncState_descriptor_->nested_type(0);
  static const int SyncState_SeqNo_offsets_[2] = {
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(SyncState_SeqNo, seq_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(SyncState_SeqNo, session_),
  };
  SyncState_SeqNo_reflection_ =
    new ::google::protobuf::internal::GeneratedMessageReflection(
      SyncState_SeqNo_descriptor_,
      SyncState_SeqNo::default_instance_,
      SyncState_SeqNo_offsets_,
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(SyncState_SeqNo, _has_bits_[0]),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(SyncState_SeqNo, _unknown_fields_),
      -1,
      ::google::protobuf::DescriptorPool::generated_pool(),
      ::google::protobuf::MessageFactory::generated_factory(),
      sizeof(SyncState_SeqNo));
  SyncState_ActionType_descriptor_ = SyncState_descriptor_->enum_type(0);
  SyncStateMsg_descriptor_ = file->message_type(1);
  static const int SyncStateMsg_offsets_[1] = {
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(SyncStateMsg, ss_),
  };
  SyncStateMsg_reflection_ =
    new ::google::protobuf::internal::GeneratedMessageReflection(
      SyncStateMsg_descriptor_,
      SyncStateMsg::default_instance_,
      SyncStateMsg_offsets_,
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(SyncStateMsg, _has_bits_[0]),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(SyncStateMsg, _unknown_fields_),
      -1,
      ::google::protobuf::DescriptorPool::generated_pool(),
      ::google::protobuf::MessageFactory::generated_factory(),
      sizeof(SyncStateMsg));
}

namespace {

GOOGLE_PROTOBUF_DECLARE_ONCE(protobuf_AssignDescriptors_once_);
inline void protobuf_AssignDescriptorsOnce() {
  ::google::protobuf::GoogleOnceInit(&protobuf_AssignDescriptors_once_,
                 &protobuf_AssignDesc_sync_2dstate_2eproto);
}

void protobuf_RegisterTypes(const ::std::string&) {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
    SyncState_descriptor_, &SyncState::default_instance());
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
    SyncState_SeqNo_descriptor_, &SyncState_SeqNo::default_instance());
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
    SyncStateMsg_descriptor_, &SyncStateMsg::default_instance());
}

}  // namespace

void protobuf_ShutdownFile_sync_2dstate_2eproto() {
  delete SyncState::default_instance_;
  delete SyncState_reflection_;
  delete SyncState_SeqNo::default_instance_;
  delete SyncState_SeqNo_reflection_;
  delete SyncStateMsg::default_instance_;
  delete SyncStateMsg_reflection_;
}

void protobuf_AddDesc_sync_2dstate_2eproto() {
  static bool already_here = false;
  if (already_here) return;
  already_here = true;
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  ::google::protobuf::DescriptorPool::InternalAddGeneratedFile(
    "\n\020sync-state.proto\022\004Sync\"\301\001\n\tSyncState\022\014"
    "\n\004name\030\001 \002(\t\022(\n\004type\030\002 \002(\0162\032.Sync.SyncSt"
    "ate.ActionType\022$\n\005seqno\030\003 \001(\0132\025.Sync.Syn"
    "cState.SeqNo\032%\n\005SeqNo\022\013\n\003seq\030\001 \002(\004\022\017\n\007se"
    "ssion\030\002 \002(\004\"/\n\nActionType\022\n\n\006UPDATE\020\000\022\n\n"
    "\006DELETE\020\001\022\t\n\005OTHER\020\002\"+\n\014SyncStateMsg\022\033\n\002"
    "ss\030\001 \003(\0132\017.Sync.SyncState", 265);
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedFile(
    "sync-state.proto", &protobuf_RegisterTypes);
  SyncState::default_instance_ = new SyncState();
  SyncState_SeqNo::default_instance_ = new SyncState_SeqNo();
  SyncStateMsg::default_instance_ = new SyncStateMsg();
  SyncState::default_instance_->InitAsDefaultInstance();
  SyncState_SeqNo::default_instance_->InitAsDefaultInstance();
  SyncStateMsg::default_instance_->InitAsDefaultInstance();
  ::google::protobuf::internal::OnShutdown(&protobuf_ShutdownFile_sync_2dstate_2eproto);
}

// Force AddDescriptors() to be called at static initialization time.
struct StaticDescriptorInitializer_sync_2dstate_2eproto {
  StaticDescriptorInitializer_sync_2dstate_2eproto() {
    protobuf_AddDesc_sync_2dstate_2eproto();
  }
} static_descriptor_initializer_sync_2dstate_2eproto_;

// ===================================================================

const ::google::protobuf::EnumDescriptor* SyncState_ActionType_descriptor() {
  protobuf_AssignDescriptorsOnce();
  return SyncState_ActionType_descriptor_;
}
bool SyncState_ActionType_IsValid(int value) {
  switch(value) {
    case 0:
    case 1:
    case 2:
      return true;
    default:
      return false;
  }
}

#ifndef _MSC_VER
const SyncState_ActionType SyncState::UPDATE;
const SyncState_ActionType SyncState::DELETE;
const SyncState_ActionType SyncState::OTHER;
const SyncState_ActionType SyncState::ActionType_MIN;
const SyncState_ActionType SyncState::ActionType_MAX;
const int SyncState::ActionType_ARRAYSIZE;
#endif  // _MSC_VER
#ifndef _MSC_VER
const int SyncState_SeqNo::kSeqFieldNumber;
const int SyncState_SeqNo::kSessionFieldNumber;
#endif  // !_MSC_VER

SyncState_SeqNo::SyncState_SeqNo()
  : ::google::protobuf::Message() {
  SharedCtor();
}

void SyncState_SeqNo::InitAsDefaultInstance() {
}

SyncState_SeqNo::SyncState_SeqNo(const SyncState_SeqNo& from)
  : ::google::protobuf::Message() {
  SharedCtor();
  MergeFrom(from);
}

void SyncState_SeqNo::SharedCtor() {
  _cached_size_ = 0;
  seq_ = GOOGLE_ULONGLONG(0);
  session_ = GOOGLE_ULONGLONG(0);
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

SyncState_SeqNo::~SyncState_SeqNo() {
  SharedDtor();
}

void SyncState_SeqNo::SharedDtor() {
  if (this != default_instance_) {
  }
}

void SyncState_SeqNo::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* SyncState_SeqNo::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return SyncState_SeqNo_descriptor_;
}

const SyncState_SeqNo& SyncState_SeqNo::default_instance() {
  if (default_instance_ == NULL) protobuf_AddDesc_sync_2dstate_2eproto();
  return *default_instance_;
}

SyncState_SeqNo* SyncState_SeqNo::default_instance_ = NULL;

SyncState_SeqNo* SyncState_SeqNo::New() const {
  return new SyncState_SeqNo;
}

void SyncState_SeqNo::Clear() {
  if (_has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    seq_ = GOOGLE_ULONGLONG(0);
    session_ = GOOGLE_ULONGLONG(0);
  }
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
  mutable_unknown_fields()->Clear();
}

bool SyncState_SeqNo::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!(EXPRESSION)) return false
  ::google::protobuf::uint32 tag;
  while ((tag = input->ReadTag()) != 0) {
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // required uint64 seq = 1;
      case 1: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_VARINT) {
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::uint64, ::google::protobuf::internal::WireFormatLite::TYPE_UINT64>(
                 input, &seq_)));
          set_has_seq();
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectTag(16)) goto parse_session;
        break;
      }

      // required uint64 session = 2;
      case 2: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_VARINT) {
         parse_session:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::uint64, ::google::protobuf::internal::WireFormatLite::TYPE_UINT64>(
                 input, &session_)));
          set_has_session();
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectAtEnd()) return true;
        break;
      }

      default: {
      handle_uninterpreted:
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_END_GROUP) {
          return true;
        }
        DO_(::google::protobuf::internal::WireFormat::SkipField(
              input, tag, mutable_unknown_fields()));
        break;
      }
    }
  }
  return true;
#undef DO_
}

void SyncState_SeqNo::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // required uint64 seq = 1;
  if (has_seq()) {
    ::google::protobuf::internal::WireFormatLite::WriteUInt64(1, this->seq(), output);
  }

  // required uint64 session = 2;
  if (has_session()) {
    ::google::protobuf::internal::WireFormatLite::WriteUInt64(2, this->session(), output);
  }

  if (!unknown_fields().empty()) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        unknown_fields(), output);
  }
}

::google::protobuf::uint8* SyncState_SeqNo::SerializeWithCachedSizesToArray(
    ::google::protobuf::uint8* target) const {
  // required uint64 seq = 1;
  if (has_seq()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteUInt64ToArray(1, this->seq(), target);
  }

  // required uint64 session = 2;
  if (has_session()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteUInt64ToArray(2, this->session(), target);
  }

  if (!unknown_fields().empty()) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        unknown_fields(), target);
  }
  return target;
}

int SyncState_SeqNo::ByteSize() const {
  int total_size = 0;

  if (_has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    // required uint64 seq = 1;
    if (has_seq()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::UInt64Size(
          this->seq());
    }

    // required uint64 session = 2;
    if (has_session()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::UInt64Size(
          this->session());
    }

  }
  if (!unknown_fields().empty()) {
    total_size +=
      ::google::protobuf::internal::WireFormat::ComputeUnknownFieldsSize(
        unknown_fields());
  }
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = total_size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
  return total_size;
}

void SyncState_SeqNo::MergeFrom(const ::google::protobuf::Message& from) {
  GOOGLE_CHECK_NE(&from, this);
  const SyncState_SeqNo* source =
    ::google::protobuf::internal::dynamic_cast_if_available<const SyncState_SeqNo*>(
      &from);
  if (source == NULL) {
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
    MergeFrom(*source);
  }
}

void SyncState_SeqNo::MergeFrom(const SyncState_SeqNo& from) {
  GOOGLE_CHECK_NE(&from, this);
  if (from._has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    if (from.has_seq()) {
      set_seq(from.seq());
    }
    if (from.has_session()) {
      set_session(from.session());
    }
  }
  mutable_unknown_fields()->MergeFrom(from.unknown_fields());
}

void SyncState_SeqNo::CopyFrom(const ::google::protobuf::Message& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void SyncState_SeqNo::CopyFrom(const SyncState_SeqNo& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool SyncState_SeqNo::IsInitialized() const {
  if ((_has_bits_[0] & 0x00000003) != 0x00000003) return false;

  return true;
}

void SyncState_SeqNo::Swap(SyncState_SeqNo* other) {
  if (other != this) {
    std::swap(seq_, other->seq_);
    std::swap(session_, other->session_);
    std::swap(_has_bits_[0], other->_has_bits_[0]);
    _unknown_fields_.Swap(&other->_unknown_fields_);
    std::swap(_cached_size_, other->_cached_size_);
  }
}

::google::protobuf::Metadata SyncState_SeqNo::GetMetadata() const {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::Metadata metadata;
  metadata.descriptor = SyncState_SeqNo_descriptor_;
  metadata.reflection = SyncState_SeqNo_reflection_;
  return metadata;
}


// -------------------------------------------------------------------

#ifndef _MSC_VER
const int SyncState::kNameFieldNumber;
const int SyncState::kTypeFieldNumber;
const int SyncState::kSeqnoFieldNumber;
#endif  // !_MSC_VER

SyncState::SyncState()
  : ::google::protobuf::Message() {
  SharedCtor();
}

void SyncState::InitAsDefaultInstance() {
  seqno_ = const_cast< ::Sync::SyncState_SeqNo*>(&::Sync::SyncState_SeqNo::default_instance());
}

SyncState::SyncState(const SyncState& from)
  : ::google::protobuf::Message() {
  SharedCtor();
  MergeFrom(from);
}

void SyncState::SharedCtor() {
  _cached_size_ = 0;
  name_ = const_cast< ::std::string*>(&::google::protobuf::internal::kEmptyString);
  type_ = 0;
  seqno_ = NULL;
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

SyncState::~SyncState() {
  SharedDtor();
}

void SyncState::SharedDtor() {
  if (name_ != &::google::protobuf::internal::kEmptyString) {
    delete name_;
  }
  if (this != default_instance_) {
    delete seqno_;
  }
}

void SyncState::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* SyncState::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return SyncState_descriptor_;
}

const SyncState& SyncState::default_instance() {
  if (default_instance_ == NULL) protobuf_AddDesc_sync_2dstate_2eproto();
  return *default_instance_;
}

SyncState* SyncState::default_instance_ = NULL;

SyncState* SyncState::New() const {
  return new SyncState;
}

void SyncState::Clear() {
  if (_has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    if (has_name()) {
      if (name_ != &::google::protobuf::internal::kEmptyString) {
        name_->clear();
      }
    }
    type_ = 0;
    if (has_seqno()) {
      if (seqno_ != NULL) seqno_->::Sync::SyncState_SeqNo::Clear();
    }
  }
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
  mutable_unknown_fields()->Clear();
}

bool SyncState::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!(EXPRESSION)) return false
  ::google::protobuf::uint32 tag;
  while ((tag = input->ReadTag()) != 0) {
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // required string name = 1;
      case 1: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_LENGTH_DELIMITED) {
          DO_(::google::protobuf::internal::WireFormatLite::ReadString(
                input, this->mutable_name()));
          ::google::protobuf::internal::WireFormat::VerifyUTF8String(
            this->name().data(), this->name().length(),
            ::google::protobuf::internal::WireFormat::PARSE);
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectTag(16)) goto parse_type;
        break;
      }

      // required .Sync.SyncState.ActionType type = 2;
      case 2: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_VARINT) {
         parse_type:
          int value;
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   int, ::google::protobuf::internal::WireFormatLite::TYPE_ENUM>(
                 input, &value)));
          if (::Sync::SyncState_ActionType_IsValid(value)) {
            set_type(static_cast< ::Sync::SyncState_ActionType >(value));
          } else {
            mutable_unknown_fields()->AddVarint(2, value);
          }
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectTag(26)) goto parse_seqno;
        break;
      }

      // optional .Sync.SyncState.SeqNo seqno = 3;
      case 3: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_LENGTH_DELIMITED) {
         parse_seqno:
          DO_(::google::protobuf::internal::WireFormatLite::ReadMessageNoVirtual(
               input, mutable_seqno()));
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectAtEnd()) return true;
        break;
      }

      default: {
      handle_uninterpreted:
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_END_GROUP) {
          return true;
        }
        DO_(::google::protobuf::internal::WireFormat::SkipField(
              input, tag, mutable_unknown_fields()));
        break;
      }
    }
  }
  return true;
#undef DO_
}

void SyncState::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // required string name = 1;
  if (has_name()) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8String(
      this->name().data(), this->name().length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE);
    ::google::protobuf::internal::WireFormatLite::WriteString(
      1, this->name(), output);
  }

  // required .Sync.SyncState.ActionType type = 2;
  if (has_type()) {
    ::google::protobuf::internal::WireFormatLite::WriteEnum(
      2, this->type(), output);
  }

  // optional .Sync.SyncState.SeqNo seqno = 3;
  if (has_seqno()) {
    ::google::protobuf::internal::WireFormatLite::WriteMessageMaybeToArray(
      3, this->seqno(), output);
  }

  if (!unknown_fields().empty()) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        unknown_fields(), output);
  }
}

::google::protobuf::uint8* SyncState::SerializeWithCachedSizesToArray(
    ::google::protobuf::uint8* target) const {
  // required string name = 1;
  if (has_name()) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8String(
      this->name().data(), this->name().length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE);
    target =
      ::google::protobuf::internal::WireFormatLite::WriteStringToArray(
        1, this->name(), target);
  }

  // required .Sync.SyncState.ActionType type = 2;
  if (has_type()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteEnumToArray(
      2, this->type(), target);
  }

  // optional .Sync.SyncState.SeqNo seqno = 3;
  if (has_seqno()) {
    target = ::google::protobuf::internal::WireFormatLite::
      WriteMessageNoVirtualToArray(
        3, this->seqno(), target);
  }

  if (!unknown_fields().empty()) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        unknown_fields(), target);
  }
  return target;
}

int SyncState::ByteSize() const {
  int total_size = 0;

  if (_has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    // required string name = 1;
    if (has_name()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::StringSize(
          this->name());
    }

    // required .Sync.SyncState.ActionType type = 2;
    if (has_type()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::EnumSize(this->type());
    }

    // optional .Sync.SyncState.SeqNo seqno = 3;
    if (has_seqno()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::MessageSizeNoVirtual(
          this->seqno());
    }

  }
  if (!unknown_fields().empty()) {
    total_size +=
      ::google::protobuf::internal::WireFormat::ComputeUnknownFieldsSize(
        unknown_fields());
  }
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = total_size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
  return total_size;
}

void SyncState::MergeFrom(const ::google::protobuf::Message& from) {
  GOOGLE_CHECK_NE(&from, this);
  const SyncState* source =
    ::google::protobuf::internal::dynamic_cast_if_available<const SyncState*>(
      &from);
  if (source == NULL) {
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
    MergeFrom(*source);
  }
}

void SyncState::MergeFrom(const SyncState& from) {
  GOOGLE_CHECK_NE(&from, this);
  if (from._has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    if (from.has_name()) {
      set_name(from.name());
    }
    if (from.has_type()) {
      set_type(from.type());
    }
    if (from.has_seqno()) {
      mutable_seqno()->::Sync::SyncState_SeqNo::MergeFrom(from.seqno());
    }
  }
  mutable_unknown_fields()->MergeFrom(from.unknown_fields());
}

void SyncState::CopyFrom(const ::google::protobuf::Message& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void SyncState::CopyFrom(const SyncState& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool SyncState::IsInitialized() const {
  if ((_has_bits_[0] & 0x00000003) != 0x00000003) return false;

  if (has_seqno()) {
    if (!this->seqno().IsInitialized()) return false;
  }
  return true;
}

void SyncState::Swap(SyncState* other) {
  if (other != this) {
    std::swap(name_, other->name_);
    std::swap(type_, other->type_);
    std::swap(seqno_, other->seqno_);
    std::swap(_has_bits_[0], other->_has_bits_[0]);
    _unknown_fields_.Swap(&other->_unknown_fields_);
    std::swap(_cached_size_, other->_cached_size_);
  }
}

::google::protobuf::Metadata SyncState::GetMetadata() const {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::Metadata metadata;
  metadata.descriptor = SyncState_descriptor_;
  metadata.reflection = SyncState_reflection_;
  return metadata;
}


// ===================================================================

#ifndef _MSC_VER
const int SyncStateMsg::kSsFieldNumber;
#endif  // !_MSC_VER

SyncStateMsg::SyncStateMsg()
  : ::google::protobuf::Message() {
  SharedCtor();
}

void SyncStateMsg::InitAsDefaultInstance() {
}

SyncStateMsg::SyncStateMsg(const SyncStateMsg& from)
  : ::google::protobuf::Message() {
  SharedCtor();
  MergeFrom(from);
}

void SyncStateMsg::SharedCtor() {
  _cached_size_ = 0;
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

SyncStateMsg::~SyncStateMsg() {
  SharedDtor();
}

void SyncStateMsg::SharedDtor() {
  if (this != default_instance_) {
  }
}

void SyncStateMsg::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* SyncStateMsg::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return SyncStateMsg_descriptor_;
}

const SyncStateMsg& SyncStateMsg::default_instance() {
  if (default_instance_ == NULL) protobuf_AddDesc_sync_2dstate_2eproto();
  return *default_instance_;
}

SyncStateMsg* SyncStateMsg::default_instance_ = NULL;

SyncStateMsg* SyncStateMsg::New() const {
  return new SyncStateMsg;
}

void SyncStateMsg::Clear() {
  ss_.Clear();
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
  mutable_unknown_fields()->Clear();
}

bool SyncStateMsg::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!(EXPRESSION)) return false
  ::google::protobuf::uint32 tag;
  while ((tag = input->ReadTag()) != 0) {
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // repeated .Sync.SyncState ss = 1;
      case 1: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_LENGTH_DELIMITED) {
         parse_ss:
          DO_(::google::protobuf::internal::WireFormatLite::ReadMessageNoVirtual(
                input, add_ss()));
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectTag(10)) goto parse_ss;
        if (input->ExpectAtEnd()) return true;
        break;
      }

      default: {
      handle_uninterpreted:
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_END_GROUP) {
          return true;
        }
        DO_(::google::protobuf::internal::WireFormat::SkipField(
              input, tag, mutable_unknown_fields()));
        break;
      }
    }
  }
  return true;
#undef DO_
}

void SyncStateMsg::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // repeated .Sync.SyncState ss = 1;
  for (int i = 0; i < this->ss_size(); i++) {
    ::google::protobuf::internal::WireFormatLite::WriteMessageMaybeToArray(
      1, this->ss(i), output);
  }

  if (!unknown_fields().empty()) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        unknown_fields(), output);
  }
}

::google::protobuf::uint8* SyncStateMsg::SerializeWithCachedSizesToArray(
    ::google::protobuf::uint8* target) const {
  // repeated .Sync.SyncState ss = 1;
  for (int i = 0; i < this->ss_size(); i++) {
    target = ::google::protobuf::internal::WireFormatLite::
      WriteMessageNoVirtualToArray(
        1, this->ss(i), target);
  }

  if (!unknown_fields().empty()) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        unknown_fields(), target);
  }
  return target;
}

int SyncStateMsg::ByteSize() const {
  int total_size = 0;

  // repeated .Sync.SyncState ss = 1;
  total_size += 1 * this->ss_size();
  for (int i = 0; i < this->ss_size(); i++) {
    total_size +=
      ::google::protobuf::internal::WireFormatLite::MessageSizeNoVirtual(
        this->ss(i));
  }

  if (!unknown_fields().empty()) {
    total_size +=
      ::google::protobuf::internal::WireFormat::ComputeUnknownFieldsSize(
        unknown_fields());
  }
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = total_size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
  return total_size;
}

void SyncStateMsg::MergeFrom(const ::google::protobuf::Message& from) {
  GOOGLE_CHECK_NE(&from, this);
  const SyncStateMsg* source =
    ::google::protobuf::internal::dynamic_cast_if_available<const SyncStateMsg*>(
      &from);
  if (source == NULL) {
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
    MergeFrom(*source);
  }
}

void SyncStateMsg::MergeFrom(const SyncStateMsg& from) {
  GOOGLE_CHECK_NE(&from, this);
  ss_.MergeFrom(from.ss_);
  mutable_unknown_fields()->MergeFrom(from.unknown_fields());
}

void SyncStateMsg::CopyFrom(const ::google::protobuf::Message& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void SyncStateMsg::CopyFrom(const SyncStateMsg& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool SyncStateMsg::IsInitialized() const {

  for (int i = 0; i < ss_size(); i++) {
    if (!this->ss(i).IsInitialized()) return false;
  }
  return true;
}

void SyncStateMsg::Swap(SyncStateMsg* other) {
  if (other != this) {
    ss_.Swap(&other->ss_);
    std::swap(_has_bits_[0], other->_has_bits_[0]);
    _unknown_fields_.Swap(&other->_unknown_fields_);
    std::swap(_cached_size_, other->_cached_size_);
  }
}

::google::protobuf::Metadata SyncStateMsg::GetMetadata() const {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::Metadata metadata;
  metadata.descriptor = SyncStateMsg_descriptor_;
  metadata.reflection = SyncStateMsg_reflection_;
  return metadata;
}


// @@protoc_insertion_point(namespace_scope)

}  // namespace Sync

// @@protoc_insertion_point(global_scope)

#endif // NDN_CPP_HAVE_PROTOBUF