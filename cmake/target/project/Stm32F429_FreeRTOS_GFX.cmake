#Compiler settings
set(PROJECT_CDEFS "-DSTM32F429xx -DUSE_HAL_DRIVER")
set(PROJECT_CPU_FLAGS "-mcpu=cortex-m4 -specs=nano.specs -specs=nosys.specs")        
set(PROJECT_FPU_FLAGS "-mfpu=fpv4-sp-d16 -mfloat-abi=hard")        
set(PROJECT_LINKER_SCRIPT_FILE "${PROJECT_DIR}/Startup/STM32F429ZITx_FLASH.ld ")

#Specific project paths
set(DRIVER_BAREMETAL_DIR     ${DRIVER_DIR}/STM32F4xx_BAREMETAL_Driver)
set(DRIVER_HAL_DIR           ${DRIVER_DIR}/STM32F4xx_HAL_Driver)

#Paths to include
include_directories(${PROJECT_DIR})
include_directories(${PROJECT_DIR}/Core/Inc)
include_directories(${PROJECT_DIR}/TouchGFX/target)
include_directories(${PROJECT_DIR}/USB_HOST/App)
include_directories(${PROJECT_DIR}/USB_HOST/Target)
include_directories(${PROJECT_DIR}/TouchGFX/generated/fonts/include)
include_directories(${PROJECT_DIR}/TouchGFX/generated/texts/include)
include_directories(${PROJECT_DIR}/TouchGFX/generated/images/include)
include_directories(${PROJECT_DIR}/TouchGFX/generated/gui_generated/include)
include_directories(${PROJECT_DIR}/TouchGFX/gui/include)
include_directories(${PROJECT_DIR}/Middlewares/ST/TouchGFX/touchgfx/framework/include)
include_directories(${PROJECT_DIR}/Drivers/STM32F4xx_HAL_Driver/Inc)
include_directories(${PROJECT_DIR}/Drivers/STM32F4xx_HAL_Driver/Inc/Legacy)
include_directories(${PROJECT_DIR}/Middlewares/Third_Party/FreeRTOS/Source/include) 
include_directories(${PROJECT_DIR}/Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS) 
include_directories(${PROJECT_DIR}/Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM4F)
include_directories(${PROJECT_DIR}/Drivers/BSP/Components/exc7200) 
include_directories(${PROJECT_DIR}/Drivers/BSP/Components/stmpe811) 
include_directories(${PROJECT_DIR}/Drivers/BSP/Components/ts3510) 
include_directories(${PROJECT_DIR}/Drivers/BSP/Components/ili9341) 
include_directories(${PROJECT_DIR}/Middlewares/ST/STM32_USB_Host_Library/Core/Inc) 
include_directories(${PROJECT_DIR}/Middlewares/ST/STM32_USB_Host_Library/Class/CDC/Inc) 
include_directories(${PROJECT_DIR}/Drivers/BSP/Components/ampire480272) 
include_directories(${PROJECT_DIR}/Drivers/CMSIS/Device/ST/STM32F4xx/Include) 
include_directories(${PROJECT_DIR}/Drivers/BSP/Components/Common) 
include_directories(${PROJECT_DIR}/Drivers/CMSIS/Include)


#Files to include
set(PROJECT_FILES
  ${PROJECT_DIR}/Middlewares/ST/STM32_USB_Host_Library/Class/CDC/Src/usbh_cdc.c
  ${PROJECT_DIR}/Middlewares/ST/STM32_USB_Host_Library/Core/Src/usbh_core.c
  ${PROJECT_DIR}/Middlewares/ST/STM32_USB_Host_Library/Core/Src/usbh_ctlreq.c
  ${PROJECT_DIR}/Middlewares/ST/STM32_USB_Host_Library/Core/Src/usbh_ioreq.c
  ${PROJECT_DIR}/Middlewares/ST/STM32_USB_Host_Library/Core/Src/usbh_pipes.c
  ${PROJECT_DIR}/Middlewares/ST/TouchGFX/touchgfx/os/OSWrappers.cpp
  ${PROJECT_DIR}/Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS/cmsis_os.c
  ${PROJECT_DIR}/Middlewares/Third_Party/FreeRTOS/Source/croutine.c
  ${PROJECT_DIR}/Middlewares/Third_Party/FreeRTOS/Source/event_groups.c
  ${PROJECT_DIR}/Middlewares/Third_Party/FreeRTOS/Source/portable/MemMang/heap_4.c
  ${PROJECT_DIR}/Middlewares/Third_Party/FreeRTOS/Source/list.c
  ${PROJECT_DIR}/Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM4F/port.c
  ${PROJECT_DIR}/Middlewares/Third_Party/FreeRTOS/Source/queue.c
  ${PROJECT_DIR}/Middlewares/Third_Party/FreeRTOS/Source/tasks.c
  ${PROJECT_DIR}/Middlewares/Third_Party/FreeRTOS/Source/timers.c
  ${PROJECT_DIR}/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal.c
  ${PROJECT_DIR}/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_cortex.c
  ${PROJECT_DIR}/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_crc.c
  ${PROJECT_DIR}/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_dma.c
  ${PROJECT_DIR}/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_dma2d.c
  ${PROJECT_DIR}/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_dma_ex.c
  ${PROJECT_DIR}/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_dsi.c
  ${PROJECT_DIR}/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_flash.c
  ${PROJECT_DIR}/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_flash_ex.c
  ${PROJECT_DIR}/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_flash_ramfunc.c
  ${PROJECT_DIR}/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_gpio.c
  ${PROJECT_DIR}/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_hcd.c
  ${PROJECT_DIR}/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_i2c.c
  ${PROJECT_DIR}/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_i2c_ex.c
  ${PROJECT_DIR}/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_ltdc.c
  ${PROJECT_DIR}/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_ltdc_ex.c
  ${PROJECT_DIR}/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_pwr.c
  ${PROJECT_DIR}/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_pwr_ex.c
  ${PROJECT_DIR}/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_rcc.c
  ${PROJECT_DIR}/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_rcc_ex.c
  ${PROJECT_DIR}/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_sdram.c
  ${PROJECT_DIR}/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_spi.c
  ${PROJECT_DIR}/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_tim.c
  ${PROJECT_DIR}/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_tim_ex.c
  ${PROJECT_DIR}/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_ll_fmc.c
  ${PROJECT_DIR}/Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_ll_usb.c
  ${PROJECT_DIR}/Drivers/BSP/Components/exc7200/exc7200.c
  ${PROJECT_DIR}/Drivers/BSP/Components/ili9341/ili9341.c
  ${PROJECT_DIR}/Drivers/BSP/Components/ili9341/ili9341.c
  ${PROJECT_DIR}/Drivers/BSP/Components/stmpe811/stmpe811.c
  ${PROJECT_DIR}/Drivers/BSP/Components/ts3510/ts3510.c
  ${PROJECT_DIR}/USB_HOST/App/usb_host.c
  ${PROJECT_DIR}/USB_HOST/Target/usbh_conf.c
  ${PROJECT_DIR}/USB_HOST/Target/usbh_platform.c
  ${PROJECT_DIR}/TouchGFX/target/BoardConfiguration.cpp
  ${PROJECT_DIR}/TouchGFX/target/GPIO.cpp
  ${PROJECT_DIR}/TouchGFX/target/HW_Init.cpp
  ${PROJECT_DIR}/TouchGFX/target/STM32F4DMA.cpp
  ${PROJECT_DIR}/TouchGFX/target/STM32F4HAL.cpp
  ${PROJECT_DIR}/TouchGFX/target/STM32F4Instrumentation.cpp
  ${PROJECT_DIR}/TouchGFX/target/STM32F4TouchController.cpp
  ${PROJECT_DIR}/TouchGFX/gui/src/screen1_screen/Screen1Presenter.cpp
  ${PROJECT_DIR}/TouchGFX/gui/src/screen1_screen/Screen1View.cpp
  ${PROJECT_DIR}/TouchGFX/gui/src/model/Model.cpp
  ${PROJECT_DIR}/TouchGFX/gui/src/common/FrontendApplication.cpp
  ${PROJECT_DIR}/TouchGFX/generated/texts/src/LanguageGb.cpp
  ${PROJECT_DIR}/TouchGFX/gui/src/common/FrontendApplication.cpp
  ${PROJECT_DIR}/TouchGFX/generated/texts/src/Texts.cpp
  ${PROJECT_DIR}/TouchGFX/generated/texts/src/TypedTextDatabase.cpp
  ${PROJECT_DIR}/TouchGFX/generated/images/src/__designer/blue_togglebars_toggle_round_large_button_off.cpp
  ${PROJECT_DIR}/TouchGFX/generated/images/src/__designer/blue_togglebars_toggle_round_large_button_on.cpp
  ${PROJECT_DIR}/TouchGFX/generated/images/src/BitmapDatabase.cpp
  ${PROJECT_DIR}/TouchGFX/generated/images/src/peabody.cpp
  ${PROJECT_DIR}/TouchGFX/generated/gui_generated/src/screen1_screen/Screen1ViewBase.cpp
  ${PROJECT_DIR}/TouchGFX/generated/gui_generated/src/common/FrontendApplicationBase.cpp
  ${PROJECT_DIR}/TouchGFX/generated/fonts/src/ApplicationFontProvider.cpp
  ${PROJECT_DIR}/TouchGFX/generated/fonts/src/FontGetters.cpp
  ${PROJECT_DIR}/TouchGFX/generated/fonts/src/Font_verdana_10_4bpp.cpp
  ${PROJECT_DIR}/TouchGFX/generated/fonts/src/Font_verdana_20_4bpp.cpp
  ${PROJECT_DIR}/TouchGFX/generated/fonts/src/Font_verdana_40_4bpp.cpp
  ${PROJECT_DIR}/TouchGFX/generated/fonts/src/Kerning_verdana_10_4bpp.cpp
  ${PROJECT_DIR}/TouchGFX/generated/fonts/src/Kerning_verdana_20_4bpp.cpp
  ${PROJECT_DIR}/TouchGFX/generated/fonts/src/Kerning_verdana_40_4bpp.cpp
  ${PROJECT_DIR}/TouchGFX/generated/fonts/src/Table_verdana_10_4bpp.cpp
  ${PROJECT_DIR}/TouchGFX/generated/fonts/src/Table_verdana_20_4bpp.cpp
  ${PROJECT_DIR}/TouchGFX/generated/fonts/src/Table_verdana_40_4bpp.cpp
  ${PROJECT_DIR}/Core/Src/freertos.c
  ${PROJECT_DIR}/Core/Src/stm32f4xx_hal_msp.c
  ${PROJECT_DIR}/Core/Src/stm32f4xx_hal_timebase_tim.c
  ${PROJECT_DIR}/Core/Src/stm32f4xx_it.c
  ${PROJECT_DIR}/Core/Src/main.cpp
  ${PROJECT_DIR}/Core/Src/system_stm32f4xx.c
  ${PROJECT_DIR}/SW4STM32/syscalls.c
  ${PROJECT_DIR}/SW4STM32/SW4STM32_STM32F429i_DISCO/Application/User/TouchGFX/target/stm32f429i_discovery_ts.c
  ${PROJECT_DIR}/SW4STM32/SW4STM32_STM32F429i_DISCO/Application/User/TouchGFX/target/stm32f429i_discovery_io.c
  ${PROJECT_DIR}/SW4STM32/SW4STM32_STM32F429i_DISCO/Application/User/TouchGFX/target/stm32f429i_discovery.c
  ${PROJECT_DIR}/SW4STM32/startup_stm32f429xx.s

)

#set additional settings
set_property(SOURCE ${PROJECT_DIR}/SW4STM32/startup_stm32f429xx.s PROPERTY LANGUAGE C)
set(LIBRARIES 
  ${PROJECT_DIR}/Middlewares/ST/TouchGFX/touchgfx/lib/core/cortex_m4f/gcc/libtouchgfx-float-abi-hard.a
  ${PROJECT_DIR}/Middlewares/ST/TouchGFX/touchgfx/lib/linux/libtouchgfx.a
)
#set additional information
set(TARGET_DEBUGER STLINK)