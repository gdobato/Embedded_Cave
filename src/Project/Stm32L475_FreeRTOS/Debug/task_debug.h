#ifndef __TASK_DEBUG_H__
#define __TASK_DEBUG_H__

#include "FreeRTOS.h"
#include "queue.h"

#define  DEBUG_QUEUE_PRINTMSG            0U
#define  DEBUG_QUEUE_PRINTMSG_TIMESTAMP  1U
typedef struct xQueueDebugData
{
  uint8_t  ucType;
  char*    pucBuff;
}xQueueDebugData;



#ifdef __cplusplus
extern "C" {
#endif

void          vTaskDebug(void* pvParameters);
xQueueHandle  xTaskDebug_GetQueue(void);
void          vTaskDebug_CreateQueue(uint8_t ucLength);    

#ifdef __cplusplus
}
#endif
#endif