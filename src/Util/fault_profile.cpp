#include <fault_profile.h>
#include <misc.h>
#include <cstdint>


namespace util::fault_profile
{
  //Auxiliary Control Register
  constexpr uint32_t ACTLR_ADD = UINT32_C(0xE000E008);
  //System Handler Control and State Register
  constexpr uint32_t SHCSR_ADD = UINT32_C(0xE000ED24);
  //Configurable Fault Status Registers
  constexpr uint32_t MFSR_ADD  = UINT32_C(0xE000ED28);
  constexpr uint32_t BFSR_ADD  = UINT32_C(0xE000ED29);
  constexpr uint32_t UFSR_ADD  = UINT32_C(0xE000ED2A);

  //HardFault Status register
  constexpr uint32_t HFSR_ADD  = UINT32_C(0xE000ED2C);
  //Debug Fault Status register
  constexpr uint32_t DFSR_ADD  = UINT32_C(0xE000ED30);
  //MemManage Address Register
  constexpr uint32_t MMFAR_ADD = UINT32_C(0xE000ED34);
  //Bus Fault Address Register
  constexpr uint32_t BFAR_ADD  = UINT32_C(0xE000ED38);

  constexpr uint32_t DUMMY_VAL = UINT32_C(0xAAAAAAAA); 
  
  union xpsr_t
  {
    uint32_t raw;
    struct bits 
    {
      uint32_t ipsr :  8; 
      uint32_t epsr : 19;
      uint32_t apsr :  5;
    };
  };
  
  struct context_t
  {
    uint32_t r0;
    uint32_t r1;
    uint32_t r2;
    uint32_t r3;
    uint32_t r12;
    uint32_t lr;
    uint32_t pc;
    xpsr_t   xpsr;
  };
  
  union shcsr_t 
  {
    uint32_t raw;
    struct bits 
    {
      uint32_t memfault_act   :  1;
      uint32_t busfault_act   :  1;
      uint32_t                :  1;
      uint32_t usgfault_act   :  1;
      uint32_t                :  3;
      uint32_t svcall_act     :  1;
      uint32_t monitor_act    :  1;
      uint32_t                :  1;
      uint32_t pendsv_act     :  1;
      uint32_t systick_act    :  1;
      uint32_t usgfault_pend  :  1;
      uint32_t memfault_pend  :  1;
      uint32_t busfault_pend  :  1;
      uint32_t svcall_pend    :  1;
      uint32_t memfault_en    :  1;
      uint32_t busfault_en    :  1;
      uint32_t usgfault_en    :  1;
      uint32_t                : 12;
  
    };
  };
  
  
   union mfsr_t
   {
     uint8_t raw;
     struct bits 
     {
       uint8_t iac_viol      : 1;
       uint8_t dacc_viol     : 1;
       uint8_t               : 1;
       uint8_t munstk_err    : 1;
       uint8_t mstk_err      : 1;
       uint8_t               : 2;
       uint8_t mmar_valid    : 1;
     };
   }; 
  
   union bfsr_t
   {
     uint8_t raw;
     struct bits 
     {
       uint8_t ibus_err      : 1;
       uint8_t precis_err    : 1;
       uint8_t imprecis_err  : 1;
       uint8_t unstk_err     : 1;
       uint8_t stk_err       : 1;
       uint8_t               : 2;
       uint8_t bfar_valid    : 1;
     };
   };
   union ufsr_t
   {
     uint16_t raw;
     struct bits
     {
       uint16_t undefinstr    : 1;
       uint16_t invstate      : 1;
       uint16_t invpc         : 1;
       uint16_t nocp          : 1;
       uint16_t               : 4;
       uint16_t unaligned     : 1;
       uint16_t divbyzero     : 1;
       uint16_t               : 6;
  
     };
   };
   union hfsr_t
   {
     uint32_t raw;
     struct bits
     {
       uint32_t              :  1;
       uint32_t vectbl       :  1;
       uint32_t              : 28;
       uint32_t forced       :  1;
       uint32_t debug_evt    :  1;
     };
   };
  
  struct csfr_t
  {
    mfsr_t mfsr;
    bfsr_t bfsr;
    ufsr_t ufsr;
  };

  volatile hfsr_t     hfsr   ;
  volatile shcsr_t    shcsr  ; 
  volatile csfr_t     cfsr   ; 
  volatile context_t  context; 
  volatile uint32_t   mmfar  ;
  volatile uint32_t   bfar   ;

}

 extern "C"
 {
  using namespace util::fault_profile;

  void fault_enable_usg_fault()       { *reinterpret_cast<volatile uint32_t*>(SHCSR_ADD) |= ( 1U << 18U); }
  void fault_enable_bus_fault()       { *reinterpret_cast<volatile uint32_t*>(SHCSR_ADD) |= ( 1U << 17U); }
  void fault_enable_mem_fault()       { *reinterpret_cast<volatile uint32_t*>(SHCSR_ADD) |= ( 1U << 16U); }
  void fault_disable_write_buffering(){ *reinterpret_cast<volatile uint32_t*>(ACTLR_ADD) |= ( 1U <<  1U); }

  __attribute__((naked))void fault_profile_prepare()
  {
      //Save PSP or MSP in R0
    __asm("tst LR, #4");  
    __asm("ite EQ");
    __asm("mrseq R0, MSP");
    __asm("mrsne R0, PSP");
  }


  void fault_profile_catch (uint32_t* pStack)
  {
  
    context.r0       = pStack[0U];
    context.r1       = pStack[1U];
    context.r2       = pStack[2U];
    context.r3       = pStack[3U];
    context.r12      = pStack[4U];
    context.lr       = pStack[5U];
    context.pc       = pStack[6U];
    context.xpsr.raw = pStack[7U];

    mmfar            = *reinterpret_cast<volatile uint32_t*> (MMFAR_ADD);
    bfar             = *reinterpret_cast<volatile uint32_t*> (BFAR_ADD);

    hfsr.raw         = *reinterpret_cast<volatile uint32_t*> (HFSR_ADD );
    shcsr.raw        = *reinterpret_cast<volatile uint32_t*> (SHCSR_ADD);
    cfsr.ufsr.raw    = *reinterpret_cast<volatile uint8_t* > (UFSR_ADD );   
    cfsr.mfsr.raw    = *reinterpret_cast<volatile uint8_t* > (MFSR_ADD );
    cfsr.bfsr.raw    = *reinterpret_cast<volatile uint8_t* > (BFSR_ADD );

    util::misc::unused(hfsr, shcsr,cfsr,context,mmfar,bfar);
    
    
    for(;;)
    {
      __asm("nop");
    }
  }

  __attribute__((naked))void fault_profile ()
  {
    __asm("b fault_profile_prepare"); 
    __asm("b fault_profile_catch");
  }

  void fault_inject_bus_fault()
  {
    *reinterpret_cast<volatile uint32_t*>(0xFFFFFFFF) = DUMMY_VAL;
  }

 }