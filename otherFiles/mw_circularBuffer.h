/* Copyright 2021 The MathWorks, Inc. */
#ifndef __CIRCULARBUFFER_H__
#define __CIRCULARBUFFER_H__

#ifndef   __STATIC_INLINE
  #ifdef __GNUC__
  #elif __ICCARM__
  #elif __TI_ARM__
  #endif

  #if defined(__CC_ARM) || defined(__ARMCC_VERSION)
  #define __STATIC_INLINE static __inline
  #else
  #define __STATIC_INLINE static inline
  #endif
#endif

#include "rtwtypes.h"

typedef struct _RingBuffer_T {
    uint16_T bufferSize;
    uint16_T readloc;
    uint16_T writeloc;
    uint8_T * bufferPtr;
    /*struct _RingBuffer_T * this;*/
} RingBuffer_T;

typedef RingBuffer_T * RingBufferPtr_T;

__STATIC_INLINE void RBuf_init(RingBufferPtr_T rbuffPtr, uint8_T * bufferPtr, size_t bufferLength)
{
    rbuffPtr->bufferPtr = bufferPtr;
    rbuffPtr->bufferSize = bufferLength;
    rbuffPtr->readloc = 0;
    rbuffPtr->writeloc = 0;
}

__STATIC_INLINE size_t RBuf_getNumberOfData(RingBufferPtr_T rbuffPtr)
{
    return (size_t)(rbuffPtr->writeloc - rbuffPtr->readloc);
}

__STATIC_INLINE int32_T RBuf_isFull(RingBufferPtr_T rbuffPtr)
{
    int32_T writeLoc;
    writeLoc = (rbuffPtr->writeloc+1 >= rbuffPtr->bufferSize) ? 0 : (rbuffPtr->writeloc+1);
    return (writeLoc == rbuffPtr->readloc);
}

__STATIC_INLINE size_t RBuf_size(rbuffPtr) {
    return rbuffPtr->writeloc >= rbuffPtr->readloc ?
            rbuffPtr->writeloc - rbuffPtr->readloc :
            rbuffPtr->bufferSize - (rbuffPtr->readloc - rbuffPtr->writeloc);
}

__STATIC_INLINE int32_T RBuf_push(RingBufferPtr_T rbuffPtr, uint8_T value)
{
    rbuffPtr->bufferPtr[rbuffPtr->writeloc] = value;
    
    if (rbuffPtr->writeloc+1 >= rbuffPtr->bufferSize)
    {
        rbuffPtr->writeloc = 0;
    }
    else
    {
        rbuffPtr->writeloc++;
    }
    /* Discard one element as buffer is overflowing */
    if (0 == RBuf_isFull(rbuffPtr))
    {
        if (rbuffPtr->readloc+1 >= rbuffPtr->bufferSize)
        {
            rbuffPtr->readloc = 0;
        }
        else
        {
            rbuffPtr->readloc++;
        }
    }
}

__STATIC_INLINE int32_T RBuf_pop(RingBufferPtr_T rbuffPtr, uint8_T * value)
{
    if (0 != RBuf_isEmpty(rbuffPtr))
    {
        if (rbuffPtr->readloc+1 >= rbuffPtr->bufferSize)
        {
            rbuffPtr->readloc = 0;
        }
        else
        {
            rbuffPtr->readloc++;
        }

        *value = rbuffPtr->bufferPtr[rbuffPtr->readloc];
    }

    return 0;
}

__STATIC_INLINE int32_T RBuf_isEmpty(RingBufferPtr_T rbuffPtr)
{
    return (rbuffPtr->writeloc == rbuffPtr->readloc);
}

__STATIC_INLINE void RBuf_reset(RingBufferPtr_T rbuffPtr)
{
    rbuffPtr->readloc = 0;
    rbuffPtr->writeloc = 0;
}

__STATIC_INLINE void RBuf_addWriteLoc(RingBufferPtr_T rbuffPtr, size_t length)
{
    
}




/*
extern void RBuf_init(RingBufferPtr_T rbuffPtr, uint8_T * bufferPtr, size_t bufferLength);

extern int32_T writeToRingBuffer(RingBufferPtr_T rbuffPtr, uint8_T value);
extern int32_T RBuf_push(RingBufferPtr_T rbuffPtr, uint8_T value);
extern int32_T RBuf_pushArray(RingBufferPtr_T rbuffPtr, uint8_T * value, size_t valueLen);
extern int32_T RBuf_ajustHead(RingBufferPtr_T rbuffPtr, size_t valueLen);
extern int32_T readFromRingBuffer(RingBufferPtr_T rbuffPtr, uint8_T * value);
extern int32_T RBuf_pop(RingBufferPtr_T rbuffPtr, uint8_T * value);
extern int32_T RBuf_popArray(RingBufferPtr_T rbuffPtr, uint8_T * value, size_t valueLen);
extern int32_T RBuf_adjustTail(RingBufferPtr_T rbuffPtr, size_t valueLen);

extern int32_T isRingBufferFull(RingBufferPtr_T rbuffPtr);
extern int32_T RBuf_isFull(RingBufferPtr_T rbuffPtr);
extern int32_T getNumberOfData(RingBufferPtr_T rbuffPtr);
extern int32_T RBuf_getNumberOfData(RingBufferPtr_T rbuffPtr);
*/
#endif /* __CIRCULARBUFFER_H__ */

/* LocalWords:  RBuf rbuff ajust CIRCULARBUFFER
 */
