#
# Main project cmake file
#  
# Author: Gabriel Dobato  dobatog@gmail.com 
# Author: Jenifer Blanco  jenifer_blanco@hotmail.com
#
#
cmake_minimum_required (VERSION 3.6)
project (${PROJECT} C CXX ASM)

#Includes
include(../utils.cmake)
include(../config.cmake)
include(../genpaths.cmake)
include(project/${PROJECT}.cmake)

# Toochain / preprocessor Flags
set(DEFAULT_FLAGS           "-O0 -g -Wall -ffunction-sections -fdata-sections")   
set(C_DEFS                  ${PROJECT_CDEFS}) 
set(CPU_FLAGS               ${PROJECT_CPU_FLAGS})        
set(FPU_FLAGS               ${PROJECT_FPU_FLAGS})        
set(MCU_FLAGS              "${CPU_FLAGS} ${FPU_FLAGS} ${FLOAT_ABI_FLAGS} -mthumb")        
set(CMAKE_C_FLAGS          "${DEFAULT_FLAGS} ${MCU_FLAGS} ${C_DEFS}" )
set(CMAKE_CXX_FLAGS        "${CMAKE_C_FLAGS} -fno-exceptions -fno-rtti")
set(CMAKE_EXE_LINKER_FLAGS "-T${STARTUP_DIR}/${PROJECT_LINKER_SCRIPT_FILE} -Wl,-Map=${DEPLOY_DIR}/${PROJECT}.map,--gc-sections ")

#Generic include directories
#Project Squeleton include
include_directories(${APP_DIR})
include_directories(${BSW_DIR})
include_directories(${CONFIG_DIR})
include_directories(${DEBUG_DIR})
include_directories(${STARTUP_DIR})

#Output Files
#Elf File
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${DEPLOY_DIR})
#set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${DEPLOY_DIR})
#set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${DEPLOY_DIR})
add_executable(${PROJECT}.elf      ${PROJECT_FILES})

#Additional output formats
add_custom_command(TARGET ${PROJECT}.elf POST_BUILD  COMMAND ${OBJCOPY}       -Oihex            ${DEPLOY_DIR}/${PROJECT}.elf    ${DEPLOY_DIR}/${PROJECT}.hex)
add_custom_command(TARGET ${PROJECT}.elf POST_BUILD  COMMAND ${OBJCOPY}       -Obinary          ${DEPLOY_DIR}/${PROJECT}.elf    ${DEPLOY_DIR}/${PROJECT}.bin)
add_custom_command(TARGET ${PROJECT}.elf POST_BUILD  COMMAND ${OBJDUMP}       -d                ${DEPLOY_DIR}/${PROJECT}.elf  > ${DEPLOY_DIR}/${PROJECT}.disa )
add_custom_command(TARGET ${PROJECT}.elf POST_BUILD  COMMAND ${SIZE}          --format=berkeley ${DEPLOY_DIR}/${PROJECT}.elf)

#Log target info
file(WRITE   ${BUILD_DIR}/target/target.info "${PROJECT} \n")
file(APPEND  ${BUILD_DIR}/target/target.info "${TARGET_DEBUGER} \n")




