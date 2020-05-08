#ifndef __LED_H__

#include <stdint.h>
#include <hal/hal.h>

#define GREEN_LED 0
#define RED_LED   1

#define LED_ON    0 
#define LED_OFF   1


class Led {
 public:
   Led(const uint8_t idx);
   ~Led();

   void On(void);
   void Off(void);
   bool getState(void);

 private:
  GPIO_TypeDef *  port;
  uint16_t         pin;
  uint8_t        state = LED_OFF;
};

#endif