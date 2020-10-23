#include "led.h"
#include <FreeRTOS.h>
#include <queue.h>
#include <debugTask.h>
#include "string.h"
#include "stdio.h"
#include <task.h>
#include <hal/hal.h>


#ifdef __cplusplus
extern "C" {
#endif

void vTaskLed(void* pvParameters)
{
  Led* redLed   = new Led(RED_LED);
  Led* greenLed = new Led(GREEN_LED);

  xQueueHandle*       xQueueDebug = DebugTask_GetQueue();
  xQueueDebugData     xQueueData;
  xQueueData.ucType  = DEBUG_QUEUE_PRINTMSG_TIMESTAMP;
  xQueueData.pucBuff = (char*)pvPortMalloc(10);
  sprintf(xQueueData.pucBuff, "Led Task");

  redLed->toggle();
  for(;;)
  {
    if (pdTRUE == xQueueSend(*xQueueDebug, &xQueueData, portMAX_DELAY)) {}
    redLed->toggle();
    greenLed->toggle();
    vTaskDelay(pdMS_TO_TICKS(100));
  }
}

#ifdef __cplusplus
}
#endif

