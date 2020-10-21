#include <debug.h>
#include <FreeRTOS.h>
#include <task.h>
#include "cmsis_os.h"

#ifdef __cplusplus
extern "C" {
#endif

static char stats[1024];

void vTaskStats(void* pvParameters)
{
  xQueueHandle* xQueueDebug = DebugTask_GetQueue();
  for(;;)
  {
    vTaskGetRunTimeStats(stats); 
    if (pdTRUE == xQueueSend(*xQueueDebug, stats, 0))
    {
      vTaskDelay(pdMS_TO_TICKS(5000));
    }
  }
}

#ifdef __cplusplus
}
#endif