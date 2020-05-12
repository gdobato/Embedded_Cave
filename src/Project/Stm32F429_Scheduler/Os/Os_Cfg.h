#ifndef __OS_CFG_H__
#define __OS_CFG_H__

#include "Os_Types.h"
#include "timer/timer.h"
#include "callouts.h"
#include "tasks.h"

/******************************************************************************************
  
                                  OS CONFIGURATION

*******************************************************************************************/
/***************
  OS Handler
****************/
#define OS_CFG                                                                                       \
{                                                                                                    \
    Timer_Start,         /*Function to handle task timeouts*/                                        \
    Timer_TimeOut,       /*Function to handle task timeouts*/                                        \
    Dummy_Idle,          /*Task which will be executed if none of the task is running .eg Watchdog*/ \
    Interrupts_Enable,   /*Function to Enable all interrupts*/                                       \
    Interrupts_Disable   /*Function to Disable all interrupts*/                                      \
}


/**************
  Tasks 
***************/
/* Task IDs*/
#define TASK_USER_BUTTON    0U
#define TASK_GREEN_LED      1U   
#define TASK_RED_LED        2U

/* Task Cfg */
#define OS_TASK_CFG                                                                                     \
{                                                                                                       \
/*     Task Id         , Init Function    , Run Function  , Alarm  , Alarm Period  , Alarm Offset */    \
   {  TASK_USER_BUTTON ,  UserButton_Init , UserButton_Run, true   , 1             , 0            },    \
   {  TASK_GREEN_LED   ,  GreenLed_Init   , GreenLed_Run  , true   , 100           , 0            },    \
   {  TASK_RED_LED     ,  RedLed_Init     , RedLed_Run    , false  , 0             , 0            },    \
}


#endif