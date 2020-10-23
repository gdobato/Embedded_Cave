#include <iostream>
#include <string>
#include "led.h"

#include <hal/hal.h>

Led::Led(const uint8_t idx)
{
  switch (idx)
  {
    case GREEN_LED:
      port = LD3_GPIO_Port;
      pin  = LD3_Pin;
      break;
    case RED_LED:
      port = LD4_GPIO_Port;
      pin  = LD4_Pin;
      break;
    default:
      break;
  }
}

void Led::toggle(void)
{
    state =!state;
    HAL_GPIO_WritePin(port, pin, (GPIO_PinState)state);
    
}

void Led::On(void)
{
  if(state == LED_OFF)
  {
    HAL_GPIO_WritePin(port, pin, GPIO_PIN_SET);
  }
}

void Led::Off(void)
{
  if(state == LED_ON)
  {
    HAL_GPIO_WritePin(port, pin, GPIO_PIN_RESET);
  }
}

bool Led::getState(void)
{
  return state;
}