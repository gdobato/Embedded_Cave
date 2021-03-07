#include <cmsis_os.h>
#include "debug.h"
#include "task_debug.h"
#include <usart.h>
#include <task.h>
#include <string>
#include <stdio.h>

static xQueueHandle xQueueDebug = NULL;
bsp::usart::Usart usart1 {USART1, 115200};

std::string aux;
template<typename T>
void Debug_PrintMsgTime2(T t1)
{
  aux.append(t1);
  /*
  std::string aux(t1);
  usart1.transmit(reinterpret_cast<const uint8_t*>(&aux[0]), aux.length());
  vTaskDelay(pdMS_TO_TICKS(500));
  */
   
}

template<typename T, typename...Ts>
void Debug_PrintMsgTime2(T t1, Ts... ts)
{
  //std::string aux(t1);
  Debug_PrintMsgTime2(ts...);
  usart1.transmit(reinterpret_cast<const uint8_t*>(&aux[0]), aux.length());
   
}

char buffer[256];
template<typename T>
void Debug_PrintMsg3(T t1)
{
  std::snprintf(buffer, 256, t1);
  usart1.transmit(reinterpret_cast<const uint8_t*>(&buffer[0]), strlen((const char *)buffer));
}
template<typename T , typename...Ts>
//void Debug_PrintMsg3(const char * format, Ts... ts)
void Debug_PrintMsg3(T t1, Ts... ts)
{
  Debug_PrintMsg3(t1);
  Debug_PrintMsg3(ts...);
}

void vTaskDebug(void* pvParamters)
{
  xQueueDebugData xQueueData;
  Debug_Init();
  usart1.init();
  for(;;)
  {
    if(pdTRUE == xQueueReceive (xQueueDebug, &xQueueData, portMAX_DELAY))
    {
      #if 0
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
      Debug_PrintMsg3("test1", "test2 \n");
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