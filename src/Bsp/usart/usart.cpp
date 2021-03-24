#include <cstdint>
#include <usart.h>
#include <hal.h>


namespace bsp::usart
{
  Usart::Usart(control_block_type ctrl, uint32_t baudrate)
  {
    handle.Instance          = ctrl;
    handle.Init.BaudRate     = baudrate;
    handle.Init.WordLength   = UART_WORDLENGTH_8B;
    handle.Init.StopBits     = UART_STOPBITS_1;
    handle.Init.Parity       = UART_PARITY_NONE;
    handle.Init.Mode         = UART_MODE_TX_RX;
    handle.Init.HwFlowCtl    = UART_HWCONTROL_NONE;
    handle.Init.OverSampling = UART_OVERSAMPLING_16;
    HAL_UART_Init(&handle);
    
  };

  void Usart::transmit(const uint8_t* data, uint16_t size)
  { 
    HAL_UART_Transmit(&handle, const_cast<uint8_t*>(data), size, UINT32_C(0xFFFF));
  };

  void Usart::receive (uint8_t* data, uint16_t size)
  { 
    HAL_UART_Receive (&handle, data, size, UINT32_C(0xFFFF));
  }

}