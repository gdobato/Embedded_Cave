#include <cmsis_os.h>
#include "debug.h"

/**
* @brief Function implementing the debugTerminal thread.
* @param argument: Not used
* @retval None
*/

void DebugHandler(void const * argument)
{
  for(;;)
  {
    Debug_PrintMsgTime("Debug Thread \n");
    osDelay(5000);
  }
}