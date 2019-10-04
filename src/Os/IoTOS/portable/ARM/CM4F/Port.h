/**
 * @file OsPort.h
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2019-10-01
 * 
 * @copyright Copyright (c) 2019
 * 
 */
#include <types.h>
#ifndef __OS_PORT_H__
#define __OS_PORT_H__

#define SCB_ICSR            0xE000ED04UL
#define SET_PENDSV()        (*(volatile unsigned int*)(SCB_ICSR)) |= 1UL<<28
#define CLEAR_PENDSV()      (*(volatile unsigned int*)(SCB_ICSR)) &= ~(1UL<<28)
#define OS_DISPATCH()        SET_PENDSV()	

#define ENABLE_INTERRUPTS()	  __asm("CPSIE I")
#define DISABLE_INTERRUPTS()  __asm("CPSID I")

#define EXCEPTION_CODE_MASK   (uint32)0x1F

void OsDispatcher(void);
void OsGetCurrentSP(volatile unsigned int* CurrentSpPtr);
void OsGetPSR(volatile unsigned int* CurrentPsr);
void OsCat2IsrWrapper(void);
void OsStartNewTask(uint32 StackFramePtr);

void SysTickTimer_Init(void);
void SysTickTimer_Start(void);
#endif