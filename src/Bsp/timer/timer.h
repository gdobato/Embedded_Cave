#ifndef __TIMER_H__
#define __TIMER_H__

#include <stdint.h>

//Basic C++ wrapper
//Keep C compatible interface for the momment


namespace bsp::timer
{
  void     Init();  
  uint32_t Get_Tick();
}

#endif