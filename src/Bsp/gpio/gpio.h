#ifndef __GPIO_H__
  #define __GPIO_H__
/**
 * @file 
 * @author 
 * @date
 * @brief
 **/

/************************************
* Public includes 
************************************/

/************************************
* Public type definitions 
************************************/

/************************************
* APIs
************************************/
namespace bsp::gpio
{
  using port_t  = GPIO_TypeDef*;
  using pin_t   = uint16_t;
  using level_t = enum level{HIGH, LOW};

  void Init(void);
  void Write(port_t port, pin_t pin, level_t level);
}

#endif