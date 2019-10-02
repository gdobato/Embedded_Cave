#Compiler settings
set(PROJECT_CDEFS "-DSTM32L475xx")
set(PROJECT_CPU_FLAGS "-mcpu=cortex-m4 -specs=nano.specs -specs=nosys.specs")        
set(PROJECT_FPU_FLAGS "-mfpu=fpv4-sp-d16 -mfloat-abi=hard")        
set(PROJECT_LINKER_SCRIPT_FILE "STM32L475VGTx_FLASH.ld ")        

#Specific project paths

#specific include directories
include_directories(${CMSIS_DIR}/Device/ST/STM32L4xx/Include)
include_directories(${CMSIS_DIR}/Include)
include_directories(${IOTOS_DIR})

#Files to include
set(PROJECT_FILES
  ${STARTUP_DIR}/SysStartup.c
  ${BSW_DIR}/system/system_stm32l4xx.c
  ${PROJECT_DIR}/main.c
  ${PROJECT_DIR}/tasks.c
  ${IOTOS_DIR}/portable/ARM/CM4F/PortAsm.s
  ${IOTOS_DIR}/portable/ARM/CM4F/Port.c
  ${IOTOS_DIR}/Os.c
  ${IOTOS_DIR}/OsAlarm.c
  ${IOTOS_DIR}/OsEvt.c
  ${IOTOS_DIR}/OsTask.c
  ${IOTOS_DIR}/TCB.c
  )

#set additional settings
set_property(SOURCE ${IOTOS_DIR}/portable/ARM/CM4F/PortAsm.s PROPERTY LANGUAGE C)
set_property(SOURCE ${STARTUP_DIR}/startup_stm32l475xx.s     PROPERTY LANGUAGE C)

#set additional information
set(TARGET_DEBUGER STLINK)