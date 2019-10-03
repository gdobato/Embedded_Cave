// *****************************************************************************************************************
// Filename    : OsCfg.h
// 
// Author      : Chalandi Amine
//
// Owner       : Chalandi Amine
// 
// Date        : 27.12.2017
// 
// Description : OSEK based application config
// 
// *****************************************************************************************************************

#include "OsGenMac.h"


//=============================================================================
//  OS Configuration
//=============================================================================

OS_CONFIG_BEGIN
  
  OS_TASK_BEGIN
    OS_TASK_DEF(Idle ,0 ,1024 ,1 ,OS_AUTOSTART    ,EXTENDED ,FULL_PREEMPT)
    OS_TASK_DEF(T1   ,5 ,1024 ,1 ,OS_AUTOSTART    ,EXTENDED ,FULL_PREEMPT)
    OS_TASK_DEF(T2   ,6 ,1024 ,1 ,OS_NO_AUTOSTART ,EXTENDED ,FULL_PREEMPT)
    OS_TASK_DEF(T3   ,8 ,1024 ,1 ,OS_NO_AUTOSTART ,EXTENDED ,FULL_PREEMPT)
    OS_TASK_DEF(T4   ,9 ,1024 ,1 ,OS_NO_AUTOSTART ,EXTENDED ,FULL_PREEMPT)
  OS_TASK_END

  OS_EVENT_BEGIN
   OS_EVENT_DEF(EVT_BLINK_BLUE_LED        , (1UL<<0))
   OS_EVENT_DEF(EVT_BLINK_GREEN_LED       , (1UL<<1))
   OS_EVENT_DEF(EVT_BLINK_FASTER_BLUE_LED , (1UL<<2))
   OS_EVENT_DEF(EVT_MSG_QUEUED            , (1UL<<3))
   OS_EVENT_DEF(EVT_BLINK_RED_LED         , (1UL<<4))
   OS_EVENT_DEF(EVT_BLINK_ORANGE_LED      , (1UL<<5))
  OS_EVENT_END
  
  OS_ALARM_BEGIN        
    OS_ALARM_DEF(ALARM_BLUE_LED        ,ALARM_SET_EVENT   ,EVT_BLINK_BLUE_LED        ,T1   ,0) 
    OS_ALARM_DEF(ALARM_GREEN_LED       ,ALARM_SET_EVENT   ,EVT_BLINK_GREEN_LED       ,Idle ,0) 
    OS_ALARM_DEF(ALARM_FASTER_BLUE_LED ,ALARM_SET_EVENT   ,EVT_BLINK_FASTER_BLUE_LED ,T2   ,0)
    OS_ALARM_DEF(ALARM_RED_LED         ,ALARM_SET_EVENT   ,EVT_BLINK_RED_LED         ,T3   ,0) 
    OS_ALARM_DEF(ALARM_ORANGE_LED      ,ALARM_SET_EVENT   ,EVT_BLINK_ORANGE_LED      ,T4   ,0) 
    OS_ALARM_AUTO_DEF(ALARM_RUN_T3 ,5000 ,0 ,ALARM_ACTIVE_TASK ,0 ,T3 ,0)
    OS_ALARM_AUTO_DEF(ALARM_RUN_T4 ,20000 ,0 ,ALARM_ACTIVE_TASK ,0 ,T4 ,0)
  OS_ALARM_END          
  
  OS_RESOURCE_BEGIN        
    OS_RESOURCE_DEF(RES_SCHEDULER ,RES_SCHEDULER_PRIO , {1,1,1,1})
    OS_RESOURCE_DEF(RES_MSG       ,10                 , {1,1,1,1})
    OS_RESOURCE_DEF(RES_R2        ,0                  , {0,0,0,0})   
  OS_RESOURCE_END

  OS_INTERRUPT_BEGIN
    OS_INTERRUPT_CAT2_DEF(15,SysTickTimer)
  OS_INTERRUPT_END  

OS_CONFIG_END
  





