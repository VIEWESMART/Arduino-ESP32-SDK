/* Generated by the protocol buffer compiler.  DO NOT EDIT! */
/* Generated from: sec2.proto */

#ifndef PROTOBUF_C_sec2_2eproto__INCLUDED
#define PROTOBUF_C_sec2_2eproto__INCLUDED

#include <protobuf-c/protobuf-c.h>

PROTOBUF_C__BEGIN_DECLS

#if PROTOBUF_C_VERSION_NUMBER < 1003000
# error This file was generated by a newer version of protoc-c which is incompatible with your libprotobuf-c headers. Please update your headers.
#elif 1004000 < PROTOBUF_C_MIN_COMPILER_VERSION
# error This file was generated by an older version of protoc-c which is incompatible with your libprotobuf-c headers. Please regenerate this file with a newer version of protoc-c.
#endif

#include "constants.pb-c.h"

typedef struct S2SessionCmd0 S2SessionCmd0;
typedef struct S2SessionResp0 S2SessionResp0;
typedef struct S2SessionCmd1 S2SessionCmd1;
typedef struct S2SessionResp1 S2SessionResp1;
typedef struct Sec2Payload Sec2Payload;


/* --- enums --- */

/*
 * A message must be of type Cmd0 / Cmd1 / Resp0 / Resp1 
 */
typedef enum _Sec2MsgType {
  SEC2_MSG_TYPE__S2Session_Command0 = 0,
  SEC2_MSG_TYPE__S2Session_Response0 = 1,
  SEC2_MSG_TYPE__S2Session_Command1 = 2,
  SEC2_MSG_TYPE__S2Session_Response1 = 3
    PROTOBUF_C__FORCE_ENUM_TO_BE_INT_SIZE(SEC2_MSG_TYPE)
} Sec2MsgType;

/* --- messages --- */

/*
 * Data structure of Session command0 packet 
 */
struct  S2SessionCmd0
{
  ProtobufCMessage base;
  ProtobufCBinaryData client_username;
  ProtobufCBinaryData client_pubkey;
};
#define S2_SESSION_CMD0__INIT \
 { PROTOBUF_C_MESSAGE_INIT (&s2_session_cmd0__descriptor) \
    , {0,NULL}, {0,NULL} }


/*
 * Data structure of Session response0 packet 
 */
struct  S2SessionResp0
{
  ProtobufCMessage base;
  Status status;
  ProtobufCBinaryData device_pubkey;
  ProtobufCBinaryData device_salt;
};
#define S2_SESSION_RESP0__INIT \
 { PROTOBUF_C_MESSAGE_INIT (&s2_session_resp0__descriptor) \
    , STATUS__Success, {0,NULL}, {0,NULL} }


/*
 * Data structure of Session command1 packet 
 */
struct  S2SessionCmd1
{
  ProtobufCMessage base;
  ProtobufCBinaryData client_proof;
};
#define S2_SESSION_CMD1__INIT \
 { PROTOBUF_C_MESSAGE_INIT (&s2_session_cmd1__descriptor) \
    , {0,NULL} }


/*
 * Data structure of Session response1 packet 
 */
struct  S2SessionResp1
{
  ProtobufCMessage base;
  Status status;
  ProtobufCBinaryData device_proof;
  ProtobufCBinaryData device_nonce;
};
#define S2_SESSION_RESP1__INIT \
 { PROTOBUF_C_MESSAGE_INIT (&s2_session_resp1__descriptor) \
    , STATUS__Success, {0,NULL}, {0,NULL} }


typedef enum {
  SEC2_PAYLOAD__PAYLOAD__NOT_SET = 0,
  SEC2_PAYLOAD__PAYLOAD_SC0 = 20,
  SEC2_PAYLOAD__PAYLOAD_SR0 = 21,
  SEC2_PAYLOAD__PAYLOAD_SC1 = 22,
  SEC2_PAYLOAD__PAYLOAD_SR1 = 23
    PROTOBUF_C__FORCE_ENUM_TO_BE_INT_SIZE(SEC2_PAYLOAD__PAYLOAD__CASE)
} Sec2Payload__PayloadCase;

/*
 * Payload structure of session data 
 */
struct  Sec2Payload
{
  ProtobufCMessage base;
  /*
   *!< Type of message 
   */
  Sec2MsgType msg;
  Sec2Payload__PayloadCase payload_case;
  union {
    /*
     *!< Payload data interpreted as Cmd0 
     */
    S2SessionCmd0 *sc0;
    /*
     *!< Payload data interpreted as Resp0 
     */
    S2SessionResp0 *sr0;
    /*
     *!< Payload data interpreted as Cmd1 
     */
    S2SessionCmd1 *sc1;
    /*
     *!< Payload data interpreted as Resp1 
     */
    S2SessionResp1 *sr1;
  };
};
#define SEC2_PAYLOAD__INIT \
 { PROTOBUF_C_MESSAGE_INIT (&sec2_payload__descriptor) \
    , SEC2_MSG_TYPE__S2Session_Command0, SEC2_PAYLOAD__PAYLOAD__NOT_SET, {0} }


/* S2SessionCmd0 methods */
void   s2_session_cmd0__init
                     (S2SessionCmd0         *message);
size_t s2_session_cmd0__get_packed_size
                     (const S2SessionCmd0   *message);
size_t s2_session_cmd0__pack
                     (const S2SessionCmd0   *message,
                      uint8_t             *out);
size_t s2_session_cmd0__pack_to_buffer
                     (const S2SessionCmd0   *message,
                      ProtobufCBuffer     *buffer);
S2SessionCmd0 *
       s2_session_cmd0__unpack
                     (ProtobufCAllocator  *allocator,
                      size_t               len,
                      const uint8_t       *data);
void   s2_session_cmd0__free_unpacked
                     (S2SessionCmd0 *message,
                      ProtobufCAllocator *allocator);
/* S2SessionResp0 methods */
void   s2_session_resp0__init
                     (S2SessionResp0         *message);
size_t s2_session_resp0__get_packed_size
                     (const S2SessionResp0   *message);
size_t s2_session_resp0__pack
                     (const S2SessionResp0   *message,
                      uint8_t             *out);
size_t s2_session_resp0__pack_to_buffer
                     (const S2SessionResp0   *message,
                      ProtobufCBuffer     *buffer);
S2SessionResp0 *
       s2_session_resp0__unpack
                     (ProtobufCAllocator  *allocator,
                      size_t               len,
                      const uint8_t       *data);
void   s2_session_resp0__free_unpacked
                     (S2SessionResp0 *message,
                      ProtobufCAllocator *allocator);
/* S2SessionCmd1 methods */
void   s2_session_cmd1__init
                     (S2SessionCmd1         *message);
size_t s2_session_cmd1__get_packed_size
                     (const S2SessionCmd1   *message);
size_t s2_session_cmd1__pack
                     (const S2SessionCmd1   *message,
                      uint8_t             *out);
size_t s2_session_cmd1__pack_to_buffer
                     (const S2SessionCmd1   *message,
                      ProtobufCBuffer     *buffer);
S2SessionCmd1 *
       s2_session_cmd1__unpack
                     (ProtobufCAllocator  *allocator,
                      size_t               len,
                      const uint8_t       *data);
void   s2_session_cmd1__free_unpacked
                     (S2SessionCmd1 *message,
                      ProtobufCAllocator *allocator);
/* S2SessionResp1 methods */
void   s2_session_resp1__init
                     (S2SessionResp1         *message);
size_t s2_session_resp1__get_packed_size
                     (const S2SessionResp1   *message);
size_t s2_session_resp1__pack
                     (const S2SessionResp1   *message,
                      uint8_t             *out);
size_t s2_session_resp1__pack_to_buffer
                     (const S2SessionResp1   *message,
                      ProtobufCBuffer     *buffer);
S2SessionResp1 *
       s2_session_resp1__unpack
                     (ProtobufCAllocator  *allocator,
                      size_t               len,
                      const uint8_t       *data);
void   s2_session_resp1__free_unpacked
                     (S2SessionResp1 *message,
                      ProtobufCAllocator *allocator);
/* Sec2Payload methods */
void   sec2_payload__init
                     (Sec2Payload         *message);
size_t sec2_payload__get_packed_size
                     (const Sec2Payload   *message);
size_t sec2_payload__pack
                     (const Sec2Payload   *message,
                      uint8_t             *out);
size_t sec2_payload__pack_to_buffer
                     (const Sec2Payload   *message,
                      ProtobufCBuffer     *buffer);
Sec2Payload *
       sec2_payload__unpack
                     (ProtobufCAllocator  *allocator,
                      size_t               len,
                      const uint8_t       *data);
void   sec2_payload__free_unpacked
                     (Sec2Payload *message,
                      ProtobufCAllocator *allocator);
/* --- per-message closures --- */

typedef void (*S2SessionCmd0_Closure)
                 (const S2SessionCmd0 *message,
                  void *closure_data);
typedef void (*S2SessionResp0_Closure)
                 (const S2SessionResp0 *message,
                  void *closure_data);
typedef void (*S2SessionCmd1_Closure)
                 (const S2SessionCmd1 *message,
                  void *closure_data);
typedef void (*S2SessionResp1_Closure)
                 (const S2SessionResp1 *message,
                  void *closure_data);
typedef void (*Sec2Payload_Closure)
                 (const Sec2Payload *message,
                  void *closure_data);

/* --- services --- */


/* --- descriptors --- */

extern const ProtobufCEnumDescriptor    sec2_msg_type__descriptor;
extern const ProtobufCMessageDescriptor s2_session_cmd0__descriptor;
extern const ProtobufCMessageDescriptor s2_session_resp0__descriptor;
extern const ProtobufCMessageDescriptor s2_session_cmd1__descriptor;
extern const ProtobufCMessageDescriptor s2_session_resp1__descriptor;
extern const ProtobufCMessageDescriptor sec2_payload__descriptor;

PROTOBUF_C__END_DECLS


#endif  /* PROTOBUF_C_sec2_2eproto__INCLUDED */
