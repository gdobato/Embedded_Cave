
#include <portable/ARM/CM4F/Port.h>

void OsStart(void)
{
  SysTickTimer_Init();
  SysTickTimer_Start();
}

void test_PendSVHandler (void)
{
  __asm("nop");
}


void test_SystickHandler (void)
{
  __asm("nop");
}