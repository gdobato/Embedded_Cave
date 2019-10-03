#Compiler settings
set(PROJECT_CDEFS "-DSTM32L475xx")
set(PROJECT_CPU_FLAGS "-mcpu=cortex-m4 -specs=nano.specs -specs=nosys.specs")        
set(PROJECT_FPU_FLAGS "-mfpu=fpv4-sp-d16 -mfloat-abi=hard")        
set(PROJECT_LINKER_SCRIPT_FILE "STM32L475VGTx_FLASH.ld ")        
set(STARTUP_FILE startup_stm32l475xx.s)

#Specific project paths
set(DRIVER_HAL_DIR           ${DRIVER_DIR}/STM32L4xx_HAL_Driver)

#specific include directories
include_directories(${BSW_DIR}/hal)
include_directories(${CMSIS_DIR}/Device/ST/STM32L4xx/Include)
include_directories(${CMSIS_DIR}/Include)
include_directories(${DRIVER_HAL_DIR}/Inc)
include_directories(${DRIVER_BAREMETAL_DIR}/Inc)
include_directories(${FREERTOS_DIR}/Source/CMSIS_RTOS)
include_directories(${FREERTOS_DIR}/Source/include)
include_directories(${FREERTOS_DIR}/Source/portable/GCC/ARM_CM4F)

#Files to include
set(PROJECT_FILES
  ${STARTUP_DIR}/startup_stm32l475xx.s
  ${STARTUP_DIR}/Startup_Init.c
  ${PROJECT_DIR}/main.c
  ${FREERTOS_DIR}/Source/freertos.c
  ${FREERTOS_DIR}/Source/croutine.c
  ${FREERTOS_DIR}/Source/event_groups.c
  ${FREERTOS_DIR}/Source/list.c
  ${FREERTOS_DIR}/Source/queue.c
  ${FREERTOS_DIR}/Source/stream_buffer.c
  ${FREERTOS_DIR}/Source/tasks.c
  ${FREERTOS_DIR}/Source/timers.c
  ${FREERTOS_DIR}/Source/CMSIS_RTOS/cmsis_os.c
  ${FREERTOS_DIR}/Source/portable/MemMang/heap_4.c
  ${FREERTOS_DIR}/Source/portable/GCC/ARM_CM4F/port.c
  ${DRIVER_HAL_DIR}/Src/stm32l4xx_hal.c
  ${DRIVER_HAL_DIR}/Src/stm32l4xx_hal_cortex.c
  ${DRIVER_HAL_DIR}/Src/stm32l4xx_hal_gpio.c
  ${DRIVER_HAL_DIR}/Src/stm32l4xx_hal_pwr.c
  ${DRIVER_HAL_DIR}/Src/stm32l4xx_hal_pwr_ex.c
  ${DRIVER_HAL_DIR}/Src/stm32l4xx_hal_rcc.c
  ${DRIVER_HAL_DIR}/Src/stm32l4xx_hal_rcc_ex.c
  ${DRIVER_HAL_DIR}/Src/stm32l4xx_hal_tim.c
  ${DRIVER_HAL_DIR}/Src/stm32l4xx_hal_tim_ex.c
  ${DRIVER_HAL_DIR}/Src/stm32l4xx_hal_uart.c
  ${DEBUG_DIR}/debug.c
  ${DEBUG_DIR}/debugThread.c
  ${BSW_DIR}/gpio/gpio.c
  ${BSW_DIR}/hal/stm32l4xx_hal_msp.c
  ${BSW_DIR}/system/stm32l4xx_it.c
  ${BSW_DIR}/system/system_stm32l4xx.c
  ${BSW_DIR}/timer/timer.c
  ${BSW_DIR}/usart/usart.c
  ${APP_DIR}/led/led.cpp
  ${APP_DIR}/led/ledThread.cpp
)

#set additional settings
set_property(SOURCE ${STARTUP_DIR}/startup_stm32l475xx.s PROPERTY LANGUAGE C)

#set additional information
set(TARGET_DEBUGER STLINK)