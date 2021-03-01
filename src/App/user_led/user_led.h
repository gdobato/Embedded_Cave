#ifndef __USER_LED_H__
#define __USER_LED_H__

#include <stdint.h>
#include <hal/hal.h>
#include <functional>
#include <Platform_Types.h>
#include <gpio/gpio.h>

namespace app::user_led
{
class User_led {
  public:
    using port_t = bsp::gpio::port_t;
    using pin_t  = bsp::gpio::pin_t;
    using state_t = enum{LED_OFF = 0, LED_ON = 1};

    User_led(const port_t& port, const pin_t& pin ) : port{port}, pin{pin}, state{LED_OFF}{} 
    User_led(const User_led& led) = delete;
    User_led& operator=(const User_led&  led) = delete;
    User_led& operator=(      User_led&& led) = default;
   ~User_led()=default;

    void toggle(void);
    void On(void);
    void Off(void);
    bool getState(void);

  protected:
    port_t     port;
    pin_t      pin;
    state_t    state;
};
}
#endif