/*
 * File: STM32F415_master_ST_private.h
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

#ifndef RTW_HEADER_STM32F415_master_ST_private_h_
#define RTW_HEADER_STM32F415_master_ST_private_h_
#include "rtwtypes.h"
#include "STM32F415_master_ST_types.h"
#ifdef __cplusplus
#define SFB_EXTERN_C                   extern "C"
#else
#define SFB_EXTERN_C                   extern
#endif

SFB_EXTERN_C void resetState_Start_wrapper(void);
SFB_EXTERN_C void resetState_Outputs_wrapper(const boolean_T *status);
SFB_EXTERN_C void resetState_Terminate_wrapper(void);

#undef SFB_EXTERN_C
#endif                           /* RTW_HEADER_STM32F415_master_ST_private_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
