#include <Os.h>
#include <user_led.h> 
#include <memory>
#include <gpio.h>
#include <hal/hal.h>


app::user_led::User_led<GPIOG_BASE, LD3_Pin> green_led;
app::user_led::User_led<GPIOG_BASE, LD4_Pin> red_led;

 void GreenLed_Init (void)
 {

  green_led.On();

 }

 void RedLed_Init (void)
 {

   red_led.Off();

 }

 void GreenLed_Run (void*)
 {
  static uint8_t ucIdx;
  
  if (ucIdx % 2)
  { 
    green_led.Off();
  }
  else
  { 

    green_led.On();
  }


  ucIdx++;

}

 void RedLed_Run (void*)
 {
  static uint8_t ucIdx;

  if (Os_GetEvent(TASK_RED_LED, OS_EVENT(LED_SWITCH_ON)) == true)
  {
    Os_ClearEvent(TASK_RED_LED, OS_EVENT(LED_SWITCH_ON));
    red_led.On();
  }

  if (Os_GetEvent(TASK_RED_LED, OS_EVENT(LED_SWITCH_OFF)) == true)
  {
    Os_ClearEvent(TASK_RED_LED, OS_EVENT(LED_SWITCH_OFF));
    red_led.Off();
  }
  

ucIdx++;

}

 void UserButton_Init (void){}
 void UserButton_Run (void*)
 {
  
  if(0)
  {
    Os_SetEvent(TASK_RED_LED, OS_EVENT(LED_SWITCH_ON)); 
  }
  else
  {
    Os_SetEvent(TASK_RED_LED, OS_EVENT(LED_SWITCH_OFF)); 
  }
 } 

 void Dummy_Idle(void*)
 {
   red_led.On();
 } 
  
  

