
#include <Os.h>
#include <led/led.h> 
#include <gpio/gpio.h>


 Led* redLed   = new Led(RED_LED);
 Led* greenLed = new Led(GREEN_LED); 

#define LED_SWITCH_OFF 0U
#define LED_SWITCH_ON  1U


 void GreenLed_Init (void)
 {

    greenLed->On();

 }

 void RedLed_Init (void)
 {

    redLed->Off();

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


  ucIdx++;

}

 void RedLed_Run (void)
 {
  static uint8_t ucIdx;

  if (Os_GetEvent(TASK_RED_LED, OS_EVENT(LED_SWITCH_ON)) == true)
  {
    Os_ClearEvent(TASK_RED_LED, OS_EVENT(LED_SWITCH_ON));
    redLed->On();
  }

  if (Os_GetEvent(TASK_RED_LED, OS_EVENT(LED_SWITCH_OFF)) == true)
  {
    Os_ClearEvent(TASK_RED_LED, OS_EVENT(LED_SWITCH_OFF));
    redLed->Off();
  }
  

ucIdx++;

}

 void UserButton_Init (void){}
 void UserButton_Run (void)
 {
  
  if (Gpio_GetUserButton() == GPIO_PIN_SET ) 
  {
    Os_SetEvent(TASK_RED_LED, OS_EVENT(LED_SWITCH_ON)); 
  }
  else
  {
    Os_SetEvent(TASK_RED_LED, OS_EVENT(LED_SWITCH_OFF)); 
  }
  
  
  
  


}