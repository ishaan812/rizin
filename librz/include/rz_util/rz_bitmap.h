#ifndef RZ_BITMAP_H
#define RZ_BITMAP_H

#include <rz_types.h>

#if RZ_SYS_BITS == 4
#define BITWORD_BITS_SHIFT 5
#define RzBitword          ut32
#else
#define BITWORD_BITS_SHIFT 6
#define RzBitword          ut64
#endif

#ifdef __cplusplus
extern "C" {
#endif

typedef struct rz_bitmap_t {
	size_t length;
	RzBitword *bitmap;
} RzBitVector;

RZ_API RZ_OWN RzBitVector *rz_bitmap_new(size_t len);
RZ_API void rz_bitmap_set_bytes(RZ_NONNULL RzBitVector *b, RZ_NONNULL const ut8 *buf, size_t len);
RZ_API void rz_bitmap_free(RZ_NULLABLE RzBitVector *b);
RZ_API void rz_bitmap_set(RZ_NONNULL RzBitVector *b, size_t bit);
RZ_API void rz_bitmap_unset(RZ_NONNULL RzBitVector *b, size_t bit);
RZ_API int rz_bitmap_test(RZ_NONNULL RzBitVector *b, size_t bit);

#ifdef __cplusplus
}
#endif

#endif //  RZ_BITMAP_H
