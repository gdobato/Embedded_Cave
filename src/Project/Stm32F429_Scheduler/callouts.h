#ifndef __CALLOUTS_H__
#define __CALLOUTS_H__


void Interrupts_Enable   (void); 
void Interrupts_Disable  (void); 
uint32_t Timer_Start(uint32_t ulTimeOut);
bool Timer_TimeOut(uint32_t ulTime);


#endif