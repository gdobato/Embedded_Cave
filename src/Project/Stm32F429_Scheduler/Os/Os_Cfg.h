#ifndef __OS_CFG_H__
#define __OS_CFG_H__

#include "Os_Types.h"
#include "timer/timer.h"

#define TASK_1         0U
#define TASK_2         1U
#define TASK_COUNT     2U


#ifdef __cplusplus
extern "C" {
#endif


void Dummy_Init          (void) {}
void Task1(void);
void Task2(void);
void Dummy_Idle          (void) {}
void Interrupts_Enable   (void) { __asm("cpsie i");}
void Interrupts_Disable  (void) { __asm("cpsid i");}

#ifdef __cplusplus
}
#endif

tsOsHandler Os_Handler =
{
  .fpTimerStart        = Timer_Start, 
  .fpTimerTimeOut      = Timer_TimeOut, 
  .fpIdle              = Dummy_Idle,
  .fpInterruptsEnable  = Interrupts_Enable,
  .fpInterruptsDisable = Interrupts_Disable,
};


tsOsTaskCfg Os_TaskCfg[TASK_COUNT] =
{
  {
   .unTaskId      = TASK_1, 
   .fpInit        = Dummy_Init, 
   .fpRun         = Task1, 
   .ulRunPeriod   = 500U,
   .ulRunOffset   = 20U,
  },
  {
   .unTaskId      = TASK_2, 
   .fpInit        = Dummy_Init, 
   .fpRun         = Task2, 
   .ulRunPeriod   = 5000U,
   .ulRunOffset   = 20U,
  }

};


#endif