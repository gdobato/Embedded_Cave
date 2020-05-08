/**
 * @file 
 * @author 
 * @date
 * @brief
 **/

/************************************
* Includes
************************************/
#include "hal/hal.h"

/************************************
* Private type definitions 
************************************/

/************************************
* Private variables
************************************/
I2C_HandleTypeDef hi2c3;
/************************************
* Private declarations 
************************************/
static void I2c_ErrorHandler(void);

/************************************
* Implementation 
************************************/

void I2c_Init(void)
{
  hi2c3.Instance = I2C3;
  hi2c3.Init.ClockSpeed = 100000;
  hi2c3.Init.DutyCycle = I2C_DUTYCYCLE_2;
  hi2c3.Init.OwnAddress1 = 0;
  hi2c3.Init.AddressingMode = I2C_ADDRESSINGMODE_7BIT;
  hi2c3.Init.DualAddressMode = I2C_DUALADDRESS_DISABLE;
  hi2c3.Init.OwnAddress2 = 0;
  hi2c3.Init.GeneralCallMode = I2C_GENERALCALL_DISABLE;
  hi2c3.Init.NoStretchMode = I2C_NOSTRETCH_DISABLE;
  if (HAL_I2C_Init(&hi2c3) != HAL_OK)
  {
    I2c_ErrorHandler();
  }
  /** Configure Analogue filter 
  */
  if (HAL_I2CEx_ConfigAnalogFilter(&hi2c3, I2C_ANALOGFILTER_ENABLE) != HAL_OK)
  {
    I2c_ErrorHandler();
  }
  /** Configure Digital filter 
  */
  if (HAL_I2CEx_ConfigDigitalFilter(&hi2c3, 0) != HAL_OK)
  {
    I2c_ErrorHandler();
  }
}

HAL_StatusTypeDef I2c1_Master_Transmit(uint16_t DevAddress, uint8_t *pData, uint16_t Size, uint32_t Timeout)
{
  return HAL_I2C_Master_Transmit(&hi2c3, (uint16_t)DevAddress, (uint8_t*)pData, Size,Timeout);
}

void I2c_ErrorHandler(void)
{
  __asm("nop");
}