#include <stdint.h>
#include <OsCfg.h>
#if (MCU == CM4)
  #include <portable/ARM/CM4F/Port.h>
#endif


void OsStart(void)
{

}

void test_PendSVHandler (void)
{
  __asm("nop");
}

void test_SystickHandler (void)
{
  __asm("nop");
  PortContextSwitch();
}