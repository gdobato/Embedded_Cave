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
#include <led/led.h> 
#include <hal/hal.h>
#include <gpio/gpio.h>
#include <system/system.h>
#include <timer/timer.h>

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
  HAL_Init();
  Gpio_Init();
  Timer_Init();
  
  //Start Os Scheduler
  Os_Start();

  //Error Hook
  for(;;)
  {

  }
}


