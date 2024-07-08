/* Copyright 2022 The MathWorks, Inc. */
#ifndef __STM_HRTIMER_LL_H__
#define __STM_HRTIMER_LL_H__
/******************************************************************************
* Includes
*******************************************************************************/
#include "rtwtypes.h"
#include "main.h"
/******************************************************************************
* Typedefs
*******************************************************************************/
typedef enum _TIMERx_Channel_Mode_T {
    CHANNEL_NOT_CONFIGURED  = 0x00,
    CHANNEL_NO_OUTPUT       = 0X01,
    TIMER_CH1               = 0x02,
    TIMER_CH2               = 0x03,
    TIMER_CH1CH2           = 0x04
} TIMERx_Channel_Mode_T;

typedef enum _HRTIMER_Timer_Index_T {
    TIMERA  = 0x00,
    TIMERB  = 0X01,
    TIMERC  = 0x02,
    TIMERD  = 0x03,
    TIMERE  = 0x04,
    TIMERF  = 0x05,
    MAINTIMER = 0x06
} HRTIMER_Timer_Index_T;

typedef struct _HRTIMER_Type_T {
    void *PeripheralPtr;
} HRTIMER_Type_T;

/******************************************************************************
* Static Inline functions
*******************************************************************************/
/* Get the TIMERA duty cycle value in counts */
__STATIC_INLINE uint32_T convertTimerADutyCyclePercentageToCounts(HRTIMER_Type_T * ptrHRTimer, float DutyCycle)
{
    if(DutyCycle < 0.0F)
    {
        DutyCycle = 0.0F;
    }
    else if (DutyCycle > 100.0F)
    {
        DutyCycle = 100.0F;
    }
    uint32_T PERRegisterValue = LL_HRTIM_TIM_GetPeriod(ptrHRTimer->PeripheralPtr,LL_HRTIM_TIMER_A);
    return (( PERRegisterValue * DutyCycle)/100.0F);
}

/* Get the TIMERB duty cycle value in counts */
__STATIC_INLINE uint32_T convertTimerBDutyCyclePercentageToCounts(HRTIMER_Type_T * ptrHRTimer, float DutyCycle)
{
    if(DutyCycle < 0.0F)
    {
        DutyCycle = 0.0F;
    }
    else if (DutyCycle > 100.0F)
    {
        DutyCycle = 100.0F;
    }
    uint32_T PERRegisterValue = LL_HRTIM_TIM_GetPeriod(ptrHRTimer->PeripheralPtr,LL_HRTIM_TIMER_B);
    return (( PERRegisterValue * DutyCycle)/100.0F);
}

/* Get the TIMERC duty cycle value in counts */
__STATIC_INLINE uint32_T convertTimerCDutyCyclePercentageToCounts(HRTIMER_Type_T * ptrHRTimer, float DutyCycle)
{
    if(DutyCycle < 0.0F)
    {
        DutyCycle = 0.0F;
    }
    else if (DutyCycle > 100.0F)
    {
        DutyCycle = 100.0F;
    }
    uint32_T PERRegisterValue = LL_HRTIM_TIM_GetPeriod(ptrHRTimer->PeripheralPtr,LL_HRTIM_TIMER_C);
    return (( PERRegisterValue * DutyCycle)/100.0F);
}

/* Get the TIMERD duty cycle value in counts */
__STATIC_INLINE uint32_T convertTimerDDutyCyclePercentageToCounts(HRTIMER_Type_T * ptrHRTimer, float DutyCycle)
{
    if(DutyCycle < 0.0F)
    {
        DutyCycle = 0.0F;
    }
    else if (DutyCycle > 100.0F)
    {
        DutyCycle = 100.0F;
    }
    uint32_T PERRegisterValue = LL_HRTIM_TIM_GetPeriod(ptrHRTimer->PeripheralPtr,LL_HRTIM_TIMER_D);
    return (( PERRegisterValue * DutyCycle)/100.0F);
}

/* Get the TIMERE duty cycle value in counts */
__STATIC_INLINE uint32_T convertTimerEDutyCyclePercentageToCounts(HRTIMER_Type_T * ptrHRTimer, float DutyCycle)
{
    if(DutyCycle < 0.0F)
    {
        DutyCycle = 0.0F;
    }
    else if (DutyCycle > 100.0F)
    {
        DutyCycle = 100.0F;
    }
    uint32_T PERRegisterValue = LL_HRTIM_TIM_GetPeriod(ptrHRTimer->PeripheralPtr,LL_HRTIM_TIMER_E);
    return (( PERRegisterValue * DutyCycle)/100.0F);
}

/* Get the TIMERF duty cycle value in counts */
#if defined(STM32G4) 
__STATIC_INLINE uint32_T convertTimerFDutyCyclePercentageToCounts(HRTIMER_Type_T * ptrHRTimer, float DutyCycle)
{
    if(DutyCycle < 0.0F)
    {
        DutyCycle = 0.0F;
    }
    else if (DutyCycle > 100.0F)
    {
        DutyCycle = 100.0F;
    }
    uint32_T PERRegisterValue = LL_HRTIM_TIM_GetPeriod(ptrHRTimer->PeripheralPtr,LL_HRTIM_TIMER_F);
    return (( PERRegisterValue * DutyCycle)/100.0F);
}
#endif

/* Get the MAIN TIMER duty cycle value in counts */
__STATIC_INLINE uint32_T convertMainTimerDutyCyclePercentageToCounts(HRTIMER_Type_T * ptrHRTimer, float DutyCycle)
{
    if(DutyCycle < 0.0F)
    {
        DutyCycle = 0.0F;
    }
    else if (DutyCycle > 100.0F)
    {
        DutyCycle = 100.0F;
    }
    uint32_T PERRegisterValue = LL_HRTIM_TIM_GetPeriod(ptrHRTimer->PeripheralPtr,LL_HRTIM_TIMER_MASTER);
    return (( PERRegisterValue * DutyCycle)/100.0F);
}

/*Enable the TIMERA counter if Enable Counter input is set */
__STATIC_INLINE void enableTimerACounterAccToInput(HRTIMER_Type_T * ptrHRTimer, boolean_T counterEnableInput)
{
    if(counterEnableInput == 1 && !(LL_HRTIM_TIM_IsCounterEnabled(ptrHRTimer->PeripheralPtr,LL_HRTIM_TIMER_A)))
    {
        LL_HRTIM_TIM_CounterEnable(ptrHRTimer->PeripheralPtr, LL_HRTIM_TIMER_A);
    }
    else if(counterEnableInput == 0 && LL_HRTIM_TIM_IsCounterEnabled(ptrHRTimer->PeripheralPtr,LL_HRTIM_TIMER_A))
    {
        LL_HRTIM_TIM_CounterDisable(ptrHRTimer->PeripheralPtr, LL_HRTIM_TIMER_A);
    }
}

/*Enable the TIMERB counter if Enable Counter input is set */
__STATIC_INLINE void enableTimerBCounterAccToInput(HRTIMER_Type_T * ptrHRTimer, boolean_T counterEnableInput)
{
    if(counterEnableInput == 1 && !(LL_HRTIM_TIM_IsCounterEnabled(ptrHRTimer->PeripheralPtr,LL_HRTIM_TIMER_B)))
    {
        LL_HRTIM_TIM_CounterEnable(ptrHRTimer->PeripheralPtr, LL_HRTIM_TIMER_B);
    }
    else if(counterEnableInput == 0 && LL_HRTIM_TIM_IsCounterEnabled(ptrHRTimer->PeripheralPtr,LL_HRTIM_TIMER_B))
    {
        LL_HRTIM_TIM_CounterDisable(ptrHRTimer->PeripheralPtr, LL_HRTIM_TIMER_B);
    }
}

/*Enable the TIMERC counter if Enable Counter input is set */
__STATIC_INLINE void enableTimerCCounterAccToInput(HRTIMER_Type_T * ptrHRTimer, boolean_T counterEnableInput)
{
    if(counterEnableInput == 1 && !(LL_HRTIM_TIM_IsCounterEnabled(ptrHRTimer->PeripheralPtr,LL_HRTIM_TIMER_C)))
    {
        LL_HRTIM_TIM_CounterEnable(ptrHRTimer->PeripheralPtr, LL_HRTIM_TIMER_C);
    }
    else if(counterEnableInput == 0 && LL_HRTIM_TIM_IsCounterEnabled(ptrHRTimer->PeripheralPtr,LL_HRTIM_TIMER_C))
    {
        LL_HRTIM_TIM_CounterDisable(ptrHRTimer->PeripheralPtr, LL_HRTIM_TIMER_C);
    }
}

/*Enable the TIMERD counter if Enable Counter input is set */
__STATIC_INLINE void enableTimerDCounterAccToInput(HRTIMER_Type_T * ptrHRTimer, boolean_T counterEnableInput)
{
    if(counterEnableInput == 1 && !(LL_HRTIM_TIM_IsCounterEnabled(ptrHRTimer->PeripheralPtr,LL_HRTIM_TIMER_D)))
    {
        LL_HRTIM_TIM_CounterEnable(ptrHRTimer->PeripheralPtr, LL_HRTIM_TIMER_D);
    }
    else if(counterEnableInput == 0 && LL_HRTIM_TIM_IsCounterEnabled(ptrHRTimer->PeripheralPtr,LL_HRTIM_TIMER_D))
    {
        LL_HRTIM_TIM_CounterDisable(ptrHRTimer->PeripheralPtr, LL_HRTIM_TIMER_D);
    }
}

/*Enable the TIMERE counter if Enable Counter input is set */
__STATIC_INLINE void enableTimerECounterAccToInput(HRTIMER_Type_T * ptrHRTimer, boolean_T counterEnableInput)
{
    if(counterEnableInput == 1 && !(LL_HRTIM_TIM_IsCounterEnabled(ptrHRTimer->PeripheralPtr,LL_HRTIM_TIMER_E)))
    {
        LL_HRTIM_TIM_CounterEnable(ptrHRTimer->PeripheralPtr, LL_HRTIM_TIMER_E);
    }
    else if(counterEnableInput == 0 && LL_HRTIM_TIM_IsCounterEnabled(ptrHRTimer->PeripheralPtr,LL_HRTIM_TIMER_E))
    {
        LL_HRTIM_TIM_CounterDisable(ptrHRTimer->PeripheralPtr, LL_HRTIM_TIMER_E);
    }
}

/*Enable the TIMERF counter if Enable Counter input is set */
#if defined(STM32G4) 
__STATIC_INLINE void enableTimerFCounterAccToInput(HRTIMER_Type_T * ptrHRTimer, boolean_T counterEnableInput)
{
    if(counterEnableInput == 1 && !(LL_HRTIM_TIM_IsCounterEnabled(ptrHRTimer->PeripheralPtr,LL_HRTIM_TIMER_F)))
    {
        LL_HRTIM_TIM_CounterEnable(ptrHRTimer->PeripheralPtr, LL_HRTIM_TIMER_F);
    }
    else if(counterEnableInput == 0 && LL_HRTIM_TIM_IsCounterEnabled(ptrHRTimer->PeripheralPtr,LL_HRTIM_TIMER_F))
    {
        LL_HRTIM_TIM_CounterDisable(ptrHRTimer->PeripheralPtr, LL_HRTIM_TIMER_F);
    }
}
#endif

/*Enable the MAINTIMER counter if Enable Counter input is set */
__STATIC_INLINE void enableMainTimerCounterAccToInput(HRTIMER_Type_T * ptrHRTimer, boolean_T counterEnableInput)
{
    if(counterEnableInput == 1 && !(LL_HRTIM_TIM_IsCounterEnabled(ptrHRTimer->PeripheralPtr,LL_HRTIM_TIMER_MASTER)))
    {
        LL_HRTIM_TIM_CounterEnable(ptrHRTimer->PeripheralPtr, LL_HRTIM_TIMER_MASTER);
    }
    else if(counterEnableInput == 0 && LL_HRTIM_TIM_IsCounterEnabled(ptrHRTimer->PeripheralPtr,LL_HRTIM_TIMER_MASTER))
    {
        LL_HRTIM_TIM_CounterDisable(ptrHRTimer->PeripheralPtr, LL_HRTIM_TIMER_MASTER);
    }
}

/*Set the TIMERA PER register if Enable Frequency Input is set */
__STATIC_INLINE void setTimerAFrequencyAccToInput(HRTIMER_Type_T * ptrHRTimer, uint32_T frequencyInput)
{
    if(LL_HRTIM_TIM_GetPeriod(ptrHRTimer->PeripheralPtr,LL_HRTIM_TIMER_A) != frequencyInput)
    {
        LL_HRTIM_TIM_SetPeriod(ptrHRTimer->PeripheralPtr, LL_HRTIM_TIMER_A, (uint32_T)frequencyInput);
    }
}

/*Set the TIMERB PER register if Enable Frequency Input is set */
__STATIC_INLINE void setTimerBFrequencyAccToInput(HRTIMER_Type_T * ptrHRTimer, uint32_T frequencyInput)
{
    if(LL_HRTIM_TIM_GetPeriod(ptrHRTimer->PeripheralPtr,LL_HRTIM_TIMER_B) != frequencyInput)
    {
        LL_HRTIM_TIM_SetPeriod(ptrHRTimer->PeripheralPtr, LL_HRTIM_TIMER_B, (uint32_T)frequencyInput);
    }
}

/*Set the TIMERC PER register if Enable Frequency Input is set */
__STATIC_INLINE void setTimerCFrequencyAccToInput(HRTIMER_Type_T * ptrHRTimer, uint32_T frequencyInput)
{
    if(LL_HRTIM_TIM_GetPeriod(ptrHRTimer->PeripheralPtr,LL_HRTIM_TIMER_C) != frequencyInput)
    {
        LL_HRTIM_TIM_SetPeriod(ptrHRTimer->PeripheralPtr, LL_HRTIM_TIMER_C, (uint32_T)frequencyInput);
    }
}

/*Set the TIMERD PER register if Enable Frequency Input is set */
__STATIC_INLINE void setTimerDFrequencyAccToInput(HRTIMER_Type_T * ptrHRTimer, uint32_T frequencyInput)
{
    if(LL_HRTIM_TIM_GetPeriod(ptrHRTimer->PeripheralPtr,LL_HRTIM_TIMER_D) != frequencyInput)
    {
        LL_HRTIM_TIM_SetPeriod(ptrHRTimer->PeripheralPtr, LL_HRTIM_TIMER_D, (uint32_T)frequencyInput);
    }
}

/*Set the TIMERE PER register if Enable Frequency Input is set */
__STATIC_INLINE void setTimerEFrequencyAccToInput(HRTIMER_Type_T * ptrHRTimer, uint32_T frequencyInput)
{
    if(LL_HRTIM_TIM_GetPeriod(ptrHRTimer->PeripheralPtr,LL_HRTIM_TIMER_E) != frequencyInput)
    {
        LL_HRTIM_TIM_SetPeriod(ptrHRTimer->PeripheralPtr, LL_HRTIM_TIMER_E, (uint32_T)frequencyInput);
    }
}

/*Set the TIMERF PER register if Enable Frequency Input is set */
#if defined(STM32G4)
__STATIC_INLINE void setTimerFFrequencyAccToInput(HRTIMER_Type_T * ptrHRTimer, uint32_T frequencyInput)
{
    if(LL_HRTIM_TIM_GetPeriod(ptrHRTimer->PeripheralPtr,LL_HRTIM_TIMER_F) != frequencyInput)
    {
        LL_HRTIM_TIM_SetPeriod(ptrHRTimer->PeripheralPtr, LL_HRTIM_TIMER_F, (uint32_T)frequencyInput);
    }
}
#endif
/*Set the MAIN TIMER PER register if Enable Frequency Input is set */
__STATIC_INLINE void setMainTimerFrequencyAccToInput(HRTIMER_Type_T * ptrHRTimer, uint32_T frequencyInput)
{
    if(LL_HRTIM_TIM_GetPeriod(ptrHRTimer->PeripheralPtr,LL_HRTIM_TIMER_MASTER) != frequencyInput)
    {
        LL_HRTIM_TIM_SetPeriod(ptrHRTimer->PeripheralPtr, LL_HRTIM_TIMER_MASTER, (uint32_T)frequencyInput);
    }
}

/*Disabled status of the TIMERA channelx */
__STATIC_INLINE uint32_T getTimerAOutputDisabledStatus(HRTIMER_Type_T * ptrHRTimer, boolean_T channelInput)
{   
    uint32_T OutputStatus = 0;

    if(0 == channelInput)
    {
       OutputStatus = LL_HRTIM_IsDisabledOutput(ptrHRTimer->PeripheralPtr, LL_HRTIM_OUTPUT_TA1);
    }
    else if(1 == channelInput)
    {
       OutputStatus = LL_HRTIM_IsDisabledOutput(ptrHRTimer->PeripheralPtr, LL_HRTIM_OUTPUT_TA2);
    }
    else
    {
       /* Do nothing */
    }
    return OutputStatus;
}

/*Disabled status of the TIMERB channelx */
__STATIC_INLINE uint32_T getTimerBOutputDisabledStatus(HRTIMER_Type_T * ptrHRTimer, boolean_T channelInput)
{   
    uint32_T OutputStatus = 0;

    if(0 == channelInput)
    {
       OutputStatus = LL_HRTIM_IsDisabledOutput(ptrHRTimer->PeripheralPtr, LL_HRTIM_OUTPUT_TB1);
    }
    else if(1 == channelInput)
    {
       OutputStatus = LL_HRTIM_IsDisabledOutput(ptrHRTimer->PeripheralPtr, LL_HRTIM_OUTPUT_TB2);
    }
    else
    {
       /* Do nothing */
    }
    return OutputStatus;
}

/*Disabled status of the TIMERC channelx */
__STATIC_INLINE uint32_T getTimerCOutputDisabledStatus(HRTIMER_Type_T * ptrHRTimer, boolean_T channelInput)
{
    uint32_T OutputStatus = 0;

    if(0 == channelInput)
    {
       OutputStatus = LL_HRTIM_IsDisabledOutput(ptrHRTimer->PeripheralPtr, LL_HRTIM_OUTPUT_TC1);
    }
    else if(1 == channelInput)
    {
       OutputStatus = LL_HRTIM_IsDisabledOutput(ptrHRTimer->PeripheralPtr, LL_HRTIM_OUTPUT_TC2);
    }
    else
    {
       /* Do nothing */
    }
    return OutputStatus;
}

/*Disabled status of the TIMERD channelx */
__STATIC_INLINE uint32_T getTimerDOutputDisabledStatus(HRTIMER_Type_T * ptrHRTimer, boolean_T channelInput)
{
    uint32_T OutputStatus = 0;

    if(0 == channelInput)
    {
       OutputStatus = LL_HRTIM_IsDisabledOutput(ptrHRTimer->PeripheralPtr, LL_HRTIM_OUTPUT_TD1);
    }
    else if(1 == channelInput)
    {
       OutputStatus = LL_HRTIM_IsDisabledOutput(ptrHRTimer->PeripheralPtr, LL_HRTIM_OUTPUT_TD2);
    }
    else
    {
       /* Do nothing */
    }
    return OutputStatus;
}

/*Disabled status of the TIMERE channelx */
__STATIC_INLINE uint32_T getTimerEOutputDisabledStatus(HRTIMER_Type_T * ptrHRTimer, boolean_T channelInput)
{
    uint32_T OutputStatus = 0;

    if(0 == channelInput)
    {
       OutputStatus = LL_HRTIM_IsDisabledOutput(ptrHRTimer->PeripheralPtr, LL_HRTIM_OUTPUT_TE1);
    }
    else if(1 == channelInput)
    {
       OutputStatus = LL_HRTIM_IsDisabledOutput(ptrHRTimer->PeripheralPtr, LL_HRTIM_OUTPUT_TE2);
    }
    else
    {
       /* Do nothing */
    }
    return OutputStatus;
}

/*Disabled status of the TIMERF channelx */
#if defined(STM32G4)
__STATIC_INLINE uint32_T getTimerFOutputDisabledStatus(HRTIMER_Type_T * ptrHRTimer, boolean_T channelInput)
{
    uint32_T OutputStatus = 0;

    if(0 == channelInput)
    {
       OutputStatus = LL_HRTIM_IsDisabledOutput(ptrHRTimer->PeripheralPtr, LL_HRTIM_OUTPUT_TF1);
    }
    else if(1 == channelInput)
    {
       OutputStatus = LL_HRTIM_IsDisabledOutput(ptrHRTimer->PeripheralPtr, LL_HRTIM_OUTPUT_TF2);
    }
    else
    {
       /* Do nothing */
    }
    return OutputStatus;
}
#endif
#if defined(STM32G4)
/*Enable DLL Calibration process of the HRTIMER */
__STATIC_INLINE void enableHRtimerDLLCalibration(HRTIMER_Type_T * ptrHRTimer, boolean_T calInput)
{
   if(calInput == 1)
   {
      LL_HRTIM_StartDLLCalibration(ptrHRTimer->PeripheralPtr);   
   }
}
#endif
/*Enable Timerx force update event generation if input is set x=A-F for G4XX, x=A-E for H7XX */
__STATIC_INLINE void setTimerxForcedUpdateEvent(HRTIMER_Type_T * ptrHRTimer, uint32_T TimerOffset, boolean_T updateInput)
{
    if(updateInput == 1)
    {
       LL_HRTIM_ForceUpdate(ptrHRTimer->PeripheralPtr,TimerOffset);
    }
}

/*Set the TIMERA UpdateEvent to Suspend/Resume */
__STATIC_INLINE void setTimerASuspendUpdateEventSelect(HRTIMER_Type_T * ptrHRTimer, uint32_T updateInput)
{
    if(updateInput == 1)
    {
        LL_HRTIM_SuspendUpdate(ptrHRTimer->PeripheralPtr, LL_HRTIM_TIMER_A);
    }
    else if(updateInput == 0)
    {
       LL_HRTIM_ResumeUpdate(ptrHRTimer->PeripheralPtr, LL_HRTIM_TIMER_A);
    }
}

/*Set the TIMERB UpdateEvent to Suspend/Resume */
__STATIC_INLINE void setTimerBSuspendUpdateEventSelect(HRTIMER_Type_T * ptrHRTimer, uint32_T updateInput)
{
    if(updateInput == 1)
    {
        LL_HRTIM_SuspendUpdate(ptrHRTimer->PeripheralPtr, LL_HRTIM_TIMER_B);
    }
    else if(updateInput == 0)
    {
       LL_HRTIM_ResumeUpdate(ptrHRTimer->PeripheralPtr, LL_HRTIM_TIMER_B);
    }
}

/*Set the TIMERC UpdateEvent to Suspend/Resume */
__STATIC_INLINE void setTimerCSuspendUpdateEventSelect(HRTIMER_Type_T * ptrHRTimer, uint32_T updateInput)
{
    if(updateInput == 1)
    {
        LL_HRTIM_SuspendUpdate(ptrHRTimer->PeripheralPtr, LL_HRTIM_TIMER_C);
    }
    else if(updateInput == 0)
    {
        LL_HRTIM_ResumeUpdate(ptrHRTimer->PeripheralPtr, LL_HRTIM_TIMER_C);
    }
}

/*Set the TIMERD UpdateEvent to Suspend/Resume */
__STATIC_INLINE void setTimerDSuspendUpdateEventSelect(HRTIMER_Type_T * ptrHRTimer, uint32_T updateInput)
{
    if(updateInput == 1)
    {
        LL_HRTIM_SuspendUpdate(ptrHRTimer->PeripheralPtr, LL_HRTIM_TIMER_D);
    }
    else if(updateInput == 0)
    {
        LL_HRTIM_ResumeUpdate(ptrHRTimer->PeripheralPtr, LL_HRTIM_TIMER_D);
    }
}

/*Set the TIMERE UpdateEvent to Suspend/Resume */
__STATIC_INLINE void setTimerESuspendUpdateEventSelect(HRTIMER_Type_T * ptrHRTimer, uint32_T updateInput)
{
    if(updateInput == 1)
    {
        LL_HRTIM_SuspendUpdate(ptrHRTimer->PeripheralPtr, LL_HRTIM_TIMER_E);
    }
    else if(updateInput == 0)
    {
        LL_HRTIM_ResumeUpdate(ptrHRTimer->PeripheralPtr, LL_HRTIM_TIMER_E);
    }
}

/*Set the TIMERF UpdateEvent to Suspend/Resume */
#if defined(STM32G4)
__STATIC_INLINE void setTimerFSuspendUpdateEventSelect(HRTIMER_Type_T * ptrHRTimer, uint32_T updateInput)
{
    if(updateInput == 1)
    {
        LL_HRTIM_SuspendUpdate(ptrHRTimer->PeripheralPtr, LL_HRTIM_TIMER_F);
    }
    else if(updateInput == 0)
    {
       LL_HRTIM_ResumeUpdate(ptrHRTimer->PeripheralPtr, LL_HRTIM_TIMER_F);
    }
}
#endif
/*Set the MAINTIMER UpdateEvent to Suspend/Resume */
__STATIC_INLINE void setMainTimerSuspendUpdateEventSelect(HRTIMER_Type_T * ptrHRTimer, uint32_T updateInput)
{
    if(updateInput == 1)
    {
        LL_HRTIM_SuspendUpdate(ptrHRTimer->PeripheralPtr, LL_HRTIM_TIMER_MASTER);
    }
    else if(updateInput == 0)
    {
        LL_HRTIM_ResumeUpdate(ptrHRTimer->PeripheralPtr, LL_HRTIM_TIMER_MASTER);
    }
}

/*Force output active/inactive level on TIMERA outputs */
__STATIC_INLINE void setTimerAOutputlevels(HRTIMER_Type_T * ptrHRTimer, boolean_T Outputlevel, boolean_T channelInput,boolean_T outstate)
{
    if(channelInput == 0 && Outputlevel == 1 && outstate == 0)
    {
       if(LL_HRTIM_OUT_GetLevel(ptrHRTimer->PeripheralPtr, LL_HRTIM_OUTPUT_TA1) == Outputlevel)
       {
           LL_HRTIM_OUT_ForceLevel(ptrHRTimer->PeripheralPtr, LL_HRTIM_OUTPUT_TA1,0);
       }  
    }/* RST operation */
    else if(channelInput == 0 && Outputlevel == 1 && outstate == 1)
    {
       if(LL_HRTIM_OUT_GetLevel(ptrHRTimer->PeripheralPtr, LL_HRTIM_OUTPUT_TA1)!= Outputlevel)
       {
           LL_HRTIM_OUT_ForceLevel(ptrHRTimer->PeripheralPtr, LL_HRTIM_OUTPUT_TA1,1);
       }
    }/* SST operation */
    else if(channelInput == 1 && Outputlevel == 1 && outstate == 0)
    {
       if(LL_HRTIM_OUT_GetLevel(ptrHRTimer->PeripheralPtr, LL_HRTIM_OUTPUT_TA2) == Outputlevel)
       {
           LL_HRTIM_OUT_ForceLevel(ptrHRTimer->PeripheralPtr, LL_HRTIM_OUTPUT_TA2,0);
       }  
    }/* RST operation */
    else if(channelInput == 1 && Outputlevel == 1 && outstate == 1)
    {
       if(LL_HRTIM_OUT_GetLevel(ptrHRTimer->PeripheralPtr, LL_HRTIM_OUTPUT_TA2)!= Outputlevel)
       {
           LL_HRTIM_OUT_ForceLevel(ptrHRTimer->PeripheralPtr, LL_HRTIM_OUTPUT_TA2,1);
       }
    }/* SST operation */
}

/*Force output active/inactive level on TIMERB outputs */
__STATIC_INLINE void setTimerBOutputlevels(HRTIMER_Type_T * ptrHRTimer, boolean_T Outputlevel, boolean_T channelInput,boolean_T outstate)
{
    if(channelInput == 0 && Outputlevel == 1 && outstate == 0)
    {
       if(LL_HRTIM_OUT_GetLevel(ptrHRTimer->PeripheralPtr, LL_HRTIM_OUTPUT_TB1) == Outputlevel)
       {
           LL_HRTIM_OUT_ForceLevel(ptrHRTimer->PeripheralPtr, LL_HRTIM_OUTPUT_TB1,0);
       }  
    }/* RST operation */
    else if(channelInput == 0 && Outputlevel == 1 && outstate == 1)
    {
       if(LL_HRTIM_OUT_GetLevel(ptrHRTimer->PeripheralPtr, LL_HRTIM_OUTPUT_TB1)!= Outputlevel)
       {
           LL_HRTIM_OUT_ForceLevel(ptrHRTimer->PeripheralPtr, LL_HRTIM_OUTPUT_TB1,1);
       }
    }/* SST operation */
    else if(channelInput == 1 && Outputlevel == 1 && outstate == 0)
    {
       if(LL_HRTIM_OUT_GetLevel(ptrHRTimer->PeripheralPtr, LL_HRTIM_OUTPUT_TB2) == Outputlevel)
       {
           LL_HRTIM_OUT_ForceLevel(ptrHRTimer->PeripheralPtr, LL_HRTIM_OUTPUT_TB2,0);
       }  
    }/* RST operation */
    else if(channelInput == 1 && Outputlevel == 1 && outstate == 1)
    {
       if(LL_HRTIM_OUT_GetLevel(ptrHRTimer->PeripheralPtr, LL_HRTIM_OUTPUT_TB2)!= Outputlevel)
       {
           LL_HRTIM_OUT_ForceLevel(ptrHRTimer->PeripheralPtr, LL_HRTIM_OUTPUT_TB2,1);
       }
    }/* SST operation */
}

/*Force output active/inactive level on TIMERC outputs */
__STATIC_INLINE void setTimerCOutputlevels(HRTIMER_Type_T * ptrHRTimer, boolean_T Outputlevel, boolean_T channelInput,boolean_T outstate)
{
    if(channelInput == 0 && Outputlevel == 1 && outstate == 0)
    {
       if(LL_HRTIM_OUT_GetLevel(ptrHRTimer->PeripheralPtr, LL_HRTIM_OUTPUT_TC1) == Outputlevel)
       {
           LL_HRTIM_OUT_ForceLevel(ptrHRTimer->PeripheralPtr, LL_HRTIM_OUTPUT_TC1,0);
       }  
    }/* RST operation */
    else if(channelInput == 0 && Outputlevel == 1 && outstate == 1)
    {
       if(LL_HRTIM_OUT_GetLevel(ptrHRTimer->PeripheralPtr, LL_HRTIM_OUTPUT_TC1)!= Outputlevel)
       {
           LL_HRTIM_OUT_ForceLevel(ptrHRTimer->PeripheralPtr, LL_HRTIM_OUTPUT_TC1,1);
       }
    }/* SST operation */
    else if(channelInput == 1 && Outputlevel == 1 && outstate == 0)
    {
       if(LL_HRTIM_OUT_GetLevel(ptrHRTimer->PeripheralPtr, LL_HRTIM_OUTPUT_TC2) == Outputlevel)
       {
           LL_HRTIM_OUT_ForceLevel(ptrHRTimer->PeripheralPtr, LL_HRTIM_OUTPUT_TC2,0);
       }  
    }/* RST operation */
    else if(channelInput == 1 && Outputlevel == 1 && outstate == 1)
    {
       if(LL_HRTIM_OUT_GetLevel(ptrHRTimer->PeripheralPtr, LL_HRTIM_OUTPUT_TC2)!= Outputlevel)
       {
           LL_HRTIM_OUT_ForceLevel(ptrHRTimer->PeripheralPtr, LL_HRTIM_OUTPUT_TC2,1);
       }
    }/* SST operation */
}

/*Force output active/inactive level on TIMERD outputs */
__STATIC_INLINE void setTimerDOutputlevels(HRTIMER_Type_T * ptrHRTimer, boolean_T Outputlevel, boolean_T channelInput,boolean_T outstate)
{
    if(channelInput == 0 && Outputlevel == 1 && outstate == 0)
    {
       if(LL_HRTIM_OUT_GetLevel(ptrHRTimer->PeripheralPtr, LL_HRTIM_OUTPUT_TD1) == Outputlevel)
       {
           LL_HRTIM_OUT_ForceLevel(ptrHRTimer->PeripheralPtr, LL_HRTIM_OUTPUT_TD1,0);
       }  
    }/* RST operation */
    else if(channelInput == 0 && Outputlevel == 1 && outstate == 1)
    {
       if(LL_HRTIM_OUT_GetLevel(ptrHRTimer->PeripheralPtr, LL_HRTIM_OUTPUT_TD1)!= Outputlevel)
       {
           LL_HRTIM_OUT_ForceLevel(ptrHRTimer->PeripheralPtr, LL_HRTIM_OUTPUT_TD1,1);
       }
    }/* SST operation */
    else if(channelInput == 1 && Outputlevel == 1 && outstate == 0)
    {
       if(LL_HRTIM_OUT_GetLevel(ptrHRTimer->PeripheralPtr, LL_HRTIM_OUTPUT_TD2) == Outputlevel)
       {
           LL_HRTIM_OUT_ForceLevel(ptrHRTimer->PeripheralPtr, LL_HRTIM_OUTPUT_TD2,0);
       }  
    }/* RST operation */
    else if(channelInput == 1 && Outputlevel == 1 && outstate == 1)
    {
       if(LL_HRTIM_OUT_GetLevel(ptrHRTimer->PeripheralPtr, LL_HRTIM_OUTPUT_TD2)!= Outputlevel)
       {
           LL_HRTIM_OUT_ForceLevel(ptrHRTimer->PeripheralPtr, LL_HRTIM_OUTPUT_TD2,1);
       }
    }/* SST operation */
}

/*Force output active/inactive level on TIMERE outputs */
__STATIC_INLINE void setTimerEOutputlevels(HRTIMER_Type_T * ptrHRTimer, boolean_T Outputlevel, boolean_T channelInput,boolean_T outstate)
{
    if(channelInput == 0 && Outputlevel == 1 && outstate == 0)
    {
       if(LL_HRTIM_OUT_GetLevel(ptrHRTimer->PeripheralPtr, LL_HRTIM_OUTPUT_TE1) == Outputlevel)
       {
           LL_HRTIM_OUT_ForceLevel(ptrHRTimer->PeripheralPtr, LL_HRTIM_OUTPUT_TE1,0);
       }  
    }/* RST operation */
    else if(channelInput == 0 && Outputlevel == 1 && outstate == 1)
    {
       if(LL_HRTIM_OUT_GetLevel(ptrHRTimer->PeripheralPtr, LL_HRTIM_OUTPUT_TE1)!= Outputlevel)
       {
           LL_HRTIM_OUT_ForceLevel(ptrHRTimer->PeripheralPtr, LL_HRTIM_OUTPUT_TE1,1);
       }
    }/* SST operation */
    else if(channelInput == 1 && Outputlevel == 1 && outstate == 0)
    {
       if(LL_HRTIM_OUT_GetLevel(ptrHRTimer->PeripheralPtr, LL_HRTIM_OUTPUT_TE2) == Outputlevel)
       {
           LL_HRTIM_OUT_ForceLevel(ptrHRTimer->PeripheralPtr, LL_HRTIM_OUTPUT_TE2,0);
       }  
    }/* RST operation */
    else if(channelInput == 1 && Outputlevel == 1 && outstate == 1)
    {
       if(LL_HRTIM_OUT_GetLevel(ptrHRTimer->PeripheralPtr, LL_HRTIM_OUTPUT_TE2)!= Outputlevel)
       {
           LL_HRTIM_OUT_ForceLevel(ptrHRTimer->PeripheralPtr, LL_HRTIM_OUTPUT_TE2,1);
       }
    }/* SST operation */
}

#if defined(STM32G4)
/*Force output active/inactive level on TIMERF outputs */
__STATIC_INLINE void setTimerFOutputlevels(HRTIMER_Type_T * ptrHRTimer, boolean_T Outputlevel, boolean_T channelInput,boolean_T outstate)
{
    if(channelInput == 0 && Outputlevel == 1 && outstate == 0)
    {
       if(LL_HRTIM_OUT_GetLevel(ptrHRTimer->PeripheralPtr, LL_HRTIM_OUTPUT_TF1) == Outputlevel)
       {
           LL_HRTIM_OUT_ForceLevel(ptrHRTimer->PeripheralPtr, LL_HRTIM_OUTPUT_TF1,0);
       }  
    }/* RST operation */
    else if(channelInput == 0 && Outputlevel == 1 && outstate == 1)
     {
       if(LL_HRTIM_OUT_GetLevel(ptrHRTimer->PeripheralPtr, LL_HRTIM_OUTPUT_TF1)!= Outputlevel)
       {
           LL_HRTIM_OUT_ForceLevel(ptrHRTimer->PeripheralPtr, LL_HRTIM_OUTPUT_TF1,1);
       }
    }/* SST operation */
    else if(channelInput == 1 && Outputlevel == 1 && outstate == 0)
     {
       if(LL_HRTIM_OUT_GetLevel(ptrHRTimer->PeripheralPtr, LL_HRTIM_OUTPUT_TF2) == Outputlevel)
       {
           LL_HRTIM_OUT_ForceLevel(ptrHRTimer->PeripheralPtr, LL_HRTIM_OUTPUT_TF2,0);
       }  
    }/* RST operation */
    else if(channelInput == 1 && Outputlevel == 1 && outstate == 1)
    {
       if(LL_HRTIM_OUT_GetLevel(ptrHRTimer->PeripheralPtr, LL_HRTIM_OUTPUT_TF2)!= Outputlevel)
       {
           LL_HRTIM_OUT_ForceLevel(ptrHRTimer->PeripheralPtr, LL_HRTIM_OUTPUT_TF2,1);
       }
    }/* SST operation */
}
#endif
/*Set the TIMERA CMP1 register if Enable compare1 Input is set */
__STATIC_INLINE void setTimerAcompare1AccToInput(HRTIMER_Type_T * ptrHRTimer, uint32_T compare1Input)
{
    if(LL_HRTIM_TIM_GetCompare1(ptrHRTimer->PeripheralPtr,LL_HRTIM_TIMER_A) != compare1Input)
    {
        LL_HRTIM_TIM_SetCompare1(ptrHRTimer->PeripheralPtr, LL_HRTIM_TIMER_A, (uint32_T)compare1Input);
    }
}
/*Set the TIMERB CMP1 register if Enable compare1 Input is set */
__STATIC_INLINE void setTimerBcompare1AccToInput(HRTIMER_Type_T * ptrHRTimer, uint32_T compare1Input)
{
    if(LL_HRTIM_TIM_GetCompare1(ptrHRTimer->PeripheralPtr,LL_HRTIM_TIMER_B) != compare1Input)
    {
        LL_HRTIM_TIM_SetCompare1(ptrHRTimer->PeripheralPtr, LL_HRTIM_TIMER_B, (uint32_T)compare1Input);
    }
}
/*Set the TIMERC CMP1 register if Enable compare1 Input is set */
__STATIC_INLINE void setTimerCcompare1AccToInput(HRTIMER_Type_T * ptrHRTimer, uint32_T compare1Input)
{
    if(LL_HRTIM_TIM_GetCompare1(ptrHRTimer->PeripheralPtr,LL_HRTIM_TIMER_C) != compare1Input)
    {
        LL_HRTIM_TIM_SetCompare1(ptrHRTimer->PeripheralPtr, LL_HRTIM_TIMER_C, (uint32_T)compare1Input);
    }
}
/*Set the TIMERD CMP1 register if Enable compare1 Input is set */
__STATIC_INLINE void setTimerDcompare1AccToInput(HRTIMER_Type_T * ptrHRTimer, uint32_T compare1Input)
{
    if(LL_HRTIM_TIM_GetCompare1(ptrHRTimer->PeripheralPtr,LL_HRTIM_TIMER_D) != compare1Input)
    {
        LL_HRTIM_TIM_SetCompare1(ptrHRTimer->PeripheralPtr, LL_HRTIM_TIMER_D, (uint32_T)compare1Input);
    }
}
/*Set the TIMERE CMP1 register if Enable compare1 Input is set */
__STATIC_INLINE void setTimerEcompare1AccToInput(HRTIMER_Type_T * ptrHRTimer, uint32_T compare1Input)
{
    if(LL_HRTIM_TIM_GetCompare1(ptrHRTimer->PeripheralPtr,LL_HRTIM_TIMER_E) != compare1Input)
    {
        LL_HRTIM_TIM_SetCompare1(ptrHRTimer->PeripheralPtr, LL_HRTIM_TIMER_E, (uint32_T)compare1Input);
    }
}
/*Set the TIMERF CMP1 register if Enable compare1 Input is set */
#if defined(STM32G4)
__STATIC_INLINE void setTimerFcompare1AccToInput(HRTIMER_Type_T * ptrHRTimer, uint32_T compare1Input)
{
    if(LL_HRTIM_TIM_GetCompare1(ptrHRTimer->PeripheralPtr,LL_HRTIM_TIMER_F) != compare1Input)
    {
        LL_HRTIM_TIM_SetCompare1(ptrHRTimer->PeripheralPtr, LL_HRTIM_TIMER_F, (uint32_T)compare1Input);
    }
}
#endif
/*Set the Main Timer CMP1 register if Enable compare1 Input is set */
__STATIC_INLINE void setMainTimercompare1AccToInput(HRTIMER_Type_T * ptrHRTimer, uint32_T compare1Input)
{
    if(LL_HRTIM_TIM_GetCompare1(ptrHRTimer->PeripheralPtr,LL_HRTIM_TIMER_MASTER) != compare1Input)
    {
        LL_HRTIM_TIM_SetCompare1(ptrHRTimer->PeripheralPtr, LL_HRTIM_TIMER_MASTER, (uint32_T)compare1Input);
    }
}

/*Set the TIMERA CMP2 register if Enable compare2 Input is set */
__STATIC_INLINE void setTimerAcompare2AccToInput(HRTIMER_Type_T * ptrHRTimer, uint32_T compare2Input)
{
    if(LL_HRTIM_TIM_GetCompare2(ptrHRTimer->PeripheralPtr,LL_HRTIM_TIMER_A) != compare2Input)
    {
        LL_HRTIM_TIM_SetCompare2(ptrHRTimer->PeripheralPtr, LL_HRTIM_TIMER_A, (uint32_T)compare2Input);
    }
}
/*Set the TIMERB CMP2 register if Enable compare2 Input is set */
__STATIC_INLINE void setTimerBcompare2AccToInput(HRTIMER_Type_T * ptrHRTimer, uint32_T compare2Input)
{
    if(LL_HRTIM_TIM_GetCompare2(ptrHRTimer->PeripheralPtr,LL_HRTIM_TIMER_B) != compare2Input)
    {
        LL_HRTIM_TIM_SetCompare2(ptrHRTimer->PeripheralPtr, LL_HRTIM_TIMER_B, (uint32_T)compare2Input);
    }
}
/*Set the TIMERC CMP2 register if Enable compare2 Input is set */
__STATIC_INLINE void setTimerCcompare2AccToInput(HRTIMER_Type_T * ptrHRTimer, uint32_T compare2Input)
{
    if(LL_HRTIM_TIM_GetCompare2(ptrHRTimer->PeripheralPtr,LL_HRTIM_TIMER_C) != compare2Input)
    {
        LL_HRTIM_TIM_SetCompare2(ptrHRTimer->PeripheralPtr, LL_HRTIM_TIMER_C, (uint32_T)compare2Input);
    }
}
/*Set the TIMERD CMP2 register if Enable compare2 Input is set */
__STATIC_INLINE void setTimerDcompare2AccToInput(HRTIMER_Type_T * ptrHRTimer, uint32_T compare2Input)
{
    if(LL_HRTIM_TIM_GetCompare2(ptrHRTimer->PeripheralPtr,LL_HRTIM_TIMER_D) != compare2Input)
    {
        LL_HRTIM_TIM_SetCompare2(ptrHRTimer->PeripheralPtr, LL_HRTIM_TIMER_D, (uint32_T)compare2Input);
    }
}
/*Set the TIMERE CMP2 register if Enable compare2 Input is set */
__STATIC_INLINE void setTimerEcompare2AccToInput(HRTIMER_Type_T * ptrHRTimer, uint32_T compare2Input)
{
    if(LL_HRTIM_TIM_GetCompare2(ptrHRTimer->PeripheralPtr,LL_HRTIM_TIMER_E) != compare2Input)
    {
        LL_HRTIM_TIM_SetCompare2(ptrHRTimer->PeripheralPtr, LL_HRTIM_TIMER_E, (uint32_T)compare2Input);
    }
}
/*Set the TIMERF CMP2 register if Enable compare2 Input is set */
#if defined(STM32G4)
__STATIC_INLINE void setTimerFcompare2AccToInput(HRTIMER_Type_T * ptrHRTimer, uint32_T compare2Input)
{
    if(LL_HRTIM_TIM_GetCompare2(ptrHRTimer->PeripheralPtr,LL_HRTIM_TIMER_F) != compare2Input)
    {
        LL_HRTIM_TIM_SetCompare2(ptrHRTimer->PeripheralPtr, LL_HRTIM_TIMER_F, (uint32_T)compare2Input);
    }
}
#endif
/*Set the Main Timer CMP2 register if Enable compare2 Input is set */
__STATIC_INLINE void setMainTimercompare2AccToInput(HRTIMER_Type_T * ptrHRTimer, uint32_T compare2Input)
{
    if(LL_HRTIM_TIM_GetCompare2(ptrHRTimer->PeripheralPtr,LL_HRTIM_TIMER_MASTER) != compare2Input)
    {
        LL_HRTIM_TIM_SetCompare2(ptrHRTimer->PeripheralPtr, LL_HRTIM_TIMER_MASTER, (uint32_T)compare2Input);
    }
}

/*Set the TIMERA CMP3 register if Enable compare3 Input is set */
__STATIC_INLINE void setTimerAcompare3AccToInput(HRTIMER_Type_T * ptrHRTimer, uint32_T compare3Input)
{
    if(LL_HRTIM_TIM_GetCompare3(ptrHRTimer->PeripheralPtr,LL_HRTIM_TIMER_A) != compare3Input)
    {
        LL_HRTIM_TIM_SetCompare3(ptrHRTimer->PeripheralPtr, LL_HRTIM_TIMER_A, (uint32_T)compare3Input);
    }
}
/*Set the TIMERB CMP3 register if Enable compare3 Input is set */
__STATIC_INLINE void setTimerBcompare3AccToInput(HRTIMER_Type_T * ptrHRTimer, uint32_T compare3Input)
{
    if(LL_HRTIM_TIM_GetCompare3(ptrHRTimer->PeripheralPtr,LL_HRTIM_TIMER_B) != compare3Input)
    {
        LL_HRTIM_TIM_SetCompare3(ptrHRTimer->PeripheralPtr, LL_HRTIM_TIMER_B, (uint32_T)compare3Input);
    }
}
/*Set the TIMERC CMP3 register if Enable compare3 Input is set */
__STATIC_INLINE void setTimerCcompare3AccToInput(HRTIMER_Type_T * ptrHRTimer, uint32_T compare3Input)
{
    if(LL_HRTIM_TIM_GetCompare3(ptrHRTimer->PeripheralPtr,LL_HRTIM_TIMER_C) != compare3Input)
    {
        LL_HRTIM_TIM_SetCompare3(ptrHRTimer->PeripheralPtr, LL_HRTIM_TIMER_C, (uint32_T)compare3Input);
    }
}
/*Set the TIMERD CMP3 register if Enable compare3 Input is set */
__STATIC_INLINE void setTimerDcompare3AccToInput(HRTIMER_Type_T * ptrHRTimer, uint32_T compare3Input)
{
    if(LL_HRTIM_TIM_GetCompare3(ptrHRTimer->PeripheralPtr,LL_HRTIM_TIMER_D) != compare3Input)
    {
        LL_HRTIM_TIM_SetCompare3(ptrHRTimer->PeripheralPtr, LL_HRTIM_TIMER_D, (uint32_T)compare3Input);
    }
}
/*Set the TIMERE CMP3 register if Enable compare3 Input is set */
__STATIC_INLINE void setTimerEcompare3AccToInput(HRTIMER_Type_T * ptrHRTimer, uint32_T compare3Input)
{
    if(LL_HRTIM_TIM_GetCompare3(ptrHRTimer->PeripheralPtr,LL_HRTIM_TIMER_E) != compare3Input)
    {
        LL_HRTIM_TIM_SetCompare3(ptrHRTimer->PeripheralPtr, LL_HRTIM_TIMER_E, (uint32_T)compare3Input);
    }
}
/*Set the TIMERF CMP3 register if Enable compare3 Input is set */
#if defined(STM32G4)
__STATIC_INLINE void setTimerFcompare3AccToInput(HRTIMER_Type_T * ptrHRTimer, uint32_T compare3Input)
{
    if(LL_HRTIM_TIM_GetCompare3(ptrHRTimer->PeripheralPtr,LL_HRTIM_TIMER_F) != compare3Input)
    {
        LL_HRTIM_TIM_SetCompare3(ptrHRTimer->PeripheralPtr, LL_HRTIM_TIMER_F, (uint32_T)compare3Input);
    }
}
#endif
/*Set the Main Timer CMP3 register if Enable compare3 Input is set */
__STATIC_INLINE void setMainTimercompare3AccToInput(HRTIMER_Type_T * ptrHRTimer, uint32_T compare3Input)
{
    if(LL_HRTIM_TIM_GetCompare3(ptrHRTimer->PeripheralPtr,LL_HRTIM_TIMER_MASTER) != compare3Input)
    {
        LL_HRTIM_TIM_SetCompare3(ptrHRTimer->PeripheralPtr, LL_HRTIM_TIMER_MASTER, (uint32_T)compare3Input);
    }
}

/*Set the TIMERA CMP4 register if Enable compare4 Input is set */
__STATIC_INLINE void setTimerAcompare4AccToInput(HRTIMER_Type_T * ptrHRTimer, uint32_T compare4Input)
{
    if(LL_HRTIM_TIM_GetCompare4(ptrHRTimer->PeripheralPtr,LL_HRTIM_TIMER_A) != compare4Input)
    {
        LL_HRTIM_TIM_SetCompare4(ptrHRTimer->PeripheralPtr, LL_HRTIM_TIMER_A, (uint32_T)compare4Input);
    }
}
/*Set the TIMERB CMP4 register if Enable compare4 Input is set */
__STATIC_INLINE void setTimerBcompare4AccToInput(HRTIMER_Type_T * ptrHRTimer, uint32_T compare4Input)
{
    if(LL_HRTIM_TIM_GetCompare4(ptrHRTimer->PeripheralPtr,LL_HRTIM_TIMER_B) != compare4Input)
    {
        LL_HRTIM_TIM_SetCompare4(ptrHRTimer->PeripheralPtr, LL_HRTIM_TIMER_B, (uint32_T)compare4Input);
    }
}
/*Set the TIMERC CMP4 register if Enable compare4 Input is set */
__STATIC_INLINE void setTimerCcompare4AccToInput(HRTIMER_Type_T * ptrHRTimer, uint32_T compare4Input)
{
    if(LL_HRTIM_TIM_GetCompare4(ptrHRTimer->PeripheralPtr,LL_HRTIM_TIMER_C) != compare4Input)
    {
        LL_HRTIM_TIM_SetCompare4(ptrHRTimer->PeripheralPtr, LL_HRTIM_TIMER_C, (uint32_T)compare4Input);
    }
}
/*Set the TIMERD CMP4 register if Enable compare4 Input is set */
__STATIC_INLINE void setTimerDcompare4AccToInput(HRTIMER_Type_T * ptrHRTimer, uint32_T compare4Input)
{
    if(LL_HRTIM_TIM_GetCompare4(ptrHRTimer->PeripheralPtr,LL_HRTIM_TIMER_D) != compare4Input)
    {
        LL_HRTIM_TIM_SetCompare4(ptrHRTimer->PeripheralPtr, LL_HRTIM_TIMER_D, (uint32_T)compare4Input);
    }
}
/*Set the TIMERE CMP4 register if Enable compare4 Input is set */
__STATIC_INLINE void setTimerEcompare4AccToInput(HRTIMER_Type_T * ptrHRTimer, uint32_T compare4Input)
{
    if(LL_HRTIM_TIM_GetCompare4(ptrHRTimer->PeripheralPtr,LL_HRTIM_TIMER_E) != compare4Input)
    {
        LL_HRTIM_TIM_SetCompare4(ptrHRTimer->PeripheralPtr, LL_HRTIM_TIMER_E, (uint32_T)compare4Input);
    }
}
/*Set the TIMERF CMP4 register if Enable compare4 Input is set */
#if defined(STM32G4)
__STATIC_INLINE void setTimerFcompare4AccToInput(HRTIMER_Type_T * ptrHRTimer, uint32_T compare4Input)
{
    if(LL_HRTIM_TIM_GetCompare4(ptrHRTimer->PeripheralPtr,LL_HRTIM_TIMER_F) != compare4Input)
    {
        LL_HRTIM_TIM_SetCompare4(ptrHRTimer->PeripheralPtr, LL_HRTIM_TIMER_F, (uint32_T)compare4Input);
    }
}
#endif
/*Set the Main Timer CMP4 register if Enable compare4 Input is set */
__STATIC_INLINE void setMainTimercompare4AccToInput(HRTIMER_Type_T * ptrHRTimer, uint32_T compare4Input)
{
    if(LL_HRTIM_TIM_GetCompare4(ptrHRTimer->PeripheralPtr,LL_HRTIM_TIMER_MASTER) != compare4Input)
    {
        LL_HRTIM_TIM_SetCompare4(ptrHRTimer->PeripheralPtr, LL_HRTIM_TIMER_MASTER, (uint32_T)compare4Input);
    }
}

/*Enable the counter of the selected Timer */
__STATIC_INLINE void enableHRtimerCounter(HRTIMER_Type_T * ptrHRTimer, uint32_T Timeroffset)
{
    LL_HRTIM_TIM_CounterEnable(ptrHRTimer->PeripheralPtr, Timeroffset);
}

/*Disable the counter of the selected Timer */
__STATIC_INLINE void disableHRtimerCounter(HRTIMER_Type_T * ptrHRTimer, uint32_T Timeroffset)
{

    LL_HRTIM_TIM_CounterDisable(ptrHRTimer->PeripheralPtr, Timeroffset);

}

/******************************************************************************
* Static Inline functions
*******************************************************************************/
HRTIMER_Type_T * HRTimer_Handle_Init(HRTIMER_Type_T * ptrTimer);
void enableTimerAChannelx(HRTIMER_Type_T * ptrHRTimer, uint32_T TIMERAChannelInfo);
void enableTimerBChannelx(HRTIMER_Type_T * ptrHRTimer, uint32_T TIMERBChannelInfo);
void enableTimerCChannelx(HRTIMER_Type_T * ptrHRTimer, uint32_T TIMERCChannelInfo);
void enableTimerDChannelx(HRTIMER_Type_T * ptrHRTimer, uint32_T TIMERDChannelInfo);
void enableTimerEChannelx(HRTIMER_Type_T * ptrHRTimer, uint32_T TIMEREChannelInfo);
void enableTimerFChannelx(HRTIMER_Type_T * ptrHRTimer, uint32_T TIMERFChannelInfo);
void disableTimerAChannelx(HRTIMER_Type_T * ptrHRTimer, uint32_T TIMERAChannelInfo);
void disableTimerBChannelx(HRTIMER_Type_T * ptrHRTimer, uint32_T TIMERBChannelInfo);
void disableTimerCChannelx(HRTIMER_Type_T * ptrHRTimer, uint32_T TIMERCChannelInfo);
void disableTimerDChannelx(HRTIMER_Type_T * ptrHRTimer, uint32_T TIMERDChannelInfo);
void disableTimerEChannelx(HRTIMER_Type_T * ptrHRTimer, uint32_T TIMEREChannelInfo);
void disableTimerFChannelx(HRTIMER_Type_T * ptrHRTimer, uint32_T TIMERFChannelInfo);
void enableCountersInSync(HRTIMER_Type_T * ptrHRTimer, uint32_T SyncCounters);
void enableHRtimerCounter(HRTIMER_Type_T * ptrHRTimer, uint32_T Timeroffset);
void disableHRtimerCounter(HRTIMER_Type_T * ptrHRTimer, uint32_T Timeroffset);
void enableHRTimerxInterrupts(HRTIMER_Type_T * ptrHRTimer, uint32_T Timeroffset,  uint16_T interruptsToEnable);
void enableHRTimerMainInterrupts(HRTIMER_Type_T * ptrHRTimer, uint16_T interruptsToEnable);
void enableHRTimerGlobalInterrupts(HRTIMER_Type_T * ptrHRTimer, uint16_T interruptsToEnable);
void enableHRTimerFaultInterrupts(HRTIMER_Type_T * ptrHRTimer, uint16_T interruptsToEnable);
void disableHRTimerxInterrupts(HRTIMER_Type_T * ptrHRTimer, uint32_T Timeroffset, uint16_T interruptsToDisable);
void disableHRTimerMainInterrupts(HRTIMER_Type_T * ptrHRTimer, uint16_T interruptsToDisable);
void disableHRTimerGlobalInterrupts(HRTIMER_Type_T * ptrHRTimer, uint16_T interruptsToDisable);
void disableHRTimerFaultInterrupts(HRTIMER_Type_T * ptrHRTimer, uint16_T interruptsToDisable);
uint32_T checkHRTimerFrequencyAndDutyCycleLimits(uint32_T input);
#endif /* __STM_HRTIMER_LL_H__ */