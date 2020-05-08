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
SPI_HandleTypeDef hspi5;
/************************************
* Private declarations 
************************************/
static void Spi_ErrorHandler(void);
/************************************
* Implementation 
************************************/

/**
  * @brief SPI5 Initialization Function
  * @param None
  * @retval None
  */
void Spi_Init(void)
{
  hspi5.Instance = SPI5;
  hspi5.Init.Mode = SPI_MODE_MASTER;
  hspi5.Init.Direction = SPI_DIRECTION_2LINES;
  hspi5.Init.DataSize = SPI_DATASIZE_8BIT;
  hspi5.Init.CLKPolarity = SPI_POLARITY_LOW;
  hspi5.Init.CLKPhase = SPI_PHASE_1EDGE;
  hspi5.Init.NSS = SPI_NSS_SOFT;
  hspi5.Init.BaudRatePrescaler = SPI_BAUDRATEPRESCALER_16;
  hspi5.Init.FirstBit = SPI_FIRSTBIT_MSB;
  hspi5.Init.TIMode = SPI_TIMODE_DISABLE;
  hspi5.Init.CRCCalculation = SPI_CRCCALCULATION_DISABLE;
  hspi5.Init.CRCPolynomial = 10;
  if (HAL_SPI_Init(&hspi5) != HAL_OK)
  {
    Spi_ErrorHandler();
  }
}


HAL_StatusTypeDef Spi1_Transmit(uint8_t *pData, uint16_t Size, uint32_t Timeout)
{
  return HAL_SPI_Transmit(&hspi5,(uint8_t*)pData,Size,Timeout);
}

void Spi_ErrorHandler(void)
{
  __asm("nop");
}