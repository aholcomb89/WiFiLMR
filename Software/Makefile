# Package definitions
export FREERTOS = Packages/FreeRTOS/FreeRTOS/
export DRIVERLIB = Packages/driverlib/
export OPUS = Packages/opus/

# Include definitions
CFLAGS += -I$(FREERTOS) -I$(FREERTOS)/Source/include/ -I$(FREERTOS)/Source/portable/GCC/ARM_CM4F/
CFLAGS += $(addprefix -I$(OPUS), include silk celt silk/fixed)
CFLAGS += -I. -IPackages/ -ISystem/
# Make TivaWare happy...
CFLAGS += -Dgcc
# GC sections
CFLAGS += -ffunction-sections -fdata-sections -ffreestanding -Os
CFLAGS += -ggdb -Werror -pipe
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


WIFILMR_SOURCES = main.c \
    System/initialization.c \
    System/interrupt_table.c \
    System/uartstdio.c \

DRIVERLIB_SOURCES := adc.c \
    aes.c \
    can.c \
    comp.c \
    cpu.c \
    crc.c \
    des.c \
    eeprom.c \
    emac.c \
    epi.c \
    flash.c \
    fpu.c \
    gpio.c \
    hibernate.c \
    i2c.c \
    interrupt.c \
    lcd.c \
    mpu.c \
    onewire.c \
    pwm.c \
    qei.c \
    shamd5.c \
    ssi.c \
    sw_crc.c \
    sysctl.c \
    sysexc.c \
    systick.c \
    timer.c \
    uart.c \
    udma.c \
    usb.c \
    watchdog.c

DRIVERLIB_SOURCES := $(addprefix $(DRIVERLIB), $(DRIVERLIB_SOURCES))

FREERTOS_SOURCES := croutine.c \
    event_groups.c \
    list.c \
    queue.c \
    tasks.c \
    timers.c \
    portable/GCC/ARM_CM4F/port.c \
    portable/MemMang/heap_4.c

FREERTOS_SOURCES := $(addprefix $(FREERTOS)/Source/, $(FREERTOS_SOURCES))

PROJECT_SOURCES = $(WIFILMR_SOURCES) $(LIBOPUS_SOURCES) $(FREERTOS_SOURCES) $(DRIVERLIB_SOURCES)

#libproject.a: $(libproject_a_SOURCES)
#find . -name *.o | xargs $(AR) rcs libproject.a 

export OBJCOPY=arm-none-eabi-objcopy
export MACHINE=armv7e-m
export CC=arm-none-eabi-gcc
export CXX=arm-none-eabi-g++
export AS=arm-none-eabi-gcc
CFLAGS += -march=$(MACHINE) -mcpu=cortex-m4 -mfloat-abi=hard -mfpu=fpv4-sp-d16
CXXFLAGS = $(CFLAGS) -fno-exceptions -fno-rtti
all: main.axf

%.o: %.c Makefile
	$(CC) $(CFLAGS) -c $< -o $@ -MMD
%.o: %.cpp Makefile
	$(CXX) $(CXXFLAGS) -c $< -o $@ -MMD
clean:
	rm -vf main.axf*
	rm -vf project.bin*
	find . -name \*.o -print -delete
	find . -name \*.d -print -delete

OBJS = $(patsubst %.S, %.o, $(patsubst %.c, %.o, $(PROJECT_SOURCES)))
project.bin: $(OBJS) Makefile
	$(CC) $(CFLAGS) -T link.ld -Wl,--nostdlib,--gc-sections,--start-group $(OBJS) -Wl,--end-group -o project.bin
main.axf: project.bin
	$(OBJCOPY) -O binary -S -j .text project.bin main.axf
-include $(patsubst %.o, %.d, $(OBJS))
