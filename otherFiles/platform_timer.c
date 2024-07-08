/* Copyright 2021-2022 The MathWorks, Inc. */

#include "mw_stm32_types.h"
#include "main.h"
#define MW_StringifyDefine(x) MW_StringifyDefineExpanded(x)
#define MW_StringifyDefineExpanded(x)  #x

#define MW_StringifyDefineHeader(x) MW_StringifyDefineHeaderExpand(x)
#define MW_StringifyDefineHeaderExpand(x)  x.h

#include MW_StringifyDefine(MW_StringifyDefineHeader(MODEL))

static volatile uint32_T timestampInitialized = 0;
static volatile uint32_T timestampStartTime = 0;

__weak void PeriphCommonClock_Config(void){};

__attribute__((optimize("O3"))) uint32_T getCurrentTimestampInMicros(void)
{
    uint32_T currentTime;
    __IO uint32_T timeInMs;
    __IO uint32_T timeInMicroTick;
    
    timeInMicroTick = (uint32_t)(MW_TIMEBASESOURCE->CNT);
    timeInMs = GET_CURRENT_TIME();

    /* Check timer is overrun before calculating time in micros */
    if (timeInMicroTick > (uint32_t)((MW_TIMEBASESOURCE)->CNT))
    {
        currentTime = GET_CURRENT_TIME()*1000 + (uint32_t)((MW_TIMEBASESOURCE)->CNT);
    }
    else
    {
        currentTime = timeInMs*1000 + timeInMicroTick;
    }

    return currentTime;
}

__attribute__((optimize("O3"))) uint32_T returnTimeElapsed(uint32_T timestampStartTime, boolean_T isTimeInMS)
{
    uint32_T currentTime;
    uint32_T ret = 0;
    
    if(0 == isTimeInMS)
    {
        currentTime = getCurrentTimestampInMicros();
    }
    else
    {
        currentTime = GET_CURRENT_TIME();
    }
    
    if (currentTime >= timestampStartTime)
    {
        ret = (uint32_T) (currentTime - timestampStartTime);
    }
    else
    {
        ret = (uint32_T) (UINT32_MAX - timestampStartTime + currentTime);
    }
    return ret ;
}

#if defined(EXT_MODE) && (EXT_MODE == 1) && !defined(XCP_TIMESTAMP_BASED_ON_SIMULATION_TIME)
static void timestampInit(void)
{
    if (0 == timestampInitialized)
    {
        timestampStartTime =  GET_CURRENT_TIME_IN_US();
        timestampInitialized = 1;
    }
}

__attribute__((optimize("O3"))) uint32_t getCurrentTimestamp(void)
{
    uint32_T ret = 0;
    if ((1 == runModel) || (1 == timestampInitialized))
    {
        if (0 == timestampInitialized)
        {
            timestampInit();
        }
        ret = returnTimeElapsed(timestampStartTime, 0);
    }
    else
    {
        timestampStartTime =  GET_CURRENT_TIME_IN_US();
    }
    return ret;
}
#endif

/* LocalWords:  TIMEBASESOURCE
 */
