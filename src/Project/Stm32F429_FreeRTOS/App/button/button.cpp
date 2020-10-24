#include <iostream>
#include <string>
#include <button/button.h> 
#include <hal/hal.h>
#include <gpio/gpio.h>

uint8_t Button::getState(void)
{
  return Gpio_GetUserButton();
}