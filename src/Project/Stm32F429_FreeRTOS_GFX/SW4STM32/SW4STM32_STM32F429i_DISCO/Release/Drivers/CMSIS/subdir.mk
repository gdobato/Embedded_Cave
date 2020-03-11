################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
/home/gdobato/Workspace/touchGFXTest/test3/SW4STM32_STM32F429i_DISCO/Core/Src/system_stm32f4xx.c 

OBJS += \
./Drivers/CMSIS/system_stm32f4xx.o 

C_DEPS += \
./Drivers/CMSIS/system_stm32f4xx.d 


# Each subdirectory must supply rules for building sources it contributes
Drivers/CMSIS/system_stm32f4xx.o: /home/gdobato/Workspace/touchGFXTest/test3/SW4STM32_STM32F429i_DISCO/Core/Src/system_stm32f4xx.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU GCC Compiler'
	@echo $(PWD)
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 '-D__weak=__attribute__((weak))' '-D__packed=__attribute__((__packed__))' -DUSE_HAL_DRIVER -DSTM32F429xx '-DUSE_BPP=16' -I"/home/gdobato/Workspace/touchGFXTest/test3/SW4STM32_STM32F429i_DISCO/Core/Inc" -I"/home/gdobato/Workspace/touchGFXTest/test3/SW4STM32_STM32F429i_DISCO/TouchGFX/target" -I"/home/gdobato/Workspace/touchGFXTest/test3/SW4STM32_STM32F429i_DISCO/USB_HOST/App" -I"/home/gdobato/Workspace/touchGFXTest/test3/SW4STM32_STM32F429i_DISCO/USB_HOST/Target" -I"/home/gdobato/Workspace/touchGFXTest/test3/SW4STM32_STM32F429i_DISCO/TouchGFX/generated/fonts/include" -I"/home/gdobato/Workspace/touchGFXTest/test3/SW4STM32_STM32F429i_DISCO/TouchGFX/generated/texts/include" -I"/home/gdobato/Workspace/touchGFXTest/test3/SW4STM32_STM32F429i_DISCO/TouchGFX/generated/images/include" -I"/home/gdobato/Workspace/touchGFXTest/test3/SW4STM32_STM32F429i_DISCO/TouchGFX/generated/gui_generated/include" -I"/home/gdobato/Workspace/touchGFXTest/test3/SW4STM32_STM32F429i_DISCO/TouchGFX/gui/include" -I"/home/gdobato/Workspace/touchGFXTest/test3/SW4STM32_STM32F429i_DISCO/Middlewares/ST/TouchGFX/touchgfx/framework/include" -I"/home/gdobato/Workspace/touchGFXTest/test3/SW4STM32_STM32F429i_DISCO/Drivers/STM32F4xx_HAL_Driver/Inc" -I"/home/gdobato/Workspace/touchGFXTest/test3/SW4STM32_STM32F429i_DISCO/Drivers/STM32F4xx_HAL_Driver/Inc/Legacy" -I"/home/gdobato/Workspace/touchGFXTest/test3/SW4STM32_STM32F429i_DISCO/Middlewares/Third_Party/FreeRTOS/Source/include" -I"/home/gdobato/Workspace/touchGFXTest/test3/SW4STM32_STM32F429i_DISCO/Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS" -I"/home/gdobato/Workspace/touchGFXTest/test3/SW4STM32_STM32F429i_DISCO/Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM4F" -I"/home/gdobato/Workspace/touchGFXTest/test3/SW4STM32_STM32F429i_DISCO/Drivers/BSP/Components/exc7200" -I"/home/gdobato/Workspace/touchGFXTest/test3/SW4STM32_STM32F429i_DISCO/Drivers/BSP/Components/stmpe811" -I"/home/gdobato/Workspace/touchGFXTest/test3/SW4STM32_STM32F429i_DISCO/Drivers/BSP/Components/ts3510" -I"/home/gdobato/Workspace/touchGFXTest/test3/SW4STM32_STM32F429i_DISCO/Drivers/BSP/Components/ili9341" -I"/home/gdobato/Workspace/touchGFXTest/test3/SW4STM32_STM32F429i_DISCO/Middlewares/ST/STM32_USB_Host_Library/Core/Inc" -I"/home/gdobato/Workspace/touchGFXTest/test3/SW4STM32_STM32F429i_DISCO/Middlewares/ST/STM32_USB_Host_Library/Class/CDC/Inc" -I"/home/gdobato/Workspace/touchGFXTest/test3/SW4STM32_STM32F429i_DISCO/Drivers/BSP/Components/ampire480272" -I"/home/gdobato/Workspace/touchGFXTest/test3/SW4STM32_STM32F429i_DISCO/Drivers/CMSIS/Device/ST/STM32F4xx/Include" -I"/home/gdobato/Workspace/touchGFXTest/test3/SW4STM32_STM32F429i_DISCO/Drivers/BSP/Components/Common" -I"/home/gdobato/Workspace/touchGFXTest/test3/SW4STM32_STM32F429i_DISCO/Drivers/CMSIS/Include"  -Og -g3 -Wall -fmessage-length=0 -ffunction-sections -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


