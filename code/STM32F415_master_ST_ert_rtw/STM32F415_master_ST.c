/*
 * File: STM32F415_master_ST.c
 *
 * Code generated for Simulink model 'STM32F415_master_ST'.
 *
 * Model version                  : 1.146
 * Simulink Coder version         : 23.2 (R2023b) 01-Aug-2023
 * C/C++ source code generated on : Mon Jul  8 23:31:52 2024
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives:
 *    1. RAM efficiency
 *    2. Execution efficiency
 *    3. Safety precaution
 *    4. Traceability
 * Validation result: Not run
 */

#include "STM32F415_master_ST.h"
#include "STM32F415_master_ST_types.h"
#include <string.h>
#include "rtwtypes.h"
#include "stm_timer_ll.h"
#include "STM32F415_master_ST_private.h"

/* Block signals (default storage) */
B_STM32F415_master_ST_T STM32F415_master_ST_B;

/* Block states (default storage) */
DW_STM32F415_master_ST_T STM32F415_master_ST_DW;

/* data stores shared across model instances */
SharedDSM_STM32F415_master_ST_T STM32F415_master_ST_SharedDSM;/* '<Root>/Data Store Memory1' */

/* Real-time model */
static RT_MODEL_STM32F415_master_ST_T STM32F415_master_ST_M_;
RT_MODEL_STM32F415_master_ST_T *const STM32F415_master_ST_M =
  &STM32F415_master_ST_M_;

/* Forward declaration for local functions */
static void STM32F415_SystemCore_setup_poof(stm32cube_blocks_UARTWrite_ST_T *obj);
static void STM32F415_ma_SystemCore_setup_p(stm32cube_blocks_UARTWrite_ST_T *obj);
static void STM32F415_m_SystemCore_setup_po(stm32cube_blocks_UARTWrite_ST_T *obj);
static void STM32F415__SystemCore_setup_poo(stm32cube_blocks_UARTWrite_ST_T *obj);
static void STM32_SystemCore_setup_poofajod(stm32cube_blocks_UARTRead_STM_T *obj);
static void STM32F41_SystemCore_setup_poofa(stm32cube_blocks_UARTRead_S_p_T *obj);
static void STM32F415_mast_SystemCore_setup(stm32cube_blocks_UARTRead_STM_T *obj);
static void STM32F_SystemCore_setup_poofajo(stm32cube_blocks_TimerBlock_S_T *obj);
static void rate_monotonic_scheduler(void);

/*
 * Set which subrates need to run this base step (base rate always runs).
 * This function must be called prior to calling the model step function
 * in order to remember which rates need to run this base step.  The
 * buffering of events allows for overlapping preemption.
 */
void STM32F415_master_ST_SetEventsForThisBaseStep(boolean_T *eventFlags)
{
  /* Task runs when its counter is zero, computed via rtmStepTask macro */
  eventFlags[1] = ((boolean_T)rtmStepTask(STM32F415_master_ST_M, 1));
  eventFlags[2] = ((boolean_T)rtmStepTask(STM32F415_master_ST_M, 2));
  eventFlags[3] = ((boolean_T)rtmStepTask(STM32F415_master_ST_M, 3));
  eventFlags[4] = ((boolean_T)rtmStepTask(STM32F415_master_ST_M, 4));
}

/*
 *         This function updates active task flag for each subrate
 *         and rate transition flags for tasks that exchange data.
 *         The function assumes rate-monotonic multitasking scheduler.
 *         The function must be called at model base rate so that
 *         the generated code self-manages all its subrates and rate
 *         transition flags.
 */
static void rate_monotonic_scheduler(void)
{
  /* Compute which subrates run during the next base time step.  Subrates
   * are an integer multiple of the base rate counter.  Therefore, the subtask
   * counter is reset when it reaches its limit (zero means run).
   */
  (STM32F415_master_ST_M->Timing.TaskCounters.TID[1])++;
  if ((STM32F415_master_ST_M->Timing.TaskCounters.TID[1]) > 1) {/* Sample time: [0.00025s, 0.0s] */
    STM32F415_master_ST_M->Timing.TaskCounters.TID[1] = 0;
  }

  (STM32F415_master_ST_M->Timing.TaskCounters.TID[2])++;
  if ((STM32F415_master_ST_M->Timing.TaskCounters.TID[2]) > 2) {/* Sample time: [0.000375s, 0.0s] */
    STM32F415_master_ST_M->Timing.TaskCounters.TID[2] = 0;
  }

  (STM32F415_master_ST_M->Timing.TaskCounters.TID[3])++;
  if ((STM32F415_master_ST_M->Timing.TaskCounters.TID[3]) > 11) {/* Sample time: [0.0015s, 0.0s] */
    STM32F415_master_ST_M->Timing.TaskCounters.TID[3] = 0;
  }

  (STM32F415_master_ST_M->Timing.TaskCounters.TID[4])++;
  if ((STM32F415_master_ST_M->Timing.TaskCounters.TID[4]) > 79) {/* Sample time: [0.01s, 0.0s] */
    STM32F415_master_ST_M->Timing.TaskCounters.TID[4] = 0;
  }
}

static void STM32F415_SystemCore_setup_poof(stm32cube_blocks_UARTWrite_ST_T *obj)
{
  UART_Type_T b;
  obj->isSetupComplete = false;

  /* Start for MATLABSystem: '<S23>/UART//USART Write' incorporates:
   *  MATLABSystem: '<S25>/UART//USART Write'
   */
  obj->isInitialized = 1;
  b.buffer.txBufferPtr = (void*)(&obj->UARTInternalBuffer[0]);
  b.enableRxOrTx = 2U;
  b.mode = UART_TX_INTERRUPT_MODE;
  b.peripheralPtr = USART2;
  b.txdmaPeripheralPtr = NULL;
  b.txdmastream = 0;
  b.buffer.txBufferSize = 128U;
  obj->UARTHandle = MW_UART_Initialize(&b);
  obj->isSetupComplete = true;
}

static void STM32F415_ma_SystemCore_setup_p(stm32cube_blocks_UARTWrite_ST_T *obj)
{
  UART_Type_T b;
  obj->isSetupComplete = false;

  /* Start for MATLABSystem: '<S13>/UART//USART Write' */
  obj->isInitialized = 1;
  b.buffer.txBufferPtr = (void*)(&obj->UARTInternalBuffer[0]);
  b.enableRxOrTx = 2U;
  b.mode = UART_TX_INTERRUPT_MODE;
  b.peripheralPtr = UART4;
  b.txdmaPeripheralPtr = NULL;
  b.txdmastream = 0;
  b.buffer.txBufferSize = 128U;
  obj->UARTHandle = MW_UART_Initialize(&b);
  obj->isSetupComplete = true;
}

static void STM32F415_m_SystemCore_setup_po(stm32cube_blocks_UARTWrite_ST_T *obj)
{
  UART_Type_T b;
  obj->isSetupComplete = false;

  /* Start for MATLABSystem: '<S16>/UART//USART Write' */
  obj->isInitialized = 1;
  b.buffer.txBufferPtr = (void*)(&obj->UARTInternalBuffer[0]);
  b.enableRxOrTx = 2U;
  b.mode = UART_TX_INTERRUPT_MODE;
  b.peripheralPtr = USART6;
  b.txdmaPeripheralPtr = NULL;
  b.txdmastream = 0;
  b.buffer.txBufferSize = 128U;
  obj->UARTHandle = MW_UART_Initialize(&b);
  obj->isSetupComplete = true;
}

static void STM32F415__SystemCore_setup_poo(stm32cube_blocks_UARTWrite_ST_T *obj)
{
  UART_Type_T b;
  obj->isSetupComplete = false;

  /* Start for MATLABSystem: '<S5>/UART//USART Write' */
  obj->isInitialized = 1;
  b.buffer.txBufferPtr = (void*)(&obj->UARTInternalBuffer[0]);
  b.enableRxOrTx = 2U;
  b.mode = UART_TX_INTERRUPT_MODE;
  b.peripheralPtr = UART5;
  b.txdmaPeripheralPtr = NULL;
  b.txdmastream = 0;
  b.buffer.txBufferSize = 128U;
  obj->UARTHandle = MW_UART_Initialize(&b);
  obj->isSetupComplete = true;
}

static void STM32_SystemCore_setup_poofajod(stm32cube_blocks_UARTRead_STM_T *obj)
{
  UART_Type_T b;
  obj->isSetupComplete = false;

  /* Start for MATLABSystem: '<Root>/UART//USART Read6' */
  obj->isInitialized = 1;
  b.buffer.rxBufferPtr = (void*)(&obj->UARTInternalBuffer[0]);
  b.enableRxOrTx = 1.0;

  /* Start for MATLABSystem: '<Root>/UART//USART Read6' */
  b.mode = UART_RX_INTERRUPT_MODE;
  b.peripheralPtr = USART2;
  b.rxdmaPeripheralPtr = NULL;
  b.rxdmastream = 0;
  b.disableDMAIntOnError = false;

  /* Start for MATLABSystem: '<Root>/UART//USART Read6' */
  b.buffer.rxBufferSize = 128U;
  obj->UARTHandle = MW_UART_Initialize(&b);
  obj->isSetupComplete = true;
}

static void STM32F41_SystemCore_setup_poofa(stm32cube_blocks_UARTRead_S_p_T *obj)
{
  UART_Type_T b;
  obj->isSetupComplete = false;

  /* Start for MATLABSystem: '<Root>/MAV Receiver' */
  obj->isInitialized = 1;
  b.buffer.rxBufferPtr = (void*)(&obj->UARTInternalBuffer[0]);
  b.enableRxOrTx = 1.0;

  /* Start for MATLABSystem: '<Root>/MAV Receiver' */
  b.mode = UART_RX_INTERRUPT_MODE;
  b.peripheralPtr = UART4;
  b.rxdmaPeripheralPtr = NULL;
  b.rxdmastream = 0;
  b.disableDMAIntOnError = false;

  /* Start for MATLABSystem: '<Root>/MAV Receiver' */
  b.buffer.rxBufferSize = 304U;
  obj->UARTHandle = MW_UART_Initialize(&b);
  obj->isSetupComplete = true;
}

static void STM32F415_mast_SystemCore_setup(stm32cube_blocks_UARTRead_STM_T *obj)
{
  UART_Type_T b;
  obj->isSetupComplete = false;

  /* Start for MATLABSystem: '<Root>/AT Receiver' */
  obj->isInitialized = 1;
  b.buffer.rxBufferPtr = (void*)(&obj->UARTInternalBuffer[0]);
  b.enableRxOrTx = 1.0;

  /* Start for MATLABSystem: '<Root>/AT Receiver' */
  b.mode = UART_RX_INTERRUPT_MODE;
  b.peripheralPtr = USART6;
  b.rxdmaPeripheralPtr = NULL;
  b.rxdmastream = 0;
  b.disableDMAIntOnError = false;

  /* Start for MATLABSystem: '<Root>/AT Receiver' */
  b.buffer.rxBufferSize = 128U;
  obj->UARTHandle = MW_UART_Initialize(&b);
  obj->isSetupComplete = true;
}

static void STM32F_SystemCore_setup_poofajo(stm32cube_blocks_TimerBlock_S_T *obj)
{
  TIM_Type_T b;
  boolean_T isSlaveModeTriggerEnabled;

  /* Start for MATLABSystem: '<Root>/Timer' */
  obj->isInitialized = 1;
  b.PeripheralPtr = TIM6;
  b.isCenterAlignedMode = false;

  /* Start for MATLABSystem: '<Root>/Timer' */
  b.repetitionCounter = 0U;
  obj->TimerHandle = Timer_Handle_Init(&b);
  enableTimerInterrupts(obj->TimerHandle, 0);
  isSlaveModeTriggerEnabled = isSlaveTriggerModeEnabled(obj->TimerHandle);
  if (!isSlaveModeTriggerEnabled) {
    /* Start for MATLABSystem: '<Root>/Timer' */
    enableCounter(obj->TimerHandle, false);
  }

  obj->isSetupComplete = true;
}

/* Model step function for TID0 */
void STM32F415_master_ST_step0(void)   /* Sample time: [0.000125s, 0.0s] */
{
  {                                    /* Sample time: [0.000125s, 0.0s] */
    rate_monotonic_scheduler();
  }
}

/* Model step function for TID1 */
void STM32F415_master_ST_step1(void)   /* Sample time: [0.00025s, 0.0s] */
{
  int32_T dataInLen;
  int32_T i;
  int32_T i_0;
  uint32_T dataBytesToRead;
  uint32_T sentLength;
  uint16_T b_varargout_2;
  uint8_T b_varargout_3;
  uint8_T uartReadData;

  /* MATLABSystem: '<Root>/UART//USART Read6' */
  dataBytesToRead = getBytesToBeReadFromBuffer
    (STM32F415_master_ST_DW.obj_d.UARTHandle, 1U, 0U);
  if (dataBytesToRead > 0U) {
    MW_UART_ReceiveUsingBuffer(STM32F415_master_ST_DW.obj_d.UARTHandle,
      &uartReadData, dataBytesToRead, &sentLength);
  } else {
    getReadErrorStatus(STM32F415_master_ST_DW.obj_d.UARTHandle);
    sentLength = 0U;
  }

  /* Outputs for Enabled SubSystem: '<Root>/Enabled Subsystem' incorporates:
   *  EnablePort: '<S4>/Enable'
   */
  /* RelationalOperator: '<S1>/Compare' incorporates:
   *  Constant: '<S11>/Constant'
   *  Constant: '<S12>/Constant'
   *  Constant: '<S14>/Constant'
   *  Constant: '<S15>/Constant'
   *  Constant: '<S17>/Constant'
   *  Constant: '<S18>/Constant'
   *  Constant: '<S1>/Constant'
   *  Logic: '<S10>/AND'
   *  Logic: '<S8>/AND'
   *  Logic: '<S9>/AND'
   *  MATLAB Function: '<S19>/MATLAB Function'
   *  MATLABSystem: '<Root>/UART//USART Read6'
   *  MATLABSystem: '<S4>/MATLAB System'
   *  RelationalOperator: '<S11>/Compare'
   *  RelationalOperator: '<S12>/Compare'
   *  RelationalOperator: '<S14>/Compare'
   *  RelationalOperator: '<S15>/Compare'
   *  RelationalOperator: '<S17>/Compare'
   *  RelationalOperator: '<S18>/Compare'
   * */
  if (sentLength > STM32F415_master_ST_P.Constant_Value_o) {
    /* MATLABSystem: '<S4>/MATLAB System' */
    /*  Initialize output data and its length */
    memcpy(&STM32F415_master_ST_B.b_varargout_1[0],
           &STM32F415_master_ST_DW.obj.zeroBuffer[0], 300U * sizeof(uint8_T));
    b_varargout_2 = 0U;
    b_varargout_3 = 0U;

    /*  Check for double start symbol to begin */
    if ((uartReadData == STM32F415_master_ST_DW.obj.startSymbol) &&
        (!STM32F415_master_ST_DW.obj.isDetecting)) {
      /*  Reset system state */
      memset(&STM32F415_master_ST_DW.obj.buffer[0], 0, 300U * sizeof(uint8_T));
      STM32F415_master_ST_DW.obj.pointer = 1U;
      STM32F415_master_ST_DW.obj.preambleLength = 0U;
      STM32F415_master_ST_DW.obj.isDetecting = true;
    }

    /*  Store symbols in buffer if detecting */
    if (STM32F415_master_ST_DW.obj.isDetecting) {
      STM32F415_master_ST_DW.obj.buffer[STM32F415_master_ST_DW.obj.pointer - 1] =
        uartReadData;

      /*  Determine the preamble length from the 4th byte */
      if (STM32F415_master_ST_DW.obj.pointer == 5) {
        /*  Check if the input is a vector of two uint8 elements */
        /*  Extract the lower and upper uint8 values from the input vector */
        /*  Combine the two uint8 values into one uint16 value */
        sentLength = (uint32_T)(STM32F415_master_ST_DW.obj.buffer[4] << 8 |
          STM32F415_master_ST_DW.obj.buffer[3]) + 5U;
        if (sentLength > 65535U) {
          sentLength = 65535U;
        }

        STM32F415_master_ST_DW.obj.preambleLength = (uint16_T)sentLength;
      }

      sentLength = STM32F415_master_ST_DW.obj.pointer + 1U;
      if (STM32F415_master_ST_DW.obj.pointer + 1U > 65535U) {
        sentLength = 65535U;
      }

      STM32F415_master_ST_DW.obj.pointer = (uint16_T)sentLength;

      /*  Check if a complete preamble is detected */
      i = (int32_T)(STM32F415_master_ST_DW.obj.pointer - /*MW:OvSatOk*/ 1U);
      if (STM32F415_master_ST_DW.obj.pointer - 1U >
          STM32F415_master_ST_DW.obj.pointer) {
        i = 0;
      }

      if (i == STM32F415_master_ST_DW.obj.preambleLength) {
        sentLength = STM32F415_master_ST_DW.obj.pointer + 4U;
        if (STM32F415_master_ST_DW.obj.pointer + 4U > 65535U) {
          sentLength = 65535U;
        }

        if ((uint16_T)sentLength < 6) {
          i = 0;
          dataInLen = -1;
        } else {
          i = 5;
          dataInLen = (uint16_T)sentLength - 1;
        }

        dataInLen -= i;
        for (i_0 = 0; i_0 <= dataInLen; i_0++) {
          STM32F415_master_ST_B.b_varargout_1[i_0] =
            STM32F415_master_ST_DW.obj.buffer[i + i_0];
        }

        sentLength = STM32F415_master_ST_DW.obj.pointer - 6U;
        if (STM32F415_master_ST_DW.obj.pointer - 6U >
            STM32F415_master_ST_DW.obj.pointer) {
          sentLength = 0U;
        }

        b_varargout_2 = (uint16_T)sentLength;
        b_varargout_3 = STM32F415_master_ST_DW.obj.buffer[2];

        /*  Reset system state */
        memset(&STM32F415_master_ST_DW.obj.buffer[0], 0, 300U * sizeof(uint8_T));
        STM32F415_master_ST_DW.obj.pointer = 1U;
        STM32F415_master_ST_DW.obj.isDetecting = false;
        STM32F415_master_ST_DW.obj.preambleLength = 0U;
      }
    }

    /*  Handle buffer overflow */
    if (STM32F415_master_ST_DW.obj.pointer > 300) {
      /*  Reset system state */
      memset(&STM32F415_master_ST_DW.obj.buffer[0], 0, 300U * sizeof(uint8_T));
      STM32F415_master_ST_DW.obj.pointer = 1U;
      STM32F415_master_ST_DW.obj.isDetecting = false;
      STM32F415_master_ST_DW.obj.preambleLength = 0U;
    }

    /* Outputs for Enabled SubSystem: '<S8>/Subsystem' incorporates:
     *  EnablePort: '<S13>/Enable'
     */
    if ((b_varargout_2 > STM32F415_master_ST_P.Constant_Value_b) &&
        (b_varargout_3 == STM32F415_master_ST_P.CompareToConstant_const)) {
      /* MATLABSystem: '<S13>/UART//USART Write' */
      dataInLen = 300;
      if (b_varargout_2 < 300U) {
        dataInLen = b_varargout_2;
      }

      memcpy(&STM32F415_master_ST_B.uartWriteData_m[0],
             &STM32F415_master_ST_B.b_varargout_1[0], 300U * sizeof(uint8_T));
      MW_UART_TransmitUsingInterrupt(STM32F415_master_ST_DW.obj_pi.UARTHandle,
        &STM32F415_master_ST_B.uartWriteData_m[0], (uint32_T)dataInLen, 0U,
        &sentLength);

      /* End of MATLABSystem: '<S13>/UART//USART Write' */
    }

    /* End of Outputs for SubSystem: '<S8>/Subsystem' */

    /* Outputs for Enabled SubSystem: '<S9>/Subsystem' incorporates:
     *  EnablePort: '<S16>/Enable'
     */
    if ((b_varargout_2 > STM32F415_master_ST_P.Constant_Value_c) &&
        (b_varargout_3 == STM32F415_master_ST_P.CompareToConstant_const_m)) {
      /* MATLABSystem: '<S16>/UART//USART Write' */
      dataInLen = 300;
      if (b_varargout_2 < 300U) {
        dataInLen = b_varargout_2;
      }

      memcpy(&STM32F415_master_ST_B.uartWriteData_m[0],
             &STM32F415_master_ST_B.b_varargout_1[0], 300U * sizeof(uint8_T));
      MW_UART_TransmitUsingInterrupt(STM32F415_master_ST_DW.obj_nc.UARTHandle,
        &STM32F415_master_ST_B.uartWriteData_m[0], (uint32_T)dataInLen, 0U,
        &sentLength);

      /* End of MATLABSystem: '<S16>/UART//USART Write' */
    }

    /* End of Outputs for SubSystem: '<S9>/Subsystem' */

    /* Outputs for Enabled SubSystem: '<S10>/Subsystem' incorporates:
     *  EnablePort: '<S19>/Enable'
     */
    if ((b_varargout_2 > STM32F415_master_ST_P.Constant_Value_a) &&
        (b_varargout_3 == STM32F415_master_ST_P.CompareToConstant_const_e)) {
      /* Outputs for Enabled SubSystem: '<S19>/Subsystem' incorporates:
       *  EnablePort: '<S21>/Enable'
       */
      if ((STM32F415_master_ST_B.b_varargout_1[0] == 15) &&
          ((STM32F415_master_ST_B.b_varargout_1[24] == 0) &&
           (STM32F415_master_ST_B.b_varargout_1[23] == 0))) {
        /* DataStoreWrite: '<S21>/Data Store Write' */
        memcpy(&STM32F415_master_ST_SharedDSM.sbusSignal[0],
               &STM32F415_master_ST_B.b_varargout_1[0], 300U * sizeof(uint8_T));

        /* DataStoreWrite: '<S21>/Data Store Write2' */
        STM32F415_master_ST_SharedDSM.sbusLengrh = b_varargout_2;
      }

      /* End of Outputs for SubSystem: '<S19>/Subsystem' */
    }

    /* End of Outputs for SubSystem: '<S10>/Subsystem' */
  }

  /* End of RelationalOperator: '<S1>/Compare' */
  /* End of Outputs for SubSystem: '<Root>/Enabled Subsystem' */
}

/* Model step function for TID2 */
void STM32F415_master_ST_step2(void)   /* Sample time: [0.000375s, 0.0s] */
{
  int32_T i;
  uint32_T dataBytesToRead;
  uint32_T sentLength;
  uint16_T b_varargout_2;
  uint8_T uartReadData;

  /* MATLABSystem: '<Root>/MAV Receiver' */
  dataBytesToRead = getBytesToBeReadFromBuffer
    (STM32F415_master_ST_DW.obj_n.UARTHandle, 1U, 0U);
  if (dataBytesToRead > 0U) {
    MW_UART_ReceiveUsingBuffer(STM32F415_master_ST_DW.obj_n.UARTHandle,
      &uartReadData, dataBytesToRead, &sentLength);
  } else {
    getReadErrorStatus(STM32F415_master_ST_DW.obj_n.UARTHandle);
    sentLength = 0U;
  }

  /* Outputs for Enabled SubSystem: '<Root>/Mav Deserializer' incorporates:
   *  EnablePort: '<S7>/Enable'
   */
  /* RelationalOperator: '<S2>/Compare' incorporates:
   *  Constant: '<S2>/Constant'
   *  MATLABSystem: '<Root>/MAV Receiver'
   * */
  if (sentLength > STM32F415_master_ST_P.Constant_Value_d) {
    /* MATLABSystem: '<S7>/MATLAB System' */
    /*  Initialize output data and its length */
    memcpy(&STM32F415_master_ST_B.b_varargout_1_c[0],
           &STM32F415_master_ST_DW.obj_g.emptyBuffer[0], 300U * sizeof(uint8_T));
    b_varargout_2 = 0U;

    /*  Check for start symbol to begin capturing */
    if ((uartReadData == STM32F415_master_ST_DW.obj_g.startSymbol) &&
        (!STM32F415_master_ST_DW.obj_g.isCapturing)) {
      STM32F415_master_ST_DW.obj_g.isCapturing = true;
    }

    /*  strt capturing process */
    if (STM32F415_master_ST_DW.obj_g.isCapturing) {
      STM32F415_master_ST_DW.obj_g.buffer[STM32F415_master_ST_DW.obj_g.pointer -
        1] = uartReadData;
      if (STM32F415_master_ST_DW.obj_g.pointer == 2) {
        STM32F415_master_ST_DW.obj_g.mavFrameLength = (uint16_T)
          (STM32F415_master_ST_DW.obj_g.buffer[1] + 12U);
      }

      /*  increment the pointer */
      sentLength = STM32F415_master_ST_DW.obj_g.pointer + 1U;
      if (STM32F415_master_ST_DW.obj_g.pointer + 1U > 65535U) {
        sentLength = 65535U;
      }

      STM32F415_master_ST_DW.obj_g.pointer = (uint16_T)sentLength;

      /*  detect the end of the message */
      i = (int32_T)(STM32F415_master_ST_DW.obj_g.pointer - 1U);
      if (STM32F415_master_ST_DW.obj_g.pointer - 1U >
          STM32F415_master_ST_DW.obj_g.pointer) {
        i = 0;
      }

      if (STM32F415_master_ST_DW.obj_g.mavFrameLength == i) {
        i = (int32_T)(STM32F415_master_ST_DW.obj_g.pointer - 1U);
        if (STM32F415_master_ST_DW.obj_g.pointer - 1U >
            STM32F415_master_ST_DW.obj_g.pointer) {
          i = 0;
        }

        b_varargout_2 = (uint16_T)i;

        /*  Reset system state */
        for (i = 0; i < 300; i++) {
          STM32F415_master_ST_B.b_varargout_1_c[i] =
            STM32F415_master_ST_DW.obj_g.buffer[i];
          STM32F415_master_ST_DW.obj_g.buffer[i] = 0U;
        }

        STM32F415_master_ST_DW.obj_g.pointer = 1U;
        STM32F415_master_ST_DW.obj_g.isCapturing = false;
        STM32F415_master_ST_DW.obj_g.mavFrameLength = 0U;
      }

      /*  Handle buffer overflow */
      if (STM32F415_master_ST_DW.obj_g.pointer >= 300) {
        /*  Reset system state */
        memset(&STM32F415_master_ST_DW.obj_g.buffer[0], 0, 300U * sizeof(uint8_T));
        STM32F415_master_ST_DW.obj_g.pointer = 1U;
        STM32F415_master_ST_DW.obj_g.isCapturing = false;
        STM32F415_master_ST_DW.obj_g.mavFrameLength = 0U;
      }
    }

    /* RelationalOperator: '<S24>/Compare' incorporates:
     *  Constant: '<S24>/Constant'
     *  MATLABSystem: '<S7>/MATLAB System'
     * */
    STM32F415_master_ST_B.Compare = (b_varargout_2 >
      STM32F415_master_ST_P.Constant_Value_f4);

    /* Outputs for Enabled SubSystem: '<S7>/Enabled Subsystem' incorporates:
     *  EnablePort: '<S25>/Enable'
     */
    if (STM32F415_master_ST_B.Compare) {
      /* Start for MATLABSystem: '<S25>/Mav Frame Encoder' incorporates:
       *  MATLABSystem: '<S7>/MATLAB System'
       * */
      /*  Check if the input is of type uint16 */
      /*  Extract lower 8 bits (least significant byte) */
      /*  255 is 0xFF in hexadecimal */
      /*  Extract upper 8 bits (most significant byte) */
      /*  Shift right by 8 bits and mask with 0xFF */
      /*  Convert to uint8 */
      /*  Create a vector of two uint8 elements */
      sentLength = b_varargout_2 + 5U;
      if (b_varargout_2 + 5U > 65535U) {
        sentLength = 65535U;
      }

      /* MATLABSystem: '<S25>/UART//USART Write' incorporates:
       *  MATLABSystem: '<S25>/Mav Frame Encoder'
       *  MATLABSystem: '<S7>/MATLAB System'
       * */
      i = 305;
      if ((uint16_T)sentLength < 305U) {
        i = (uint16_T)sentLength;
      }

      STM32F415_master_ST_B.uartWriteData[0] = 206U;
      STM32F415_master_ST_B.uartWriteData[1] = 206U;
      STM32F415_master_ST_B.uartWriteData[2] = 1U;
      STM32F415_master_ST_B.uartWriteData[3] = (uint8_T)(b_varargout_2 & 255);
      STM32F415_master_ST_B.uartWriteData[4] = (uint8_T)((uint32_T)b_varargout_2
        >> 8);
      memcpy(&STM32F415_master_ST_B.uartWriteData[5],
             &STM32F415_master_ST_B.b_varargout_1_c[0], 300U * sizeof(uint8_T));
      MW_UART_TransmitUsingInterrupt(STM32F415_master_ST_DW.obj_p.UARTHandle,
        &STM32F415_master_ST_B.uartWriteData[0], (uint32_T)i, 0U, &sentLength);

      /* End of MATLABSystem: '<S25>/UART//USART Write' */
    }

    /* End of Outputs for SubSystem: '<S7>/Enabled Subsystem' */

    /* S-Function (resetState): '<S7>/S-Function Builder1' */
    resetState_Outputs_wrapper(&STM32F415_master_ST_B.Compare);
  }

  /* End of RelationalOperator: '<S2>/Compare' */
  /* End of Outputs for SubSystem: '<Root>/Mav Deserializer' */
}

/* Model step function for TID3 */
void STM32F415_master_ST_step3(void)   /* Sample time: [0.0015s, 0.0s] */
{
  int32_T dataInLen;
  int32_T i;
  uint32_T dataBytesToRead;
  uint32_T sentLength;
  uint16_T b_varargout_2;
  uint8_T uartReadData;

  /* MATLABSystem: '<Root>/AT Receiver' */
  dataBytesToRead = getBytesToBeReadFromBuffer
    (STM32F415_master_ST_DW.obj_e.UARTHandle, 1U, 0U);
  if (dataBytesToRead > 0U) {
    MW_UART_ReceiveUsingBuffer(STM32F415_master_ST_DW.obj_e.UARTHandle,
      &uartReadData, dataBytesToRead, &sentLength);
  } else {
    getReadErrorStatus(STM32F415_master_ST_DW.obj_e.UARTHandle);
    sentLength = 0U;
  }

  /* Outputs for Enabled SubSystem: '<Root>/Enabled Subsystem2' incorporates:
   *  EnablePort: '<S6>/Enable'
   */
  /* RelationalOperator: '<S3>/Compare' incorporates:
   *  Constant: '<S22>/Constant'
   *  Constant: '<S3>/Constant'
   *  MATLABSystem: '<Root>/AT Receiver'
   *  MATLABSystem: '<S6>/MATLAB System'
   *  RelationalOperator: '<S22>/Compare'
   * */
  if (sentLength > STM32F415_master_ST_P.Constant_Value) {
    if (!STM32F415_master_ST_DW.EnabledSubsystem2_MODE) {
      /* InitializeConditions for MATLABSystem: '<S6>/MATLAB System' */
      for (i = 0; i < 50; i++) {
        STM32F415_master_ST_DW.obj_m.buffer[i] = 0U;
      }

      STM32F415_master_ST_DW.obj_m.pointer = 1U;

      /* End of InitializeConditions for MATLABSystem: '<S6>/MATLAB System' */
      STM32F415_master_ST_DW.EnabledSubsystem2_MODE = true;
    }

    /* MATLABSystem: '<S6>/MATLAB System' */
    for (i = 0; i < 50; i++) {
      STM32F415_master_ST_B.b_varargout_1_b[i] =
        STM32F415_master_ST_DW.obj_m.zeroBuffer[i];
    }

    b_varargout_2 = 0U;

    /*  Changed to uint16 to avoid overflow */
    /*  Store the incoming symbol in the buffer */
    if (STM32F415_master_ST_DW.obj_m.pointer <= 50) {
      STM32F415_master_ST_DW.obj_m.buffer[STM32F415_master_ST_DW.obj_m.pointer -
        1] = uartReadData;
      STM32F415_master_ST_DW.obj_m.pointer++;
    } else {
      /*  Reset the system if buffer overflows */
      for (i = 0; i < 50; i++) {
        STM32F415_master_ST_DW.obj_m.buffer[i] = 0U;
      }

      STM32F415_master_ST_DW.obj_m.pointer = 1U;
    }

    /*  Check if the incoming symbol is the end symbol */
    if (uartReadData == 75) {
      /*  Set the output data to the content of the buffer up to the current pointer */
      i = (int32_T)(STM32F415_master_ST_DW.obj_m.pointer - /*MW:OvSatOk*/ 1U);
      if (STM32F415_master_ST_DW.obj_m.pointer - 1U >
          STM32F415_master_ST_DW.obj_m.pointer) {
        i = 0;
      }

      b_varargout_2 = (uint16_T)i;

      /*  Set the output data length */
      /*  Reset the system */
      for (i = 0; i < 50; i++) {
        STM32F415_master_ST_B.b_varargout_1_b[i] =
          STM32F415_master_ST_DW.obj_m.buffer[i];
        STM32F415_master_ST_DW.obj_m.buffer[i] = 0U;
      }

      STM32F415_master_ST_DW.obj_m.pointer = 1U;
    }

    /* Outputs for Enabled SubSystem: '<S6>/Enabled Subsystem' incorporates:
     *  EnablePort: '<S23>/Enable'
     */
    if (b_varargout_2 > STM32F415_master_ST_P.Constant_Value_f) {
      /* MATLABSystem: '<S23>/UART//USART Write' incorporates:
       *  MATLABSystem: '<S23>/AT response encoder'
       * */
      /*  Check if the input is of type uint16 */
      /*  Extract lower 8 bits (least significant byte) */
      /*  255 is 0xFF in hexadecimal */
      /*  Extract upper 8 bits (most significant byte) */
      /*  Shift right by 8 bits and mask with 0xFF */
      /*  Convert to uint8 */
      /*  Create a vector of two uint8 elements */
      dataInLen = 55;
      if (b_varargout_2 + 5U < 55U) {
        dataInLen = (int32_T)(b_varargout_2 + 5U);
      }

      STM32F415_master_ST_B.uartWriteData_c[0] = 206U;
      STM32F415_master_ST_B.uartWriteData_c[1] = 206U;
      STM32F415_master_ST_B.uartWriteData_c[2] = 2U;
      STM32F415_master_ST_B.uartWriteData_c[3] = (uint8_T)b_varargout_2;
      STM32F415_master_ST_B.uartWriteData_c[4] = 0U;
      for (i = 0; i < 50; i++) {
        STM32F415_master_ST_B.uartWriteData_c[i + 5] =
          STM32F415_master_ST_B.b_varargout_1_b[i];
      }

      MW_UART_TransmitUsingInterrupt(STM32F415_master_ST_DW.obj_ep.UARTHandle,
        &STM32F415_master_ST_B.uartWriteData_c[0], (uint32_T)dataInLen, 0U,
        &sentLength);

      /* End of MATLABSystem: '<S23>/UART//USART Write' */
    }

    /* End of Outputs for SubSystem: '<S6>/Enabled Subsystem' */
  } else {
    STM32F415_master_ST_DW.EnabledSubsystem2_MODE = false;
  }

  /* End of RelationalOperator: '<S3>/Compare' */
  /* End of Outputs for SubSystem: '<Root>/Enabled Subsystem2' */
}

/* Model step function for TID4 */
void STM32F415_master_ST_step4(void)   /* Sample time: [0.01s, 0.0s] */
{
  int32_T dataInLen;
  uint32_T counts;

  /* MATLABSystem: '<Root>/Timer' */
  counts = getTimerCounterValue(STM32F415_master_ST_DW.obj_d2.TimerHandle);

  /* Outputs for Enabled SubSystem: '<Root>/Enabled Subsystem1' incorporates:
   *  EnablePort: '<S5>/Enable'
   */
  if (counts > 0U) {
    /* MATLABSystem: '<S5>/UART//USART Write' incorporates:
     *  DataStoreRead: '<S5>/Data Store Read'
     *  DataStoreRead: '<S5>/Data Store Read1'
     */
    dataInLen = 300;
    if (STM32F415_master_ST_SharedDSM.sbusLengrh < 300U) {
      dataInLen = STM32F415_master_ST_SharedDSM.sbusLengrh;
    }

    memcpy(&STM32F415_master_ST_B.uartWriteData_k[0],
           &STM32F415_master_ST_SharedDSM.sbusSignal[0], 300U * sizeof(uint8_T));
    MW_UART_TransmitUsingInterrupt(STM32F415_master_ST_DW.obj_ps.UARTHandle,
      &STM32F415_master_ST_B.uartWriteData_k[0], (uint32_T)dataInLen, 0U,
      &counts);

    /* End of MATLABSystem: '<S5>/UART//USART Write' */
  }

  /* End of MATLABSystem: '<Root>/Timer' */
  /* End of Outputs for SubSystem: '<Root>/Enabled Subsystem1' */
}

/* Model initialize function */
void STM32F415_master_ST_initialize(void)
{
  {
    int32_T i;

    /* Start for DataStoreMemory: '<Root>/Data Store Memory' */
    for (i = 0; i < 300; i++) {
      STM32F415_master_ST_SharedDSM.sbusSignal[i] =
        STM32F415_master_ST_P.DataStoreMemory_InitialValue;
    }

    /* End of Start for DataStoreMemory: '<Root>/Data Store Memory' */

    /* Start for DataStoreMemory: '<Root>/Data Store Memory1' */
    STM32F415_master_ST_SharedDSM.sbusLengrh =
      STM32F415_master_ST_P.DataStoreMemory1_InitialValue;

    /* SystemInitialize for Enabled SubSystem: '<Root>/Enabled Subsystem2' */
    /* SystemInitialize for Enabled SubSystem: '<S6>/Enabled Subsystem' */
    /* Start for MATLABSystem: '<S23>/UART//USART Write' */
    /*  Constructor */
    /*  Support name-value pair arguments when constructing object */
    /*         %% Common functions */
    STM32F415_master_ST_DW.obj_ep.isInitialized = 0;
    STM32F415_master_ST_DW.obj_ep.matlabCodegenIsDeleted = false;
    STM32F415_SystemCore_setup_poof(&STM32F415_master_ST_DW.obj_ep);

    /* End of SystemInitialize for SubSystem: '<S6>/Enabled Subsystem' */

    /* Start for MATLABSystem: '<S6>/MATLAB System' */
    /*  Constructor */
    /*  Support name-value pair arguments when constructing object */
    STM32F415_master_ST_DW.obj_m.isInitialized = 1;

    /*  Return false if input size cannot change */
    /*  between calls to the System object */
    /*         %% Common functions */
    for (i = 0; i < 50; i++) {
      STM32F415_master_ST_DW.obj_m.zeroBuffer[i] = 0U;

      /* InitializeConditions for MATLABSystem: '<S6>/MATLAB System' */
      STM32F415_master_ST_DW.obj_m.buffer[i] = 0U;
    }

    /* InitializeConditions for MATLABSystem: '<S6>/MATLAB System' */
    STM32F415_master_ST_DW.obj_m.pointer = 1U;

    /* End of SystemInitialize for SubSystem: '<Root>/Enabled Subsystem2' */

    /* SystemInitialize for Enabled SubSystem: '<Root>/Enabled Subsystem' */
    /* SystemInitialize for Enabled SubSystem: '<S8>/Subsystem' */
    /* Start for MATLABSystem: '<S13>/UART//USART Write' */
    STM32F415_master_ST_DW.obj_pi.isInitialized = 0;
    STM32F415_master_ST_DW.obj_pi.matlabCodegenIsDeleted = false;
    STM32F415_ma_SystemCore_setup_p(&STM32F415_master_ST_DW.obj_pi);

    /* End of SystemInitialize for SubSystem: '<S8>/Subsystem' */

    /* SystemInitialize for Enabled SubSystem: '<S9>/Subsystem' */
    /* Start for MATLABSystem: '<S16>/UART//USART Write' */
    STM32F415_master_ST_DW.obj_nc.isInitialized = 0;
    STM32F415_master_ST_DW.obj_nc.matlabCodegenIsDeleted = false;
    STM32F415_m_SystemCore_setup_po(&STM32F415_master_ST_DW.obj_nc);

    /* End of SystemInitialize for SubSystem: '<S9>/Subsystem' */

    /* Start for MATLABSystem: '<S4>/MATLAB System' */
    STM32F415_master_ST_DW.obj.startSymbol = 206U;

    /*  Constructor */
    /*  Support name-value pair arguments when constructing object */
    STM32F415_master_ST_DW.obj.isInitialized = 1;

    /*  Return false if input size cannot change */
    /*         %% Common functions */
    /*  Initialize the buffer */
    /*  Initialize / reset internal or discrete properties */
    /*  Reset system state */
    memset(&STM32F415_master_ST_DW.obj.zeroBuffer[0], 0, 300U * sizeof(uint8_T));

    /* InitializeConditions for MATLABSystem: '<S4>/MATLAB System' */
    memset(&STM32F415_master_ST_DW.obj.buffer[0], 0, 300U * sizeof(uint8_T));
    STM32F415_master_ST_DW.obj.pointer = 1U;
    STM32F415_master_ST_DW.obj.isDetecting = false;
    STM32F415_master_ST_DW.obj.preambleLength = 0U;

    /* End of SystemInitialize for SubSystem: '<Root>/Enabled Subsystem' */

    /* SystemInitialize for Enabled SubSystem: '<Root>/Mav Deserializer' */
    /* SystemInitialize for Enabled SubSystem: '<S7>/Enabled Subsystem' */
    /* Start for MATLABSystem: '<S25>/UART//USART Write' */
    /*  Constructor */
    /*  Support name-value pair arguments when constructing object */
    /*         %% Common functions */
    STM32F415_master_ST_DW.obj_p.isInitialized = 0;
    STM32F415_master_ST_DW.obj_p.matlabCodegenIsDeleted = false;
    STM32F415_SystemCore_setup_poof(&STM32F415_master_ST_DW.obj_p);

    /* End of SystemInitialize for SubSystem: '<S7>/Enabled Subsystem' */

    /* Start for MATLABSystem: '<S7>/MATLAB System' */
    STM32F415_master_ST_DW.obj_g.startSymbol = 253U;
    STM32F415_master_ST_DW.obj_g.pointer = 1U;
    STM32F415_master_ST_DW.obj_g.isCapturing = false;
    STM32F415_master_ST_DW.obj_g.mavFrameLength = 0U;

    /*  Constructor */
    /*  Support name-value pair arguments when constructing object */
    STM32F415_master_ST_DW.obj_g.isInitialized = 1;

    /*  Return false if input size cannot change */
    /*         %% Common functions */
    memset(&STM32F415_master_ST_DW.obj_g.emptyBuffer[0], 0, 300U * sizeof
           (uint8_T));
    memset(&STM32F415_master_ST_DW.obj_g.buffer[0], 0, 300U * sizeof(uint8_T));

    /* End of SystemInitialize for SubSystem: '<Root>/Mav Deserializer' */

    /* SystemInitialize for Enabled SubSystem: '<Root>/Enabled Subsystem1' */
    /* Start for MATLABSystem: '<S5>/UART//USART Write' */
    STM32F415_master_ST_DW.obj_ps.isInitialized = 0;
    STM32F415_master_ST_DW.obj_ps.matlabCodegenIsDeleted = false;
    STM32F415__SystemCore_setup_poo(&STM32F415_master_ST_DW.obj_ps);

    /* End of SystemInitialize for SubSystem: '<Root>/Enabled Subsystem1' */

    /* Start for MATLABSystem: '<Root>/UART//USART Read6' */
    STM32F415_master_ST_DW.obj_d.isInitialized = 0;
    STM32F415_master_ST_DW.obj_d.matlabCodegenIsDeleted = false;
    STM32_SystemCore_setup_poofajod(&STM32F415_master_ST_DW.obj_d);

    /* Start for MATLABSystem: '<Root>/MAV Receiver' */
    STM32F415_master_ST_DW.obj_n.isInitialized = 0;
    STM32F415_master_ST_DW.obj_n.matlabCodegenIsDeleted = false;
    STM32F41_SystemCore_setup_poofa(&STM32F415_master_ST_DW.obj_n);

    /* Start for MATLABSystem: '<Root>/AT Receiver' */
    STM32F415_master_ST_DW.obj_e.isInitialized = 0;
    STM32F415_master_ST_DW.obj_e.matlabCodegenIsDeleted = false;
    STM32F415_mast_SystemCore_setup(&STM32F415_master_ST_DW.obj_e);

    /* Start for MATLABSystem: '<Root>/Timer' */
    STM32F415_master_ST_DW.obj_d2.isInitialized = 0;
    STM32F415_master_ST_DW.obj_d2.matlabCodegenIsDeleted = false;
    STM32F_SystemCore_setup_poofajo(&STM32F415_master_ST_DW.obj_d2);
  }
}

/* Model terminate function */
void STM32F415_master_ST_terminate(void)
{
  /* Terminate for MATLABSystem: '<Root>/UART//USART Read6' */
  if (!STM32F415_master_ST_DW.obj_d.matlabCodegenIsDeleted) {
    STM32F415_master_ST_DW.obj_d.matlabCodegenIsDeleted = true;
    if ((STM32F415_master_ST_DW.obj_d.isInitialized == 1) &&
        STM32F415_master_ST_DW.obj_d.isSetupComplete) {
      MW_UART_DeInit(STM32F415_master_ST_DW.obj_d.UARTHandle);
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/UART//USART Read6' */

  /* Terminate for Enabled SubSystem: '<Root>/Enabled Subsystem' */
  /* Terminate for Enabled SubSystem: '<S8>/Subsystem' */
  /* Terminate for MATLABSystem: '<S13>/UART//USART Write' */
  if (!STM32F415_master_ST_DW.obj_pi.matlabCodegenIsDeleted) {
    STM32F415_master_ST_DW.obj_pi.matlabCodegenIsDeleted = true;
    if ((STM32F415_master_ST_DW.obj_pi.isInitialized == 1) &&
        STM32F415_master_ST_DW.obj_pi.isSetupComplete) {
      MW_UART_DeInit(STM32F415_master_ST_DW.obj_pi.UARTHandle);
    }
  }

  /* End of Terminate for MATLABSystem: '<S13>/UART//USART Write' */
  /* End of Terminate for SubSystem: '<S8>/Subsystem' */

  /* Terminate for Enabled SubSystem: '<S9>/Subsystem' */
  /* Terminate for MATLABSystem: '<S16>/UART//USART Write' */
  if (!STM32F415_master_ST_DW.obj_nc.matlabCodegenIsDeleted) {
    STM32F415_master_ST_DW.obj_nc.matlabCodegenIsDeleted = true;
    if ((STM32F415_master_ST_DW.obj_nc.isInitialized == 1) &&
        STM32F415_master_ST_DW.obj_nc.isSetupComplete) {
      MW_UART_DeInit(STM32F415_master_ST_DW.obj_nc.UARTHandle);
    }
  }

  /* End of Terminate for MATLABSystem: '<S16>/UART//USART Write' */
  /* End of Terminate for SubSystem: '<S9>/Subsystem' */
  /* End of Terminate for SubSystem: '<Root>/Enabled Subsystem' */

  /* Terminate for MATLABSystem: '<Root>/MAV Receiver' */
  if (!STM32F415_master_ST_DW.obj_n.matlabCodegenIsDeleted) {
    STM32F415_master_ST_DW.obj_n.matlabCodegenIsDeleted = true;
    if ((STM32F415_master_ST_DW.obj_n.isInitialized == 1) &&
        STM32F415_master_ST_DW.obj_n.isSetupComplete) {
      MW_UART_DeInit(STM32F415_master_ST_DW.obj_n.UARTHandle);
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/MAV Receiver' */

  /* Terminate for Enabled SubSystem: '<Root>/Mav Deserializer' */
  /* Terminate for Enabled SubSystem: '<S7>/Enabled Subsystem' */
  /* Terminate for MATLABSystem: '<S25>/UART//USART Write' */
  if (!STM32F415_master_ST_DW.obj_p.matlabCodegenIsDeleted) {
    STM32F415_master_ST_DW.obj_p.matlabCodegenIsDeleted = true;
    if ((STM32F415_master_ST_DW.obj_p.isInitialized == 1) &&
        STM32F415_master_ST_DW.obj_p.isSetupComplete) {
      MW_UART_DeInit(STM32F415_master_ST_DW.obj_p.UARTHandle);
    }
  }

  /* End of Terminate for MATLABSystem: '<S25>/UART//USART Write' */
  /* End of Terminate for SubSystem: '<S7>/Enabled Subsystem' */
  /* End of Terminate for SubSystem: '<Root>/Mav Deserializer' */

  /* Terminate for MATLABSystem: '<Root>/AT Receiver' */
  if (!STM32F415_master_ST_DW.obj_e.matlabCodegenIsDeleted) {
    STM32F415_master_ST_DW.obj_e.matlabCodegenIsDeleted = true;
    if ((STM32F415_master_ST_DW.obj_e.isInitialized == 1) &&
        STM32F415_master_ST_DW.obj_e.isSetupComplete) {
      MW_UART_DeInit(STM32F415_master_ST_DW.obj_e.UARTHandle);
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/AT Receiver' */

  /* Terminate for Enabled SubSystem: '<Root>/Enabled Subsystem2' */
  /* Terminate for Enabled SubSystem: '<S6>/Enabled Subsystem' */
  /* Terminate for MATLABSystem: '<S23>/UART//USART Write' */
  if (!STM32F415_master_ST_DW.obj_ep.matlabCodegenIsDeleted) {
    STM32F415_master_ST_DW.obj_ep.matlabCodegenIsDeleted = true;
    if ((STM32F415_master_ST_DW.obj_ep.isInitialized == 1) &&
        STM32F415_master_ST_DW.obj_ep.isSetupComplete) {
      MW_UART_DeInit(STM32F415_master_ST_DW.obj_ep.UARTHandle);
    }
  }

  /* End of Terminate for MATLABSystem: '<S23>/UART//USART Write' */
  /* End of Terminate for SubSystem: '<S6>/Enabled Subsystem' */
  /* End of Terminate for SubSystem: '<Root>/Enabled Subsystem2' */

  /* Terminate for MATLABSystem: '<Root>/Timer' */
  if (!STM32F415_master_ST_DW.obj_d2.matlabCodegenIsDeleted) {
    STM32F415_master_ST_DW.obj_d2.matlabCodegenIsDeleted = true;
    if ((STM32F415_master_ST_DW.obj_d2.isInitialized == 1) &&
        STM32F415_master_ST_DW.obj_d2.isSetupComplete) {
      disableCounter(STM32F415_master_ST_DW.obj_d2.TimerHandle);
      disableTimerInterrupts(STM32F415_master_ST_DW.obj_d2.TimerHandle, 0);
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/Timer' */

  /* Terminate for Enabled SubSystem: '<Root>/Enabled Subsystem1' */
  /* Terminate for MATLABSystem: '<S5>/UART//USART Write' */
  if (!STM32F415_master_ST_DW.obj_ps.matlabCodegenIsDeleted) {
    STM32F415_master_ST_DW.obj_ps.matlabCodegenIsDeleted = true;
    if ((STM32F415_master_ST_DW.obj_ps.isInitialized == 1) &&
        STM32F415_master_ST_DW.obj_ps.isSetupComplete) {
      MW_UART_DeInit(STM32F415_master_ST_DW.obj_ps.UARTHandle);
    }
  }

  /* End of Terminate for MATLABSystem: '<S5>/UART//USART Write' */
  /* End of Terminate for SubSystem: '<Root>/Enabled Subsystem1' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
