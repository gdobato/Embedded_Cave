// *****************************************************************************************************************
// Filename    : OsAsm.c
// 
// Core        : ARM Cortex-M4
//
// Compiler    : ARM GCC
//
// Author      : Chalandi Amine
//
// Owner       : Chalandi Amine
// 
// Date        : 18.04.2018
// 
// Description : OSEK/ECC1 Context switch and ISR category 2 wrapper for Renesas RH850
// 
// *****************************************************************************************************************

//------------------------------------------------------------------------------------------------------------------
// function prototypes
//------------------------------------------------------------------------------------------------------------------
void __attribute__((weak))OsDispatcher(void);
void __attribute__((weak))OsCat2IsrWrapper(void);
void __attribute__((weak))OsCat2FEIsrWrapper(void);
#if 0
//------------------------------------------------------------------------------------------------------------------
/// \brief  OsDispatcher
///
/// \descr  Context switcher
///
/// \param  void
///
/// \return void
//------------------------------------------------------------------------------------------------------------------
#pragma asm
 __asm__(
  ".align 4"
  ".globl  _OsDispatcher"
"_OsDispatcher:"
  "di"
  "pushsp r1-r2             -- Store the current context into the stack"
  "pushsp r6-r31"
#if defined(OS_SUPPORT_HW_FPU)
  "stsr fpsr,r24            -- Store the FPU context"
  "stsr fpepc,r25"
  "pushsp r24-r25"
#endif
  stsr eipsw,r26
  stsr eipc,r27
  pushsp r26-r27 
  mov sp,r6                -- Prepare the input parameter for the function OS_Dispatcher
  jarl _OS_Dispatcher,lp   -- Call the dispatcher to switch the context
  mov r10,sp               -- Set the new stack pointer of the active task
  popsp r26-r27            -- Restore the context from the active task
  ldsr r27,eipc 
  ldsr r26,eipsw
#if defined(OS_SUPPORT_HW_FPU)
  popsp r24-r25
  ldsr r24,fpsr            -- Restore the FPU context
  ldsr r25,fpepc
#endif
  popsp r6-r31  
  popsp r1-r2  
  ei
  eiret
#pragma endasm

//------------------------------------------------------------------------------------------------------------------
/// \brief  OsCat2IsrWrapper
///
/// \descr  Wrapper for all category 2 EI level interrupts
///
/// \param  void
///
/// \return void
//------------------------------------------------------------------------------------------------------------------
#pragma asm

  .align 4
  .globl  _OsCat2IsrWrapper

_OsCat2IsrWrapper:

#ifndef OS_NESTED_INT  
  di
#endif  
  pushsp r1-r2                      -- Store the current context into the stack
  pushsp r6-r31
#if defined(OS_SUPPORT_HW_FPU)
  stsr fpsr,r24                     -- Store the FPU context
  stsr fpepc,r25
  pushsp r24-r25
#endif
  stsr eipsw,r26
  stsr eipc,r27
  pushsp r26-r27 
  mov sp,r6                         -- prepare the input parameter for the function OsStoreStackPointer
  jarl _OsStoreStackPointer,lp      -- Save the stack pointer of the current task
  jarl _OsRunCat2Isr,lp             -- Call the ISR (lookup table)
  jarl _OsGetSavedStackPointer,lp   -- Restore the stack pointer of the current task
  mov r10,r6
  jarl _OsIsrCallDispatch,lp        -- Call dispatcher if needed
  mov r10,sp                        -- Set the new stack pointer of the active task
  popsp r26-r27                     -- Restore the context from the active task
  ldsr r27,eipc 
  ldsr r26,eipsw
#if defined(OS_SUPPORT_HW_FPU)
  popsp r24-r25
  ldsr r24,fpsr                     -- Restore the FPU context
  ldsr r25,fpepc
#endif
  popsp r6-r31  
  popsp r1-r2 
#ifndef OS_NESTED_INT
  ei
#endif  
  eiret

#pragma endasm

//------------------------------------------------------------------------------------------------------------------
/// \brief  OsCat2FEIsrWrapper
///
/// \descr  Wrapper for all category 2 FE level interrupts
///
/// \param  void
///
/// \return void
//------------------------------------------------------------------------------------------------------------------
#pragma asm

_asm (
  ".align 4"
  ".globl  _OsCat2FEIsrWrapper"
)

_OsCat2FEIsrWrapper:

  pushsp r1-r2                      -- Store the current context into the stack
  pushsp r6-r31
#if defined(OS_SUPPORT_HW_FPU)
  stsr fpsr,r24                     -- Store the FPU context
  stsr fpepc,r25
  pushsp r24-r25 
#endif
  stsr fepsw,r26
  stsr fepc,r27
  pushsp r26-r27 
  mov sp,r6                         -- prepare the input parameter for the function OsStoreStackPointer
  jarl _OsStoreStackPointer,lp      -- Save the stack pointer of the current task
  jarl _OsRunCat2FEIsr,lp           -- Call the ISR (lookup table)
  jarl _OsGetSavedStackPointer,lp   -- Restore the stack pointer of the current task
  mov r10,r6
  jarl _OsIsrCallDispatch,lp        -- Call dispatcher if needed
  mov r10,sp                        -- Set the new stack pointer of the active task
  popsp r26-r27                     -- Restore the context from the active task
  ldsr r27,fepc 
  ldsr r26,fepsw
#if defined(OS_SUPPORT_HW_FPU)
  popsp r24-r25
  ldsr r24,fpsr                     -- Restore the FPU context
  ldsr r25,fpepc
#endif
  popsp r6-r31
  popsp r1-r2
  feret

#pragma endasm
#endif
