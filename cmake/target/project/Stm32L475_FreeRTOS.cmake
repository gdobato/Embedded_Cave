#Compiler settings
set(PROJECT_CDEFS "-DSTM32L475xx")
set(PROJECT_CPU_FLAGS "-mcpu=cortex-m4 -specs=nano.specs -specs=nosys.specs")        
set(PROJECT_FPU_FLAGS "-mfpu=fpv4-sp-d16 -mfloat-abi=hard")        
set(PROJECT_LINKER_SCRIPT_FILE "${PROJECT_DIR}/Startup/STM32L475VGTx_FLASH.ld ")        
set(STARTUP_FILE startup_stm32l475xx.s)

#Specific project paths

#specific include directories
include_directories(${BSP_DIR}/STM32F4xx/Inc)
include_directories(${THIRD_PARTY_DIR}/CMSIS/Device/ST/STM32L4xx/Include)
include_directories(${THIRD_PARTY_DIR}/CMSIS/Include)
include_directories(${THIRD_PARTY_DIR}/Drivers/STM32L4xx_HAL_Driver/Inc)
include_directories(${PROJECT_DIR}/Os)
include_directories(${PROJECT_DIR}/App)
include_directories(${PROJECT_DIR}/Bsp)
include_directories(${PROJECT_DIR}/Debug)
include_directories(${PROJECT_DIR}/Startup)
include_directories(${PROJECT_DIR}/Bsp/hal)
include_directories(${THIRD_PARTY_DIR}/FreeRTOS/Source/CMSIS_RTOS)
include_directories(${THIRD_PARTY_DIR}/FreeRTOS/Source/include)
include_directories(${THIRD_PARTY_DIR}/FreeRTOS/Source/portable/GCC/ARM_CM4F)

#Files to include
set(PROJECT_FILES
  ${THIRD_PARTY_DIR}/FreeRTOS/Source/freertos.c
  ${THIRD_PARTY_DIR}/FreeRTOS/Source/croutine.c
  ${THIRD_PARTY_DIR}/FreeRTOS/Source/event_groups.c
  ${THIRD_PARTY_DIR}/FreeRTOS/Source/list.c
  ${THIRD_PARTY_DIR}/FreeRTOS/Source/queue.c
  ${THIRD_PARTY_DIR}/FreeRTOS/Source/stream_buffer.c
  ${THIRD_PARTY_DIR}/FreeRTOS/Source/tasks.c
  ${THIRD_PARTY_DIR}/FreeRTOS/Source/timers.c
  ${THIRD_PARTY_DIR}/FreeRTOS/Source/CMSIS_RTOS/cmsis_os.c
  ${THIRD_PARTY_DIR}/FreeRTOS/Source/portable/MemMang/heap_4.c
  ${THIRD_PARTY_DIR}/FreeRTOS/Source/portable/GCC/ARM_CM4F/port.c
  ${THIRD_PARTY_DIR}/Drivers/STM32L4xx_HAL_Driver/Src/stm32l4xx_hal.c
  ${THIRD_PARTY_DIR}/Drivers/STM32L4xx_HAL_Driver/Src/stm32l4xx_hal_cortex.c
  ${THIRD_PARTY_DIR}/Drivers/STM32L4xx_HAL_Driver/Src/stm32l4xx_hal_gpio.c
  ${THIRD_PARTY_DIR}/Drivers/STM32L4xx_HAL_Driver/Src/stm32l4xx_hal_pwr.c
  ${THIRD_PARTY_DIR}/Drivers/STM32L4xx_HAL_Driver/Src/stm32l4xx_hal_pwr_ex.c
  ${THIRD_PARTY_DIR}/Drivers/STM32L4xx_HAL_Driver/Src/stm32l4xx_hal_rcc.c
  ${THIRD_PARTY_DIR}/Drivers/STM32L4xx_HAL_Driver/Src/stm32l4xx_hal_rcc_ex.c
  ${THIRD_PARTY_DIR}/Drivers/STM32L4xx_HAL_Driver/Src/stm32l4xx_hal_tim.c
  ${THIRD_PARTY_DIR}/Drivers/STM32L4xx_HAL_Driver/Src/stm32l4xx_hal_tim_ex.c
  ${THIRD_PARTY_DIR}/Drivers/STM32L4xx_HAL_Driver/Src/stm32l4xx_hal_uart.c
  ${PROJECT_DIR}/Debug/debug.c
  ${PROJECT_DIR}/Debug/taskDebug.c
  ${PROJECT_DIR}/Bsp/gpio/gpio.c
  ${PROJECT_DIR}/Bsp/hal/stm32l4xx_hal_msp.c
  ${PROJECT_DIR}/Bsp/system/stm32l4xx_it.c
  ${PROJECT_DIR}/Bsp/system/system_stm32l4xx.c
  ${PROJECT_DIR}/Bsp/timer/timer.c
  ${PROJECT_DIR}/Bsp/usart/usart.c
  ${PROJECT_DIR}/App/userLed/userLed.cpp
  ${PROJECT_DIR}/App/userLed/taskUserLed.cpp
  ${PROJECT_DIR}/Startup/startup_stm32l475xx.s
  ${PROJECT_DIR}/Startup/Startup_Init.c
  ${PROJECT_DIR}/main.c
)

#set additional settings
set_property(SOURCE ${PROJECT_DIR}/Startup/startup_stm32l475xx.s PROPERTY LANGUAGE C)

#set additional information
set(TARGET_DEBUGER STLINK)