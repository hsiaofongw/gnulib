#include "io_adapter.h"

#include <config.h>

#include <emscripten.h>

#include "md5.h"
#include "sha1.h"
#include "sha256.h"
#include "sha512.h"
#include "sm3.h"

#define MAX_RESULT_BUF_SIZE 128

char result_buf[MAX_RESULT_BUF_SIZE];

enum HashProcessStage { HASH_STAGE_COMPLETE = 1, HASH_STAGE_PROCESSING = 0 };

void on_hash_value_update_wrap(char *ref_buf, uint32_t alg_id, uint32_t stage) {
  on_hash_value_update(ref_buf, alg_id, stage);
  emscripten_sleep(33);
}

void read_result(void *ctx, uint32_t alg_id, uint32_t stage) {
  switch (alg_id) {
    case DIGEST_MD5:
      md5_read_ctx(ctx, result_buf);
      break;
    case DIGEST_SHA1:
      sha1_read_ctx(ctx, result_buf);
      break;
    case DIGEST_SHA224:
      sha224_read_ctx(ctx, result_buf);
      break;
    case DIGEST_SHA256:
      sha256_read_ctx(ctx, result_buf);
      break;
    case DIGEST_SHA384:
      sha384_read_ctx(ctx, result_buf);
      break;
    case DIGEST_SHA512:
      sha512_read_ctx(ctx, result_buf);
      break;
    case DIGEST_SM3:
      sm3_read_ctx(ctx, result_buf);
      break;
    default:
      return;
  }

  on_hash_value_update_wrap(result_buf, alg_id, stage);
}

void on_hash_process_block_iterate(uint32_t iter_idx, void *ctx,
                                   uint32_t alg_id) {
  uint32_t stride_mask = (2 << 14) - 1;
  if (iter_idx & stride_mask) {
    return;
  }

  read_result(ctx, alg_id, HASH_STAGE_PROCESSING);
}

void *initiate_buffer_hashing(char *msg_buf, uint32_t msg_len,
                              uint32_t alg_id) {
  switch (alg_id) {
    case DIGEST_MD5:
      md5_buffer(msg_buf, msg_len, result_buf);
      break;
    case DIGEST_SHA1:
      sha1_buffer(msg_buf, msg_len, result_buf);
      break;
    case DIGEST_SHA224:
      sha224_buffer(msg_buf, msg_len, result_buf);
      break;
    case DIGEST_SHA256:
      sha256_buffer(msg_buf, msg_len, result_buf);
      break;
    case DIGEST_SHA384:
      sha384_buffer(msg_buf, msg_len, result_buf);
      break;
    case DIGEST_SHA512:
      sha512_buffer(msg_buf, msg_len, result_buf);
      break;
    case DIGEST_SM3:
      sm3_buffer(msg_buf, msg_len, result_buf);
      break;
    default:
      return (void *)0;
  }

  on_hash_value_update_wrap(result_buf, alg_id, HASH_STAGE_COMPLETE);
  return result_buf;
}

void *get_first_usable_address() { return getllvmallocastacktop(); }
