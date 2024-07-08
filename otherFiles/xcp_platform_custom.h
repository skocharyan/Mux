/*
* Copyright 2021-2022 The MathWorks, Inc.
*
* File: xcp_platform_custom.h
* Abstract:
*   Implementation of XCP Platform Abstraction Layer interface
*   for STM32F4xx-Based processors
*/

#ifndef XCP_PLATFORM_CUSTOM_H
#define XCP_PLATFORM_CUSTOM_H

#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include "sys_arch.h"
#include "main.h"
#include "mw_stm32_types.h"

extern void HAL_Delay(uint32_t);

#if defined(EXT_MODE) && (EXT_MODE == 1) 
    #define XCP_MUTEX_DEFINE(lock)    uint32_t lock
    #define XCP_MUTEX_INIT(lock)      lock = 0
    #define XCP_MUTEX_LOCK(lock)      lock = sys_arch_protect()
    #define XCP_MUTEX_UNLOCK(lock)    sys_arch_unprotect(lock)

    #define PRAGMA(n)   _Pragma(#n)
    #define XCP_PRAGMA_PACK_BEGIN(n)     PRAGMA(pack(push, n))
    #define XCP_PRAGMA_PACK_END()        PRAGMA(pack(pop))
    #define XCP_ATTRIBUTE_ALIGNED(n)
    #define XCP_ATTRIBUTE_PACKED

    #define XCP_ADDRESS_GET(addressExtension, address)  (uint8_T*) ((uintptr_t) address)

    #define XCP_SLEEP(s, us)          HAL_Delay( (1000*(s)) + ((us)/1000) )

    #define XCP_MEM_ALIGNMENT 4

    #ifndef XCP_TIMESTAMP_BASED_ON_SIMULATION_TIME
        uint32_t getCurrentTimestamp(void);
        #define XCP_TIMESTAMP_GET() getCurrentTimestamp()
        #define XCP_TIMESTAMP_UNIT XCP_TIMESTAMP_UNIT_1US
    #endif
	
#endif 

#define profileTimerRead() (getCurrentTimestampInMicros())
#endif
