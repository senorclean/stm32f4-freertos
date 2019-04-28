cmake_minimum_required(VERSION 2.8.12)
project (stm32f4.elf C CXX)

set(CORE_FLAGS "--specs=nosys.specs -mlittle-endian -mthumb -mcpu=cortex-m4 -mthumb-interwork -mfloat-abi=hard -mfpu=fpv4-sp-d16")

set(CMAKE_C_FLAGS "${CORE_FLAGS} -fno-builtin -Wall -std=gnu99 -fdata-sections -ffunction-sections -g -O2")
set(CMAKE_CXX_FLAGS "${CORE_FLAGS} -fno-builtin -Wall -std=gnu++11 -fdata-sections -ffunction-sections -g -O2")
set(CMAKE_EXE_LINKER_FLAGS "-T${PROJECT_SOURCE_DIR}/bin/stm32_flash.ld")

set(SRCS src/main.cpp
         src/system_stm32f4xx.c
         third_party/FreeRTOSv10.1.1/FreeRTOS/Source/list.c
         third_party/FreeRTOSv10.1.1/FreeRTOS/Source/queue.c
         third_party/FreeRTOSv10.1.1/FreeRTOS/Source/tasks.c
         third_party/FreeRTOSv10.1.1/FreeRTOS/Source/timers.c
         third_party/FreeRTOSv10.1.1/FreeRTOS/Source/portable/MemMang/heap_4.c
         third_party/FreeRTOSv10.1.1/FreeRTOS/Source/portable/GCC/ARM_CM4F/port.c
         third_party/SEGGER/Config/SEGGER_SYSVIEW_Config_FreeRTOS.c
         third_party/SEGGER/OS/SEGGER_SYSVIEW_FreeRTOS.c
         third_party/SEGGER/SEGGER/SEGGER_RTT.c
         third_party/SEGGER/SEGGER/SEGGER_SYSVIEW.c
         startup/startup_stm32f4xx.s)

add_executable(stm32f4.elf ${SRCS})

target_compile_definitions(stm32f4.elf PUBLIC STM32F40_41xxx)

target_include_directories(stm32f4.elf PUBLIC inc
                    inc/stm_lib
                    inc/util
                    third_party/FreeRTOSv10.1.1/FreeRTOS/Source/include
                    third_party/FreeRTOSv10.1.1/FreeRTOS/Source/portable/GCC/ARM_CM4F
                    third_party/SEGGER/Config
                    third_party/SEGGER/OS
                    third_party/SEGGER/SEGGER)

#target_compile_options(stm32f4.elf PUBLIC --specs=nosys.specs -mlittle-endian -mthumb -mcpu=cortex-m4 -mthumb-interwork -mfloat-abi=hard -mfpu=fpv4-sp-d16)

# external libraries
# target_link_libraries(stm32f4.elf -lc -lnosys)

add_custom_command(TARGET "stm32f4.elf" POST_BUILD
  # build .hex and .bin files
  COMMAND arm-none-eabi-objcopy -Oihex stm32f4.elf stm32f4.hex
  COMMAND arm-none-eabi-objcopy -Obinary stm32f4.elf stm32f4.bin
  COMMENT "Building hex and bin files"
  )

# file(GLOB SRCS "src/*.c")