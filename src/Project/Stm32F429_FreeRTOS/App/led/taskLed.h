#ifndef __TASK_LED_H__
  #define __TASK_LED_H__

#include <cmsis_os.h>

#ifdef __cplusplus
extern "C" {
#endif

void vTaskLed(void * pvParameters);

#ifdef __cplusplus
}
#endif

#endif