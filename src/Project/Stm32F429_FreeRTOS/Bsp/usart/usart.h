#ifndef __USART_H__
  #define __USART_H__
/**
 * @file 
 * @author 
 * @date
 * @brief
 **/

/************************************
* Public includes
************************************/

/************************************
* Public definitions 
************************************/
#define USART_IFC1 1 
#define USART_IFC2 0

/************************************
* Public includes 
************************************/
#include "hal/hal.h"

/************************************
* Public type definitions 
************************************/

/************************************
* APIs
************************************/
#ifdef __cplusplus
extern "C"{
#endif

#if(USART_IFC1 || USART_IFC2)
void Usart_Init(void);
#endif

#if(USART_IFC1)
HAL_StatusTypeDef Usart1_Transmit(uint8_t *pData, uint16_t Size, uint32_t Timeout);
#endif

#if(USART_IFC2)
HAL_StatusTypeDef Usart2_Transmit(uint8_t *pData, uint16_t Size, uint32_t Timeout);
#endif

#ifdef __cplusplus
}
#endif

#endif