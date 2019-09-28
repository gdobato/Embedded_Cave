set(CMAKE_SYSTEM_NAME STM32F4)
set(CMAKE_SYSTEM_PROCESSOR arm)


#set(TOOLCHAIN_PATH  "${CMAKE_SOURCE_DIR}/../tools/gcc-arm-none-eabi-8-2018-q4-major/bin")
#set(TOOLCHAIN_PATH  "${CMAKE_SOURCE_DIR}/../tools/gcc-arm-none-eabi-8-2018-q4-major/bin")
set(TOOLCHAIN_PATH  "/home/gdobato/workspace/MCUPlatform/Target/tools/gcc-arm-none-eabi-8-2018-q4-major/bin")

set(CMAKE_C_FLAGS "-O0 -g -Wall -ffunction-sections -fdata-sections")
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -DSTM32F042x6 -mcpu=cortex-m0 -mthumb")
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -mno-thumb-interwork -mfpu=vfp -msoft-float")
set(CMAKE_EXE_LINKER_FLAGS "-T../STM32F042K6Tx_FLASH.ld -Wl,--gc-section")

#set(CMAKE_C_COMPILER    ${TOOLCHAIN_PATH}/arm-none-eabi-gcc)
#set(CMAKE_CXX_COMPILER  ${TOOLCHAIN_PATH}/arm-none-eabi-g++)
set(CMAKE_FORCE_C_COMPILER    ${TOOLCHAIN_PATH}/arm-none-eabi-gcc)
set(CMAKE_FORCE_CXX_COMPILER  ${TOOLCHAIN_PATH}/arm-none-eabi-g++)
set(AS                  ${TOOLCHAIN_PATH}/arm-none-eabi-as)
set(AR                  ${TOOLCHAIN_PATH}/arm-none-eabi-ar)
set(OBJCOPY             ${TOOLCHAIN_PATH}/arm-none-eabi-objcopy)
set(OBJDUMP             ${TOOLCHAIN_PATH}/arm-none-eabi-objdump)
set(SIZE                ${TOOLCHAIN_PATH}/arm-none-eabi-size)
set(GDB                 ${TOOLCHAIN_PATH}/arm-none-eabi-gdb)
set(SIZE                ${TOOLCHAIN_PATH}/arm-none-eabi-size)


#set(CMAKE_FIND_ROOT_PATH_MODE_PROGRAM NEVER)
#set(CMAKE_FIND_ROOT_PATH_MODE_LIBRARY ONLY)
#set(CMAKE_FIND_ROOT_PATH_MODE_INCLUDE ONLY)
#set(CMAKE_FIND_ROOT_PATH_MODE_PACKAGE ONLY)


