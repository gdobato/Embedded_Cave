#include <iostream>
#include <string>
#include <userButton/userButton.h> 

uint8_t UserButton::getState (void) const
{
  if (getLL != nullptr)
    return getLL();
  else
    return STD_LOW;
}

void UserButton::listener(void)const
{

}

void UserButton::registerAction (UserButton::actionType actionType, UserButton::action)
{

}