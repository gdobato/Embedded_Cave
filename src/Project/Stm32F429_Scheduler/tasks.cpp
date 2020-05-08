
#include <Os.h>
#include <led/led.h> 


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
    Os_SetEvent(TASK_RED_LED, OS_EVENT(0)); 
  }

  ucIdx++;

}

 void RedLed_Run (void)
 {
  static uint8_t ucIdx;
  static bool boDead = false;

  if (Os_GetEvent(TASK_RED_LED, OS_EVENT(0))== true)
  {
     Os_ClearEvent(TASK_RED_LED, OS_EVENT(0));
     boDead = true;
  }
  if (boDead != true)  
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
  else
  {
    redLed->Off();
  }
  

ucIdx++;

}

