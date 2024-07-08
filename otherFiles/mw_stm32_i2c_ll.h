/* Copyright 2022 The MathWorks, Inc. */
#ifndef __MW_STM32_I2C_LL_H__
#define __MW_STM32_I2C_LL_H__

#include "main.h"

/* Status */
#define MW_I2C_STATUS_SUCCESS               0x00UL
#define MW_I2C_STATUS_BUSY                  0x01UL
#define MW_I2C_STATUS_ARBITRATION_LOST      0x02UL
#define MW_I2C_STATUS_NO_ACKNOWLEDGE        0x04UL
#define MW_I2C_STATUS_BUS_ERROR             0x08UL
#define MW_I2C_STATUS_BUS_NOT_IN_USE        0x10UL
#define MW_I2C_STATUS_AS_CONTROLLER         0x20UL
#define MW_I2C_STATUS_AS_PERIPHERAL         0x40UL
#define MW_I2C_STATUS_NOT_SUCCESS			0x80UL
#define MW_I2C_STATUS_INVALID_BUS			0x100UL
#define MW_I2C_STATUS_TIMEOUT				0x200UL
#define MW_I2C_STATUS_OVERRUN_UNERRUN		0x400UL
/* Flag status */
#define MW_I2C_FLAG_ACTIVE                  0x01
#define MW_I2C_FLAG_INACTIVE                0x00
#define MW_I2C_FLAG_TIMEOUT                 0x02
/* Address modes */
#define MW_I2C_ADDRESS_MODE_7BITS			0x00UL
#define MW_I2C_ADDRESS_MODE_10BITS			0x01UL
/* Communication USING */
#define MW_I2C_COMMUNICATION_POLLING        0x00UL
#define MW_I2C_COMMUNICATION_INTERRUPT      0x01UL
#define MW_I2C_COMMUNICATION_DMA            0x02UL
/* COMMUNICATION Sequence */
#define MW_I2C_COMM_SEQ_READ_ONLY			0x01UL
#define MW_I2C_COMM_SEQ_WRITE_ONLY			0x02UL
#define MW_I2C_COMM_SEQ_READ_1ST_AND_WRITE	0x04UL
#define MW_I2C_COMM_SEQ_WRITE_1ST_AND_READ	0x08UL
/* Data Exchange mode */
#define MW_I2C_EXCH_MODE_TRANSMIT			0x01UL
#define MW_I2C_EXCH_MODE_RECEIVE			0x02UL
#define MW_I2C_EXCH_MODE_START				0x10UL
#define MW_I2C_EXCH_MODE_STOP				0x20UL
#define MW_I2C_EXCH_MODE_SEND_NACK_AT_END	0x40UL
#define MW_I2C_EXCH_MODE_PERIPHERAL			0x80UL

#define MW_ISEQUAL_TO_NULL(x)               ((void *)(x) == NULL)

typedef struct STM32_I2C_DataBufferSturct_T_ {
    uint32_t bufferSize;
    uint32_t exchangedCount;
    uint16_t peripheralAddress;
    uint16_t exchMode;
    uint8_t * dataPtr;
} STM32_I2C_DataBufferSturct_T;

typedef struct STM32_I2C_ModuleStruct_T_ {
    uint32_t status;                                /* State to hold busy status */
    uint32_t lastError;                             /* Holds the error state of I2C during communication */
    uint32_t currentUsageMode;                      /* Usage as Controller or Peripheral or Not in use */
    uint32_t txCommunicationMode;                   /* Communicate using polling/interrupt/DMA */
    uint32_t rxCommunicationMode;                   /* Communicate using polling/interrupt/DMA */
    struct STM32_I2C_Struct_T_ * blockStructPtr;    /* Hold address of block structure. This pointer will be helpful in Interrupt handlers to access data structures allocated for block. */
    void * instance;                                /* I2C module peripheral memory address */
} STM32_I2C_ModuleStruct_T;

struct STM32_I2C_Struct_T_ {
    STM32_I2C_ModuleStruct_T * h_i2c;
    STM32_I2C_DataBufferSturct_T * rxBufferStructPtr;
    STM32_I2C_DataBufferSturct_T * txBufferStructPtr;
};

typedef struct STM32_I2C_Struct_T_ STM32_I2C_Struct_T;

/* Function to open */
STM32_I2C_Struct_T * I2C_Init(void * i2c_module, STM32_I2C_Struct_T * i2c_BlockStructPtr);
/* Send Data */

uint32_t I2C_Controller_TransmitData_Polling(STM32_I2C_Struct_T * h_i2cBlock, uint16_t peripheralAddress, const uint8_t * txData, uint32_t dataLength, uint8_t RepeatedStart, uint8_t SendNoAck, uint32_t timeout);
uint32_t I2C_Controller_TransmitData_IT(STM32_I2C_Struct_T * h_i2cBlock, uint16_t peripheralAddress, const uint8_t * txData, uint32_t dataLength, uint8_t RepeatedStart, uint8_t SendNoAck, uint32_t timeout);
uint32_t I2C_Controller_TransmitData_DMA(STM32_I2C_Struct_T * h_i2cBlock, uint16_t peripheralAddress, const uint8_t * txData, uint32_t dataLength, uint8_t RepeatedStart, uint8_t SendNoAck, uint32_t timeout);
/* Receive Data */
uint32_t I2C_Controller_ReceiveData_Polling(STM32_I2C_Struct_T * h_i2cBlock, uint16_t peripheralAddress, uint8_t * rxData, uint32_t dataLength, uint8_t RepeatedStart, uint8_t SendNoAck, uint32_t timeout);
uint32_t I2C_Controller_ReceiveData_IT(STM32_I2C_Struct_T * h_i2cBlock, uint16_t peripheralAddress, uint8_t * rxData, uint32_t dataLength, uint8_t RepeatedStart, uint8_t SendNoAck, uint32_t timeout);
uint32_t I2C_Controller_ReceiveData_DMA(STM32_I2C_Struct_T * h_i2cBlock, uint16_t peripheralAddress, uint8_t * rxData, uint32_t dataLength, uint8_t RepeatedStart, uint8_t SendNoAck, uint32_t timeout);
/* Get Status */
uint32_t I2C_GetStatus(STM32_I2C_Struct_T * h_i2c);

#endif
