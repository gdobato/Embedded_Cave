#include <ble_server.h>
#include <FreeRTOS.h>
#include <queue.h>
#include <task_debug.h>
#include "string.h"
#include <stdio.h>
#include <task.h>
#include <hal/hal.h>
#include <memory>
#include <gpio/gpio.h>
#include <Cfg.h>

extern "C" 
{
void vTaskBleServer(void* pvParameters)
{

  for(;;)
  {
    Ble_server_process();
    vTaskDelay(pdMS_TO_TICKS(250));
  }
}

}

