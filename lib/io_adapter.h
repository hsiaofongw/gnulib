#include <stdint.h>

enum DigestId {
  DIGEST_MD5 = 1,
  DIGEST_SHA1 = 2,
  DIGEST_SHA224 = 3,
  DIGEST_SHA256 = 4,
  DIGEST_SHA384 = 5,
  DIGEST_SHA512 = 6,
  DIGEST_SM3 = 7,
};

// called within hash iterate function.
void on_hash_process_block_iterate(uint32_t iter_idx, void *ctx,
                                   uint32_t alg_id);

// provided by wasm embedder.
void on_hash_value_update(char *ref_buf, uint32_t alg_id, uint32_t stage);

// provided by linking
void *getllvmallocastacktop();

// called within embedder (e.g. web browser)
// returns the addr of result_buf
void *initiate_buffer_hashing(char *msg_buf, uint32_t msg_len, uint32_t alg_id);
