/* Removing min 1ms wait from HAL_Delay */
#include "rtwtypes.h"
#include "main.h"

void HAL_Delay(uint32_t Delay)
{
  uint32_t tickstart = HAL_GetTick();
  uint32_t wait = Delay;

  /* Add a freq to guarantee minimum wait */
 /* if (wait < HAL_MAX_DELAY)
  {
    wait += (uint32_t)(uwTickFreq);
  }*/

  while((HAL_GetTick() - tickstart) < wait)
  {
  }
}