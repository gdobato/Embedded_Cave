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
#ifdef __cplusplus
extern "C" {
#endif

void Timer_Init(void);
uint32_t Timer_GetTick(void);
uint32_t Timer_Start(uint32_t ulTimeOut);
bool     Timer_TimeOut(uint32_t ulTime);

#ifdef __cplusplus
}
#endif

#endif