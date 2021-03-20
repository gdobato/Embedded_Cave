#include <cmsis_os.h>
#include "debug.h"
#include "task_debug.h"
#include <usart.h>
#include <task.h>
#include <string>
#include <stdio.h>

static xQueueHandle xQueueDebug = NULL;
bsp::usart::Usart usart1 {USART1, 115200};


/*
#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>
using namespace std;

int main()
{
    stringstream ss;
    for (int i = 0; i < 20; i++) {
        ss << setw(3) << i;
    }
    cout << "Resulting string: " << endl;
    cout << ss.str() << endl;
    printf("Resulting char*: \n%s\n", ss.str().c_str() );
    return 0;
}
*/

#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>

template<typename T>
void Debug_PrintMsg3(T t1)
{
  auto s = std::to_string(t1);
  usart1.transmit(reinterpret_cast<const uint8_t*>(s.c_str()), s.length() );
}

template<>
void Debug_PrintMsg3(const char* data)
{
  usart1.transmit(reinterpret_cast<const uint8_t*>(data), strlen(data) );
}

template<typename T , typename...Ts>
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
      Debug_PrintMsg3( "test", 1, 2, "\n");
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