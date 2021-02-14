#ifndef __TASK_STATS_H__
#define __TASK_STATS_H__

#define STATS_BUFFER_SIZE  512
#ifdef __cplusplus
extern "C" {
#endif

void vTaskStats(void* pvParameters);

#ifdef __cplusplus
}
#endif

#endif