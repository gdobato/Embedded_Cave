/**
 * @file 
 * @author 
 * @date
 * @brief
 **/

/************************************
* Includes
************************************/
#include "hal/hal.h"
#include "usart/usart.h"
#include "debug.h"
#include "timer/timer.h"

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
void Debug_PrintMsg(char *msg, ...)
{
  CREATE_VAR_BUFF(buff, msg, 80);
  Usart1_Transmit((uint8_t*)VAR_BUFF(buff), strlen((const char *)VAR_BUFF(buff)), HAL_MAX_DELAY);
}

void Debug_PrintMsgTime(char *msg, ...)
{
  CREATE_VAR_BUFF(buff, msg, 80);
  uint32_t timems = Timer_GetTick();
  char auxStr[90];
  sprintf(auxStr, "[%lu ms] : ", timems);
  strcat(auxStr, VAR_BUFF(buff));
  Usart1_Transmit((uint8_t*)auxStr, strlen((const char *)auxStr), HAL_MAX_DELAY);

}