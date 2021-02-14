#Compiler settings
set(PROJECT_CDEFS "-DSTM32L475xx")
set(PROJECT_CPU_FLAGS "-mcpu=cortex-m4 -specs=nano.specs -specs=nosys.specs")        
set(PROJECT_FPU_FLAGS "-mfpu=fpv4-sp-d16 -mfloat-abi=hard")        
set(PROJECT_LINKER_SCRIPT_FILE "${PROJECT_DIR}/Startup/STM32L475VGTx_FLASH.ld ")        

#Specific project paths

#specific include directories
include_directories(${THIRD_PARTY_DIR}/CMSIS/Device/ST/STM32L4xx/Include)
include_directories(${THIRD_PARTY_DIR}/CMSIS/Include)
include_directories(${THIRD_PARTY_DIR}/Drivers/STM32L4xx_HAL_Driver/Inc)
include_directories(${THIRD_PARTY_DIR}/FreeRTOS/Source/CMSIS_RTOS)
include_directories(${THIRD_PARTY_DIR}/FreeRTOS/Source/include)
include_directories(${THIRD_PARTY_DIR}/FreeRTOS/Source/portable/GCC/ARM_CM4F)
include_directories(${BSP_DIR}/STM32F4xx/Inc)
include_directories(${OS_DIR}/IoTOS)
include_directories(${PROJECT_DIR}/Os)
include_directories(${PROJECT_DIR}/App)
include_directories(${PROJECT_DIR}/Bsp)
include_directories(${PROJECT_DIR}/Debug)
include_directories(${PROJECT_DIR}/Startup)
include_directories(${PROJECT_DIR}/Bsp/hal)


#Files to include
set(PROJECT_FILES
  ${THIRD_PARTY_DIR}/CMSIS/Device/ST/STM32L4xx/Source/Templates/system_stm32l4xx.c
  ${OS_DIR}/IoTOS/Os.c
  ${PROJECT_DIR}/main.c
  ${PROJECT_DIR}/Startup/startup_stm32l475xx.s
  )

#set additional settings
set_property(SOURCE ${PROJECT_DIR}/Startup/startup_stm32l475xx.s         PROPERTY LANGUAGE C)
set_property(SOURCE ${OS_DIR}/IoTOS/portable/ARM/CM4F/PortAsm.s          PROPERTY LANGUAGE C)

#set additional information
set(TARGET_DEBUGER STLINK)