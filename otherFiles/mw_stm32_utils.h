/* Copyright 2022 The MathWorks, Inc. */
#ifndef __MW_STM32_UTILS_H__
#define __MW_STM32_UTILS_H__

#include <stdint.h>

/* Byte ordering functions */
void mw_swap16(uint16_t * dest, const uint16_t * src, uint32_t srcSize);
void mw_swap32(uint32_t * dest, const uint32_t * src, uint32_t srcSize);
void mw_swap64(uint64_t * dest, const uint64_t * src, uint32_t srcSize);
#define mw_swap_xint16_uint8(dest,src,srcSize) mw_swap16((uint16_t *)(dest), (const uint16_t *)(src), (srcSize))
#define mw_swap_xint32_uint8(dest,src,srcSize) mw_swap32((uint32_t *)(dest), (const uint32_t *)(src), (srcSize))
#define mw_swap_xint64_uint8(dest,src,srcSize) mw_swap64((uint64_t *)(dest), (const uint64_t *)(src), (srcSize))
#define mw_swap_uint8_xint16(dest,src,srcSize) mw_swap16((uint16_t *)(dest), (const uint16_t *)(src), (srcSize))
#define mw_swap_uint8_xint32(dest,src,srcSize) mw_swap32((uint32_t *)(dest), (const uint32_t *)(src), (srcSize))
#define mw_swap_uint8_xint64(dest,src,srcSize) mw_swap64((uint64_t *)(dest), (const uint64_t *)(src), (srcSize))
#define mw_swap_single_uint8(dest,src,srcSize) mw_swap32((uint32_t *)(dest), (const uint32_t *)(src), (srcSize))
#define mw_swap_double_uint8(dest,src,srcSize) mw_swap64((uint64_t *)(dest), (const uint64_t *)(src), (srcSize))
#define mw_swap_uint8_single(dest,src,srcSize) mw_swap32((uint32_t *)(dest), (const uint32_t *)(src), (srcSize))
#define mw_swap_uint8_double(dest,src,srcSize) mw_swap64((uint64_t *)(dest), (const uint64_t *)(src), (srcSize))

#endif /* __MW_STM32_UTILS_H__ */
