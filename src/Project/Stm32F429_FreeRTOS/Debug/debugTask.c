#include <cmsis_os.h>
#include "debug.h"
#include "debugTask.h"

/**
* @brief Function implementing the debugTerminal thread.
* @param argument: Not used
* @retval None
*/

void vTaskDebug(void* pvParamters)
{
  for(;;)
  {
    Debug_PrintMsgTime("Debug Thread \n");
    osDelay(5000);
  }
}