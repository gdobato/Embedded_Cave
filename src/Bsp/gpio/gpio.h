#ifndef __GPIO__H__
#define __GPIO__H__

#include <cstdint>
#include <hal/hal.h>

namespace bsp::gpio
{
  void Init(void);

  using port_type  = uintptr_t;
  using pin_type   = uint16_t;
  using state_type = GPIO_PinState;

  template <const    port_type port_value ,
            const    pin_type  pin_value  >
  class Gpio_Pin
  {
    public:
      static void Write(state_type value) 
      {
       //ToDo: Remove HAL dependencies
        HAL_GPIO_WritePin(reinterpret_cast<GPIO_TypeDef*>(port_value), pin_value,value); 

      }
      static state_type Read (void) 
      {
        return static_cast<uint8_t>(HAL_GPIO_ReadPin (reinterpret_cast<GPIO_TypeDef*>(port_value), pin_value));
      }
  };

}

#endif