/* stm_fdcan_hal.h: Header file for STM32 HAL based FDCAN driver implementation*/

/* Copyright 2022 The MathWorks, Inc. */

#ifndef MW_FDCAN_HAL_H
#define MW_FDCAN_HAL_H

#define MW_ISEQUAL_TO_NULL(x)               ((void *)(x) == NULL)
#define MW_ISNOTEQUAL_TO_HAL_OK(x)          ((x) != HAL_OK)

#include "main.h"

typedef struct _FDCAN_Type_T {   
    void * peripheralPtr;
    uint8_T isInit;
	uint8_T isFilterConfigured ;
	uint8_T isGlobalFilterConfigured ;
} FDCAN_Type_T;

FDCAN_Type_T* MW_FDCAN_Initialize(uint8_T module);
void MW_configureFDCANFilter(FDCAN_Type_T * handle, uint8_T module, uint16_T idHigh, uint16_T idLow, uint16_T maskIdHigh, uint16_T maskIdLow, uint8_T FIFO, uint8_T fbNum, uint8_T mode, uint8_T scale, uint8_T enable);
uint8_T MW_FDCAN_TransmitMessage(FDCAN_Type_T* handle, uint8_T* txData, uint32_T id, uint8_T idType, uint8_T remote, uint32_T length, uint32_T timeout, uint8_T isFDCANForamt,uint8_T brs, uint32_T * FifoLevel);
uint8_T MW_FDCAN_ReceiveMessage(FDCAN_Type_T* handle, uint8_T ReadSrc, uint8_T* rxData, uint32_T *id, uint8_T *idType, uint8_T *remote, uint8_T *length, uint8_T *dlc, uint8_T *isBRS, uint8_T *isFDCAN, uint32_T timeout, uint32_T * FifoLevel);
void MW_FDCAN_Close(FDCAN_Type_T* handle);

__STATIC_INLINE uint8_T MW_FDCAN_EnterPowerDownMode(FDCAN_Type_T* handle)
{
	uint8_T status = 1;
	#ifndef MATLAB_MEX_FILE
    if ((NULL != handle) && (1 == handle->isInit))
    {
		if (0U == (((FDCAN_HandleTypeDef*)handle->peripheralPtr)->Instance->CCCR & FDCAN_CCCR_CSR))
		{
			if(HAL_FDCAN_EnterPowerDownMode((FDCAN_HandleTypeDef*)handle->peripheralPtr) == HAL_OK)
			{
				status = 0;
			}
		}
	}
	#endif
	return status;
}

__STATIC_INLINE uint8_T MW_FDCAN_ExitPowerDownMode(FDCAN_Type_T* handle)
{
	uint8_T status = 1;
	#ifndef MATLAB_MEX_FILE
    if ((NULL != handle) && (1 == handle->isInit))
    {
		if (FDCAN_CCCR_CSR == (((FDCAN_HandleTypeDef*)handle->peripheralPtr)->Instance->CCCR & FDCAN_CCCR_CSR))
		{
			if(HAL_FDCAN_ExitPowerDownMode((FDCAN_HandleTypeDef*)handle->peripheralPtr) == HAL_OK)
			{
				status = 0;
			}
		}
	}
	#endif
	return status;
}

__STATIC_INLINE uint8_T MW_FDCAN_Request_Sleep_Status(FDCAN_Type_T* handle)
{
	#ifndef MATLAB_MEX_FILE
    if ((NULL != handle) && (1 == handle->isInit))
    {
		if (FDCAN_CCCR_CSR == (((FDCAN_HandleTypeDef*)handle->peripheralPtr)->Instance->CCCR & FDCAN_CCCR_CSR))
		{
			return 1;
		}
		else
		{
			return 0;
		}
	}
	#endif
	return 0;
}


__STATIC_INLINE uint8_T MW_FDCAN_IsRestrictedOperationMode(FDCAN_Type_T* handle)
{
	#ifndef MATLAB_MEX_FILE
    if ((NULL != handle) && (1 == handle->isInit))
    {
		return (uint8_T)HAL_FDCAN_IsRestrictedOperationMode((FDCAN_HandleTypeDef*)handle->peripheralPtr) ;
	}
	#endif
	return 0;
}

__STATIC_INLINE uint8_T MW_FDCAN_ExitRestrictedOperationMode(FDCAN_Type_T* handle)
{
	#ifndef MATLAB_MEX_FILE
    if ((NULL != handle) && (1 == handle->isInit))
    {
		if(HAL_FDCAN_IsRestrictedOperationMode((FDCAN_HandleTypeDef*)handle->peripheralPtr))
		{
			if (HAL_FDCAN_ExitRestrictedOperationMode((FDCAN_HandleTypeDef*)handle->peripheralPtr) == HAL_OK)
			{
				return 0;
			}
		}
	}
	#endif
	return 1;
}

__STATIC_INLINE uint8_T MW_FDCAN_GetLastErrorCode(FDCAN_Type_T * handle)
{
    #ifndef MATLAB_MEX_FILE
	if ((NULL != handle) && (1 == handle->isInit))
	{
		return (uint8_T)(((uint32_T)READ_REG(((FDCAN_HandleTypeDef*)handle->peripheralPtr)->Instance->PSR) & (uint32_T)FDCAN_PSR_LEC)>>FDCAN_PSR_LEC_Pos);
	}
    #endif
    return 0;
}

__STATIC_INLINE void MW_FDCAN_Start(FDCAN_Type_T * handle)
{
	#ifndef MATLAB_MEX_FILE
	if ((NULL != handle) && (1 == handle->isInit))
	{
		HAL_FDCAN_Start((FDCAN_HandleTypeDef*)handle->peripheralPtr);
	}
	#endif
}
#endif
