#ifndef __BUTTON_H__
#define __BUTTON_H__

#include <stdint.h>
#include <hal/hal.h>
#include <Platform_Types.h>

class Button {
 public:
  Button(): state(STD_OFF){};
  ~Button();

  uint8_t getState(void);

 private:
  uint8_t        state;
};

#endif