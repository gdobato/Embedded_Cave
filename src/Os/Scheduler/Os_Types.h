#ifndef __OS_TYPES_H__
#define __OS_TYPES_H__

#include <stdint.h>
#include <stdbool.h>


typedef void    (*tfpTaskInit)               (void*);
typedef void    (*tfpTaskRun)                (void*);
typedef uint32_t(*tfpTimerStart)             (uint32_t);
typedef bool    (*tfpTimerTimeOut)           (uint32_t ulTimeOut);
typedef void    (*tfpInterruptsSwitch)       (void);

typedef struct tsOsHandler
{
  tfpTimerStart        fpTimerStart;
  tfpTimerTimeOut      fpTimerTimeOut;
  tfpTaskRun           fpIdle;
  tfpInterruptsSwitch  fpInterruptsEnable;
  tfpInterruptsSwitch  fpInterruptsDisable;
}tsOsHandler;

typedef struct tsOsTaskCfg
{
  uint16_t      unTaskId; 
  tfpTaskInit   fpInit;
  tfpTaskRun    fpRun;
  bool          boAlarm;
  int32_t       ulRunPeriod;
  int32_t       ulRunOffset;
}tsOsTaskCfg;

typedef struct tsOsTaskTCB
{
  uint32_t       ulEvent;
  uint32_t       ulAlarm;
}tsOsTaskTCB;


#endif