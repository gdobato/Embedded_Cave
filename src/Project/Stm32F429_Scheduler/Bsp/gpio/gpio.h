#ifndef __GPIO_H__
  #define __GPIO_H__
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
#ifdef __cplusplus
extern "C" {
#endif
void    Gpio_Init(void);
uint8_t Gpio_GetUserButton(void);
void    Gpio_WriteGreenLed(uint8_t level);
void    Gpio_WriteRedLed(uint8_t level);
#ifdef __cplusplus
}
#endif

#endif