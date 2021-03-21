#include <cmsis_os.h>
#include "debug.h"
#include "task_debug.h"
#include <usart.h>
#include <task.h>
#include <string>
#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>
#include <array>

static xQueueHandle xQueueDebug = NULL;
;

void vTaskDebug(void* pvParamters)
{
  xQueueDebugData xQueueData;
  Debug_Init();
  for(;;)
  {
    if(pdTRUE == xQueueReceive (xQueueDebug, &xQueueData, portMAX_DELAY))
    {
      #if 1
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
      #else
      //Debug_PrintMsg3( "test1", "test2");
      #endif
    }
  }
}

xQueueHandle  xTaskDebug_GetQueue(void)
{
  return xQueueDebug;
}

void vTaskDebug_CreateQueue(uint8_t ucLength)
{
  xQueueDebug = xQueueCreate(ucLength ,sizeof(xQueueDebugData));
}