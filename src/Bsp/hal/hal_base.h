#ifndef __HAL_BASE_H__
#define __HAL_BASE_H__

//ToDo : Do proper interface inclusion depending of underlying HAL
extern "C"
HAL_StatusTypeDef HAL_Init(void);

namespace bsp::hal
{
  void Init(void){ HAL_Init(); } 
}


#endif