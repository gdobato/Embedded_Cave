################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
/home/gdobato/Workspace/touchGFXTest/test3/SW4STM32_STM32F429i_DISCO/TouchGFX/gui/src/model/Model.cpp 

OBJS += \
./Application/User/TouchGFX/gui/model/Model.o 

CPP_DEPS += \
./Application/User/TouchGFX/gui/model/Model.d 


# Each subdirectory must supply rules for building sources it contributes
Application/User/TouchGFX/gui/model/Model.o: /home/gdobato/Workspace/touchGFXTest/test3/SW4STM32_STM32F429i_DISCO/TouchGFX/gui/src/model/Model.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: MCU G++ Compiler'
	@echo $(PWD)
	arm-none-eabi-g++ -mcpu=cortex-m4 -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 -I"/home/gdobato/Workspace/touchGFXTest/test3/SW4STM32_STM32F429i_DISCO/Core/Inc" -I"/home/gdobato/Workspace/touchGFXTest/test3/SW4STM32_STM32F429i_DISCO/TouchGFX/target" -I"/home/gdobato/Workspace/touchGFXTest/test3/SW4STM32_STM32F429i_DISCO/USB_HOST/App" -I"/home/gdobato/Workspace/touchGFXTest/test3/SW4STM32_STM32F429i_DISCO/USB_HOST/Target" -I"/home/gdobato/Workspace/touchGFXTest/test3/SW4STM32_STM32F429i_DISCO/TouchGFX/generated/fonts/include" -I"/home/gdobato/Workspace/touchGFXTest/test3/SW4STM32_STM32F429i_DISCO/TouchGFX/generated/texts/include" -I"/home/gdobato/Workspace/touchGFXTest/test3/SW4STM32_STM32F429i_DISCO/TouchGFX/generated/images/include" -I"/home/gdobato/Workspace/touchGFXTest/test3/SW4STM32_STM32F429i_DISCO/TouchGFX/generated/gui_generated/include" -I"/home/gdobato/Workspace/touchGFXTest/test3/SW4STM32_STM32F429i_DISCO/TouchGFX/gui/include" -I"/home/gdobato/Workspace/touchGFXTest/test3/SW4STM32_STM32F429i_DISCO/Middlewares/ST/TouchGFX/touchgfx/framework/include" -I"/home/gdobato/Workspace/touchGFXTest/test3/SW4STM32_STM32F429i_DISCO/Drivers/STM32F4xx_HAL_Driver/Inc" -I"/home/gdobato/Workspace/touchGFXTest/test3/SW4STM32_STM32F429i_DISCO/Drivers/STM32F4xx_HAL_Driver/Inc/Legacy" -I"/home/gdobato/Workspace/touchGFXTest/test3/SW4STM32_STM32F429i_DISCO/Middlewares/Third_Party/FreeRTOS/Source/include" -I"/home/gdobato/Workspace/touchGFXTest/test3/SW4STM32_STM32F429i_DISCO/Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS" -I"/home/gdobato/Workspace/touchGFXTest/test3/SW4STM32_STM32F429i_DISCO/Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM4F" -I"/home/gdobato/Workspace/touchGFXTest/test3/SW4STM32_STM32F429i_DISCO/Drivers/BSP/Components/exc7200" -I"/home/gdobato/Workspace/touchGFXTest/test3/SW4STM32_STM32F429i_DISCO/Drivers/BSP/Components/stmpe811" -I"/home/gdobato/Workspace/touchGFXTest/test3/SW4STM32_STM32F429i_DISCO/Drivers/BSP/Components/ts3510" -I"/home/gdobato/Workspace/touchGFXTest/test3/SW4STM32_STM32F429i_DISCO/Drivers/BSP/Components/ili9341" -I"/home/gdobato/Workspace/touchGFXTest/test3/SW4STM32_STM32F429i_DISCO/Middlewares/ST/STM32_USB_Host_Library/Core/Inc" -I"/home/gdobato/Workspace/touchGFXTest/test3/SW4STM32_STM32F429i_DISCO/Middlewares/ST/STM32_USB_Host_Library/Class/CDC/Inc" -I"/home/gdobato/Workspace/touchGFXTest/test3/SW4STM32_STM32F429i_DISCO/Drivers/BSP/Components/ampire480272" -I"/home/gdobato/Workspace/touchGFXTest/test3/SW4STM32_STM32F429i_DISCO/Drivers/CMSIS/Device/ST/STM32F4xx/Include" -I"/home/gdobato/Workspace/touchGFXTest/test3/SW4STM32_STM32F429i_DISCO/Drivers/BSP/Components/Common" -I"/home/gdobato/Workspace/touchGFXTest/test3/SW4STM32_STM32F429i_DISCO/Drivers/CMSIS/Include"  -Og -Wall -fmessage-length=0 -ffunction-sections -c -fno-exceptions -fno-rtti __weak=__attribute__((weak)) __packed=__attribute__((__packed__)) USE_HAL_DRIVER STM32F429xx USE_BPP=16 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


