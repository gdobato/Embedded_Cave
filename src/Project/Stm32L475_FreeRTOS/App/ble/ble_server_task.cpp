#include <ble_server_legacy.h>
#include <ble_server.h>
#include <FreeRTOS.h>
#include <queue.h>
#include <task_debug.h>
#include "string.h"
#include <stdio.h>
#include <cstdint>
#include <task.h>
#include <hal/hal.h>
#include <gpio.h>
#include <Cfg.h>

extern "C" 
{

void vTaskBleServer(void* pvParameters)
{

  for(;;)
  {
    Ble_server_process();
    vTaskDelay(pdMS_TO_TICKS(UINT16_C(500)));
  }
}

} //extern C
