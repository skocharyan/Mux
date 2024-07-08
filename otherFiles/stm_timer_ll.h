/* Copyright 2021-2022 The MathWorks, Inc. */
#ifndef __STM_PWMOUTPUT_LL_H__
#define __STM_PWMOUTPUT_LL_H__
/******************************************************************************
* Includes
*******************************************************************************/
#include "mw_stm32_types.h"
#include "main.h"

/* Get DMA buffer for timer channels */
/*Get buffers for TIM1 */
#ifdef MW_TIM1_CH1_DMA_ENABLED
#ifdef STM32H7
    #if defined(MW_DCACHE_ENABLED)
    extern uint16_T TIM1CH1DMABuffer[DMA_BUFFER_SIZE_BYTE_ALLIGNED(MW_TIM1_CH1_DMA_BUFFER_SIZE,32)];
    #else
    extern uint16_T TIM1CH1DMABuffer[MW_TIM1_CH1_DMA_BUFFER_SIZE] ;
    #endif
#elif defined(STM32F7) && defined(MW_DCACHE_ENABLED)
    extern uint16_T TIM1CH1DMABuffer[DMA_BUFFER_SIZE_BYTE_ALLIGNED(MW_TIM1_CH1_DMA_BUFFER_SIZE,32)];
#endif
#define GET_TIM1_CH1_DMA_BUFFER() &TIM1CH1DMABuffer[0]
#endif

#ifdef MW_TIM1_CH2_DMA_ENABLED
#ifdef STM32H7
    #if defined(MW_DCACHE_ENABLED)
    extern uint16_T TIM1CH2DMABuffer[DMA_BUFFER_SIZE_BYTE_ALLIGNED(MW_TIM1_CH2_DMA_BUFFER_SIZE,32)];
    #else
    extern uint16_T TIM1CH2DMABuffer[MW_TIM1_CH2_DMA_BUFFER_SIZE] ;
    #endif
#elif defined(STM32F7) && defined(MW_DCACHE_ENABLED)
    extern uint16_T TIM1CH2DMABuffer[DMA_BUFFER_SIZE_BYTE_ALLIGNED(MW_TIM1_CH2_DMA_BUFFER_SIZE,32)];
#endif
#define GET_TIM1_CH2_DMA_BUFFER() &TIM1CH2DMABuffer[0]
#endif

#ifdef MW_TIM1_CH3_DMA_ENABLED
#ifdef STM32H7
    #if defined(MW_DCACHE_ENABLED)
    extern uint16_T TIM1CH3DMABuffer[DMA_BUFFER_SIZE_BYTE_ALLIGNED(MW_TIM1_CH3_DMA_BUFFER_SIZE,32)];
    #else
    extern uint16_T TIM1CH3DMABuffer[MW_TIM1_CH3_DMA_BUFFER_SIZE] ;
    #endif
#elif defined(STM32F7) && defined(MW_DCACHE_ENABLED)
    extern uint16_T TIM1CH3DMABuffer[DMA_BUFFER_SIZE_BYTE_ALLIGNED(MW_TIM1_CH3_DMA_BUFFER_SIZE,32)];
#endif
#define GET_TIM1_CH3_DMA_BUFFER() &TIM1CH3DMABuffer[0]
#endif

#ifdef MW_TIM1_CH4_DMA_ENABLED
#ifdef STM32H7
    #if defined(MW_DCACHE_ENABLED)
    extern uint16_T TIM1CH4DMABuffer[DMA_BUFFER_SIZE_BYTE_ALLIGNED(MW_TIM1_CH4_DMA_BUFFER_SIZE,32)];
    #else
    extern uint16_T TIM1CH4DMABuffer[MW_TIM1_CH4_DMA_BUFFER_SIZE] ;
    #endif
#elif defined(STM32F7) && defined(MW_DCACHE_ENABLED)
    extern uint16_T TIM1CH4DMABuffer[DMA_BUFFER_SIZE_BYTE_ALLIGNED(MW_TIM1_CH4_DMA_BUFFER_SIZE,32)];
#endif
#define GET_TIM1_CH4_DMA_BUFFER() &TIM1CH4DMABuffer[0]
#endif

/* Get buffers for TIM2 */
#ifdef MW_TIM2_CH1_DMA_ENABLED
#ifdef STM32H7
    #if defined(MW_DCACHE_ENABLED)
    extern uint32_T TIM2CH1DMABuffer[DMA_BUFFER_SIZE_BYTE_ALLIGNED(MW_TIM2_CH1_DMA_BUFFER_SIZE,32)];
    #else
    extern uint32_T TIM2CH1DMABuffer[MW_TIM2_CH1_DMA_BUFFER_SIZE] ;
    #endif
#elif defined(STM32F7) && defined(MW_DCACHE_ENABLED)
    extern uint32_T TIM2CH1DMABuffer[DMA_BUFFER_SIZE_BYTE_ALLIGNED(MW_TIM2_CH1_DMA_BUFFER_SIZE,32)];
#endif
#define GET_TIM2_CH1_DMA_BUFFER() &TIM2CH1DMABuffer[0]
#endif

#ifdef MW_TIM2_CH2_DMA_ENABLED
#ifdef STM32H7
    #if defined(MW_DCACHE_ENABLED)
    extern uint32_T TIM2CH2DMABuffer[DMA_BUFFER_SIZE_BYTE_ALLIGNED(MW_TIM2_CH2_DMA_BUFFER_SIZE,32)];
    #else
    extern uint32_T TIM2CH2DMABuffer[MW_TIM2_CH2_DMA_BUFFER_SIZE] ;
    #endif
#elif defined(STM32F7) && defined(MW_DCACHE_ENABLED)
    extern uint32_T TIM2CH2DMABuffer[DMA_BUFFER_SIZE_BYTE_ALLIGNED(MW_TIM2_CH2_DMA_BUFFER_SIZE,32)];
#endif
#define GET_TIM2_CH2_DMA_BUFFER() &TIM2CH2DMABuffer[0]
#endif

#ifdef MW_TIM2_CH3_DMA_ENABLED
#ifdef STM32H7
    #if defined(MW_DCACHE_ENABLED)
    extern uint32_T TIM2CH3DMABuffer[DMA_BUFFER_SIZE_BYTE_ALLIGNED(MW_TIM2_CH3_DMA_BUFFER_SIZE,32)];
    #else
    extern uint32_T TIM2CH3DMABuffer[MW_TIM2_CH3_DMA_BUFFER_SIZE] ;
    #endif
#elif defined(STM32F7) && defined(MW_DCACHE_ENABLED)
    extern uint32_T TIM2CH3DMABuffer[DMA_BUFFER_SIZE_BYTE_ALLIGNED(MW_TIM2_CH3_DMA_BUFFER_SIZE,32)];
#endif
#define GET_TIM2_CH3_DMA_BUFFER() &TIM2CH3DMABuffer[0]
#endif

#ifdef MW_TIM2_CH4_DMA_ENABLED
#ifdef STM32H7
    #if defined(MW_DCACHE_ENABLED)
    extern uint32_T TIM2CH4DMABuffer[DMA_BUFFER_SIZE_BYTE_ALLIGNED(MW_TIM2_CH4_DMA_BUFFER_SIZE,32)];
    #else
    extern uint32_T TIM2CH4DMABuffer[MW_TIM2_CH4_DMA_BUFFER_SIZE] ;
    #endif
#elif defined(STM32F7) && defined(MW_DCACHE_ENABLED)
    extern uint32_T TIM2CH4DMABuffer[DMA_BUFFER_SIZE_BYTE_ALLIGNED(MW_TIM2_CH4_DMA_BUFFER_SIZE,32)];
#endif
#define GET_TIM2_CH4_DMA_BUFFER() &TIM2CH4DMABuffer[0]
#endif

/* Get buffers for TIM3 */
#ifdef MW_TIM3_CH1_DMA_ENABLED
#ifdef STM32H7
    #if defined(MW_DCACHE_ENABLED)
    extern uint16_T TIM3CH1DMABuffer[DMA_BUFFER_SIZE_BYTE_ALLIGNED(MW_TIM3_CH1_DMA_BUFFER_SIZE,32)];
    #else
    extern uint16_T TIM3CH1DMABuffer[MW_TIM3_CH1_DMA_BUFFER_SIZE] ;
    #endif
#elif defined(STM32F7) && defined(MW_DCACHE_ENABLED)
    extern uint16_T TIM3CH1DMABuffer[DMA_BUFFER_SIZE_BYTE_ALLIGNED(MW_TIM3_CH1_DMA_BUFFER_SIZE,32)];
#endif
#define GET_TIM3_CH1_DMA_BUFFER() &TIM3CH1DMABuffer[0]
#endif

#ifdef MW_TIM3_CH2_DMA_ENABLED
#ifdef STM32H7
    #if defined(MW_DCACHE_ENABLED)
    extern uint16_T TIM3CH2DMABuffer[DMA_BUFFER_SIZE_BYTE_ALLIGNED(MW_TIM3_CH2_DMA_BUFFER_SIZE,32)];
    #else
    extern uint16_T TIM3CH2DMABuffer[MW_TIM3_CH2_DMA_BUFFER_SIZE] ;
    #endif
#elif defined(STM32F7) && defined(MW_DCACHE_ENABLED)
    extern uint16_T TIM3CH2DMABuffer[DMA_BUFFER_SIZE_BYTE_ALLIGNED(MW_TIM3_CH2_DMA_BUFFER_SIZE,32)];
#endif
#define GET_TIM3_CH2_DMA_BUFFER() &TIM3CH2DMABuffer[0]
#endif

#ifdef MW_TIM3_CH3_DMA_ENABLED
#ifdef STM32H7
    #if defined(MW_DCACHE_ENABLED)
    extern uint16_T TIM3CH3DMABuffer[DMA_BUFFER_SIZE_BYTE_ALLIGNED(MW_TIM3_CH3_DMA_BUFFER_SIZE,32)];
    #else
    extern uint16_T TIM3CH3DMABuffer[MW_TIM3_CH3_DMA_BUFFER_SIZE] ;
    #endif
#elif defined(STM32F7) && defined(MW_DCACHE_ENABLED)
    extern uint16_T TIM3CH3DMABuffer[DMA_BUFFER_SIZE_BYTE_ALLIGNED(MW_TIM3_CH3_DMA_BUFFER_SIZE,32)];
#endif
#define GET_TIM3_CH3_DMA_BUFFER() &TIM3CH3DMABuffer[0]
#endif

#ifdef MW_TIM3_CH4_DMA_ENABLED
#ifdef STM32H7
    #if defined(MW_DCACHE_ENABLED)
    extern uint16_T TIM3CH4DMABuffer[DMA_BUFFER_SIZE_BYTE_ALLIGNED(MW_TIM3_CH4_DMA_BUFFER_SIZE,32)];
    #else
    extern uint16_T TIM3CH4DMABuffer[MW_TIM3_CH4_DMA_BUFFER_SIZE] ;
    #endif
#elif defined(STM32F7) && defined(MW_DCACHE_ENABLED)
    extern uint16_T TIM3CH4DMABuffer[DMA_BUFFER_SIZE_BYTE_ALLIGNED(MW_TIM3_CH4_DMA_BUFFER_SIZE,32)];
#endif
#define GET_TIM3_CH4_DMA_BUFFER() &TIM3CH4DMABuffer[0]
#endif

/* Get buffers for TIM4 */
#ifdef MW_TIM4_CH1_DMA_ENABLED
#ifdef STM32H7
    #if defined(MW_DCACHE_ENABLED)
    extern uint16_T TIM4CH1DMABuffer[DMA_BUFFER_SIZE_BYTE_ALLIGNED(MW_TIM4_CH1_DMA_BUFFER_SIZE,32)];
    #else
    extern uint16_T TIM4CH1DMABuffer[MW_TIM4_CH1_DMA_BUFFER_SIZE] ;
    #endif
#elif defined(STM32F7) && defined(MW_DCACHE_ENABLED)
    extern uint16_T TIM4CH1DMABuffer[DMA_BUFFER_SIZE_BYTE_ALLIGNED(MW_TIM4_CH1_DMA_BUFFER_SIZE,32)];
#endif
#define GET_TIM4_CH1_DMA_BUFFER() &TIM4CH1DMABuffer[0]
#endif

#ifdef MW_TIM4_CH2_DMA_ENABLED
#ifdef STM32H7
    #if defined(MW_DCACHE_ENABLED)
    extern uint16_T TIM4CH2DMABuffer[DMA_BUFFER_SIZE_BYTE_ALLIGNED(MW_TIM4_CH2_DMA_BUFFER_SIZE,32)];
    #else
    extern uint16_T TIM4CH2DMABuffer[MW_TIM4_CH2_DMA_BUFFER_SIZE] ;
    #endif
#elif defined(STM32F7) && defined(MW_DCACHE_ENABLED)
    extern uint16_T TIM4CH2DMABuffer[DMA_BUFFER_SIZE_BYTE_ALLIGNED(MW_TIM4_CH2_DMA_BUFFER_SIZE,32)];
#endif
#define GET_TIM4_CH2_DMA_BUFFER() &TIM4CH2DMABuffer[0]
#endif

#ifdef MW_TIM4_CH3_DMA_ENABLED
#ifdef STM32H7
    #if defined(MW_DCACHE_ENABLED)
    extern uint16_T TIM4CH3DMABuffer[DMA_BUFFER_SIZE_BYTE_ALLIGNED(MW_TIM4_CH3_DMA_BUFFER_SIZE,32)];
    #else
    extern uint16_T TIM4CH3DMABuffer[MW_TIM4_CH3_DMA_BUFFER_SIZE] ;
    #endif
#elif defined(STM32F7) && defined(MW_DCACHE_ENABLED)
    extern uint16_T TIM4CH3DMABuffer[DMA_BUFFER_SIZE_BYTE_ALLIGNED(MW_TIM4_CH3_DMA_BUFFER_SIZE,32)];
#endif
#define GET_TIM4_CH3_DMA_BUFFER() &TIM4CH3DMABuffer[0]
#endif

#ifdef MW_TIM4_CH4_DMA_ENABLED
#ifdef STM32H7
    #if defined(MW_DCACHE_ENABLED)
    extern uint16_T TIM4CH4DMABuffer[DMA_BUFFER_SIZE_BYTE_ALLIGNED(MW_TIM4_CH4_DMA_BUFFER_SIZE,32)];
    #else
    extern uint16_T TIM4CH4DMABuffer[MW_TIM4_CH4_DMA_BUFFER_SIZE] ;
    #endif
#elif defined(STM32F7) && defined(MW_DCACHE_ENABLED)
    extern uint16_T TIM4CH4DMABuffer[DMA_BUFFER_SIZE_BYTE_ALLIGNED(MW_TIM4_CH4_DMA_BUFFER_SIZE,32)];
#endif
#define GET_TIM4_CH4_DMA_BUFFER() &TIM4CH4DMABuffer[0]
#endif

/* Get buffers for TIM5 */
#ifdef MW_TIM5_CH1_DMA_ENABLED
#ifdef STM32H7
    #if defined(MW_DCACHE_ENABLED)
    extern uint32_T TIM5CH1DMABuffer[DMA_BUFFER_SIZE_BYTE_ALLIGNED(MW_TIM5_CH1_DMA_BUFFER_SIZE,32)];
    #else
    extern uint32_T TIM5CH1DMABuffer[MW_TIM5_CH1_DMA_BUFFER_SIZE] ;
    #endif
#elif defined(STM32F7) && defined(MW_DCACHE_ENABLED)
    extern uint32_T TIM5CH1DMABuffer[DMA_BUFFER_SIZE_BYTE_ALLIGNED(MW_TIM5_CH1_DMA_BUFFER_SIZE,32)];
#endif
#define GET_TIM5_CH1_DMA_BUFFER() &TIM5CH1DMABuffer[0]
#endif

#ifdef MW_TIM5_CH2_DMA_ENABLED
#ifdef STM32H7
    #if defined(MW_DCACHE_ENABLED)
    extern uint32_T TIM5CH2DMABuffer[DMA_BUFFER_SIZE_BYTE_ALLIGNED(MW_TIM5_CH2_DMA_BUFFER_SIZE,32)];
    #else
    extern uint32_T TIM5CH2DMABuffer[MW_TIM5_CH2_DMA_BUFFER_SIZE] ;
    #endif
#elif defined(STM32F7) && defined(MW_DCACHE_ENABLED)
    extern uint32_T TIM5CH2DMABuffer[DMA_BUFFER_SIZE_BYTE_ALLIGNED(MW_TIM5_CH2_DMA_BUFFER_SIZE,32)];
#endif
#define GET_TIM5_CH2_DMA_BUFFER() &TIM5CH2DMABuffer[0]
#endif

#ifdef MW_TIM5_CH3_DMA_ENABLED
#ifdef STM32H7
    #if defined(MW_DCACHE_ENABLED)
    extern uint32_T TIM5CH3DMABuffer[DMA_BUFFER_SIZE_BYTE_ALLIGNED(MW_TIM5_CH3_DMA_BUFFER_SIZE,32)];
    #else
    extern uint32_T TIM5CH3DMABuffer[MW_TIM5_CH3_DMA_BUFFER_SIZE] ;
    #endif
#elif defined(STM32F7) && defined(MW_DCACHE_ENABLED)
    extern uint32_T TIM5CH3DMABuffer[DMA_BUFFER_SIZE_BYTE_ALLIGNED(MW_TIM5_CH3_DMA_BUFFER_SIZE,32)];
#endif
#define GET_TIM5_CH3_DMA_BUFFER() &TIM5CH3DMABuffer[0]
#endif

#ifdef MW_TIM5_CH4_DMA_ENABLED
#ifdef STM32H7
    #if defined(MW_DCACHE_ENABLED)
    extern uint32_T TIM5CH4DMABuffer[DMA_BUFFER_SIZE_BYTE_ALLIGNED(MW_TIM5_CH4_DMA_BUFFER_SIZE,32)];
    #else
    extern uint32_T TIM5CH4DMABuffer[MW_TIM5_CH4_DMA_BUFFER_SIZE] ;
    #endif
#elif defined(STM32F7) && defined(MW_DCACHE_ENABLED)
    extern uint32_T TIM5CH4DMABuffer[DMA_BUFFER_SIZE_BYTE_ALLIGNED(MW_TIM5_CH4_DMA_BUFFER_SIZE,32)];
#endif
#define GET_TIM5_CH4_DMA_BUFFER() &TIM5CH4DMABuffer[0]
#endif

/* Get buffers for TIM8 */
#ifdef MW_TIM8_CH1_DMA_ENABLED
#ifdef STM32H7
    #if defined(MW_DCACHE_ENABLED)
    extern uint16_T TIM8CH1DMABuffer[DMA_BUFFER_SIZE_BYTE_ALLIGNED(MW_TIM8_CH1_DMA_BUFFER_SIZE,32)];
    #else
    extern uint16_T TIM8CH1DMABuffer[MW_TIM8_CH1_DMA_BUFFER_SIZE] ;
    #endif
#elif defined(STM32F7) && defined(MW_DCACHE_ENABLED)
    extern uint16_T TIM8CH1DMABuffer[DMA_BUFFER_SIZE_BYTE_ALLIGNED(MW_TIM8_CH1_DMA_BUFFER_SIZE,32)];
#endif
#define GET_TIM8_CH1_DMA_BUFFER() &TIM8CH1DMABuffer[0]
#endif

#ifdef MW_TIM8_CH2_DMA_ENABLED
#ifdef STM32H7
    #if defined(MW_DCACHE_ENABLED)
    extern uint16_T TIM8CH2DMABuffer[DMA_BUFFER_SIZE_BYTE_ALLIGNED(MW_TIM8_CH2_DMA_BUFFER_SIZE,32)];
    #else
    extern uint16_T TIM8CH2DMABuffer[MW_TIM8_CH2_DMA_BUFFER_SIZE] ;
    #endif
#elif defined(STM32F7) && defined(MW_DCACHE_ENABLED)
    extern uint16_T TIM8CH2DMABuffer[DMA_BUFFER_SIZE_BYTE_ALLIGNED(MW_TIM8_CH2_DMA_BUFFER_SIZE,32)];
#endif
#define GET_TIM8_CH2_DMA_BUFFER() &TIM8CH2DMABuffer[0]
#endif

#ifdef MW_TIM8_CH3_DMA_ENABLED
#ifdef STM32H7
    #if defined(MW_DCACHE_ENABLED)
    extern uint16_T TIM8CH3DMABuffer[DMA_BUFFER_SIZE_BYTE_ALLIGNED(MW_TIM8_CH3_DMA_BUFFER_SIZE,32)];
    #else
    extern uint16_T TIM8CH3DMABuffer[MW_TIM8_CH3_DMA_BUFFER_SIZE] ;
    #endif
#elif defined(STM32F7) && defined(MW_DCACHE_ENABLED)
    extern uint16_T TIM8CH3DMABuffer[DMA_BUFFER_SIZE_BYTE_ALLIGNED(MW_TIM8_CH3_DMA_BUFFER_SIZE,32)];
#endif
#define GET_TIM8_CH3_DMA_BUFFER() &TIM8CH3DMABuffer[0]
#endif

#ifdef MW_TIM8_CH4_DMA_ENABLED
#ifdef STM32H7
    #if defined(MW_DCACHE_ENABLED)
    extern uint16_T TIM8CH4DMABuffer[DMA_BUFFER_SIZE_BYTE_ALLIGNED(MW_TIM8_CH4_DMA_BUFFER_SIZE,32)];
    #else
    extern uint16_T TIM8CH4DMABuffer[MW_TIM8_CH4_DMA_BUFFER_SIZE] ;
    #endif
#elif defined(STM32F7) && defined(MW_DCACHE_ENABLED)
    extern uint16_T TIM8CH4DMABuffer[DMA_BUFFER_SIZE_BYTE_ALLIGNED(MW_TIM8_CH4_DMA_BUFFER_SIZE,32)];
#endif
#define GET_TIM8_CH4_DMA_BUFFER() &TIM8CH4DMABuffer[0]
#endif

/* Get buffers for TIM9 */
#ifdef MW_TIM9_CH1_DMA_ENABLED
#ifdef STM32H7
    #if defined(MW_DCACHE_ENABLED)
    extern uint16_T TIM9CH1DMABuffer[DMA_BUFFER_SIZE_BYTE_ALLIGNED(MW_TIM9_CH1_DMA_BUFFER_SIZE,32)];
    #else
    extern uint16_T TIM9CH1DMABuffer[MW_TIM9_CH1_DMA_BUFFER_SIZE] ;
    #endif
#elif defined(STM32F7) && defined(MW_DCACHE_ENABLED)
    extern uint16_T TIM9CH1DMABuffer[DMA_BUFFER_SIZE_BYTE_ALLIGNED(MW_TIM9_CH1_DMA_BUFFER_SIZE,32)];
#endif
#define GET_TIM9_CH1_DMA_BUFFER() &TIM9CH1DMABuffer[0]
#endif

#ifdef MW_TIM9_CH2_DMA_ENABLED
#ifdef STM32H7
    #if defined(MW_DCACHE_ENABLED)
    extern uint16_T TIM9CH2DMABuffer[DMA_BUFFER_SIZE_BYTE_ALLIGNED(MW_TIM9_CH2_DMA_BUFFER_SIZE,32)];
    #else
    extern uint16_T TIM9CH2DMABuffer[MW_TIM9_CH2_DMA_BUFFER_SIZE] ;
    #endif
#elif defined(STM32F7) && defined(MW_DCACHE_ENABLED)
    extern uint16_T TIM9CH2DMABuffer[DMA_BUFFER_SIZE_BYTE_ALLIGNED(MW_TIM9_CH2_DMA_BUFFER_SIZE,32)];
#endif
#define GET_TIM9_CH2_DMA_BUFFER() &TIM9CH2DMABuffer[0]
#endif

/* Get buffers for TIM10 */
#ifdef MW_TIM10_CH1_DMA_ENABLED
#ifdef STM32H7
    #if defined(MW_DCACHE_ENABLED)
    extern uint16_T TIM10CH1DMABuffer[DMA_BUFFER_SIZE_BYTE_ALLIGNED(MW_TIM10_CH1_DMA_BUFFER_SIZE,32)];
    #else
    extern uint16_T TIM10CH1DMABuffer[MW_TIM10_CH1_DMA_BUFFER_SIZE] ;
    #endif
#elif defined(STM32F7) && defined(MW_DCACHE_ENABLED)
    extern uint16_T TIM10CH1DMABuffer[DMA_BUFFER_SIZE_BYTE_ALLIGNED(MW_TIM10_CH1_DMA_BUFFER_SIZE,32)];
#endif
#define GET_TIM10_CH1_DMA_BUFFER() &TIM10CH1DMABuffer[0]
#endif

/* Get buffers for TIM11 */
#ifdef MW_TIM11_CH1_DMA_ENABLED
#ifdef STM32H7
    #if defined(MW_DCACHE_ENABLED)
    extern uint16_T TIM11CH1DMABuffer[DMA_BUFFER_SIZE_BYTE_ALLIGNED(MW_TIM11_CH1_DMA_BUFFER_SIZE,32)];
    #else
    extern uint16_T TIM11CH1DMABuffer[MW_TIM11_CH1_DMA_BUFFER_SIZE] ;
    #endif
#elif defined(STM32F7) && defined(MW_DCACHE_ENABLED)
    extern uint16_T TIM11CH1DMABuffer[DMA_BUFFER_SIZE_BYTE_ALLIGNED(MW_TIM11_CH1_DMA_BUFFER_SIZE,32)];
#endif
#define GET_TIM11_CH1_DMA_BUFFER() &TIM11CH1DMABuffer[0]
#endif

/* Get buffers for TIM12 */
#ifdef MW_TIM12_CH1_DMA_ENABLED
#ifdef STM32H7
    #if defined(MW_DCACHE_ENABLED)
    extern uint16_T TIM12CH1DMABuffer[DMA_BUFFER_SIZE_BYTE_ALLIGNED(MW_TIM12_CH1_DMA_BUFFER_SIZE,32)];
    #else
    extern uint16_T TIM12CH1DMABuffer[MW_TIM12_CH1_DMA_BUFFER_SIZE] ;
    #endif
#elif defined(STM32F7) && defined(MW_DCACHE_ENABLED)
    extern uint16_T TIM12CH1DMABuffer[DMA_BUFFER_SIZE_BYTE_ALLIGNED(MW_TIM12_CH1_DMA_BUFFER_SIZE,32)];
#endif
#define GET_TIM12_CH1_DMA_BUFFER() &TIM12CH1DMABuffer[0]
#endif

#ifdef MW_TIM12_CH2_DMA_ENABLED
#ifdef STM32H7
    #if defined(MW_DCACHE_ENABLED)
    extern uint16_T TIM12CH2DMABuffer[DMA_BUFFER_SIZE_BYTE_ALLIGNED(MW_TIM12_CH2_DMA_BUFFER_SIZE,32)];
    #else
    extern uint16_T TIM12CH2DMABuffer[MW_TIM12_CH2_DMA_BUFFER_SIZE] ;
    #endif
#elif defined(STM32F7) && defined(MW_DCACHE_ENABLED)
    extern uint16_T TIM12CH2DMABuffer[DMA_BUFFER_SIZE_BYTE_ALLIGNED(MW_TIM12_CH2_DMA_BUFFER_SIZE,32)];
#endif
#define GET_TIM12_CH2_DMA_BUFFER() &TIM12CH2DMABuffer[0]
#endif

/* Get buffers for TIM13 */
#ifdef MW_TIM13_CH1_DMA_ENABLED
#ifdef STM32H7
    #if defined(MW_DCACHE_ENABLED)
    extern uint16_T TIM13CH1DMABuffer[DMA_BUFFER_SIZE_BYTE_ALLIGNED(MW_TIM13_CH1_DMA_BUFFER_SIZE,32)];
    #else
    extern uint16_T TIM13CH1DMABuffer[MW_TIM13_CH1_DMA_BUFFER_SIZE] ;
    #endif
#elif defined(STM32F7) && defined(MW_DCACHE_ENABLED)
    extern uint16_T TIM13CH1DMABuffer[DMA_BUFFER_SIZE_BYTE_ALLIGNED(MW_TIM13_CH1_DMA_BUFFER_SIZE,32)];
#endif
#define GET_TIM13_CH1_DMA_BUFFER() &TIM13CH1DMABuffer[0]
#endif

/* Get buffers for TIM14 */
#ifdef MW_TIM14_CH1_DMA_ENABLED
#ifdef STM32H7
    #if defined(MW_DCACHE_ENABLED)
    extern uint16_T TIM14CH1DMABuffer[DMA_BUFFER_SIZE_BYTE_ALLIGNED(MW_TIM14_CH1_DMA_BUFFER_SIZE,32)];
    #else
    extern uint16_T TIM14CH1DMABuffer[MW_TIM14_CH1_DMA_BUFFER_SIZE] ;
    #endif
#elif defined(STM32F7) && defined(MW_DCACHE_ENABLED)
    extern uint16_T TIM14CH1DMABuffer[DMA_BUFFER_SIZE_BYTE_ALLIGNED(MW_TIM14_CH1_DMA_BUFFER_SIZE,32)];
#endif
#define GET_TIM14_CH1_DMA_BUFFER() &TIM14CH1DMABuffer[0]
#endif

/* Get buffers for TIM15 */
#ifdef MW_TIM15_CH1_DMA_ENABLED
#ifdef STM32H7
    #if defined(MW_DCACHE_ENABLED)
    extern uint16_T TIM15CH1DMABuffer[DMA_BUFFER_SIZE_BYTE_ALLIGNED(MW_TIM15_CH1_DMA_BUFFER_SIZE,32)];
    #else
    extern uint16_T TIM15CH1DMABuffer[MW_TIM15_CH1_DMA_BUFFER_SIZE] ;
    #endif
#elif defined(STM32F7) && defined(MW_DCACHE_ENABLED)
    extern uint16_T TIM15CH1DMABuffer[DMA_BUFFER_SIZE_BYTE_ALLIGNED(MW_TIM15_CH1_DMA_BUFFER_SIZE,32)];
#endif
#define GET_TIM15_CH1_DMA_BUFFER() &TIM15CH1DMABuffer[0]
#endif

#ifdef MW_TIM15_CH2_DMA_ENABLED
#ifdef STM32H7
    #if defined(MW_DCACHE_ENABLED)
    extern uint16_T TIM15CH2DMABuffer[DMA_BUFFER_SIZE_BYTE_ALLIGNED(MW_TIM15_CH2_DMA_BUFFER_SIZE,32)];
    #else
    extern uint16_T TIM15CH2DMABuffer[MW_TIM15_CH2_DMA_BUFFER_SIZE] ;
    #endif
#elif defined(STM32F7) && defined(MW_DCACHE_ENABLED)
    extern uint16_T TIM15CH2DMABuffer[DMA_BUFFER_SIZE_BYTE_ALLIGNED(MW_TIM15_CH2_DMA_BUFFER_SIZE,32)];
#endif
#define GET_TIM15_CH2_DMA_BUFFER() &TIM15CH2DMABuffer[0]
#endif

/* Get buffers for TIM16 */
#ifdef MW_TIM16_CH1_DMA_ENABLED
#ifdef STM32H7
    #if defined(MW_DCACHE_ENABLED)
    extern uint16_T TIM16CH1DMABuffer[DMA_BUFFER_SIZE_BYTE_ALLIGNED(MW_TIM16_CH1_DMA_BUFFER_SIZE,32)];
    #else
    extern uint16_T TIM16CH1DMABuffer[MW_TIM16_CH1_DMA_BUFFER_SIZE] ;
    #endif
#elif defined(STM32F7) && defined(MW_DCACHE_ENABLED)
    extern uint16_T TIM16CH1DMABuffer[DMA_BUFFER_SIZE_BYTE_ALLIGNED(MW_TIM16_CH1_DMA_BUFFER_SIZE,32)];
#endif
#define GET_TIM16_CH1_DMA_BUFFER() &TIM16CH1DMABuffer[0]
#endif

/* Get buffers for TIM17 */
#ifdef MW_TIM17_CH1_DMA_ENABLED
#ifdef STM32H7
    #if defined(MW_DCACHE_ENABLED)
    extern uint16_T TIM17CH1DMABuffer[DMA_BUFFER_SIZE_BYTE_ALLIGNED(MW_TIM17_CH1_DMA_BUFFER_SIZE,32)];
    #else
    extern uint16_T TIM17CH1DMABuffer[MW_TIM17_CH1_DMA_BUFFER_SIZE] ;
    #endif
#elif defined(STM32F7) && defined(MW_DCACHE_ENABLED)
    extern uint16_T TIM17CH1DMABuffer[DMA_BUFFER_SIZE_BYTE_ALLIGNED(MW_TIM17_CH1_DMA_BUFFER_SIZE,32)];
#endif
#define GET_TIM17_CH1_DMA_BUFFER() &TIM17CH1DMABuffer[0]
#endif

/* Get buffers for TIM23 */
#ifdef MW_TIM23_CH1_DMA_ENABLED
#ifdef STM32H7
    #if defined(MW_DCACHE_ENABLED)
    extern uint32_T TIM23CH1DMABuffer[DMA_BUFFER_SIZE_BYTE_ALLIGNED(MW_TIM23_CH1_DMA_BUFFER_SIZE,32)];
    #else
    extern uint32_T TIM23CH1DMABuffer[MW_TIM23_CH1_DMA_BUFFER_SIZE] ;
    #endif
#elif defined(STM32F7) && defined(MW_DCACHE_ENABLED)
    extern uint32_T TIM23CH1DMABuffer[DMA_BUFFER_SIZE_BYTE_ALLIGNED(MW_TIM23_CH1_DMA_BUFFER_SIZE,32)];
#endif
#define GET_TIM23_CH1_DMA_BUFFER() &TIM23CH1DMABuffer[0]
#endif

#ifdef MW_TIM23_CH2_DMA_ENABLED
#ifdef STM32H7
    #if defined(MW_DCACHE_ENABLED)
    extern uint32_T TIM23CH2DMABuffer[DMA_BUFFER_SIZE_BYTE_ALLIGNED(MW_TIM23_CH2_DMA_BUFFER_SIZE,32)];
    #else
    extern uint32_T TIM23CH2DMABuffer[MW_TIM23_CH2_DMA_BUFFER_SIZE] ;
    #endif
#elif defined(STM32F7) && defined(MW_DCACHE_ENABLED)
    extern uint32_T TIM23CH2DMABuffer[DMA_BUFFER_SIZE_BYTE_ALLIGNED(MW_TIM23_CH2_DMA_BUFFER_SIZE,32)];
#endif
#define GET_TIM23_CH2_DMA_BUFFER() &TIM23CH2DMABuffer[0]
#endif

#ifdef MW_TIM23_CH3_DMA_ENABLED
#ifdef STM32H7
    #if defined(MW_DCACHE_ENABLED)
    extern uint32_T TIM23CH3DMABuffer[DMA_BUFFER_SIZE_BYTE_ALLIGNED(MW_TIM23_CH3_DMA_BUFFER_SIZE,32)];
    #else
    extern uint32_T TIM23CH3DMABuffer[MW_TIM23_CH3_DMA_BUFFER_SIZE] ;
    #endif
#elif defined(STM32F7) && defined(MW_DCACHE_ENABLED)
    extern uint32_T TIM23CH3DMABuffer[DMA_BUFFER_SIZE_BYTE_ALLIGNED(MW_TIM23_CH3_DMA_BUFFER_SIZE,32)];
#endif
#define GET_TIM23_CH3_DMA_BUFFER() &TIM23CH3DMABuffer[0]
#endif

#ifdef MW_TIM23_CH4_DMA_ENABLED
#ifdef STM32H7
    #if defined(MW_DCACHE_ENABLED)
    extern uint32_T TIM23CH4DMABuffer[DMA_BUFFER_SIZE_BYTE_ALLIGNED(MW_TIM23_CH4_DMA_BUFFER_SIZE,32)];
    #else
    extern uint32_T TIM23CH4DMABuffer[MW_TIM23_CH4_DMA_BUFFER_SIZE] ;
    #endif
#elif defined(STM32F7) && defined(MW_DCACHE_ENABLED)
    extern uint32_T TIM23CH4DMABuffer[DMA_BUFFER_SIZE_BYTE_ALLIGNED(MW_TIM23_CH4_DMA_BUFFER_SIZE,32)];
#endif
#define GET_TIM23_CH4_DMA_BUFFER() &TIM23CH4DMABuffer[0]
#endif

/* Get buffers for TIM24 */
#ifdef MW_TIM24_CH1_DMA_ENABLED
#ifdef STM32H7
    #if defined(MW_DCACHE_ENABLED)
    extern uint32_T TIM24CH1DMABuffer[DMA_BUFFER_SIZE_BYTE_ALLIGNED(MW_TIM24_CH1_DMA_BUFFER_SIZE,32)];
    #else
    extern uint32_T TIM24CH1DMABuffer[MW_TIM24_CH1_DMA_BUFFER_SIZE] ;
    #endif
#elif defined(STM32F7) && defined(MW_DCACHE_ENABLED)
    extern uint32_T TIM24CH1DMABuffer[DMA_BUFFER_SIZE_BYTE_ALLIGNED(MW_TIM24_CH1_DMA_BUFFER_SIZE,32)];
#endif
#define GET_TIM24_CH1_DMA_BUFFER() &TIM24CH1DMABuffer[0]
#endif

#ifdef MW_TIM24_CH2_DMA_ENABLED
#ifdef STM32H7
    #if defined(MW_DCACHE_ENABLED)
    extern uint32_T TIM24CH2DMABuffer[DMA_BUFFER_SIZE_BYTE_ALLIGNED(MW_TIM24_CH2_DMA_BUFFER_SIZE,32)];
    #else
    extern uint32_T TIM24CH2DMABuffer[MW_TIM24_CH2_DMA_BUFFER_SIZE] ;
    #endif
#elif defined(STM32F7) && defined(MW_DCACHE_ENABLED)
    extern uint32_T TIM24CH2DMABuffer[DMA_BUFFER_SIZE_BYTE_ALLIGNED(MW_TIM24_CH2_DMA_BUFFER_SIZE,32)];
#endif
#define GET_TIM24_CH2_DMA_BUFFER() &TIM24CH2DMABuffer[0]
#endif

#ifdef MW_TIM24_CH3_DMA_ENABLED
#ifdef STM32H7
    #if defined(MW_DCACHE_ENABLED)
    extern uint32_T TIM24CH3DMABuffer[DMA_BUFFER_SIZE_BYTE_ALLIGNED(MW_TIM24_CH3_DMA_BUFFER_SIZE,32)];
    #else
    extern uint32_T TIM24CH3DMABuffer[MW_TIM24_CH3_DMA_BUFFER_SIZE] ;
    #endif
#elif defined(STM32F7) && defined(MW_DCACHE_ENABLED)
    extern uint32_T TIM24CH3DMABuffer[DMA_BUFFER_SIZE_BYTE_ALLIGNED(MW_TIM24_CH3_DMA_BUFFER_SIZE,32)];
#endif
#define GET_TIM24_CH3_DMA_BUFFER() &TIM24CH3DMABuffer[0]
#endif

#ifdef MW_TIM24_CH4_DMA_ENABLED
#ifdef STM32H7
    #if defined(MW_DCACHE_ENABLED)
    extern uint32_T TIM24CH4DMABuffer[DMA_BUFFER_SIZE_BYTE_ALLIGNED(MW_TIM24_CH4_DMA_BUFFER_SIZE,32)];
    #else
    extern uint32_T TIM24CH4DMABuffer[MW_TIM24_CH4_DMA_BUFFER_SIZE] ;
    #endif
#elif defined(STM32F7) && defined(MW_DCACHE_ENABLED)
    extern uint32_T TIM24CH4DMABuffer[DMA_BUFFER_SIZE_BYTE_ALLIGNED(MW_TIM24_CH4_DMA_BUFFER_SIZE,32)];
#endif
#define GET_TIM24_CH4_DMA_BUFFER() &TIM24CH4DMABuffer[0]
#endif

/******************************************************************************
* Typedefs
*******************************************************************************/
typedef enum _Timer_Channel_Mode_T {
    MODE_NOT_CONFIGURED   = 0x00,
    NO_INPUT_OUTPUT       = 0X01,
    ENABLE_CH             = 0x02,
    ENABLE_CHN            = 0x03,
    ENABLE_CH_CHN         = 0x04
} Timer_Channel_Mode_T;

typedef enum _MW_Timer_Capture_Status_Type {
    MW_TIM_SUCCESS         = 0,/*0x00*/
        MW_TIM_OVERRUN_ERROR   = 1<<0,/*0x01*/
} MW_Timer_Capture_Status_Type;

typedef enum _MW_Encoder_Error {
    ENCODER_NO_ERROR           = 0,/*0x00*/
        ENCODER_TRANSITION_ERROR   = 1<<0,/*0x01*/
        ENCODER_INDEX_ERROR        = 1<<1,/*0x02*/
} MW_Encoder_Error;

typedef struct _Timer_Circular_Buffer_T{
    uint16_T * bufferPtr16Bit;
    uint32_T * bufferPtr32Bit;
    uint32_T bufferSize;
    uint32_T readPos;
    boolean_T writeRollOver;
}Timer_Circular_Buffer_T;

typedef struct _Channel_DMA_T{
    void * dmaPeripheralPtr;
    uint8_T dmastream ;
    Timer_Circular_Buffer_T buffer ;
    MW_Timer_Capture_Status_Type errorStatus;
}Channel_DMA_T;

typedef struct _TIM_Type_T {
    void *PeripheralPtr;
    boolean_T isCenterAlignedMode ;
    uint8_T repetitionCounter ;
    #ifdef STM32G4
    uint8_T errorStatus;
    uint8_T firstIndexReceivedStatus;
    #endif
    Channel_DMA_T channel1;
    Channel_DMA_T channel2;
    Channel_DMA_T channel3;
    Channel_DMA_T channel4;
    boolean_T cc1Flag;
    boolean_T cc2Flag;
    boolean_T cc3Flag;
    boolean_T cc4Flag;
} TIM_Type_T;

/* Make timer handles accesible to HWI block */
#if defined(TIM1) && defined(MW_TIM1_ENABLED)
extern TIM_Type_T mw_tim1;
#endif
#if defined(TIM2) && defined(MW_TIM2_ENABLED)
extern TIM_Type_T mw_tim2;
#endif
#if defined(TIM3) && defined(MW_TIM3_ENABLED)
extern TIM_Type_T mw_tim3;
#endif
#if defined(TIM4) && defined(MW_TIM4_ENABLED)
extern TIM_Type_T mw_tim4;
#endif
#if defined(TIM5) && defined(MW_TIM5_ENABLED)
extern TIM_Type_T mw_tim5;
#endif
#if defined(TIM6) && defined(MW_TIM6_ENABLED)
extern TIM_Type_T mw_tim6;
#endif
#if defined(TIM7) && defined(MW_TIM7_ENABLED)
extern   TIM_Type_T mw_tim7;
#endif
#if defined(TIM8) && defined(MW_TIM8_ENABLED)
extern  TIM_Type_T mw_tim8;
#endif
#if defined(TIM9) && defined(MW_TIM9_ENABLED)
extern  TIM_Type_T mw_tim9;
#endif
#if defined(TIM10) && defined(MW_TIM10_ENABLED)
extern  TIM_Type_T mw_tim10;
#endif
#if defined(TIM11) && defined(MW_TIM11_ENABLED)
extern  TIM_Type_T mw_tim11;
#endif
#if defined(TIM12) && defined(MW_TIM12_ENABLED)
extern  TIM_Type_T mw_tim12;
#endif
#if defined(TIM13) && defined(MW_TIM13_ENABLED)
extern  TIM_Type_T mw_tim13;
#endif
#if defined(TIM14) && defined(MW_TIM14_ENABLED)
extern  TIM_Type_T mw_tim14;
#endif
#if defined(TIM15) && defined(MW_TIM15_ENABLED)
extern  TIM_Type_T mw_tim15;
#endif
#if defined(TIM16) && defined(MW_TIM16_ENABLED)
extern  TIM_Type_T mw_tim16;
#endif
#if defined(TIM17) && defined(MW_TIM17_ENABLED)
extern  TIM_Type_T mw_tim17;
#endif
#if defined(TIM18) && defined(MW_TIM18_ENABLED)
extern  TIM_Type_T mw_tim18;
#endif
#if defined(TIM19) && defined(MW_TIM19_ENABLED)
extern  TIM_Type_T mw_tim19;
#endif
#if defined(TIM20) && defined(MW_TIM20_ENABLED)
extern  TIM_Type_T mw_tim20;
#endif
#if defined(TIM23) && defined(MW_TIM23_ENABLED)
extern  TIM_Type_T mw_tim23;
#endif
#if defined(TIM24) && defined(MW_TIM24_ENABLED)
extern  TIM_Type_T mw_tim24;
#endif

/******************************************************************************
* Static Inline functions
*******************************************************************************/

/* Get the duty cycle value in counts */
__STATIC_INLINE uint32_T convertDutyCyclePercentageToCounts(TIM_Type_T * TimerPtr, float DutyCycle)
{
    if(DutyCycle < 0.0F)
    {
        DutyCycle = 0.0F;
    }
    else if (DutyCycle > 100.0F)
    {
        DutyCycle = 100.0F;
    }
    uint32_T ARRRegisterValue = LL_TIM_GetAutoReload(TimerPtr->PeripheralPtr);
    return ((((!TimerPtr->isCenterAlignedMode) + ARRRegisterValue) * DutyCycle)/100.0F);
}

/*Set the ARR register if Enable Frequency Input is set */
__STATIC_INLINE void setFrequencyAccToInput(TIM_Type_T * TimerPtr, uint32_T frequencyInput)
{
    if(LL_TIM_GetAutoReload(TimerPtr->PeripheralPtr) != frequencyInput)
    {
        LL_TIM_SetAutoReload(TimerPtr->PeripheralPtr , (uint32_T)frequencyInput);
    }
}

/* Set the duty cycle of channels - Duty cycle in counts */
__STATIC_INLINE void setDutyCycleChannel1(TIM_Type_T * TimerPtr, uint32_T ChannelDutyCycle)
{
    if(LL_TIM_OC_GetCompareCH1(TimerPtr->PeripheralPtr) != ChannelDutyCycle)
    {
        LL_TIM_OC_SetCompareCH1 (TimerPtr->PeripheralPtr, ChannelDutyCycle);
    }
}
__STATIC_INLINE void setDutyCycleChannel2(TIM_Type_T * TimerPtr, uint32_T ChannelDutyCycle)
{
    if(LL_TIM_OC_GetCompareCH2(TimerPtr->PeripheralPtr) != ChannelDutyCycle)
    {
        LL_TIM_OC_SetCompareCH2 (TimerPtr->PeripheralPtr, ChannelDutyCycle);
    }
}
__STATIC_INLINE void setDutyCycleChannel3(TIM_Type_T * TimerPtr, uint32_T ChannelDutyCycle)
{
    if(LL_TIM_OC_GetCompareCH3(TimerPtr->PeripheralPtr) != ChannelDutyCycle)
    {
        LL_TIM_OC_SetCompareCH3 (TimerPtr->PeripheralPtr, ChannelDutyCycle);
    }
}
__STATIC_INLINE void setDutyCycleChannel4(TIM_Type_T * TimerPtr, uint32_T ChannelDutyCycle)
{
    if(LL_TIM_OC_GetCompareCH4(TimerPtr->PeripheralPtr) != ChannelDutyCycle)
    {
        LL_TIM_OC_SetCompareCH4 (TimerPtr->PeripheralPtr, ChannelDutyCycle);
    }
}

#if defined(STM32F7) || defined(STM32G4) || defined(STM32H7) || defined(STM32WB)
__STATIC_INLINE void setDutyCycleChannel5(TIM_Type_T * TimerPtr, uint32_T ChannelDutyCycle)
{
    if(LL_TIM_OC_GetCompareCH5(TimerPtr->PeripheralPtr) != ChannelDutyCycle)
    {
        LL_TIM_OC_SetCompareCH5 (TimerPtr->PeripheralPtr, ChannelDutyCycle);
    }
}
__STATIC_INLINE void setDutyCycleChannel6(TIM_Type_T * TimerPtr, uint32_T ChannelDutyCycle)
{
    if(LL_TIM_OC_GetCompareCH6(TimerPtr->PeripheralPtr) != ChannelDutyCycle)
    {
        LL_TIM_OC_SetCompareCH6 (TimerPtr->PeripheralPtr, ChannelDutyCycle);
    }
}
#endif

/* Set the duty cycle of channels - Duty cycle in percentage */
__STATIC_INLINE void setDutyCycleInPercentageChannel1(TIM_Type_T * TimerPtr, float ChannelDutyCycle)
{
    uint32_T ChannelDutyCycleinCounts =  convertDutyCyclePercentageToCounts(TimerPtr, ChannelDutyCycle);
    setDutyCycleChannel1(TimerPtr, ChannelDutyCycleinCounts);
}
__STATIC_INLINE void setDutyCycleInPercentageChannel2(TIM_Type_T * TimerPtr, float ChannelDutyCycle)
{
    uint32_T ChannelDutyCycleinCounts =  convertDutyCyclePercentageToCounts(TimerPtr, ChannelDutyCycle);
    setDutyCycleChannel2(TimerPtr, ChannelDutyCycleinCounts);
}
__STATIC_INLINE void setDutyCycleInPercentageChannel3(TIM_Type_T * TimerPtr, float ChannelDutyCycle)
{
    uint32_T ChannelDutyCycleinCounts =  convertDutyCyclePercentageToCounts(TimerPtr, ChannelDutyCycle);
    setDutyCycleChannel3(TimerPtr, ChannelDutyCycleinCounts);
}
__STATIC_INLINE void setDutyCycleInPercentageChannel4(TIM_Type_T * TimerPtr, float ChannelDutyCycle)
{
    uint32_T ChannelDutyCycleinCounts =  convertDutyCyclePercentageToCounts(TimerPtr, ChannelDutyCycle);
    setDutyCycleChannel4(TimerPtr, ChannelDutyCycleinCounts);
}

#if defined(STM32F7) || defined(STM32G4) || defined(STM32H7) || defined(STM32WB)
__STATIC_INLINE void setDutyCycleInPercentageChannel5(TIM_Type_T * TimerPtr, float ChannelDutyCycle)
{
    uint32_T ChannelDutyCycleinCounts =  convertDutyCyclePercentageToCounts(TimerPtr, ChannelDutyCycle);
    setDutyCycleChannel5(TimerPtr, ChannelDutyCycleinCounts);
}
__STATIC_INLINE void setDutyCycleInPercentageChannel6(TIM_Type_T * TimerPtr, float ChannelDutyCycle)
{
    uint32_T ChannelDutyCycleinCounts =  convertDutyCyclePercentageToCounts(TimerPtr, ChannelDutyCycle);
    setDutyCycleChannel6(TimerPtr, ChannelDutyCycleinCounts);
}
#endif

/*Check if slave mode is trigger or combines trigger and reset */
__STATIC_INLINE boolean_T isSlaveTriggerModeEnabled(TIM_Type_T * ptrTimer)
{
    uint32_T slaveMode = ((TIM_TypeDef *)ptrTimer->PeripheralPtr)->SMCR & TIM_SMCR_SMS;
    #ifdef STM32F7
    return ( (slaveMode == LL_TIM_SLAVEMODE_TRIGGER) || (slaveMode == LL_TIM_SLAVEMODE_COMBINED_RESETTRIGGER) ) ;
    #else
    return (slaveMode == LL_TIM_SLAVEMODE_TRIGGER);
    #endif
}

/*Enable the counter of the selected Timer */
__STATIC_INLINE void enableCounter(TIM_Type_T * ptrTimer, boolean_T isSetRCAfterCEEnabled)
{
    uint32_T URSBit =  LL_TIM_GetUpdateSource(ptrTimer->PeripheralPtr);
    if(isSetRCAfterCEEnabled  && IS_TIM_REPETITION_COUNTER_INSTANCE(ptrTimer->PeripheralPtr))
    {
        LL_TIM_SetRepetitionCounter(ptrTimer->PeripheralPtr,0);
    }
    if(URSBit != LL_TIM_UPDATESOURCE_COUNTER)
    {
        LL_TIM_SetUpdateSource(ptrTimer->PeripheralPtr,LL_TIM_UPDATESOURCE_COUNTER);
        LL_TIM_GenerateEvent_UPDATE(ptrTimer->PeripheralPtr);
        LL_TIM_SetUpdateSource(ptrTimer->PeripheralPtr,URSBit);
    }
    else
    {
        LL_TIM_GenerateEvent_UPDATE(ptrTimer->PeripheralPtr);
    }
    LL_TIM_EnableCounter(ptrTimer->PeripheralPtr);
    if(isSetRCAfterCEEnabled  && IS_TIM_REPETITION_COUNTER_INSTANCE(ptrTimer->PeripheralPtr))
    {
        LL_TIM_SetRepetitionCounter(ptrTimer->PeripheralPtr,ptrTimer->repetitionCounter);
    }

}

/*Enable the counter if Enable Counter input is set */
__STATIC_INLINE void enableCounterAccToInput(TIM_Type_T * TimerPtr, boolean_T counterEnableInput, boolean_T isSetRCAfterCEEnabled)
{
    if(counterEnableInput == 1 && !(LL_TIM_IsEnabledCounter(TimerPtr->PeripheralPtr)))
    {
        enableCounter(TimerPtr,isSetRCAfterCEEnabled);
    }
    else if(counterEnableInput == 0 && LL_TIM_IsEnabledCounter(TimerPtr->PeripheralPtr))
    {
        LL_TIM_DisableCounter(TimerPtr -> PeripheralPtr);
    }
}

/*Output the direction of the counter */
__STATIC_INLINE boolean_T ouputDirectionOfCounter(TIM_Type_T * TimerPtr)
{
    return (LL_TIM_GetDirection(TimerPtr->PeripheralPtr) != LL_TIM_COUNTERDIRECTION_UP);
}

/* Output the status of MOE bit */
__STATIC_INLINE boolean_T ouputMOEBitStatus(TIM_Type_T * TimerPtr)
{
    if (IS_TIM_BREAK_INSTANCE(TimerPtr->PeripheralPtr))
    {
        return (LL_TIM_IsEnabledAllOutputs(TimerPtr->PeripheralPtr));
    }
    else
    {
        return 0;
    }
}

/*Generate Update Event if Enable Update Event Input is set */
__STATIC_INLINE void enableUpdateEventAccToInput(TIM_Type_T * TimerPtr, boolean_T UpdateEventEnableInput)
{
    if(UpdateEventEnableInput)
    {
        LL_TIM_GenerateEvent_UPDATE(TimerPtr->PeripheralPtr);
    }
}

/*Generate capture compare 1 Event if Enable capture compare 4 Input is set */
__STATIC_INLINE void enableCaptureCompare1EventAccToInput(TIM_Type_T * TimerPtr, boolean_T CaptureCompare1EventEnableInput)
{
    if(CaptureCompare1EventEnableInput)
    {
        LL_TIM_GenerateEvent_CC1(TimerPtr->PeripheralPtr);
    }

}

/*Generate capture compare 2 Event if Enable capture compare 4 Input is set */
__STATIC_INLINE void enableCaptureCompare2EventAccToInput(TIM_Type_T * TimerPtr, boolean_T CaptureCompare2EventEnableInput)
{
    if(CaptureCompare2EventEnableInput)
    {
        LL_TIM_GenerateEvent_CC2(TimerPtr->PeripheralPtr);
    }
}

/*Generate capture compare 3 Event if Enable capture compare 4 Input is set */
__STATIC_INLINE void enableCaptureCompare3EventAccToInput(TIM_Type_T * TimerPtr, boolean_T CaptureCompare3EventEnableInput)
{
    if(CaptureCompare3EventEnableInput)
    {
        LL_TIM_GenerateEvent_CC3(TimerPtr->PeripheralPtr);
    }
}

/*Generate capture compare 4 Event if Enable capture compare 4 Input is set */
__STATIC_INLINE void enableCaptureCompare4EventAccToInput(TIM_Type_T * TimerPtr, boolean_T CaptureCompare4EventEnableInput)
{
    if(CaptureCompare4EventEnableInput)
    {
        LL_TIM_GenerateEvent_CC4(TimerPtr->PeripheralPtr);
    }
}

/*Generate trigger Event if Enable Trigger Event Input is set */
__STATIC_INLINE void enableTriggerEventAccToInput(TIM_Type_T * TimerPtr, boolean_T TriggerEventEnableInput)
{
    if(TriggerEventEnableInput)
    {
        LL_TIM_GenerateEvent_TRIG(TimerPtr->PeripheralPtr);
    }
}

/*Generate trigger Event if Enable Trigger Event Input is set */
__STATIC_INLINE void enableCOMEventAccToInput(TIM_Type_T * TimerPtr, boolean_T COMEventEnableInput)
{
    if(COMEventEnableInput)
    {
        LL_TIM_GenerateEvent_COM(TimerPtr->PeripheralPtr);
    }
}

/*Disable the counter */
__STATIC_INLINE void disableCounter(TIM_Type_T * TimerPtr)
{
    LL_TIM_DisableCounter(TimerPtr -> PeripheralPtr);
}

/*Generate break Event if Enable Break Input is set */
__STATIC_INLINE void enableBreakEventAccToInput(TIM_Type_T * TimerPtr, boolean_T BreakEventEnableInput)
{
    if(BreakEventEnableInput)
    {
        LL_TIM_GenerateEvent_BRK(TimerPtr->PeripheralPtr);
    }
}

/*Generate break Event if Enable Break Input2 is set */
#if defined(STM32F7) || defined(STM32G4) || defined(STM32H7)  || defined(STM32WB)
__STATIC_INLINE void enableBreakEvent2AccToInput(TIM_Type_T * TimerPtr, boolean_T BreakEventEnableInput)
{
    if(BreakEventEnableInput)
    {
        LL_TIM_GenerateEvent_BRK2(TimerPtr->PeripheralPtr);
    }
}
#endif

/*Set the MOE bit if Enable MOE bit status is set */
__STATIC_INLINE void setMOEBitAccToInput(TIM_Type_T * TimerPtr, boolean_T MOEbitEnableInput)
{
    if ( (MOEbitEnableInput == 1) && IS_TIM_BREAK_INSTANCE(TimerPtr->PeripheralPtr) && !(LL_TIM_IsEnabledAllOutputs(TimerPtr->PeripheralPtr)))
    {
        LL_TIM_EnableAllOutputs(TimerPtr->PeripheralPtr);
    }
}

/*Reset counter */
__STATIC_INLINE void resetCounterAccToInput(TIM_Type_T * TimerPtr, boolean_T counterResetInput)
{
    if(counterResetInput == 1)
    {
        if (LL_TIM_COUNTERDIRECTION_UP == LL_TIM_GetDirection(TimerPtr->PeripheralPtr))
        {
            LL_TIM_SetCounter(TimerPtr->PeripheralPtr, 0);
        }
        else
        {
            uint32_T arrValue = LL_TIM_GetAutoReload(TimerPtr->PeripheralPtr);
            LL_TIM_SetCounter(TimerPtr->PeripheralPtr, arrValue);
        }
    }
}


/******************************************************************************
* Function declarations
*******************************************************************************/
/*Initialize timer handle */
TIM_Type_T * Timer_Handle_Init(TIM_Type_T * ptrTimer);

/*Enable Timer channels */
void enableTimerChannel1(TIM_Type_T * ptrTimer,  uint8_T PWMChannelInfo);
void enableTimerChannel2(TIM_Type_T * ptrTimer,  uint8_T PWMChannelInfo);
void enableTimerChannel3(TIM_Type_T * ptrTimer,  uint8_T PWMChannelInfo);
void enableTimerChannel4(TIM_Type_T * ptrTimer,  uint8_T PWMChannelInfo);

/*Disable Timer channels*/
void disableTimerChannel1(TIM_Type_T * ptrTimer,  uint8_T PWMChannelInfo);
void disableTimerChannel2(TIM_Type_T * ptrTimer,  uint8_T PWMChannelInfo);
void disableTimerChannel3(TIM_Type_T * ptrTimer,  uint8_T PWMChannelInfo);
void disableTimerChannel4(TIM_Type_T * ptrTimer,  uint8_T PWMChannelInfo);

/*Enable timer interrupts */
void enableTimerInterrupts(TIM_Type_T * ptrTimer, uint16_T interruptsToEnable);

/*Disable timer interrupts */
void disableTimerInterrupts(TIM_Type_T * ptrTimer, uint16_T interruptsToDisable);

/* Check frequency and duty cycle limits */
uint32_T checkFrequencyAndDutyCycleLimits(TIM_Type_T * ptrTimer, uint32_T input);

/* Get capture data in DMA mode */
uint8_T getCCR1RegisterValueDMAMode(TIM_Type_T * TimerPtr, void *data, uint32_T dataLength, uint32_T *receivedLength);
uint8_T getCCR2RegisterValueDMAMode(TIM_Type_T * TimerPtr, void *data, uint32_T dataLength, uint32_T *receivedLength);
uint8_T getCCR3RegisterValueDMAMode(TIM_Type_T * TimerPtr, void *data, uint32_T dataLength, uint32_T *receivedLength);
uint8_T getCCR4RegisterValueDMAMode(TIM_Type_T * TimerPtr, void *data, uint32_T dataLength, uint32_T *receivedLength);

/*Get capture data in Polling mode */
uint8_T getCCR1RegisterValuePollingMode(TIM_Type_T * TimerPtr, void *data, uint32_T *receivedLen);
uint8_T getCCR2RegisterValuePollingMode(TIM_Type_T * TimerPtr, void *data, uint32_T *receivedLen);
uint8_T getCCR3RegisterValuePollingMode(TIM_Type_T * TimerPtr, void *data, uint32_T *receivedLen);
uint8_T getCCR4RegisterValuePollingMode(TIM_Type_T * TimerPtr, void *data, uint32_T *receivedLen);
/*Configure DMA */
void configureDMAForChannel(TIM_Type_T * ptrTimer, Channel_DMA_T ptrTimChannel, uint8_T channel);

/*Read data from timer buffer */
uint32_T getAvailableDataInTimerBuffer(Channel_DMA_T * ptrTimChannel);
void getDataFrom16BitTimerBuffer(Channel_DMA_T * ptrTimChannel, uint16_T *dataPtr, uint32_T dataToRead);
void getDataFrom32BitTimerBuffer(Channel_DMA_T * ptrTimChannel, uint32_T *dataPtr, uint32_T dataToRead);
uint8_T readDataFromTimerBuffer(TIM_Type_T * TimerPtr, Channel_DMA_T * ptrTimChannel, void *dataPtr, uint32_T dataToRead, uint32_T *receivedLength);

#ifdef STM32G4
/*Get counter value for G4 processors */
uint32_T getTimerCounterValueForG4(TIM_Type_T * TimerPtr, boolean_T enableCountAfterFirstIndex, boolean_T * validindex);
uint8_T ouputEncoderReadStatus(TIM_Type_T * TimerPtr);
/*Check if TERR flag is active */
uint8_T TIM_IsActiveFlagTERR(TIM_Type_T * ptrTimer);
/*Check if IERR flag is active */
uint8_T TIM_IsActiveFlagIERR(TIM_Type_T * ptrTimer);
/*Check if IDX flag is active */
boolean_T TIM_IsActiveFlagIDX(TIM_Type_T * ptrTimer);
#endif

/*Get counter value */
uint32_T getTimerCounterValue(TIM_Type_T * TimerPtr);
/*Check if CC1 flag is active */
boolean_T TIM_IsActiveFlag_CC1(TIM_Type_T * ptrTimer);
/*Check if CC2 flag is active */
boolean_T TIM_IsActiveFlag_CC2(TIM_Type_T * ptrTimer);
/*Check if CC3 flag is active */
boolean_T TIM_IsActiveFlag_CC3(TIM_Type_T * ptrTimer);
/*Check if CC4 flag is active */
boolean_T TIM_IsActiveFlag_CC4(TIM_Type_T * ptrTimer);


#endif /* __STM_PWMOUTPUT_LL_H__ */
