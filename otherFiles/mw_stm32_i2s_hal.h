/* Copyright 2022 The MathWorks, Inc. */
#ifndef __MW_I2S_H__
#define __MW_I2S_H__

#include "main.h"

#define MW_GET_DATA_PTR(x) x

/* Define global variables for I2S1 */
#if defined(MW_SPI1_AS_I2S1) && defined(SPI1)
    #if defined(MW_I2S1_PDM2PCM_RECEIVE_BUFFER_SIZE)
    extern uint16_t MW_I2S1_PDM2PCMReceiveBuffer[MW_I2S1_PDM2PCM_RECEIVE_BUFFER_SIZE];
    #define MW_I2S1_GET_PDM2PCM_RECEIVE_BUFFER_PTR() (&MW_I2S1_PDM2PCMReceiveBuffer[0])
    #endif

    /* Define Receive buffer */
    #if defined(MW_I2S1_RECEIVE_BUFFER_SIZE)
    extern uint16_t MW_I2S1_ReceiveBuffer[MW_I2S1_RECEIVE_BUFFER_SIZE];
    #define MW_I2S1_GET_RECEIVE_BUFFER_PTR() (&MW_I2S1_ReceiveBuffer[0])
    #endif
    
    /* Define Transmit buffer */
    #if defined(MW_I2S1_TRANSMIT_BUFFER_SIZE)
    extern uint16_t MW_I2S1_TransmitBuffer[MW_I2S1_TRANSMIT_BUFFER_SIZE];
    #define MW_I2S1_GET_TRANSMIT_BUFFER_PTR() (&MW_I2S1_TransmitBuffer[0])
    #endif
#endif

/* Define global variables for I2S2 */
#if defined(MW_SPI2_AS_I2S2) && defined(SPI2)
    #if defined(MW_I2S2_PDM2PCM_RECEIVE_BUFFER_SIZE)
    extern uint16_t MW_I2S2_PDM2PCMReceiveBuffer[MW_I2S2_PDM2PCM_RECEIVE_BUFFER_SIZE];
    #define MW_I2S2_GET_PDM2PCM_RECEIVE_BUFFER_PTR() (&MW_I2S2_PDM2PCMReceiveBuffer[0])
    #endif

    /* Define Receive buffer */
    #if defined(MW_I2S2_RECEIVE_BUFFER_SIZE)
    extern uint16_t MW_I2S2_ReceiveBuffer[MW_I2S2_RECEIVE_BUFFER_SIZE];
    #define MW_I2S2_GET_RECEIVE_BUFFER_PTR() (&MW_I2S2_ReceiveBuffer[0])
    #endif
    
    /* Define Transmit buffer */
    #if defined(MW_I2S2_TRANSMIT_BUFFER_SIZE)
    extern uint16_t MW_I2S2_TransmitBuffer[MW_I2S2_TRANSMIT_BUFFER_SIZE];
    #define MW_I2S2_GET_TRANSMIT_BUFFER_PTR() (&MW_I2S2_TransmitBuffer[0])
    #endif
#endif

#if defined(MW_SPI3_AS_I2S3) && defined(SPI3)
    #if defined(MW_I2S3_PDM2PCM_RECEIVE_BUFFER_SIZE)
    extern uint16_t MW_I2S3_PDM2PCMReceiveBuffer[MW_I2S3_PDM2PCM_RECEIVE_BUFFER_SIZE];
    #define MW_I2S3_GET_PDM2PCM_RECEIVE_BUFFER_PTR() (&MW_I2S3_PDM2PCMReceiveBuffer[0])
    #endif

    /* Define Receive buffer */
    #if defined(MW_I2S3_RECEIVE_BUFFER_SIZE)
    extern uint16_t MW_I2S3_ReceiveBuffer[MW_I2S3_RECEIVE_BUFFER_SIZE];
    #define MW_I2S3_GET_RECEIVE_BUFFER_PTR() (&MW_I2S3_ReceiveBuffer[0])
    #endif
    
    /* Define Transmit buffer */
    #if defined(MW_I2S3_TRANSMIT_BUFFER_SIZE)
    extern uint16_t MW_I2S3_TransmitBuffer[MW_I2S3_TRANSMIT_BUFFER_SIZE];
    #define MW_I2S3_GET_TRANSMIT_BUFFER_PTR() (&MW_I2S3_TransmitBuffer[0])
    #endif
#endif

typedef enum _MW_I2S_OperatingMode_Type_T {
    MW_I2S_USING_DMA = 0,
    MW_I2S_USING_INTERRUPT,
    MW_I2S_USING_POLLING
} MW_I2S_OperatingMode_Type_T;

typedef enum _MW_I2S_FrameDataType_T {
    MW_I2S_FRAME_DATATYPE_UINT16 = 0x01,
    MW_I2S_FRAME_DATATYPE_UINT32 = 0x10
} MW_I2S_FrameDataType_T;

typedef enum _MW_I2S_ReceiveTransmit_Type_T {
    MW_I2S_NONE = 0x00,
    MW_I2S_RECEIVE = 0x01,
    MW_I2S_TRANSMIT = 0x02,
    MW_I2S_BOTH = 0x03
} MW_I2S_ReceiveTransmit_Type_T;

typedef struct _MW_I2S_Handle_Type_T {
    uint32_t TxBufferSize;              /* Transmit Buffer Size */
    uint32_t RxBufferSize;              /* Receive Buffer Size */
    uint32_t RxPDM2PCMBufferSize;       /* Receive PDM2PCM buffer size */
    uint8_t ReceiveOrTransmit;          /* Receive, Transmit or Both */
    uint8_t OperatingMode;              /* Using DMA, Interrupt or Polling */
    uint8_t RxPDMStreamEnabled;         /* Receive PDM stream of data */
    uint8_t RxPDMDecimationFactor;      /* Receive PDM Decimation factor */
    uint8_t NumberOfChannels;           /* Mono - 1, Stereo - 2 */
    uint8_t FrameDataType;              /* uint16 or uint32 */
    void * PDM2PCMRxBufferPtr;          /* PDM2PCM Filter buffer pointer */
    void * TxBufferPtr;                 /* Transmit Buffer pointer */
    void * RxBufferPtr;                 /* Receive Buffer pointer */
    void * CopyFromRxBufferPtr;
    void * CopyToTxBufferPtr;
    I2S_HandleTypeDef * HAL_I2S_Ptr;    /* HAL I2S driver handle */
} MW_I2S_Handle_Type_T;


void * MW_I2S_Open(SPI_TypeDef * i2sModule,MW_I2S_Handle_Type_T * i2sConfig);
void MW_I2S_SetAudioFrequencyAndStartDMA(MW_I2S_Handle_Type_T * h_i2s, uint32_t audioFrequency, uint8_t numberOfChannels, uint8_t dataFormat);
void MW_I2S_WriteDMA_16bits(MW_I2S_Handle_Type_T * h_i2s, void * dataPtr, uint32_t dataSize, uint8_t numberOfChannels);
void MW_I2S_WriteDMA_32bits(MW_I2S_Handle_Type_T * h_i2s, void * dataPtr, uint32_t dataSize, uint8_t numberOfChannels);
void MW_I2S_ReadDMA_16bits(MW_I2S_Handle_Type_T * h_i2s, void * dataPtr, uint32_t dataSize, uint8_t numberOfChannels);
void MW_I2S_ReadDMA_32bits(MW_I2S_Handle_Type_T * h_i2s, void * dataPtr, uint32_t dataSize, uint8_t numberOfChannels);
void MW_I2S_CloseDMA(MW_I2S_Handle_Type_T * h_i2s);

#endif

/* LocalWords:  PDM PCM
 */
