#ifndef __DEBUG_TASK_H__
#define __DEBUG_TASK_H__

#include "FreeRTOS.h"
#include "queue.h"

void          vTaskDebug        (void* pvParameters);
xQueueHandle* DebugTask_GetQueue(void);

#endif