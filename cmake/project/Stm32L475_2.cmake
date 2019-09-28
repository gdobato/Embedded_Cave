#Compiler settings
set(PROJECT_CDEFS "-DSTM32L475xx")
set(PROJECT_CPU_FLAGS "-mcpu=cortex-m4 -specs=nano.specs -specs=nosys.specs")        
set(PROJECT_FPU_FLAGS "-mfpu=fpv4-sp-d16 -mfloat-abi=hard")        
set(PROJECT_LINKER_SCRIPT_FILE "STM32L475VGTx_FLASH.ld ")        
set(STARTUP_FILE startup_stm32l475xx.s)

#Specific project paths

#specific include directories
include_directories(${CMSIS_DIR}/Device/ST/STM32L4xx/Include)

#Files to include
set(PROJECT_FILES
  ${STARTUP_DIR}/startup_stm32l475xx.s
  ${BSW_DIR}/system/system_stm32l4xx.c
  ${PROJECT_DIR}/main.c
  ${IOTOS_DIR}/OsSysCall.c
  )

#set additional information
set(TARGET_DEBUGER STLINK)