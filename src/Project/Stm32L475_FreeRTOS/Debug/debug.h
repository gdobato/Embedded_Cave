#ifndef __DEBUG_H__
  #define __DEBUG_H__
/**
 * @file 
 * @author 
 * @date
 * @brief
 **/

/************************************
* Public includes 
************************************/
#include "stdarg.h"
#include "string.h"
#include "stdio.h"
/************************************
* Public type definitions 
************************************/

/************************************
* APIs
************************************/
#ifdef __cplusplus
extern "C" {
#endif
void Debug_Init(void);
void Debug_PrintMsg(char *msg, ...);
void Debug_PrintMsgTime(char *msg, ...);
void Debug_PrintMsgTime2(char *msg);

#ifdef __cplusplus
}
#endif


#endif