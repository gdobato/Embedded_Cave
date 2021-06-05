#Compiler settings
set(PROJECT_CDEFS "-DSTM32H747xx -DCORE_CM7")
set(PROJECT_CPU_FLAGS "-mcpu=cortex-m7 -specs=nano.specs -specs=nosys.specs")        
set(PROJECT_FPU_FLAGS "-mfpu=fpv5-d16 -mfloat-abi=hard")        
set(PROJECT_LINKER_SCRIPT_FILE "${PROJECT_DIR}/Startup/STM32H747XIHX_FLASH.ld ")        
set(STARTUP_FILE startup_stm32l475xx.s)

#Specific project paths

#specific include directories
include_directories(
  ${PROJECT_DIR}/Os
  ${PROJECT_DIR}/App
  ${PROJECT_DIR}/App/ble
  ${PROJECT_DIR}/Bsp
  ${PROJECT_DIR}/Bsp/ble
  ${PROJECT_DIR}/Bsp/hal
  ${PROJECT_DIR}/Debug
  ${PROJECT_DIR}/Startup
  ${PROJECT_DIR}/Stubs
  ${PROJECT_DIR}/Bsp/hal
  ${THIRD_PARTY_DIR}/CMSIS/Device/ST/STM32H7xx/Include
  ${THIRD_PARTY_DIR}/CMSIS/Include
  ${THIRD_PARTY_DIR}/CMSIS/Include
  ${THIRD_PARTY_DIR}/Drivers/STM32H7xx_HAL_Driver/Inc
)






#Files to include
set(PROJECT_FILES
  ${PROJECT_DIR}/main.c
  ${PROJECT_DIR}/Bsp/system/system_stm32h7xx_dualcore_boot_cm4_cm7.c
  ${PROJECT_DIR}/Bsp/system/stm32h7xx_it.c
  ${PROJECT_DIR}/Bsp/hal/stm32h7xx_hal_msp.c
  ${THIRD_PARTY_DIR}/Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal_cortex.c;
  ${THIRD_PARTY_DIR}/Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal_rcc.c;
  ${THIRD_PARTY_DIR}/Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal_rcc_ex.c;
  ${THIRD_PARTY_DIR}/Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal_flash.c;
  ${THIRD_PARTY_DIR}/Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal_flash_ex.c;
  ${THIRD_PARTY_DIR}/Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal_gpio.c;
  ${THIRD_PARTY_DIR}/Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal_hsem.c;
 #${THIRD_PARTY_DIR}/Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal_dma.c;
 #${THIRD_PARTY_DIR}/Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal_dma_ex.c;
 #${THIRD_PARTY_DIR}/Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal_mdma.c;
  ${THIRD_PARTY_DIR}/Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal_pwr.c;
  ${THIRD_PARTY_DIR}/Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal_pwr_ex.c;
  ${THIRD_PARTY_DIR}/Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal.c;
  #${THIRD_PARTY_DIR}/Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal_i2c.c;
  #${THIRD_PARTY_DIR}/Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal_i2c_ex.c;
  ${THIRD_PARTY_DIR}/Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal_exti.c;
  ${THIRD_PARTY_DIR}/Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal_tim.c;
  ${THIRD_PARTY_DIR}/Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal_tim_ex.c;
  ${THIRD_PARTY_DIR}/Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal_uart.c;
  ${THIRD_PARTY_DIR}/Drivers/STM32H7xx_HAL_Driver/Src/stm32h7xx_hal_uart_ex.c;
  #${APP_DIR}/ble/ble_server_legacy.c
  #${APP_DIR}/ble/ble_uuid.cpp
  #${APP_DIR}/stats/stats.cpp
  #${BSP_DIR}/hal/hal_base.cpp
  #${BSP_DIR}/timer/stm32l4x/timer.cpp
  #${BSP_DIR}/usart/usart.cpp
  #${PROJECT_DIR}/main.cpp
  #${THIRD_PARTY_DIR}/FreeRTOS/Source/freertos.c
  #${THIRD_PARTY_DIR}/FreeRTOS/Source/croutine.c
  #${THIRD_PARTY_DIR}/FreeRTOS/Source/event_groups.c
  #${THIRD_PARTY_DIR}/FreeRTOS/Source/list.c
  #${THIRD_PARTY_DIR}/FreeRTOS/Source/queue.c
  #${THIRD_PARTY_DIR}/FreeRTOS/Source/stream_buffer.c
  #${THIRD_PARTY_DIR}/FreeRTOS/Source/tasks.c
  #${THIRD_PARTY_DIR}/FreeRTOS/Source/timers.c
  #${THIRD_PARTY_DIR}/FreeRTOS/Source/CMSIS_RTOS/cmsis_os.c
  #${THIRD_PARTY_DIR}/FreeRTOS/Source/portable/MemMang/heap_4.c
  #${THIRD_PARTY_DIR}/FreeRTOS/Source/portable/GCC/ARM_CM4F/port.c
  #${UTIL_DIR}/fault_profile.cpp
)

#set additional settings
#set_property(SOURCE ${THIRD_PARTY_DIR}/SEGGER/SEGGER/SEGGER_RTT_ASM_ARMv7M.S PROPERTY LANGUAGE C)
set_property(SOURCE ${PROJECT_DIR}/Startup/startup_stm32h747xihx PROPERTY LANGUAGE C)

#set additional information
set(TARGET_DEBUGER USBDFU)