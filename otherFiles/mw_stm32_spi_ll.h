/* Copyright 2023 The MathWorks, Inc. */
#ifndef __MW_STM32_SPI_LL_H__
#define __MW_STM32_SPI_LL_H__
/******************************************************************************
* Includes
*******************************************************************************/
#include "main.h"
#include "MW_SPI.h"
#include "mw_stm32_types.h"
/******************************************************************************
* Preprocessor Macros
*******************************************************************************/
#define MW_SPI_MODULE_NUM (6) //Number of max SPI modules available on STM32
/******************************************************************************
* Typedefs
*******************************************************************************/
__STATIC_INLINE void MW_SPI_Disable(SPI_TypeDef *SPIx);

typedef enum _MW_STM32_SPI_FIFO_Access_type {
    FIFO_ACCESS_8BIT      = 0x00,
    FIFO_ACCESS_16BIT     = 0x01,
    FIFO_ACCESS_32BIT     = 0x02,
}MW_STM32_SPI_FIFO_Access_type;

typedef struct STM32_SPI_ModuleStruct_T_ {
    uint16_T spi_clk_mode;
    uint32_T charLength;
    uint8_T SPI_oneTimeInit[MW_SPI_MODULE_NUM];
    #if defined(STM32H7) || defined(STM32U5)
    uint8_T SPI_fifo_oneTimeInit[MW_SPI_MODULE_NUM];
    #endif
    void *PeripheralPtr;
} STM32_SPI_ModuleStruct_T;
/******************************************************************************
* Static Inline functions
*******************************************************************************/
/* Initiate SPI data write */
__STATIC_INLINE MW_SPI_Status_Type MW_SPI_Direction_Set(SPI_TypeDef *SPIx, uint16_T blockFunction)
{
    /* block function = 0 (Read), block function = 1 (Write) */
    if((LL_SPI_GetTransferDirection(SPIx)==LL_SPI_HALF_DUPLEX_RX) && (blockFunction==1))
    {
        MW_SPI_Disable(SPIx);
        LL_SPI_SetTransferDirection(SPIx, LL_SPI_HALF_DUPLEX_TX);
    }
    else if((LL_SPI_GetTransferDirection(SPIx)==LL_SPI_HALF_DUPLEX_TX) && (blockFunction==0))
    {
        MW_SPI_Disable(SPIx);
        LL_SPI_SetTransferDirection(SPIx, LL_SPI_HALF_DUPLEX_RX);
    }
    return MW_SPI_SUCCESS;
}

#if defined(STM32H7) || defined(STM32U5)
__STATIC_INLINE MW_SPI_Status_Type MW_SPI_Write_Databits(STM32_SPI_ModuleStruct_T* SPIModuleHandle, const void * wrData, uint16_T datalength, uint16_T fifo_access, uint16_T blockingMode, uint32_T Timeout)
{
    #ifndef MATLAB_MEX_FILE
    uint16_T localVar;
    uint16_T ret = MW_SPI_SUCCESS;
    uint32_T initialTime = 0;
    initialTime = GET_CURRENT_TIME();
    ret = MW_SPI_Direction_Set((SPI_TypeDef *)SPIModuleHandle->PeripheralPtr, 1);
    
    if(blockingMode==0)
    {Timeout=0;}
    if(LL_SPI_IsActiveFlag_UDR((SPI_TypeDef *)SPIModuleHandle->PeripheralPtr)==1)
	{
		LL_SPI_ClearFlag_UDR((SPI_TypeDef *)SPIModuleHandle->PeripheralPtr);
	}
    if(LL_SPI_IsEnabled((SPI_TypeDef *)SPIModuleHandle->PeripheralPtr)==0)
    {
        LL_SPI_Enable((SPI_TypeDef *)SPIModuleHandle->PeripheralPtr);
    }
    if(LL_SPI_GetMode((SPI_TypeDef *)SPIModuleHandle->PeripheralPtr)==LL_SPI_MODE_MASTER)
    {LL_SPI_StartMasterTransfer((SPI_TypeDef *)SPIModuleHandle->PeripheralPtr);
    }


    if(FIFO_ACCESS_8BIT == (MW_STM32_SPI_FIFO_Access_type)fifo_access)
    {
        uint8_T *writedata = (uint8_T*) wrData;
        localVar=0;
        while (localVar < datalength)
        {
            if(1 == LL_SPI_IsActiveFlag_TXP((SPI_TypeDef *)SPIModuleHandle->PeripheralPtr))
            {
                LL_SPI_TransmitData8((SPI_TypeDef *)SPIModuleHandle->PeripheralPtr, writedata[localVar]);
                localVar++;
            }
            else
            {
                if(returnTimeElapsed(initialTime, 1) > Timeout)
                {
                    ret = MW_SPI_BUSY;
                    goto error;
                }
            }
        }
    }
    else if(FIFO_ACCESS_16BIT == (MW_STM32_SPI_FIFO_Access_type)fifo_access)
    {
        uint16_T *writedata = (uint16_T*) wrData;
        localVar=0;
        while (localVar < datalength)
        {
            if(1 == LL_SPI_IsActiveFlag_TXP ((SPI_TypeDef *)SPIModuleHandle->PeripheralPtr))
            {
                LL_SPI_TransmitData16((SPI_TypeDef *)SPIModuleHandle->PeripheralPtr, writedata[localVar]);
                localVar++;
            }
            else
            {
                if(returnTimeElapsed(initialTime, 1) > Timeout)
                {
                    ret = MW_SPI_BUSY;
                    goto error;
                }
            }
        }
    }
    else if(FIFO_ACCESS_32BIT == (MW_STM32_SPI_FIFO_Access_type)fifo_access)
    {
        uint32_T *writedata = (uint32_T*) wrData;
        localVar=0;
        while (localVar < datalength)
        {
            if(1 == LL_SPI_IsActiveFlag_TXP ((SPI_TypeDef *)SPIModuleHandle->PeripheralPtr))
            {
                LL_SPI_TransmitData32((SPI_TypeDef *)SPIModuleHandle->PeripheralPtr, writedata[localVar]);
                localVar++;
            }
            else
            {
                if(returnTimeElapsed(initialTime, 1) > Timeout)
                {
                    ret = MW_SPI_BUSY;
                    goto error;
                }
            }
        }
    }

    error:
    if(LL_SPI_IsActiveFlag_UDR((SPI_TypeDef *)SPIModuleHandle->PeripheralPtr)==1)
    {
        LL_SPI_ClearFlag_UDR((SPI_TypeDef *)SPIModuleHandle->PeripheralPtr);
    }
    return (MW_SPI_Status_Type)ret;
    #else
    return -1;
    #endif
}
#else
__STATIC_INLINE MW_SPI_Status_Type MW_SPI_Write_Databits(STM32_SPI_ModuleStruct_T* SPIModuleHandle, const void * wrData, uint16_T datalength, uint16_T fifo_access, uint16_T blockingMode, uint32_T Timeout)
{
    #ifndef MATLAB_MEX_FILE
    uint16_T localVar;
    uint16_T ret = MW_SPI_SUCCESS;
    ret = MW_SPI_Direction_Set((SPI_TypeDef *)SPIModuleHandle->PeripheralPtr, 1);
    
    uint32_T initialTime = 0;
    initialTime = GET_CURRENT_TIME();


    if(blockingMode==0)
    {Timeout=0;}

    if(LL_SPI_IsEnabled((SPI_TypeDef *)SPIModuleHandle->PeripheralPtr)==0)
    {
        LL_SPI_Enable((SPI_TypeDef *)SPIModuleHandle->PeripheralPtr);
    }

    if(FIFO_ACCESS_8BIT == (MW_STM32_SPI_FIFO_Access_type)fifo_access)
    {
        uint8_T *writedata = (uint8_T*) wrData;
        localVar = 0;
        while (localVar < datalength)
        {
            if(1 == LL_SPI_IsActiveFlag_TXE ((SPI_TypeDef *)SPIModuleHandle->PeripheralPtr))
            {
                LL_SPI_TransmitData8((SPI_TypeDef *)SPIModuleHandle->PeripheralPtr, writedata[localVar]);
                localVar++;
            }
            else
            {
                if(returnTimeElapsed(initialTime, 1) > Timeout)
                {
                    ret = MW_SPI_BUSY;
                    goto error;
                }
            }
        }
    }
    else if(FIFO_ACCESS_16BIT == (MW_STM32_SPI_FIFO_Access_type)fifo_access)
    {
        uint16_T *writedata = (uint16_T*) wrData;
        localVar = 0;
        while (localVar < datalength)
        {
            if(1 == LL_SPI_IsActiveFlag_TXE ((SPI_TypeDef *)SPIModuleHandle->PeripheralPtr))
            {
                LL_SPI_TransmitData16((SPI_TypeDef *)SPIModuleHandle->PeripheralPtr, writedata[localVar]);
                localVar++;
            }
            else
            {
                if(returnTimeElapsed(initialTime, 1) > Timeout)
                {
                    ret = MW_SPI_BUSY;
                    goto error;
                }
            }
        }
    }

    error:
    return (MW_SPI_Status_Type)ret;
    #else
    return -1;
    #endif
}
#endif

#if defined(STM32H7) || defined(STM32U5)
__STATIC_INLINE MW_SPI_Status_Type MW_SPI_Read_Databits(STM32_SPI_ModuleStruct_T* SPIModuleHandle, const void * rdData, uint16_T datalength, uint16_T fifo_access, uint16_T blockingMode, uint32_T Timeout)
{
    #ifndef MATLAB_MEX_FILE
    uint16_T localVar=0;
    uint16_T ret = MW_SPI_SUCCESS;
    uint32_T initialTime = 0;
    initialTime = GET_CURRENT_TIME();
    ret = MW_SPI_Direction_Set((SPI_TypeDef *)SPIModuleHandle->PeripheralPtr, 0);
    
    if(blockingMode==0)
    {Timeout=0;}
    
    if((LL_SPI_GetTransferDirection((SPI_TypeDef *)SPIModuleHandle->PeripheralPtr)==LL_SPI_HALF_DUPLEX_RX)&&(LL_SPI_GetMode((SPI_TypeDef *)SPIModuleHandle->PeripheralPtr)==LL_SPI_MODE_MASTER))
    {
        LL_SPI_SetTransferSize((SPI_TypeDef *)SPIModuleHandle->PeripheralPtr,datalength);
    }
    if(LL_SPI_IsEnabled((SPI_TypeDef *)SPIModuleHandle->PeripheralPtr)==0)
    {
        LL_SPI_Enable((SPI_TypeDef *)SPIModuleHandle->PeripheralPtr);
        if(LL_SPI_GetMode((SPI_TypeDef *)SPIModuleHandle->PeripheralPtr)==LL_SPI_MODE_MASTER)
        {
            LL_SPI_ClearFlag_SUSP((SPI_TypeDef *)SPIModuleHandle->PeripheralPtr);
            LL_SPI_StartMasterTransfer((SPI_TypeDef *)SPIModuleHandle->PeripheralPtr);
        }
    }

    if(FIFO_ACCESS_8BIT == (MW_STM32_SPI_FIFO_Access_type)fifo_access)
    {
        uint8_T *readdata = (uint8_T*) rdData;
        localVar=0;
        while (localVar < datalength)
        {
            if((LL_SPI_IsActiveFlag_RXWNE((SPI_TypeDef *)SPIModuleHandle->PeripheralPtr)>0) || (LL_SPI_GetRxFIFOPackingLevel((SPI_TypeDef *)SPIModuleHandle->PeripheralPtr)>0) || (LL_SPI_IsActiveFlag_RXP((SPI_TypeDef *)SPIModuleHandle->PeripheralPtr)>0))
            {
                readdata[localVar] = LL_SPI_ReceiveData8((SPI_TypeDef *)SPIModuleHandle->PeripheralPtr);
                localVar++;
            }
            else
            {
                if(returnTimeElapsed(initialTime, 1) > Timeout)
                {
                    ret = MW_SPI_BUSY;
                    goto error;
                }
            }
        }
    }
    else if(FIFO_ACCESS_16BIT == (MW_STM32_SPI_FIFO_Access_type)fifo_access)
    {
        uint16_T *readdata = (uint16_T*) rdData;
        localVar = 0;
        while (localVar < datalength)
        {
            if((LL_SPI_IsActiveFlag_RXWNE((SPI_TypeDef *)SPIModuleHandle->PeripheralPtr)>0) || (LL_SPI_GetRxFIFOPackingLevel((SPI_TypeDef *)SPIModuleHandle->PeripheralPtr)>0) || (LL_SPI_IsActiveFlag_RXP((SPI_TypeDef *)SPIModuleHandle->PeripheralPtr)>0))
            {
                readdata[localVar] = LL_SPI_ReceiveData16((SPI_TypeDef *)SPIModuleHandle->PeripheralPtr);
                localVar++;
            }
            else
            {
                if(returnTimeElapsed(initialTime, 1) > Timeout)
                {
                    ret = MW_SPI_BUSY;
                    goto error;
                }
            }
        }
    }
    else if(FIFO_ACCESS_32BIT == (MW_STM32_SPI_FIFO_Access_type)fifo_access)
    {
        uint32_T *readdata = (uint32_T*) rdData;
        localVar = 0;
        while (localVar < datalength)
        {
            if((LL_SPI_IsActiveFlag_RXWNE((SPI_TypeDef *)SPIModuleHandle->PeripheralPtr)>0) || (LL_SPI_GetRxFIFOPackingLevel((SPI_TypeDef *)SPIModuleHandle->PeripheralPtr)>0) || (LL_SPI_IsActiveFlag_RXP((SPI_TypeDef *)SPIModuleHandle->PeripheralPtr)>0))
            {
                readdata[localVar] = LL_SPI_ReceiveData32((SPI_TypeDef *)SPIModuleHandle->PeripheralPtr);
                localVar++;
            }
            else
            {
                if(returnTimeElapsed(initialTime, 1) > Timeout)
                {
                    ret = MW_SPI_BUSY;
                    goto error;
                }
            }
        }
    }

    error:
    if((LL_SPI_GetMode((SPI_TypeDef *)SPIModuleHandle->PeripheralPtr)==LL_SPI_MODE_MASTER) && (LL_SPI_GetTransferDirection((SPI_TypeDef *)SPIModuleHandle->PeripheralPtr)==LL_SPI_HALF_DUPLEX_RX))
    {
        LL_SPI_SuspendMasterTransfer((SPI_TypeDef *)SPIModuleHandle->PeripheralPtr);
        
        while((LL_SPI_IsActiveFlag_RXWNE((SPI_TypeDef *)SPIModuleHandle->PeripheralPtr)>0) || (LL_SPI_GetRxFIFOPackingLevel((SPI_TypeDef *)SPIModuleHandle->PeripheralPtr)>0) || (LL_SPI_IsActiveFlag_RXP((SPI_TypeDef *)SPIModuleHandle->PeripheralPtr)>0))
        {
        	LL_SPI_ReceiveData8((SPI_TypeDef *)SPIModuleHandle->PeripheralPtr);
        }
        LL_SPI_Disable((SPI_TypeDef *)SPIModuleHandle->PeripheralPtr);
    }
    return (MW_SPI_Status_Type)ret;
    #else
    return -1;
    #endif
}
#else
__STATIC_INLINE MW_SPI_Status_Type MW_SPI_Read_Databits(STM32_SPI_ModuleStruct_T* SPIModuleHandle, const void * rdData, uint16_T datalength, uint16_T fifo_access, uint16_T blockingMode, uint32_T Timeout)
{
    #ifndef MATLAB_MEX_FILE
    uint16_T localVar;
    uint16_T ret = MW_SPI_SUCCESS;
    uint32_T initialTime = 0;
    ret = MW_SPI_Direction_Set((SPI_TypeDef *)SPIModuleHandle->PeripheralPtr, 0);
    initialTime = GET_CURRENT_TIME();
    uint16_T RxBuffSize = datalength;

    if(blockingMode==0)
    {Timeout=0;}

    if((LL_SPI_GetMode((SPI_TypeDef *)SPIModuleHandle->PeripheralPtr)==LL_SPI_MODE_MASTER) && (LL_SPI_GetTransferDirection((SPI_TypeDef *)SPIModuleHandle->PeripheralPtr)==LL_SPI_HALF_DUPLEX_RX))
    {
        RxBuffSize = RxBuffSize-1;
    }

    if(LL_SPI_IsEnabled((SPI_TypeDef *)SPIModuleHandle->PeripheralPtr)==0)
    {
        LL_SPI_Enable((SPI_TypeDef *)SPIModuleHandle->PeripheralPtr);
    }

    if(FIFO_ACCESS_8BIT == (MW_STM32_SPI_FIFO_Access_type)fifo_access)
    {
        uint8_T *readdata = (uint8_T*) rdData;
        localVar = 0;
        while (localVar < RxBuffSize)
        {
            if(LL_SPI_IsActiveFlag_RXNE((SPI_TypeDef *)SPIModuleHandle->PeripheralPtr) > 0)
            {
                readdata[localVar] = LL_SPI_ReceiveData8((SPI_TypeDef *)SPIModuleHandle->PeripheralPtr);
                localVar++;
            }
            else
            {
                if(returnTimeElapsed(initialTime, 1) > Timeout)
                {
                    ret = MW_SPI_BUSY;
                    goto error;
                }
            }
        }
    }
    else if(FIFO_ACCESS_16BIT == (MW_STM32_SPI_FIFO_Access_type)fifo_access)
    {
        uint16_T *readdata = (uint16_T*) rdData;
        localVar = 0;
        while (localVar < RxBuffSize)
        {
            if(LL_SPI_IsActiveFlag_RXNE((SPI_TypeDef *)SPIModuleHandle->PeripheralPtr) > 0)
            {
                readdata[localVar] = LL_SPI_ReceiveData16((SPI_TypeDef *)SPIModuleHandle->PeripheralPtr);
                localVar++;
            }
            else
            {
                if(returnTimeElapsed(initialTime, 1) > Timeout)
                {
                    ret = MW_SPI_BUSY;
                    goto error;
                }
            }

        }
    }

    error:
    if((LL_SPI_GetMode((SPI_TypeDef *)SPIModuleHandle->PeripheralPtr)==LL_SPI_MODE_MASTER) && (LL_SPI_GetTransferDirection((SPI_TypeDef *)SPIModuleHandle->PeripheralPtr)==LL_SPI_HALF_DUPLEX_RX))
    {
        LL_SPI_Disable((SPI_TypeDef *)SPIModuleHandle->PeripheralPtr);
        if(RxBuffSize != datalength)
        {
            while(1){
                if(LL_SPI_IsActiveFlag_RXNE((SPI_TypeDef *)SPIModuleHandle->PeripheralPtr) > 0)
                {
                    if(FIFO_ACCESS_8BIT == (MW_STM32_SPI_FIFO_Access_type)fifo_access){
                        uint8_T *readdata = (uint8_T*) rdData;
                        readdata[localVar] = LL_SPI_ReceiveData8((SPI_TypeDef *)SPIModuleHandle->PeripheralPtr);}
                    else if(FIFO_ACCESS_16BIT == (MW_STM32_SPI_FIFO_Access_type)fifo_access){
                        uint16_T *readdata = (uint16_T*) rdData;
                        readdata[localVar] = LL_SPI_ReceiveData16((SPI_TypeDef *)SPIModuleHandle->PeripheralPtr);}
                    break;
                }
                else
                {
                    if(returnTimeElapsed(initialTime, 1) > Timeout)
                    {
                        ret = MW_SPI_BUSY;
                        break;
                    }
                }
            }


        }
        #if !defined(STM32F4)
        while(LL_SPI_GetRxFIFOLevel((SPI_TypeDef *)SPIModuleHandle->PeripheralPtr) > 0)
        {
            LL_SPI_ReceiveData8((SPI_TypeDef *)SPIModuleHandle->PeripheralPtr);
        }
        #endif
    }

    return (MW_SPI_Status_Type)ret;
    #else
    return -1;
    #endif
}
#endif
#if defined(STM32H7) || defined(STM32U5)
__STATIC_INLINE MW_SPI_Status_Type MW_SPI_MasterWriteRead_Databits(STM32_SPI_ModuleStruct_T* SPIModuleHandle, const void * wrData, void * rdData, uint16_T fifo_access, uint32_T datalength, uint16_T blockingMode, uint32_T Timeout)
{
    #ifndef MATLAB_MEX_FILE
    uint16_T localVarTx;
    uint16_T localVarRx;
    uint16_T ret = MW_SPI_SUCCESS;
    uint32_T initialTime = 0;
    initialTime = GET_CURRENT_TIME();

    uint16_T TxAllowed =1;

    if(blockingMode==0)
    {Timeout=0;}

    if(LL_SPI_IsEnabled((SPI_TypeDef *)SPIModuleHandle->PeripheralPtr)==0)
    {
        LL_SPI_Enable((SPI_TypeDef *)SPIModuleHandle->PeripheralPtr);
    }

    if(FIFO_ACCESS_8BIT == (MW_STM32_SPI_FIFO_Access_type)fifo_access)
    {
        uint8_T *readdata = (uint8_T*) rdData;
        uint8_T *writedata = (uint8_T*) wrData;
        localVarTx = 0;
        localVarRx = 0;
        while (localVarTx < datalength || localVarRx < datalength)
        {
            if((1 == LL_SPI_IsActiveFlag_TXP ((SPI_TypeDef *)SPIModuleHandle->PeripheralPtr)) && (TxAllowed==1) && (localVarTx < datalength))
            {
                LL_SPI_TransmitData8((SPI_TypeDef *)SPIModuleHandle->PeripheralPtr, writedata[localVarTx]);
                localVarTx++;
                TxAllowed = 0;
            }
            else
            {
                if(returnTimeElapsed(initialTime, 1) > Timeout)
                {
                    ret = MW_SPI_BUSY;
                    goto error;
                }
            }
            if(((1 == LL_SPI_IsActiveFlag_RXWNE((SPI_TypeDef *)SPIModuleHandle->PeripheralPtr)) || (LL_SPI_GetRxFIFOPackingLevel((SPI_TypeDef *)SPIModuleHandle->PeripheralPtr)>0)) && (localVarRx < datalength) && (TxAllowed==0))
            {
                readdata[localVarRx] = LL_SPI_ReceiveData8((SPI_TypeDef *)SPIModuleHandle->PeripheralPtr);
                //ret |= (uint16_T)LL_SPI_IsActiveFlag_OVR((SPI_TypeDef *)SPIModuleHandle->PeripheralPtr);
                localVarRx++;
                TxAllowed = 1;
            }
            else
            {
                if(returnTimeElapsed(initialTime, 1) > Timeout)
                {
                    ret = MW_SPI_BUSY;
                    goto error;
                }
            }
        }
    }
    else if(FIFO_ACCESS_16BIT == (MW_STM32_SPI_FIFO_Access_type)fifo_access)
    {
        uint16_T *readdata = (uint16_T*) rdData;
        uint16_T *writedata = (uint16_T*) wrData;
        localVarTx = 0;
        localVarRx = 0;
        while (localVarTx < datalength || localVarRx < datalength)
        {
            if((1 == LL_SPI_IsActiveFlag_TXP ((SPI_TypeDef *)SPIModuleHandle->PeripheralPtr)) && (TxAllowed==1) && (localVarTx < datalength))
            {
                LL_SPI_TransmitData16((SPI_TypeDef *)SPIModuleHandle->PeripheralPtr, writedata[localVarTx]);
                localVarTx++;
                TxAllowed = 0;
            }
            else
            {
                if(returnTimeElapsed(initialTime, 1) > Timeout)
                {
                    ret = MW_SPI_BUSY;
                    goto error;
                }
            }
            if(((1 == LL_SPI_IsActiveFlag_RXWNE((SPI_TypeDef *)SPIModuleHandle->PeripheralPtr)) || (LL_SPI_GetRxFIFOPackingLevel((SPI_TypeDef *)SPIModuleHandle->PeripheralPtr)>0)) && (localVarRx < datalength) && (TxAllowed==0))
            {
                readdata[localVarRx] = LL_SPI_ReceiveData16((SPI_TypeDef *)SPIModuleHandle->PeripheralPtr);
                //ret |= (uint16_T)LL_SPI_IsActiveFlag_OVR((SPI_TypeDef *)SPIModuleHandle->PeripheralPtr);
                localVarRx++;
                TxAllowed = 1;
            }
            else
            {
                if(returnTimeElapsed(initialTime, 1) > Timeout)
                {
                    ret = MW_SPI_BUSY;
                    goto error;
                }
            }
        }
    }
    else if(FIFO_ACCESS_32BIT == (MW_STM32_SPI_FIFO_Access_type)fifo_access)
    {
        uint32_T *readdata = (uint32_T*) rdData;
        uint32_T *writedata = (uint32_T*) wrData;
        localVarTx = 0;
        localVarRx = 0;
        while (localVarTx < datalength || localVarRx < datalength)
        {
            if((1 == LL_SPI_IsActiveFlag_TXP ((SPI_TypeDef *)SPIModuleHandle->PeripheralPtr)) && (TxAllowed==1) && (localVarTx < datalength))
            {
                LL_SPI_TransmitData32((SPI_TypeDef *)SPIModuleHandle->PeripheralPtr, writedata[localVarTx]);
                localVarTx++;
                TxAllowed = 0;
            }
            else
            {
                if(returnTimeElapsed(initialTime, 1) > Timeout)
                {
                    ret = MW_SPI_BUSY;
                    goto error;
                }
            }
            if(((1 == LL_SPI_IsActiveFlag_RXWNE((SPI_TypeDef *)SPIModuleHandle->PeripheralPtr)) || (LL_SPI_GetRxFIFOPackingLevel((SPI_TypeDef *)SPIModuleHandle->PeripheralPtr)>0)) && (localVarRx < datalength) && (TxAllowed==0))
            {
                readdata[localVarRx] = LL_SPI_ReceiveData32((SPI_TypeDef *)SPIModuleHandle->PeripheralPtr);
                //ret = (uint16_T)LL_SPI_IsActiveFlag_OVR((SPI_TypeDef *)SPIModuleHandle->PeripheralPtr);
                localVarRx++;
                TxAllowed = 1;
            }
            else
            {
                if(returnTimeElapsed(initialTime, 1) > Timeout)
                {
                    ret = MW_SPI_BUSY;
                    goto error;
                }
            }
        }
    }

    error:

    return (MW_SPI_Status_Type)ret;
    #else
    return -1;
    #endif
}
#else
__STATIC_INLINE MW_SPI_Status_Type MW_SPI_MasterWriteRead_Databits(STM32_SPI_ModuleStruct_T* SPIModuleHandle, const void * wrData, void * rdData, uint16_T fifo_access, uint32_T datalength, uint16_T blockingMode, uint32_T Timeout)
{
    #ifndef MATLAB_MEX_FILE
    uint16_T localVarTx;
    uint16_T localVarRx;
    uint16_T ret = MW_SPI_SUCCESS;
    uint32_T initialTime = 0;
    initialTime = GET_CURRENT_TIME();

    uint16_T TxAllowed =1;

    if(blockingMode==0)
    {Timeout=0;}

    if(LL_SPI_IsEnabled((SPI_TypeDef *)SPIModuleHandle->PeripheralPtr)==0)
    {
        LL_SPI_Enable((SPI_TypeDef *)SPIModuleHandle->PeripheralPtr);
    }

    if(FIFO_ACCESS_8BIT == (MW_STM32_SPI_FIFO_Access_type)fifo_access)
    {
        uint8_T *readdata = (uint8_T*) rdData;
        uint8_T *writedata = (uint8_T*) wrData;
        localVarTx = 0;
        localVarRx = 0;
        while (localVarTx < datalength || localVarRx < datalength)
        {
            if((1 == LL_SPI_IsActiveFlag_TXE ((SPI_TypeDef *)SPIModuleHandle->PeripheralPtr)) && (TxAllowed==1) && (localVarTx < datalength))
            {
                LL_SPI_TransmitData8((SPI_TypeDef *)SPIModuleHandle->PeripheralPtr, writedata[localVarTx]);
                localVarTx++;
                TxAllowed = 0;

            }
            else
            {
                if(returnTimeElapsed(initialTime, 1) > Timeout)
                {
                    ret = MW_SPI_BUSY;
                    goto error;
                }
            }
            if((1 == LL_SPI_IsActiveFlag_RXNE((SPI_TypeDef *)SPIModuleHandle->PeripheralPtr)) && (localVarRx < datalength) && (TxAllowed==0))
            {
                readdata[localVarRx] = LL_SPI_ReceiveData8((SPI_TypeDef *)SPIModuleHandle->PeripheralPtr);
                //ret |= (uint16_T)LL_SPI_IsActiveFlag_OVR((SPI_TypeDef *)SPIModuleHandle->PeripheralPtr);
                localVarRx++;
                TxAllowed = 1;
            }
            else
            {
                if(returnTimeElapsed(initialTime, 1) > Timeout)
                {
                    ret = MW_SPI_BUSY;
                    goto error;
                }
            }
        }
    }
    else if(FIFO_ACCESS_16BIT == (MW_STM32_SPI_FIFO_Access_type)fifo_access)
    {
        uint16_T *readdata = (uint16_T*) rdData;
        uint16_T *writedata = (uint16_T*) wrData;
        localVarTx = 0;
        localVarRx = 0;
        while (localVarTx < datalength || localVarRx < datalength)
        {
            if((1 == LL_SPI_IsActiveFlag_TXE ((SPI_TypeDef *)SPIModuleHandle->PeripheralPtr)) && (TxAllowed==1) && (localVarTx < datalength))
            {
                LL_SPI_TransmitData16((SPI_TypeDef *)SPIModuleHandle->PeripheralPtr, writedata[localVarTx]);
                localVarTx++;
                TxAllowed = 0;
            }
            else
            {
                if(returnTimeElapsed(initialTime, 1) > Timeout)
                {
                    ret = MW_SPI_BUSY;
                    goto error;
                }
            }
            if((1 == LL_SPI_IsActiveFlag_RXNE((SPI_TypeDef *)SPIModuleHandle->PeripheralPtr)) && (localVarRx < datalength) && (TxAllowed==0))
            {
                readdata[localVarRx] = LL_SPI_ReceiveData16((SPI_TypeDef *)SPIModuleHandle->PeripheralPtr);
                //ret |= (uint16_T)LL_SPI_IsActiveFlag_OVR((SPI_TypeDef *)SPIModuleHandle->PeripheralPtr);
                localVarRx++;
                TxAllowed = 1;
            }
            else
            {
                if(returnTimeElapsed(initialTime, 1) > Timeout)
                {
                    ret = MW_SPI_BUSY;
                    goto error;
                }
            }
        }
    }

    error:
    if(LL_SPI_GetMode((SPI_TypeDef *)SPIModuleHandle->PeripheralPtr)==LL_SPI_MODE_MASTER)
    {while(LL_SPI_IsActiveFlag_BSY((SPI_TypeDef *)SPIModuleHandle->PeripheralPtr)){}
    }
    return (MW_SPI_Status_Type)ret;
    #else
    return -1;
    #endif
}
#endif
#if defined(STM32H7) || defined(STM32U5)
__STATIC_INLINE void MW_SPI_Disable(SPI_TypeDef *SPIx)
{
    if(LL_SPI_IsEnabled(SPIx)){
        if((LL_SPI_GetMode(SPIx)==LL_SPI_MODE_MASTER))
        {
            if((LL_SPI_GetTransferDirection(SPIx)==LL_SPI_HALF_DUPLEX_RX))
            {
                LL_SPI_SuspendMasterTransfer(SPIx);
                while((LL_SPI_IsActiveFlag_RXWNE(SPIx)>0) || (LL_SPI_GetRxFIFOPackingLevel(SPIx)>0) || (LL_SPI_IsActiveFlag_RXP(SPIx)>0))
                {
                    LL_SPI_ReceiveData8(SPIx);
                }
                LL_SPI_Disable(SPIx);
            }
            else
            {
                while((LL_SPI_IsActiveFlag_TXC(SPIx)!=1) && (LL_SPI_IsActiveFlag_EOT(SPIx)!=1)){}
                while((LL_SPI_IsActiveFlag_RXWNE(SPIx)>0) || (LL_SPI_GetRxFIFOPackingLevel(SPIx)>0) || (LL_SPI_IsActiveFlag_RXP(SPIx)>0))
                {
                    LL_SPI_ReceiveData8(SPIx);
                }
                LL_SPI_Disable(SPIx);
            }
        }
        else
        {
            LL_SPI_Disable(SPIx);
        }
    }
}
#elif defined(STM32F4)
__STATIC_INLINE void MW_SPI_Disable(SPI_TypeDef *SPIx)
{
    if(LL_SPI_IsEnabled(SPIx)){
        if(LL_SPI_GetTransferDirection(SPIx)==LL_SPI_FULL_DUPLEX)
        {
            while(LL_SPI_IsActiveFlag_BSY(SPIx)){};
            LL_SPI_Disable(SPIx);
        }
        else if((LL_SPI_GetTransferDirection(SPIx)==LL_SPI_SIMPLEX_RX)||(LL_SPI_GetTransferDirection(SPIx)==LL_SPI_HALF_DUPLEX_RX))
        {
            LL_SPI_Disable(SPIx);
        }
        else
        {
            while(LL_SPI_IsActiveFlag_BSY(SPIx)){};
            LL_SPI_Disable(SPIx);
        }
    }
}
#else
__STATIC_INLINE void MW_SPI_Disable(SPI_TypeDef *SPIx)
{
    if(LL_SPI_IsEnabled(SPIx)){
        if((LL_SPI_GetMode(SPIx)==LL_SPI_MODE_MASTER))
        {
            if((LL_SPI_GetTransferDirection(SPIx)==LL_SPI_HALF_DUPLEX_RX))
            {
                LL_SPI_Disable(SPIx);
                while(LL_SPI_IsActiveFlag_BSY(SPIx));
                while(LL_SPI_GetRxFIFOLevel(SPIx)>0)
                {
                    LL_SPI_ReceiveData8(SPIx);
                }
            }
            else
            {
                while(LL_SPI_GetTxFIFOLevel(SPIx)>0);
                while(LL_SPI_IsActiveFlag_BSY(SPIx));
                LL_SPI_Disable(SPIx);
                while(LL_SPI_GetRxFIFOLevel(SPIx)>0)
                {
                    LL_SPI_ReceiveData8(SPIx);
                }
            }
        }
        else
        {
            LL_SPI_Disable(SPIx);
        }
    }
}
#endif
STM32_SPI_ModuleStruct_T * SPI_STM32_Init(STM32_SPI_ModuleStruct_T * spi_module);
void MW_STM32_EnableSPIx_Interrupts(STM32_SPI_ModuleStruct_T* SPIModuleHandle, uint16_T interruptsToEnable);
void MW_SPI_STM32_H7xx_FIFO_Init(STM32_SPI_ModuleStruct_T* SPIModuleHandle, uint16_T spiModule, uint16_T fifolevel);
MW_SPI_Status_Type MW_STM32_SPI_SetFormat(STM32_SPI_ModuleStruct_T* SPIModuleHandle, uint16_T spiModule,  uint32_T targetprecision, MW_SPI_Mode_type spi_mode);

#endif /* __MW_STM32_SPI_LL_H__ */

/* LocalWords:  OVR
*/
