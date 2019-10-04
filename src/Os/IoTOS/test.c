
#include <portable/ARM/CM4F/Port.h>
#include <stm32l475xx.h>

void OsStart(void)
{
  //SysTickTimer_Init();
  //SysTickTimer_Start();
  SysTick_Config(10000000);
}

void test_PendSVHandler (void)
{
  __asm("nop");
}


void test_SystickHandler (void)
{
  __asm("nop");
}