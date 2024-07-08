/* Copyright 2021-2023 The MathWorks, Inc. */
/******************************************************************************
* Includes
*******************************************************************************/
#include "stm_timer_ll.h"
#include <string.h>
/******************************************************************************
* Preprocessor Macros
*******************************************************************************/
/******************************************************************************
* Global Variable Definitions
*******************************************************************************/
#if defined(TIM1) && defined(MW_TIM1_ENABLED)
TIM_Type_T mw_tim1;

#ifdef MW_TIM1_CH1_DMA_ENABLED
    #ifdef STM32H7
        #if defined(MW_DCACHE_ENABLED)
        uint16_T TIM1CH1DMABuffer[DMA_BUFFER_SIZE_BYTE_ALLIGNED(MW_TIM1_CH1_DMA_BUFFER_SIZE,32)] __attribute__((aligned (32))) __attribute__((section(".dma_buffer"))) ;
        #else
        uint16_T TIM1CH1DMABuffer[MW_TIM1_CH1_DMA_BUFFER_SIZE] __attribute__((section(".dma_buffer"))) ;
        #endif
    #elif defined(STM32F7) && defined(MW_DCACHE_ENABLED)
        uint16_T TIM1CH1DMABuffer[DMA_BUFFER_SIZE_BYTE_ALLIGNED(MW_TIM1_CH1_DMA_BUFFER_SIZE,32)] __attribute__((aligned (32)));
    #endif
#endif

#ifdef MW_TIM1_CH2_DMA_ENABLED
    #ifdef STM32H7
        #if defined(MW_DCACHE_ENABLED)
        uint16_T TIM1CH2DMABuffer[DMA_BUFFER_SIZE_BYTE_ALLIGNED(MW_TIM1_CH2_DMA_BUFFER_SIZE,32)] __attribute__((aligned (32))) __attribute__((section(".dma_buffer"))) ;
        #else
        uint16_T TIM1CH2DMABuffer[MW_TIM1_CH2_DMA_BUFFER_SIZE] __attribute__((section(".dma_buffer"))) ;
        #endif
    #elif defined(STM32F7) && defined(MW_DCACHE_ENABLED)
        uint16_T TIM1CH2DMABuffer[DMA_BUFFER_SIZE_BYTE_ALLIGNED(MW_TIM1_CH2_DMA_BUFFER_SIZE,32)] __attribute__((aligned (32)));
    #endif
#endif

#ifdef MW_TIM1_CH3_DMA_ENABLED
    #ifdef STM32H7
        #if defined(MW_DCACHE_ENABLED)
        uint16_T TIM1CH3DMABuffer[DMA_BUFFER_SIZE_BYTE_ALLIGNED(MW_TIM1_CH3_DMA_BUFFER_SIZE,32)] __attribute__((aligned (32))) __attribute__((section(".dma_buffer"))) ;
        #else
        uint16_T TIM1CH3DMABuffer[MW_TIM1_CH3_DMA_BUFFER_SIZE] __attribute__((section(".dma_buffer"))) ;
        #endif
    #elif defined(STM32F7) && defined(MW_DCACHE_ENABLED)
        uint16_T TIM1CH3DMABuffer[DMA_BUFFER_SIZE_BYTE_ALLIGNED(MW_TIM1_CH3_DMA_BUFFER_SIZE,32)] __attribute__((aligned (32)));
    #endif
#endif

#ifdef MW_TIM1_CH4_DMA_ENABLED
    #ifdef STM32H7
        #if defined(MW_DCACHE_ENABLED)
        uint16_T TIM1CH4DMABuffer[DMA_BUFFER_SIZE_BYTE_ALLIGNED(MW_TIM1_CH4_DMA_BUFFER_SIZE,32)] __attribute__((aligned (32))) __attribute__((section(".dma_buffer"))) ;
        #else
        uint16_T TIM1CH4DMABuffer[MW_TIM1_CH4_DMA_BUFFER_SIZE] __attribute__((section(".dma_buffer"))) ;
        #endif
    #elif defined(STM32F7) && defined(MW_DCACHE_ENABLED)
        uint16_T TIM1CH4DMABuffer[DMA_BUFFER_SIZE_BYTE_ALLIGNED(MW_TIM1_CH4_DMA_BUFFER_SIZE,32)] __attribute__((aligned (32)));
    #endif
#endif
#endif

#if defined(TIM2) && defined(MW_TIM2_ENABLED)
TIM_Type_T mw_tim2;
#ifdef MW_TIM2_CH1_DMA_ENABLED
    #ifdef STM32H7
        #if defined(MW_DCACHE_ENABLED)
        uint32_T TIM2CH1DMABuffer[DMA_BUFFER_SIZE_BYTE_ALLIGNED(MW_TIM2_CH1_DMA_BUFFER_SIZE,32)] __attribute__((aligned (32))) __attribute__((section(".dma_buffer"))) ;
        #else
        uint32_T TIM2CH1DMABuffer[MW_TIM2_CH1_DMA_BUFFER_SIZE] __attribute__((section(".dma_buffer"))) ;
        #endif
    #elif defined(STM32F7) && defined(MW_DCACHE_ENABLED)
        uint32_T TIM2CH1DMABuffer[DMA_BUFFER_SIZE_BYTE_ALLIGNED(MW_TIM2_CH1_DMA_BUFFER_SIZE,32)] __attribute__((aligned (32)));
    #endif
#endif

#ifdef MW_TIM2_CH2_DMA_ENABLED
    #ifdef STM32H7
        #if defined(MW_DCACHE_ENABLED)
        uint32_T TIM2CH2DMABuffer[DMA_BUFFER_SIZE_BYTE_ALLIGNED(MW_TIM2_CH2_DMA_BUFFER_SIZE,32)] __attribute__((aligned (32))) __attribute__((section(".dma_buffer"))) ;
        #else
        uint32_T TIM2CH2DMABuffer[MW_TIM2_CH2_DMA_BUFFER_SIZE] __attribute__((section(".dma_buffer"))) ;
        #endif
    #elif defined(STM32F7) && defined(MW_DCACHE_ENABLED)
        uint32_T TIM2CH2DMABuffer[DMA_BUFFER_SIZE_BYTE_ALLIGNED(MW_TIM2_CH2_DMA_BUFFER_SIZE,32)] __attribute__((aligned (32)));
    #endif
#endif

#ifdef MW_TIM2_CH3_DMA_ENABLED
    #ifdef STM32H7
        #if defined(MW_DCACHE_ENABLED)
        uint32_T TIM2CH3DMABuffer[DMA_BUFFER_SIZE_BYTE_ALLIGNED(MW_TIM2_CH3_DMA_BUFFER_SIZE,32)] __attribute__((aligned (32))) __attribute__((section(".dma_buffer"))) ;
        #else
        uint32_T TIM2CH3DMABuffer[MW_TIM2_CH3_DMA_BUFFER_SIZE] __attribute__((section(".dma_buffer"))) ;
        #endif
    #elif defined(STM32F7) && defined(MW_DCACHE_ENABLED)
        uint32_T TIM2CH3DMABuffer[DMA_BUFFER_SIZE_BYTE_ALLIGNED(MW_TIM2_CH3_DMA_BUFFER_SIZE,32)] __attribute__((aligned (32)));
    #endif
#endif

#ifdef MW_TIM2_CH4_DMA_ENABLED
    #ifdef STM32H7
        #if defined(MW_DCACHE_ENABLED)
        uint32_T TIM2CH4DMABuffer[DMA_BUFFER_SIZE_BYTE_ALLIGNED(MW_TIM2_CH4_DMA_BUFFER_SIZE,32)] __attribute__((aligned (32))) __attribute__((section(".dma_buffer"))) ;
        #else
        uint32_T TIM2CH4DMABuffer[MW_TIM2_CH4_DMA_BUFFER_SIZE] __attribute__((section(".dma_buffer"))) ;
        #endif
    #elif defined(STM32F7) && defined(MW_DCACHE_ENABLED)
        uint32_T TIM2CH4DMABuffer[DMA_BUFFER_SIZE_BYTE_ALLIGNED(MW_TIM2_CH4_DMA_BUFFER_SIZE,32)] __attribute__((aligned (32)));
    #endif
#endif
#endif

#if defined(TIM3) && defined(MW_TIM3_ENABLED)
TIM_Type_T mw_tim3;
#ifdef MW_TIM3_CH1_DMA_ENABLED
    #ifdef STM32H7
        #if defined(MW_DCACHE_ENABLED)
        uint16_T TIM3CH1DMABuffer[DMA_BUFFER_SIZE_BYTE_ALLIGNED(MW_TIM3_CH1_DMA_BUFFER_SIZE,32)] __attribute__((aligned (32))) __attribute__((section(".dma_buffer"))) ;
        #else
        uint16_T TIM3CH1DMABuffer[MW_TIM3_CH1_DMA_BUFFER_SIZE] __attribute__((section(".dma_buffer"))) ;
        #endif
    #elif defined(STM32F7) && defined(MW_DCACHE_ENABLED)
        uint16_T TIM3CH1DMABuffer[DMA_BUFFER_SIZE_BYTE_ALLIGNED(MW_TIM3_CH1_DMA_BUFFER_SIZE,32)] __attribute__((aligned (32)));
    #endif
#endif

#ifdef MW_TIM3_CH2_DMA_ENABLED
    #ifdef STM32H7
        #if defined(MW_DCACHE_ENABLED)
        uint16_T TIM3CH2DMABuffer[DMA_BUFFER_SIZE_BYTE_ALLIGNED(MW_TIM3_CH2_DMA_BUFFER_SIZE,32)] __attribute__((aligned (32))) __attribute__((section(".dma_buffer"))) ;
        #else
        uint16_T TIM3CH2DMABuffer[MW_TIM3_CH2_DMA_BUFFER_SIZE] __attribute__((section(".dma_buffer"))) ;
        #endif
    #elif defined(STM32F7) && defined(MW_DCACHE_ENABLED)
        uint16_T TIM3CH2DMABuffer[DMA_BUFFER_SIZE_BYTE_ALLIGNED(MW_TIM3_CH2_DMA_BUFFER_SIZE,32)] __attribute__((aligned (32)));
    #endif
#endif

#ifdef MW_TIM3_CH3_DMA_ENABLED
    #ifdef STM32H7
        #if defined(MW_DCACHE_ENABLED)
        uint16_T TIM3CH3DMABuffer[DMA_BUFFER_SIZE_BYTE_ALLIGNED(MW_TIM3_CH3_DMA_BUFFER_SIZE,32)] __attribute__((aligned (32))) __attribute__((section(".dma_buffer"))) ;
        #else
        uint16_T TIM3CH3DMABuffer[MW_TIM3_CH3_DMA_BUFFER_SIZE] __attribute__((section(".dma_buffer"))) ;
        #endif
    #elif defined(STM32F7) && defined(MW_DCACHE_ENABLED)
        uint16_T TIM3CH3DMABuffer[DMA_BUFFER_SIZE_BYTE_ALLIGNED(MW_TIM3_CH3_DMA_BUFFER_SIZE,32)] __attribute__((aligned (32)));
    #endif
#endif

#ifdef MW_TIM3_CH4_DMA_ENABLED
    #ifdef STM32H7
        #if defined(MW_DCACHE_ENABLED)
        uint16_T TIM3CH4DMABuffer[DMA_BUFFER_SIZE_BYTE_ALLIGNED(MW_TIM3_CH4_DMA_BUFFER_SIZE,32)] __attribute__((aligned (32))) __attribute__((section(".dma_buffer"))) ;
        #else
        uint16_T TIM3CH4DMABuffer[MW_TIM3_CH4_DMA_BUFFER_SIZE] __attribute__((section(".dma_buffer"))) ;
        #endif
    #elif defined(STM32F7) && defined(MW_DCACHE_ENABLED)
        uint16_T TIM3CH4DMABuffer[DMA_BUFFER_SIZE_BYTE_ALLIGNED(MW_TIM3_CH4_DMA_BUFFER_SIZE,32)] __attribute__((aligned (32)));
    #endif
#endif
#endif

#if defined(TIM4) && defined(MW_TIM4_ENABLED)
TIM_Type_T mw_tim4;
#ifdef MW_TIM4_CH1_DMA_ENABLED
    #ifdef STM32H7
        #if defined(MW_DCACHE_ENABLED)
        uint16_T TIM4CH1DMABuffer[DMA_BUFFER_SIZE_BYTE_ALLIGNED(MW_TIM4_CH1_DMA_BUFFER_SIZE,32)] __attribute__((aligned (32))) __attribute__((section(".dma_buffer"))) ;
        #else
        uint16_T TIM4CH1DMABuffer[MW_TIM4_CH1_DMA_BUFFER_SIZE] __attribute__((section(".dma_buffer"))) ;
        #endif
    #elif defined(STM32F7) && defined(MW_DCACHE_ENABLED)
        uint16_T TIM4CH1DMABuffer[DMA_BUFFER_SIZE_BYTE_ALLIGNED(MW_TIM4_CH1_DMA_BUFFER_SIZE,32)] __attribute__((aligned (32)));
    #endif
#endif

#ifdef MW_TIM4_CH2_DMA_ENABLED
    #ifdef STM32H7
        #if defined(MW_DCACHE_ENABLED)
        uint16_T TIM4CH2DMABuffer[DMA_BUFFER_SIZE_BYTE_ALLIGNED(MW_TIM4_CH2_DMA_BUFFER_SIZE,32)] __attribute__((aligned (32))) __attribute__((section(".dma_buffer"))) ;
        #else
        uint16_T TIM4CH2DMABuffer[MW_TIM4_CH2_DMA_BUFFER_SIZE] __attribute__((section(".dma_buffer"))) ;
        #endif
    #elif defined(STM32F7) && defined(MW_DCACHE_ENABLED)
        uint16_T TIM4CH2DMABuffer[DMA_BUFFER_SIZE_BYTE_ALLIGNED(MW_TIM4_CH2_DMA_BUFFER_SIZE,32)] __attribute__((aligned (32)));
    #endif
#endif

#ifdef MW_TIM4_CH3_DMA_ENABLED
    #ifdef STM32H7
        #if defined(MW_DCACHE_ENABLED)
        uint16_T TIM4CH3DMABuffer[DMA_BUFFER_SIZE_BYTE_ALLIGNED(MW_TIM4_CH3_DMA_BUFFER_SIZE,32)] __attribute__((aligned (32))) __attribute__((section(".dma_buffer"))) ;
        #else
        uint16_T TIM4CH3DMABuffer[MW_TIM4_CH3_DMA_BUFFER_SIZE] __attribute__((section(".dma_buffer"))) ;
        #endif
    #elif defined(STM32F7) && defined(MW_DCACHE_ENABLED)
        uint16_T TIM4CH3DMABuffer[DMA_BUFFER_SIZE_BYTE_ALLIGNED(MW_TIM4_CH3_DMA_BUFFER_SIZE,32)] __attribute__((aligned (32)));
    #endif
#endif

#ifdef MW_TIM4_CH4_DMA_ENABLED
    #ifdef STM32H7
        #if defined(MW_DCACHE_ENABLED)
        uint16_T TIM4CH4DMABuffer[DMA_BUFFER_SIZE_BYTE_ALLIGNED(MW_TIM4_CH4_DMA_BUFFER_SIZE,32)] __attribute__((aligned (32))) __attribute__((section(".dma_buffer"))) ;
        #else
        uint16_T TIM4CH4DMABuffer[MW_TIM4_CH4_DMA_BUFFER_SIZE] __attribute__((section(".dma_buffer"))) ;
        #endif
    #elif defined(STM32F7) && defined(MW_DCACHE_ENABLED)
        uint16_T TIM4CH4DMABuffer[DMA_BUFFER_SIZE_BYTE_ALLIGNED(MW_TIM4_CH4_DMA_BUFFER_SIZE,32)] __attribute__((aligned (32)));
    #endif
#endif
#endif

#if defined(TIM5) && defined(MW_TIM5_ENABLED)
TIM_Type_T mw_tim5;
#ifdef MW_TIM5_CH1_DMA_ENABLED
    #ifdef STM32H7
        #if defined(MW_DCACHE_ENABLED)
        uint32_T TIM5CH1DMABuffer[DMA_BUFFER_SIZE_BYTE_ALLIGNED(MW_TIM5_CH1_DMA_BUFFER_SIZE,32)] __attribute__((aligned (32))) __attribute__((section(".dma_buffer"))) ;
        #else
        uint32_T TIM5CH1DMABuffer[MW_TIM5_CH1_DMA_BUFFER_SIZE] __attribute__((section(".dma_buffer"))) ;
        #endif
    #elif defined(STM32F7) && defined(MW_DCACHE_ENABLED)
        uint32_T TIM5CH1DMABuffer[DMA_BUFFER_SIZE_BYTE_ALLIGNED(MW_TIM5_CH1_DMA_BUFFER_SIZE,32)] __attribute__((aligned (32)));
    #endif
#endif

#ifdef MW_TIM5_CH2_DMA_ENABLED
    #ifdef STM32H7
        #if defined(MW_DCACHE_ENABLED)
        uint32_T TIM5CH2DMABuffer[DMA_BUFFER_SIZE_BYTE_ALLIGNED(MW_TIM5_CH2_DMA_BUFFER_SIZE,32)] __attribute__((aligned (32))) __attribute__((section(".dma_buffer"))) ;
        #else
        uint32_T TIM5CH2DMABuffer[MW_TIM5_CH2_DMA_BUFFER_SIZE] __attribute__((section(".dma_buffer"))) ;
        #endif
    #elif defined(STM32F7) && defined(MW_DCACHE_ENABLED)
        uint32_T TIM5CH2DMABuffer[DMA_BUFFER_SIZE_BYTE_ALLIGNED(MW_TIM5_CH2_DMA_BUFFER_SIZE,32)] __attribute__((aligned (32)));
    #endif
#endif

#ifdef MW_TIM5_CH3_DMA_ENABLED
    #ifdef STM32H7
        #if defined(MW_DCACHE_ENABLED)
        uint32_T TIM5CH3DMABuffer[DMA_BUFFER_SIZE_BYTE_ALLIGNED(MW_TIM5_CH3_DMA_BUFFER_SIZE,32)] __attribute__((aligned (32))) __attribute__((section(".dma_buffer"))) ;
        #else
        uint32_T TIM5CH3DMABuffer[MW_TIM5_CH3_DMA_BUFFER_SIZE] __attribute__((section(".dma_buffer"))) ;
        #endif
    #elif defined(STM32F7) && defined(MW_DCACHE_ENABLED)
        uint32_T TIM5CH3DMABuffer[DMA_BUFFER_SIZE_BYTE_ALLIGNED(MW_TIM5_CH3_DMA_BUFFER_SIZE,32)] __attribute__((aligned (32)));
    #endif
#endif

#ifdef MW_TIM5_CH4_DMA_ENABLED
    #ifdef STM32H7
        #if defined(MW_DCACHE_ENABLED)
        uint32_T TIM5CH4DMABuffer[DMA_BUFFER_SIZE_BYTE_ALLIGNED(MW_TIM5_CH4_DMA_BUFFER_SIZE,32)] __attribute__((aligned (32))) __attribute__((section(".dma_buffer"))) ;
        #else
        uint32_T TIM5CH4DMABuffer[MW_TIM5_CH4_DMA_BUFFER_SIZE] __attribute__((section(".dma_buffer"))) ;
        #endif
    #elif defined(STM32F7) && defined(MW_DCACHE_ENABLED)
        uint32_T TIM5CH4DMABuffer[DMA_BUFFER_SIZE_BYTE_ALLIGNED(MW_TIM5_CH4_DMA_BUFFER_SIZE,32)] __attribute__((aligned (32)));
    #endif
#endif
#endif

#if defined(TIM6) && defined(MW_TIM6_ENABLED)
TIM_Type_T mw_tim6;
#endif

#if defined(TIM7) && defined(MW_TIM7_ENABLED)
TIM_Type_T mw_tim7;
#endif

#if defined(TIM8) && defined(MW_TIM8_ENABLED)
TIM_Type_T mw_tim8;
#ifdef MW_TIM8_CH1_DMA_ENABLED
    #ifdef STM32H7
        #if defined(MW_DCACHE_ENABLED)
        uint16_T TIM8CH1DMABuffer[DMA_BUFFER_SIZE_BYTE_ALLIGNED(MW_TIM8_CH1_DMA_BUFFER_SIZE,32)] __attribute__((aligned (32))) __attribute__((section(".dma_buffer"))) ;
        #else
        uint16_T TIM8CH1DMABuffer[MW_TIM8_CH1_DMA_BUFFER_SIZE] __attribute__((section(".dma_buffer"))) ;
        #endif
    #elif defined(STM32F7) && defined(MW_DCACHE_ENABLED)
        uint16_T TIM8CH1DMABuffer[DMA_BUFFER_SIZE_BYTE_ALLIGNED(MW_TIM8_CH1_DMA_BUFFER_SIZE,32)] __attribute__((aligned (32)));
    #endif
#endif

#ifdef MW_TIM8_CH2_DMA_ENABLED
    #ifdef STM32H7
        #if defined(MW_DCACHE_ENABLED)
        uint16_T TIM8CH2DMABuffer[DMA_BUFFER_SIZE_BYTE_ALLIGNED(MW_TIM8_CH2_DMA_BUFFER_SIZE,32)] __attribute__((aligned (32))) __attribute__((section(".dma_buffer"))) ;
        #else
        uint16_T TIM8CH2DMABuffer[MW_TIM8_CH2_DMA_BUFFER_SIZE] __attribute__((section(".dma_buffer"))) ;
        #endif
    #elif defined(STM32F7) && defined(MW_DCACHE_ENABLED)
        uint16_T TIM8CH2DMABuffer[DMA_BUFFER_SIZE_BYTE_ALLIGNED(MW_TIM8_CH2_DMA_BUFFER_SIZE,32)] __attribute__((aligned (32)));
    #endif
#endif

#ifdef MW_TIM8_CH3_DMA_ENABLED
    #ifdef STM32H7
        #if defined(MW_DCACHE_ENABLED)
        uint16_T TIM8CH3DMABuffer[DMA_BUFFER_SIZE_BYTE_ALLIGNED(MW_TIM8_CH3_DMA_BUFFER_SIZE,32)] __attribute__((aligned (32))) __attribute__((section(".dma_buffer"))) ;
        #else
        uint16_T TIM8CH3DMABuffer[MW_TIM8_CH3_DMA_BUFFER_SIZE] __attribute__((section(".dma_buffer"))) ;
        #endif
    #elif defined(STM32F7) && defined(MW_DCACHE_ENABLED)
        uint16_T TIM8CH3DMABuffer[DMA_BUFFER_SIZE_BYTE_ALLIGNED(MW_TIM8_CH3_DMA_BUFFER_SIZE,32)] __attribute__((aligned (32)));
    #endif
#endif

#ifdef MW_TIM8_CH4_DMA_ENABLED
    #ifdef STM32H7
        #if defined(MW_DCACHE_ENABLED)
        uint16_T TIM8CH4DMABuffer[DMA_BUFFER_SIZE_BYTE_ALLIGNED(MW_TIM8_CH4_DMA_BUFFER_SIZE,32)] __attribute__((aligned (32))) __attribute__((section(".dma_buffer"))) ;
        #else
        uint16_T TIM8CH4DMABuffer[MW_TIM8_CH4_DMA_BUFFER_SIZE] __attribute__((section(".dma_buffer"))) ;
        #endif
    #elif defined(STM32F7) && defined(MW_DCACHE_ENABLED)
        uint16_T TIM8CH4DMABuffer[DMA_BUFFER_SIZE_BYTE_ALLIGNED(MW_TIM8_CH4_DMA_BUFFER_SIZE,32)] __attribute__((aligned (32)));
    #endif
#endif
#endif

#if defined(TIM9) && defined(MW_TIM9_ENABLED)
TIM_Type_T mw_tim9;
#ifdef MW_TIM9_CH1_DMA_ENABLED
    #ifdef STM32H7
        #if defined(MW_DCACHE_ENABLED)
        uint16_T TIM9CH1DMABuffer[DMA_BUFFER_SIZE_BYTE_ALLIGNED(MW_TIM9_CH1_DMA_BUFFER_SIZE,32)] __attribute__((aligned (32))) __attribute__((section(".dma_buffer"))) ;
        #else
        uint16_T TIM9CH1DMABuffer[MW_TIM9_CH1_DMA_BUFFER_SIZE] __attribute__((section(".dma_buffer"))) ;
        #endif
    #elif defined(STM32F7) && defined(MW_DCACHE_ENABLED)
        uint16_T TIM9CH1DMABuffer[DMA_BUFFER_SIZE_BYTE_ALLIGNED(MW_TIM9_CH1_DMA_BUFFER_SIZE,32)] __attribute__((aligned (32)));
    #endif
#endif

#ifdef MW_TIM9_CH2_DMA_ENABLED
    #ifdef STM32H7
        #if defined(MW_DCACHE_ENABLED)
        uint16_T TIM9CH2DMABuffer[DMA_BUFFER_SIZE_BYTE_ALLIGNED(MW_TIM9_CH2_DMA_BUFFER_SIZE,32)] __attribute__((aligned (32))) __attribute__((section(".dma_buffer"))) ;
        #else
        uint16_T TIM9CH2DMABuffer[MW_TIM9_CH2_DMA_BUFFER_SIZE] __attribute__((section(".dma_buffer"))) ;
        #endif
    #elif defined(STM32F7) && defined(MW_DCACHE_ENABLED)
        uint16_T TIM9CH2DMABuffer[DMA_BUFFER_SIZE_BYTE_ALLIGNED(MW_TIM9_CH2_DMA_BUFFER_SIZE,32)] __attribute__((aligned (32)));
    #endif
#endif
#endif

#if defined(TIM10) && defined(MW_TIM10_ENABLED)
TIM_Type_T mw_tim10;
#ifdef MW_TIM10_CH1_DMA_ENABLED
    #ifdef STM32H7
        #if defined(MW_DCACHE_ENABLED)
        uint16_T TIM10CH1DMABuffer[DMA_BUFFER_SIZE_BYTE_ALLIGNED(MW_TIM10_CH1_DMA_BUFFER_SIZE,32)] __attribute__((aligned (32))) __attribute__((section(".dma_buffer"))) ;
        #else
        uint16_T TIM10CH1DMABuffer[MW_TIM10_CH1_DMA_BUFFER_SIZE] __attribute__((section(".dma_buffer"))) ;
        #endif
    #elif defined(STM32F7) && defined(MW_DCACHE_ENABLED)
        uint16_T TIM10CH1DMABuffer[DMA_BUFFER_SIZE_BYTE_ALLIGNED(MW_TIM10_CH1_DMA_BUFFER_SIZE,32)] __attribute__((aligned (32)));
    #endif
#endif
#endif

#if defined(TIM11) && defined(MW_TIM11_ENABLED)
TIM_Type_T mw_tim11;
#ifdef MW_TIM11_CH1_DMA_ENABLED
    #ifdef STM32H7
        #if defined(MW_DCACHE_ENABLED)
        uint16_T TIM11CH1DMABuffer[DMA_BUFFER_SIZE_BYTE_ALLIGNED(MW_TIM11_CH1_DMA_BUFFER_SIZE,32)] __attribute__((aligned (32))) __attribute__((section(".dma_buffer"))) ;
        #else
        uint16_T TIM11CH1DMABuffer[MW_TIM11_CH1_DMA_BUFFER_SIZE] __attribute__((section(".dma_buffer"))) ;
        #endif
    #elif defined(STM32F7) && defined(MW_DCACHE_ENABLED)
        uint16_T TIM11CH1DMABuffer[DMA_BUFFER_SIZE_BYTE_ALLIGNED(MW_TIM11_CH1_DMA_BUFFER_SIZE,32)] __attribute__((aligned (32)));
    #endif
#endif
#endif

#if defined(TIM12) && defined(MW_TIM12_ENABLED)
TIM_Type_T mw_tim12;
#ifdef MW_TIM12_CH1_DMA_ENABLED
    #ifdef STM32H7
        #if defined(MW_DCACHE_ENABLED)
        uint16_T TIM12CH1DMABuffer[DMA_BUFFER_SIZE_BYTE_ALLIGNED(MW_TIM12_CH1_DMA_BUFFER_SIZE,32)] __attribute__((aligned (32))) __attribute__((section(".dma_buffer"))) ;
        #else
        uint16_T TIM12CH1DMABuffer[MW_TIM12_CH1_DMA_BUFFER_SIZE] __attribute__((section(".dma_buffer"))) ;
        #endif
    #elif defined(STM32F7) && defined(MW_DCACHE_ENABLED)
        uint16_T TIM12CH1DMABuffer[DMA_BUFFER_SIZE_BYTE_ALLIGNED(MW_TIM12_CH1_DMA_BUFFER_SIZE,32)] __attribute__((aligned (32)));
    #endif
#endif

#ifdef MW_TIM12_CH2_DMA_ENABLED
    #ifdef STM32H7
        #if defined(MW_DCACHE_ENABLED)
        uint16_T TIM12CH2DMABuffer[DMA_BUFFER_SIZE_BYTE_ALLIGNED(MW_TIM12_CH2_DMA_BUFFER_SIZE,32)] __attribute__((aligned (32))) __attribute__((section(".dma_buffer"))) ;
        #else
        uint16_T TIM12CH2DMABuffer[MW_TIM12_CH2_DMA_BUFFER_SIZE] __attribute__((section(".dma_buffer"))) ;
        #endif
    #elif defined(STM32F7) && defined(MW_DCACHE_ENABLED)
        uint16_T TIM12CH2DMABuffer[DMA_BUFFER_SIZE_BYTE_ALLIGNED(MW_TIM12_CH2_DMA_BUFFER_SIZE,32)] __attribute__((aligned (32)));
    #endif
#endif
#endif

#if defined(TIM13) && defined(MW_TIM13_ENABLED)
TIM_Type_T mw_tim13;
#ifdef MW_TIM13_CH1_DMA_ENABLED
    #ifdef STM32H7
        #if defined(MW_DCACHE_ENABLED)
        uint16_T TIM13CH1DMABuffer[DMA_BUFFER_SIZE_BYTE_ALLIGNED(MW_TIM13_CH1_DMA_BUFFER_SIZE,32)] __attribute__((aligned (32))) __attribute__((section(".dma_buffer"))) ;
        #else
        uint16_T TIM13CH1DMABuffer[MW_TIM13_CH1_DMA_BUFFER_SIZE] __attribute__((section(".dma_buffer"))) ;
        #endif
    #elif defined(STM32F7) && defined(MW_DCACHE_ENABLED)
        uint16_T TIM13CH1DMABuffer[DMA_BUFFER_SIZE_BYTE_ALLIGNED(MW_TIM13_CH1_DMA_BUFFER_SIZE,32)] __attribute__((aligned (32)));
    #endif
#endif
#endif

#if defined(TIM14) && defined(MW_TIM14_ENABLED)
TIM_Type_T mw_tim14;
#ifdef MW_TIM14_CH1_DMA_ENABLED
    #ifdef STM32H7
        #if defined(MW_DCACHE_ENABLED)
        uint16_T TIM14CH1DMABuffer[DMA_BUFFER_SIZE_BYTE_ALLIGNED(MW_TIM14_CH1_DMA_BUFFER_SIZE,32)] __attribute__((aligned (32))) __attribute__((section(".dma_buffer"))) ;
        #else
        uint16_T TIM14CH1DMABuffer[MW_TIM14_CH1_DMA_BUFFER_SIZE] __attribute__((section(".dma_buffer"))) ;
        #endif
    #elif defined(STM32F7) && defined(MW_DCACHE_ENABLED)
        uint16_T TIM14CH1DMABuffer[DMA_BUFFER_SIZE_BYTE_ALLIGNED(MW_TIM14_CH1_DMA_BUFFER_SIZE,32)] __attribute__((aligned (32)));
    #endif
#endif
#endif

#if defined(TIM15) && defined(MW_TIM15_ENABLED)
TIM_Type_T mw_tim15;
#ifdef MW_TIM15_CH1_DMA_ENABLED
    #ifdef STM32H7
        #if defined(MW_DCACHE_ENABLED)
        uint16_T TIM15CH1DMABuffer[DMA_BUFFER_SIZE_BYTE_ALLIGNED(MW_TIM15_CH1_DMA_BUFFER_SIZE,32)] __attribute__((aligned (32))) __attribute__((section(".dma_buffer"))) ;
        #else
        uint16_T TIM15CH1DMABuffer[MW_TIM15_CH1_DMA_BUFFER_SIZE] __attribute__((section(".dma_buffer"))) ;
        #endif
    #elif defined(STM32F7) && defined(MW_DCACHE_ENABLED)
        uint16_T TIM15CH1DMABuffer[DMA_BUFFER_SIZE_BYTE_ALLIGNED(MW_TIM15_CH1_DMA_BUFFER_SIZE,32)] __attribute__((aligned (32)));
    #endif
#endif

#ifdef MW_TIM15_CH2_DMA_ENABLED
    #ifdef STM32H7
        #if defined(MW_DCACHE_ENABLED)
        uint16_T TIM15CH2DMABuffer[DMA_BUFFER_SIZE_BYTE_ALLIGNED(MW_TIM15_CH2_DMA_BUFFER_SIZE,32)] __attribute__((aligned (32))) __attribute__((section(".dma_buffer"))) ;
        #else
        uint16_T TIM15CH2DMABuffer[MW_TIM15_CH2_DMA_BUFFER_SIZE] __attribute__((section(".dma_buffer"))) ;
        #endif
    #elif defined(STM32F7) && defined(MW_DCACHE_ENABLED)
        uint16_T TIM15CH2DMABuffer[DMA_BUFFER_SIZE_BYTE_ALLIGNED(MW_TIM15_CH2_DMA_BUFFER_SIZE,32)] __attribute__((aligned (32)));
    #endif
#endif
#endif

#if defined(TIM16) && defined(MW_TIM16_ENABLED)
TIM_Type_T mw_tim16;
#ifdef MW_TIM16_CH1_DMA_ENABLED
    #ifdef STM32H7
        #if defined(MW_DCACHE_ENABLED)
        uint16_T TIM16CH1DMABuffer[DMA_BUFFER_SIZE_BYTE_ALLIGNED(MW_TIM16_CH1_DMA_BUFFER_SIZE,32)] __attribute__((aligned (32))) __attribute__((section(".dma_buffer"))) ;
        #else
        uint16_T TIM16CH1DMABuffer[MW_TIM16_CH1_DMA_BUFFER_SIZE] __attribute__((section(".dma_buffer"))) ;
        #endif
    #elif defined(STM32F7) && defined(MW_DCACHE_ENABLED)
        uint16_T TIM16CH1DMABuffer[DMA_BUFFER_SIZE_BYTE_ALLIGNED(MW_TIM16_CH1_DMA_BUFFER_SIZE,32)] __attribute__((aligned (32)));
    #endif
#endif
#endif

#if defined(TIM17) && defined(MW_TIM17_ENABLED)
TIM_Type_T mw_tim17;
#ifdef MW_TIM17_CH1_DMA_ENABLED
    #ifdef STM32H7
        #if defined(MW_DCACHE_ENABLED)
        uint16_T TIM17CH1DMABuffer[DMA_BUFFER_SIZE_BYTE_ALLIGNED(MW_TIM17_CH1_DMA_BUFFER_SIZE,32)] __attribute__((aligned (32))) __attribute__((section(".dma_buffer"))) ;
        #else
        uint16_T TIM17CH1DMABuffer[MW_TIM17_CH1_DMA_BUFFER_SIZE] __attribute__((section(".dma_buffer"))) ;
        #endif
    #elif defined(STM32F7) && defined(MW_DCACHE_ENABLED)
        uint16_T TIM17CH1DMABuffer[DMA_BUFFER_SIZE_BYTE_ALLIGNED(MW_TIM17_CH1_DMA_BUFFER_SIZE,32)] __attribute__((aligned (32)));
    #endif
#endif
#endif

#if defined(TIM20) && defined(MW_TIM20_ENABLED)
TIM_Type_T mw_tim20;
#endif

#if defined(TIM23) && defined(MW_TIM23_ENABLED)
TIM_Type_T mw_tim23;
#ifdef MW_TIM23_CH1_DMA_ENABLED
    #ifdef STM32H7
        #if defined(MW_DCACHE_ENABLED)
        uint32_T TIM23CH1DMABuffer[DMA_BUFFER_SIZE_BYTE_ALLIGNED(MW_TIM23_CH1_DMA_BUFFER_SIZE,32)] __attribute__((aligned (32))) __attribute__((section(".dma_buffer"))) ;
        #else
        uint32_T TIM23CH1DMABuffer[MW_TIM23_CH1_DMA_BUFFER_SIZE] __attribute__((section(".dma_buffer"))) ;
        #endif
    #elif defined(STM32F7) && defined(MW_DCACHE_ENABLED)
        uint32_T TIM23CH1DMABuffer[DMA_BUFFER_SIZE_BYTE_ALLIGNED(MW_TIM23_CH1_DMA_BUFFER_SIZE,32)] __attribute__((aligned (32)));
    #endif
#endif

#ifdef MW_TIM23_CH2_DMA_ENABLED
    #ifdef STM32H7
        #if defined(MW_DCACHE_ENABLED)
        uint32_T TIM23CH2DMABuffer[DMA_BUFFER_SIZE_BYTE_ALLIGNED(MW_TIM23_CH2_DMA_BUFFER_SIZE,32)] __attribute__((aligned (32))) __attribute__((section(".dma_buffer"))) ;
        #else
        uint32_T TIM23CH2DMABuffer[MW_TIM23_CH2_DMA_BUFFER_SIZE] __attribute__((section(".dma_buffer"))) ;
        #endif
    #elif defined(STM32F7) && defined(MW_DCACHE_ENABLED)
        uint32_T TIM23CH2DMABuffer[DMA_BUFFER_SIZE_BYTE_ALLIGNED(MW_TIM23_CH2_DMA_BUFFER_SIZE,32)] __attribute__((aligned (32)));
    #endif
#endif

#ifdef MW_TIM23_CH3_DMA_ENABLED
    #ifdef STM32H7
        #if defined(MW_DCACHE_ENABLED)
        uint32_T TIM23CH3DMABuffer[DMA_BUFFER_SIZE_BYTE_ALLIGNED(MW_TIM23_CH3_DMA_BUFFER_SIZE,32)] __attribute__((aligned (32))) __attribute__((section(".dma_buffer"))) ;
        #else
        uint32_T TIM23CH3DMABuffer[MW_TIM23_CH3_DMA_BUFFER_SIZE] __attribute__((section(".dma_buffer"))) ;
        #endif
    #elif defined(STM32F7) && defined(MW_DCACHE_ENABLED)
        uint32_T TIM23CH3DMABuffer[DMA_BUFFER_SIZE_BYTE_ALLIGNED(MW_TIM23_CH3_DMA_BUFFER_SIZE,32)] __attribute__((aligned (32)));
    #endif
#endif

#ifdef MW_TIM23_CH4_DMA_ENABLED
    #ifdef STM32H7
        #if defined(MW_DCACHE_ENABLED)
        uint32_T TIM23CH4DMABuffer[DMA_BUFFER_SIZE_BYTE_ALLIGNED(MW_TIM23_CH4_DMA_BUFFER_SIZE,32)] __attribute__((aligned (32))) __attribute__((section(".dma_buffer"))) ;
        #else
        uint32_T TIM23CH4DMABuffer[MW_TIM23_CH4_DMA_BUFFER_SIZE] __attribute__((section(".dma_buffer"))) ;
        #endif
    #elif defined(STM32F7) && defined(MW_DCACHE_ENABLED)
        uint32_T TIM23CH4DMABuffer[DMA_BUFFER_SIZE_BYTE_ALLIGNED(MW_TIM23_CH4_DMA_BUFFER_SIZE,32)] __attribute__((aligned (32)));
    #endif
#endif
#endif

#if defined(TIM24) && defined(MW_TIM24_ENABLED)
TIM_Type_T mw_tim24;
#ifdef MW_TIM24_CH1_DMA_ENABLED
    #ifdef STM32H7
        #if defined(MW_DCACHE_ENABLED)
        uint32_T TIM24CH1DMABuffer[DMA_BUFFER_SIZE_BYTE_ALLIGNED(MW_TIM24_CH1_DMA_BUFFER_SIZE,32)] __attribute__((aligned (32))) __attribute__((section(".dma_buffer"))) ;
        #else
        uint32_T TIM24CH1DMABuffer[MW_TIM24_CH1_DMA_BUFFER_SIZE] __attribute__((section(".dma_buffer"))) ;
        #endif
    #elif defined(STM32F7) && defined(MW_DCACHE_ENABLED)
        uint32_T TIM24CH1DMABuffer[DMA_BUFFER_SIZE_BYTE_ALLIGNED(MW_TIM24_CH1_DMA_BUFFER_SIZE,32)] __attribute__((aligned (32)));
    #endif
#endif

#ifdef MW_TIM24_CH2_DMA_ENABLED
    #ifdef STM32H7
        #if defined(MW_DCACHE_ENABLED)
        uint32_T TIM24CH2DMABuffer[DMA_BUFFER_SIZE_BYTE_ALLIGNED(MW_TIM24_CH2_DMA_BUFFER_SIZE,32)] __attribute__((aligned (32))) __attribute__((section(".dma_buffer"))) ;
        #else
        uint32_T TIM24CH2DMABuffer[MW_TIM24_CH2_DMA_BUFFER_SIZE] __attribute__((section(".dma_buffer"))) ;
        #endif
    #elif defined(STM32F7) && defined(MW_DCACHE_ENABLED)
        uint32_T TIM24CH2DMABuffer[DMA_BUFFER_SIZE_BYTE_ALLIGNED(MW_TIM24_CH2_DMA_BUFFER_SIZE,32)] __attribute__((aligned (32)));
    #endif
#endif

#ifdef MW_TIM24_CH3_DMA_ENABLED
    #ifdef STM32H7
        #if defined(MW_DCACHE_ENABLED)
        uint32_T TIM24CH3DMABuffer[DMA_BUFFER_SIZE_BYTE_ALLIGNED(MW_TIM24_CH3_DMA_BUFFER_SIZE,32)] __attribute__((aligned (32))) __attribute__((section(".dma_buffer"))) ;
        #else
        uint32_T TIM24CH3DMABuffer[MW_TIM24_CH3_DMA_BUFFER_SIZE] __attribute__((section(".dma_buffer"))) ;
        #endif
    #elif defined(STM32F7) && defined(MW_DCACHE_ENABLED)
        uint32_T TIM24CH3DMABuffer[DMA_BUFFER_SIZE_BYTE_ALLIGNED(MW_TIM24_CH3_DMA_BUFFER_SIZE,32)] __attribute__((aligned (32)));
    #endif
#endif

#ifdef MW_TIM24_CH4_DMA_ENABLED
    #ifdef STM32H7
        #if defined(MW_DCACHE_ENABLED)
        uint32_T TIM24CH4DMABuffer[DMA_BUFFER_SIZE_BYTE_ALLIGNED(MW_TIM24_CH4_DMA_BUFFER_SIZE,32)] __attribute__((aligned (32))) __attribute__((section(".dma_buffer"))) ;
        #else
        uint32_T TIM24CH4DMABuffer[MW_TIM24_CH4_DMA_BUFFER_SIZE] __attribute__((section(".dma_buffer"))) ;
        #endif
    #elif defined(STM32F7) && defined(MW_DCACHE_ENABLED)
        uint32_T TIM24CH4DMABuffer[DMA_BUFFER_SIZE_BYTE_ALLIGNED(MW_TIM24_CH4_DMA_BUFFER_SIZE,32)] __attribute__((aligned (32)));
    #endif
#endif
#endif

/*DMA transfer complete callback */
uint8_T TIM_IsEnabledDMAITTransferComplete(Channel_DMA_T * ptrTimChannel, uint32_t (*checkActiveFlag)(DMA_TypeDef *DMAx),  void (*clearActiveFlag)(DMA_TypeDef *DMAx))
{
    /* Check transfer-complete interrupt */
    if (LL_DMA_IsEnabledIT_TC(ptrTimChannel->dmaPeripheralPtr, ptrTimChannel->dmastream) && (1 == checkActiveFlag(ptrTimChannel->dmaPeripheralPtr)))
    {
        clearActiveFlag(ptrTimChannel->dmaPeripheralPtr);         /* Clear transfer complete interrupt flag */
        if(ptrTimChannel->buffer.writeRollOver == 1)
        {
            ptrTimChannel->errorStatus =  ptrTimChannel->errorStatus |  MW_TIM_OVERRUN_ERROR;
            ptrTimChannel->buffer.readPos = 0;
        }
        ptrTimChannel->buffer.writeRollOver = 1;
        #ifndef GPDMA1
        /* Start DMA again when DMA mode is Normal - GetMode not preset for GPDMA*/
        if (LL_DMA_MODE_NORMAL == LL_DMA_GetMode(ptrTimChannel->dmaPeripheralPtr, ptrTimChannel->dmastream))
        #endif
        {
            /* Disable DMA stream */
            #if defined(STM32G4)  || defined(STM32WB) || defined(STM32L5) || defined(STM32L4) || defined(STM32U5)
            LL_DMA_DisableChannel(ptrTimChannel->dmaPeripheralPtr, (uint32_t)ptrTimChannel->dmastream);
            #else
            LL_DMA_DisableStream(ptrTimChannel->dmaPeripheralPtr, (uint32_t)ptrTimChannel->dmastream);
            #endif
            /* Set length to receive */
            #if defined (GPDMA1)
            if(((uint32_t)NULL) != ((uint32_t)(ptrTimChannel->buffer.bufferPtr32Bit)))
            {
                LL_DMA_SetDestAddress(ptrTimChannel->dmaPeripheralPtr, (uint32_t)ptrTimChannel->dmastream, (uint32_t)ptrTimChannel->buffer.bufferPtr32Bit);
            }
            else
            {
                LL_DMA_SetDestAddress(ptrTimChannel->dmaPeripheralPtr, (uint32_t)ptrTimChannel->dmastream, (uint32_t)ptrTimChannel->buffer.bufferPtr16Bit);
            }
            LL_DMA_SetBlkDataLength(ptrTimChannel->dmaPeripheralPtr, ptrTimChannel->dmastream, ptrTimChannel->buffer.bufferSize);
            #else
            LL_DMA_SetDataLength(ptrTimChannel->dmaPeripheralPtr, ptrTimChannel->dmastream, ptrTimChannel->buffer.bufferSize);
            #endif
            /* Start DMA again */
            #if defined(STM32G4)  || defined(STM32WB) || defined(STM32L5) || defined(STM32L4) || defined(STM32U5)
            LL_DMA_EnableChannel(ptrTimChannel->dmaPeripheralPtr, (uint32_t)ptrTimChannel->dmastream);
            #else
            LL_DMA_EnableStream(ptrTimChannel->dmaPeripheralPtr, (uint32_t)ptrTimChannel->dmastream);
            #endif
        }
        return 1;
    }
    else
    {
        return 0;
    }
}

/******************************************************************************
* DMA IRQ for Timer channels
*******************************************************************************/
#if defined(MW_TIM1_CH1_DMA_ENABLED) && (!MW_GET_IRQ_HANDLER_DEFINE(MW_TIM1_CH1_DMA_ENABLED))
GETIRQ_NAME(MW_TIM1_CH1_DMA_ENABLED)
{
    TIM_IsEnabledDMAITTransferComplete(&(mw_tim1.channel1), GETFCN_LL_GET_STREAM_ACTIVEFLAG(MW_TIM1_CH1_DMA_STREAM), GETFCN_LL_CLEAR_STREAM_ACTIVEFLAG(MW_TIM1_CH1_DMA_STREAM));
}
#endif
#if defined(MW_TIM1_CH2_DMA_ENABLED) && (!MW_GET_IRQ_HANDLER_DEFINE(MW_TIM1_CH2_DMA_ENABLED))
GETIRQ_NAME(MW_TIM1_CH2_DMA_ENABLED)
{
    TIM_IsEnabledDMAITTransferComplete(&(mw_tim1.channel2), GETFCN_LL_GET_STREAM_ACTIVEFLAG(MW_TIM1_CH2_DMA_STREAM), GETFCN_LL_CLEAR_STREAM_ACTIVEFLAG(MW_TIM1_CH2_DMA_STREAM));
}
#endif
#if defined(MW_TIM1_CH3_DMA_ENABLED) && (!MW_GET_IRQ_HANDLER_DEFINE(MW_TIM1_CH3_DMA_ENABLED))
GETIRQ_NAME(MW_TIM1_CH3_DMA_ENABLED)
{
    TIM_IsEnabledDMAITTransferComplete(&(mw_tim1.channel3), GETFCN_LL_GET_STREAM_ACTIVEFLAG(MW_TIM1_CH3_DMA_STREAM), GETFCN_LL_CLEAR_STREAM_ACTIVEFLAG(MW_TIM1_CH3_DMA_STREAM));
}
#endif
#if defined(MW_TIM1_CH4_DMA_ENABLED) && (!MW_GET_IRQ_HANDLER_DEFINE(MW_TIM1_CH4_DMA_ENABLED))
GETIRQ_NAME(MW_TIM1_CH4_DMA_ENABLED)
{
    TIM_IsEnabledDMAITTransferComplete(&(mw_tim1.channel4), GETFCN_LL_GET_STREAM_ACTIVEFLAG(MW_TIM1_CH4_DMA_STREAM), GETFCN_LL_CLEAR_STREAM_ACTIVEFLAG(MW_TIM1_CH4_DMA_STREAM));
}
#endif
#if defined(MW_TIM2_CH1_DMA_ENABLED) && (!MW_GET_IRQ_HANDLER_DEFINE(MW_TIM2_CH1_DMA_ENABLED))
GETIRQ_NAME(MW_TIM2_CH1_DMA_ENABLED)
{
    TIM_IsEnabledDMAITTransferComplete(&(mw_tim2.channel1), GETFCN_LL_GET_STREAM_ACTIVEFLAG(MW_TIM2_CH1_DMA_STREAM), GETFCN_LL_CLEAR_STREAM_ACTIVEFLAG(MW_TIM2_CH1_DMA_STREAM));
}
#endif
#if defined(MW_TIM2_CH2_DMA_ENABLED) && (!MW_GET_IRQ_HANDLER_DEFINE(MW_TIM2_CH2_DMA_ENABLED))
GETIRQ_NAME(MW_TIM2_CH2_DMA_ENABLED)
{
    TIM_IsEnabledDMAITTransferComplete(&(mw_tim2.channel2), GETFCN_LL_GET_STREAM_ACTIVEFLAG(MW_TIM2_CH2_DMA_STREAM), GETFCN_LL_CLEAR_STREAM_ACTIVEFLAG(MW_TIM2_CH2_DMA_STREAM));
}
#endif
#if defined(MW_TIM2_CH3_DMA_ENABLED) && (!MW_GET_IRQ_HANDLER_DEFINE(MW_TIM2_CH3_DMA_ENABLED))
GETIRQ_NAME(MW_TIM2_CH3_DMA_ENABLED)
{
    TIM_IsEnabledDMAITTransferComplete(&(mw_tim2.channel3), GETFCN_LL_GET_STREAM_ACTIVEFLAG(MW_TIM2_CH3_DMA_STREAM), GETFCN_LL_CLEAR_STREAM_ACTIVEFLAG(MW_TIM2_CH3_DMA_STREAM));
}
#endif
#if defined(MW_TIM2_CH4_DMA_ENABLED) && (!MW_GET_IRQ_HANDLER_DEFINE(MW_TIM2_CH4_DMA_ENABLED))
GETIRQ_NAME(MW_TIM2_CH4_DMA_ENABLED)
{
    TIM_IsEnabledDMAITTransferComplete(&(mw_tim2.channel4), GETFCN_LL_GET_STREAM_ACTIVEFLAG(MW_TIM2_CH4_DMA_STREAM), GETFCN_LL_CLEAR_STREAM_ACTIVEFLAG(MW_TIM2_CH4_DMA_STREAM));
}
#endif
#if defined(MW_TIM3_CH1_DMA_ENABLED) && (!MW_GET_IRQ_HANDLER_DEFINE(MW_TIM3_CH1_DMA_ENABLED))
GETIRQ_NAME(MW_TIM3_CH1_DMA_ENABLED)
{
    TIM_IsEnabledDMAITTransferComplete(&(mw_tim3.channel1), GETFCN_LL_GET_STREAM_ACTIVEFLAG(MW_TIM3_CH1_DMA_STREAM), GETFCN_LL_CLEAR_STREAM_ACTIVEFLAG(MW_TIM3_CH1_DMA_STREAM));
}
#endif
#if defined(MW_TIM3_CH2_DMA_ENABLED) && (!MW_GET_IRQ_HANDLER_DEFINE(MW_TIM3_CH2_DMA_ENABLED))
GETIRQ_NAME(MW_TIM3_CH2_DMA_ENABLED)
{
    TIM_IsEnabledDMAITTransferComplete(&(mw_tim3.channel2), GETFCN_LL_GET_STREAM_ACTIVEFLAG(MW_TIM3_CH2_DMA_STREAM), GETFCN_LL_CLEAR_STREAM_ACTIVEFLAG(MW_TIM3_CH2_DMA_STREAM));
}
#endif
#if defined(MW_TIM3_CH3_DMA_ENABLED) && (!MW_GET_IRQ_HANDLER_DEFINE(MW_TIM3_CH3_DMA_ENABLED))
GETIRQ_NAME(MW_TIM3_CH3_DMA_ENABLED)
{
    TIM_IsEnabledDMAITTransferComplete(&(mw_tim3.channel3), GETFCN_LL_GET_STREAM_ACTIVEFLAG(MW_TIM3_CH3_DMA_STREAM), GETFCN_LL_CLEAR_STREAM_ACTIVEFLAG(MW_TIM3_CH3_DMA_STREAM));
}
#endif
#if defined(MW_TIM3_CH4_DMA_ENABLED) && (!MW_GET_IRQ_HANDLER_DEFINE(MW_TIM3_CH4_DMA_ENABLED))
GETIRQ_NAME(MW_TIM3_CH4_DMA_ENABLED)
{
    TIM_IsEnabledDMAITTransferComplete(&(mw_tim3.channel4), GETFCN_LL_GET_STREAM_ACTIVEFLAG(MW_TIM3_CH4_DMA_STREAM), GETFCN_LL_CLEAR_STREAM_ACTIVEFLAG(MW_TIM3_CH4_DMA_STREAM));
}
#endif
#if defined(MW_TIM4_CH1_DMA_ENABLED) && (!MW_GET_IRQ_HANDLER_DEFINE(MW_TIM4_CH1_DMA_ENABLED))
GETIRQ_NAME(MW_TIM4_CH1_DMA_ENABLED)
{
    TIM_IsEnabledDMAITTransferComplete(&(mw_tim4.channel1), GETFCN_LL_GET_STREAM_ACTIVEFLAG(MW_TIM4_CH1_DMA_STREAM), GETFCN_LL_CLEAR_STREAM_ACTIVEFLAG(MW_TIM4_CH1_DMA_STREAM));
}
#endif
#if defined(MW_TIM4_CH2_DMA_ENABLED) && (!MW_GET_IRQ_HANDLER_DEFINE(MW_TIM4_CH2_DMA_ENABLED))
GETIRQ_NAME(MW_TIM4_CH2_DMA_ENABLED)
{
    TIM_IsEnabledDMAITTransferComplete(&(mw_tim4.channel2), GETFCN_LL_GET_STREAM_ACTIVEFLAG(MW_TIM4_CH2_DMA_STREAM), GETFCN_LL_CLEAR_STREAM_ACTIVEFLAG(MW_TIM4_CH2_DMA_STREAM));
}
#endif
#if defined(MW_TIM4_CH3_DMA_ENABLED) && (!MW_GET_IRQ_HANDLER_DEFINE(MW_TIM4_CH3_DMA_ENABLED))
GETIRQ_NAME(MW_TIM4_CH3_DMA_ENABLED)
{
    TIM_IsEnabledDMAITTransferComplete(&(mw_tim4.channel3), GETFCN_LL_GET_STREAM_ACTIVEFLAG(MW_TIM4_CH3_DMA_STREAM), GETFCN_LL_CLEAR_STREAM_ACTIVEFLAG(MW_TIM4_CH3_DMA_STREAM));
}
#endif
#if defined(MW_TIM4_CH4_DMA_ENABLED) && (!MW_GET_IRQ_HANDLER_DEFINE(MW_TIM4_CH4_DMA_ENABLED))
GETIRQ_NAME(MW_TIM4_CH4_DMA_ENABLED)
{
    TIM_IsEnabledDMAITTransferComplete(&(mw_tim4.channel4), GETFCN_LL_GET_STREAM_ACTIVEFLAG(MW_TIM4_CH4_DMA_STREAM), GETFCN_LL_CLEAR_STREAM_ACTIVEFLAG(MW_TIM4_CH4_DMA_STREAM));
}
#endif
#if defined(MW_TIM5_CH1_DMA_ENABLED) && (!MW_GET_IRQ_HANDLER_DEFINE(MW_TIM5_CH1_DMA_ENABLED))
GETIRQ_NAME(MW_TIM5_CH1_DMA_ENABLED)
{
    TIM_IsEnabledDMAITTransferComplete(&(mw_tim5.channel1), GETFCN_LL_GET_STREAM_ACTIVEFLAG(MW_TIM5_CH1_DMA_STREAM), GETFCN_LL_CLEAR_STREAM_ACTIVEFLAG(MW_TIM5_CH1_DMA_STREAM));
}
#endif
#if defined(MW_TIM5_CH2_DMA_ENABLED) && (!MW_GET_IRQ_HANDLER_DEFINE(MW_TIM5_CH2_DMA_ENABLED))
GETIRQ_NAME(MW_TIM5_CH2_DMA_ENABLED)
{
    TIM_IsEnabledDMAITTransferComplete(&(mw_tim5.channel2), GETFCN_LL_GET_STREAM_ACTIVEFLAG(MW_TIM5_CH2_DMA_STREAM), GETFCN_LL_CLEAR_STREAM_ACTIVEFLAG(MW_TIM5_CH2_DMA_STREAM));
}
#endif
#if defined(MW_TIM5_CH3_DMA_ENABLED) && (!MW_GET_IRQ_HANDLER_DEFINE(MW_TIM5_CH3_DMA_ENABLED))
GETIRQ_NAME(MW_TIM5_CH3_DMA_ENABLED)
{
    TIM_IsEnabledDMAITTransferComplete(&(mw_tim5.channel3), GETFCN_LL_GET_STREAM_ACTIVEFLAG(MW_TIM5_CH3_DMA_STREAM), GETFCN_LL_CLEAR_STREAM_ACTIVEFLAG(MW_TIM5_CH3_DMA_STREAM));
}
#endif
#if defined(MW_TIM5_CH4_DMA_ENABLED) && (!MW_GET_IRQ_HANDLER_DEFINE(MW_TIM5_CH4_DMA_ENABLED))
GETIRQ_NAME(MW_TIM5_CH4_DMA_ENABLED)
{
    TIM_IsEnabledDMAITTransferComplete(&(mw_tim5.channel4), GETFCN_LL_GET_STREAM_ACTIVEFLAG(MW_TIM5_CH4_DMA_STREAM), GETFCN_LL_CLEAR_STREAM_ACTIVEFLAG(MW_TIM5_CH4_DMA_STREAM));
}
#endif
#if defined(MW_TIM8_CH1_DMA_ENABLED) && (!MW_GET_IRQ_HANDLER_DEFINE(MW_TIM8_CH1_DMA_ENABLED))
GETIRQ_NAME(MW_TIM8_CH1_DMA_ENABLED)
{
    TIM_IsEnabledDMAITTransferComplete(&(mw_tim8.channel1), GETFCN_LL_GET_STREAM_ACTIVEFLAG(MW_TIM8_CH1_DMA_STREAM), GETFCN_LL_CLEAR_STREAM_ACTIVEFLAG(MW_TIM8_CH1_DMA_STREAM));
}
#endif
#if defined(MW_TIM8_CH2_DMA_ENABLED) && (!MW_GET_IRQ_HANDLER_DEFINE(MW_TIM8_CH2_DMA_ENABLED))
GETIRQ_NAME(MW_TIM8_CH2_DMA_ENABLED)
{
    TIM_IsEnabledDMAITTransferComplete(&(mw_tim8.channel2), GETFCN_LL_GET_STREAM_ACTIVEFLAG(MW_TIM8_CH2_DMA_STREAM), GETFCN_LL_CLEAR_STREAM_ACTIVEFLAG(MW_TIM8_CH2_DMA_STREAM));
}
#endif
#if defined(MW_TIM8_CH3_DMA_ENABLED) && (!MW_GET_IRQ_HANDLER_DEFINE(MW_TIM8_CH3_DMA_ENABLED))
GETIRQ_NAME(MW_TIM8_CH3_DMA_ENABLED)
{
    TIM_IsEnabledDMAITTransferComplete(&(mw_tim8.channel3), GETFCN_LL_GET_STREAM_ACTIVEFLAG(MW_TIM8_CH3_DMA_STREAM), GETFCN_LL_CLEAR_STREAM_ACTIVEFLAG(MW_TIM8_CH3_DMA_STREAM));
}
#endif
#if defined(MW_TIM8_CH4_DMA_ENABLED) && (!MW_GET_IRQ_HANDLER_DEFINE(MW_TIM8_CH4_DMA_ENABLED))
GETIRQ_NAME(MW_TIM8_CH4_DMA_ENABLED)
{
    TIM_IsEnabledDMAITTransferComplete(&(mw_tim8.channel4), GETFCN_LL_GET_STREAM_ACTIVEFLAG(MW_TIM8_CH4_DMA_STREAM), GETFCN_LL_CLEAR_STREAM_ACTIVEFLAG(MW_TIM8_CH4_DMA_STREAM));
}
#endif

#if defined(MW_TIM9_CH1_DMA_ENABLED) && (!MW_GET_IRQ_HANDLER_DEFINE(MW_TIM9_CH1_DMA_ENABLED))
GETIRQ_NAME(MW_TIM9_CH1_DMA_ENABLED)
{
    TIM_IsEnabledDMAITTransferComplete(&(mw_tim9.channel1), GETFCN_LL_GET_STREAM_ACTIVEFLAG(MW_TIM9_CH1_DMA_STREAM), GETFCN_LL_CLEAR_STREAM_ACTIVEFLAG(MW_TIM9_CH1_DMA_STREAM));
}
#endif
#if defined(MW_TIM9_CH2_DMA_ENABLED) && (!MW_GET_IRQ_HANDLER_DEFINE(MW_TIM9_CH2_DMA_ENABLED))
GETIRQ_NAME(MW_TIM9_CH2_DMA_ENABLED)
{
    TIM_IsEnabledDMAITTransferComplete(&(mw_tim9.channel2), GETFCN_LL_GET_STREAM_ACTIVEFLAG(MW_TIM9_CH2_DMA_STREAM), GETFCN_LL_CLEAR_STREAM_ACTIVEFLAG(MW_TIM9_CH2_DMA_STREAM));
}
#endif

#if defined(MW_TIM12_CH1_DMA_ENABLED) && (!MW_GET_IRQ_HANDLER_DEFINE(MW_TIM12_CH1_DMA_ENABLED))
GETIRQ_NAME(MW_TIM12_CH1_DMA_ENABLED)
{
    TIM_IsEnabledDMAITTransferComplete(&(mw_tim12.channel1), GETFCN_LL_GET_STREAM_ACTIVEFLAG(MW_TIM12_CH1_DMA_STREAM), GETFCN_LL_CLEAR_STREAM_ACTIVEFLAG(MW_TIM12_CH1_DMA_STREAM));
}
#endif
#if defined(MW_TIM12_CH2_DMA_ENABLED) && (!MW_GET_IRQ_HANDLER_DEFINE(MW_TIM12_CH2_DMA_ENABLED))
GETIRQ_NAME(MW_TIM12_CH2_DMA_ENABLED)
{
    TIM_IsEnabledDMAITTransferComplete(&(mw_tim12.channel2), GETFCN_LL_GET_STREAM_ACTIVEFLAG(MW_TIM12_CH2_DMA_STREAM), GETFCN_LL_CLEAR_STREAM_ACTIVEFLAG(MW_TIM12_CH2_DMA_STREAM));
}
#endif

#if defined(MW_TIM10_CH1_DMA_ENABLED) && (!MW_GET_IRQ_HANDLER_DEFINE(MW_TIM10_CH1_DMA_ENABLED))
GETIRQ_NAME(MW_TIM10_CH1_DMA_ENABLED)
{
    TIM_IsEnabledDMAITTransferComplete(&(mw_tim10.channel1), GETFCN_LL_GET_STREAM_ACTIVEFLAG(MW_TIM10_CH1_DMA_STREAM), GETFCN_LL_CLEAR_STREAM_ACTIVEFLAG(MW_TIM10_CH1_DMA_STREAM));
}
#endif

#if defined(MW_TIM11_CH1_DMA_ENABLED) && (!MW_GET_IRQ_HANDLER_DEFINE(MW_TIM11_CH1_DMA_ENABLED))
GETIRQ_NAME(MW_TIM1_CH1_DMA_ENABLED)
{
    TIM_IsEnabledDMAITTransferComplete(&(mw_tim11.channel1), GETFCN_LL_GET_STREAM_ACTIVEFLAG(MW_TIM11_CH1_DMA_STREAM), GETFCN_LL_CLEAR_STREAM_ACTIVEFLAG(MW_TIM11_CH1_DMA_STREAM));
}
#endif
#if defined(MW_TIM13_CH1_DMA_ENABLED) && (!MW_GET_IRQ_HANDLER_DEFINE(MW_TIM13_CH1_DMA_ENABLED))
GETIRQ_NAME(MW_TIM13_CH1_DMA_ENABLED)
{
    TIM_IsEnabledDMAITTransferComplete(&(mw_tim13.channel1), GETFCN_LL_GET_STREAM_ACTIVEFLAG(MW_TIM13_CH1_DMA_STREAM), GETFCN_LL_CLEAR_STREAM_ACTIVEFLAG(MW_TIM13_CH1_DMA_STREAM));
}
#endif
#if defined(MW_TIM14_CH1_DMA_ENABLED) && (!MW_GET_IRQ_HANDLER_DEFINE(MW_TIM14_CH1_DMA_ENABLED))
GETIRQ_NAME(MW_TIM14_CH1_DMA_ENABLED)
{
    TIM_IsEnabledDMAITTransferComplete(&(mw_tim14.channel1), GETFCN_LL_GET_STREAM_ACTIVEFLAG(MW_TIM14_CH1_DMA_STREAM), GETFCN_LL_CLEAR_STREAM_ACTIVEFLAG(MW_TIM14_CH1_DMA_STREAM));
}
#endif

#if defined(MW_TIM15_CH1_DMA_ENABLED) && (!MW_GET_IRQ_HANDLER_DEFINE(MW_TIM15_CH1_DMA_ENABLED))
GETIRQ_NAME(MW_TIM15_CH1_DMA_ENABLED)
{
    TIM_IsEnabledDMAITTransferComplete(&(mw_tim15.channel1), GETFCN_LL_GET_STREAM_ACTIVEFLAG(MW_TIM15_CH1_DMA_STREAM), GETFCN_LL_CLEAR_STREAM_ACTIVEFLAG(MW_TIM15_CH1_DMA_STREAM));
}
#endif
#if defined(MW_TIM15_CH2_DMA_ENABLED) && (!MW_GET_IRQ_HANDLER_DEFINE(MW_TIM15_CH2_DMA_ENABLED))
GETIRQ_NAME(MW_TIM15_CH2_DMA_ENABLED)
{
    TIM_IsEnabledDMAITTransferComplete(&(mw_tim15.channel2), GETFCN_LL_GET_STREAM_ACTIVEFLAG(MW_TIM15_CH2_DMA_STREAM), GETFCN_LL_CLEAR_STREAM_ACTIVEFLAG(MW_TIM15_CH2_DMA_STREAM));
}
#endif

#if defined(MW_TIM16_CH1_DMA_ENABLED) && (!MW_GET_IRQ_HANDLER_DEFINE(MW_TIM16_CH1_DMA_ENABLED))
GETIRQ_NAME(MW_TIM16_CH1_DMA_ENABLED)
{
    TIM_IsEnabledDMAITTransferComplete(&(mw_tim16.channel1), GETFCN_LL_GET_STREAM_ACTIVEFLAG(MW_TIM16_CH1_DMA_STREAM), GETFCN_LL_CLEAR_STREAM_ACTIVEFLAG(MW_TIM16_CH1_DMA_STREAM));
}
#endif
#if defined(MW_TIM17_CH1_DMA_ENABLED) && (!MW_GET_IRQ_HANDLER_DEFINE(MW_TIM17_CH1_DMA_ENABLED))
GETIRQ_NAME(MW_TIM17_CH1_DMA_ENABLED)
{
    TIM_IsEnabledDMAITTransferComplete(&(mw_tim17.channel1), GETFCN_LL_GET_STREAM_ACTIVEFLAG(MW_TIM17_CH1_DMA_STREAM), GETFCN_LL_CLEAR_STREAM_ACTIVEFLAG(MW_TIM17_CH1_DMA_STREAM));
}
#endif

#if defined(MW_TIM23_CH1_DMA_ENABLED) && (!MW_GET_IRQ_HANDLER_DEFINE(MW_TIM23_CH1_DMA_ENABLED))
GETIRQ_NAME(MW_TIM23_CH1_DMA_ENABLED)
{
    TIM_IsEnabledDMAITTransferComplete(&(mw_tim23.channel1), GETFCN_LL_GET_STREAM_ACTIVEFLAG(MW_TIM23_CH1_DMA_STREAM), GETFCN_LL_CLEAR_STREAM_ACTIVEFLAG(MW_TIM23_CH1_DMA_STREAM));
}
#endif
#if defined(MW_TIM23_CH2_DMA_ENABLED) && (!MW_GET_IRQ_HANDLER_DEFINE(MW_TIM23_CH2_DMA_ENABLED))
GETIRQ_NAME(MW_TIM23_CH2_DMA_ENABLED)
{
    TIM_IsEnabledDMAITTransferComplete(&(mw_tim23.channel2), GETFCN_LL_GET_STREAM_ACTIVEFLAG(MW_TIM23_CH2_DMA_STREAM), GETFCN_LL_CLEAR_STREAM_ACTIVEFLAG(MW_TIM23_CH2_DMA_STREAM));
}
#endif
#if defined(MW_TIM23_CH3_DMA_ENABLED) && (!MW_GET_IRQ_HANDLER_DEFINE(MW_TIM23_CH3_DMA_ENABLED))
GETIRQ_NAME(MW_TIM23_CH3_DMA_ENABLED)
{
    TIM_IsEnabledDMAITTransferComplete(&(mw_tim23.channel3), GETFCN_LL_GET_STREAM_ACTIVEFLAG(MW_TIM23_CH3_DMA_STREAM), GETFCN_LL_CLEAR_STREAM_ACTIVEFLAG(MW_TIM23_CH3_DMA_STREAM));
}
#endif
#if defined(MW_TIM23_CH4_DMA_ENABLED) && (!MW_GET_IRQ_HANDLER_DEFINE(MW_TIM23_CH4_DMA_ENABLED))
GETIRQ_NAME(MW_TIM23_CH4_DMA_ENABLED)
{
    TIM_IsEnabledDMAITTransferComplete(&(mw_tim23.channel4), GETFCN_LL_GET_STREAM_ACTIVEFLAG(MW_TIM23_CH4_DMA_STREAM), GETFCN_LL_CLEAR_STREAM_ACTIVEFLAG(MW_TIM23_CH4_DMA_STREAM));
}
#endif
#if defined(MW_TIM24_CH1_DMA_ENABLED) && (!MW_GET_IRQ_HANDLER_DEFINE(MW_TIM24_CH1_DMA_ENABLED))
GETIRQ_NAME(MW_TIM24_CH1_DMA_ENABLED)
{
    TIM_IsEnabledDMAITTransferComplete(&(mw_tim24.channel1), GETFCN_LL_GET_STREAM_ACTIVEFLAG(MW_TIM24_CH1_DMA_STREAM), GETFCN_LL_CLEAR_STREAM_ACTIVEFLAG(MW_TIM24_CH1_DMA_STREAM));
}
#endif
#if defined(MW_TIM24_CH2_DMA_ENABLED) && (!MW_GET_IRQ_HANDLER_DEFINE(MW_TIM24_CH2_DMA_ENABLED))
GETIRQ_NAME(MW_TIM24_CH2_DMA_ENABLED)
{
    TIM_IsEnabledDMAITTransferComplete(&(mw_tim24.channel2), GETFCN_LL_GET_STREAM_ACTIVEFLAG(MW_TIM24_CH2_DMA_STREAM), GETFCN_LL_CLEAR_STREAM_ACTIVEFLAG(MW_TIM24_CH2_DMA_STREAM));
}
#endif
#if defined(MW_TIM24_CH3_DMA_ENABLED) && (!MW_GET_IRQ_HANDLER_DEFINE(MW_TIM24_CH3_DMA_ENABLED))
GETIRQ_NAME(MW_TIM24_CH3_DMA_ENABLED)
{
    TIM_IsEnabledDMAITTransferComplete(&(mw_tim24.channel3), GETFCN_LL_GET_STREAM_ACTIVEFLAG(MW_TIM24_CH3_DMA_STREAM), GETFCN_LL_CLEAR_STREAM_ACTIVEFLAG(MW_TIM24_CH3_DMA_STREAM));
}
#endif
#if defined(MW_TIM24_CH4_DMA_ENABLED) && (!MW_GET_IRQ_HANDLER_DEFINE(MW_TIM24_CH4_DMA_ENABLED))
GETIRQ_NAME(MW_TIM24_CH4_DMA_ENABLED)
{
    TIM_IsEnabledDMAITTransferComplete(&(mw_tim24.channel4), GETFCN_LL_GET_STREAM_ACTIVEFLAG(MW_TIM24_CH4_DMA_STREAM), GETFCN_LL_CLEAR_STREAM_ACTIVEFLAG(MW_TIM24_CH4_DMA_STREAM));
}
#endif

#if defined(MW_TIM20_CH1_DMA_ENABLED) && (!MW_GET_IRQ_HANDLER_DEFINE(MW_TIM20_CH1_DMA_ENABLED))
GETIRQ_NAME(MW_TIM20_CH1_DMA_ENABLED)
{
    TIM_IsEnabledDMAITTransferComplete(&(mw_tim20.channel1), GETFCN_LL_GET_STREAM_ACTIVEFLAG(MW_TIM20_CH1_DMA_STREAM), GETFCN_LL_CLEAR_STREAM_ACTIVEFLAG(MW_TIM20_CH1_DMA_STREAM));
}
#endif
#if defined(MW_TIM20_CH2_DMA_ENABLED) && (!MW_GET_IRQ_HANDLER_DEFINE(MW_TIM20_CH2_DMA_ENABLED))
GETIRQ_NAME(MW_TIM20_CH2_DMA_ENABLED)
{
    TIM_IsEnabledDMAITTransferComplete(&(mw_tim20.channel2), GETFCN_LL_GET_STREAM_ACTIVEFLAG(MW_TIM20_CH2_DMA_STREAM), GETFCN_LL_CLEAR_STREAM_ACTIVEFLAG(MW_TIM20_CH2_DMA_STREAM));
}
#endif
#if defined(MW_TIM20_CH3_DMA_ENABLED) && (!MW_GET_IRQ_HANDLER_DEFINE(MW_TIM20_CH3_DMA_ENABLED))
GETIRQ_NAME(MW_TIM20_CH3_DMA_ENABLED)
{
    TIM_IsEnabledDMAITTransferComplete(&(mw_tim20.channel3), GETFCN_LL_GET_STREAM_ACTIVEFLAG(MW_TIM20_CH3_DMA_STREAM), GETFCN_LL_CLEAR_STREAM_ACTIVEFLAG(MW_TIM20_CH3_DMA_STREAM));
}
#endif
#if defined(MW_TIM20_CH4_DMA_ENABLED) && (!MW_GET_IRQ_HANDLER_DEFINE(MW_TIM20_CH4_DMA_ENABLED))
GETIRQ_NAME(MW_TIM20_CH4_DMA_ENABLED)
{
    TIM_IsEnabledDMAITTransferComplete(&(mw_tim20.channel4), GETFCN_LL_GET_STREAM_ACTIVEFLAG(MW_TIM20_CH4_DMA_STREAM), GETFCN_LL_CLEAR_STREAM_ACTIVEFLAG(MW_TIM20_CH4_DMA_STREAM));
}
#endif


/******************************************************************************
* Function Definitions
*******************************************************************************/

/******************************************************************************
* Check Flags
*******************************************************************************/
#ifdef STM32G4

/*Check if TERR flag is active */
uint8_T TIM_IsActiveFlagTERR(TIM_Type_T * ptrTimer)
{
    if ( 1 == LL_TIM_IsActiveFlag_TERR(ptrTimer->PeripheralPtr) )
    {
        ptrTimer->errorStatus = ptrTimer->errorStatus | ENCODER_TRANSITION_ERROR ;
    }
    return (ptrTimer->errorStatus & ENCODER_TRANSITION_ERROR );
}

/*Check if IERR flag is active */
uint8_T TIM_IsActiveFlagIERR(TIM_Type_T * ptrTimer)
{
    if ( 1 == LL_TIM_IsActiveFlag_IERR(ptrTimer->PeripheralPtr) )
    {
        ptrTimer->errorStatus = ptrTimer->errorStatus | ENCODER_INDEX_ERROR ;
    }
    return (ptrTimer->errorStatus & ENCODER_INDEX_ERROR );
}

/*Check if IDX flag is active */
boolean_T TIM_IsActiveFlagIDX(TIM_Type_T * ptrTimer)
{
    if(1 == LL_TIM_IsActiveFlag_IDX(ptrTimer->PeripheralPtr))
    {
        ptrTimer->firstIndexReceivedStatus = 1 ;
    }
    return (ptrTimer->firstIndexReceivedStatus == 1 );
}
#endif

/*Check if CC1 flag is active */
boolean_T TIM_IsActiveFlag_CC1(TIM_Type_T * ptrTimer)
{
    if ( 1 == LL_TIM_IsActiveFlag_CC1(ptrTimer->PeripheralPtr) )
    {
        ptrTimer->cc1Flag = 1 ;
    }
    return (ptrTimer->cc1Flag == 1 ) ;
}

/*Check if CC2 flag is active */
boolean_T TIM_IsActiveFlag_CC2(TIM_Type_T * ptrTimer)
{
    if ( 1 == LL_TIM_IsActiveFlag_CC2(ptrTimer->PeripheralPtr) )
    {
        ptrTimer->cc2Flag = 1 ;
    }
    return (ptrTimer->cc2Flag == 1 );
}

/*Check if CC3 flag is active */
boolean_T TIM_IsActiveFlag_CC3(TIM_Type_T * ptrTimer)
{
    if ( 1 == LL_TIM_IsActiveFlag_CC3(ptrTimer->PeripheralPtr) )
    {
        ptrTimer->cc3Flag = 1 ;
    }
    return (ptrTimer->cc3Flag == 1 );
}

/*Check if CC4 flag is active */
boolean_T TIM_IsActiveFlag_CC4(TIM_Type_T * ptrTimer)
{
    if ( 1 == LL_TIM_IsActiveFlag_CC4(ptrTimer->PeripheralPtr) )
    {
        ptrTimer->cc4Flag = 1 ;
    }
    return (ptrTimer->cc4Flag == 1 );
}

/******************************************************************************
* Enable and Disable timer Interrupts
*******************************************************************************/

/*Enable Timer Interrupts */
void enableTimerInterrupts(TIM_Type_T * ptrTimer, uint16_T interruptsToEnable)
{
    if( (interruptsToEnable & 1) &&  (1 != LL_TIM_IsEnabledIT_TRIG(ptrTimer->PeripheralPtr)))
    {
        //Enable Trigger Interrupt
        LL_TIM_EnableIT_TRIG(ptrTimer->PeripheralPtr);
    }
    if( (interruptsToEnable & 2) &&  (1 != LL_TIM_IsEnabledIT_CC1(ptrTimer->PeripheralPtr)))
    {
        //Enable Capture Compare 1 Interrupt
        LL_TIM_EnableIT_CC1(ptrTimer->PeripheralPtr);
    }
    if( (interruptsToEnable & 4) && (1 != LL_TIM_IsEnabledIT_CC2(ptrTimer->PeripheralPtr)))
    {
        //Enable Capture Compare 2 Interrupt
        LL_TIM_EnableIT_CC2(ptrTimer->PeripheralPtr);
    }
    if((interruptsToEnable & 8) && (1 != LL_TIM_IsEnabledIT_CC3(ptrTimer->PeripheralPtr)) )
    {
        //Enable Capture Compare 3 Interrupt
        LL_TIM_EnableIT_CC3(ptrTimer->PeripheralPtr);
    }
    if( (interruptsToEnable & 16) &&  (1 != LL_TIM_IsEnabledIT_CC4(ptrTimer->PeripheralPtr)))
    {
        //Enable Capture Compare 4 Interrupt
        LL_TIM_EnableIT_CC4(ptrTimer->PeripheralPtr);
    }
    if( (interruptsToEnable & 32) &&  (1 != LL_TIM_IsEnabledIT_UPDATE(ptrTimer->PeripheralPtr)))
    {
        //Enable Update Interrupt
        LL_TIM_EnableIT_UPDATE(ptrTimer->PeripheralPtr);
    }
    if( (interruptsToEnable & 64) &&  (1 != LL_TIM_IsEnabledIT_BRK(ptrTimer->PeripheralPtr)) )
    {
        //Enable Break Interrupt
        LL_TIM_EnableIT_BRK(ptrTimer->PeripheralPtr);
    }
    if( (interruptsToEnable & 128) &&  (1 != LL_TIM_IsEnabledIT_COM(ptrTimer->PeripheralPtr)) )
    {
        //Enable Break Interrupt
        LL_TIM_EnableIT_COM(ptrTimer->PeripheralPtr);
    }
    #ifdef STM32G4
    if( (interruptsToEnable & 256) &&  (1 != LL_TIM_IsEnabledIT_IDX(ptrTimer->PeripheralPtr)) )
    {
        //Enable Index Interrupt
        LL_TIM_EnableIT_IDX(ptrTimer->PeripheralPtr);
    }
    if( (interruptsToEnable & 512) &&  (1 != LL_TIM_IsEnabledIT_DIR(ptrTimer->PeripheralPtr)) )
    {
        //Enable Direction Interrupt
        LL_TIM_EnableIT_DIR(ptrTimer->PeripheralPtr);
    }
    if( (interruptsToEnable & 1024) &&  (1 != LL_TIM_IsEnabledIT_TERR(ptrTimer->PeripheralPtr)) )
    {
        //Enable Transition error Interrupt
        LL_TIM_EnableIT_TERR(ptrTimer->PeripheralPtr);
    }
    if( (interruptsToEnable & 2048) &&  (1 != LL_TIM_IsEnabledIT_IERR(ptrTimer->PeripheralPtr)) )
    {
        //Enable Index error Interrupt
        LL_TIM_EnableIT_IERR(ptrTimer->PeripheralPtr);
    }
    #endif
}

/*Disable Timer Interrupts */
void disableTimerInterrupts(TIM_Type_T * ptrTimer, uint16_T interruptsToDisable)
{
    if( (interruptsToDisable & 1) &&  (1 == LL_TIM_IsEnabledIT_TRIG(ptrTimer->PeripheralPtr)))
    {
        //Disable Trigger Interrupt
        LL_TIM_DisableIT_TRIG(ptrTimer->PeripheralPtr);
    }
    if( (interruptsToDisable & 2) &&  (1 == LL_TIM_IsEnabledIT_CC1(ptrTimer->PeripheralPtr)))
    {
        //Disable Capture Compare 1 Interrupt
        LL_TIM_DisableIT_CC1(ptrTimer->PeripheralPtr);
    }
    if( (interruptsToDisable & 4) && (1 == LL_TIM_IsEnabledIT_CC2(ptrTimer->PeripheralPtr)))
    {
        //Disable Capture Compare 2 Interrupt
        LL_TIM_DisableIT_CC2(ptrTimer->PeripheralPtr);
    }
    if((interruptsToDisable & 8) && (1 == LL_TIM_IsEnabledIT_CC3(ptrTimer->PeripheralPtr)) )
    {
        //Disable Capture Compare 3 Interrupt
        LL_TIM_DisableIT_CC3(ptrTimer->PeripheralPtr);
    }
    if( (interruptsToDisable & 16) &&  (1 == LL_TIM_IsEnabledIT_CC4(ptrTimer->PeripheralPtr)))
    {
        //Disable Capture Compare 4 Interrupt
        LL_TIM_DisableIT_CC4(ptrTimer->PeripheralPtr);
    }
    if( (interruptsToDisable & 32) &&  (1 != LL_TIM_IsEnabledIT_UPDATE(ptrTimer->PeripheralPtr)))
    {
        //Disable Update Interrupt
        LL_TIM_DisableIT_UPDATE(ptrTimer->PeripheralPtr);
    }
    if((interruptsToDisable & 64) &&  (1 == LL_TIM_IsEnabledIT_BRK(ptrTimer->PeripheralPtr)))
    {
        //Disable Break Interrupt
        LL_TIM_DisableIT_BRK(ptrTimer->PeripheralPtr);
    }
    if( (interruptsToDisable & 128) &&  (1 == LL_TIM_IsEnabledIT_COM(ptrTimer->PeripheralPtr)) )
    {
        //Disable Break Interrupt
        LL_TIM_DisableIT_COM(ptrTimer->PeripheralPtr);
    }
    #ifdef STM32G4
    if( (interruptsToDisable & 256) &&  (1 == LL_TIM_IsEnabledIT_IDX(ptrTimer->PeripheralPtr)) )
    {
        //Disable Index Interrupt
        LL_TIM_DisableIT_IDX(ptrTimer->PeripheralPtr);
    }
    if( (interruptsToDisable & 512) &&  (1 == LL_TIM_IsEnabledIT_DIR(ptrTimer->PeripheralPtr)) )
    {
        //Disable Direction Interrupt
        LL_TIM_DisableIT_DIR(ptrTimer->PeripheralPtr);
    }
    if( (interruptsToDisable & 1024) &&  (1 == LL_TIM_IsEnabledIT_TERR(ptrTimer->PeripheralPtr)) )
    {
        //Disable Transition error Interrupt
        LL_TIM_DisableIT_TERR(ptrTimer->PeripheralPtr);
    }
    if( (interruptsToDisable & 2048) &&  (1 == LL_TIM_IsEnabledIT_IERR(ptrTimer->PeripheralPtr)) )
    {
        //Disable Index error Interrupt
        LL_TIM_DisableIT_IERR(ptrTimer->PeripheralPtr);
    }
    #endif

}

/******************************************************************************
* Enable and Disable Timer channels
*******************************************************************************/

/* Enable the Timer Capture compare channel 1 */
void enableTimerChannel1(TIM_Type_T * ptrTimer,  uint8_T PWMChannelInfo)
{
    if(PWMChannelInfo == ENABLE_CH)
    {
        LL_TIM_CC_EnableChannel(ptrTimer->PeripheralPtr, LL_TIM_CHANNEL_CH1);
    }
    else if  (IS_TIM_BREAK_INSTANCE(ptrTimer->PeripheralPtr))
    {
        if(PWMChannelInfo == ENABLE_CHN)
        {
            LL_TIM_CC_EnableChannel(ptrTimer->PeripheralPtr, LL_TIM_CHANNEL_CH1N);
        }
        else if(PWMChannelInfo == ENABLE_CH_CHN)
        {
            LL_TIM_CC_EnableChannel(ptrTimer->PeripheralPtr, LL_TIM_CHANNEL_CH1);
            LL_TIM_CC_EnableChannel(ptrTimer->PeripheralPtr, LL_TIM_CHANNEL_CH1N);
        }
    }
}

/* Disable Timer Capture Compare Channel 1 */
void disableTimerChannel1(TIM_Type_T * ptrTimer,  uint8_T PWMChannelInfo)
{
    if(PWMChannelInfo == ENABLE_CH)
    {
        LL_TIM_CC_DisableChannel(ptrTimer->PeripheralPtr, LL_TIM_CHANNEL_CH1);
    }
    else if  (IS_TIM_BREAK_INSTANCE(ptrTimer->PeripheralPtr))
    {
        if(PWMChannelInfo == ENABLE_CHN)
        {
            LL_TIM_CC_DisableChannel(ptrTimer->PeripheralPtr, LL_TIM_CHANNEL_CH1N);
        }
        else if(PWMChannelInfo == ENABLE_CH_CHN)
        {
            LL_TIM_CC_DisableChannel(ptrTimer->PeripheralPtr, LL_TIM_CHANNEL_CH1);
            LL_TIM_CC_DisableChannel(ptrTimer->PeripheralPtr, LL_TIM_CHANNEL_CH1N);
        }
    }
}

/* Enable the Timer Capture compare channel 2 */
void enableTimerChannel2(TIM_Type_T * ptrTimer,  uint8_T PWMChannelInfo)
{
    if(PWMChannelInfo == ENABLE_CH)
    {
        LL_TIM_CC_EnableChannel(ptrTimer->PeripheralPtr, LL_TIM_CHANNEL_CH2);
    }
    else if  (IS_TIM_BREAK_INSTANCE(ptrTimer->PeripheralPtr))
    {
        if(PWMChannelInfo == ENABLE_CHN)
        {
            LL_TIM_CC_EnableChannel(ptrTimer->PeripheralPtr, LL_TIM_CHANNEL_CH2N);
        }
        else if(PWMChannelInfo == ENABLE_CH_CHN)
        {
            LL_TIM_CC_EnableChannel(ptrTimer->PeripheralPtr, LL_TIM_CHANNEL_CH2);
            LL_TIM_CC_EnableChannel(ptrTimer->PeripheralPtr, LL_TIM_CHANNEL_CH2N);
        }
    }
}

/* Disable the Timer Capture compare channel 2 */
void disableTimerChannel2(TIM_Type_T * ptrTimer,  uint8_T PWMChannelInfo)
{
    if(PWMChannelInfo == ENABLE_CH)
    {
        LL_TIM_CC_DisableChannel(ptrTimer->PeripheralPtr, LL_TIM_CHANNEL_CH2);
    }

    else if  (IS_TIM_BREAK_INSTANCE(ptrTimer->PeripheralPtr))
    {
        if(PWMChannelInfo == ENABLE_CHN)
        {
            LL_TIM_CC_DisableChannel(ptrTimer->PeripheralPtr, LL_TIM_CHANNEL_CH2N);
        }
        else if(PWMChannelInfo == ENABLE_CH_CHN)
        {
            LL_TIM_CC_DisableChannel(ptrTimer->PeripheralPtr, LL_TIM_CHANNEL_CH2);
            LL_TIM_CC_DisableChannel(ptrTimer->PeripheralPtr, LL_TIM_CHANNEL_CH2N);
        }
    }
}

/* Enable the Timer Capture compare channel 3 */
void enableTimerChannel3(TIM_Type_T * ptrTimer,  uint8_T PWMChannelInfo)
{
    if(PWMChannelInfo == ENABLE_CH)
    {
        LL_TIM_CC_EnableChannel(ptrTimer->PeripheralPtr, LL_TIM_CHANNEL_CH3);
    }
    else if  (IS_TIM_BREAK_INSTANCE(ptrTimer->PeripheralPtr))
    {
        if(PWMChannelInfo == ENABLE_CHN)
        {
            LL_TIM_CC_EnableChannel(ptrTimer->PeripheralPtr, LL_TIM_CHANNEL_CH3N);
        }
        else if(PWMChannelInfo == ENABLE_CH_CHN)
        {
            LL_TIM_CC_EnableChannel(ptrTimer->PeripheralPtr, LL_TIM_CHANNEL_CH3);
            LL_TIM_CC_EnableChannel(ptrTimer->PeripheralPtr, LL_TIM_CHANNEL_CH3N);
        }
    }
}

/* Disable the Timer Capture compare channel 3 */
void disableTimerChannel3(TIM_Type_T * ptrTimer,  uint8_T PWMChannelInfo)
{
    if(PWMChannelInfo == ENABLE_CH)
    {
        LL_TIM_CC_DisableChannel(ptrTimer->PeripheralPtr, LL_TIM_CHANNEL_CH3);
    }
    else if  (IS_TIM_BREAK_INSTANCE(ptrTimer->PeripheralPtr))
    {
        if(PWMChannelInfo == ENABLE_CHN)
        {
            LL_TIM_CC_DisableChannel(ptrTimer->PeripheralPtr, LL_TIM_CHANNEL_CH3N);
        }
        else if(PWMChannelInfo == ENABLE_CH_CHN)
        {
            LL_TIM_CC_DisableChannel(ptrTimer->PeripheralPtr, LL_TIM_CHANNEL_CH3);
            LL_TIM_CC_DisableChannel(ptrTimer->PeripheralPtr, LL_TIM_CHANNEL_CH3N);
        }
    }
}

/* Enable the Timer Capture compare channel 4 */
void enableTimerChannel4(TIM_Type_T * ptrTimer,  uint8_T PWMChannelInfo)
{
    if(PWMChannelInfo == ENABLE_CH)
    {
        LL_TIM_CC_EnableChannel(ptrTimer->PeripheralPtr, LL_TIM_CHANNEL_CH4);
    }
}

/* Disable the Timer Capture compare channel 4 */
void disableTimerChannel4(TIM_Type_T * ptrTimer,  uint8_T PWMChannelInfo)
{
    if(PWMChannelInfo == ENABLE_CH)
    {
        LL_TIM_CC_DisableChannel(ptrTimer->PeripheralPtr, LL_TIM_CHANNEL_CH4);
    }
}

/******************************************************************************
* Initialize Timer Handle
*******************************************************************************/

/*Initialize the timer */
TIM_Type_T * Timer_Handle_Init(TIM_Type_T * ptrTimer)
{
    TIM_Type_T* tempTimerPtr = NULL;

    //Initialize the peripheral ptr
    #if defined(TIM1) && defined(MW_TIM1_ENABLED)

    if ( (TIM_TypeDef *)TIM1 == (TIM_TypeDef  *)ptrTimer->PeripheralPtr)
    {
        tempTimerPtr = &mw_tim1;
    }
    else
        #endif

        #if defined(TIM2) && defined(MW_TIM2_ENABLED)
        if ((TIM_TypeDef *)TIM2 == (TIM_TypeDef  *)ptrTimer->PeripheralPtr)
        {
            tempTimerPtr = &mw_tim2;
        }
    else
        #endif
        #if defined(TIM3) && defined(MW_TIM3_ENABLED)
        if ((TIM_TypeDef *)TIM3 == (TIM_TypeDef *)ptrTimer->PeripheralPtr)
        {
            tempTimerPtr = &mw_tim3;
        }
    else
        #endif

        #if defined(TIM4) && defined(MW_TIM4_ENABLED)
        if ((TIM_TypeDef *)TIM4 == (TIM_TypeDef *)ptrTimer->PeripheralPtr)
        {
            tempTimerPtr = &mw_tim4;
        }
    else
        #endif
        #if defined(TIM5) && defined(MW_TIM5_ENABLED)
        if ( (TIM_TypeDef *)TIM5 == (TIM_TypeDef *)ptrTimer->PeripheralPtr)
        {
            tempTimerPtr = &mw_tim5;
        }
    else
        #endif

        #if defined(TIM6) && defined(MW_TIM6_ENABLED)
        if ((TIM_TypeDef *)TIM6 == (TIM_TypeDef *)ptrTimer->PeripheralPtr)
        {
            tempTimerPtr = &mw_tim6;
        }
    else
        #endif
        #if defined(TIM7) && defined(MW_TIM7_ENABLED)
        if ((TIM_TypeDef *)TIM7 == (TIM_TypeDef *)ptrTimer->PeripheralPtr)
        {
            tempTimerPtr = &mw_tim7;
        }
    else
        #endif
        #if defined(TIM8) && defined(MW_TIM8_ENABLED)
        if ((TIM_TypeDef *)TIM8 == (TIM_TypeDef *)ptrTimer->PeripheralPtr)
        {
            tempTimerPtr = &mw_tim8;
        }
    else
        #endif
        #if defined(TIM9) && defined(MW_TIM9_ENABLED)
        if ((TIM_TypeDef *)TIM9 == (TIM_TypeDef *)ptrTimer->PeripheralPtr)
        {
            tempTimerPtr = &mw_tim9;
        }
    else
        #endif
        #if defined(TIM10) && defined(MW_TIM10_ENABLED)
        if ( (TIM_TypeDef *)TIM10 == (TIM_TypeDef *)ptrTimer->PeripheralPtr)
        {
            tempTimerPtr = &mw_tim10;
        }
    else
        #endif
        #if defined(TIM11) && defined(MW_TIM11_ENABLED)
        if ((TIM_TypeDef *)TIM11 == (TIM_TypeDef *)ptrTimer->PeripheralPtr)
        {
            tempTimerPtr = &mw_tim11;
        }
    else
        #endif
        #if defined(TIM12) && defined(MW_TIM12_ENABLED)
        if ((TIM_TypeDef *)TIM12 == (TIM_TypeDef *)ptrTimer->PeripheralPtr)
        {
            tempTimerPtr = &mw_tim12;
        }
    else
        #endif
        #if defined(TIM13) && defined(MW_TIM13_ENABLED)
        if ((TIM_TypeDef *)TIM13 == (TIM_TypeDef *)ptrTimer->PeripheralPtr)
        {
            tempTimerPtr = &mw_tim13;
        }
    else
        #endif
        #if defined(TIM14) && defined(MW_TIM14_ENABLED)
        if ((TIM_TypeDef *)TIM14 == (TIM_TypeDef *)ptrTimer->PeripheralPtr)
        {
            tempTimerPtr = &mw_tim14;
        }
    else
        #endif
        #if defined(TIM15) && defined(MW_TIM15_ENABLED)
        if ((TIM_TypeDef *)TIM15 == (TIM_TypeDef *)ptrTimer->PeripheralPtr)
        {
            tempTimerPtr = &mw_tim15;
        }
    else
        #endif
        #if defined(TIM16) && defined(MW_TIM16_ENABLED)
        if ((TIM_TypeDef *)TIM16 == (TIM_TypeDef *)ptrTimer->PeripheralPtr)
        {
            tempTimerPtr = &mw_tim16;
        }
    else
        #endif
        #if defined(TIM17) && defined(MW_TIM17_ENABLED)
        if ((TIM_TypeDef *)TIM17 == (TIM_TypeDef *)ptrTimer->PeripheralPtr)
        {
            tempTimerPtr = &mw_tim17;
        }
    else
        #endif
        #if defined(TIM18) && defined(MW_TIM18_ENABLED)
        if ((TIM_TypeDef *)TIM18 == (TIM_TypeDef *)ptrTimer->PeripheralPtr)
        {
            tempTimerPtr = &mw_tim18;
        }
    else
        #endif
        #if defined(TIM19) && defined(MW_TIM19_ENABLED)
        if ((TIM_TypeDef *)TIM19 == (TIM_TypeDef *)ptrTimer->PeripheralPtr)
        {
            tempTimerPtr = &mw_tim19;
        }
    else
        #endif
        #if defined(TIM20) && defined(MW_TIM20_ENABLED)
        if ((TIM_TypeDef *)TIM20 == (TIM_TypeDef *)ptrTimer->PeripheralPtr)
        {
            tempTimerPtr = &mw_tim20;
        }
    else
        #endif
        #if defined(TIM23) && defined(MW_TIM23_ENABLED)
        if ((TIM_TypeDef *)TIM23 == (TIM_TypeDef *)ptrTimer->PeripheralPtr)
        {
            tempTimerPtr = &mw_tim23;
        }
    else
        #endif
        #if defined(TIM24) && defined(MW_TIM24_ENABLED)
        if ((TIM_TypeDef *)TIM24 == (TIM_TypeDef *)ptrTimer->PeripheralPtr)
        {
            tempTimerPtr = &mw_tim24;
        }
    else
        #endif
    {
    }
    tempTimerPtr->PeripheralPtr = (TIM_TypeDef *)ptrTimer->PeripheralPtr;
    uint32_t mode =  LL_TIM_GetCounterMode (tempTimerPtr->PeripheralPtr);
    if( (mode != LL_TIM_COUNTERMODE_UP) && (mode != LL_TIM_COUNTERMODE_DOWN))
    {
        tempTimerPtr->isCenterAlignedMode = 1;
    }
    else
    {
        tempTimerPtr->isCenterAlignedMode = 0;
    }

    // Enable the MOE bit if AOE bit is disabled in STM32CubemMX for Advanced TIMERS
    if( IS_TIM_BREAK_INSTANCE(tempTimerPtr->PeripheralPtr))
    {
        LL_TIM_EnableAllOutputs(tempTimerPtr->PeripheralPtr);
    }
    //Get the current repetition counter value
    if( IS_TIM_REPETITION_COUNTER_INSTANCE(tempTimerPtr->PeripheralPtr))
    {
        tempTimerPtr->repetitionCounter = (uint8_T)LL_TIM_GetRepetitionCounter(ptrTimer->PeripheralPtr) ;
    }
    #ifdef STM32G4
    tempTimerPtr->errorStatus = ENCODER_NO_ERROR;
    tempTimerPtr->firstIndexReceivedStatus = 0;
    #endif

    return tempTimerPtr;
}

/*Configure DMA for Timer capture if capture length > 1*/
void configureDMAForChannel(TIM_Type_T * ptrTimer, Channel_DMA_T ptrTimChannel, uint8_T channel)
{
    register uint32_t data_reg_addr = 0;
    switch (channel)
    {
        case 1:
            data_reg_addr = (uint32_t)&(((TIM_TypeDef *)ptrTimer->PeripheralPtr)->CCR1);
            ptrTimer->channel1 = ptrTimChannel;
            ptrTimer->cc1Flag = 0;
            break;
        case 2:
            data_reg_addr = (uint32_t)&(((TIM_TypeDef *)ptrTimer->PeripheralPtr)->CCR2);
            ptrTimer->channel2 = ptrTimChannel;
            ptrTimer->cc2Flag = 0;
            break;
        case 3:
            data_reg_addr = (uint32_t)&(((TIM_TypeDef *)ptrTimer->PeripheralPtr)->CCR3);
            ptrTimer->channel3 = ptrTimChannel;
            ptrTimer->cc3Flag = 0;
            break;
        case 4:
            data_reg_addr = (uint32_t)&(((TIM_TypeDef *)ptrTimer->PeripheralPtr)->CCR4);
            ptrTimer->channel4 = ptrTimChannel;
            ptrTimer->cc4Flag = 0;
            break;
    }

    /* Enable TC interrupts */
    if(IS_TIM_32B_COUNTER_INSTANCE(ptrTimer->PeripheralPtr))
    {
        #if defined(GPDMA1)
        LL_DMA_ConfigAddresses(ptrTimChannel.dmaPeripheralPtr, (uint32_t)ptrTimChannel.dmastream,data_reg_addr ,
                               (uint32_t)&ptrTimChannel.buffer.bufferPtr32Bit[0]);
        #else
            LL_DMA_ConfigAddresses(ptrTimChannel.dmaPeripheralPtr, (uint32_t)ptrTimChannel.dmastream,data_reg_addr ,
                               (uint32_t)&ptrTimChannel.buffer.bufferPtr32Bit[0],
                               LL_DMA_DIRECTION_PERIPH_TO_MEMORY);
        #endif
    }
    else
    {
        #if defined(GPDMA1)
        LL_DMA_ConfigAddresses(ptrTimChannel.dmaPeripheralPtr, (uint32_t)ptrTimChannel.dmastream,data_reg_addr ,
                                   (uint32_t)&ptrTimChannel.buffer.bufferPtr16Bit[0]);
        #else
            LL_DMA_ConfigAddresses(ptrTimChannel.dmaPeripheralPtr, (uint32_t)ptrTimChannel.dmastream,data_reg_addr,
                               (uint32_t)&ptrTimChannel.buffer.bufferPtr16Bit[0],
                               LL_DMA_DIRECTION_PERIPH_TO_MEMORY);
        #endif
    }

    #if defined(GPDMA1)
        LL_DMA_SetBlkDataLength(ptrTimChannel.dmaPeripheralPtr, (uint32_t)ptrTimChannel.dmastream, ptrTimChannel.buffer.bufferSize);
    #else
    LL_DMA_SetDataLength(ptrTimChannel.dmaPeripheralPtr, (uint32_t)ptrTimChannel.dmastream, ptrTimChannel.buffer.bufferSize);
    #endif

    LL_DMA_EnableIT_TC(ptrTimChannel.dmaPeripheralPtr, (uint32_t)ptrTimChannel.dmastream);

    LL_TIM_CC_SetDMAReqTrigger(ptrTimer->PeripheralPtr,LL_TIM_CCDMAREQUEST_CC);

    switch (channel)
    {
        case 1:
            LL_TIM_EnableDMAReq_CC1(ptrTimer->PeripheralPtr);
            break;
        case 2:
            LL_TIM_EnableDMAReq_CC2(ptrTimer->PeripheralPtr);
            break;
        case 3:
            LL_TIM_EnableDMAReq_CC3(ptrTimer->PeripheralPtr);
            break;
        case 4:
            LL_TIM_EnableDMAReq_CC4(ptrTimer->PeripheralPtr);
            break;
    }
    /* Enable USART and DMA Stream */
    #if defined(STM32G4)  || defined(STM32WB) || defined(STM32L5) || defined(STM32L4) || defined(STM32U5)
    LL_DMA_EnableChannel(ptrTimChannel.dmaPeripheralPtr, (uint32_t)ptrTimChannel.dmastream);
    #else
    LL_DMA_EnableStream(ptrTimChannel.dmaPeripheralPtr, (uint32_t)ptrTimChannel.dmastream);
    #endif
}


/*Check that frequeny/duty cycle is not greater than 65535 for 16 bit timers */
uint32_T checkFrequencyAndDutyCycleLimits(TIM_Type_T * ptrTimer, uint32_T input)
{
    uint32_t ret = input;
    if ((input > 65535) && (!IS_TIM_32B_COUNTER_INSTANCE(ptrTimer->PeripheralPtr)))
    {
        ret = 65535;
    }
    return ret;
}

/******************************************************************************
* Internal functions to get data from buffer
*******************************************************************************/

/* Get data available in internal recieve buffer */
uint32_T getAvailableDataInTimerBuffer(Channel_DMA_T * ptrTimChannel)
{
	boolean_T rollOverFlag = ptrTimChannel->buffer.writeRollOver;
    #if defined(GPDMA1)
        uint32_T dmaDataToBeTransferred = LL_DMA_GetBlkDataLength(ptrTimChannel->dmaPeripheralPtr, (uint32_t)ptrTimChannel->dmastream);
    #else
	uint32_T dmaDataToBeTransferred = LL_DMA_GetDataLength(ptrTimChannel->dmaPeripheralPtr, (uint32_t)ptrTimChannel->dmastream);
    #endif
    uint32_T nbDataPos = (ptrTimChannel->buffer.bufferSize - dmaDataToBeTransferred);
    if(nbDataPos == ptrTimChannel->buffer.bufferSize)
    {
        nbDataPos = 0;
    }

    /* Update read position to nbDataPos if buffer is overwritten in DMA mode i.e. read data which is not overwritten */
    if(1 == rollOverFlag)
    {
        if(nbDataPos > ptrTimChannel->buffer.readPos)
        {
            ptrTimChannel->errorStatus =  ptrTimChannel->errorStatus |  MW_TIM_OVERRUN_ERROR;
            ptrTimChannel->buffer.readPos = nbDataPos;
        }
    }

    if (nbDataPos > ptrTimChannel->buffer.readPos)
    {
        /* No rollover condition */
        return  (nbDataPos - ptrTimChannel->buffer.readPos);
    }
    else if  (nbDataPos < ptrTimChannel->buffer.readPos)
    {
        /* Rollover condition */
        return  ((ptrTimChannel->buffer.bufferSize - (ptrTimChannel->buffer.readPos)) + nbDataPos);
    }
    else
    {
        if(1 == rollOverFlag)
        {
            return (ptrTimChannel->buffer.bufferSize);
        }
        else
        {
            return 0;
        }
    }
}

/*Read data from 16 bit buffer */
void getDataFrom16BitTimerBuffer(Channel_DMA_T * ptrTimChannel, uint16_T *dataPtr, uint32_T dataToRead)
 {
    #if defined(MW_DCACHE_ENABLED) //Invalidate cache if enabled before reading from DMA buffer
    SCB_InvalidateDCache_by_Addr((uint32_t *)&ptrTimChannel->buffer.bufferPtr16Bit[0],  DMA_BUFFER_SIZE_BYTE_ALLIGNED(ptrTimChannel->buffer.bufferSize, 32) * 2);
    #endif
    if (((ptrTimChannel->buffer.readPos ) + dataToRead) > ptrTimChannel->buffer.bufferSize)
    {
        int lengthToReadFromBottom = (ptrTimChannel->buffer.bufferSize - ptrTimChannel->buffer.readPos);
        memcpy(dataPtr,&ptrTimChannel->buffer.bufferPtr16Bit[ptrTimChannel->buffer.readPos],(lengthToReadFromBottom * 2));

        ptrTimChannel->buffer.readPos = (ptrTimChannel->buffer.readPos + dataToRead) - ptrTimChannel->buffer.bufferSize;
        memcpy((dataPtr + lengthToReadFromBottom),&ptrTimChannel->buffer.bufferPtr16Bit[0],(ptrTimChannel->buffer.readPos * 2));
        ptrTimChannel->buffer.writeRollOver = 0;
    }
    else
    {
        memcpy(dataPtr,&ptrTimChannel->buffer.bufferPtr16Bit[ptrTimChannel->buffer.readPos],(dataToRead * 2));
        ptrTimChannel->buffer.readPos+=dataToRead;
    }
}

/*Read data from 32 bit buffer */
void getDataFrom32BitTimerBuffer(Channel_DMA_T * ptrTimChannel, uint32_T *dataPtr, uint32_T dataToRead)
{
    #if defined(MW_DCACHE_ENABLED) //Invalidate cache if enabled before reading from DMA buffer
    SCB_InvalidateDCache_by_Addr((uint32_t *)&ptrTimChannel->buffer.bufferPtr32Bit[0],  DMA_BUFFER_SIZE_BYTE_ALLIGNED(ptrTimChannel->buffer.bufferSize, 32) * 4);
    #endif
    if (((ptrTimChannel->buffer.readPos ) + dataToRead) > ptrTimChannel->buffer.bufferSize)
    {
        int lengthToReadFromBottom = (ptrTimChannel->buffer.bufferSize - ptrTimChannel->buffer.readPos);
        memcpy(dataPtr,&ptrTimChannel->buffer.bufferPtr32Bit[ptrTimChannel->buffer.readPos],(lengthToReadFromBottom * 4));

        ptrTimChannel->buffer.readPos = (ptrTimChannel->buffer.readPos + dataToRead) - ptrTimChannel->buffer.bufferSize;
        memcpy((dataPtr + lengthToReadFromBottom),&ptrTimChannel->buffer.bufferPtr32Bit[0],(ptrTimChannel->buffer.readPos * 4));
        ptrTimChannel->buffer.writeRollOver = 0;
    }
    else
    {
        memcpy(dataPtr,&ptrTimChannel->buffer.bufferPtr32Bit[ptrTimChannel->buffer.readPos],(dataToRead * 4));
        ptrTimChannel->buffer.readPos+=dataToRead;
    }
}

/*Read data from timer internal receive buffer */
uint8_T readDataFromTimerBuffer(TIM_Type_T * TimerPtr, Channel_DMA_T * ptrTimChannel, void *dataPtr, uint32_T dataToRead, uint32_T *receivedLength)
{
    *receivedLength = 0;
    uint8_T status = MW_TIM_SUCCESS;

    uint32_T availableData = getAvailableDataInTimerBuffer(ptrTimChannel);
    if (availableData < dataToRead)
    {
        dataToRead = availableData;
    }
    if(availableData > 0)
    {
        if(IS_TIM_32B_COUNTER_INSTANCE(TimerPtr->PeripheralPtr))
        {
            getDataFrom32BitTimerBuffer(ptrTimChannel, (uint32_T *)dataPtr, dataToRead);
        }
        else
        {
            getDataFrom16BitTimerBuffer(ptrTimChannel, (uint16_T *)dataPtr, dataToRead);
        }

        if(ptrTimChannel->buffer.readPos == ptrTimChannel->buffer.bufferSize )
        {
            ptrTimChannel->buffer.readPos = 0;
            ptrTimChannel->buffer.writeRollOver = 0;
        }
        status = ptrTimChannel->errorStatus;
        ptrTimChannel->errorStatus = MW_TIM_SUCCESS;
    }
    *receivedLength = dataToRead;
    return status;
}

/******************************************************************************
* Internal functions to get capture data
*******************************************************************************/

/* Read capture comapre register 1  in DMA mode */
uint8_T getCCR1RegisterValueDMAMode(TIM_Type_T * TimerPtr, void *data, uint32_T dataLength, uint32_T *receivedLength)
{

    return readDataFromTimerBuffer(TimerPtr,&TimerPtr->channel1, data, dataLength, receivedLength);
}
/* Read capture comapre register 2  in DMA mode */
uint8_T getCCR2RegisterValueDMAMode(TIM_Type_T * TimerPtr, void *data, uint32_T dataLength, uint32_T *receivedLength)
{
    return readDataFromTimerBuffer(TimerPtr,&TimerPtr->channel2, data, dataLength, receivedLength);
}
/* Read capture comapre register 3  in DMA mode */
uint8_T getCCR3RegisterValueDMAMode(TIM_Type_T * TimerPtr, void *data, uint32_T dataLength, uint32_T *receivedLength)
{
    return readDataFromTimerBuffer(TimerPtr,&TimerPtr->channel3, data, dataLength, receivedLength);
}
/* Read capture comapre register 4  in DMA mode */
uint8_T getCCR4RegisterValueDMAMode(TIM_Type_T * TimerPtr, void *data, uint32_T dataLength, uint32_T *receivedLength)
{
    return readDataFromTimerBuffer(TimerPtr,&TimerPtr->channel4, data, dataLength, receivedLength);
}
/* Read capture comapre register 1  in polling mode */
uint8_T getCCR1RegisterValuePollingMode(TIM_Type_T * TimerPtr, void *data, uint32_T *receivedLen)
{
    uint8_T status = MW_TIM_SUCCESS;
    if(0 ==  TIM_IsActiveFlag_CC1(TimerPtr))
    {
        *receivedLen = 0;
    }
    else
    {
        if(IS_TIM_32B_COUNTER_INSTANCE(TimerPtr->PeripheralPtr))
        {
            *(uint32_T *)data = LL_TIM_IC_GetCaptureCH1(TimerPtr->PeripheralPtr);
        }
        else
        {
            *(uint16_T *)data = LL_TIM_IC_GetCaptureCH1(TimerPtr->PeripheralPtr);
        }
        LL_TIM_ClearFlag_CC1(TimerPtr->PeripheralPtr);
        TimerPtr->cc1Flag = 0;
        *receivedLen = 1;
        if( 1 ==  LL_TIM_IsActiveFlag_CC1OVR(TimerPtr->PeripheralPtr))
        {
            LL_TIM_ClearFlag_CC1OVR(TimerPtr->PeripheralPtr);
            status = MW_TIM_OVERRUN_ERROR;
        }
    }
    return status;
}
/* Read capture comapre register 2  in polling mode */
uint8_T getCCR2RegisterValuePollingMode(TIM_Type_T * TimerPtr, void *data, uint32_T *receivedLen)
{
    uint8_T status = MW_TIM_SUCCESS;
    if(0 ==  TIM_IsActiveFlag_CC2(TimerPtr))
    {
        *receivedLen = 0;
    }
    else
    {
        if(IS_TIM_32B_COUNTER_INSTANCE(TimerPtr->PeripheralPtr))
        {
            *(uint32_T *)data = LL_TIM_IC_GetCaptureCH2(TimerPtr->PeripheralPtr);
        }
        else
        {
            *(uint16_T *)data = LL_TIM_IC_GetCaptureCH2(TimerPtr->PeripheralPtr);
        }
        LL_TIM_ClearFlag_CC2(TimerPtr->PeripheralPtr);
        TimerPtr->cc2Flag = 0;
        *receivedLen = 1;
        if( 1 ==  LL_TIM_IsActiveFlag_CC2OVR(TimerPtr->PeripheralPtr))
        {
            LL_TIM_ClearFlag_CC2OVR(TimerPtr->PeripheralPtr);
            status = MW_TIM_OVERRUN_ERROR;
        }
    }
    return status;
}
/* Read capture comapre register 3  in polling mode */
uint8_T getCCR3RegisterValuePollingMode(TIM_Type_T * TimerPtr, void *data, uint32_T *receivedLen)
{
    uint8_T status = MW_TIM_SUCCESS;
    if(0 ==  TIM_IsActiveFlag_CC3(TimerPtr))
    {
        *receivedLen = 0;
    }
    else
    {
        if(IS_TIM_32B_COUNTER_INSTANCE(TimerPtr->PeripheralPtr))
        {
            *(uint32_T *)data = LL_TIM_IC_GetCaptureCH3(TimerPtr->PeripheralPtr);
        }
        else
        {
            *(uint16_T *)data = LL_TIM_IC_GetCaptureCH3(TimerPtr->PeripheralPtr);
        }
        LL_TIM_ClearFlag_CC3(TimerPtr->PeripheralPtr);
        TimerPtr->cc3Flag = 0;
        *receivedLen = 1;
        if( 1 ==  LL_TIM_IsActiveFlag_CC3OVR(TimerPtr->PeripheralPtr))
        {
            LL_TIM_ClearFlag_CC3OVR(TimerPtr->PeripheralPtr);
            status = MW_TIM_OVERRUN_ERROR;
        }
    }
    return status;
}
/* Read capture comapre register 4  in polling mode */
uint8_T getCCR4RegisterValuePollingMode(TIM_Type_T * TimerPtr, void *data, uint32_T *receivedLen)
{
    uint8_T status = MW_TIM_SUCCESS;
    if(0 ==  TIM_IsActiveFlag_CC4(TimerPtr))
    {
        *receivedLen = 0;
    }
    else
    {
        if(IS_TIM_32B_COUNTER_INSTANCE(TimerPtr->PeripheralPtr))
        {
            *(uint32_T *)data = LL_TIM_IC_GetCaptureCH4(TimerPtr->PeripheralPtr);
        }
        else
        {
            *(uint16_T *)data = LL_TIM_IC_GetCaptureCH4(TimerPtr->PeripheralPtr);
        }
        LL_TIM_ClearFlag_CC4(TimerPtr->PeripheralPtr);
        TimerPtr->cc4Flag = 0;
        *receivedLen = 1;
        if( 1 ==  LL_TIM_IsActiveFlag_CC4OVR(TimerPtr->PeripheralPtr))
        {
            LL_TIM_ClearFlag_CC4OVR(TimerPtr->PeripheralPtr);
            status = MW_TIM_OVERRUN_ERROR;
        }
    }
    return status;
}

/******************************************************************************
*  Internal functions to get counter value
*******************************************************************************/

/*Get Timer counter value */
uint32_T getTimerCounterValue(TIM_Type_T * TimerPtr)
{
    return LL_TIM_GetCounter(TimerPtr->PeripheralPtr);
}

#if  defined(STM32G4)
/* Get counter value for G4 */
uint32_T getTimerCounterValueForG4(TIM_Type_T * TimerPtr, boolean_T enableCountAfterFirstIndex, boolean_T * validIndex)
{
    if ((enableCountAfterFirstIndex == 1) || (validIndex != NULL))
    {
        static boolean_T firstIndexReceived = 0;
        if(firstIndexReceived == 0)
        {
            if (0 == TIM_IsActiveFlagIDX(TimerPtr) )
            {
                if(enableCountAfterFirstIndex == 1)
                {
                    return 0;
                }
            }
            else
            {
                if(validIndex != NULL)
                {
                    *validIndex = 1;
                }
                firstIndexReceived = 1;
            }
        }
    }
    return LL_TIM_GetCounter(TimerPtr->PeripheralPtr);
}


/******************************************************************************
* Internal functions to get encoder read status for G4
*******************************************************************************/
/*Get encoder read status for G4 */
uint8_T ouputEncoderReadStatus(TIM_Type_T * TimerPtr)
{
    uint8_T status = ENCODER_NO_ERROR;
    if ( ENCODER_TRANSITION_ERROR == TIM_IsActiveFlagTERR(TimerPtr) )
    {
        status = status | ENCODER_TRANSITION_ERROR;
        LL_TIM_ClearFlag_TERR(TimerPtr->PeripheralPtr);
    }
    if ( ENCODER_INDEX_ERROR == TIM_IsActiveFlagIERR(TimerPtr))
    {
        status = status | ENCODER_INDEX_ERROR;
        LL_TIM_ClearFlag_IERR(TimerPtr->PeripheralPtr);
    }
    TimerPtr->errorStatus = ENCODER_NO_ERROR ;
    return status;
}

#endif
