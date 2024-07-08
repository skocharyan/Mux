/* Copyright 2022-2023 The MathWorks, Inc. */
#ifndef __STM_COMP_LL_H__
#define __STM_COMP_LL_H__
/******************************************************************************
* Includes
*******************************************************************************/
#include "mw_stm32_types.h"
#include "rtwtypes.h"
#include "main.h"
/******************************************************************************
* Typedefs
*******************************************************************************/
typedef struct _MW_COMP_Type_T {
    void * peripheralPtr;

} MW_COMP_Type_T;


/******************************************************************************
* Function Prototypes
*******************************************************************************/

MW_COMP_Type_T* MW_COMP_Init(MW_COMP_Type_T* ptrComp);

void MW_COMP_Enable(MW_COMP_Type_T * ptrComp);
void MW_COMP_Disable(MW_COMP_Type_T * ptrComp);
boolean_T MW_COMP_ReadOutput(MW_COMP_Type_T * ptrComp);


#endif
