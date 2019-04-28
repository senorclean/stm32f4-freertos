# Binaries will be generated with this name (.elf, .bin, .hex, etc)
PROJ_NAME := stm32f4

PROJ_ROOT := .
PROJ_SRC := ./src
OUT_DIR := _build
FREERTOS_DIR := ./third_party/FreeRTOSv10.1.1/FreeRTOS/Source
SEGGER_SYSVIEW_DIR := ./third_party/SEGGER
STFLASH := ./bin/st-flash

LINKER_SCRIPT := ./bin/stm32_flash.ld
STARTUP_FILE := ./startup/startup_stm32f4xx.s

# adds all .c files in current source directory
SRCS := $(wildcard $(PROJ_SRC)/*.c)

# add all FreeRTOS files
SRCS += $(FREERTOS_DIR)/list.c
SRCS += $(FREERTOS_DIR)/queue.c
SRCS += $(FREERTOS_DIR)/tasks.c
SRCS += $(FREERTOS_DIR)/timers.c
SRCS += $(FREERTOS_DIR)/portable/MemMang/heap_4.c
SRCS += $(FREERTOS_DIR)/portable/GCC/ARM_CM4F/port.c

# add all SEGGER files
SRCS += $(wildcard $(SEGGER_SYSVIEW_DIR)/Config/*.c)
SRCS += $(wildcard $(SEGGER_SYSVIEW_DIR)/OS/*.c)
SRCS += $(wildcard $(SEGGER_SYSVIEW_DIR)/SEGGER/*.c)

# The compiler
CC = arm-none-eabi-gcc
# Objcopy for generating the different binaries
OBJCOPY = arm-none-eabi-objcopy


# Meaning of all of these flags:
# -I: tells gcc to look in the directory immediately following the "I" for
# include files
# -L: same thing as above but for linker files
# -g: compile with debug information
# -O2: specifies that gcc should optimize the code (O0-O3)
# -Wall: gives verbose compiler warnings
# -T: specifies the following file as a linker script
# -m: used to specify hardware/hardware configurations
# 	- little-endian: specifies compiling code for little-endian config
# 	- thumb: generate code for 16-bit Thumb inst set
# 	- cpu=cortex-m4: processor type
# 	- thumb-interwork: generate code for both Thumb and ARM inst sets
# 	- float-abi=hard: generate code with floating point inst
# 	- fpu=fpv4-sp-d16: another floating point specification, too lazy to find
CFLAGS  = -g -O2 -Wall -T$(LINKER_SCRIPT)
CFLAGS += -mlittle-endian -mthumb -mcpu=cortex-m4 -mthumb-interwork
CFLAGS += -mfloat-abi=hard -mfpu=fpv4-sp-d16

# Include directories
CFLAGS += -I.
CFLAGS += -I./inc
CFLAGS += -I./inc/stm_lib
CFLAGS += -I./inc/util
CFLAGS += -I$(FREERTOS_DIR)/include
CFLAGS += -I$(FREERTOS_DIR)/portable/GCC/ARM_CM4F
CFLAGS += -I$(SEGGER_SYSVIEW_DIR)/Config
CFLAGS += -I$(SEGGER_SYSVIEW_DIR)/OS
CFLAGS += -I$(SEGGER_SYSVIEW_DIR)/SEGGER

# add startup file to build
SRCS += $(STARTUP_FILE)
OBJS = $(SRCS:.c=.o)

# Ensures that 'make' runs regardless is there is already a file named whatever
# proj is defined as 
.PHONY: proj

# "all" specifies the target when 'make' is run without arguments
all: proj

proj: $(OUT_DIR)/$(PROJ_NAME).elf

# $^: acts as a placeholder for all of the prerequisites used in the archive
# $@: acts as the name of the target in the archive
# -o: do not remake the file even if it is older than its prereqs

# -O: specifies the output target (here elf is src, hex or bin is dest)
$(OUT_DIR)/$(PROJ_NAME).elf: $(SRCS)
	@echo Building project
	@if [ ! -d $(OUT_DIR) ]; then \
		echo Creating build directory; \
		mkdir $(OUT_DIR); \
	fi
	@$(CC) $(CFLAGS) $^ -o $@ 
	@echo Generating extra binaries
	@$(OBJCOPY) -O ihex $@ $(OUT_DIR)/$(PROJ_NAME).hex
	@$(OBJCOPY) -O binary $@ $(OUT_DIR)/$(PROJ_NAME).bin
	@echo Done

# if 'make clean' is entered, all of these files are removed before
# it attempts to compile the program.
clean:
	rm -f $(addprefix $(OUT_DIR)/, *.elf *.hex *.bin)

# Flash the STM32F4
flash:
	@echo Programming device
	$(STFLASH) write $(OUT_DIR)/$(PROJ_NAME).bin 0x8000000
	$(STFLASH) --reset
	@echo Done

# Erase the STM32F4
erase:
	@echo Erasing device
	$(STFLASH) erase
	@echo Done

