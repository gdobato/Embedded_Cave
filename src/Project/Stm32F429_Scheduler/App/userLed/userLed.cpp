#include <iostream>
#include <string>
#include <hal/hal.h>
#include "userLed.h"
#include <Platform_Types.h>



void UserLed::toggle(void)
{
  if(wLLPort!= nullptr)
  {
    state =!state;
    wLLPort(state);
  }
}

void UserLed::On(void)
{
  if(wLLPort!= nullptr)
  {
    wLLPort(STD_ON);
  }
}

void UserLed::Off(void)
{
  if(wLLPort!= nullptr)
  {
    wLLPort(STD_OFF);
  }
}

bool UserLed::getState(void)
{
  return state;
}