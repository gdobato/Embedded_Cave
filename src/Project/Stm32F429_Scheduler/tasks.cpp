
#include <Os.h>
#include <led/led.h> 
#include <gpio/gpio.h>


 Led* redLed   = new Led(RED_LED);
 Led* greenLed = new Led(GREEN_LED); 




 void GreenLed_Init (void)
 {

    greenLed->On();

 }

 void RedLed_Init (void)
 {

    redLed->On();

 }

 void GreenLed_Run (void)
 {
  static uint8_t ucIdx;

  
  if (ucIdx % 2)
  { 
    greenLed->Off();
  }
  else
  { 

    greenLed->On();
  }

  if (ucIdx == 7)
  {
    //Os_SetEvent(TASK_RED_LED, OS_EVENT(0)); 
  }

  ucIdx++;

}

 void RedLed_Run (void)
 {
  static uint8_t ucIdx;

  if (Os_GetEvent(TASK_RED_LED, OS_EVENT(1))== true)
  {
     Os_ClearEvent(TASK_RED_LED, OS_EVENT(1));
     redLed->Off();
  }
  else
  {
    if (ucIdx % 2)
    { 
      redLed->Off();
    }
    else
    { 
      redLed->On();
    }
  }

ucIdx++;

}


 void UserButton_Init (void){}
 void UserButton_Run (void)
 {
  static uint8_t ucIdx;

  if (Gpio_GetUserButton() == GPIO_PIN_SET ) 
  {
    Os_SetEvent(TASK_RED_LED, OS_EVENT(1)); 
  }
  

  ucIdx++;

}