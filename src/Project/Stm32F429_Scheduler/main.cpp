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
 Led* redLed   = new Led(RED_LED);
 Led* greenLed = new Led(GREEN_LED); 

#ifdef __cplusplus
extern "C" {
#endif


 void Task1 (void)
 {
  static uint8_t ucIdx;
  
  if (ucIdx % 2)
  { 
    greenLed->On();
  }
  else
  { 

    greenLed->Off();
  }

  ucIdx++;

}

 void Task2 (void)
 {
  static uint8_t ucIdx;
  
  if (ucIdx % 2)
  { 
    redLed->On();
  }
  else
  { 

    redLed->Off();
  }

  ucIdx++;

}

int main(void)
{
  HAL_Init();
  Gpio_Init();
  Timer_Init();

  Os_Start();

  //Error Hook
  for(;;)
  {

  }
}


#ifdef __cplusplus
}
#endif
