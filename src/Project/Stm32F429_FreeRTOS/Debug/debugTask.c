#include <cmsis_os.h>
#include "debug.h"
#include "debugTask.h"


extern xQueueHandle xQueueDebug ;
xQueueHandle xQueueDebug = NULL;
static char buff[1024];
void vTaskDebug(void* pvParamters)
{
  for(;;)
  {
    if(pdTRUE == xQueueReceive (xQueueDebug, buff, 0))
    {
      Debug_PrintMsg("%s \n", buff);
    }
    vTaskDelay(pdMS_TO_TICKS(5000));
  }
}

xQueueHandle* DebugTask_GetQueue(void)
{
  return &xQueueDebug;
}