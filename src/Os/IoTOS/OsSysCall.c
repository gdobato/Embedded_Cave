#include <stdint.h>
#include "OsDefs.h"

       void Service1(void) __WEAK;
       void Service2(void) __WEAK;
static void SVC_Parser(uint32_t *svc_args);

void SVC_Handler(void)
{
  __ASM("TST   LR, #4 ");
  __ASM("ITE   EQ     ");
  __ASM("MRSEQ R0, MSP");
  __ASM("MRSNE R0, PSP");
  __ASM("BL    SVC_Parser");
}

/*
   -----------------
   |    R15(PC)    |
   -----------------
   |    R14(LR)    |
   -----------------
   |    R12        |
   -----------------
   |    R3         |
   -----------------
   |    R2         |
   -----------------
   |    R1         |
   -----------------
   |    R0         |
   -----------------
 */
static void SVC_Parser(uint32_t *svc_args)
{
  uint32_t svc_number = ((uint8_t*)svc_args[6])[-2];

  switch(svc_number)
  {
    case 0:
      Service1();
      break;
    case 1:
      Service1();
      break;
    default:
      break;
  }
}
