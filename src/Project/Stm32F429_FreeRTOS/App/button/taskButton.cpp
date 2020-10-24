#include <button/button.h>
#include <FreeRTOS.h>
#include <queue.h>
#include <taskDebug.h>
#include "string.h"
#include <stdio.h>
#include <task.h>
#include <Cfg.h>

#ifdef __cplusplus
extern "C" {
#endif

void vTaskButton(void* pvParameters)
{
  Button* button = new Button();
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

    if (button->getState() == STD_ON)
    {
    }
    else
    {
    }
    vTaskDelay(pdMS_TO_TICKS(200));
  }
}

#ifdef __cplusplus
}
#endif

