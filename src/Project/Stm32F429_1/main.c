/**
 * @file 
 * @author 
 * @date
 * @brief
 **/

/************************************
* Includes
************************************/
#include "cmsis_os.h"

#include <debugThread.h>
#include <debug.h>

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

#include <led/ledThread.h>

#include <string.h>
#include "stm32f4xx_hal.h"

/************************************
* Private definitions 
************************************/
#define I2C_ADDRESS        0x3E

/************************************
* Private type definitions 
************************************/

/************************************
* Private variables
************************************/
static osThreadId DebugThread;
static osThreadId SpiThread;
static osThreadId I2cThread;
static osThreadId AdcThread;
static osThreadId ledThread;

/************************************
* Private declarations 
************************************/
static void SpiHandler(void const * argument);
static void I2cHandler(void const * argument);
static void AdcHandler(void const * argument);
static void Error_Handler(void);

/************************************
* Implementation 
************************************/

/**
  * @brief  main
  * @param  argument: Not used 
  * @retval int
  */
int main(void)
{
  HAL_Init();
  Gpio_Init();
  Adc_Init();
  Dma_Init();
  Usart_Init();
  Spi_Init();
  I2c_Init();
  Timer_Init();
  Fmc_Init();

  /* Create the thread(s) */

  /* definition and creation of debugTerminal */
  osThreadDef(Debug, DebugHandler, osPriorityNormal, 0, 512);
  DebugThread = osThreadCreate(osThread(Debug), NULL);

  /* definition and creation of SPI thread */
  osThreadDef(Spi, SpiHandler, osPriorityNormal, 0, 512);
  SpiThread = osThreadCreate(osThread(Spi), NULL);

 /* definition and creation of I2c thread */
  osThreadDef(I2c, I2cHandler, osPriorityNormal, 0, 512);
  I2cThread = osThreadCreate(osThread(I2c), NULL);

 /* definition and creation of Adc thread */
  osThreadDef(Adc, AdcHandler, osPriorityNormal, 0, 512);
  AdcThread = osThreadCreate(osThread(Adc), NULL);

 /* definition and creation of Led thread */
  osThreadDef(Led, ledHandler, osPriorityNormal, 0, 512);
  ledThread = osThreadCreate(osThread(Led), NULL);

  /* Start scheduler */
  osKernelStart();
  
  while (1)
  {
    Error_Handler();
  }

  return 0;
}

/**
* @brief Function implementing the SPI thread.
* @param argument: Not used
* @retval None
*/
void SpiHandler(void const * argument)
{
  char message[]="Hello World";
  for(;;)
  {
    Debug_PrintMsgTime("SPI Thread \n"); 
    Spi1_Transmit((uint8_t*)message,strlen(message),HAL_MAX_DELAY);
    osDelay(500);
  }
}

/**
* @brief Function implementing the I2C thread.
* @param argument: Not used
* @retval None
*/
void I2cHandler(void const * argument)
{
  /* USER CODE BEGIN I2CHandler */
  char message[]="Hello World";
  /* Infinite loop */
  for(;;)
  {
    Debug_PrintMsgTime("I2C Thread \n"); 
    I2c1_Master_Transmit((uint16_t)I2C_ADDRESS, (uint8_t*)message, strlen(message),HAL_MAX_DELAY);
    osDelay(500);
  }
}

/**
* @brief Function implementing the I2C thread.
* @param argument: Not used
* @retval None
*/
void AdcHandler(void const * argument)
{
  extern ADC_HandleTypeDef hadc1;
  int ADCValue = 0;
  for(;;)
  {
    HAL_ADC_Start(&hadc1);
    if (HAL_ADC_PollForConversion(&hadc1, 1000000) == HAL_OK)
    {
      ADCValue = HAL_ADC_GetValue(&hadc1);
    }
    Debug_PrintMsgTime("ADC Thread \n"); 
    Debug_PrintMsg(" -ADCValue: %i \n", ADCValue); 
    osDelay(500);
  }
}


void Error_Handler(void)
{

}


