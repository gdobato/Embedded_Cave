#ifndef __TIMER_H__
#define __TIMER_H__
#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

uint32_t Get_Tick();

#ifdef __cplusplus
}
#endif


//Basic C++ wrapper
//Keep C compatible interface for the momment
namespace bsp::timer
{
  void     Init();  
  using    ::Get_Tick;
}

#endif