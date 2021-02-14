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
  while(1)
  {
    __asm("nop");
  }
}


void test_PendSVHandler(void);
void test_SystickHandler(void);

