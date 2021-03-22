#ifndef __USART__H__
#define __USART__H__

#include <hal.h>
#include <cstdint>

//Basic C++ wrapper.

namespace bsp::usart
{
  using handle_type        = UART_HandleTypeDef;
  using control_block_type = USART_TypeDef*;
  class Usart
  {
    public:
      Usart(control_block_type ctrl, uint32_t baudrate);
      Usart(const Usart&) = delete;
     ~Usart() = default;
      void init();
      void transmit(const uint8_t* data, uint16_t size);
      void receive (      uint8_t* data, uint16_t size);

    private:
      handle_type handle;     
  };

}
#endif 