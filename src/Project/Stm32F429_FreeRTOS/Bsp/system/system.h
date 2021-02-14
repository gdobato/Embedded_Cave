#ifndef __SYSTEM_H__
  #define __SYSTEM_H__
/**
 * @file 
 * @author 
 * @date
 * @brief
 **/
#include "core_cm4.h"
void System_Init(void);
 /* Enable Counter of DWT Cell. ToDo:it needs to be encapsulated. Remove CMSIS dependencies*/

static inline void System_EnableCycleCounter(void) { DWT->CTRL |= 0x01; }

#endif