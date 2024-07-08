/* stm_cordic_ll.h: Header file for STM32 LL based CORDIC driver implementation*/

/* Copyright 2023 The MathWorks, Inc. */

#ifndef STM_CORDIC_LL_H
#define STM_CORDIC_LL_H

#include<stdint.h>
#include<string.h>
#include<mw_stm32_types.h>


//Status variables.
struct CORDIC_STATUS {
    int cordic_state;
    uint32_t fnc;
    uint32_t numIters;
};

struct DMA_STATUS {
    int dma_state;
    int32_t buffer_size;        //currently used buffer size
};





#define _USE_MATH_DEFINES

#ifdef  __cplusplus
extern "C"
{
#endif
    extern void cordicZONP(int32_T* input1, int32_T* input2, int32_T* output1, int32_T* output2, int32_T array_size, uint32_T fcn, uint32_T scale, uint32_T nbwrite, uint32_T nbread, uint32_T numIters);
    extern void cordicZO(int32_T* input1, int32_T* input2, int32_T* output1, int32_T* output2, uint32_T fcn, uint32_T scale, uint32_T nbwrite, uint32_T nbread, uint32_T numIters);
    extern int32_T dmaCORDICWriteRead(int32_T* input1, int32_T* input2, int32_T* output1, int32_T* output2, uint32_T fcn, uint32_T numIters, uint32_T scale, int32_T array_size, uint32_T nbread, uint32_T nbwrite, uint32_T timeout);
    extern int32_T dmaCORDICWrite(int32_T* input1, int32_T* input2, uint32_T fcn, uint32_T numIters, uint32_T scale, int32_T array_size, uint32_T nbread, uint32_T nbwrite, uint32_T timeout);
    extern int32_T CORDICdmaSingleRead(int32_T* output, uint32_T fcn, uint32_T numIters, int32_T array_size, uint32_T timeout, int32_T* funcExecuted, int32_T* arraySizeExecuted, int32_T* numItersExecuted);
    int32_T dmaDoubleRead(int32_T* output1, int32_T* output2, uint32_T fcn, uint32_T numIters, int32_T array_size, uint32_T timeout, int32_T* funcExecuted, int32_T* arraySizeExecuted, int32_T* numItersExecuted);
    extern int32_T extractInterleavedBuffer(int32_T* output1, int32_T* output2, uint32_T fcn, uint32_T numIters, int32_T array_size);
    extern void generateInterleavedBuffer(int32_T* input1, int32_T* input2, int8_T* output, int32_T array_size);
    extern void CORDICterminate();

#ifdef __cplusplus
}
#endif
#endif //STM_CORDIC_LL_H