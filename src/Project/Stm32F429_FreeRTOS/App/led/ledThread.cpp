#include "led.h"
#include "ledThread.h"
#include <debug.h>


void ledHandler(void const * argument)
{
  Led* redLed   = new Led(RED_LED);
  Led* greenLed = new Led(GREEN_LED);

  for(;;)
  {
    Debug_PrintMsgTime((char *)"Led Thread \n");

    redLed->toggle(500);
    Debug_PrintMsgTime((char *)"  Red  :%d \n", redLed->getState());

    greenLed->On();
    Debug_PrintMsgTime((char *)"  Green:%d \n", greenLed->getState());
  }
}
