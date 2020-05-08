#ifndef __OS_TYPES_H__
#define __OS_TYPES_H__

#include <stdint.h>
#include <stdbool.h>

typedef enum teOsTaskState
{
  Os_eState_Wait = 0,
  Os_eState_Ready,
  Os_eState_Run,
}tsOsTaskState;


typedef void    (*tfpTask)                   (void);
typedef uint32_t(*tfpTimerStart)             (uint32_t);
typedef bool    (*tfpTimerTimeOut)           (uint32_t ulTimeOut);
typedef void    (*tfpInterruptsSwitch)       (void);

typedef struct tsOsHandler
{
  tfpTimerStart        fpTimerStart;
  tfpTimerTimeOut      fpTimerTimeOut;
  tfpTask              fpIdle;
  tfpInterruptsSwitch  fpInterruptsEnable;
  tfpInterruptsSwitch  fpInterruptsDisable;
}tsOsHandler;

typedef struct tsOsTaskCfg
{
  uint16_t      unTaskId; 
  tfpTask       fpInit;
  tfpTask       fpRun;
  int32_t       ulRunPeriod;
  int32_t       ulRunOffset;
}tsOsTaskCfg;

typedef struct tsOsTaskTCB
{
  tsOsTaskState  eState;
  uint8_t        ulEvent;
  uint32_t       ulTimer;
  uint32_t       ulTimeOut;
}tsOsTaskTCB;


#endif