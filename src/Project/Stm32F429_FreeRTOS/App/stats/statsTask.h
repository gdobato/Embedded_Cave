#ifndef __STATS_TRHEAD_H__
#define __STATS_THREAD_H__

#include <cmsis_os.h>
#define STATS_BUFFER_SIZE  512

void vTaskStats(void* pvParameters);


#endif