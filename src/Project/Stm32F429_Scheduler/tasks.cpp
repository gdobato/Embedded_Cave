#include <Os.h>
#include <user_led.h> 
#include <memory>
#include <gpio/gpio.h>
#include <hal.h>

app::user_led::User_led green_led{LD3_GPIO_Port, LD3_Pin};
app::user_led::User_led red_led  {LD4_GPIO_Port, LD4_Pin};

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
  
  //if (Gpio_GetUserButton() == GPIO_PIN_SET ) 
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
//    redLed->On();
 } 
  
  

