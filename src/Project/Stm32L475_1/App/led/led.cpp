#include <iostream>
#include <string>
#include "led.h"

#include <cmsis_os.h>
#include <hal/hal.h>

Led::Led(const uint8_t idx)
{
  switch (idx)
  {
    case GREEN_LED:
      port = LED2_GPIO_Port;
      pin  = LED2_Pin;
      break;
    default:
      break;
  }
}

void Led::toggle(uint32_t delay)
{
    state =!state;
    HAL_GPIO_WritePin(port, pin, (GPIO_PinState)state);
    osDelay(delay);
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