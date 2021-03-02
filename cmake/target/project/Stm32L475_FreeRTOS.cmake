#Compiler settings
set(PROJECT_CDEFS "-DSTM32L475xx")
set(PROJECT_CPU_FLAGS "-mcpu=cortex-m4 -specs=nano.specs -specs=nosys.specs")        
set(PROJECT_FPU_FLAGS "-mfpu=fpv4-sp-d16 -mfloat-abi=hard")        
set(PROJECT_LINKER_SCRIPT_FILE "${PROJECT_DIR}/Startup/STM32L475VGTx_FLASH.ld ")        
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
  ${THIRD_PARTY_DIR}/CMSIS/Device/ST/STM32L4xx/Include
  ${THIRD_PARTY_DIR}/CMSIS/Include
  ${THIRD_PARTY_DIR}/CMSIS/Include
  ${THIRD_PARTY_DIR}/Drivers/STM32L4xx_HAL_Driver/Inc
  ${THIRD_PARTY_DIR}/Middleware/BlueNRG-MS/includes
  ${THIRD_PARTY_DIR}/Middleware/BlueNRG-MS/utils
  ${THIRD_PARTY_DIR}/Middleware/BlueNRG-MS/hci/hci_tl_patterns/Basic
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
  ${APP_DIR}/ble/ble_server_legacy.c
  ${APP_DIR}/ble/ble_uuid.cpp
  ${APP_DIR}/stats/stats.cpp
  ${BSP_DIR}/hal/hal_base.cpp
  ${PROJECT_DIR}/App/ble/ble_server_task.cpp
  ${PROJECT_DIR}/App/user_led/task_user_led.cpp
  ${PROJECT_DIR}/App/stats/task_stats.cpp
  ${PROJECT_DIR}/Bsp/gpio/gpio.cpp
  ${PROJECT_DIR}/Bsp/ble/ble_hci.cpp
  ${PROJECT_DIR}/Bsp/ble/b_l475e_iot01a1_bus.c
  ${PROJECT_DIR}/Bsp/ble/hci_tl_interface.c
  ${PROJECT_DIR}/Bsp/hal/stm32l4xx_hal_msp.c
  ${PROJECT_DIR}/Bsp/system/stm32l4xx_it.c
  ${PROJECT_DIR}/Bsp/system/system_stm32l4xx.c
  ${PROJECT_DIR}/Bsp/timer/timer.c
  ${PROJECT_DIR}/Bsp/usart/usart.c
  ${PROJECT_DIR}/Debug/debug.c
  ${PROJECT_DIR}/Debug/task_debug.c
  ${PROJECT_DIR}/Startup/startup_stm32l475xx.s
  ${PROJECT_DIR}/Startup/Startup_Init.c
  ${PROJECT_DIR}/main.cpp
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
  ${THIRD_PARTY_DIR}/Drivers/STM32L4xx_HAL_Driver/Src/stm32l4xx_hal_dma.c
  ${THIRD_PARTY_DIR}/Drivers/STM32L4xx_HAL_Driver/Src/stm32l4xx_hal_exti.c
  ${THIRD_PARTY_DIR}/Drivers/STM32L4xx_HAL_Driver/Src/stm32l4xx_hal_gpio.c
  ${THIRD_PARTY_DIR}/Drivers/STM32L4xx_HAL_Driver/Src/stm32l4xx_hal_pwr.c
  ${THIRD_PARTY_DIR}/Drivers/STM32L4xx_HAL_Driver/Src/stm32l4xx_hal_pwr_ex.c
  ${THIRD_PARTY_DIR}/Drivers/STM32L4xx_HAL_Driver/Src/stm32l4xx_hal_rcc.c
  ${THIRD_PARTY_DIR}/Drivers/STM32L4xx_HAL_Driver/Src/stm32l4xx_hal_rcc_ex.c
  ${THIRD_PARTY_DIR}/Drivers/STM32L4xx_HAL_Driver/Src/stm32l4xx_hal_spi.c
  ${THIRD_PARTY_DIR}/Drivers/STM32L4xx_HAL_Driver/Src/stm32l4xx_hal_tim.c
  ${THIRD_PARTY_DIR}/Drivers/STM32L4xx_HAL_Driver/Src/stm32l4xx_hal_tim_ex.c
  ${THIRD_PARTY_DIR}/Drivers/STM32L4xx_HAL_Driver/Src/stm32l4xx_hal_uart.c
  ${THIRD_PARTY_DIR}/Middleware/BlueNRG-MS/hci/hci_tl_patterns/Basic/hci_tl.c
  ${THIRD_PARTY_DIR}/Middleware/BlueNRG-MS/hci/hci_le.c
  ${THIRD_PARTY_DIR}/Middleware/BlueNRG-MS/hci/controller/bluenrg_gap_aci.c
  ${THIRD_PARTY_DIR}/Middleware/BlueNRG-MS/hci/controller/bluenrg_gatt_aci.c
  ${THIRD_PARTY_DIR}/Middleware/BlueNRG-MS/hci/controller/bluenrg_hal_aci.c
  ${THIRD_PARTY_DIR}/Middleware/BlueNRG-MS/hci/controller/bluenrg_l2cap_aci.c
  ${THIRD_PARTY_DIR}/Middleware/BlueNRG-MS/hci/controller/bluenrg_updater_aci.c
  ${THIRD_PARTY_DIR}/Middleware/BlueNRG-MS/hci/controller/bluenrg_utils_small.c
  ${THIRD_PARTY_DIR}/Middleware/BlueNRG-MS/utils/ble_list.c
  ${THIRD_PARTY_DIR}/SEGGER/Config/SEGGER_SYSVIEW_Config_FreeRTOS.c
  ${THIRD_PARTY_DIR}/SEGGER/OS/SEGGER_SYSVIEW_FreeRTOS.c
  ${THIRD_PARTY_DIR}/SEGGER/SEGGER/SEGGER_RTT_ASM_ARMv7M.S
  ${THIRD_PARTY_DIR}/SEGGER/SEGGER/SEGGER_RTT_printf.c
  ${THIRD_PARTY_DIR}/SEGGER/SEGGER/SEGGER_RTT.c
  ${THIRD_PARTY_DIR}/SEGGER/SEGGER/SEGGER_SYSVIEW.c
)

#set additional settings
set_property(SOURCE ${THIRD_PARTY_DIR}/SEGGER/SEGGER/SEGGER_RTT_ASM_ARMv7M.S PROPERTY LANGUAGE C)
set_property(SOURCE ${PROJECT_DIR}/Startup/startup_stm32l475xx.s PROPERTY LANGUAGE C)

#set additional information
set(TARGET_DEBUGER STLINK)