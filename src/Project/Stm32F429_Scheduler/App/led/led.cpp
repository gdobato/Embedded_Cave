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

void Led::On(void)
{

  HAL_GPIO_WritePin(port, pin, GPIO_PIN_SET);
  state = LED_ON;
}

void Led::Off(void)
{
  HAL_GPIO_WritePin(port, pin, GPIO_PIN_RESET);
  state = LED_OFF;
}

bool Led::getState(void)
{
  return state;
}