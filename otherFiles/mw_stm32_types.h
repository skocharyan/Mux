/* Copyright 2021-2023 The MathWorks, Inc. */
#ifndef __MW_STM32_TYPES_H__
#define __MW_STM32_TYPES_H__

#include "rtwtypes.h"
/* Pre-processor to get form Interrupt handler function prototype. */
#define MAKE_FN_NAME(x)   void x (void)
#define GETIRQ_NAME(signal) MAKE_FN_NAME(signal)


/*LL function to get/clear TC amd HT flag are different for GPDMA and DMA*/
#if defined (GPDMA1)
    /* Pre-processors to get GPDMA Stream/Channel Transfer complete active flag function handle */
    #define GETFCN_LL_GET_STREAM_ACTIVEFLAG(x) LL_DMA_IsActiveFlag_TC

    /* Pre-processors to get GPDMA Stream/Channel Clear Transfer complete flag function handle */
    #define GETFCN_LL_CLEAR_STREAM_ACTIVEFLAG(x) LL_DMA_ClearFlag_TC
    
    /* Pre-processors to get GPDMA half transfer active flag function handles */
    #define GETFCN_LL_GET_STREAM_HT_ACTIVEFLAG(x) LL_DMA_IsActiveFlag_HT
    
    /* Pre-processors to get GPDMA half transfer clear flag function handles */
    #define GETFCN_LL_CLEAR_STREAM_HT_ACTIVEFLAG(x) LL_DMA_ClearFlag_HT
#else
    /* Pre-processors to get DMA Stream/Channel Transfer complete active flag function handle */
    #define LL_GET_STREAM_ACTIVEFLAG(x) LL_DMA_IsActiveFlag_TC##x
    #define GETFCN_LL_GET_STREAM_ACTIVEFLAG(x) LL_GET_STREAM_ACTIVEFLAG(x)

    /* Pre-processors to get DMA Stream/Channel Clear Transfer complete flag function handle */
    #define LL_CLEAR_STREAM_ACTIVEFLAG(x) LL_DMA_ClearFlag_TC##x
    #define GETFCN_LL_CLEAR_STREAM_ACTIVEFLAG(x) LL_CLEAR_STREAM_ACTIVEFLAG(x)
    
    /* Pre-processors to get DMA half transfer active flag function handles */
    #define LL_GET_STREAM_HT_ACTIVEFLAG(x) LL_DMA_IsActiveFlag_HT##x
    #define GETFCN_LL_GET_STREAM_HT_ACTIVEFLAG(x) LL_GET_STREAM_HT_ACTIVEFLAG(x)
    
    /* Pre-processors to get DMA half transfer clear flag function handles */
    #define LL_CLEAR_STREAM_HT_ACTIVEFLAG(x) LL_DMA_ClearFlag_HT##x
    #define GETFCN_LL_CLEAR_STREAM_HT_ACTIVEFLAG(x) LL_CLEAR_STREAM_HT_ACTIVEFLAG(x)    
#endif


#define MW_IRQ_EXPAND_NAME(x) HWI_##x
#define MW_GET_IRQ_HANDLER_DEFINE(x)  MW_IRQ_EXPAND_NAME(x)
#define MW_EXPAND_DEFINED(x) defined(x)

#define GET_CURRENT_TIME() ((uint32_t)(HAL_GetTick()))
#define GET_CURRENT_TIME_IN_US() (getCurrentTimestampInMicros())

#if defined(STM32H7) && defined(MW_LPUART1_ENABLED)
#define LL_GET_STREAM_BDMA_ACTIVEFLAG(x) LL_BDMA_IsActiveFlag_TC##x
#define LL_CLEAR_STREAM_BDMA_ACTIVEFLAG(x) LL_BDMA_ClearFlag_TC##x
#define GETFCN_LL_GET_STREAM_BDMA_ACTIVEFLAG(x) LL_GET_STREAM_BDMA_ACTIVEFLAG(x)
#define GETFCN_LL_CLEAR_STREAM_BDMA_ACTIVEFLAG(x) LL_CLEAR_STREAM_BDMA_ACTIVEFLAG(x)
#endif

#define DMA_BUFFER_SIZE_BYTE_ALLIGNED(numBytes,byteAlign) (((numBytes) + ((byteAlign) - 1)) & ~((byteAlign) - 1))

extern uint32_T getCurrentTimestampInMicros(void);
extern uint32_T returnTimeElapsed(uint32_T timestampStartTime, boolean_T isTimeInMS);

#endif
