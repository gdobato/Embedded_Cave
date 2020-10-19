#include <debug.h>
#include <FreeRTOS.h>
#include <task.h>
#include "cmsis_os.h"

#ifdef __cplusplus
extern "C" {
#endif
static char stats[1024];
void statsHandler(void const * argument)
{
  for(;;)
  {
    vTaskGetRunTimeStats(stats); 
    Debug_PrintMsg("================== Run Time Measurement ==================================\n");
    Debug_PrintMsg((char *)"%s \n", stats);
    Debug_PrintMsg("==========================================================================\n");
    osDelay(5000);
  }
}

#ifdef __cplusplus
}
#endif