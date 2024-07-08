/* Copyright 2021-2023 The MathWorks, Inc. */



#if defined(MW_LPUART1_ENABLED)

#include "MW_target_hardware_resources.h"

#include "main.h"
#include "stm_lpuart.h"
#include "string.h"


#if defined(LPUART1) && defined(MW_LPUART1_ENABLED)
UART_Type_T mw_lpuart1;
#if defined(MW_LPUART1_RX_DMA_ENABLED)
    #ifdef STM32H7
	    #if defined(MW_DCACHE_ENABLED)
		    uint8_T LPUART1ReceiveBuffer[MW_LPUART1_RECEIVE_BUFFER_SIZE] __attribute__((aligned (32))) __attribute__((section(".bdma_buffer"))) ;
	    #else
		    uint8_T LPUART1ReceiveBuffer[MW_LPUART1_RECEIVE_BUFFER_SIZE] __attribute__((section(".bdma_buffer"))) ;
	    #endif
    #elif defined(MW_DCACHE_ENABLED)
        uint8_T LPUART1ReceiveBuffer[MW_LPUART1_RECEIVE_BUFFER_SIZE] __attribute__((aligned (32)));
    #else
        uint8_T LPUART1ReceiveBuffer[MW_LPUART1_RECEIVE_BUFFER_SIZE];
    #endif
#endif 
#if defined(MW_LPUART1_TX_DMA_ENABLED)
    #ifdef STM32H7
	    #if defined(MW_DCACHE_ENABLED)
		    uint8_T LPUART1TransmitBuffer[MW_LPUART1_TRANSMIT_BUFFER_SIZE] __attribute__((aligned (32))) __attribute__((section(".bdma_buffer"))) ;
	    #else
	       uint8_T LPUART1TransmitBuffer[MW_LPUART1_TRANSMIT_BUFFER_SIZE] __attribute__((section(".bdma_buffer"))) ;
	    #endif
    #elif defined(MW_DCACHE_ENABLED)
        uint8_T LPUART1TransmitBuffer[MW_LPUART1_TRANSMIT_BUFFER_SIZE] __attribute__((aligned (32)));
    #else
        uint8_T LPUART1TransmitBuffer[MW_LPUART1_TRANSMIT_BUFFER_SIZE];
    #endif
#endif 
#endif


/* DMA RX Interrupt Handler */
void LPUART_RXDMAInterruptHandler(UART_Type_T *h ,uint32_t  (*checkActiveFlag)(DMA_TypeDef *DMAx),  void (*clearActiveFlag)(DMA_TypeDef *DMAx))
{
    /* Check transfer-complete interrupt */
    if (LL_DMA_IsEnabledIT_TC(h->rxdmaPeripheralPtr, h->rxdmastream) && (checkActiveFlag(h->rxdmaPeripheralPtr)))
        /* Clear transfer complete interrupt flag */
    {
        clearActiveFlag(h->rxdmaPeripheralPtr);
        if(h->buffer.writeRollOver == 1)
        {
            h->errorStatus =  h->errorStatus |  MW_SCI_RX_BUFFER_FULL;
            h->buffer.readPos = 0;
        }
        h->buffer.writeRollOver = 1;
		/* Start DMA again when DMA mode is Normal */
		if ((LL_DMA_MODE_NORMAL == LL_DMA_GetMode(h->rxdmaPeripheralPtr, h->rxdmastream)) && ( (h->disableDMAIntOnError == 0) ||
		                   ((h->disableDMAIntOnError == 1) && ((h->errorStatus == MW_SCI_SUCCESS) || (h->errorStatus == MW_SCI_RX_BUFFER_FULL)))))
		{
            #if defined(STM32G4) || defined(STM32L5) || defined(STM32WB) || defined(STM32L4)
            LL_DMA_DisableChannel(h->rxdmaPeripheralPtr, h->rxdmastream);
            #else
			LL_DMA_DisableStream(h->rxdmaPeripheralPtr, h->rxdmastream);
            #endif
			/* Set length to receive */
			LL_DMA_SetDataLength(h->rxdmaPeripheralPtr, h->rxdmastream, h->buffer.rxBufferSize);
			/* Start DMA again */
			#if defined(STM32G4) || defined(STM32L5) || defined(STM32WB) || defined(STM32L4)
            LL_DMA_EnableChannel(h->rxdmaPeripheralPtr, (uint32_t)h->rxdmastream);
            #else
            LL_DMA_EnableStream(h->rxdmaPeripheralPtr, (uint32_t)h->rxdmastream);
            #endif
		}
    }   
}
/* DMA RX Interrupt Handler */
#if defined(STM32H7) && defined(MW_LPUART1_ENABLED)
void LPUART_RXBDMAInterruptHandler(UART_Type_T *h ,uint32_t  (*checkActiveFlag)(BDMA_TypeDef *BDMAx),  void (*clearActiveFlag)(BDMA_TypeDef *BDMAx))
{
    /* Check transfer-complete interrupt */
    if (LL_BDMA_IsEnabledIT_TC(h->rxdmaPeripheralPtr, h->rxdmastream) && (checkActiveFlag(h->rxdmaPeripheralPtr)))
        /* Clear transfer complete interrupt flag */
    {
        clearActiveFlag(h->rxdmaPeripheralPtr);
        if(h->buffer.writeRollOver == 1)
        {
            h->errorStatus =  h->errorStatus |  MW_SCI_RX_BUFFER_FULL;
            h->buffer.readPos = 0;
        }
        h->buffer.writeRollOver = 1;
        /* Start DMA again when DMA mode is Normal */
        if ((LL_BDMA_MODE_NORMAL == LL_BDMA_GetMode(h->rxdmaPeripheralPtr, h->rxdmastream)) && ( (h->disableDMAIntOnError == 0) ||
                                                                                                ((h->disableDMAIntOnError == 1) && ((h->errorStatus == MW_SCI_SUCCESS) || (h->errorStatus == MW_SCI_RX_BUFFER_FULL)))))
        {
            LL_BDMA_DisableChannel(h->rxdmaPeripheralPtr, h->rxdmastream);
            /* Set length to receive */
            LL_BDMA_SetDataLength(h->rxdmaPeripheralPtr, h->rxdmastream, h->buffer.rxBufferSize);
            /* Start BDMA again */
            LL_BDMA_EnableChannel(h->rxdmaPeripheralPtr, h->rxdmastream);
        }
    }
}
#endif

/*DMA TX Interrupt Handler */
void LPUART_TXDMAInterruptHandler(UART_Type_T *h ,uint32_t  (*checkActiveFlag)(DMA_TypeDef *DMAx),  void (*clearActiveFlag)(DMA_TypeDef *DMAx))
{
    /* Check transfer-complete interrupt */
    if (LL_DMA_IsEnabledIT_TC(h->txdmaPeripheralPtr, h->txdmastream) && (checkActiveFlag(h->txdmaPeripheralPtr)))
        /* Clear transfer complete interrupt flag */
    {
        clearActiveFlag(h->txdmaPeripheralPtr);
    /* Start DMA again when DMA mode is Normal */
		if (LL_DMA_MODE_NORMAL == LL_DMA_GetMode(h->txdmaPeripheralPtr, h->txdmastream))
		{
			/* Data equal to h->txDMATransferLength has been transmitted so update the h->sentPos */
			h->buffer.sentPos = h->buffer.sentPos + h->txDMATransferLength;
			if(h->buffer.sentPos == h->buffer.txBufferSize)
			{
				h->buffer.sentPos = 0;
			}
			h->txdmaEnabled = 0;

			/*If buffer not empty, then start the DMA with length equal to length of data in buffer */
			if(h->buffer.sentPos < h->buffer.writePos)
			{
				h->txDMATransferLength = h->buffer.writePos - h->buffer.sentPos;
                #if defined(STM32G4) || defined(STM32L5) || defined(STM32WB) || defined(STM32L4)
                LL_DMA_DisableChannel(h->txdmaPeripheralPtr, h->txdmastream);
                #else
				LL_DMA_DisableStream(h->txdmaPeripheralPtr, h->txdmastream);
                #endif
				LL_DMA_SetMemoryAddress(h->txdmaPeripheralPtr, (uint32_t)h->txdmastream, (uint32_t)(h->buffer.txBufferPtr +  h->buffer.sentPos));
				LL_DMA_SetDataLength(h->txdmaPeripheralPtr, (uint32_t)h->txdmastream, h->txDMATransferLength);
                #if defined(MW_DCACHE_ENABLED) // Clean cache if enabled before starting DMA
                SCB_CleanDCache_by_Addr((uint32_t *)&h->buffer.txBufferPtr[0], h->buffer.txBufferSize);
                #endif
                #if defined(STM32G4) || defined(STM32L5) || defined(STM32WB) || defined(STM32L4)
                LL_DMA_EnableChannel(h->txdmaPeripheralPtr, (uint32_t)h->txdmastream);
                #else
                LL_DMA_EnableStream(h->txdmaPeripheralPtr, (uint32_t)h->txdmastream);
                #endif
				h->txdmaEnabled = 1;
			}
			else if(h->buffer.sentPos > h->buffer.writePos)
			{
				h->txDMATransferLength = h->buffer.txBufferSize - h->buffer.sentPos;
				#if defined(STM32G4) || defined(STM32L5) || defined(STM32WB) || defined(STM32L4)
                LL_DMA_DisableChannel(h->txdmaPeripheralPtr, h->txdmastream);
                #else
				LL_DMA_DisableStream(h->txdmaPeripheralPtr, h->txdmastream);
                #endif
				LL_DMA_SetMemoryAddress(h->txdmaPeripheralPtr, (uint32_t)h->txdmastream, (uint32_t)(h->buffer.txBufferPtr +  h->buffer.sentPos));
				LL_DMA_SetDataLength(h->txdmaPeripheralPtr, (uint32_t)h->txdmastream, h->txDMATransferLength);
                #if defined(MW_DCACHE_ENABLED)  // Clean cache if enabled before starting DMA
                SCB_CleanDCache_by_Addr((uint32_t *)&h->buffer.txBufferPtr[0], h->buffer.txBufferSize);
                #endif                
                #if defined(STM32G4) || defined(STM32L5) || defined(STM32WB) || defined(STM32L4)
                LL_DMA_EnableChannel(h->txdmaPeripheralPtr, (uint32_t)h->txdmastream);
                #else
                LL_DMA_EnableStream(h->txdmaPeripheralPtr, (uint32_t)h->txdmastream);
                #endif
				h->txdmaEnabled = 1;
			}
		}
	}
}

#if defined(STM32H7) && defined(MW_LPUART1_ENABLED)
void LPUART_TXBDMAInterruptHandler(UART_Type_T *h ,uint32_t  (*checkActiveFlag)(BDMA_TypeDef *BDMAx),  void (*clearActiveFlag)(BDMA_TypeDef *BDMAx))
{
    /* Check transfer-complete interrupt */
    if (LL_BDMA_IsEnabledIT_TC(h->txdmaPeripheralPtr, h->txdmastream) && (checkActiveFlag(h->txdmaPeripheralPtr)))
        /* Clear transfer complete interrupt flag */
    {
        clearActiveFlag(h->txdmaPeripheralPtr);
        /* Start DMA again when DMA mode is Normal */
        if (LL_BDMA_MODE_NORMAL == LL_BDMA_GetMode(h->txdmaPeripheralPtr, h->txdmastream))
        {
            /* Data equal to h->txDMATransferLength has been transmitted so update the h->sentPos */
            h->buffer.sentPos = h->buffer.sentPos + h->txDMATransferLength;
            if(h->buffer.sentPos == h->buffer.txBufferSize)
            {
                h->buffer.sentPos = 0;
            }
            h->txdmaEnabled = 0;

            /*If buffer not empty, then start the DMA with length equal to length of data in buffer */
            if(h->buffer.sentPos < h->buffer.writePos)
            {
                h->txDMATransferLength = h->buffer.writePos - h->buffer.sentPos;
                LL_BDMA_DisableChannel(h->txdmaPeripheralPtr, h->txdmastream);
                LL_BDMA_SetMemoryAddress(h->txdmaPeripheralPtr, (uint32_t)h->txdmastream, (uint32_t)(h->buffer.txBufferPtr +  h->buffer.sentPos));
                LL_BDMA_SetDataLength(h->txdmaPeripheralPtr, (uint32_t)h->txdmastream, h->txDMATransferLength);
                #if defined(MW_DCACHE_ENABLED)// Clean cache if enabled before starting DMA                
                SCB_CleanDCache_by_Addr((uint32_t *)&h->buffer.txBufferPtr[0], h->buffer.txBufferSize);
                #endif
                LL_BDMA_EnableChannel(h->txdmaPeripheralPtr, (uint32_t)h->txdmastream);
                h->txdmaEnabled = 1;
            }
            else if(h->buffer.sentPos > h->buffer.writePos)
            {
                h->txDMATransferLength = h->buffer.txBufferSize - h->buffer.sentPos;
                LL_BDMA_DisableChannel(h->txdmaPeripheralPtr, h->txdmastream);
                LL_BDMA_SetMemoryAddress(h->txdmaPeripheralPtr, (uint32_t)h->txdmastream, (uint32_t)(h->buffer.txBufferPtr +  h->buffer.sentPos));
                LL_BDMA_SetDataLength(h->txdmaPeripheralPtr, (uint32_t)h->txdmastream, h->txDMATransferLength);
                #if defined(MW_DCACHE_ENABLED) // Clean cache if enabled before starting DMA
                SCB_CleanDCache_by_Addr((uint32_t *)&h->buffer.txBufferPtr[0], h->buffer.txBufferSize);
                #endif                
                LL_BDMA_EnableChannel(h->txdmaPeripheralPtr, (uint32_t)h->txdmastream);
                h->txdmaEnabled = 1;
            }
        }
    }
}
#endif

/* Check if RXNE flag is active */
uint8_T LPUART_IsActiveFlagRXNE(UART_Type_T *h)
{
    uint8_T ret = (uint8_T)LL_LPUART_IsActiveFlag_RXNE(h->peripheralPtr) || (uint8_T)LL_LPUART_IsActiveFlag_ORE(h->peripheralPtr);
    if(1 == ret)
    {
        // Store if any error occured
        // Clear RXNE flag by reading the data
        if((h->buffer.writeRollOver == 1) && (h->buffer.toReadPos == h->buffer.readPos) )
        {
            h->buffer.readPos++;
            if(h->buffer.readPos == h->buffer.rxBufferSize)
            {
                h->buffer.readPos = 0;
            }
            h->errorStatus =  h->errorStatus |  MW_SCI_RX_BUFFER_FULL;
        }
        LPUART_IsActiveFlagError(h);
        h->buffer.rxBufferPtr[h->buffer.toReadPos] = LL_LPUART_ReceiveData8((USART_TypeDef*)h->peripheralPtr) ;
        //Update the readPos
        if((h->buffer.toReadPos + 1) == h->buffer.rxBufferSize)
        {
            h->buffer.toReadPos  = 0;
            h->buffer.writeRollOver = 1;
        }
        else
        {
            h->buffer.toReadPos++;
        }
    }
    return ret;
}

/*Check if error flag is active */
void LPUART_IsActiveFlagError(UART_Type_T *h)
{
    uint8_T ret = 0;
   
    if(1 == LL_LPUART_IsActiveFlag_ORE(h->peripheralPtr))
    {
        h->errorStatus = h->errorStatus | MW_SCI_ORE_ERROR;
        ret = 1;
    }
    if(1 == LL_LPUART_IsActiveFlag_FE(h->peripheralPtr))
    {
        h->errorStatus = h->errorStatus | MW_SCI_FRAME_ERROR;
        ret = 1;
    }
    if(1 == LL_LPUART_IsActiveFlag_NE(h->peripheralPtr))
    {
        h->errorStatus = h->errorStatus | MW_SCI_NOISE_ERROR;
        ret = 1;
    }
    if(1 == LL_LPUART_IsActiveFlag_PE(h->peripheralPtr))
    {
        h->errorStatus = h->errorStatus | MW_SCI_PARITY_ERROR;
        ret = 1;
    }
    
    if(ret == 1)
    {
        if(h->disableDMAIntOnError == 1)
        {
            if((h->mode & UART_RX_INTERRUPT_MODE) == UART_RX_INTERRUPT_MODE)
            {
                LL_LPUART_DisableIT_RXNE(h->peripheralPtr);
            }
            else
            {
                LL_LPUART_DisableDMAReq_RX(h->peripheralPtr);
            }
        }
        LL_LPUART_ClearFlag_PE(h->peripheralPtr); //Clearing this flag will clear all ORE,NE,FE and PE flags

        
        LL_LPUART_ClearFlag_ORE(h->peripheralPtr);
        LL_LPUART_ClearFlag_FE(h->peripheralPtr);
        LL_LPUART_ClearFlag_NE(h->peripheralPtr);
    }
}

/* Check if TXE flag is active*/
uint8_T LPUART_IsActiveFlagTXE(UART_Type_T *h)
{
    uint8_T ret = (uint8_T)LL_LPUART_IsActiveFlag_TXE(h->peripheralPtr);
    if(1 == ret)
    {
        /*If buffer is not empty, transmit a byte and update sentPos */
        if (h->buffer.sentPos != h->buffer.writePos)
        {
            LL_LPUART_TransmitData8((USART_TypeDef*)h->peripheralPtr,h->buffer.txBufferPtr[h->buffer.sentPos]);

            if((h->buffer.sentPos + 1) == h->buffer.txBufferSize)
            {
                h->buffer.sentPos = 0;
            }
            else
            {
                h->buffer.sentPos++;
            }
        }
        else /*Disable TXE interrupt if buffer is empty */
        {
            LL_LPUART_DisableIT_TXE(h->peripheralPtr);
            h->txeEnabled = 0;
        }
    }
    return ret;
}


#if defined(MW_LPUART1_RXNE_INTERRUPT_ENABLED ) || defined(MW_LPUART1_TXE_INTERRUPT_ENABLED ) || defined(MW_LPUART1_RX_DMA_ENABLED)
void LPUART1_IRQHandler(void)
{
    #ifdef MW_LPUART1_RXNE_INTERRUPT_ENABLED
    LPUART_IsActiveFlagRXNE(&mw_lpuart1);
    #endif

    #if  defined(MW_LPUART1_RX_DMA_ENABLED)
    LPUART_IsActiveFlagError(&mw_lpuart1);
    #endif

    #ifdef MW_LPUART1_TXE_INTERRUPT_ENABLED
    LPUART_IsActiveFlagTXE(&mw_lpuart1);
    #endif
}
#endif


#ifdef MW_LPUART1_TX_DMA_ENABLED
GETIRQ_NAME(MW_LPUART1_TX_DMA_ENABLED)
{
    #ifdef STM32H7
    LPUART_TXBDMAInterruptHandler(&mw_lpuart1, GETFCN_LL_GET_STREAM_BDMA_ACTIVEFLAG(MW_LPUART1_TX_DMA_STREAM), GETFCN_LL_CLEAR_STREAM_BDMA_ACTIVEFLAG(MW_LPUART1_TX_DMA_STREAM));
    #else
    LPUART_TXDMAInterruptHandler(&mw_lpuart1, GETFCN_LL_GET_STREAM_ACTIVEFLAG(MW_LPUART1_TX_DMA_STREAM), GETFCN_LL_CLEAR_STREAM_ACTIVEFLAG(MW_LPUART1_TX_DMA_STREAM));
    #endif
}
#endif

#ifdef MW_LPUART1_RX_DMA_ENABLED
GETIRQ_NAME(MW_LPUART1_RX_DMA_ENABLED)
{
    #ifdef STM32H7
    LPUART_RXBDMAInterruptHandler(&mw_lpuart1, GETFCN_LL_GET_STREAM_BDMA_ACTIVEFLAG(MW_LPUART1_RX_DMA_STREAM), GETFCN_LL_CLEAR_STREAM_BDMA_ACTIVEFLAG(MW_LPUART1_RX_DMA_STREAM));
    #else
    LPUART_RXDMAInterruptHandler(&mw_lpuart1, GETFCN_LL_GET_STREAM_ACTIVEFLAG(MW_LPUART1_RX_DMA_STREAM), GETFCN_LL_CLEAR_STREAM_ACTIVEFLAG(MW_LPUART1_RX_DMA_STREAM));
    #endif
}
#endif
/**************Internal Functions ****************************************************************************/

/*Configure UART Receive DMA */
void LPUART_ConfigureReceiveDMA(UART_Type_T *h)
{
    if (1 == LL_LPUART_IsEnabled(h->peripheralPtr))
    {
         /* Disable USART */
        LL_LPUART_Disable(h->peripheralPtr);
        LL_DMA_ConfigAddresses(h->rxdmaPeripheralPtr, (uint32_t)h->rxdmastream, 
                               LL_LPUART_DMA_GetRegAddr(h->peripheralPtr, LL_LPUART_DMA_REG_DATA_RECEIVE),
                               (uint32_t)h->buffer.rxBufferPtr, LL_DMA_DIRECTION_PERIPH_TO_MEMORY);
        LL_DMA_SetDataLength(h->rxdmaPeripheralPtr, (uint32_t)h->rxdmastream, h->buffer.rxBufferSize);

        /* Enable TC interrupts */
        LL_DMA_EnableIT_TC(h->rxdmaPeripheralPtr, (uint32_t)h->rxdmastream);
        /* Enable DMA */
        LL_LPUART_EnableDMAReq_RX(h->peripheralPtr);
        ((USART_TypeDef *)h->peripheralPtr)->CR3 |= USART_CR3_DMAR;
        /* Enable USART and DMA Stream */
        #if defined(STM32G4) || defined(STM32L5) || defined(STM32WB) || defined(STM32L4)
        LL_DMA_EnableChannel(h->rxdmaPeripheralPtr, (uint32_t)h->rxdmastream);
        #else
        LL_DMA_EnableStream(h->rxdmaPeripheralPtr, (uint32_t)h->rxdmastream);
        #endif
        LL_LPUART_Enable(h->peripheralPtr);
    }

}

#if defined(STM32H7) && defined(MW_LPUART1_ENABLED)
void LPUART_ConfigureReceiveBDMA(UART_Type_T *h)
{
    if (1 == LL_LPUART_IsEnabled(h->peripheralPtr))
    {
        /* Disable USART */
        LL_LPUART_Disable(h->peripheralPtr);
        LL_BDMA_SetPeriphAddress(h->rxdmaPeripheralPtr, (uint32_t)h->rxdmastream, (uint32_t)(&((USART_TypeDef *)(h->peripheralPtr))->RDR));
        LL_BDMA_SetMemoryAddress(h->rxdmaPeripheralPtr, (uint32_t)h->rxdmastream, (uint32_t)h->buffer.rxBufferPtr);
        LL_BDMA_SetDataLength(h->rxdmaPeripheralPtr, (uint32_t)h->rxdmastream, h->buffer.rxBufferSize);

        /* Enable TC interrupts */
        LL_BDMA_EnableIT_TC(h->rxdmaPeripheralPtr, (uint32_t)h->rxdmastream);
        /* Enable DMA */
        LL_LPUART_EnableDMAReq_RX(h->peripheralPtr);
        /* Enable USART and DMA Stream */
        LL_BDMA_EnableChannel(h->rxdmaPeripheralPtr, (uint32_t)h->rxdmastream);
        LL_LPUART_Enable(h->peripheralPtr);
    }

}
#endif

/*Configure UART Transmit DMA */
void LPUART_ConfigureTransmitDMA(UART_Type_T *h)
{
     if (1 == LL_LPUART_IsEnabled(h->peripheralPtr))
    {
        /* Disable USART */
        LL_LPUART_Disable(h->peripheralPtr);
        LL_DMA_ConfigAddresses(h->txdmaPeripheralPtr, (uint32_t)h->txdmastream, 
        					   (uint32_t)h->buffer.txBufferPtr,  
                               LL_LPUART_DMA_GetRegAddr(h->peripheralPtr, LL_LPUART_DMA_REG_DATA_TRANSMIT),
                               LL_DMA_DIRECTION_MEMORY_TO_PERIPH);

        /* Enable  TC interrupts */
        LL_DMA_EnableIT_TC(h->txdmaPeripheralPtr, (uint32_t)h->txdmastream);
        /* Enable DMA */
        LL_LPUART_EnableDMAReq_TX(h->peripheralPtr);
        /* Enable USART and DMA */
        LL_LPUART_Enable(h->peripheralPtr);
    }
}

#if defined(STM32H7) && defined(MW_LPUART1_ENABLED)
void LPUART_ConfigureTransmitBDMA(UART_Type_T *h)
{
    if (1 == LL_LPUART_IsEnabled(h->peripheralPtr))
    {
        /* Disable USART */
        LL_LPUART_Disable(h->peripheralPtr);
        LL_BDMA_SetPeriphAddress(h->txdmaPeripheralPtr, (uint32_t)h->txdmastream, (uint32_t)(&((USART_TypeDef *)(h->peripheralPtr))->TDR));
        LL_BDMA_SetMemoryAddress(h->txdmaPeripheralPtr, (uint32_t)h->txdmastream, (uint32_t)h->buffer.txBufferPtr);

        /* Enable  TC interrupts */
        LL_BDMA_EnableIT_TC(h->txdmaPeripheralPtr, (uint32_t)h->txdmastream);
        /* Enable DMA */
        LL_LPUART_EnableDMAReq_TX(h->peripheralPtr);
        /* Enable USART and DMA */
        LL_LPUART_Enable(h->peripheralPtr);
    }
}
#endif

uint16_T MW_LPUART_GetReadErrorStatus(UART_Type_T *h)
{
   uint16_T status = MW_SCI_SUCCESS;   
    if((h->errorStatus & MW_SCI_RX_BUFFER_FULL) == MW_SCI_RX_BUFFER_FULL) // If buffer is full, show in same step in interrupt mode
    {
        status = status |  MW_SCI_RX_BUFFER_FULL;
        h->errorStatus &= ~MW_SCI_RX_BUFFER_FULL;
    }

    if(h->disableDMAIntOnError == 0) // If h->disableDMAIntOnError is 0, output the error status if this step itself
    {
        status = status | h->errorStatus;
        h->errorStatus = MW_SCI_SUCCESS;
    }
    else if ((h->disableDMAIntOnError == 1) && (getAvailableDataInBuffer(h) == 0) && (h->errorStatus != MW_SCI_SUCCESS)) //Output error status only when last byte (erroneous) is read
    {
        status = status | h->errorStatus;
        h->errorStatus = MW_SCI_SUCCESS;
        if((h->mode & UART_RX_INTERRUPT_MODE) == UART_RX_INTERRUPT_MODE)
        {
            LL_LPUART_ReceiveData8((USART_TypeDef*)h->peripheralPtr);
            LL_LPUART_ClearFlag_ORE(h->peripheralPtr);
            LL_LPUART_EnableIT_RXNE(h->peripheralPtr);
        }
        else
        {
            LL_LPUART_ReceiveData8((USART_TypeDef*)h->peripheralPtr);
            LL_LPUART_ClearFlag_ORE(h->peripheralPtr);
            /* Enable DMA */
            LL_LPUART_EnableDMAReq_RX(h->peripheralPtr);
        }
    }
    return status ;
}


/* Initialize UART module */
UART_Type_T * MW_LPUART_Initialize(UART_Type_T  * SCIModule)
{
    UART_Type_T * mw_usart;
    switch ((uint32_t)((UART_Type_T *)SCIModule)->peripheralPtr)
    {
            #if defined(LPUART1) && defined(MW_LPUART1_ENABLED)
        case ((uint32_t)LPUART1):
            mw_usart = &mw_lpuart1;
            #if defined(MW_LPUART1_RX_DMA_ENABLED) || defined(MW_LPUART1_RXNE_INTERRUPT_ENABLED )|| defined(MW_LPUART1_TXE_INTERRUPT_ENABLED )
            NVIC_SetPriority(LPUART1_IRQn, NVIC_EncodePriority(NVIC_GetPriorityGrouping(),0, 0));
            NVIC_EnableIRQ(LPUART1_IRQn);
            #endif
            break;
            #endif
        default:
            mw_usart = NULL;
            break;
    }
	if (mw_usart != NULL)
	{
		mw_usart->enableRxOrTx |=  ((UART_Type_T *)SCIModule)->enableRxOrTx;
		mw_usart->mode |= ((UART_Type_T *)SCIModule)->mode;
		mw_usart->peripheralPtr = ((UART_Type_T *)SCIModule)->peripheralPtr;
		mw_usart->errorStatus = MW_SCI_SUCCESS;
		mw_usart->uartStatus =  MW_SCI_SUCCESS ;
		if (UART_ENABLE_RX == (((UART_Type_T *)SCIModule)->enableRxOrTx & UART_ENABLE_RX))
		{
			mw_usart->buffer.rxBufferSize = ((UART_Type_T *)SCIModule)->buffer.rxBufferSize;
			mw_usart->buffer.rxBufferPtr = ((UART_Type_T *)SCIModule)->buffer.rxBufferPtr;
			mw_usart->buffer.readPos = 0;
			mw_usart->buffer.toReadPos = 0;
			mw_usart->disableDMAIntOnError = ((UART_Type_T *)SCIModule)->disableDMAIntOnError;
			mw_usart->buffer.writeRollOver = 0;
			/* configure for DMA Rx */
			if ((mw_usart->mode & UART_RX_DMA_MODE) == UART_RX_DMA_MODE)
			{
				mw_usart->rxdmaPeripheralPtr = (DMA_TypeDef *)((UART_Type_T *)SCIModule)->rxdmaPeripheralPtr;
				mw_usart->rxdmastream = ((UART_Type_T *)SCIModule)->rxdmastream;
				#if defined(STM32H7)
                    LPUART_ConfigureReceiveBDMA(mw_usart);
                #else
					LPUART_ConfigureReceiveDMA(mw_usart);
				#endif
				LL_LPUART_EnableIT_ERROR(mw_usart->peripheralPtr);
				LL_LPUART_EnableIT_PE(mw_usart->peripheralPtr);
			}
			/*Configure interrupts for Rx with inetrrupts */
			else if ((mw_usart->mode & UART_RX_INTERRUPT_MODE) == UART_RX_INTERRUPT_MODE)
			{
				LL_LPUART_EnableIT_RXNE(mw_usart->peripheralPtr);
			}
		}
		if (UART_ENABLE_TX == (((UART_Type_T *)SCIModule)->enableRxOrTx & UART_ENABLE_TX))
		{
			mw_usart->buffer.txBufferSize = ((UART_Type_T *)SCIModule)->buffer.txBufferSize;
			mw_usart->buffer.txBufferPtr = ((UART_Type_T *)SCIModule)->buffer.txBufferPtr;
			mw_usart->buffer.writePos = 0;
			mw_usart->buffer.sentPos = 0;
			mw_usart->txeEnabled = 0;
			mw_usart->txdmaEnabled = 0;
			/* configure for DMA Tx */
			if ((mw_usart->mode & UART_TX_DMA_MODE) == UART_TX_DMA_MODE)
			{
				mw_usart->txdmaPeripheralPtr = (DMA_TypeDef *)((UART_Type_T *)SCIModule)->txdmaPeripheralPtr;
				mw_usart->txdmastream = ((UART_Type_T *)SCIModule)->txdmastream;
				mw_usart->txDMATransferLength = 0;
				#ifdef STM32H7
					LPUART_ConfigureTransmitBDMA(mw_usart);
				#else
					LPUART_ConfigureTransmitDMA(mw_usart);
				#endif
			}
		}
	}
    return mw_usart;
}

/* Receive the data over UART in Polling mode*/
MW_SCI_Status_Type MW_LPUART_ReceiveUsingPolling(UART_Type_T * h, void * RxDataPtr, uint32_T RxDataLength, uint32_T * receivedLength, uint32_T timeout)
{
    uint8_T *rxData = (uint8_T *)RxDataPtr;
     *receivedLength = 0;
    if(MW_SCI_RX_BUSY == (h->uartStatus & MW_SCI_RX_BUSY))
    {
        return MW_SCI_RX_BUSY;
    }
    else
    {
        h->uartStatus |= MW_SCI_RX_BUSY ;
        uint32_T dataCounter;
        uint16_T status =    MW_SCI_SUCCESS;
        uint32_T initialTime = 0;

        for (dataCounter = 0; dataCounter < RxDataLength; dataCounter++)
        {

            if (0 == LL_LPUART_IsActiveFlag_RXNE((USART_TypeDef*)h->peripheralPtr))
            {
                if (timeout > 0)
                {
                    initialTime = GET_CURRENT_TIME();
                    while ((0 == LL_LPUART_IsActiveFlag_RXNE((USART_TypeDef*)h->peripheralPtr)) && (returnTimeElapsed(initialTime, 1) <= (timeout)));
                    if (returnTimeElapsed(initialTime, 1) > (timeout) )
                    {
                        status = status | MW_SCI_DATA_NOT_AVAILABLE ;
                        h->uartStatus &= ~MW_SCI_RX_BUSY ;
                        return status;
                    }
                }
                else{
                    status = status | MW_SCI_DATA_NOT_AVAILABLE ;
                    h->uartStatus &= ~MW_SCI_RX_BUSY ;
                    return status;
                }
            }
            if(1 == LL_LPUART_IsActiveFlag_ORE(h->peripheralPtr))
            {
                status = status | MW_SCI_ORE_ERROR;
            }
            if(1 == LL_LPUART_IsActiveFlag_FE(h->peripheralPtr))
            {
                status = status | MW_SCI_FRAME_ERROR;
            }
            if(1 == LL_LPUART_IsActiveFlag_NE(h->peripheralPtr))
            {
                status = status | MW_SCI_NOISE_ERROR;
            }
            if(1 == LL_LPUART_IsActiveFlag_PE(h->peripheralPtr))
            {
                status = status | MW_SCI_PARITY_ERROR;
            }
            rxData[dataCounter] = LL_LPUART_ReceiveData8((USART_TypeDef*)h->peripheralPtr);
            if(status != MW_SCI_SUCCESS)
            {
                LL_LPUART_ClearFlag_PE(h->peripheralPtr); //Clearing this flag will clear all ORE,NE,FE and PE flags
            }
            (*receivedLength)++ ;

        }
        h->uartStatus &= ~MW_SCI_RX_BUSY ;
        return status;
    }
}

/* Receive the data over UART using DMA/Interrupt and buffer */
MW_SCI_Status_Type MW_LPUART_ReceiveUsingBuffer(UART_Type_T * h, void * RxDataPtr, uint32_T RxDataLength, uint32_T * receivedLength)
{
    *receivedLength = 0;
    if(MW_SCI_RX_BUSY == (h->uartStatus & MW_SCI_RX_BUSY))
    {
        return MW_SCI_RX_BUSY;
    }
    else
    {
        h->uartStatus |= MW_SCI_RX_BUSY ;
        MW_SCI_Status_Type status = readDataFromBuffer(h,(uint8_T *)RxDataPtr, RxDataLength, receivedLength);
        h->uartStatus &= ~MW_SCI_RX_BUSY ;
        return status ;
    }
}

/* Transmit the data over UART in Polling mode*/
MW_SCI_Status_Type MW_LPUART_TransmitUsingPolling(UART_Type_T * h, void * TxDataPtr, uint32_T TxDataLength, uint32_T timeout, uint32_T *sentDataLength)
{
    *sentDataLength = 0;
    uint8_T * TxData = (uint8_T *)TxDataPtr ;
    if(MW_SCI_TX_BUSY == (h->uartStatus & MW_SCI_TX_BUSY))
    {
        return MW_SCI_TX_BUSY;
    }
    else
    {
        h->uartStatus |= MW_SCI_TX_BUSY ;
        uint32_T dataCounter = 0;
        uint32_T initialTime = 0;


        for (dataCounter = 0; dataCounter < TxDataLength; dataCounter++)
        {
            if (0 == LL_LPUART_IsActiveFlag_TXE((USART_TypeDef*)h->peripheralPtr))
            {
                if (timeout > 0)
                {
                    initialTime = GET_CURRENT_TIME();
                    while ((0 == LL_LPUART_IsActiveFlag_TXE((USART_TypeDef*)h->peripheralPtr)) && (returnTimeElapsed(initialTime, 1) <= (timeout)));
                    if(returnTimeElapsed(initialTime, 1) > (timeout) )
                    {
                        *sentDataLength = dataCounter;
                        h->uartStatus &= ~MW_SCI_TX_BUSY ;
                        return MW_SCI_TX_FAILED;
                    }
                }
                else
                {
                    *sentDataLength = dataCounter;
                    h->uartStatus &= ~MW_SCI_TX_BUSY ;
                    return MW_SCI_TX_FAILED;
                }
            }
            LL_LPUART_TransmitData8((USART_TypeDef*)h->peripheralPtr,TxData[dataCounter]);
        }

        if (0 == LL_LPUART_IsActiveFlag_TC((USART_TypeDef*)h->peripheralPtr))
        {
            if (timeout > 0)
            {
                initialTime = GET_CURRENT_TIME();
                while ((0 == LL_LPUART_IsActiveFlag_TC((USART_TypeDef*)h->peripheralPtr)) &&  (returnTimeElapsed(initialTime, 1) <= (timeout)))
                    if (returnTimeElapsed(initialTime, 1) > (timeout) )
                    {
                        *sentDataLength = (TxDataLength - 1);
                        h->uartStatus &= ~MW_SCI_TX_BUSY ;
                        return MW_SCI_TX_FAILED;
                    }
            }
            else
            {
                *sentDataLength = (TxDataLength - 1);
                h->uartStatus &= ~MW_SCI_TX_BUSY ;
                return MW_SCI_TX_FAILED;
            }
        }
        *sentDataLength = TxDataLength;
        h->uartStatus &= ~MW_SCI_TX_BUSY ;
        return MW_SCI_SUCCESS;
    }
}

/* Trasmit the data over UART in Interrupt mode*/
MW_SCI_Status_Type MW_LPUART_TransmitUsingInterrupt(UART_Type_T * h, void * TxDataPtr, uint32_T TxDataLength, uint32_T timeout,uint32_T *sentDataLength)
{
    *sentDataLength = 0;
    if(MW_SCI_TX_BUSY == (h->uartStatus & MW_SCI_TX_BUSY))
    {
        return MW_SCI_TX_BUSY;
    }
    else
    {
        if (TxDataLength > 0)
        {
            h->uartStatus |= MW_SCI_TX_BUSY ;
            if(copyToTransmitBuffer(h,(uint8_T *)TxDataPtr,TxDataLength,timeout) == 1)
            {
                h->uartStatus &= ~MW_SCI_TX_BUSY ;
                return MW_SCI_TX_FAILED ;
            }
            if(h->txeEnabled == 0)
            {
                LL_LPUART_TransmitData8((USART_TypeDef*)h->peripheralPtr,h->buffer.txBufferPtr[h->buffer.sentPos]);
                if((h->buffer.sentPos + 1) == h->buffer.txBufferSize)
                {
                    h->buffer.sentPos = 0;
                }
                else
                {
                    h->buffer.sentPos++;
                }

                if(h->buffer.sentPos != h->buffer.writePos)
                {
                    h->txeEnabled = 1;
                    LL_LPUART_EnableIT_TXE(h->peripheralPtr);
                }
            }
            *sentDataLength = TxDataLength;
            h->uartStatus &= ~MW_SCI_TX_BUSY ;
        }
        return MW_SCI_SUCCESS;
    }
}

/* Trasmit the data over UART in DMA mode*/
MW_SCI_Status_Type MW_LPUART_TransmitUsingDMA(UART_Type_T * h, void * TxDataPtr, uint32_T TxDataLength, uint32_T timeout,uint32_T *sentDataLength)
{
    *sentDataLength = 0;
    if(MW_SCI_TX_BUSY == (h->uartStatus & MW_SCI_TX_BUSY))
    {
        return MW_SCI_TX_BUSY;
    }
    else
    {
        if (TxDataLength > 0)
        {
            h->uartStatus |= MW_SCI_TX_BUSY ;
            uint32_T intialWritePos = h->buffer.writePos ;
            if(copyToTransmitBuffer(h,(uint8_T *)TxDataPtr,TxDataLength,timeout) == 1)
            {
                h->uartStatus &= ~MW_SCI_TX_BUSY ;
                return MW_SCI_TX_FAILED ;
            }
            if(h->txdmaEnabled == 0)
            {
                if(h->buffer.writePos < h->buffer.sentPos)
                {
                    h->txDMATransferLength = h->buffer.txBufferSize - intialWritePos;
                }
                else
                {
                    h->txDMATransferLength = TxDataLength ;
                }
                h->txdmaEnabled = 1;
				#ifdef STM32H7
					LL_BDMA_DisableChannel(h->txdmaPeripheralPtr, h->txdmastream);
                    LL_BDMA_SetMemoryAddress(h->txdmaPeripheralPtr, (uint32_t)h->txdmastream, (uint32_t)(h->buffer.txBufferPtr +  h->buffer.sentPos));
                    LL_BDMA_SetDataLength(h->txdmaPeripheralPtr, (uint32_t)h->txdmastream,  h->txDMATransferLength);
                    #if defined(MW_DCACHE_ENABLED) // Clean cache if enabled before starting DMA
                    SCB_CleanDCache_by_Addr((uint32_t *)&h->buffer.txBufferPtr[0], h->buffer.txBufferSize);
                    #endif
                    LL_BDMA_EnableChannel(h->txdmaPeripheralPtr, (uint32_t)h->txdmastream);
				#else
					#if defined(STM32G4) || defined(STM32L5) || defined(STM32WB) || defined(STM32L4)
					LL_DMA_DisableChannel(h->txdmaPeripheralPtr, h->txdmastream);
					#else
					LL_DMA_DisableStream(h->txdmaPeripheralPtr, h->txdmastream);
					#endif
					LL_DMA_SetMemoryAddress(h->txdmaPeripheralPtr, (uint32_t)h->txdmastream, (uint32_t)(h->buffer.txBufferPtr +  h->buffer.sentPos));
					LL_DMA_SetDataLength(h->txdmaPeripheralPtr, (uint32_t)h->txdmastream,  h->txDMATransferLength);
                    #if defined(STM32G4) || defined(STM32L5) || defined(STM32WB) || defined(STM32L4)
					LL_DMA_EnableChannel(h->txdmaPeripheralPtr, (uint32_t)h->txdmastream);
					#else
					LL_DMA_EnableStream(h->txdmaPeripheralPtr, (uint32_t)h->txdmastream);
					#endif
				#endif
            }
            *sentDataLength = TxDataLength;
            h->uartStatus &= ~MW_SCI_TX_BUSY ;
        }
        return MW_SCI_SUCCESS;
    }

}

/* Release SCI module */
void MW_LPUART_DeInit(UART_Type_T * h)
{
    /* Disable USART */
    LL_LPUART_Disable(h->peripheralPtr);
    /*Disable Interrupts and DMA */
    if (UART_TX_DMA_MODE == (h->mode & UART_TX_DMA_MODE))
    {
		#ifdef STM32H7
			LL_BDMA_DisableIT_TC(h->txdmaPeripheralPtr, (uint32_t)h->txdmastream);
		#else
			LL_DMA_DisableIT_TC(h->txdmaPeripheralPtr, (uint32_t)h->txdmastream);
		#endif
        LL_LPUART_DisableDMAReq_TX(h->peripheralPtr);
    }
    else if(UART_TX_INTERRUPT_MODE == (h->mode & UART_TX_INTERRUPT_MODE))
    {
        LL_LPUART_DisableIT_TXE(h->peripheralPtr);
    }

    if (UART_RX_DMA_MODE == (h->mode & UART_RX_DMA_MODE))
    {
        LL_LPUART_DisableIT_ERROR(h->peripheralPtr);
        LL_LPUART_DisableIT_PE(h->peripheralPtr);
		#ifdef STM32H7
			            LL_BDMA_DisableIT_TC(h->rxdmaPeripheralPtr, (uint32_t)h->rxdmastream);

		#else 
			LL_DMA_DisableIT_TC(h->rxdmaPeripheralPtr, (uint32_t)h->rxdmastream);
		#endif
        LL_LPUART_DisableDMAReq_RX(h->peripheralPtr);
    }
    else if(UART_RX_INTERRUPT_MODE == (h->mode & UART_RX_INTERRUPT_MODE))
    {
        LL_LPUART_DisableIT_RXNE(h->peripheralPtr);
    }
}

#endif