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
#include <taskDebug.h>
#include <led/taskLed.h>
#include <stats/taskStats.h>
#include <button/taskButton.h>

//Bsp
#include "stm32f4xx_hal.h"
#include <hal/hal.h>
#include <adc/adc.h>
#include <dma/dma.h>
#include <fmc/fmc.h>
#include <gpio/gpio.h>
#include <i2c/i2c.h>
#include <ltdc/ltdc.h>
#include <spi/spi.h>
#include <system/system.h>
#include <timer/timer.h>
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
  HAL_Init();
  Gpio_Init();
  Usart_Init();
  Timer_Init();

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
  vTaskDebug_CreateQueue(3U);

  //Tasks
  xTaskCreate(vTaskStats  , "Stats"  , 1024, NULL, 2, NULL );
  xTaskCreate(vTaskDebug  , "Debug"  , 1024, NULL, 2, NULL );
  xTaskCreate(vTaskLed    , "Led"    , 256 , NULL, 1, NULL );
  xTaskCreate(vTaskButton , "Button" , 256 , NULL, 1, NULL );

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

