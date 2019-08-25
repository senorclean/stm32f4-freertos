cmake_minimum_required(VERSION 3.6)
project (stm32f4 C CXX ASM)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY)
set(OBJCOPY arm-none-eabi-objcopy)

set(PROJ_DIR "${CMAKE_CURRENT_SOURCE_DIR}/../")
set(FREE_RTOS_DIR "${CMAKE_CURRENT_SOURCE_DIR}/../third_party/freertos")
set(SEGGER_DIR "${CMAKE_CURRENT_SOURCE_DIR}/../third_party/segger")
set(STARTUP_DIR "${CMAKE_CURRENT_SOURCE_DIR}/../startup")
set(LINKER_SCRIPT "${CMAKE_CURRENT_SOURCE_DIR}/../bin/stm32_flash.ld")

set(CORE_FLAGS "--specs=nosys.specs -mlittle-endian -mthumb -mcpu=cortex-m4 -mthumb-interwork -mfloat-abi=hard -mfpu=fpv4-sp-d16")

set(CMAKE_C_FLAGS "${CORE_FLAGS} -fno-builtin -Wall -std=gnu99 -fdata-sections -ffunction-sections -g -O2")
set(CMAKE_CXX_FLAGS "${CORE_FLAGS} -fno-rtti -fno-builtin -Wall -std=gnu++11 -fdata-sections -ffunction-sections -g -O0")
set(CMAKE_EXE_LINKER_FLAGS "-T ${LINKER_SCRIPT}")

#file(GLOB USER_SRCS "src/*.cpp")
set(USER_SRCS "${PROJ_DIR}/src/main.cpp")
file(GLOB USER_SRCS ${USER_SRCS} "${PROJ_DIR}/src/*.c")
set(RTOS_SRCS "${FREE_RTOS_DIR}/list.c")
set(RTOS_SRCS ${RTOS_SRCS} "${FREE_RTOS_DIR}/queue.c")
set(RTOS_SRCS ${RTOS_SRCS} "${FREE_RTOS_DIR}/tasks.c")
set(RTOS_SRCS ${RTOS_SRCS} "${FREE_RTOS_DIR}/timers.c")
set(RTOS_SRCS ${RTOS_SRCS} "${FREE_RTOS_DIR}/heap_4.c")
set(RTOS_SRCS ${RTOS_SRCS} "${FREE_RTOS_DIR}/port.c")
set(SEGGER_SRCS "${SEGGER_DIR}/SEGGER_SYSVIEW_Config_FreeRTOS.c")
set(SEGGER_SRCS ${SEGGER_SRCS} "${SEGGER_DIR}/SEGGER_SYSVIEW_FreeRTOS.c") 
set(SEGGER_SRCS ${SEGGER_SRCS} "${SEGGER_DIR}/SEGGER_RTT.c")
set(SEGGER_SRCS ${SEGGER_SRCS} "${SEGGER_DIR}/SEGGER_SYSVIEW.c")
set(STARTUP "${STARTUP_DIR}/startup_stm32f4xx.s")

include_directories(${PROJ_DIR}/inc 
                    ${PROJ_DIR}/inc/stm_lib
                    ${PROJ_DIR}/third_party/freertos
                    ${PROJ_DIR}/third_party/segger)

add_executable(${PROJECT_NAME}.elf ${USER_SRCS} ${RTOS_SRCS} ${SEGGER_SRCS} ${STARTUP})

add_custom_command(TARGET ${PROJECT_NAME}.elf POST_BUILD
  # build .hex and .bin files
  COMMAND ${OBJCOPY} -Oihex ${PROJECT_NAME}.elf ${PROJECT_NAME}.hex
  COMMAND ${OBJCOPY} -Obinary ${PROJECT_NAME}.elf ${PROJECT_NAME}.bin
  COMMENT "Building hex and bin files"
)

add_custom_target(flash
  COMMAND JLinkExe -if swd -device STM32F407VG -speed 4000 -autoconnect 1 -CommanderScript ${CMAKE_CURRENT_SOURCE_DIR}/program.jlink
  COMMENT "Flashing device"
)

add_custom_target(mr_clean
  COMMAND rm ${PROJECT_NAME}.*
  COMMAND rm CMakeCache.txt
  COMMAND rm -r CMakeFiles
  COMMAND rm -r cmake_install.cmake
  COMMENT "Cleaning build directory"
)