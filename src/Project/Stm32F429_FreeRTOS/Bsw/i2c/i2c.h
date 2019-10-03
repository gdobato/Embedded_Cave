#ifndef __I2C_H__
  #define __I2C_H__
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
void I2c_Init(void);
HAL_StatusTypeDef I2c1_Master_Transmit(uint16_t DevAddress, uint8_t *pData, uint16_t Size, uint32_t Timeout);

#endif