/**
 * @file 
 * @author 
 * @date
 * @brief
 **/

/************************************
* Includes
************************************/
#include <Os.h>
#include <user_led.h> 
#include <hal_base.h>
#include <hal.h>
#include <gpio.h>
#include <system/system.h>
#include <timer.h>

/************************************
* Private definitions 
************************************/

/************************************
* Private type definitions 
************************************/

/************************************
* Private variables
************************************/

/************************************
* Private declarations 
************************************/

/************************************
* Implementation 
************************************/
 

int main(void)
{
  //Init Bsp
  bsp::hal  ::Init();
  bsp::timer::Init();
  bsp::gpio ::Init();

  
  //Start Os Scheduler
  Os_Start();

  //Error Hook
  for(;;)
  {

  }
}


