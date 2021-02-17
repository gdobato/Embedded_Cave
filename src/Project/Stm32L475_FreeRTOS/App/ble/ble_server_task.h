#ifndef __TASK_BLESERVER_H__
  #define __TASK_BLESERVER_H__

#include <cmsis_os.h>

#ifdef __cplusplus
extern "C" {
#endif

void vTaskBleServer(void * pvParameters);

#ifdef __cplusplus
}
#endif

#endif