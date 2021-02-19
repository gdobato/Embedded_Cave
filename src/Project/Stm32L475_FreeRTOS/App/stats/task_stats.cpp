#include <FreeRTOS.h>
#include <task.h>
#include <stats/task_stats.h>
#include <task_debug.h>
#include <stdio.h>
#include <Cfg.h>

extern "C"
{
void vTaskStats(void* pvParameters)
{
  xQueueHandle    xQueueDebug = xTaskDebug_GetQueue();
  xQueueDebugData xQueueData;
  xQueueData.pucBuff = static_cast<char *>(pvPortMalloc(STATS_BUFFER_SIZE));
  for(;;)
  {
    #if (DEBUG_TRACE  == STD_ON)
    xQueueData.ucType = DEBUG_QUEUE_PRINTMSG_TIMESTAMP;
    sprintf(xQueueData.pucBuff, "Task Stats");
    if (pdTRUE == xQueueSend(xQueueDebug, &xQueueData, portMAX_DELAY)) {}
    #endif

    xQueueData.ucType  = DEBUG_QUEUE_PRINTMSG;
    vTaskGetRunTimeStats(xQueueData.pucBuff); 
    if (pdTRUE == xQueueSend(xQueueDebug, &xQueueData, portMAX_DELAY)) {}

    vTaskDelay(pdMS_TO_TICKS(1000));
  }
}
}  
