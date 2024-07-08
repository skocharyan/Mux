/* Copyright 2022 The MathWorks, Inc. */
#ifndef __STM_DAC_LL_H__
#define __STM_DAC_LL_H__
/******************************************************************************
* Includes
*******************************************************************************/
#include "mw_stm32_types.h"
#include "main.h"
#include "rtwtypes.h"
/******************************************************************************
* Typedefs
*******************************************************************************/
typedef struct _MW_DAC_Type_T {
    void * peripheralPtr;
    boolean_T dualChannel;

} MW_DAC_Type_T;


/******************************************************************************
* Function Prototypes
*******************************************************************************/

MW_DAC_Type_T* MW_DAC_Init(MW_DAC_Type_T* ptrdac);

boolean_T MW_DAC_Enable(MW_DAC_Type_T * ptrdac,uint32_T Channel);

boolean_T MW_DAC_SetDHR(MW_DAC_Type_T * ptrdac, uint32_T Channel, uint32_T Data, boolean_T dataLength, boolean_T dataAlign,uint32_T maxValue);

boolean_T MW_DAC_SetDHRDual(MW_DAC_Type_T * ptrdac, uint32_T DataChannel1, uint32_T DataChannel2, boolean_T dataLength, boolean_T dataAlign,uint32_T maxValue);

void MW_DAC_SoftwareTriggerEnable(MW_DAC_Type_T * ptrdac,uint32_T Channel);

boolean_T MW_DAC_SoftwareTrigger1(MW_DAC_Type_T * ptrdac,uint32_T Channel);

boolean_T MW_DAC_SoftwareTrigger2(MW_DAC_Type_T * ptrdac,uint32_T Channel);

boolean_T MW_DAC_SetSawtoothStep(MW_DAC_Type_T * ptrdac, uint32_T Channel, uint32_T Data);

#endif



