#ifndef __TIMER_H__
  #define __TIMER_H__
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
void Timer_Init(void);
uint32_t Timer_GetTick(void);
#endif