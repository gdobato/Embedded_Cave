#ifndef __OS_H__
#define __OS_H__

#include <stdint.h>
#include <stdbool.h>
#include "Os_Cfg.h"

#define OS_EVENT(x)         (1U << x)

#ifdef __cplusplus
extern "C" {
#endif

void Os_Start     (void);
void Os_SetEvent  (uint16_t unTaskId, uint32_t ulEvent);
void Os_ClearEvent(uint16_t unTaskId, uint32_t ulEvent);
bool Os_GetEvent  (uint16_t unTaskId, uint32_t ulEvent);

#ifdef __cplusplus
}
#endif

#endif