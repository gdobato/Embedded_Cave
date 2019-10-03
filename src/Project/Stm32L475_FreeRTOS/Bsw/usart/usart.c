/**
 * @file 
 * @author 
 * @date
 * @brief
 **/

/************************************
* Includes
************************************/
#include "stm32l4xx_hal.h"
#include "hal/hal.h"
#include "usart.h"

/************************************
* Private type definitions 
************************************/

/************************************
* Private variables
************************************/
UART_HandleTypeDef huart5;
UART_HandleTypeDef huart1;
/************************************
* Private declarations 
************************************/
static void Usart_ErrorHandler();

/************************************
* Implementation 
************************************/

void Usart_Init(void)
{
#if(USART_IFC1)
  huart1.Instance = USART1;
  huart1.Init.BaudRate = 115200;
  huart1.Init.WordLength = UART_WORDLENGTH_8B;
  huart1.Init.StopBits = UART_STOPBITS_1;
  huart1.Init.Parity = UART_PARITY_NONE;
  huart1.Init.Mode = UART_MODE_TX_RX;
  huart1.Init.HwFlowCtl = UART_HWCONTROL_NONE;
  huart1.Init.OverSampling = UART_OVERSAMPLING_16;
  if (HAL_UART_Init(&huart1) != HAL_OK)
  {
    Usart_ErrorHandler();
  }
#endif

#if(USART_IFC2)
  huart5.Instance = UART5;
  huart5.Init.BaudRate = 115200;
  huart5.Init.WordLength = UART_WORDLENGTH_8B;
  huart5.Init.StopBits = UART_STOPBITS_1;
  huart5.Init.Parity = UART_PARITY_NONE;
  huart5.Init.Mode = UART_MODE_TX_RX;
  huart5.Init.HwFlowCtl = UART_HWCONTROL_NONE;
  huart5.Init.OverSampling = UART_OVERSAMPLING_16;
  if (HAL_UART_Init(&huart5) != HAL_OK)
  {
    Usart_ErrorHandler();
  }
#endif
}

#if(USART_IFC1)
HAL_StatusTypeDef Usart1_Transmit( uint8_t *pData, uint16_t Size, uint32_t Timeout)
{
  return HAL_UART_Transmit(&huart1, (uint8_t*)pData, Size, Timeout);
}
#endif

#if(USART_IFC1)
HAL_StatusTypeDef Usart2_Transmit(uint8_t *pData, uint16_t Size, uint32_t Timeout)
{
  return HAL_UART_Transmit(&huart5, (uint8_t*)pData, Size, Timeout);
}
#endif

#if(USART_IFC1 || USART_IFC2)
static void Usart_ErrorHandler(void)
{
  __asm("nop");
}
#endif