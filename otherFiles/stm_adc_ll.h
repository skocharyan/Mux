/* Copyright 2021-2023 The MathWorks, Inc. */
#ifndef __STM_ADC_LL_H__
#define __STM_ADC_LL_H__
/******************************************************************************
* Includes
*******************************************************************************/
#include "main.h"
#include "mw_stm32_types.h"

/******************************************************************************
* Defines
*******************************************************************************/
#define MW_ADC_DATA_IN_DMA_FIRST_HALF_BUFFER        0x00U
#define MW_ADC_DATA_IN_DMA_SECOND_HALF_BUFFER       0x01U


#if defined(MW_ADC1_DMA_ENABLED)
    #ifdef STM32H7
        #if defined(MW_DCACHE_ENABLED)
            extern uint32_T ADC1DMABuffer[DMA_BUFFER_SIZE_BYTE_ALLIGNED(MW_ADC1_DMA_BUFFER_SIZE,32)] ;
        #else
            extern uint32_T ADC1DMABuffer[MW_ADC1_DMA_BUFFER_SIZE] ;
        #endif
    #elif defined(STM32F7) && defined(MW_DCACHE_ENABLED)
            extern uint16_T ADC1DMABuffer[DMA_BUFFER_SIZE_BYTE_ALLIGNED(MW_ADC1_DMA_BUFFER_SIZE,32)] ;
    #elif defined(STM32U5)
            extern uint32_T ADC1DMABuffer[MW_ADC1_DMA_BUFFER_SIZE];
    #endif
    #define GET_ADC1_DMA_BUFFER() &ADC1DMABuffer[0]
#endif

#if defined(MW_ADC2_DMA_ENABLED)
#ifdef STM32H7
    #if defined(MW_DCACHE_ENABLED)
    extern uint32_T ADC2DMABuffer[DMA_BUFFER_SIZE_BYTE_ALLIGNED(MW_ADC2_DMA_BUFFER_SIZE,32)] ;
    #else
    extern uint32_T ADC2DMABuffer[MW_ADC2_DMA_BUFFER_SIZE] ;
    #endif
#elif defined(STM32F7) && defined(MW_DCACHE_ENABLED)
    extern uint16_T ADC2DMABuffer[DMA_BUFFER_SIZE_BYTE_ALLIGNED(MW_ADC2_DMA_BUFFER_SIZE,32)] ;
#endif
#define GET_ADC2_DMA_BUFFER() &ADC2DMABuffer[0]
#endif

#if defined(MW_ADC3_DMA_ENABLED)
#ifdef STM32H7
    #if defined(MW_DCACHE_ENABLED)
    extern uint32_T ADC3DMABuffer[DMA_BUFFER_SIZE_BYTE_ALLIGNED(MW_ADC3_DMA_BUFFER_SIZE,32)] ;
    #else
    extern uint32_T ADC3DMABuffer[MW_ADC3_DMA_BUFFER_SIZE] ;
    #endif
#elif defined(STM32F7) && defined(MW_DCACHE_ENABLED)
    extern uint16_T ADC3DMABuffer[DMA_BUFFER_SIZE_BYTE_ALLIGNED(MW_ADC3_DMA_BUFFER_SIZE,32)] ;
#endif
#define GET_ADC3_DMA_BUFFER() &ADC3DMABuffer[0]
#endif

#if defined(MW_ADC4_DMA_ENABLED)
    #if defined(STM32U5)
        extern uint16_T ADC4DMABuffer[MW_ADC4_DMA_BUFFER_SIZE];
    #endif
    #define GET_ADC4_DMA_BUFFER() &ADC4DMABuffer[0]
#endif

#if defined(STM32H7) || defined(STM32U5)
    typedef uint32_T ADC_Buffer_DataType_T;
#else
    typedef uint16_T ADC_Buffer_DataType_T;
#endif

#ifdef MW_DCACHE_ENABLED
    #ifdef STM32H7
        #define DMA_BUFFER_WIDTH 4
    #else
        #define DMA_BUFFER_WIDTH 2
    #endif
#endif

/******************************************************************************
* Typedefs
*******************************************************************************/

typedef enum _ADC_Data_Transfer_Mode_T {    
    ADC_DR_TRANSFER              = 0,
    ADC_DMA_ONESHOT              = 1,
    ADC_MDF_TRANSFER             = 2,
    ADC_DMA_CIRCULAR             = 3
} ADC_Data_Transfer_Mode_T;

typedef enum _ADC_Dma_Transfer_Mode_T {    
    ADC_DMA_TRANSFER_NONE        = 0,
    ADC_DMA_TRANSFER_LIMITED     = 1,
    ADC_DMA_TRANSFER_UNLIMITED   = 2
} ADC_Dma_Transfer_Mode_T;

typedef enum _ADC_Mode_T {
    ADC_NORMAL_MODE                 = 0x01,
    ADC_INTERRUPT_MODE              = 0x02,
    ADC_DMA_INTERRUPT_MODE          = 0x04,
    ADC_ERROR_INTERRUPT_MODE        = 0x08
} ADC_Mode_T;
typedef enum _ADC_Trigger_T {
    ADC_TRIGGER                     = 0x01,
    ADC_READ                        = 0x02,
    ADC_TRIGGER_AND_READ            = 0x04
} ADC_Trigger_T;
typedef enum _ADC_DMA_Status_T {
    ADC_DMA_TRANSFER_INIT           = 0x01,
    ADC_DMA_TRANSFER_START          = 0x02,
    ADC_DMA_TRANSFER_HALF_COMPLETED = 0x04,
    ADC_DMA_TRANSFER_FULL_COMPLETED = 0x08,
    ADC_DMA_DATA_READ               = 0x10
} ADC_DMA_Status_T;
typedef enum _ADC_Status_T {
    ADC_BUSY                        = 0x01,
    ADC_INT_TRIGGERED               = 0x02,
    ADC_DMA_TRANSFER_FULL_TRIGGERED = 0x04,
    ADC_DATA_READ                   = 0x08,
    ADC_OVR                         = 0x10,
    ADC_BUSY_BUT_DATA_AVAILABLE     = 0x20
} ADC_Status_T;

typedef struct _ADC_Type_T {
        uint32_T InternalBufferSize;
        uint8_T RegularNoOfConversion;
        uint8_T InjectedNoOfConversion;
        uint8_T dmastream ;
        uint8_T DataReadyBufferID;
        ADC_Mode_T mode;
        volatile ADC_Status_T RegStatus;
        volatile ADC_Status_T InjStatus;
        ADC_Buffer_DataType_T * InternalBufferPtr;
        void * peripheralPtr;
        void * dmaPeripheralPtr;
        ADC_Data_Transfer_Mode_T DataTransferMode;
        ADC_Dma_Transfer_Mode_T DmaTransferMode;
    } ADC_Type_T;

/******************************************************************************
* Global variable declarations
*******************************************************************************/
#if defined(ADC1) && defined(MW_ADC1_ENABLED)
extern ADC_Type_T mw_adc1;
#endif
#if defined(ADC2) && defined(MW_ADC2_ENABLED)
extern ADC_Type_T mw_adc2;
#endif
#if defined(ADC3) && defined(MW_ADC3_ENABLED)
extern ADC_Type_T mw_adc3;
#endif
#if defined(ADC4) && defined(MW_ADC4_ENABLED)
extern ADC_Type_T mw_adc4;
#endif
#if defined(ADC5) && defined(MW_ADC5_ENABLED)
extern ADC_Type_T mw_adc5;
#endif
/*********************************************************************************
*Static Inline Functions 
*************************************************************************************/
__STATIC_INLINE void enableADCManualCalibrationOffset(ADC_Type_T* ptradc, uint32_T offsetCalibrationFactor, uint32_T conversionMode)
{
    #if defined(STM32H7)
    LL_ADC_SetCalibrationOffsetFactor (ptradc->peripheralPtr, (uint32_T)conversionMode, (uint32_T)offsetCalibrationFactor);
    #endif
    #if defined(STM32G4) || defined(STM32L5)
    LL_ADC_SetCalibrationFactor(ptradc->peripheralPtr, (uint32_T)conversionMode, (uint32_T)offsetCalibrationFactor);
    #endif
    #if defined(STM32WB)
    #if defined (ADC_SUPPORT_2_5_MSPS)
    LL_ADC_SetCalibrationFactor(ptradc->peripheralPtr, (uint32_T)offsetCalibrationFactor);
    #else
    LL_ADC_SetCalibrationFactor(ptradc->peripheralPtr, (uint32_T)conversionMode, (uint32_T)offsetCalibrationFactor);
    #endif
    #endif
}
__STATIC_INLINE void enableADCManualcalibrationLinearity (ADC_Type_T* ptradc, uint32_T linearityCalibWord1, uint32_T linearityCalibWord2, uint32_T linearityCalibWord3, uint32_T linearityCalibWord4, uint32_T linearityCalibWord5, uint32_T linearityCalibWord6)
{
    #if defined(STM32H7)
    LL_ADC_SetCalibrationLinearFactor (ptradc->peripheralPtr, LL_ADC_CALIB_LINEARITY_WORD1, linearityCalibWord1);
    LL_ADC_SetCalibrationLinearFactor (ptradc->peripheralPtr, LL_ADC_CALIB_LINEARITY_WORD2, linearityCalibWord2);
    LL_ADC_SetCalibrationLinearFactor (ptradc->peripheralPtr, LL_ADC_CALIB_LINEARITY_WORD3, linearityCalibWord3);
    LL_ADC_SetCalibrationLinearFactor (ptradc->peripheralPtr, LL_ADC_CALIB_LINEARITY_WORD4, linearityCalibWord4);
    LL_ADC_SetCalibrationLinearFactor (ptradc->peripheralPtr, LL_ADC_CALIB_LINEARITY_WORD5, linearityCalibWord5);
    LL_ADC_SetCalibrationLinearFactor (ptradc->peripheralPtr, LL_ADC_CALIB_LINEARITY_WORD6, linearityCalibWord6);
    #endif
}
/******************************************************************************
* Function Prototypes
*******************************************************************************/
#if defined(GPDMA1)
    uint8_T ADC_IsEnabledDMAITTransferComplete(ADC_Type_T * ptradc, uint32_t (*checkActiveFlag)(DMA_TypeDef *DMAx, uint32_t dmastream),  void (*clearActiveFlag)(DMA_TypeDef *DMAx, uint32_t dmastream));
#else
    uint8_T ADC_IsEnabledDMAITTransferComplete(ADC_Type_T * ptradc, uint32_t (*checkActiveFlag)(DMA_TypeDef *DMAx),  void (*clearActiveFlag)(DMA_TypeDef *DMAx));
#endif
uint8_T ADC_IsActiveFlagOVR(ADC_Type_T * ptradc);
uint8_T ADC_IsActiveFlagJEOS(ADC_Type_T * ptradc);
uint8_T ADC_IsActiveFlagEOCS(ADC_Type_T * ptradc);
ADC_Type_T* ADC_Handle_Init(ADC_Type_T* ptradc, uint16_T mode, uint16_T isRegualar, uint16_T triggerType, uint32_T noOfConversionEnable);
void enableADC( ADC_Type_T * ptradc);
#ifdef STM32H7
void configureADCChannelPreselectionRegister(ADC_TypeDef * ADCx, uint8_T noOfRegularConversions, uint8_T noOfInjectedConversions);
#endif
void enableADCAutomaticCalibration (ADC_Type_T * ptradc, uint32_T calibrationMode, uint8_T adcConversionMode);
void enableADCAutomaticCalibrationOffset(ADC_Type_T * ptradc, uint8_T adcConversionMode);
uint16_T regularReadADCNormal(ADC_Type_T * ptradc, uint16_T triggerType, ADC_Buffer_DataType_T* result);
uint16_T regularReadADCDMA(ADC_Type_T * ptradc, uint16_T triggerType, ADC_Buffer_DataType_T* result);
uint16_T regularReadADCIntr(ADC_Type_T * ptradc, uint16_T triggerType, ADC_Buffer_DataType_T* result);
uint16_T injectedReadADCNormal(ADC_Type_T * ptradc, uint16_T triggerType, ADC_Buffer_DataType_T *data);
uint16_T injectedReadADCIntr(ADC_Type_T * ptradc, uint16_T triggerType, ADC_Buffer_DataType_T *data);
void ADC_Handle_Deinit(ADC_Type_T * ptradc, uint16_T mode, uint16_T isRegualar);
void startADCConversionForExternalTrigger(ADC_Type_T* ptradc, uint8_T isRegular );
#endif /* __STM_ADC_LL_H__ */
