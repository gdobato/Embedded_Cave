#include <Os.h>
#include <userLed/userLed.h> 
#include <memory>
#include <gpio/gpio.h>

auto redLed    = std::make_unique<UserLed>(Gpio_WriteRedLed);
auto greenLed  = std::make_unique<UserLed>(Gpio_WriteGreenLed);


 void GreenLed_Init (void)
 {

    greenLed->On();

 }

 void RedLed_Init (void)
 {

    redLed->Off();

 }

 void GreenLed_Run (void*)
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

 void RedLed_Run (void*)
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
 void UserButton_Run (void*)
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

 void Dummy_Idle(void*)
 {
//    redLed->On();
 } 
  
  

