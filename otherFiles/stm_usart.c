/* Copyright 2021-2023 The MathWorks, Inc. */


#include "MW_target_hardware_resources.h"

#include "main.h"

#include "stm_uart.h"


#include "string.h"

#if defined(MW_USART1_ENABLED) || defined(MW_USART2_ENABLED) || defined(MW_USART3_ENABLED) || defined(MW_UART4_ENABLED) || defined(MW_UART5_ENABLED) || defined(MW_USART6_ENABLED) || defined(MW_UART7_ENABLED) || defined(MW_UART8_ENABLED)
#define MW_USART_MODULES_ENABLED 1
#else
#define MW_USART_MODULES_ENABLED 0
#endif


#if defined(USART1) && defined(MW_USART1_ENABLED)
UART_Type_T mw_usart1;
#if defined(MW_USART1_RX_DMA_ENABLED)
#ifdef STM32H7
#if defined(MW_DCACHE_ENABLED)
uint8_T USART1ReceiveBuffer[MW_USART1_RECEIVE_BUFFER_SIZE] __attribute__((aligned (32))) __attribute__((section(".dma_buffer"))) ;
#else
uint8_T USART1ReceiveBuffer[MW_USART1_RECEIVE_BUFFER_SIZE] __attribute__((section(".dma_buffer"))) ;
#endif
#elif defined(MW_DCACHE_ENABLED)
uint8_T USART1ReceiveBuffer[MW_USART1_RECEIVE_BUFFER_SIZE] __attribute__((aligned (32)));
#else
uint8_T USART1ReceiveBuffer[MW_USART1_RECEIVE_BUFFER_SIZE];
#endif
#endif

#if defined(MW_USART1_TX_DMA_ENABLED)
#ifdef STM32H7
#if defined(MW_DCACHE_ENABLED)
uint8_T USART1TransmitBuffer[MW_USART1_TRANSMIT_BUFFER_SIZE] __attribute__((aligned (32))) __attribute__((section(".dma_buffer"))) ;
#else
uint8_T USART1TransmitBuffer[MW_USART1_TRANSMIT_BUFFER_SIZE] __attribute__((section(".dma_buffer"))) ;
#endif
#elif defined(MW_DCACHE_ENABLED)
uint8_T USART1TransmitBuffer[MW_USART1_TRANSMIT_BUFFER_SIZE] __attribute__((aligned (32)));
#else
uint8_T USART1TransmitBuffer[MW_USART1_TRANSMIT_BUFFER_SIZE];
#endif
#endif
#endif

#if defined(USART2) && defined(MW_USART2_ENABLED)
UART_Type_T mw_usart2;
#if defined(MW_USART2_RX_DMA_ENABLED)
#ifdef STM32H7
#if defined(MW_DCACHE_ENABLED)
uint8_T USART2ReceiveBuffer[MW_USART2_RECEIVE_BUFFER_SIZE] __attribute__((aligned (32))) __attribute__((section(".dma_buffer"))) ;
#else
uint8_T USART2ReceiveBuffer[MW_USART2_RECEIVE_BUFFER_SIZE] __attribute__((section(".dma_buffer"))) ;
#endif
#elif defined(MW_DCACHE_ENABLED)
uint8_T USART2ReceiveBuffer[MW_USART2_RECEIVE_BUFFER_SIZE] __attribute__((aligned (32)));
#else
uint8_T USART2ReceiveBuffer[MW_USART2_RECEIVE_BUFFER_SIZE];
#endif
#endif

#if defined(MW_USART2_TX_DMA_ENABLED)
#ifdef STM32H7
#if defined(MW_DCACHE_ENABLED)
uint8_T USART2TransmitBuffer[MW_USART2_TRANSMIT_BUFFER_SIZE] __attribute__((aligned (32))) __attribute__((section(".dma_buffer"))) ;
#else
uint8_T USART2TransmitBuffer[MW_USART2_TRANSMIT_BUFFER_SIZE] __attribute__((section(".dma_buffer"))) ;
#endif
#elif defined(MW_DCACHE_ENABLED)
uint8_T USART2TransmitBuffer[MW_USART2_TRANSMIT_BUFFER_SIZE] __attribute__((aligned (32)));
#else
uint8_T USART2TransmitBuffer[MW_USART2_TRANSMIT_BUFFER_SIZE];
#endif
#endif
#endif

#if defined(USART3) && defined(MW_USART3_ENABLED)
UART_Type_T mw_usart3;
#if defined(MW_USART3_RX_DMA_ENABLED)
#ifdef STM32H7
#if defined(MW_DCACHE_ENABLED)
uint8_T USART3ReceiveBuffer[MW_USART3_RECEIVE_BUFFER_SIZE] __attribute__((aligned (32))) __attribute__((section(".dma_buffer"))) ;
#else
uint8_T USART3ReceiveBuffer[MW_USART3_RECEIVE_BUFFER_SIZE] __attribute__((section(".dma_buffer"))) ;
#endif
#elif defined(MW_DCACHE_ENABLED)
uint8_T USART3ReceiveBuffer[MW_USART3_RECEIVE_BUFFER_SIZE] __attribute__((aligned (32)));
#else
uint8_T USART3ReceiveBuffer[MW_USART3_RECEIVE_BUFFER_SIZE];
#endif
#endif

#if defined(MW_USART3_TX_DMA_ENABLED)
#ifdef STM32H7
#if defined(MW_DCACHE_ENABLED)
uint8_T USART3TransmitBuffer[MW_USART3_TRANSMIT_BUFFER_SIZE] __attribute__((aligned (32))) __attribute__((section(".dma_buffer"))) ;
#else
uint8_T USART3TransmitBuffer[MW_USART3_TRANSMIT_BUFFER_SIZE] __attribute__((section(".dma_buffer"))) ;
#endif
#elif defined(MW_DCACHE_ENABLED)
uint8_T USART3TransmitBuffer[MW_USART3_TRANSMIT_BUFFER_SIZE] __attribute__((aligned (32)));
#else
uint8_T USART3TransmitBuffer[MW_USART3_TRANSMIT_BUFFER_SIZE];
#endif
#endif
#endif

#if defined(UART4) && defined(MW_UART4_ENABLED)
UART_Type_T mw_usart4;
#if defined(MW_UART4_RX_DMA_ENABLED)
#ifdef STM32H7
#if defined(MW_DCACHE_ENABLED)
uint8_T UART4ReceiveBuffer[MW_UART4_RECEIVE_BUFFER_SIZE] __attribute__((aligned (32))) __attribute__((section(".dma_buffer"))) ;
#else
uint8_T UART4ReceiveBuffer[MW_UART4_RECEIVE_BUFFER_SIZE] __attribute__((section(".dma_buffer"))) ;
#endif
#elif defined(MW_DCACHE_ENABLED)
uint8_T UART4ReceiveBuffer[MW_UART4_RECEIVE_BUFFER_SIZE] __attribute__((aligned (32)));
#else
uint8_T UART4ReceiveBuffer[MW_UART4_RECEIVE_BUFFER_SIZE];
#endif
#endif

#if defined(MW_UART4_TX_DMA_ENABLED)
#ifdef STM32H7
#if defined(MW_DCACHE_ENABLED)
uint8_T UART4TransmitBuffer[MW_UART4_TRANSMIT_BUFFER_SIZE] __attribute__((aligned (32))) __attribute__((section(".dma_buffer"))) ;
#else
uint8_T UART4TransmitBuffer[MW_UART4_TRANSMIT_BUFFER_SIZE] __attribute__((section(".dma_buffer"))) ;
#endif
#elif defined(MW_DCACHE_ENABLED)
uint8_T UART4TransmitBuffer[MW_UART4_TRANSMIT_BUFFER_SIZE] __attribute__((aligned (32)));
#else
uint8_T UART4TransmitBuffer[MW_UART4_TRANSMIT_BUFFER_SIZE];
#endif
#endif
#endif

#if defined(UART5) && defined(MW_UART5_ENABLED)
UART_Type_T mw_usart5;
#if defined(MW_UART5_RX_DMA_ENABLED)
#ifdef STM32H7
#if defined(MW_DCACHE_ENABLED)
uint8_T UART5ReceiveBuffer[MW_UART5_RECEIVE_BUFFER_SIZE] __attribute__((aligned (32))) __attribute__((section(".dma_buffer"))) ;
#else
uint8_T UART5ReceiveBuffer[MW_UART5_RECEIVE_BUFFER_SIZE] __attribute__((section(".dma_buffer"))) ;
#endif
#elif defined(MW_DCACHE_ENABLED)
uint8_T UART5ReceiveBuffer[MW_UART5_RECEIVE_BUFFER_SIZE] __attribute__((aligned (32)));
#else
uint8_T UART5ReceiveBuffer[MW_UART5_RECEIVE_BUFFER_SIZE];
#endif
#endif

#if defined(MW_UART5_TX_DMA_ENABLED)
#ifdef STM32H7
#if defined(MW_DCACHE_ENABLED)
uint8_T UART5TransmitBuffer[MW_UART5_TRANSMIT_BUFFER_SIZE] __attribute__((aligned (32))) __attribute__((section(".dma_buffer"))) ;
#else
uint8_T UART5TransmitBuffer[MW_UART5_TRANSMIT_BUFFER_SIZE] __attribute__((section(".dma_buffer"))) ;
#endif
#elif defined(MW_DCACHE_ENABLED)
uint8_T UART5TransmitBuffer[MW_UART5_TRANSMIT_BUFFER_SIZE] __attribute__((aligned (32)));
#else
uint8_T UART5TransmitBuffer[MW_UART5_TRANSMIT_BUFFER_SIZE];
#endif
#endif
#endif

#if defined(USART6) && defined(MW_USART6_ENABLED)
UART_Type_T mw_usart6;
#if defined(MW_USART6_RX_DMA_ENABLED)
#ifdef STM32H7
#if defined(MW_DCACHE_ENABLED)
uint8_T USART6ReceiveBuffer[MW_USART6_RECEIVE_BUFFER_SIZE] __attribute__((aligned (32))) __attribute__((section(".dma_buffer"))) ;
#else
uint8_T USART6ReceiveBuffer[MW_USART6_RECEIVE_BUFFER_SIZE] __attribute__((section(".dma_buffer"))) ;
#endif
#elif defined(MW_DCACHE_ENABLED)
uint8_T USART6ReceiveBuffer[MW_USART6_RECEIVE_BUFFER_SIZE] __attribute__((aligned (32)));
#else
uint8_T USART6ReceiveBuffer[MW_USART6_RECEIVE_BUFFER_SIZE];
#endif
#endif

#if defined(MW_USART6_TX_DMA_ENABLED)
#ifdef STM32H7
#if defined(MW_DCACHE_ENABLED)
uint8_T USART6TransmitBuffer[MW_USART6_TRANSMIT_BUFFER_SIZE] __attribute__((aligned (32))) __attribute__((section(".dma_buffer"))) ;
#else
uint8_T USART6TransmitBuffer[MW_USART6_TRANSMIT_BUFFER_SIZE] __attribute__((section(".dma_buffer"))) ;
#endif
#elif defined(MW_DCACHE_ENABLED)
uint8_T USART6TransmitBuffer[MW_USART6_TRANSMIT_BUFFER_SIZE] __attribute__((aligned (32)));
#else
uint8_T USART6TransmitBuffer[MW_USART6_TRANSMIT_BUFFER_SIZE];
#endif
#endif
#endif

#if defined(UART7) && defined(MW_UART7_ENABLED)
UART_Type_T mw_usart7;
#if defined(MW_UART7_RX_DMA_ENABLED)
#ifdef STM32H7
#if defined(MW_DCACHE_ENABLED)
uint8_T UART7ReceiveBuffer[MW_UART7_RECEIVE_BUFFER_SIZE] __attribute__((aligned (32))) __attribute__((section(".dma_buffer"))) ;
#else
uint8_T UART7ReceiveBuffer[MW_UART7_RECEIVE_BUFFER_SIZE] __attribute__((section(".dma_buffer"))) ;
#endif
#elif defined(MW_DCACHE_ENABLED)
uint8_T UART7ReceiveBuffer[MW_UART7_RECEIVE_BUFFER_SIZE] __attribute__((aligned (32)));
#else
uint8_T UART7ReceiveBuffer[MW_UART7_RECEIVE_BUFFER_SIZE];
#endif
#endif

#if defined(MW_UART7_TX_DMA_ENABLED)
#ifdef STM32H7
#if defined(MW_DCACHE_ENABLED)
uint8_T UART7TransmitBuffer[MW_UART7_TRANSMIT_BUFFER_SIZE] __attribute__((aligned (32))) __attribute__((section(".dma_buffer"))) ;
#else
uint8_T UART7TransmitBuffer[MW_UART7_TRANSMIT_BUFFER_SIZE] __attribute__((section(".dma_buffer"))) ;
#endif
#elif defined(MW_DCACHE_ENABLED)
uint8_T UART7TransmitBuffer[MW_UART7_TRANSMIT_BUFFER_SIZE] __attribute__((aligned (32)));
#else
uint8_T UART7TransmitBuffer[MW_UART7_TRANSMIT_BUFFER_SIZE];
#endif
#endif
#endif

#if defined(UART8) && defined(MW_UART8_ENABLED)
UART_Type_T mw_usart8;
#if defined(MW_UART8_RX_DMA_ENABLED)
#ifdef STM32H7
#if defined(MW_DCACHE_ENABLED)
uint8_T UART8ReceiveBuffer[MW_UART8_RECEIVE_BUFFER_SIZE] __attribute__((aligned (32))) __attribute__((section(".dma_buffer"))) ;
#else
uint8_T UART8ReceiveBuffer[MW_UART8_RECEIVE_BUFFER_SIZE] __attribute__((section(".dma_buffer"))) ;
#endif
#elif defined(MW_DCACHE_ENABLED)
uint8_T UART8ReceiveBuffer[MW_UART8_RECEIVE_BUFFER_SIZE] __attribute__((aligned (32)));
#else
uint8_T UART8ReceiveBuffer[MW_UART8_RECEIVE_BUFFER_SIZE];
#endif
#endif

#if defined(MW_UART8_TX_DMA_ENABLED)
#ifdef STM32H7
#if defined(MW_DCACHE_ENABLED)
uint8_T UART8TransmitBuffer[MW_UART8_TRANSMIT_BUFFER_SIZE] __attribute__((aligned (32))) __attribute__((section(".dma_buffer"))) ;
#else
uint8_T UART8TransmitBuffer[MW_UART8_TRANSMIT_BUFFER_SIZE] __attribute__((section(".dma_buffer"))) ;
#endif
#elif defined(MW_DCACHE_ENABLED)
uint8_T UART8TransmitBuffer[MW_UART8_TRANSMIT_BUFFER_SIZE] __attribute__((aligned (32)));
#else
uint8_T UART8TransmitBuffer[MW_UART8_TRANSMIT_BUFFER_SIZE];
#endif
#endif
#endif

#if defined(UART9) && defined(MW_UART9_ENABLED)
UART_Type_T mw_usart9;
#if defined(MW_UART9_RX_DMA_ENABLED)
#ifdef STM32H7
#if defined(MW_DCACHE_ENABLED)
uint8_T UART9ReceiveBuffer[MW_UART9_RECEIVE_BUFFER_SIZE] __attribute__((aligned (32))) __attribute__((section(".dma_buffer"))) ;
#else
uint8_T UART9ReceiveBuffer[MW_UART9_RECEIVE_BUFFER_SIZE] __attribute__((section(".dma_buffer"))) ;
#endif
#elif defined(MW_DCACHE_ENABLED)
uint8_T UART9ReceiveBuffer[MW_UART9_RECEIVE_BUFFER_SIZE] __attribute__((aligned (32)));
#else
uint8_T UART9ReceiveBuffer[MW_UART9_RECEIVE_BUFFER_SIZE];
#endif
#endif

#if defined(MW_UART9_TX_DMA_ENABLED)
#ifdef STM32H7
#if defined(MW_DCACHE_ENABLED)
uint8_T UART9TransmitBuffer[MW_UART9_TRANSMIT_BUFFER_SIZE] __attribute__((aligned (32))) __attribute__((section(".dma_buffer"))) ;
#else
uint8_T UART9TransmitBuffer[MW_UART9_TRANSMIT_BUFFER_SIZE] __attribute__((section(".dma_buffer"))) ;
#endif
#elif defined(MW_DCACHE_ENABLED)
uint8_T UART9TransmitBuffer[MW_UART9_TRANSMIT_BUFFER_SIZE] __attribute__((aligned (32)));
#else
uint8_T UART9TransmitBuffer[MW_UART9_TRANSMIT_BUFFER_SIZE];
#endif
#endif
#endif

#if defined(USART10) && defined(MW_USART10_ENABLED)
UART_Type_T mw_usart10;
#if defined(MW_USART10_RX_DMA_ENABLED)
#ifdef STM32H7
#if defined(MW_DCACHE_ENABLED)
uint8_T USART10ReceiveBuffer[MW_USART10_RECEIVE_BUFFER_SIZE] __attribute__((aligned (32))) __attribute__((section(".dma_buffer"))) ;
#else
uint8_T USART10ReceiveBuffer[MW_USART10_RECEIVE_BUFFER_SIZE] __attribute__((section(".dma_buffer"))) ;
#endif
#elif defined(MW_DCACHE_ENABLED)
uint8_T USART10ReceiveBuffer[MW_USART10_RECEIVE_BUFFER_SIZE] __attribute__((aligned (32)));
#else
uint8_T USART10ReceiveBuffer[MW_USART10_RECEIVE_BUFFER_SIZE];
#endif
#endif

#if defined(MW_USART10_TX_DMA_ENABLED)
#ifdef STM32H7
#if defined(MW_DCACHE_ENABLED)
uint8_T USART10TransmitBuffer[MW_USART10_TRANSMIT_BUFFER_SIZE] __attribute__((aligned (32))) __attribute__((section(".dma_buffer"))) ;
#else
uint8_T USART10TransmitBuffer[MW_USART10_TRANSMIT_BUFFER_SIZE] __attribute__((section(".dma_buffer"))) ;
#endif
#elif defined(MW_DCACHE_ENABLED)
uint8_T USART10TransmitBuffer[MW_USART10_TRANSMIT_BUFFER_SIZE] __attribute__((aligned (32)));
#else
uint8_T USART10TransmitBuffer[MW_USART10_TRANSMIT_BUFFER_SIZE];
#endif
#endif
#endif

/* Buffer functions */
/* Check if transmit buffer is full */
boolean_T checkIfTransmitBufferFull(UART_Type_T *h, uint32_T DataLength)
{
    uint32_T newWritePos = (h->buffer.writePos + DataLength);
    return ((( h->buffer.writePos < h->buffer.sentPos) && (newWritePos >= h->buffer.sentPos)) || ((( h->buffer.writePos >= h->buffer.sentPos)) && ((newWritePos >= h->buffer.txBufferSize) && ((newWritePos - h->buffer.txBufferSize) >= h->buffer.sentPos))) );
}


/* Copy data to Transmit internal buffer */
uint8_T copyToTransmitBuffer(UART_Type_T *h, uint8_T * txData, uint32_T DataLength, uint32_T timeout)
{
    if (checkIfTransmitBufferFull(h, DataLength))
    {
        if (timeout > 0)
        {
            uint32_T initialTime = GET_CURRENT_TIME() ;
            while (checkIfTransmitBufferFull(h, DataLength) && (returnTimeElapsed(initialTime, 1) <= (timeout)) );
            if (returnTimeElapsed(initialTime, 1) > (timeout) )
            {
                return 1;
            }
        }
        else
        {
            return 1;
        }
    }

    if (((h->buffer.writePos ) + DataLength) > h->buffer.txBufferSize)
    {
        int lengthToWriteFromBottom = (h->buffer.txBufferSize)-(h->buffer.writePos);
        memcpy(&h->buffer.txBufferPtr[h->buffer.writePos],txData,lengthToWriteFromBottom);
        h->buffer.writePos = (h->buffer.writePos + DataLength) - h->buffer.txBufferSize;
        memcpy(&h->buffer.txBufferPtr[0], (txData + lengthToWriteFromBottom),h->buffer.writePos);
    }
    else
    {
        memcpy(&h->buffer.txBufferPtr[h->buffer.writePos],txData,DataLength);
        h->buffer.writePos = (h->buffer.writePos + DataLength);
    }
    if(h->buffer.writePos == h->buffer.txBufferSize )
    {
        h->buffer.writePos = 0;
    }
    return 0;
}


uint32_T getAvailableDataInBuffer(UART_Type_T *h)
{
    uint32_T nbDataPos;
    uint32_T availableData;
    uint32_T dataToBeFilled;
    boolean_T flag1 = h->buffer.writeRollOver;
    if (UART_RX_INTERRUPT_MODE == (h->mode & UART_RX_INTERRUPT_MODE))
    {
        nbDataPos = h->buffer.toReadPos ;
    }
    else
    {
        #if defined(STM32H7) && defined(MW_LPUART1_ENABLED)
        if( LPUART1 == h->peripheralPtr)
        {
            dataToBeFilled = LL_BDMA_GetDataLength(h->rxdmaPeripheralPtr, (uint32_t)h->rxdmastream);
        }
        else
        {
            #endif
            #if defined (GPDMA1)
                dataToBeFilled = LL_DMA_GetBlkDataLength(h->rxdmaPeripheralPtr, (uint32_t)h->rxdmastream);
            #else
            dataToBeFilled = LL_DMA_GetDataLength(h->rxdmaPeripheralPtr, (uint32_t)h->rxdmastream);
            #endif
            #if defined(STM32H7) && defined(MW_LPUART1_ENABLED)
        }
        #endif
        nbDataPos = h->buffer.rxBufferSize - dataToBeFilled;
    }
    if (nbDataPos == h->buffer.rxBufferSize)
    {
        nbDataPos = 0;
    }
    /* Update read position to nbDataPos if buffer is overwritten in DMA mode i.e. read data which is not overwritten */
    if((1 == flag1) && (UART_RX_DMA_MODE == (h->mode & UART_RX_DMA_MODE)))
    {
        if(nbDataPos > h->buffer.readPos)
        {
            h->errorStatus =  h->errorStatus |  MW_SCI_RX_BUFFER_FULL;
            h->buffer.readPos = nbDataPos;
        }
    }
    if (nbDataPos > h->buffer.readPos)
    {
        /* No rollover condition */
        availableData = nbDataPos - h->buffer.readPos;
    }
    else if  (nbDataPos < h->buffer.readPos)
    {
        /* Rollover condition */
        availableData = (h->buffer.rxBufferSize - (h->buffer.readPos)) + nbDataPos;
    }
    else
    {
        if(1 == flag1)
        {
            availableData = h->buffer.rxBufferSize;
        }
        else
        {
            availableData = 0;
        }
    }
    return availableData;
}

/*Wait till timeout and return the number of bytes that can be read from the buffer */
uint32_T getBytesToBeReadFromBuffer(UART_Type_T *h, uint32_T RxDataLength, uint32_T timeout)
{
    uint32_T availableData = 0;
    uint32_T dataToRead;
    if((getAvailableDataInBuffer(h) < RxDataLength) && (timeout > 0))
    {
        uint32_T initialTime = GET_CURRENT_TIME();
        while ((getAvailableDataInBuffer(h) < RxDataLength) && (returnTimeElapsed(initialTime, 1) <= (timeout)));
    }

    availableData = getAvailableDataInBuffer(h);
    (availableData < RxDataLength) ? (dataToRead = availableData) :(dataToRead = RxDataLength);
    return dataToRead;
}

/*Read data from internal receive buffer */
uint16_T readDataFromBuffer(UART_Type_T *h, uint8_T * RxDataPtr, uint32_T dataToRead, uint32_T * receivedLength)
{
    *receivedLength = 0;
    uint16_T status = MW_SCI_SUCCESS;
    #if defined(MW_DCACHE_ENABLED) // Invalidate cache if enabled before reading data
    if (UART_RX_DMA_MODE == (h->mode & UART_RX_DMA_MODE))
    {
        SCB_InvalidateDCache_by_Addr((uint32_t *)&h->buffer.rxBufferPtr[0],   h->buffer.rxBufferSize);
    }
    #endif
    /* update read position */
    if (((h->buffer.readPos ) + dataToRead) > h->buffer.rxBufferSize)
    {
        int lengthToReadFromBottom = h->buffer.rxBufferSize-(h->buffer.readPos);
        memcpy(RxDataPtr,&h->buffer.rxBufferPtr[h->buffer.readPos],lengthToReadFromBottom);
        h->buffer.readPos = (h->buffer.readPos + dataToRead) - h->buffer.rxBufferSize;
        memcpy((RxDataPtr + lengthToReadFromBottom),&h->buffer.rxBufferPtr[0],h->buffer.readPos);
        h->buffer.writeRollOver = 0;
    }
    else
    {
        memcpy(RxDataPtr,&h->buffer.rxBufferPtr[h->buffer.readPos],dataToRead);
        h->buffer.readPos+=dataToRead;
    }
    if(h->buffer.readPos == h->buffer.rxBufferSize )
    {
        h->buffer.readPos = 0;
        h->buffer.writeRollOver = 0;
    }

    #if defined(MW_LPUART1_ENABLED)
    if ((uint32_t)LPUART1 == (uint32_t)h->peripheralPtr)
    {
        extern uint16_T MW_LPUART_GetReadErrorStatus(UART_Type_T *h);
        status = MW_LPUART_GetReadErrorStatus(h);
    }
    else
    {
        #if MW_USART_MODULES_ENABLED == 1
        status = getReadErrorStatus(h);
        #endif
    }
    #else
    status = getReadErrorStatus(h);
    #endif
    *receivedLength = dataToRead;
    return status;
}

#if MW_USART_MODULES_ENABLED == 1

/* DMA RX Interrupt Handler */
#if defined (GPDMA1)
    void UART_RXDMAInterruptHandler(UART_Type_T *h ,uint32_t  (*checkActiveFlag)(DMA_TypeDef *DMAx, uint32_t rxdmastream),  void (*clearActiveFlag)(DMA_TypeDef *DMAx, uint32_t rxdmastream))
#else
void UART_RXDMAInterruptHandler(UART_Type_T *h ,uint32_t  (*checkActiveFlag)(DMA_TypeDef *DMAx),  void (*clearActiveFlag)(DMA_TypeDef *DMAx))
#endif
{
    /* Check transfer-complete interrupt */
    #if defined (GPDMA1)    
    if (LL_DMA_IsEnabledIT_TC(h->rxdmaPeripheralPtr, h->rxdmastream) && (checkActiveFlag(h->rxdmaPeripheralPtr, h->rxdmastream)))
    #else
    if (LL_DMA_IsEnabledIT_TC(h->rxdmaPeripheralPtr, h->rxdmastream) && (checkActiveFlag(h->rxdmaPeripheralPtr)))
    #endif
        /* Clear transfer complete interrupt flag */
    {
        #if defined (GPDMA1)    
            clearActiveFlag(h->rxdmaPeripheralPtr, h->rxdmastream);
        #else
        clearActiveFlag(h->rxdmaPeripheralPtr);
        #endif
        if(h->buffer.writeRollOver == 1)
        {
            h->errorStatus =  h->errorStatus |  MW_SCI_RX_BUFFER_FULL;
            h->buffer.readPos = 0;
        }
        h->buffer.writeRollOver = 1;

        /* Start DMA again when DMA mode is Normal */

        #if defined(GPDMA1)
        if (( (h->disableDMAIntOnError == 0) || ((h->disableDMAIntOnError == 1) && ((h->errorStatus == MW_SCI_SUCCESS) || (h->errorStatus == MW_SCI_RX_BUFFER_FULL)))))
        #else
        if ((LL_DMA_MODE_NORMAL == LL_DMA_GetMode(h->rxdmaPeripheralPtr, h->rxdmastream)) && ( (h->disableDMAIntOnError == 0) ||
                                                                                              ((h->disableDMAIntOnError == 1) && ((h->errorStatus == MW_SCI_SUCCESS) || (h->errorStatus == MW_SCI_RX_BUFFER_FULL)))))
        #endif
        {
            #if defined(STM32G4) || defined(STM32WB) || defined(STM32L5)|| defined(STM32L4) || defined(STM32U5)
            LL_DMA_DisableChannel(h->rxdmaPeripheralPtr, h->rxdmastream);
            #else
            LL_DMA_DisableStream(h->rxdmaPeripheralPtr, h->rxdmastream);
            #endif
            /* Set length to receive */
            #if defined (GPDMA1)
                LL_DMA_SetDestAddress(h->rxdmaPeripheralPtr, (uint32_t)h->rxdmastream, (uint32_t)(h->buffer.rxBufferPtr));
                LL_DMA_SetBlkDataLength(h->rxdmaPeripheralPtr, h->rxdmastream, h->buffer.rxBufferSize);
            #else
            LL_DMA_SetDataLength(h->rxdmaPeripheralPtr, h->rxdmastream, h->buffer.rxBufferSize);
            #endif
            /* Start DMA again */
            #if defined(STM32G4) || defined(STM32WB) || defined(STM32L5)|| defined(STM32L4) || defined(STM32U5)
            LL_DMA_EnableChannel(h->rxdmaPeripheralPtr, (uint32_t)h->rxdmastream);
            #else
            LL_DMA_EnableStream(h->rxdmaPeripheralPtr, (uint32_t)h->rxdmastream);
            #endif
        }
    }
}

/*DMA TX Interrupt Handler */
#if defined(GPDMA1)
void UART_TXDMAInterruptHandler(UART_Type_T *h ,uint32_t  (*checkActiveFlag)(DMA_TypeDef *DMAx, uint32_t txdmastream),  void (*clearActiveFlag)(DMA_TypeDef *DMAx, uint32_t txdmastream))
#else
void UART_TXDMAInterruptHandler(UART_Type_T *h ,uint32_t  (*checkActiveFlag)(DMA_TypeDef *DMAx),  void (*clearActiveFlag)(DMA_TypeDef *DMAx))
#endif
{
    /* Check transfer-complete interrupt */
    #if defined(GPDMA1)
    if (LL_DMA_IsEnabledIT_TC(h->txdmaPeripheralPtr, h->txdmastream) && (checkActiveFlag(h->txdmaPeripheralPtr, h->txdmastream)))
        /* Clear transfer complete interrupt flag */
    {
        clearActiveFlag(h->txdmaPeripheralPtr, h->txdmastream);

    #else
    if (LL_DMA_IsEnabledIT_TC(h->txdmaPeripheralPtr, h->txdmastream) && (checkActiveFlag(h->txdmaPeripheralPtr)))
        /* Clear transfer complete interrupt flag */
    {
        clearActiveFlag(h->txdmaPeripheralPtr);
        /* Start DMA again when DMA mode is Normal */
        if (LL_DMA_MODE_NORMAL == LL_DMA_GetMode(h->txdmaPeripheralPtr, h->txdmastream))
    #endif
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
                #if defined(STM32G4) || defined(STM32WB) || defined(STM32L5)|| defined(STM32L4) || defined(STM32U5)
                LL_DMA_DisableChannel(h->txdmaPeripheralPtr, h->txdmastream);
                #else
                LL_DMA_DisableStream(h->txdmaPeripheralPtr, h->txdmastream);
                #endif
                #if defined (GPDMA1)
                    LL_DMA_SetSrcAddress(h->txdmaPeripheralPtr, (uint32_t)h->txdmastream, (uint32_t)(h->buffer.txBufferPtr +  h->buffer.sentPos));
                    LL_DMA_SetBlkDataLength(h->txdmaPeripheralPtr, (uint32_t)h->txdmastream, h->txDMATransferLength);
                #else
                LL_DMA_SetMemoryAddress(h->txdmaPeripheralPtr, (uint32_t)h->txdmastream, (uint32_t)(h->buffer.txBufferPtr +  h->buffer.sentPos));
                LL_DMA_SetDataLength(h->txdmaPeripheralPtr, (uint32_t)h->txdmastream, h->txDMATransferLength);
                #endif
                #if defined(MW_DCACHE_ENABLED) // Clean cache if enabled before starting DMA
                SCB_CleanDCache_by_Addr((uint32_t *)&h->buffer.txBufferPtr[0], h->buffer.txBufferSize);
                #endif
                #if defined(STM32G4) || defined(STM32WB) || defined(STM32L5)|| defined(STM32L4) || defined(STM32U5)
                LL_DMA_EnableChannel(h->txdmaPeripheralPtr, (uint32_t)h->txdmastream);
                #else
                LL_DMA_EnableStream(h->txdmaPeripheralPtr, (uint32_t)h->txdmastream);
                #endif
                h->txdmaEnabled = 1;
            }
            else if(h->buffer.sentPos > h->buffer.writePos)
            {
                h->txDMATransferLength = h->buffer.txBufferSize - h->buffer.sentPos;
                #if defined(STM32G4) || defined(STM32WB) || defined(STM32L5)|| defined(STM32L4) || defined(STM32U5)
                LL_DMA_DisableChannel(h->txdmaPeripheralPtr, h->txdmastream);
                #else
                LL_DMA_DisableStream(h->txdmaPeripheralPtr, h->txdmastream);
                #endif
                #if defined (GPDMA1)
                    LL_DMA_SetSrcAddress(h->txdmaPeripheralPtr, (uint32_t)h->txdmastream, (uint32_t)(h->buffer.txBufferPtr +  h->buffer.sentPos));
                    LL_DMA_SetBlkDataLength(h->txdmaPeripheralPtr, (uint32_t)h->txdmastream, h->txDMATransferLength);
                #else
                LL_DMA_SetMemoryAddress(h->txdmaPeripheralPtr, (uint32_t)h->txdmastream, (uint32_t)(h->buffer.txBufferPtr +  h->buffer.sentPos));
                LL_DMA_SetDataLength(h->txdmaPeripheralPtr, (uint32_t)h->txdmastream, h->txDMATransferLength);
                #endif
                #if defined(MW_DCACHE_ENABLED) // Clean cache if enabled before starting DMA
                SCB_CleanDCache_by_Addr((uint32_t *)&h->buffer.txBufferPtr[0], h->buffer.txBufferSize);
                #endif
                #if defined(STM32G4) || defined(STM32WB) || defined(STM32L5)|| defined(STM32L4) || defined(STM32U5)
                LL_DMA_EnableChannel(h->txdmaPeripheralPtr, (uint32_t)h->txdmastream);
                #else
                LL_DMA_EnableStream(h->txdmaPeripheralPtr, (uint32_t)h->txdmastream);
                #endif
                h->txdmaEnabled = 1;
            }
        }

    }
}


/* Check if RXNE flag is active */
uint8_T UART_IsActiveFlagRXNE(UART_Type_T *h)
{
    uint8_T ret = (uint8_T)LL_USART_IsActiveFlag_RXNE(h->peripheralPtr) || (uint8_T)LL_USART_IsActiveFlag_ORE(h->peripheralPtr);
    if(1 == ret)
    {
        // Store if any error occurred
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
        UART_IsActiveFlagError(h);
        h->buffer.rxBufferPtr[h->buffer.toReadPos] = LL_USART_ReceiveData8((USART_TypeDef*)h->peripheralPtr) ;
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
void UART_IsActiveFlagError(UART_Type_T *h)
{
    uint8_T ret = 0;

    if(1 == LL_USART_IsActiveFlag_ORE(h->peripheralPtr))
    {
        h->errorStatus = h->errorStatus | MW_SCI_ORE_ERROR;
        ret = 1;
    }
    if(1 == LL_USART_IsActiveFlag_FE(h->peripheralPtr))
    {
        h->errorStatus = h->errorStatus | MW_SCI_FRAME_ERROR;
        ret = 1;
    }
    if(1 == LL_USART_IsActiveFlag_NE(h->peripheralPtr))
    {
        h->errorStatus = h->errorStatus | MW_SCI_NOISE_ERROR;
        ret = 1;
    }
    if(1 == LL_USART_IsActiveFlag_PE(h->peripheralPtr))
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
                LL_USART_DisableIT_RXNE(h->peripheralPtr);
            }
            else
            {
                // LL_DMA_DisableStream(h->rxdmaPeripheralPtr, h->rxdmastream);
                LL_USART_DisableDMAReq_RX(h->peripheralPtr);
            }
        }
        LL_USART_ClearFlag_PE(h->peripheralPtr); //Clearing this flag will clear all ORE,NE,FE and PE flags

        #if defined(STM32F7) || defined(STM32G4) || defined(STM32H7) || defined(STM32WB) || defined(STM32L5) || defined(STM32L4) || defined(STM32U5)
        LL_USART_ClearFlag_ORE(h->peripheralPtr);
        LL_USART_ClearFlag_FE(h->peripheralPtr);
        LL_USART_ClearFlag_NE(h->peripheralPtr);
        #endif
    }
}

/* Check if TXE flag is active*/
uint8_T UART_IsActiveFlagTXE(UART_Type_T *h)
{
    uint8_T ret = (uint8_T)LL_USART_IsActiveFlag_TXE(h->peripheralPtr);
    if(1 == ret)
    {
        /*If buffer is not empty, transmit a byte and update sentPos */
        if (h->buffer.sentPos != h->buffer.writePos)
        {
            LL_USART_TransmitData8((USART_TypeDef*)h->peripheralPtr,h->buffer.txBufferPtr[h->buffer.sentPos]);

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
            LL_USART_DisableIT_TXE(h->peripheralPtr);
            h->txeEnabled = 0;
        }
    }
    return ret;
}
#if defined(MW_USART1_RXNE_INTERRUPT_ENABLED ) || defined(MW_USART1_TXE_INTERRUPT_ENABLED ) || defined(MW_USART1_RX_DMA_ENABLED)
void USART1_IRQHandler(void)
{
    #ifdef MW_USART1_RXNE_INTERRUPT_ENABLED
    UART_IsActiveFlagRXNE(&mw_usart1);
    #endif

    #if defined(MW_USART1_RX_DMA_ENABLED)
    UART_IsActiveFlagError(&mw_usart1);
    #endif

    #ifdef MW_USART1_TXE_INTERRUPT_ENABLED
    UART_IsActiveFlagTXE(&mw_usart1);
    #endif
}
#endif

#if defined(MW_USART2_RXNE_INTERRUPT_ENABLED ) || defined(MW_USART2_TXE_INTERRUPT_ENABLED ) || defined(MW_USART2_RX_DMA_ENABLED)
void USART2_IRQHandler(void)
{
    #ifdef MW_USART2_RXNE_INTERRUPT_ENABLED
    UART_IsActiveFlagRXNE(&mw_usart2);
    #endif

    #if defined(MW_USART2_RX_DMA_ENABLED)
    UART_IsActiveFlagError(&mw_usart2);
    #endif

    #ifdef MW_USART2_TXE_INTERRUPT_ENABLED
    UART_IsActiveFlagTXE(&mw_usart2);
    #endif
}
#endif

#if defined(MW_USART3_RXNE_INTERRUPT_ENABLED ) || defined(MW_USART3_TXE_INTERRUPT_ENABLED ) || defined(MW_USART3_RX_DMA_ENABLED)
void USART3_IRQHandler(void)
{
    #ifdef MW_USART3_RXNE_INTERRUPT_ENABLED
    UART_IsActiveFlagRXNE(&mw_usart3);
    #endif
    #if defined(MW_USART3_RX_DMA_ENABLED)
    UART_IsActiveFlagError(&mw_usart3);
    #endif

    #ifdef MW_USART3_TXE_INTERRUPT_ENABLED
    UART_IsActiveFlagTXE(&mw_usart3);
    #endif
}
#endif

#if defined(MW_UART4_RXNE_INTERRUPT_ENABLED ) || defined(MW_UART4_TXE_INTERRUPT_ENABLED ) || defined(MW_UART4_RX_DMA_ENABLED)
void UART4_IRQHandler(void)
{
    #ifdef MW_UART4_RXNE_INTERRUPT_ENABLED
    UART_IsActiveFlagRXNE(&mw_usart4);
    #endif

    #if  defined(MW_UART4_RX_DMA_ENABLED)
    UART_IsActiveFlagError(&mw_usart4);
    #endif

    #ifdef MW_UART4_TXE_INTERRUPT_ENABLED
    UART_IsActiveFlagTXE(&mw_usart4);
    #endif
}
#endif

#if defined(MW_UART5_RXNE_INTERRUPT_ENABLED ) || defined(MW_UART5_TXE_INTERRUPT_ENABLED )|| defined(MW_UART5_RX_DMA_ENABLED)
void UART5_IRQHandler(void)
{
    #ifdef MW_UART5_RXNE_INTERRUPT_ENABLED
    UART_IsActiveFlagRXNE(&mw_usart5);
    #endif

    #if defined(MW_UART5_RX_DMA_ENABLED)
    UART_IsActiveFlagError(&mw_usart5);
    #endif

    #ifdef MW_UART5_TXE_INTERRUPT_ENABLED
    UART_IsActiveFlagTXE(&mw_usart5);
    #endif
}
#endif

#if defined(MW_USART6_RXNE_INTERRUPT_ENABLED ) || defined(MW_USART6_TXE_INTERRUPT_ENABLED ) || defined(MW_USART6_RX_DMA_ENABLED)
void USART6_IRQHandler(void)
{
    #ifdef MW_USART6_RXNE_INTERRUPT_ENABLED
    UART_IsActiveFlagRXNE(&mw_usart6);
    #endif

    #if defined(MW_USART6_RX_DMA_ENABLED)
    UART_IsActiveFlagError(&mw_usart6);
    #endif

    #ifdef MW_USART6_TXE_INTERRUPT_ENABLED
    UART_IsActiveFlagTXE(&mw_usart6);
    #endif
}
#endif

#if defined(MW_UART7_RXNE_INTERRUPT_ENABLED ) || defined(MW_UART7_TXE_INTERRUPT_ENABLED ) || defined(MW_UART7_RX_DMA_ENABLED)
void UART7_IRQHandler(void)
{
    #ifdef MW_UART7_RXNE_INTERRUPT_ENABLED
    UART_IsActiveFlagRXNE(&mw_usart7);
    #endif

    #if  defined(MW_UART7_RX_DMA_ENABLED)
    UART_IsActiveFlagError(&mw_usart7);
    #endif

    #ifdef MW_UART7_TXE_INTERRUPT_ENABLED
    UART_IsActiveFlagTXE(&mw_usart7);
    #endif
}
#endif

#if defined(MW_UART8_RXNE_INTERRUPT_ENABLED ) || defined(MW_UART8_TXE_INTERRUPT_ENABLED ) || defined(MW_UART8_RX_DMA_ENABLED)
void UART8_IRQHandler(void)
{
    #ifdef MW_UART8_RXNE_INTERRUPT_ENABLED
    UART_IsActiveFlagRXNE(&mw_usart8);
    #endif

    #if  defined(MW_UART8_RX_DMA_ENABLED)
    UART_IsActiveFlagError(&mw_usart8);
    #endif

    #ifdef MW_UART8_TXE_INTERRUPT_ENABLED
    UART_IsActiveFlagTXE(&mw_usart8);
    #endif
}
#endif
#if defined(MW_UART9_RXNE_INTERRUPT_ENABLED ) || defined(MW_UART9_TXE_INTERRUPT_ENABLED ) || defined(MW_UART9_RX_DMA_ENABLED)
void UART9_IRQHandler(void)
{
    #ifdef MW_UART9_RXNE_INTERRUPT_ENABLED
    UART_IsActiveFlagRXNE(&mw_usart9);
    #endif

    #if  defined(MW_UART9_RX_DMA_ENABLED)
    UART_IsActiveFlagError(&mw_usart9);
    #endif

    #ifdef MW_UART9_TXE_INTERRUPT_ENABLED
    UART_IsActiveFlagTXE(&mw_usart9);
    #endif
}
#endif

#if defined(MW_USART10_RXNE_INTERRUPT_ENABLED ) || defined(MW_USART10_TXE_INTERRUPT_ENABLED ) || defined(MW_USART10_RX_DMA_ENABLED)
void USART10_IRQHandler(void)
{
    #ifdef MW_USART10_RXNE_INTERRUPT_ENABLED
    UART_IsActiveFlagRXNE(&mw_usart10);
    #endif

    #if defined(MW_USART10_RX_DMA_ENABLED)
    UART_IsActiveFlagError(&mw_usart10);
    #endif

    #ifdef MW_USART10_TXE_INTERRUPT_ENABLED
    UART_IsActiveFlagTXE(&mw_usart10);
    #endif
}
#endif



#ifdef MW_USART1_TX_DMA_ENABLED
GETIRQ_NAME(MW_USART1_TX_DMA_ENABLED)
{
    UART_TXDMAInterruptHandler(&mw_usart1, GETFCN_LL_GET_STREAM_ACTIVEFLAG(MW_USART1_TX_DMA_STREAM), GETFCN_LL_CLEAR_STREAM_ACTIVEFLAG(MW_USART1_TX_DMA_STREAM));

}
#endif
#ifdef MW_USART1_RX_DMA_ENABLED
GETIRQ_NAME(MW_USART1_RX_DMA_ENABLED)
{
    UART_RXDMAInterruptHandler(&mw_usart1, GETFCN_LL_GET_STREAM_ACTIVEFLAG(MW_USART1_RX_DMA_STREAM), GETFCN_LL_CLEAR_STREAM_ACTIVEFLAG(MW_USART1_RX_DMA_STREAM));

}
#endif
#ifdef MW_USART2_TX_DMA_ENABLED
GETIRQ_NAME(MW_USART2_TX_DMA_ENABLED)
{
    UART_TXDMAInterruptHandler(&mw_usart2, GETFCN_LL_GET_STREAM_ACTIVEFLAG(MW_USART2_TX_DMA_STREAM), GETFCN_LL_CLEAR_STREAM_ACTIVEFLAG(MW_USART2_TX_DMA_STREAM));

}
#endif

#ifdef MW_USART2_RX_DMA_ENABLED
GETIRQ_NAME(MW_USART2_RX_DMA_ENABLED)
{
    UART_RXDMAInterruptHandler(&mw_usart2, GETFCN_LL_GET_STREAM_ACTIVEFLAG(MW_USART2_RX_DMA_STREAM), GETFCN_LL_CLEAR_STREAM_ACTIVEFLAG(MW_USART2_RX_DMA_STREAM));

}
#endif

#ifdef MW_USART3_TX_DMA_ENABLED
GETIRQ_NAME(MW_USART3_TX_DMA_ENABLED)
{
    UART_TXDMAInterruptHandler(&mw_usart3, GETFCN_LL_GET_STREAM_ACTIVEFLAG(MW_USART3_TX_DMA_STREAM), GETFCN_LL_CLEAR_STREAM_ACTIVEFLAG(MW_USART3_TX_DMA_STREAM));

}
#endif
#ifdef MW_USART3_RX_DMA_ENABLED
GETIRQ_NAME(MW_USART3_RX_DMA_ENABLED)
{
    UART_RXDMAInterruptHandler(&mw_usart3, GETFCN_LL_GET_STREAM_ACTIVEFLAG(MW_USART3_RX_DMA_STREAM), GETFCN_LL_CLEAR_STREAM_ACTIVEFLAG(MW_USART3_RX_DMA_STREAM));

}
#endif


#ifdef MW_UART4_TX_DMA_ENABLED
GETIRQ_NAME(MW_UART4_TX_DMA_ENABLED)
{
    UART_TXDMAInterruptHandler(&mw_usart4, GETFCN_LL_GET_STREAM_ACTIVEFLAG(MW_UART4_TX_DMA_STREAM), GETFCN_LL_CLEAR_STREAM_ACTIVEFLAG(MW_UART4_TX_DMA_STREAM));
}
#endif

#ifdef MW_UART4_RX_DMA_ENABLED
GETIRQ_NAME(MW_UART4_RX_DMA_ENABLED)
{
    UART_RXDMAInterruptHandler(&mw_usart4, GETFCN_LL_GET_STREAM_ACTIVEFLAG(MW_UART4_RX_DMA_STREAM), GETFCN_LL_CLEAR_STREAM_ACTIVEFLAG(MW_UART4_RX_DMA_STREAM));
}
#endif

#ifdef MW_UART5_TX_DMA_ENABLED
GETIRQ_NAME(MW_UART5_TX_DMA_ENABLED)
{
    UART_TXDMAInterruptHandler(&mw_usart5, GETFCN_LL_GET_STREAM_ACTIVEFLAG(MW_UART5_TX_DMA_STREAM), GETFCN_LL_CLEAR_STREAM_ACTIVEFLAG(MW_UART5_TX_DMA_STREAM));
}
#endif

#ifdef MW_UART5_RX_DMA_ENABLED
GETIRQ_NAME(MW_UART5_RX_DMA_ENABLED)
{
    UART_RXDMAInterruptHandler(&mw_usart5, GETFCN_LL_GET_STREAM_ACTIVEFLAG(MW_UART5_RX_DMA_STREAM), GETFCN_LL_CLEAR_STREAM_ACTIVEFLAG(MW_UART5_RX_DMA_STREAM));
}
#endif

#ifdef MW_USART6_TX_DMA_ENABLED
GETIRQ_NAME(MW_USART6_TX_DMA_ENABLED)
{
    UART_TXDMAInterruptHandler(&mw_usart6, GETFCN_LL_GET_STREAM_ACTIVEFLAG(MW_USART6_TX_DMA_STREAM), GETFCN_LL_CLEAR_STREAM_ACTIVEFLAG(MW_USART6_TX_DMA_STREAM));

}
#endif
#ifdef MW_USART6_RX_DMA_ENABLED
GETIRQ_NAME(MW_USART6_RX_DMA_ENABLED)
{
    UART_RXDMAInterruptHandler(&mw_usart6, GETFCN_LL_GET_STREAM_ACTIVEFLAG(MW_USART6_RX_DMA_STREAM), GETFCN_LL_CLEAR_STREAM_ACTIVEFLAG(MW_USART6_RX_DMA_STREAM));

}
#endif

#ifdef MW_UART7_TX_DMA_ENABLED
GETIRQ_NAME(MW_UART7_TX_DMA_ENABLED)
{
    UART_TXDMAInterruptHandler(&mw_usart7, GETFCN_LL_GET_STREAM_ACTIVEFLAG(MW_UART7_TX_DMA_STREAM), GETFCN_LL_CLEAR_STREAM_ACTIVEFLAG(MW_UART7_TX_DMA_STREAM));
}
#endif

#ifdef MW_UART7_RX_DMA_ENABLED
GETIRQ_NAME(MW_UART7_RX_DMA_ENABLED)
{
    UART_RXDMAInterruptHandler(&mw_usart7, GETFCN_LL_GET_STREAM_ACTIVEFLAG(MW_UART7_RX_DMA_STREAM), GETFCN_LL_CLEAR_STREAM_ACTIVEFLAG(MW_UART7_RX_DMA_STREAM));
}
#endif

#ifdef MW_UART8_TX_DMA_ENABLED
GETIRQ_NAME(MW_UART8_TX_DMA_ENABLED)
{
    UART_TXDMAInterruptHandler(&mw_usart8, GETFCN_LL_GET_STREAM_ACTIVEFLAG(MW_UART8_TX_DMA_STREAM), GETFCN_LL_CLEAR_STREAM_ACTIVEFLAG(MW_UART8_TX_DMA_STREAM));
}
#endif

#ifdef MW_UART8_RX_DMA_ENABLED
GETIRQ_NAME(MW_UART8_RX_DMA_ENABLED)
{
    UART_RXDMAInterruptHandler(&mw_usart8, GETFCN_LL_GET_STREAM_ACTIVEFLAG(MW_UART8_RX_DMA_STREAM), GETFCN_LL_CLEAR_STREAM_ACTIVEFLAG(MW_UART8_RX_DMA_STREAM));
}
#endif
#ifdef MW_UART9_TX_DMA_ENABLED
GETIRQ_NAME(MW_UART9_TX_DMA_ENABLED)
{
    UART_TXDMAInterruptHandler(&mw_usart9, GETFCN_LL_GET_STREAM_ACTIVEFLAG(MW_UART9_TX_DMA_STREAM), GETFCN_LL_CLEAR_STREAM_ACTIVEFLAG(MW_UART9_TX_DMA_STREAM));
}
#endif

#ifdef MW_UART9_RX_DMA_ENABLED
GETIRQ_NAME(MW_UART9_RX_DMA_ENABLED)
{
    UART_RXDMAInterruptHandler(&mw_usart9, GETFCN_LL_GET_STREAM_ACTIVEFLAG(MW_UART9_RX_DMA_STREAM), GETFCN_LL_CLEAR_STREAM_ACTIVEFLAG(MW_UART9_RX_DMA_STREAM));
}
#endif

#ifdef MW_USART10_TX_DMA_ENABLED
GETIRQ_NAME(MW_USART10_TX_DMA_ENABLED)
{
    UART_TXDMAInterruptHandler(&mw_usart10, GETFCN_LL_GET_STREAM_ACTIVEFLAG(MW_USART10_TX_DMA_STREAM), GETFCN_LL_CLEAR_STREAM_ACTIVEFLAG(MW_USART10_TX_DMA_STREAM));
}
#endif

#ifdef MW_USART10_RX_DMA_ENABLED
GETIRQ_NAME(MW_USART10_RX_DMA_ENABLED)
{
    UART_RXDMAInterruptHandler(&mw_usart10, GETFCN_LL_GET_STREAM_ACTIVEFLAG(MW_USART10_RX_DMA_STREAM), GETFCN_LL_CLEAR_STREAM_ACTIVEFLAG(MW_USART10_RX_DMA_STREAM));
}
#endif

/**************Internal Functions ****************************************************************************/

void UART_ConfigureReceiveDMA(UART_Type_T *h)
{
    #if defined (GPDMA1)
        LL_DMA_ConfigAddresses(h->rxdmaPeripheralPtr, (uint32_t)h->rxdmastream,
                           LL_USART_DMA_GetRegAddr(h->peripheralPtr, LL_USART_DMA_REG_DATA_RECEIVE),
                           (uint32_t)h->buffer.rxBufferPtr);
    
        LL_DMA_SetBlkDataLength(h->rxdmaPeripheralPtr, (uint32_t)h->rxdmastream, h->buffer.rxBufferSize);
    #else
    LL_DMA_ConfigAddresses(h->rxdmaPeripheralPtr, (uint32_t)h->rxdmastream,
                           #if defined(STM32F7) ||  defined(STM32H7) || defined(STM32G4) || defined(STM32WB) || defined(STM32L5)|| defined(STM32L4) || defined(STM32U5)
                           LL_USART_DMA_GetRegAddr(h->peripheralPtr, LL_USART_DMA_REG_DATA_RECEIVE),
                           #else
                           LL_USART_DMA_GetRegAddr(h->peripheralPtr),
                           #endif
                           (uint32_t)h->buffer.rxBufferPtr,
                           LL_DMA_DIRECTION_PERIPH_TO_MEMORY);
    LL_DMA_SetDataLength(h->rxdmaPeripheralPtr, (uint32_t)h->rxdmastream, h->buffer.rxBufferSize);
    #endif
    /* Enable TC interrupts */
    LL_DMA_EnableIT_TC(h->rxdmaPeripheralPtr, (uint32_t)h->rxdmastream);
    /* Enable DMA */
    LL_USART_EnableDMAReq_RX(h->peripheralPtr);
    ((USART_TypeDef *)h->peripheralPtr)->CR3 |= USART_CR3_DMAR;
    /* Enable USART and DMA Stream */
    #if defined(STM32G4) || defined(STM32WB) || defined(STM32L5)|| defined(STM32L4) || defined(STM32U5)
    LL_DMA_EnableChannel(h->rxdmaPeripheralPtr, (uint32_t)h->rxdmastream);
    #else
    LL_DMA_EnableStream(h->rxdmaPeripheralPtr, (uint32_t)h->rxdmastream);
    #endif
}

/*Configure UART Transmit DMA */
void UART_ConfigureTransmitDMA(UART_Type_T *h)
{
    #if defined (GPDMA1)
        LL_DMA_ConfigAddresses(h->txdmaPeripheralPtr, (uint32_t)h->txdmastream,
                               (uint32_t)h->buffer.txBufferPtr,
                           LL_USART_DMA_GetRegAddr(h->peripheralPtr, LL_USART_DMA_REG_DATA_TRANSMIT)
                           );
    #else
    LL_DMA_ConfigAddresses(h->txdmaPeripheralPtr, (uint32_t)h->txdmastream,
                           (uint32_t)h->buffer.txBufferPtr,
                           #if defined(STM32F7) ||  defined(STM32H7)  || defined(STM32G4) || defined(STM32WB) || defined(STM32L5) || defined(STM32L4)
                           LL_USART_DMA_GetRegAddr(h->peripheralPtr, LL_USART_DMA_REG_DATA_TRANSMIT),
                           #else
                           LL_USART_DMA_GetRegAddr(h->peripheralPtr),
                           #endif
                           LL_DMA_DIRECTION_MEMORY_TO_PERIPH);
    #endif
    /* Enable  TC interrupts */
    LL_DMA_EnableIT_TC(h->txdmaPeripheralPtr, (uint32_t)h->txdmastream);
    /* Enable DMA */
    LL_USART_EnableDMAReq_TX(h->peripheralPtr);
}

uint16_T getReadErrorStatus(UART_Type_T *h)
{
    uint16_T status = MW_SCI_SUCCESS;
    if((h->errorStatus & MW_SCI_RX_BUFFER_FULL) == MW_SCI_RX_BUFFER_FULL) // If buffer is full, show in same step in interrupt mode
    {
        status = status |  MW_SCI_RX_BUFFER_FULL;
        h->errorStatus &= ~MW_SCI_RX_BUFFER_FULL;
    }
    #if defined(STM32F7) || defined(STM32H7) || defined(STM32G4) || defined(STM32WB) || defined(STM32L4)
    if(IS_USART_AUTOBAUDRATE_DETECTION_INSTANCE(h->peripheralPtr) && LL_USART_IsEnabledAutoBaud(h->peripheralPtr))
    {
        if(LL_USART_IsActiveFlag_ABR(h->peripheralPtr) && LL_USART_IsActiveFlag_ABRE(h->peripheralPtr))
        {
            status = status |  MW_SCI_ARBE_ERROR;
            LL_USART_RequestAutoBaudRate(h->peripheralPtr);
        }
    }
    #endif
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
            LL_USART_ReceiveData8((USART_TypeDef*)h->peripheralPtr);
            LL_USART_ClearFlag_ORE(h->peripheralPtr);
            LL_USART_EnableIT_RXNE(h->peripheralPtr);
        }
        else
        {
            LL_USART_ReceiveData8((USART_TypeDef*)h->peripheralPtr);
            LL_USART_ClearFlag_ORE(h->peripheralPtr);
            /* Enable DMA */
            LL_USART_EnableDMAReq_RX(h->peripheralPtr);
        }
    }
    return status ;
}

/* Initialize UART module */
UART_Type_T * MW_UART_Initialize(UART_Type_T  * SCIModule)
{
    UART_Type_T * mw_usart;
    switch ((uint32_t)((UART_Type_T *)SCIModule)->peripheralPtr)
    {
    #if defined(USART1) && defined(MW_USART1_ENABLED)
        case ((uint32_t)USART1):
            mw_usart = &mw_usart1;
            #if defined(MW_USART1_RX_DMA_ENABLED) || defined(MW_USART1_RXNE_INTERRUPT_ENABLED ) || defined(MW_USART1_TXE_INTERRUPT_ENABLED )
            NVIC_SetPriority(USART1_IRQn, NVIC_EncodePriority(NVIC_GetPriorityGrouping(),0, 0));
            NVIC_EnableIRQ(USART1_IRQn);
            #endif
            break;
            #endif
            #if defined(USART2) && defined(MW_USART2_ENABLED)
        case ((uint32_t)USART2):
            mw_usart = &mw_usart2;
            #if defined(MW_USART2_RX_DMA_ENABLED) || defined(MW_USART2_RXNE_INTERRUPT_ENABLED ) || defined(MW_USART2_TXE_INTERRUPT_ENABLED )
            NVIC_SetPriority(USART2_IRQn, NVIC_EncodePriority(NVIC_GetPriorityGrouping(),0, 0));
            NVIC_EnableIRQ(USART2_IRQn);
            #endif
            break;
            #endif

            #if defined(USART3) && defined(MW_USART3_ENABLED)
        case ((uint32_t)USART3):
            mw_usart = &mw_usart3;
            #if defined(MW_USART3_RX_DMA_ENABLED) || defined(MW_USART3_RXNE_INTERRUPT_ENABLED ) || defined(MW_USART3_TXE_INTERRUPT_ENABLED )
            NVIC_SetPriority(USART3_IRQn, NVIC_EncodePriority(NVIC_GetPriorityGrouping(),0, 0));
            NVIC_EnableIRQ(USART3_IRQn);
            #endif
            break;
            #endif

            #if defined(UART4) && defined(MW_UART4_ENABLED)
        case ((uint32_t)UART4):
            mw_usart = &mw_usart4;
            #if defined(MW_UART4_RX_DMA_ENABLED) || defined(MW_UART4_RXNE_INTERRUPT_ENABLED ) || defined(MW_UART4_TXE_INTERRUPT_ENABLED )
            NVIC_SetPriority(UART4_IRQn, NVIC_EncodePriority(NVIC_GetPriorityGrouping(),0, 0));
            NVIC_EnableIRQ(UART4_IRQn);
            #endif
            break;
            #endif

            #if defined(UART5) && defined(MW_UART5_ENABLED)
        case ((uint32_t)UART5):
            mw_usart = &mw_usart5;
            #if defined(MW_UART5_RX_DMA_ENABLED) || defined(MW_UART5_RXNE_INTERRUPT_ENABLED ) || defined(MW_UART5_TXE_INTERRUPT_ENABLED )
            NVIC_SetPriority(UART5_IRQn, NVIC_EncodePriority(NVIC_GetPriorityGrouping(),0, 0));
            NVIC_EnableIRQ(UART5_IRQn);
            #endif
            break;
            #endif

            #if defined(USART6) && defined(MW_USART6_ENABLED)
        case ((uint32_t)USART6):
            mw_usart = &mw_usart6;
            #if defined(MW_USART6_RX_DMA_ENABLED) || defined(MW_USART6_RXNE_INTERRUPT_ENABLED ) || defined(MW_USART6_TXE_INTERRUPT_ENABLED )
            NVIC_SetPriority(USART6_IRQn, NVIC_EncodePriority(NVIC_GetPriorityGrouping(),0, 0));
            NVIC_EnableIRQ(USART6_IRQn);
            #endif
            break;
            #endif

            #if defined(UART7) && defined(MW_UART7_ENABLED)
        case ((uint32_t)UART7):
            mw_usart = &mw_usart7;
            #if defined(MW_UART7_RX_DMA_ENABLED) || defined(MW_UART7_RXNE_INTERRUPT_ENABLED )|| defined(MW_UART7_TXE_INTERRUPT_ENABLED )
            NVIC_SetPriority(UART7_IRQn, NVIC_EncodePriority(NVIC_GetPriorityGrouping(),0, 0));
            NVIC_EnableIRQ(UART7_IRQn);
            #endif
            break;
            #endif

            #if defined(UART8) && defined(MW_UART8_ENABLED)
        case ((uint32_t)UART8):
            mw_usart = &mw_usart8;
            #if defined(MW_UART8_RX_DMA_ENABLED) || defined(MW_UART8_RXNE_INTERRUPT_ENABLED )|| defined(MW_UART8_TXE_INTERRUPT_ENABLED )
            NVIC_SetPriority(UART8_IRQn, NVIC_EncodePriority(NVIC_GetPriorityGrouping(),0, 0));
            NVIC_EnableIRQ(UART8_IRQn);
            #endif
            break;
            #endif
            #if defined(UART9) && defined(MW_UART9_ENABLED)
        case ((uint32_t)UART9):
            mw_usart = &mw_usart9;
            #if defined(MW_UART9_RX_DMA_ENABLED) || defined(MW_UART9_RXNE_INTERRUPT_ENABLED )|| defined(MW_UART9_TXE_INTERRUPT_ENABLED )
            NVIC_SetPriority(UART9_IRQn, NVIC_EncodePriority(NVIC_GetPriorityGrouping(),0, 0));
            NVIC_EnableIRQ(UART9_IRQn);
            #endif
            break;
            #endif

            #if defined(USART10) && defined(MW_USART10_ENABLED)
        case ((uint32_t)USART10):
            mw_usart = &mw_usart10;
            #if defined(MW_USART10_RX_DMA_ENABLED) || defined(MW_USART10_RXNE_INTERRUPT_ENABLED ) || defined(MW_USART10_TXE_INTERRUPT_ENABLED )
            NVIC_SetPriority(USART10_IRQn, NVIC_EncodePriority(NVIC_GetPriorityGrouping(),0, 0));
            NVIC_EnableIRQ(USART10_IRQn);
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
        LL_USART_Disable(mw_usart->peripheralPtr);
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
                UART_ConfigureReceiveDMA(mw_usart);
                LL_USART_EnableIT_ERROR(mw_usart->peripheralPtr);
                LL_USART_EnableIT_PE(mw_usart->peripheralPtr);
            }
            /*Configure interrupts for Rx with interrupts */
            else if ((mw_usart->mode & UART_RX_INTERRUPT_MODE) == UART_RX_INTERRUPT_MODE)
            {
                LL_USART_EnableIT_RXNE(mw_usart->peripheralPtr);
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
                UART_ConfigureTransmitDMA(mw_usart);
            }
        }
        LL_USART_Enable(mw_usart->peripheralPtr);
    }
    return mw_usart;
}

/* Receive the data over UART in Polling mode*/
MW_SCI_Status_Type MW_UART_ReceiveUsingPolling(UART_Type_T * h, void * RxDataPtr, uint32_T RxDataLength, uint32_T * receivedLength, uint32_T timeout)
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
        uint16_T status = MW_SCI_SUCCESS;
        uint32_T initialTime = 0;

        for (dataCounter = 0; dataCounter < RxDataLength; dataCounter++)
        {

            if (0 == LL_USART_IsActiveFlag_RXNE((USART_TypeDef*)h->peripheralPtr))
            {
                if (timeout > 0)
                {
                    initialTime = GET_CURRENT_TIME();
                    while ((0 == LL_USART_IsActiveFlag_RXNE((USART_TypeDef*)h->peripheralPtr)) && (returnTimeElapsed(initialTime, 1) <= (timeout)));
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

            #if defined(STM32F7) || defined(STM32H7) || defined(STM32G4) || defined(STM32WB) || defined(STM32L4)
            if(IS_USART_AUTOBAUDRATE_DETECTION_INSTANCE(h->peripheralPtr) && LL_USART_IsEnabledAutoBaud(h->peripheralPtr))
            {
                if(LL_USART_IsActiveFlag_ABR(h->peripheralPtr) && LL_USART_IsActiveFlag_ABRE(h->peripheralPtr))
                {
                    status = status |  MW_SCI_ARBE_ERROR;
                    LL_USART_RequestAutoBaudRate(h->peripheralPtr);
                }
            }
            #endif
            if(1 == LL_USART_IsActiveFlag_ORE(h->peripheralPtr))
            {
                status = status | MW_SCI_ORE_ERROR;
            }
            if(1 == LL_USART_IsActiveFlag_FE(h->peripheralPtr))
            {
                status = status | MW_SCI_FRAME_ERROR;
            }
            if(1 == LL_USART_IsActiveFlag_NE(h->peripheralPtr))
            {
                status = status | MW_SCI_NOISE_ERROR;
            }
            if(1 == LL_USART_IsActiveFlag_PE(h->peripheralPtr))
            {
                status = status | MW_SCI_PARITY_ERROR;
            }
            rxData[dataCounter] = LL_USART_ReceiveData8((USART_TypeDef*)h->peripheralPtr);
            if(status != MW_SCI_SUCCESS)
            {
                LL_USART_ClearFlag_PE(h->peripheralPtr); //Clearing this flag will clear all ORE,NE,FE and PE flags for STM32F4
                #if defined(STM32F7) || defined(STM32G4) || defined(STM32H7) || defined(STM32WB) || defined(STM32L4) || defined(STM32U5)
                LL_USART_ClearFlag_ORE(h->peripheralPtr);
                LL_USART_ClearFlag_FE(h->peripheralPtr);
                LL_USART_ClearFlag_NE(h->peripheralPtr);
                #endif
            }
            (*receivedLength)++ ;

        }
        h->uartStatus &= ~MW_SCI_RX_BUSY ;
        return status;
    }
}

/* Receive the data over UART using DMA/Interrupt and buffer */
MW_SCI_Status_Type MW_UART_ReceiveUsingBuffer(UART_Type_T * h, void * RxDataPtr, uint32_T RxDataLength, uint32_T * receivedLength)
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
MW_SCI_Status_Type MW_UART_TransmitUsingPolling(UART_Type_T * h, void * TxDataPtr, uint32_T TxDataLength, uint32_T timeout, uint32_T *sentDataLength)
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
            if (0 == LL_USART_IsActiveFlag_TXE((USART_TypeDef*)h->peripheralPtr))
            {
                if (timeout > 0)
                {
                    initialTime = GET_CURRENT_TIME();
                    while ((0 == LL_USART_IsActiveFlag_TXE((USART_TypeDef*)h->peripheralPtr)) && (returnTimeElapsed(initialTime, 1) <= (timeout)));
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
            LL_USART_TransmitData8((USART_TypeDef*)h->peripheralPtr,TxData[dataCounter]);
        }

        if (0 == LL_USART_IsActiveFlag_TC((USART_TypeDef*)h->peripheralPtr))
        {
            if (timeout > 0)
            {
                initialTime = GET_CURRENT_TIME();
                while ((0 == LL_USART_IsActiveFlag_TC((USART_TypeDef*)h->peripheralPtr)) &&  (returnTimeElapsed(initialTime, 1) <= (timeout)))
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

/* Transmit the data over UART in Interrupt mode*/
MW_SCI_Status_Type MW_UART_TransmitUsingInterrupt(UART_Type_T * h, void * TxDataPtr, uint32_T TxDataLength, uint32_T timeout,uint32_T *sentDataLength)
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
                LL_USART_TransmitData8((USART_TypeDef*)h->peripheralPtr,h->buffer.txBufferPtr[h->buffer.sentPos]);
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
                    LL_USART_EnableIT_TXE(h->peripheralPtr);
                }
            }
            *sentDataLength = TxDataLength;
            h->uartStatus &= ~MW_SCI_TX_BUSY ;
        }
        return MW_SCI_SUCCESS;
    }
}


/* Transmit the data over UART in DMA mode*/
MW_SCI_Status_Type MW_UART_TransmitUsingDMA(UART_Type_T * h, void * TxDataPtr, uint32_T TxDataLength, uint32_T timeout,uint32_T *sentDataLength)
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
                #if defined(STM32G4) || defined(STM32WB) || defined(STM32L5) || defined(STM32L4) || defined(STM32U5)
                LL_DMA_DisableChannel(h->txdmaPeripheralPtr, h->txdmastream);
                #else
                LL_DMA_DisableStream(h->txdmaPeripheralPtr, h->txdmastream);
                #endif
                #if defined (GPDMA1)
                    LL_DMA_SetSrcAddress(h->txdmaPeripheralPtr, (uint32_t)h->txdmastream, (uint32_t)(h->buffer.txBufferPtr +  h->buffer.sentPos));
                    LL_DMA_SetBlkDataLength(h->txdmaPeripheralPtr, (uint32_t)h->txdmastream, h->txDMATransferLength);
                #else
                LL_DMA_SetMemoryAddress(h->txdmaPeripheralPtr, (uint32_t)h->txdmastream, (uint32_t)(h->buffer.txBufferPtr +  h->buffer.sentPos));
                LL_DMA_SetDataLength(h->txdmaPeripheralPtr, (uint32_t)h->txdmastream,  h->txDMATransferLength);
                #endif
                #if defined(MW_DCACHE_ENABLED) // Clean cache if enabled before starting DMA
                SCB_CleanDCache_by_Addr((uint32_t *)&h->buffer.txBufferPtr[0], h->buffer.txBufferSize);
                #endif
                #if defined(STM32G4) || defined(STM32WB) || defined(STM32L5) || defined(STM32L4) || defined(STM32U5)
                LL_DMA_EnableChannel(h->txdmaPeripheralPtr, (uint32_t)h->txdmastream);
                #else
                LL_DMA_EnableStream(h->txdmaPeripheralPtr, (uint32_t)h->txdmastream);
                #endif
            }
            *sentDataLength = TxDataLength;
            h->uartStatus &= ~MW_SCI_TX_BUSY ;
        }
        return MW_SCI_SUCCESS;
    }

}

/* Release SCI module */
void MW_UART_DeInit(UART_Type_T * h)
{
    /* Disable USART */
    LL_USART_Disable(h->peripheralPtr);
    /*Disable Interrupts and DMA */
    if (UART_TX_DMA_MODE == (h->mode & UART_TX_DMA_MODE))
    {
        LL_DMA_DisableIT_TC(h->txdmaPeripheralPtr, (uint32_t)h->txdmastream);
        LL_USART_DisableDMAReq_TX(h->peripheralPtr);
    }
    else if(UART_TX_INTERRUPT_MODE == (h->mode & UART_TX_INTERRUPT_MODE))
    {
        LL_USART_DisableIT_TXE(h->peripheralPtr);
    }

    if (UART_RX_DMA_MODE == (h->mode & UART_RX_DMA_MODE))
    {
        LL_USART_DisableIT_ERROR(h->peripheralPtr);
        LL_USART_DisableIT_PE(h->peripheralPtr);
        LL_DMA_DisableIT_TC(h->rxdmaPeripheralPtr, (uint32_t)h->rxdmastream);
        LL_USART_DisableDMAReq_RX(h->peripheralPtr);
    }
    else if(UART_RX_INTERRUPT_MODE == (h->mode & UART_RX_INTERRUPT_MODE))
    {
        LL_USART_DisableIT_RXNE(h->peripheralPtr);
    }
}

#endif

/* LocalWords:  dma nbDataPos RXNE rxdma rxdmastream TXE UART
*/
