#ifndef __FAULT_PROFILE_H__
#define __FAULT_PROFILE_H__
#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

void fault_profile ();
void fault_inject_bus_fault();
void fault_enable_usg_fault();
void fault_enable_bus_fault();
void fault_enable_mem_fault();
void fault_disable_write_buffering();

#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
namespace util::fault_profile
{
  using ::fault_profile;
  using ::fault_inject_bus_fault;
  using ::fault_enable_usg_fault;
  using ::fault_enable_bus_fault;
  using ::fault_enable_mem_fault;
  using ::fault_disable_write_buffering;
}
#endif

#endif
