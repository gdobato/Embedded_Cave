#include "led.h"
#include <debug.h>

#ifdef __cplusplus
extern "C" {
#endif

void vTaskLed(void* pvParameters)
{
  Led* redLed   = new Led(RED_LED);
  Led* greenLed = new Led(GREEN_LED);

  for(;;)
  {
    Debug_PrintMsgTime((char *)"Led Thread \n");

    redLed->toggle(500);
    greenLed->On();
  }
}

#ifdef __cplusplus
}
#endif

