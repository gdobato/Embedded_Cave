/**
 * @file 
 * @author 
 * @date
 * @brief
 **/

/************************************
* Includes
************************************/
#include "debug.h"
#include <hal.h>
#include <timer.h>
#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>

/************************************
* Private type definitions 
************************************/
#define CREATE_VAR_BUFF(buff, msg, size)  \
  char buff##Var[size];                   \
  va_list args;                           \
  va_start(args,msg);                     \
  vsprintf(buff##Var,msg,args);           \

#define VAR_BUFF(buff) buff##Var

/************************************
* Private variables
************************************/

/************************************
* Private declarations 
************************************/

/************************************
* Implementation 
************************************/
#include <usart.h>
#include <string>
//ToDo add proper C++ semihosting artifact
bsp::usart::Usart usart1 {USART1, 115200};

void Debug_Init(void){usart1.init();}
void Debug_PrintMsg(char *msg, ...)
{
  CREATE_VAR_BUFF(buff, msg, 1024);
  usart1.transmit((uint8_t*)VAR_BUFF(buff), strlen((const char *)VAR_BUFF(buff)));
}

void Debug_PrintMsgTime(char *msg, ...)
{
  CREATE_VAR_BUFF(buff, msg, 1024);
  uint32_t timems = bsp::timer::Get_Tick();
  char auxStr[90];
  sprintf(auxStr, "[%lu ms] : ", timems);
  strcat(auxStr, VAR_BUFF(buff));
  usart1.transmit((uint8_t*)auxStr, strlen((const char *)auxStr));
   
}

