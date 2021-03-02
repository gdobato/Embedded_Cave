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
#include <usart/usart.h> 
#include <user_led/task_user_led.h> 
#include <task_debug.h> 
#include <stats/task_stats.h> 
#include <ble/ble_server_task.h>
#include <ble/ble_server_legacy.h>
#include <timer/timer.h>
}
#include <Cfg.h>
#include <cstdlib>
#include <gpio.h> 
#include <user_button.h>
#include <hal_base.h>
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

  //Init Bsp
  bsp::hal::Init();
  bsp::gpio::Init();
  Timer_Init();

  /* ToDo: Implement own API. Remove CMSIS depenencies */
  /* Analyse why sysgroup bit is not 0 by default*/
  NVIC_SetPriorityGrouping( 0 );


  Usart_Init();


  Ble_server_init();


   /* Start System recording*/
  #if (SYSTEMVIEW == STD_ON)
  SEGGER_SYSVIEW_Conf();
  SEGGER_SYSVIEW_Start();
  #endif

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



