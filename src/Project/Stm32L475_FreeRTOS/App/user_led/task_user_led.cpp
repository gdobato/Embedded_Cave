#include <user_led.h>
#include <FreeRTOS.h>
#include <queue.h>
#include <task_debug.h>
#include "string.h"
#include <stdio.h>
#include <task.h>
#include <hal/hal.h>
#include <memory>
#include <gpio.h>
#include <Cfg.h>

extern "C" {

void vTaskLed(void* pvParameters)
{

  app::user_led::User_led<GPIOB_BASE, LED2_Pin> green_led;

  #if (DEBUG_TRACE  == STD_ON)
  xQueueHandle        xQueueDebug = xTaskDebug_GetQueue();
  xQueueDebugData     xQueueData;
  xQueueData.ucType  = DEBUG_QUEUE_PRINTMSG_TIMESTAMP;
  xQueueData.pucBuff = static_cast<char *>(pvPortMalloc(10));
  sprintf(xQueueData.pucBuff, "Task Led");
  #endif


  for(;;)
  {
    #if (DEBUG_TRACE  == STD_ON)
    if (pdTRUE == xQueueSend(xQueueDebug, &xQueueData, portMAX_DELAY)) {}
    #endif

    green_led.toggle();

    vTaskDelay(pdMS_TO_TICKS(250));
  }
}

}

