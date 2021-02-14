#ifndef __USERLED_H__
#define __USERLED_H__

#include <stdint.h>
#include <hal/hal.h>


class UserLed {
 public:
   using writeLLPort = void(*)(uint8_t);

   UserLed(writeLLPort wLLPort = nullptr) : wLLPort(wLLPort) {};
   UserLed(const UserLed& led) = delete;
   UserLed& operator=(const UserLed& led)  = delete;
   UserLed& operator=(      UserLed&& led) = default;
  ~UserLed()=default;

   void toggle(void);
   void On(void);
   void Off(void);
   bool getState(void);

 private:
  writeLLPort wLLPort;
  uint8_t     state;
};

#endif