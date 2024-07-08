/*
 * File: STM32F415_master_ST.h
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

#ifndef RTW_HEADER_STM32F415_master_ST_h_
#define RTW_HEADER_STM32F415_master_ST_h_
#ifndef STM32F415_master_ST_COMMON_INCLUDES_
#define STM32F415_master_ST_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "stm_uart.h"
#endif                                /* STM32F415_master_ST_COMMON_INCLUDES_ */

#include "STM32F415_master_ST_types.h"
#include <stddef.h>
#include "MW_target_hardware_resources.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

#ifndef rtmStepTask
#define rtmStepTask(rtm, idx)          ((rtm)->Timing.TaskCounters.TID[(idx)] == 0)
#endif

#ifndef rtmTaskCounter
#define rtmTaskCounter(rtm, idx)       ((rtm)->Timing.TaskCounters.TID[(idx)])
#endif

/* Block signals (default storage) */
typedef struct {
  uint8_T uartWriteData[305];
  uint8_T b_varargout_1[300];
  uint8_T uartWriteData_m[300];
  uint8_T b_varargout_1_c[300];
  uint8_T uartWriteData_k[300];
  uint8_T uartWriteData_c[55];
  uint8_T b_varargout_1_b[50];
  boolean_T Compare;                   /* '<S24>/Compare' */
} B_STM32F415_master_ST_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  PreambleDetectorST_STM32F415__T obj; /* '<S4>/MATLAB System' */
  MavlinkDeserializerST_STM32F4_T obj_g;/* '<S7>/MATLAB System' */
  stm32cube_blocks_UARTRead_S_p_T obj_n;/* '<Root>/MAV Receiver' */
  stm32cube_blocks_UARTRead_STM_T obj_d;/* '<Root>/UART//USART Read6' */
  stm32cube_blocks_UARTRead_STM_T obj_e;/* '<Root>/AT Receiver' */
  stm32cube_blocks_UARTWrite_ST_T obj_p;/* '<S25>/UART//USART Write' */
  stm32cube_blocks_UARTWrite_ST_T obj_ep;/* '<S23>/UART//USART Write' */
  stm32cube_blocks_UARTWrite_ST_T obj_ps;/* '<S5>/UART//USART Write' */
  stm32cube_blocks_UARTWrite_ST_T obj_nc;/* '<S16>/UART//USART Write' */
  stm32cube_blocks_UARTWrite_ST_T obj_pi;/* '<S13>/UART//USART Write' */
  ATResponseDeserializerST_STM3_T obj_m;/* '<S6>/MATLAB System' */
  stm32cube_blocks_TimerBlock_S_T obj_d2;/* '<Root>/Timer' */
  boolean_T EnabledSubsystem2_MODE;    /* '<Root>/Enabled Subsystem2' */
} DW_STM32F415_master_ST_T;

/* data stores shared across model instances, for system '<Root>' */
typedef struct {
  uint16_T sbusLengrh;                 /* '<Root>/Data Store Memory1' */
  uint8_T sbusSignal[300];             /* '<Root>/Data Store Memory' */
} SharedDSM_STM32F415_master_ST_T;

/* Parameters (default storage) */
struct P_STM32F415_master_ST_T_ {
  uint8_T CompareToConstant_const;    /* Mask Parameter: CompareToConstant_const
                                       * Referenced by: '<S11>/Constant'
                                       */
  uint8_T CompareToConstant_const_m;/* Mask Parameter: CompareToConstant_const_m
                                     * Referenced by: '<S14>/Constant'
                                     */
  uint8_T CompareToConstant_const_e;/* Mask Parameter: CompareToConstant_const_e
                                     * Referenced by: '<S17>/Constant'
                                     */
  uint32_T Constant_Value;             /* Computed Parameter: Constant_Value
                                        * Referenced by: '<S3>/Constant'
                                        */
  uint32_T Constant_Value_o;           /* Computed Parameter: Constant_Value_o
                                        * Referenced by: '<S1>/Constant'
                                        */
  uint32_T Constant_Value_d;           /* Computed Parameter: Constant_Value_d
                                        * Referenced by: '<S2>/Constant'
                                        */
  uint16_T Constant_Value_b;           /* Computed Parameter: Constant_Value_b
                                        * Referenced by: '<S12>/Constant'
                                        */
  uint16_T Constant_Value_c;           /* Computed Parameter: Constant_Value_c
                                        * Referenced by: '<S15>/Constant'
                                        */
  uint16_T Constant_Value_a;           /* Computed Parameter: Constant_Value_a
                                        * Referenced by: '<S18>/Constant'
                                        */
  uint16_T Constant_Value_f;           /* Computed Parameter: Constant_Value_f
                                        * Referenced by: '<S22>/Constant'
                                        */
  uint16_T Constant_Value_f4;          /* Computed Parameter: Constant_Value_f4
                                        * Referenced by: '<S24>/Constant'
                                        */
  uint16_T DataStoreMemory1_InitialValue;
                            /* Computed Parameter: DataStoreMemory1_InitialValue
                             * Referenced by: '<Root>/Data Store Memory1'
                             */
  uint8_T DataStoreMemory_InitialValue;
                             /* Computed Parameter: DataStoreMemory_InitialValue
                              * Referenced by: '<Root>/Data Store Memory'
                              */
};

/* Real-time Model Data Structure */
struct tag_RTM_STM32F415_master_ST_T {
  const char_T * volatile errorStatus;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    struct {
      uint8_T TID[5];
    } TaskCounters;
  } Timing;
};

/* Block parameters (default storage) */
extern P_STM32F415_master_ST_T STM32F415_master_ST_P;

/* Block signals (default storage) */
extern B_STM32F415_master_ST_T STM32F415_master_ST_B;

/* Block states (default storage) */
extern DW_STM32F415_master_ST_T STM32F415_master_ST_DW;

/* data stores shared across model instances */
extern SharedDSM_STM32F415_master_ST_T STM32F415_master_ST_SharedDSM;/* '<Root>/Data Store Memory1' */

/* External function called from main */
extern void STM32F415_master_ST_SetEventsForThisBaseStep(boolean_T *eventFlags);

/* Model entry point functions */
extern void STM32F415_master_ST_initialize(void);
extern void STM32F415_master_ST_step0(void);
extern void STM32F415_master_ST_step1(void);
extern void STM32F415_master_ST_step2(void);
extern void STM32F415_master_ST_step3(void);
extern void STM32F415_master_ST_step4(void);
extern void STM32F415_master_ST_terminate(void);

/* Real-time Model object */
extern RT_MODEL_STM32F415_master_ST_T *const STM32F415_master_ST_M;
extern volatile boolean_T stopRequested;
extern volatile boolean_T runModel;

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'STM32F415_master_ST'
 * '<S1>'   : 'STM32F415_master_ST/Compare To Zero'
 * '<S2>'   : 'STM32F415_master_ST/Compare To Zero1'
 * '<S3>'   : 'STM32F415_master_ST/Compare To Zero2'
 * '<S4>'   : 'STM32F415_master_ST/Enabled Subsystem'
 * '<S5>'   : 'STM32F415_master_ST/Enabled Subsystem1'
 * '<S6>'   : 'STM32F415_master_ST/Enabled Subsystem2'
 * '<S7>'   : 'STM32F415_master_ST/Mav Deserializer'
 * '<S8>'   : 'STM32F415_master_ST/Enabled Subsystem/PortID 1 UART4'
 * '<S9>'   : 'STM32F415_master_ST/Enabled Subsystem/PortID 2 UART2 '
 * '<S10>'  : 'STM32F415_master_ST/Enabled Subsystem/PortID3 UART5'
 * '<S11>'  : 'STM32F415_master_ST/Enabled Subsystem/PortID 1 UART4/Compare To Constant'
 * '<S12>'  : 'STM32F415_master_ST/Enabled Subsystem/PortID 1 UART4/Compare To Zero'
 * '<S13>'  : 'STM32F415_master_ST/Enabled Subsystem/PortID 1 UART4/Subsystem'
 * '<S14>'  : 'STM32F415_master_ST/Enabled Subsystem/PortID 2 UART2 /Compare To Constant'
 * '<S15>'  : 'STM32F415_master_ST/Enabled Subsystem/PortID 2 UART2 /Compare To Zero'
 * '<S16>'  : 'STM32F415_master_ST/Enabled Subsystem/PortID 2 UART2 /Subsystem'
 * '<S17>'  : 'STM32F415_master_ST/Enabled Subsystem/PortID3 UART5/Compare To Constant'
 * '<S18>'  : 'STM32F415_master_ST/Enabled Subsystem/PortID3 UART5/Compare To Zero'
 * '<S19>'  : 'STM32F415_master_ST/Enabled Subsystem/PortID3 UART5/Subsystem'
 * '<S20>'  : 'STM32F415_master_ST/Enabled Subsystem/PortID3 UART5/Subsystem/MATLAB Function'
 * '<S21>'  : 'STM32F415_master_ST/Enabled Subsystem/PortID3 UART5/Subsystem/Subsystem'
 * '<S22>'  : 'STM32F415_master_ST/Enabled Subsystem2/Compare To Zero'
 * '<S23>'  : 'STM32F415_master_ST/Enabled Subsystem2/Enabled Subsystem'
 * '<S24>'  : 'STM32F415_master_ST/Mav Deserializer/Compare To Zero'
 * '<S25>'  : 'STM32F415_master_ST/Mav Deserializer/Enabled Subsystem'
 */
#endif                                 /* RTW_HEADER_STM32F415_master_ST_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
