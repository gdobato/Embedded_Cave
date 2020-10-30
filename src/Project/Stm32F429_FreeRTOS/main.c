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
  /* Init BSP*/
  HAL_Init();
  Gpio_Init();
  Adc_Init();
  Dma_Init();
  Usart_Init();
  Spi_Init();
  I2c_Init();
  Timer_Init();
  Fmc_Init();
  
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

