#ifndef __USER_BUTTON_H__
#define __USER_BUTTON_H__

#include <stdint.h>
#include <hal/hal.h>
#include <functional>
#include <Platform_Types.h>
#include <gpio.h>

namespace app::user_button
{
  template<bsp::gpio::port_type port_value ,
           bsp::gpio::pin_type  pin_value  >
  class User_button
  {
    public:
      using pull_type    = enum{PULLUP, PULLDOWN};
      using state_type   = enum{PRESSED, RELEASED};
      using event_type   = enum{HIGH,LOW, RISE,DOWN};
      using action_type  = std::function<void()>;
      using gpio_pin     = bsp::gpio::Gpio_Pin<port_value,
                                              pin_value>;

      User_button(pull_type pull) : pull(pull),state{RELEASED}{};
      User_button(const User_button& led)              = delete;
      User_button& operator=(const User_button&   led) = delete;
      User_button& operator=(      User_button&&  led) = default;
     ~User_button()=default;
  

      state_type getState()
      { 
        state = gpio_pin::Read() == static_cast<bsp::gpio::state_type>(0) ? (pull == PULLDOWN ? RELEASED : PRESSED)
                                                                          : (pull == PULLDOWN ? PRESSED  : RELEASED);
        return state;
      }
      void  register_action (event_type event, action_type action); 
      void  listener();

    protected:
      state_type state;
      pull_type  pull;
  
  };
}
#endif