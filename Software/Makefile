# Package definitions
export FREERTOS = Packages/FreeRTOS/FreeRTOS/
export DRIVERLIB = Packages/driverlib/
export OPUS = Packages/opus/

# Compiler/Toolchain definitions
TOOLCHAIN ?= arm-none-eabi-
export OBJCOPY=$(TOOLCHAIN)objcopy
export CC=$(TOOLCHAIN)gcc
export CXX=$(TOOLCHAIN)g++
export AS=$(TOOLCHAIN)gcc

# Include definitions
CFLAGS += -I$(FREERTOS) -I$(FREERTOS)/Source/include/ -I$(FREERTOS)/Source/portable/GCC/ARM_CM4F/
CFLAGS += $(addprefix -I$(OPUS), include silk celt silk/fixed)
CFLAGS += -I. -IPackages/ -ISystem/
# GC sections
CFLAGS += -ffunction-sections -fdata-sections -ffreestanding -Og
CFLAGS += -ggdb -pipe
# libopus configuration
CFLAGS += -DFIXED_POINT -DDISABLE_FLOAT_API -DHAVE_LRINTF -DNONTHREADSAFE_PSEUDOSTACK -DOVERRIDE_OPUS_ALLOC_SCRATCH -DOPUS_BUILD -DOPUS_ARM_MAY_HAVE_EDSP -DOPUS_ARM_MAY_HAVE_MEDIA -DOPUS_ARM_PRESUME_EDSP

include $(OPUS)/celt_sources.mk
include $(OPUS)/opus_sources.mk
include $(OPUS)/silk_sources.mk
export ASFLAGS = -DOPUS_ARM_MAY_HAVE_EDSP=1 -DOPUS_ARM_MAY_HAVE_MEDIA=1 -DOPUS_ARM_PRESUME_EDSP=1 -DOPUS_ARM_MAY_HAVE_NEON=0
%-gnu.S: %.s
	perl Packages/opus/celt/arm/arm2gnu.pl < $< > $@

# Packages/opus/celt/arm/celt_pitch_xcorr_arm-gnu.S: Packages/opus/celt/arm/armopts-gnu.S
# 	perl Packages/opus/celt/arm/arm2gnu.pl < $< > $@

CELT_SOURCES_ARM_ASM_GNU = $(patsubst %.s, %-gnu.S, $(addprefix $(OPUS), $(CELT_SOURCES_ARM_ASM)))

LIBOPUS_SOURCES = $(CELT_SOURCES_ARM_ASM_GNU) $(addprefix $(OPUS), $(CELT_SOURCES) $(OPUS_SOURCES) $(SILK_SOURCES) $(SILK_SOURCES_FIXED))


WIFILMR_SOURCES = main.cpp \
	System/HAL/clock.cpp \
	System/HAL/lpuart.cpp \
	System/HAL/util.c \
    System/initialization.c \
    System/interrupt_table.c \
	System/logging.cpp

FREERTOS_SOURCES := croutine.c \
    event_groups.c \
    list.c \
    queue.c \
    tasks.c \
    timers.c \
    portable/GCC/ARM_CM4F/port.c \
    portable/MemMang/heap_4.c

FREERTOS_SOURCES := $(addprefix $(FREERTOS)/Source/, $(FREERTOS_SOURCES))

PROJECT_SOURCES = $(WIFILMR_SOURCES) $(LIBOPUS_SOURCES) $(FREERTOS_SOURCES)

#libproject.a: $(libproject_a_SOURCES)
#find . -name *.o | xargs $(AR) rcs libproject.a 

export MACHINE=armv7e-m
CFLAGS += -march=$(MACHINE) -mcpu=cortex-m4 -mfloat-abi=hard -mfpu=fpv4-sp-d16
CXXFLAGS = $(CFLAGS) -fno-exceptions -fno-rtti -std=c++17
all: main.bin

%.o: %.c Makefile
	$(CC) $(CFLAGS) -c $< -o $@ -MMD
%.o: %.cpp Makefile
	$(CXX) $(CXXFLAGS) -c $< -o $@ -MMD
clean:
	rm -vf main.bin*
	rm -vf project.elf*
	find . -name \*.o -print -delete
	find . -name \*.d -print -delete

OBJS = $(patsubst %.cpp, %.o, $(patsubst %.S, %.o, $(patsubst %.c, %.o, $(PROJECT_SOURCES))))
project.elf: $(OBJS) Makefile link.ld
	$(CC) $(CFLAGS) -T link.ld -Wl,--nostdlib,--gc-sections,--start-group $(OBJS) -Wl,--end-group -o project.elf
main.bin: project.elf
	$(OBJCOPY) -O binary -S -j .text project.elf main.bin
-include $(patsubst %.o, %.d, $(OBJS))
