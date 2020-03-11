################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include Middlewares/USB_Host_Library/subdir.mk
-include Middlewares/TouchGFX/subdir.mk
-include Middlewares/FreeRTOS/subdir.mk
-include Drivers/STM32F4xx_HAL_Driver/subdir.mk
-include Drivers/CMSIS/subdir.mk
-include Drivers/BSP/Components/subdir.mk
-include Application/User/USB_Host_Library/Target/subdir.mk
-include Application/User/USB_Host_Library/App/subdir.mk
-include Application/User/TouchGFX/target/subdir.mk
-include Application/User/TouchGFX/gui/screen1_screen/subdir.mk
-include Application/User/TouchGFX/gui/model/subdir.mk
-include Application/User/TouchGFX/gui/common/subdir.mk
-include Application/User/TouchGFX/generated/texts/subdir.mk
-include Application/User/TouchGFX/generated/images/__designer/subdir.mk
-include Application/User/TouchGFX/generated/images/subdir.mk
-include Application/User/TouchGFX/generated/gui_generated/screen1_screen/subdir.mk
-include Application/User/TouchGFX/generated/gui_generated/common/subdir.mk
-include Application/User/TouchGFX/generated/fonts/subdir.mk
-include Application/User/Core/subdir.mk
-include Application/SW4STM32/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(CC_DEPS)),)
-include $(CC_DEPS)
endif
ifneq ($(strip $(C++_DEPS)),)
-include $(C++_DEPS)
endif
ifneq ($(strip $(C_UPPER_DEPS)),)
-include $(C_UPPER_DEPS)
endif
ifneq ($(strip $(CXX_DEPS)),)
-include $(CXX_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
ifneq ($(strip $(CPP_DEPS)),)
-include $(CPP_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 

# All Target
all: SW4STM32_STM32F429i_DISCO.elf

# Tool invocations
SW4STM32_STM32F429i_DISCO.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: MCU G++ Linker'
	arm-none-eabi-g++ -mcpu=cortex-m4 -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 -L"/home/gdobato/Workspace/touchGFXTest/test3/SW4STM32_STM32F429i_DISCO/Middlewares/ST/TouchGFX/touchgfx/lib/core/cortex_m4f/gcc"  -specs=nosys.specs -specs=nano.specs -T"../STM32F429ZITx_FLASH.ld" -Wl,-Map=output.map -Wl,--gc-sections -fno-exceptions -fno-rtti -o "SW4STM32_STM32F429i_DISCO.elf" @"objects.list" $(USER_OBJS) $(LIBS) -lm
	@echo 'Finished building target: $@'
	@echo ' '
	$(MAKE) --no-print-directory post-build

# Other Targets
clean:
	-$(RM) *
	-@echo ' '

post-build:
	-@echo 'Generating hex and Printing size information:'
	arm-none-eabi-objcopy -O ihex "SW4STM32_STM32F429i_DISCO.elf" "SW4STM32_STM32F429i_DISCO.hex"
	arm-none-eabi-size "SW4STM32_STM32F429i_DISCO.elf"
	-@echo ' '

.PHONY: all clean dependents
.SECONDARY: post-build

-include ../makefile.targets
