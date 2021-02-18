#include "ble_server.h"
#include <FreeRTOS.h>
#include <queue.h>
#include <taskDebug.h>
#include "string.h"
#include <stdio.h>
#include <task.h>
#include <hal/hal.h>
#include <memory>
#include <gpio/gpio.h>
#include <Cfg.h>

#ifdef __cplusplus
extern "C" {
#endif

void vTaskBleServer(void* pvParameters)
{

  for(;;)
  {
    Ble_server_process();
    vTaskDelay(pdMS_TO_TICKS(250));
  }
}

#ifdef __cplusplus
}
#endif

