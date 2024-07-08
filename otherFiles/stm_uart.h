/* Copyright 2021-2023 The MathWorks, Inc. */

#ifndef __STM_UART__
#define __STM_UART__

#include "mw_stm32_types.h"
#include "MW_target_hardware_resources.h"

#if defined(MW_USART1_RX_DMA_ENABLED)
        extern uint8_T USART1ReceiveBuffer[MW_USART1_RECEIVE_BUFFER_SIZE] ;
        #define GET_USART1_RECEIVE_BUFFER() &USART1ReceiveBuffer[0]
#endif
#if  defined(MW_USART1_TX_DMA_ENABLED)
        extern uint8_T USART1TransmitBuffer[MW_USART1_TRANSMIT_BUFFER_SIZE] ;
        #define GET_USART1_TRANSMIT_BUFFER() &USART1TransmitBuffer[0]
#endif


#if defined(MW_USART2_RX_DMA_ENABLED)
        extern uint8_T USART2ReceiveBuffer[MW_USART2_RECEIVE_BUFFER_SIZE]  ;
        #define GET_USART2_RECEIVE_BUFFER() &USART2ReceiveBuffer[0]
#endif
#if  defined(MW_USART2_TX_DMA_ENABLED)
        extern uint8_T USART2TransmitBuffer[MW_USART2_TRANSMIT_BUFFER_SIZE] ;
        #define GET_USART2_TRANSMIT_BUFFER() &USART2TransmitBuffer[0]
#endif


 #if defined(MW_USART3_RX_DMA_ENABLED)
         extern uint8_T USART3ReceiveBuffer[MW_USART3_RECEIVE_BUFFER_SIZE] ;
         #define GET_USART3_RECEIVE_BUFFER() &USART3ReceiveBuffer[0]
 #endif
 #if  defined(MW_USART3_TX_DMA_ENABLED)
         extern uint8_T USART3TransmitBuffer[MW_USART3_TRANSMIT_BUFFER_SIZE] ;
         #define GET_USART3_TRANSMIT_BUFFER() &USART3TransmitBuffer[0]
 #endif


#if defined(MW_UART4_RX_DMA_ENABLED)
        extern uint8_T UART4ReceiveBuffer[MW_UART4_RECEIVE_BUFFER_SIZE] ;
        #define GET_UART4_RECEIVE_BUFFER() &UART4ReceiveBuffer[0]
#endif
#if  defined(MW_UART4_TX_DMA_ENABLED)
        extern uint8_T UART4TransmitBuffer[MW_UART4_TRANSMIT_BUFFER_SIZE] ;
        #define GET_UART4_TRANSMIT_BUFFER() &UART4TransmitBuffer[0]
#endif


#if defined(MW_UART5_RX_DMA_ENABLED)
        extern uint8_T UART5ReceiveBuffer[MW_UART5_RECEIVE_BUFFER_SIZE]  ;
        #define GET_UART5_RECEIVE_BUFFER() &UART5ReceiveBuffer[0]
#endif
#if  defined(MW_UART5_TX_DMA_ENABLED)
        extern uint8_T UART5TransmitBuffer[MW_UART5_TRANSMIT_BUFFER_SIZE]  ;
        #define GET_UART5_TRANSMIT_BUFFER() &UART5TransmitBuffer[0]
#endif

#if defined(MW_USART6_RX_DMA_ENABLED)
        extern uint8_T USART6ReceiveBuffer[MW_USART6_RECEIVE_BUFFER_SIZE] ;
        #define GET_USART6_RECEIVE_BUFFER() &USART6ReceiveBuffer[0]
#endif
#if  defined(MW_USART6_TX_DMA_ENABLED)
        extern uint8_T USART6TransmitBuffer[MW_USART6_TRANSMIT_BUFFER_SIZE]  ;
        #define GET_USART6_TRANSMIT_BUFFER() &USART6TransmitBuffer[0]
#endif

#if defined(MW_UART7_RX_DMA_ENABLED)
        extern uint8_T UART7ReceiveBuffer[MW_UART7_RECEIVE_BUFFER_SIZE]  ;
        #define GET_UART7_RECEIVE_BUFFER() &UART7ReceiveBuffer[0]
#endif
#if  defined(MW_UART7_TX_DMA_ENABLED)
        extern uint8_T UART7TransmitBuffer[MW_UART7_TRANSMIT_BUFFER_SIZE]  ;
        #define GET_UART7_TRANSMIT_BUFFER() &UART7TransmitBuffer[0]
#endif

#if defined(MW_UART8_RX_DMA_ENABLED)
        extern uint8_T UART8ReceiveBuffer[MW_UART8_RECEIVE_BUFFER_SIZE] ;
        #define GET_UART8_RECEIVE_BUFFER() &UART8ReceiveBuffer[0]
#endif
#if  defined(MW_UART8_TX_DMA_ENABLED)
        extern uint8_T UART8TransmitBuffer[MW_UART8_TRANSMIT_BUFFER_SIZE] ;
        #define GET_UART8_TRANSMIT_BUFFER() &UART8TransmitBuffer[0]
#endif

#if defined(MW_UART9_RX_DMA_ENABLED)
        extern uint8_T UART9ReceiveBuffer[MW_UART9_RECEIVE_BUFFER_SIZE]  ;
        #define GET_UART9_RECEIVE_BUFFER() &UART9ReceiveBuffer[0]
#endif
#if  defined(MW_UART9_TX_DMA_ENABLED)
        extern uint8_T UART9TransmitBuffer[MW_UART9_TRANSMIT_BUFFER_SIZE]  ;
        #define GET_UART9_TRANSMIT_BUFFER() &UART9TransmitBuffer[0]
#endif

#if defined(MW_USART10_RX_DMA_ENABLED)
        extern uint8_T USART10ReceiveBuffer[MW_USART10_RECEIVE_BUFFER_SIZE]  ;
        #define GET_USART10_RECEIVE_BUFFER() &USART10ReceiveBuffer[0]
#endif
#if  defined(MW_USART10_TX_DMA_ENABLED)
        extern uint8_T USART10TransmitBuffer[MW_USART10_TRANSMIT_BUFFER_SIZE] ;
        #define GET_USART10_TRANSMIT_BUFFER() &USART10TransmitBuffer[0]
#endif

typedef void * MW_Handle_Type;

typedef enum _MW_SCI_Status_Type {
    MW_SCI_SUCCESS              = 0,/*0x00*/
    MW_SCI_DATA_NOT_AVAILABLE   = 1<<0,/*0x01*/
	MW_SCI_ORE_ERROR            = 1<<1,/*0x02*/
	MW_SCI_PARITY_ERROR         = 1<<2,/*0x04*/
	MW_SCI_FRAME_ERROR          = 1<<3,/*0x08*/
	MW_SCI_NOISE_ERROR          = 1<<4,/*0x10*/
	MW_SCI_RX_BUFFER_FULL       = 1<<5,/*0x20*/
	MW_SCI_TX_FAILED            = 1<<6,/*0x40*/
	MW_SCI_TX_BUSY              = 1<<7,/*0x80*/
	MW_SCI_RX_BUSY              = 1<<8,/*0x100*/
    MW_SCI_ARBE_ERROR           = 1<<9 
} MW_SCI_Status_Type;

typedef enum _UART_Mode_T {
    UART_RX_POLLING_MODE    = 0x01,
    UART_TX_POLLING_MODE    = 0x02,
    UART_RX_INTERRUPT_MODE  = 0x04,
    UART_TX_INTERRUPT_MODE  = 0x08,
    UART_RX_DMA_MODE        = 0x10,
    UART_TX_DMA_MODE        = 0x20
} UART_Mode_T;

typedef struct _Circular_Buffer_T{
	uint8_T * rxBufferPtr;
    uint8_T * txBufferPtr;
	uint32_T rxBufferSize;
    uint32_T txBufferSize;
    uint32_T readPos;
    uint32_T toReadPos ;
    uint32_T writePos;
    uint32_T sentPos;
	boolean_T writeRollOver;
}Circular_Buffer_T;


typedef enum _UART_Comm_T {
    UART_ENABLE_RX = 0x01,
    UART_ENABLE_TX = 0x02,
    UART_ENABLE_BOTH = 0x03
} UART_Comm_T;

typedef struct _UART_Type_T {   
    void * peripheralPtr;
    void * rxdmaPeripheralPtr;
	void * txdmaPeripheralPtr;
	uint32_T txDMATransferLength;
    uint8_T rxdmastream ;
    uint8_T txdmastream ;
    boolean_T txeEnabled;
    boolean_T txdmaEnabled;
    boolean_T disableDMAIntOnError;
	UART_Comm_T enableRxOrTx;
	UART_Mode_T mode;  
    MW_SCI_Status_Type errorStatus;
    MW_SCI_Status_Type uartStatus ;
	Circular_Buffer_T buffer ;	
} UART_Type_T;

/* Internal functions for UART buffer */

/* Check if transmit buffer is full */
boolean_T checkIfTransmitBufferFull(UART_Type_T *h, uint32_T DataLength);
/* Copy data to Tranmit internal buffer */
uint8_T copyToTransmitBuffer(UART_Type_T *h, uint8_T * txData, uint32_T DataLength, uint32_T timeout);
/* Get Data available in internal recieve buffer */
uint32_T getAvailableDataInBuffer(UART_Type_T *h);
/*Wait till timeout and return the number of bytes that can be read from the buffer */
uint32_T getBytesToBeReadFromBuffer(UART_Type_T *h, uint32_T RxDataLength, uint32_T timeout);
/*Read data from internal receive buffer */
uint16_T readDataFromBuffer(UART_Type_T *h, uint8_T * RxDataPtr, uint32_T dataToRead, uint32_T * receivedLength);

/*Internal functions for UART */

/* DMA RX Interrupt Handler */
/* Handler prototype is different for GPDMA and DMA. GPDMA1/DMA is defined in CMSIS Device Peripheral Access Layer Header File.*/
#if defined (GPDMA1)
    void UART_RXDMAInterruptHandler(UART_Type_T *h ,uint32_t  (*checkActiveFlag)(DMA_TypeDef *DMAx, uint32_t rxdmastream),  void (*clearActiveFlag)(DMA_TypeDef *DMAx, uint32_t rxdmastream));
    void UART_TXDMAInterruptHandler(UART_Type_T *h ,uint32_t  (*checkActiveFlag)(DMA_TypeDef *DMAx, uint32_t txdmastream),  void (*clearActiveFlag)(DMA_TypeDef *DMAx, uint32_t txdmastream));
#else
    void UART_RXDMAInterruptHandler(UART_Type_T *h ,uint32_t  (*checkActiveFlag)(DMA_TypeDef *DMAx),  void (*clearActiveFlag)(DMA_TypeDef *DMAx));
    void UART_TXDMAInterruptHandler(UART_Type_T *h ,uint32_t  (*checkActiveFlag)(DMA_TypeDef *DMAx),  void (*clearActiveFlag)(DMA_TypeDef *DMAx));
#endif
/*DMA TX Interrupt Handler */

/* Check if RXNE flag is active */
uint8_T UART_IsActiveFlagRXNE(UART_Type_T *h);
/* Check if any error flag is active */
void UART_IsActiveFlagError(UART_Type_T *h);
/* Check if TXE flag is active */
uint8_T UART_IsActiveFlagTXE(UART_Type_T *h);
/*Configure UART Receive DMA */
void UART_ConfigureReceiveDMA(UART_Type_T *h);
/*Configure UART Transmit DMA */
void UART_ConfigureTransmitDMA(UART_Type_T *h);
/*Get read error status */
uint16_T getReadErrorStatus(UART_Type_T *h);
/*Functions called from System object of blocks */

/* Initialize UART module */
UART_Type_T * MW_UART_Initialize(UART_Type_T  * SCIModule);
/* Receive the data over UART in Polling mode*/
MW_SCI_Status_Type MW_UART_ReceiveUsingPolling(UART_Type_T * h, void * RxDataPtr, uint32_T RxDataLength, uint32_T * receivedLength, uint32_T timeout);
/* Receive the data over UART using DMA/Interrupt and buffer */
MW_SCI_Status_Type MW_UART_ReceiveUsingBuffer(UART_Type_T * h, void * RxDataPtr, uint32_T RxDataLength, uint32_T * receivedLength);
/* Transmit the data over UART in Polling mode*/
MW_SCI_Status_Type MW_UART_TransmitUsingPolling(UART_Type_T * h, void  * TxDataPtr, uint32_T TxDataLength, uint32_T timeout, uint32_T *sentDataLength);
/* Transmit the data over UART using Interrupts */
MW_SCI_Status_Type MW_UART_TransmitUsingInterrupt(UART_Type_T * h, void * TxDataPtr, uint32_T TxDataLength, uint32_T timeout,uint32_T *sentDataLength);
/* Transmit the data over UART using DMA*/
MW_SCI_Status_Type MW_UART_TransmitUsingDMA(UART_Type_T * h, void * TxDataPtr, uint32_T TxDataLength, uint32_T timeout,uint32_T *sentDataLength);
/* Release UART module */
void MW_UART_DeInit(UART_Type_T * h);

#endif
