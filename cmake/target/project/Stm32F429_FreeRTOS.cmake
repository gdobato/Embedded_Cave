#Compiler settings
set(PROJECT_CDEFS "-DSTM32F429xx")
set(PROJECT_CPU_FLAGS "-mcpu=cortex-m4 -specs=nano.specs -specs=nosys.specs")        
set(PROJECT_FPU_FLAGS "-mfpu=fpv4-sp-d16 -mfloat-abi=hard")        
set(PROJECT_LINKER_SCRIPT_FILE "STM32F429ZITx_FLASH.ld ")        

#Specific project paths
set(DRIVER_BAREMETAL_DIR     ${DRIVER_DIR}/STM32F4xx_BAREMETAL_Driver)
set(DRIVER_HAL_DIR           ${DRIVER_DIR}/STM32F4xx_HAL_Driver)

#Paths to include
include_directories(${BSP_DIR}/hal)
include_directories(${PROJECT_DIR}/Os)
include_directories(${CMSIS_DIR}/Device/ST/STM32F4xx/Include)
include_directories(${CMSIS_DIR}/Include)
include_directories(${DRIVER_HAL_DIR}/Inc)
include_directories(${DRIVER_BAREMETAL_DIR}/Inc)
include_directories(${FREERTOS_DIR}/Source/CMSIS_RTOS)
include_directories(${FREERTOS_DIR}/Source/include)
include_directories(${FREERTOS_DIR}/Source/portable/GCC/ARM_CM4F)

#Files to include
set(PROJECT_FILES
  ${STARTUP_DIR}/startup_stm32f429xx.s
  ${STARTUP_DIR}/Startup_Init.c
  ${PROJECT_DIR}/main.c
  ${DRIVER_BAREMETAL_DIR}/Src/stm32f4xx_BareMetal_spi.c
  ${DRIVER_HAL_DIR}/Src/stm32f4xx_hal_adc.c
  ${DRIVER_HAL_DIR}/Src/stm32f4xx_hal_hcd.c
  ${DRIVER_HAL_DIR}/Src/stm32f4xx_ll_usb.c
  ${DRIVER_HAL_DIR}/Src/stm32f4xx_hal_crc.c
  ${DRIVER_HAL_DIR}/Src/stm32f4xx_hal_dma2d.c
  ${DRIVER_HAL_DIR}/Src/stm32f4xx_ll_fmc.c
  ${DRIVER_HAL_DIR}/Src/stm32f4xx_hal_sdram.c
  ${DRIVER_HAL_DIR}/Src/stm32f4xx_hal_i2c.c
  ${DRIVER_HAL_DIR}/Src/stm32f4xx_hal_i2c_ex.c
  ${DRIVER_HAL_DIR}/Src/stm32f4xx_hal_ltdc.c
  ${DRIVER_HAL_DIR}/Src/stm32f4xx_hal_ltdc_ex.c
  ${DRIVER_HAL_DIR}/Src/stm32f4xx_hal_dsi.c
  ${DRIVER_HAL_DIR}/Src/stm32f4xx_hal_spi.c
  ${DRIVER_HAL_DIR}/Src/stm32f4xx_hal_tim.c
  ${DRIVER_HAL_DIR}/Src/stm32f4xx_hal_tim_ex.c
  ${DRIVER_HAL_DIR}/Src/stm32f4xx_hal_uart.c
  ${DRIVER_HAL_DIR}/Src/stm32f4xx_hal_rcc.c
  ${DRIVER_HAL_DIR}/Src/stm32f4xx_hal_rcc_ex.c
  ${DRIVER_HAL_DIR}/Src/stm32f4xx_hal_flash.c
  ${DRIVER_HAL_DIR}/Src/stm32f4xx_hal_flash_ex.c
  ${DRIVER_HAL_DIR}/Src/stm32f4xx_hal_flash_ramfunc.c
  ${DRIVER_HAL_DIR}/Src/stm32f4xx_hal_gpio.c
  ${DRIVER_HAL_DIR}/Src/stm32f4xx_hal_dma.c
  ${DRIVER_HAL_DIR}/Src/stm32f4xx_hal_pwr.c
  ${DRIVER_HAL_DIR}/Src/stm32f4xx_hal_pwr_ex.c
  ${DRIVER_HAL_DIR}/Src/stm32f4xx_hal_cortex.c
  ${DRIVER_HAL_DIR}/Src/stm32f4xx_hal.c
  ${DRIVER_HAL_DIR}/Src/stm32f4xx_hal_exti.c
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
  ${DEBUG_DIR}/debug.c
  ${DEBUG_DIR}/debugThread.c
  ${BSP_DIR}/system/stm32f4xx_it.c
  ${BSP_DIR}/system/system_stm32f4xx.c
  ${BSP_DIR}/hal/stm32f4xx_hal_msp.c
  ${BSP_DIR}/adc/adc.c
  ${BSP_DIR}/crc/crc.c
  ${BSP_DIR}/dma/dma.c
  ${BSP_DIR}/fmc/fmc.c
  ${BSP_DIR}/gpio/gpio.c
  ${BSP_DIR}/i2c/i2c.c
  ${BSP_DIR}/ltdc/ltdc.c
  ${BSP_DIR}/spi/spi.c
  ${BSP_DIR}/timer/timer.c
  ${BSP_DIR}/usart/usart.c
  ${APP_DIR}/led/led.cpp
  ${APP_DIR}/led/ledThread.cpp
)

#set additional settings
set_property(SOURCE ${STARTUP_DIR}/startup_stm32f429xx.s PROPERTY LANGUAGE C)

#set additional information
set(TARGET_DEBUGER STLINK)