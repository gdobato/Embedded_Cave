// *****************************************************************************************************************
// Filename    : OsAsm.h
// 
// Core        : ARM Cortex-M4
//
// Compiler    : ARM GCC
//
// Author      : Chalandi Amine
//
// Owner       : Chalandi Amine
// 
// Date        : 06.12.2018
// 
// Description : OSEK/ECC1 Context switch and ISR category 2 wrapper for ARM Cortex-M4
// 
// *****************************************************************************************************************

  void OsDispatcher(void);
  void OsGetCurrentSP(volatile unsigned int* CurrentSpPtr);
  void OsGetPSR(volatile unsigned int* CurrentPsr);
  void OsCat2IsrWrapper(void);
  void OsStartNewTask(uint32 StackFramePtr);

#if 0
//------------------------------------------------------------------------------------------------------------------
/// \brief  OsGetCurrentSP
///
/// \descr  Get the current stack pointer register value
///
/// \param  void
///
/// \return Current stack pointer register value
//------------------------------------------------------------------------------------------------------------------
__asm unsigned int OsGetCurrentSP(void)
{
  mov sp, r10
}

//------------------------------------------------------------------------------------------------------------------
/// \brief  OsGetPSW
///
/// \descr  Get the program status register value
///
/// \param  void
///
/// \return Current program status register value
//------------------------------------------------------------------------------------------------------------------
__asm unsigned int OsGetPSW(void)
{
  stsr PSW, r10
}

//------------------------------------------------------------------------------------------------------------------
/// \brief  OsGetICSR
///
/// \descr  Get the interrupt control status register value
///
/// \param  void
///
/// \return the interrupt control status register value
//------------------------------------------------------------------------------------------------------------------
__asm unsigned int OsGetICSR(void)
{
  stsr ICSR, r10
}

//------------------------------------------------------------------------------------------------------------------
/// \brief  OS_DISPATCH
///
/// \descr  Generate a software trap
///
/// \param  void
///
/// \return void
//------------------------------------------------------------------------------------------------------------------
__asm void OS_DISPATCH(void)
{
   trap 0
}

//------------------------------------------------------------------------------------------------------------------
/// \brief  OsGetFEIC
///
/// \descr  Get the FEIC register value
///
/// \param  void
///
/// \return the FEIC register value
//------------------------------------------------------------------------------------------------------------------
__asm unsigned int OsGetFEIC(void)
{
  stsr FEIC, r10
}

//------------------------------------------------------------------------------------------------------------------
/// \brief  OsGetEIIC
///
/// \descr  Get the EIIC register value
///
/// \param  void
///
/// \return the EIIC register value
//------------------------------------------------------------------------------------------------------------------
__asm unsigned int OsGetEIIC(void)
{
  stsr EIIC, r10
}

//------------------------------------------------------------------------------------------------------------------
/// \brief  OsStartNewTask
///
/// \descr  This function start an OSEK Task for the 1st execution
///
/// \param  void
///
/// \return void
//------------------------------------------------------------------------------------------------------------------
asm void OsStartNewTask(uint32 StackFramePtr, pFunc TaskFuncPtr)
{
%reg StackFramePtr %reg TaskFuncPtr
  mov StackFramePtr,sp   -- set the new stack pointer
  mov TaskFuncPtr,r1
  ldsr r1,eipc           -- set the PC register to TaskFuncPtr
  stsr eipsw,r2          -- load the saved PSW register value
  mov 0x400180E0UL,r1    -- reset the flags SAT,CY,OV,S and Z
  and r1,r2
  ldsr r2,eipsw          -- set the new PSW register
  eiret                  -- return from OsDispatcher
%error 
}
#endif

