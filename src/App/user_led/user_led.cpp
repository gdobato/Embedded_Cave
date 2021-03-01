#include <iostream>
#include <string>
#include <hal/hal.h>
#include <user_led.h>
#include <Platform_Types.h>
#include <gpio/gpio.h>

namespace app::user_led
{

using namespace bsp::gpio;

void User_led::toggle(void)
{
  state = (state == LED_OFF) ? LED_ON : LED_OFF;
  Write(port, pin, (state == LED_OFF) ? HIGH : LOW);
}

void User_led::On(void)
{
  state = LED_ON;
  Write(port, pin, HIGH);
}

void User_led::Off(void)
{
  state = LED_OFF;
  Write(port, pin, LOW);
}

bool User_led::getState(void)
{
  return state;
}
}