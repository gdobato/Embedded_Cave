#include <debug.h>
#include <FreeRTOS.h>
#include <task.h>
#include "statsTask.h"
#include <debugTask.h>

void vTaskStats(void* pvParameters)
{
  xQueueHandle* xQueueDebug = DebugTask_GetQueue();
  xQueueDebugData xQueueData;
  xQueueData.ucType  = DEBUG_QUEUE_PRINTMSG;
  xQueueData.pucBuff = pvPortMalloc(STATS_BUFFER_SIZE);
  for(;;)
  {
    vTaskGetRunTimeStats(xQueueData.pucBuff); 
    if (pdTRUE == xQueueSend(*xQueueDebug, &xQueueData, portMAX_DELAY))
    {
    }
    vTaskDelay(pdMS_TO_TICKS(5000));
  }
}
