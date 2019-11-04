/**
 * @file 
 * @author 
 * @date
 * @brief
 **/

/************************************
* Includes
************************************/
#include <stm32l475xx.h>
#include <OsAPI.h>
/************************************
* Private definitions 
************************************/

/************************************
* Private type definitions 
************************************/

/************************************
* Private variables
************************************/
extern uint32_t SystemCoreClock;

/************************************
* Private declarations 
************************************/

int main(void)
{
  SystemCoreClockUpdate();
  SysTick_Config(SystemCoreClock/1000);
  OsStart();
  while(1)
  {
    __asm("nop");
  }
}

