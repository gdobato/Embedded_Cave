#include <task_debug.h>
#include <usart.h>
#include <task.h>
#include <usart.h>
#include <log.h>


bsp::usart::Usart usart1 {USART1, 115200};
util::log::Serial serial {usart1};

static xQueueHandle xQueueDebug = NULL;
void vTaskDebug(void* pvParamters)
{
  xQueueDebugData xQueueData;
  for(;;)
  {
    if(pdTRUE == xQueueReceive (xQueueDebug, &xQueueData, portMAX_DELAY))
    {
      switch(xQueueData.ucType)
      {
        case DEBUG_QUEUE_PRINTMSG_TIMESTAMP:
          serial.print_ts(xQueueData.pucBuff, "\n");
          break;
        case DEBUG_QUEUE_PRINTMSG:
        default:
          serial.print(xQueueData.pucBuff, "\n");
          break;

      }
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