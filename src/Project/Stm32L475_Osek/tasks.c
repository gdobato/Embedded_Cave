#include <TCB.h>
#include <OsAPIs.h>
#include <portable/ARM/CM4F/Port.h>

//===============================================================================================================================
// OS TASK : T1
//===============================================================================================================================
TASK(T1)
{
  uint32 Cpt=0;
  OsEventMaskType OsWaitEventMask = EVT_BLINK_BLUE_LED;
  OsEventMaskType Events = 0;
  (void)OS_SetRelAlarm(ALARM_BLUE_LED,0,1000);

  for(;;)
  {
    Cpt++;
    if(E_OK == OS_WaitEvent(OsWaitEventMask))
    {	
      (void)OS_GetEvent((OsTaskType)T1, &Events);
      if((Events & EVT_BLINK_BLUE_LED) == EVT_BLINK_BLUE_LED)
      {
        OS_ClearEvent(EVT_BLINK_BLUE_LED);
        //LED_BLUE_TOGGLE();
      }
      if(Cpt == 10)
      {
        OS_CancelAlarm(ALARM_BLUE_LED);
        OS_ChainTask(T2);			
      }
    }
    else
    {
      OS_TerminateTask(); /* In case of error we switch off the task */
    }
  }
}

//===============================================================================================================================
// OS TASK : Idle
//===============================================================================================================================
TASK(Idle)
{
  OsEventMaskType OsWaitEventMask = EVT_BLINK_GREEN_LED;
  OsEventMaskType Events = 0;
  (void)OS_SetRelAlarm(ALARM_GREEN_LED,0,1000);

  for(;;)
  {
    if(E_OK == OS_WaitEvent(OsWaitEventMask))
    {	
      (void)OS_GetEvent((OsTaskType)Idle, &Events);
      if((Events & EVT_BLINK_GREEN_LED) == EVT_BLINK_GREEN_LED)
      {
        OS_ClearEvent(EVT_BLINK_GREEN_LED);
        //LED_GREEN_TOGGLE();
      }
    }
    else
    {
      OS_TerminateTask(); /* In case of error we switch off the task */
    }
  }
}

//===============================================================================================================================
// OS TASK : T2
//===============================================================================================================================
TASK(T2)
{
  OsEventMaskType OsWaitEventMask = EVT_BLINK_FASTER_BLUE_LED;
  OsEventMaskType Events = 0;
  (void)OS_SetRelAlarm(ALARM_FASTER_BLUE_LED,0,50);

  for(;;)
  {
    (void)OS_WaitEvent(OsWaitEventMask);
    (void)OS_GetEvent((OsTaskType)T2, &Events);
    if((Events & EVT_BLINK_FASTER_BLUE_LED) == EVT_BLINK_FASTER_BLUE_LED)
    {
      OS_ClearEvent(EVT_BLINK_FASTER_BLUE_LED);
      //LED_BLUE_TOGGLE();
    }	
  }
}

//===============================================================================================================================
// OS TASK : T3
//===============================================================================================================================
TASK(T3)
{
  OsEventMaskType OsWaitEventMask = EVT_BLINK_RED_LED;
  OsEventMaskType Events = 0;
  (void)OS_SetRelAlarm(ALARM_RED_LED,0,100);

  for(;;)
  {
    if(E_OK == OS_WaitEvent(OsWaitEventMask))
    {	
      (void)OS_GetEvent((OsTaskType)T3, &Events);
      if((Events & EVT_BLINK_RED_LED) == EVT_BLINK_RED_LED)
      {
        OS_ClearEvent(EVT_BLINK_RED_LED);
        //LED_RED_TOGGLE();
      }
    }
    else
    {
      OS_TerminateTask(); /* In case of error we switch off the task */
    }
  }
}

//===============================================================================================================================
// OS TASK : T4
//===============================================================================================================================
TASK(T4)
{
  OsEventMaskType OsWaitEventMask = EVT_BLINK_ORANGE_LED;
  OsEventMaskType Events = 0;
  (void)OS_SetRelAlarm(ALARM_ORANGE_LED,0,500);

  for(;;)
  {
    if(E_OK == OS_WaitEvent(OsWaitEventMask))
    {	
      (void)OS_GetEvent((OsTaskType)T4, &Events);
      if((Events & EVT_BLINK_ORANGE_LED) == EVT_BLINK_ORANGE_LED)
      {
        OS_ClearEvent(EVT_BLINK_ORANGE_LED);
        //LED_ORANGE_TOGGLE();
      }
    }
    else
    {
      OS_TerminateTask(); /* In case of error we switch off the task */
    }
  }
}
