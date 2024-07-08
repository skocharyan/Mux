/* stm_can_hal.h: Header file for STM32 HAL based bxCAN driver implementation*/

/* Copyright 2022 The MathWorks, Inc. */

#ifndef MW_CAN_HAL_H
#define MW_CAN_HAL_H

#include "main.h"
#define MW_ISEQUAL_TO_NULL(x)               ((void *)(x) == NULL)
#define MW_ISNOTEQUAL_TO_HAL_OK(x)          ((x) != HAL_OK)
typedef struct _CAN_Type_T {   
    void * peripheralPtr;
    uint8_T isInit;
} CAN_Type_T;

CAN_Type_T* MW_CAN_Initialize(uint8_T module);
void MW_configureCANFilter(CAN_Type_T * handle, uint8_T module, uint16_T idHigh, uint16_T idLow, uint16_T maskIdHigh, uint16_T maskIdLow,
        uint8_T FIFO, uint8_T fbNum, uint8_T mode, uint8_T scale, uint8_T enable);
uint8_T MW_CAN_TransmitMessage(CAN_Type_T* handle, uint8_T* txData, uint32_T id, uint8_T idType, uint8_T remote, uint8_T length, uint32_T timeout, uint32_T * FifoLevel);
uint8_T MW_CAN_ReceiveMessage(CAN_Type_T* handle, uint8_T ReadSrc, uint8_T* rxData, uint32_T *id, uint8_T *idType, uint8_T *remote, uint8_T *length, uint32_T timeout, uint32_T * FifoLevel);
void MW_CAN_Close(CAN_Type_T* handle);

__STATIC_INLINE uint8_T MW_Request_Sleep(CAN_Type_T* handle)
{
	uint8_T status = 1;
	#ifndef MATLAB_MEX_FILE
    if ((NULL != handle) && (1 == handle->isInit))
    {
		if (0U == (((CAN_HandleTypeDef*)handle->peripheralPtr)->Instance->MSR & CAN_MSR_SLAK))
		{
			if(HAL_CAN_RequestSleep((CAN_HandleTypeDef*)handle->peripheralPtr) == HAL_OK)
			{
				status = 0;
			}
		}
	}
	#endif
	return status;
}

__STATIC_INLINE uint8_T MW_Request_Wakeup(CAN_Type_T* handle)
{
	uint8_T status = 1;
	#ifndef MATLAB_MEX_FILE
    if ((NULL != handle) && (1 == handle->isInit))
    {
		if (0U != (((CAN_HandleTypeDef*)handle->peripheralPtr)->Instance->MSR & CAN_MSR_SLAK))
		{
			if(HAL_CAN_WakeUp((CAN_HandleTypeDef*)handle->peripheralPtr) == HAL_OK)
			{
				status = 0;
			}
		}
	}
	#endif
	return status;
}

__STATIC_INLINE uint8_T MW_Request_Sleep_Status(CAN_Type_T* handle)
{
	#ifndef MATLAB_MEX_FILE
    if ((NULL != handle) && (1 == handle->isInit))
    {
		return (uint8_T)HAL_CAN_IsSleepActive((CAN_HandleTypeDef*)handle->peripheralPtr);
	}
	#endif
	return 0;
}
#endif