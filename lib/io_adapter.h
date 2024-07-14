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

// called within hash iterate function.
void on_hash_process_block_iterate(uint32_t iter_idx, void *ctx,
                                   uint32_t alg_id);

#endif
