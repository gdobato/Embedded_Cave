#include "led.h"
#include "ledThread.h"
#include <debug.h>


void ledHandler(void const * argument)
{
  Led* greenLed = new Led(GREEN_LED);

  for(;;)
  {
    Debug_PrintMsgTime((char *)"Led Thread \n");

    greenLed->toggle(100);
    Debug_PrintMsgTime((char *)"  Green:%d \n", greenLed->getState());
  }
}
