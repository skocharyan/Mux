/*
 * File: STM32F415_master_ST_types.h
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

#ifndef RTW_HEADER_STM32F415_master_ST_types_h_
#define RTW_HEADER_STM32F415_master_ST_types_h_
#include "rtwtypes.h"
#include "stm_timer_ll.h"
#ifndef struct_tag_BEsSHOG2YhsXR3k9tZsFj
#define struct_tag_BEsSHOG2YhsXR3k9tZsFj

struct tag_BEsSHOG2YhsXR3k9tZsFj
{
  int32_T isInitialized;
  uint8_T startSymbol;
  uint16_T pointer;
  boolean_T isDetecting;
  uint8_T buffer[300];
  uint16_T preambleLength;
  uint8_T zeroBuffer[300];
};

#endif                                 /* struct_tag_BEsSHOG2YhsXR3k9tZsFj */

#ifndef typedef_PreambleDetectorST_STM32F415__T
#define typedef_PreambleDetectorST_STM32F415__T

typedef struct tag_BEsSHOG2YhsXR3k9tZsFj PreambleDetectorST_STM32F415__T;

#endif                             /* typedef_PreambleDetectorST_STM32F415__T */

#ifndef struct_tag_ZIM0DhLhk1U6kjGFviPZpB
#define struct_tag_ZIM0DhLhk1U6kjGFviPZpB

struct tag_ZIM0DhLhk1U6kjGFviPZpB
{
  int32_T isInitialized;
};

#endif                                 /* struct_tag_ZIM0DhLhk1U6kjGFviPZpB */

#ifndef typedef_DataEncoder_STM32F415_master__T
#define typedef_DataEncoder_STM32F415_master__T

typedef struct tag_ZIM0DhLhk1U6kjGFviPZpB DataEncoder_STM32F415_master__T;

#endif                             /* typedef_DataEncoder_STM32F415_master__T */

#ifndef struct_tag_m3PhuB4ljo8ECcIQ43OpnG
#define struct_tag_m3PhuB4ljo8ECcIQ43OpnG

struct tag_m3PhuB4ljo8ECcIQ43OpnG
{
  int32_T isInitialized;
  uint8_T pointer;
  uint8_T buffer[50];
  uint8_T zeroBuffer[50];
};

#endif                                 /* struct_tag_m3PhuB4ljo8ECcIQ43OpnG */

#ifndef typedef_ATResponseDeserializerST_STM3_T
#define typedef_ATResponseDeserializerST_STM3_T

typedef struct tag_m3PhuB4ljo8ECcIQ43OpnG ATResponseDeserializerST_STM3_T;

#endif                             /* typedef_ATResponseDeserializerST_STM3_T */

#ifndef struct_tag_dObVt1Fs7IqXDSeJNuUCpG
#define struct_tag_dObVt1Fs7IqXDSeJNuUCpG

struct tag_dObVt1Fs7IqXDSeJNuUCpG
{
  int32_T isInitialized;
  uint8_T startSymbol;
  uint16_T pointer;
  boolean_T isCapturing;
  uint8_T buffer[300];
  uint16_T mavFrameLength;
  uint8_T emptyBuffer[300];
};

#endif                                 /* struct_tag_dObVt1Fs7IqXDSeJNuUCpG */

#ifndef typedef_MavlinkDeserializerST_STM32F4_T
#define typedef_MavlinkDeserializerST_STM32F4_T

typedef struct tag_dObVt1Fs7IqXDSeJNuUCpG MavlinkDeserializerST_STM32F4_T;

#endif                             /* typedef_MavlinkDeserializerST_STM32F4_T */

/* Custom Type definition for MATLABSystem: '<Root>/Timer' */
#include "stm_timer_ll.h"
#include "stm_timer_ll.h"
#ifndef struct_tag_lVYsrGoTQYYB21wZ5vAzOC
#define struct_tag_lVYsrGoTQYYB21wZ5vAzOC

struct tag_lVYsrGoTQYYB21wZ5vAzOC
{
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  boolean_T isSetupComplete;
  TIM_Type_T* TimerHandle;
};

#endif                                 /* struct_tag_lVYsrGoTQYYB21wZ5vAzOC */

#ifndef typedef_stm32cube_blocks_TimerBlock_S_T
#define typedef_stm32cube_blocks_TimerBlock_S_T

typedef struct tag_lVYsrGoTQYYB21wZ5vAzOC stm32cube_blocks_TimerBlock_S_T;

#endif                             /* typedef_stm32cube_blocks_TimerBlock_S_T */

#ifndef struct_tag_KT387TO2So4uk2kI2Lbb3C
#define struct_tag_KT387TO2So4uk2kI2Lbb3C

struct tag_KT387TO2So4uk2kI2Lbb3C
{
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  boolean_T isSetupComplete;
  UART_Type_T* UARTHandle;
  uint8_T UARTInternalBuffer[128];
};

#endif                                 /* struct_tag_KT387TO2So4uk2kI2Lbb3C */

#ifndef typedef_stm32cube_blocks_UARTRead_STM_T
#define typedef_stm32cube_blocks_UARTRead_STM_T

typedef struct tag_KT387TO2So4uk2kI2Lbb3C stm32cube_blocks_UARTRead_STM_T;

#endif                             /* typedef_stm32cube_blocks_UARTRead_STM_T */

#ifndef struct_tag_K5QCAuLh2FF8FsZmLWzJxB
#define struct_tag_K5QCAuLh2FF8FsZmLWzJxB

struct tag_K5QCAuLh2FF8FsZmLWzJxB
{
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  boolean_T isSetupComplete;
  UART_Type_T* UARTHandle;
  uint8_T UARTInternalBuffer[128];
};

#endif                                 /* struct_tag_K5QCAuLh2FF8FsZmLWzJxB */

#ifndef typedef_stm32cube_blocks_UARTWrite_ST_T
#define typedef_stm32cube_blocks_UARTWrite_ST_T

typedef struct tag_K5QCAuLh2FF8FsZmLWzJxB stm32cube_blocks_UARTWrite_ST_T;

#endif                             /* typedef_stm32cube_blocks_UARTWrite_ST_T */

#ifndef struct_tag_EV80wBzLT2XwMbP6cWDInB
#define struct_tag_EV80wBzLT2XwMbP6cWDInB

struct tag_EV80wBzLT2XwMbP6cWDInB
{
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  boolean_T isSetupComplete;
  UART_Type_T* UARTHandle;
  uint8_T UARTInternalBuffer[304];
};

#endif                                 /* struct_tag_EV80wBzLT2XwMbP6cWDInB */

#ifndef typedef_stm32cube_blocks_UARTRead_S_p_T
#define typedef_stm32cube_blocks_UARTRead_S_p_T

typedef struct tag_EV80wBzLT2XwMbP6cWDInB stm32cube_blocks_UARTRead_S_p_T;

#endif                             /* typedef_stm32cube_blocks_UARTRead_S_p_T */

/* Parameters (default storage) */
typedef struct P_STM32F415_master_ST_T_ P_STM32F415_master_ST_T;

/* Forward declaration for rtModel */
typedef struct tag_RTM_STM32F415_master_ST_T RT_MODEL_STM32F415_master_ST_T;

#endif                             /* RTW_HEADER_STM32F415_master_ST_types_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
