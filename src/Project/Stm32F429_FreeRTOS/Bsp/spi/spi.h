#ifndef __SPI_H__
  #define __SPI_H__
/**
 * @file 
 * @author 
 * @date
 * @brief
 **/

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
void Spi_Init(void);
HAL_StatusTypeDef Spi1_Transmit(uint8_t *pData, uint16_t Size, uint32_t Timeout);
#endif