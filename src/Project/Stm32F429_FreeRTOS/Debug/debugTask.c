#include <cmsis_os.h>
#include "debug.h"
#include "debugTask.h"


xQueueHandle xQueueDebug = NULL;
static char buff[1024];



void vTaskDebug(void* pvParamters)
{
  xQueueDebugData xQueueData;
  for(;;)
  {
    #if 1
    if(pdTRUE == xQueueReceive (xQueueDebug, &xQueueData, portMAX_DELAY))
    {
      switch(xQueueData.ucType)
      {
        case DEBUG_QUEUE_PRINTMSG_TIMESTAMP:
          Debug_PrintMsgTime("%s \n", xQueueData.pucBuff);
          break;
        case DEBUG_QUEUE_PRINTMSG:
        default:
          Debug_PrintMsg("%s \n", xQueueData.pucBuff);
          break;

      }
    }
    #else
    if(pdTRUE == xQueueReceive (xQueueDebug, &xQueueData.pucBuff,portMAX_DELAY))
    {
      Debug_PrintMsg("%s \n", xQueueData.pucBuff);
    }
    #endif
  }
}

xQueueHandle* DebugTask_GetQueue(void)
{
  return &xQueueDebug;
}