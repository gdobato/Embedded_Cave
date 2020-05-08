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
#define TASK_GREEN_LED  0U
#define TASK_RED_LED    1U

/* Task Cfg */
#define OS_TASK_CFG                                                                                 \
{                                                                                                   \
   /* Task Id          , Init Function   , Run Function  , Period, Offset */                        \
   {  TASK_GREEN_LED   ,  GreenLed_Init  , GreenLed_Run  , 500   , 0     },                         \
   {  TASK_RED_LED     ,  RedLed_Init    , RedLed_Run    , 500   , 500   },                         \
}


#endif