#ifndef __STATS_TRHEAD_H__
#define __STATS_THREAD_H__

#include <cmsis_os.h>

#ifdef __cplusplus
extern "C" {
#endif

void vTaskStats(void* pvParameters);

#ifdef __cplusplus
}
#endif

#endif