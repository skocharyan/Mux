
/*
 * Include Files
 *
 */
#if defined(MATLAB_MEX_FILE)
#include "tmwtypes.h"
#include "simstruc_types.h"
#else
#define SIMPLIFIED_RTWTYPES_COMPATIBILITY
#include "rtwtypes.h"
#undef SIMPLIFIED_RTWTYPES_COMPATIBILITY
#endif



/* %%%-SFUNWIZ_wrapper_includes_Changes_BEGIN --- EDIT HERE TO _END */
#include <math.h>
#include <stdint.h>  // For standard integer types like uint32_t
#include <stdbool.h> // For boolean types (if available)
/* extern double func(double a); */
// Base address for IWDG
#define IWDG_BASE        0x40003000UL
// Offsets for IWDG registers
#define IWDG_KR_OFFSET   0x00UL
// Define pointer to the IWDG Key Register
#define IWDG_KR    (*(volatile uint32_t *)(IWDG_BASE + IWDG_KR_OFFSET))
// Key value for reloading the IWDG
#define IWDG_KEY_RELOAD  0xAAAA
/* %%%-SFUNWIZ_wrapper_includes_Changes_END --- EDIT HERE TO _BEGIN */
#define u_width 1

/*
 * Create external references here.  
 *
 */
/* %%%-SFUNWIZ_wrapper_externs_Changes_BEGIN --- EDIT HERE TO _END */
/* extern double func(double a); */
/* %%%-SFUNWIZ_wrapper_externs_Changes_END --- EDIT HERE TO _BEGIN */

/*
 * Output function
 *
 */
void resetState_Outputs_wrapper(const boolean_T *status)
{
/* %%%-SFUNWIZ_wrapper_Outputs_Changes_BEGIN --- EDIT HERE TO _END */
if (*status) {
        IWDG_KR = IWDG_KEY_RELOAD;
    }
/* %%%-SFUNWIZ_wrapper_Outputs_Changes_END --- EDIT HERE TO _BEGIN */
}


