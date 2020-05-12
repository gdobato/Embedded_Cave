/************************************
* Includes
************************************/
#include <stdint.h>
#include <stdbool.h>
#include "Os.h"
#include "Os_Types.h"
#include "Os_Cfg.h"

/************************************
* Private definitions 
************************************/

/************************************
* Private variables
************************************/
static tsOsHandler Os_Handler   = OS_CFG;
static tsOsTaskCfg Os_TaskCfg[] = OS_TASK_CFG;
static tsOsTaskTCB Os_TaskTCB[sizeof(Os_TaskCfg)/sizeof(tsOsTaskCfg)];

/************************************
* Private declarations 
************************************/

/************************************
* Implementation 
************************************/
void Os_Start(void)
{
  //Init Procedure
  for (uint16_t unTaskIdx = 0; unTaskIdx < sizeof(Os_TaskCfg)/sizeof(tsOsTaskCfg); unTaskIdx++)
  {
    //Initialize Timer to offset
    if (Os_Handler.fpTimerStart(Os_TaskCfg[unTaskIdx].boAlarm) != false)
    {
      Os_TaskTCB[unTaskIdx].ulTimer = Os_Handler.fpTimerStart(Os_TaskCfg[unTaskIdx].ulRunOffset);
    }

    //Call init functions onces
    Os_TaskCfg[unTaskIdx].fpInit();
  }
   
  //Never Return loop
  for (;;)
  {

    bool boTaskWakeUp = false;

    for (uint16_t unTaskIdx = 0; unTaskIdx < sizeof(Os_TaskCfg)/sizeof(tsOsTaskCfg); unTaskIdx++)
    {

      //Check Task Even has been set
      if (Os_TaskTCB[unTaskIdx].ulEvent != 0U ) 
      {
        boTaskWakeUp = true;
      }

      //Check Task timeout has been elapsed
      if (Os_TaskCfg[unTaskIdx].boAlarm != false)
      {
        if (Os_Handler.fpTimerTimeOut(Os_TaskTCB[unTaskIdx].ulTimer) == true)
        {
          Os_TaskTCB[unTaskIdx].ulTimer = Os_Handler.fpTimerStart(Os_TaskCfg[unTaskIdx].ulRunPeriod);
          boTaskWakeUp = true;
        }
      }

      if (boTaskWakeUp == true)
      {
         Os_TaskCfg[unTaskIdx].fpRun();
         break;
      }
    }

    //If no task is waken up, call Idle function
    if (boTaskWakeUp != true)
    {
      Os_Handler.fpIdle();

    }
    
  }

}

void Os_SetEvent(uint16_t unTaskId, uint32_t ulEvent)
{
  Os_Handler.fpInterruptsDisable();
  Os_TaskTCB[unTaskId].ulEvent |=  ulEvent ;
  Os_Handler.fpInterruptsEnable();
}

void Os_ClearEvent(uint16_t unTaskId, uint32_t ulEvent)
{
  Os_Handler.fpInterruptsDisable();
  Os_TaskTCB[unTaskId].ulEvent &=  ~ulEvent ;
  Os_Handler.fpInterruptsEnable();
}

bool Os_GetEvent(uint16_t unTaskId, uint32_t ulEvent)
{
  bool boRetVal;

  Os_Handler.fpInterruptsDisable();
  boRetVal =  ((Os_TaskTCB[unTaskId].ulEvent &  ulEvent) != 0U) ? true : false;
  Os_Handler.fpInterruptsEnable();

  return boRetVal;
}