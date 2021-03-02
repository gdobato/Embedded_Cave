#Compiler settings

set(PROJECT_CDEFS "-DSTM32F429xx")
set(PROJECT_CPU_FLAGS "-mcpu=cortex-m4 -specs=nano.specs -specs=nosys.specs")        
set(PROJECT_FPU_FLAGS "-mfpu=fpv4-sp-d16 -mfloat-abi=hard")        
set(PROJECT_LINKER_SCRIPT_FILE "${PROJECT_DIR}/Startup/STM32F429ZITx_FLASH.ld ")        

#Specific project paths

#Paths to include
include_directories(
  ${BSP_DIR}/STM32F4xx/Inc
  ${PROJECT_DIR}/Os
  ${PROJECT_DIR}/App
  ${PROJECT_DIR}/Bsp
  ${PROJECT_DIR}/Debug
  ${PROJECT_DIR}/Startup
  ${PROJECT_DIR}/Bsp/hal
  ${THIRD_PARTY_DIR}/CMSIS/Device/ST/STM32F4xx/Include
  ${THIRD_PARTY_DIR}/CMSIS/Include
  ${THIRD_PARTY_DIR}/Drivers/STM32F4xx_HAL_Driver/Inc
  ${THIRD_PARTY_DIR}/FreeRTOS/Source/CMSIS_RTOS
  ${THIRD_PARTY_DIR}/FreeRTOS/Source/include
  ${THIRD_PARTY_DIR}/FreeRTOS/Source/portable/GCC/ARM_CM4F
  ${THIRD_PARTY_DIR}/SEGGER/Config
  ${THIRD_PARTY_DIR}/SEGGER/OS
  ${THIRD_PARTY_DIR}/SEGGER/Patch
  ${THIRD_PARTY_DIR}/SEGGER/SEGGER
)

#Files to include
set(PROJECT_FILES
  ${APP_DIR}/stats/stats.cpp
  ${PROJECT_DIR}/App/userLed/taskUserLed.cpp
  ${PROJECT_DIR}/App/stats/taskStats.cpp
  ${PROJECT_DIR}/App/userButton/taskUserButton.cpp
  ${PROJECT_DIR}/main.cpp  
  ${PROJECT_DIR}/Bsp/gpio/gpio.cpp
  ${PROJECT_DIR}/Bsp/system/stm32f4xx_it.c
  ${PROJECT_DIR}/Bsp/system/system_stm32f4xx.c
  ${PROJECT_DIR}/Bsp/hal/stm32f4xx_hal_msp.c
  ${PROJECT_DIR}/Bsp/timer/timer.c
  ${PROJECT_DIR}/Bsp/usart/usart.c
  ${PROJECT_DIR}/Debug/debug.c
  ${PROJECT_DIR}/Debug/taskDebug.c
  ${PROJECT_DIR}/Startup/startup_stm32f429xx.s
  ${PROJECT_DIR}/Startup/Startup_Init.c
  ${THIRD_PARTY_DIR}/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_adc.c
  ${THIRD_PARTY_DIR}/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_hcd.c
  ${THIRD_PARTY_DIR}/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_ll_usb.c
  ${THIRD_PARTY_DIR}/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_crc.c
  ${THIRD_PARTY_DIR}/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_dma2d.c
  ${THIRD_PARTY_DIR}/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_ll_fmc.c
  ${THIRD_PARTY_DIR}/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_sdram.c
  ${THIRD_PARTY_DIR}/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_i2c.c
  ${THIRD_PARTY_DIR}/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_i2c_ex.c
  ${THIRD_PARTY_DIR}/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_ltdc.c
  ${THIRD_PARTY_DIR}/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_ltdc_ex.c
  ${THIRD_PARTY_DIR}/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_dsi.c
  ${THIRD_PARTY_DIR}/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_spi.c
  ${THIRD_PARTY_DIR}/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_tim.c
  ${THIRD_PARTY_DIR}/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_tim_ex.c
  ${THIRD_PARTY_DIR}/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_uart.c
  ${THIRD_PARTY_DIR}/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_rcc.c
  ${THIRD_PARTY_DIR}/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_rcc_ex.c
  ${THIRD_PARTY_DIR}/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_flash.c
  ${THIRD_PARTY_DIR}/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_flash_ex.c
  ${THIRD_PARTY_DIR}/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_flash_ramfunc.c
  ${THIRD_PARTY_DIR}/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_gpio.c
  ${THIRD_PARTY_DIR}/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_dma.c
  ${THIRD_PARTY_DIR}/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_pwr.c
  ${THIRD_PARTY_DIR}/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_pwr_ex.c
  ${THIRD_PARTY_DIR}/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_cortex.c
  ${THIRD_PARTY_DIR}/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal.c
  ${THIRD_PARTY_DIR}/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_exti.c
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
  ${THIRD_PARTY_DIR}/SEGGER/Config/SEGGER_SYSVIEW_Config_FreeRTOS.c
  ${THIRD_PARTY_DIR}/SEGGER/OS/SEGGER_SYSVIEW_FreeRTOS.c
  ${THIRD_PARTY_DIR}/SEGGER/SEGGER/SEGGER_RTT_ASM_ARMv7M.S
  ${THIRD_PARTY_DIR}/SEGGER/SEGGER/SEGGER_RTT_printf.c
  ${THIRD_PARTY_DIR}/SEGGER/SEGGER/SEGGER_RTT.c
  ${THIRD_PARTY_DIR}/SEGGER/SEGGER/SEGGER_SYSVIEW.c
)

#set additional settings
#set_property(SOURCE ${STARTUP_DIR}/startup_stm32f429xx.s PROPERTY LANGUAGE C)
set_property(SOURCE ${THIRD_PARTY_DIR}/SEGGER/SEGGER/SEGGER_RTT_ASM_ARMv7M.S PROPERTY LANGUAGE C)
#set additional information
set(TARGET_DEBUGER STLINK)