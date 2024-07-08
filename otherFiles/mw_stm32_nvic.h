/* Copyright 2021-2023 The MathWorks, Inc. */
#ifndef __MW_STM32_NVIC_H__
#define __MW_STM32_NVIC_H__

/* Offset to get IRQ numbers with respect to CMSIS.  The driver calls are written with respect to 
 * Hardware Interrupt block which expects positive number for interrupt numbers.
 */
#define MW_INTERRUPT_NUMBER_OFFSET 15

#define MW_EnableNVICPeripheral()
#define MW_DisableNVICPeripheral()

#define MW_NVIC_SetPriority(IRQNumber,IRQPriority)  NVIC_SetPriority(((IRQNumber)-MW_INTERRUPT_NUMBER_OFFSET),(IRQPriority))
#define MW_NVIC_EnableIRQ(IRQNumber)                NVIC_EnableIRQ((IRQNumber)-MW_INTERRUPT_NUMBER_OFFSET)
#define MW_NVIC_DisableIRQ(IRQNumber)               NVIC_DisableIRQ((IRQNumber)-MW_INTERRUPT_NUMBER_OFFSET)
#define MW_NVIC_ClearPendingIRQ(IRQNumber)          NVIC_ClearPendingIRQ((IRQNumber)-MW_INTERRUPT_NUMBER_OFFSET)

void MW_NVIC_ConfigureIRQ(uint32_T IRQNumber, void (*irqFcn)(void), uint32_T irqPriority);
uint32_T MW_HWI_MaskInterrupt(void);
#define MW_HWI_UnMaskInterrupt(old_maskStatus) __set_PRIMASK(old_maskStatus)


#endif /* __MW_STM32_NVIC_H__ */
