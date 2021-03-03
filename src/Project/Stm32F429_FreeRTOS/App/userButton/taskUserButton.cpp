#include <FreeRTOS.h>
#include <queue.h>
#include <taskDebug.h>
#include "string.h"
#include <stdio.h>
#include <task.h>
#include <Cfg.h>
#include <memory>
#include <gpio.h>

extern "C" {

void vTaskButton(void* pvParameters)
{

  #if (DEBUG_TRACE  == STD_ON)
  xQueueHandle        xQueueDebug = xTaskDebug_GetQueue();
  xQueueDebugData     xQueueData;
  xQueueData.ucType  = DEBUG_QUEUE_PRINTMSG_TIMESTAMP;
  xQueueData.pucBuff = static_cast<char *>(pvPortMalloc(10));
  sprintf(xQueueData.pucBuff, "Task Button");
  #endif
  
  for(;;)
  {
    #if (DEBUG_TRACE  == STD_ON)
    if (pdTRUE == xQueueSend(xQueueDebug, &xQueueData, portMAX_DELAY)) {}
    #endif

    #if 0
    if (button->getState() == STD_ON)
    {
    }
    else
    {
    }
    #endif
    vTaskDelay(pdMS_TO_TICKS(200));
  }
}

}

