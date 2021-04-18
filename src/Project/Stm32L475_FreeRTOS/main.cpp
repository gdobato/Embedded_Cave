/**
 * @file 
 * @author 
 * @date
 * @brief
 **/
/************************************
* Includes
************************************/
extern "C"
{
  #include <system/system.h> 
  #include <user_led/task_user_led.h> 
  #include <task_debug.h> 
  #include <stats/task_stats.h> 
  #include <ble/ble_server_task.h>
  #include <ble/ble_server_legacy.h>
}

#include <Cfg.h>
#include <cstdlib>
#include <gpio.h> 
#include <user_button.h>
#include <hal_base.h>
#include <timer.h>
#include <fault_profile.h>
/************************************
* Private definitions 
************************************/

/************************************
* Private type definitions 
************************************/

/************************************
* Private variables
************************************/

/************************************
* Private declarations 
************************************/
int main(void)
{
  #if (SYSTEMVIEW == STD_ON)
  System_EnableCycleCounter();
  #endif

  #if (FAULT_PROFILE == STD_ON)
  util::fault_profile::fault_disable_write_buffering();
  util::fault_profile::fault_enable_usg_fault();
  util::fault_profile::fault_enable_bus_fault();
  util::fault_profile::fault_enable_mem_fault();
  #endif

  #if 0 
  util::fault_profile::fault_inject_bus_fault();
  #endif

  //Init Bsp
  bsp::hal  ::Init();
  bsp::gpio ::Init();
  bsp::timer::Init();

  /* ToDo: Implement own API. Remove CMSIS depenencies */
  /* Analyse why sysgroup bit is not 0 by default*/
  NVIC_SetPriorityGrouping( 0 );

   /* Start System recording*/
  #if (SYSTEMVIEW == STD_ON)
  SEGGER_SYSVIEW_Conf();
  SEGGER_SYSVIEW_Start();
  #endif

  //ToDo: Deprecated
  Ble_server_init();


  vTaskDebug_CreateQueue(3U);
  
  /* definition and creation of Led thread */
  xTaskCreate(vTaskLed         , "UserLed"   , 256  , NULL, 2, NULL );
  xTaskCreate(vTaskBleServer   , "bleserver" , 1024 , NULL, 2, NULL );
  xTaskCreate(vTaskStats       , "Stats"     , 1024 , NULL, 1, NULL );
  #if (DEBUG_TRACE == STD_ON)
  xTaskCreate(vTaskDebug       , "Debug"     , 1024 , NULL, 1, NULL );
  #endif

  vTaskStartScheduler();


  while (1)
  {

  }

  return 0;
}



