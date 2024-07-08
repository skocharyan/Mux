/* Copyright 2021-2022 The MathWorks, Inc. */

#ifndef __STM_LPUART__
#define __STM_LPUART__

#include "stm_uart.h"

#if defined(MW_LPUART1_RX_DMA_ENABLED)
        extern uint8_T LPUART1ReceiveBuffer[MW_LPUART1_RECEIVE_BUFFER_SIZE] ;
        #define GET_LPUART1_RECEIVE_BUFFER() &LPUART1ReceiveBuffer[0]
#endif
#if  defined(MW_LPUART1_TX_DMA_ENABLED)
        extern uint8_T LPUART1TransmitBuffer[MW_LPUART1_TRANSMIT_BUFFER_SIZE] ;
        #define GET_LPUART1_TRANSMIT_BUFFER() &LPUART1TransmitBuffer[0]
#endif
/* DMA RX Interrupt Handler */
void LPUART_RXDMAInterruptHandler(UART_Type_T *h ,uint32_t  (*checkActiveFlag)(DMA_TypeDef *DMAx),  void (*clearActiveFlag)(DMA_TypeDef *DMAx));
/*DMA TX Interrupt Handler */
void LPUART_TXDMAInterruptHandler(UART_Type_T *h ,uint32_t  (*checkActiveFlag)(DMA_TypeDef *DMAx),  void (*clearActiveFlag)(DMA_TypeDef *DMAx));
/* Check if RXNE flag is active */
uint8_T LPUART_IsActiveFlagRXNE(UART_Type_T *h);
/* Check if any error flag is active */
void LPUART_IsActiveFlagError(UART_Type_T *h);
/* Check if TXE flag is active */
uint8_T LPUART_IsActiveFlagTXE(UART_Type_T *h);
/*Configure UART Receive DMA */
void LPUART_ConfigureReceiveDMA(UART_Type_T *h);
/*Configure UART Transmit DMA */
void LPUART_ConfigureTransmitDMA(UART_Type_T *h);
/*Get read error status */
uint16_T MW_LPUART_GetReadErrorStatus(UART_Type_T *h);
#if defined(STM32H7) && defined(MW_LPUART1_ENABLED)
/*Configure LPUART Transmit BDMA */
void LPUART_ConfigureTransmitBDMA(UART_Type_T *h);
/*Configure LPUART Receive BDMA */
void LPUART_ConfigureReceiveBDMA(UART_Type_T *h);
/* BDMA TX Interrupt Handler */
void LPUART_TXBDMAInterruptHandler(UART_Type_T *h ,uint32_t  (*checkActiveFlag)(BDMA_TypeDef *BDMAx),  void (*clearActiveFlag)(BDMA_TypeDef *BDMAx));
/* BDMA RX Interrupt Handler */
void LPUART_RXBDMAInterruptHandler(UART_Type_T *h ,uint32_t  (*checkActiveFlag)(BDMA_TypeDef *BDMAx),  void (*clearActiveFlag)(BDMA_TypeDef *BDMAx));
#endif
/*Functions called from System object of blocks */

/* Initialize UART module */
UART_Type_T * MW_LPUART_Initialize(UART_Type_T  * SCIModule);
/* Receive the data over UART in Polling mode*/
MW_SCI_Status_Type MW_LPUART_ReceiveUsingPolling(UART_Type_T * h, void * RxDataPtr, uint32_T RxDataLength, uint32_T * receivedLength, uint32_T timeout);
/* Receive the data over UART using DMA/Interrupt and buffer */
MW_SCI_Status_Type MW_LPUART_ReceiveUsingBuffer(UART_Type_T * h, void * RxDataPtr, uint32_T RxDataLength, uint32_T * receivedLength);
/* Transmit the data over UART in Polling mode*/
MW_SCI_Status_Type MW_LPUART_TransmitUsingPolling(UART_Type_T * h, void  * TxDataPtr, uint32_T TxDataLength, uint32_T timeout, uint32_T *sentDataLength);
/* Transmit the data over UART using Interrupts */
MW_SCI_Status_Type MW_LPUART_TransmitUsingInterrupt(UART_Type_T * h, void * TxDataPtr, uint32_T TxDataLength, uint32_T timeout,uint32_T *sentDataLength);
/* Transmit the data over UART using DMA*/
MW_SCI_Status_Type MW_LPUART_TransmitUsingDMA(UART_Type_T * h, void * TxDataPtr, uint32_T TxDataLength, uint32_T timeout,uint32_T *sentDataLength);
/* Release UART module */
void MW_LPUART_DeInit(UART_Type_T * h);

#endif
