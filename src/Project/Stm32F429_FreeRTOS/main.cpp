/**
 * @file 
 * @author 
 * @date
 * @brief
 **/

/************************************
* Includes
************************************/
//Std
#include <string.h>

//Os objects
#include "FreeRTOS.h"
#include <userLed/taskUserLed.h>
#include <stats/taskStats.h>
#include <userButton/taskUserButton.h>

//Bsp
#include "stm32f4xx_hal.h"
#include <hal_base.h>
#include <hal.h>
#include <gpio.h>
#include <system/system.h>
#include <timer.h>
#include <usart/usart.h>

//Cfg
#include <Cfg.h>

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
static void Error_Handler(void);

/************************************
* Implementation 
************************************/
int main(void)
{
  /* Enable Counter of DWT Cell. ToDo:it needs to be encapsulated. Remove CMSIS dependencies*/
  #if (SYSTEMVIEW == STD_ON)
  System_EnableCycleCounter();
  #endif

  /* Init BSP*/
  bsp::hal::Init();
  bsp::timer::Init();
  Usart_Init();

  bsp::gpio::Init();

  /* ToDo: Implement own API. Remove CMSIS depenencies */
  /* Analyse why sysgroup bit is not 0 by default*/
  NVIC_SetPriorityGrouping( 0 ); 

  /* Start System recording*/
  #if (SYSTEMVIEW == STD_ON)
  SEGGER_SYSVIEW_Conf();
  SEGGER_SYSVIEW_Start();
  #endif

  /* Initialize Os objects */
  //Queues
  //vTaskDebug_CreateQueue(3U);

  //Tasks
  //xTaskCreate(vTaskStats  , "Stats"     , 1024, NULL, 2, NULL );
  xTaskCreate(vTaskLed    , "UserLed"   , 256 , NULL, 1, NULL );
  xTaskCreate(vTaskButton , "UserButton", 256 , NULL, 1, NULL );

  /*Start Os*/
  vTaskStartScheduler();

  
  while (1)
  {
    Error_Handler();
  }

  return 0;
}

void Error_Handler(void)
{

}

