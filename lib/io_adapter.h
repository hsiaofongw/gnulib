#ifndef IO_ADAPTER_H
#define IO_ADAPTER_H

#include <stdint.h>

enum DigestId {
  DIGEST_MD5 = 0,
  DIGEST_SHA1 = 1,
  DIGEST_SHA224 = 2,
  DIGEST_SHA256 = 3,
  DIGEST_SHA384 = 4,
  DIGEST_SHA512 = 5,
  DIGEST_SM3 = 6,
};

typedef struct {
  char *msg_buf;
  size_t msg_len;
  char *result_buf;
  size_t result_len;
  int alg_id;
  void (*notify_progress)(uint32_t, uint32_t, void *, void *);
  void (*report_progress_to_upstream)(uint32_t sub_chunks_did,
                                      uint32_t total_sub_chunks, void *io_ctx,
                                      char *result_buf, size_t result_len);
} CksumIOCtx;

void *sha256_calc(CksumIOCtx *io_ctx);
void *sha224_calc(CksumIOCtx *io_ctx);

#endif
