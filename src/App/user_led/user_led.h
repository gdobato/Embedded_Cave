#ifndef __USER_LED_H__
#define __USER_LED_H__

#include <stdint.h>
#include <hal/hal.h>
#include <functional>
#include <Platform_Types.h>
#include <gpio.h>

namespace app::user_led
{
  template<bsp::gpio::port_type port_value ,
           bsp::gpio::pin_type  pin_value  >
  class User_led
  {
    public:
      using state_type = enum{LED_OFF = 0, LED_ON = 1};
      using gpio_pin  = bsp::gpio::Gpio_Pin<port_value,
                                            pin_value>;

      User_led()                                = default;
      User_led(const User_led& led)             = delete;
      User_led& operator=(const User_led&  led) = delete;
      User_led& operator=(      User_led&& led) = default;
     ~User_led()=default;
  
      void toggle()
      { 
        if (state == LED_OFF)
        {
          gpio_pin::Write(static_cast<bsp::gpio::state_type>(1));
          state = LED_ON;
        }
        else
        {
          gpio_pin::Write(static_cast<bsp::gpio::state_type>(0));
          state = LED_OFF;
        }
          
      }
  
      void On() { state = LED_ON ; gpio_pin::Write(static_cast<bsp::gpio::state_type>(1));}

      void Off(){ state = LED_OFF; gpio_pin::Write(static_cast<bsp::gpio::state_type>(0));}

      state_type getState(void) const { return state;}
  
    protected:
      state_type state;
  
  };
}
#endif