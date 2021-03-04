#include <stdint.h>
#include <hal.h>

extern "C"
{
void Interrupts_Enable   (void) { __asm("cpsie i");}
void Interrupts_Disable  (void) { __asm("cpsid i");}

uint32_t Timer_Start(uint32_t ulTimeOut)
{
  uint32_t ulTicks = HAL_GetTick();
  return (uint32_t)(ulTicks + ulTimeOut);
}

bool Timer_TimeOut(uint32_t ulTime)
{
   uint32_t ulTicks = HAL_GetTick();
   return  (((ulTicks - ulTime ) & (uint32_t)0x80000000UL) == (uint32_t)0U ) ? true : false;
}
}