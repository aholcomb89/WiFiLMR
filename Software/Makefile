# Package definitions
export FREERTOS = Packages/FreeRTOS/FreeRTOS/
export DRIVERLIB = Packages/driverlib/

# Include definitions
CFLAGS += -I. -I$(FREERTOS) -I$(FREERTOS)/Source/include/ -I$(FREERTOS)/Source/portable/GCC/ARM_CM4F/
CFLAGS += -IPackages/ -ISystem/
# Make TivaWare happy...
CFLAGS += -Dgcc
# GC sections
CFLAGS += -ffunction-sections -fdata-sections -ffreestanding

libproject_a_SOURCES = main.c \
    System/initialization.c \
    System/interrupt_table.c \
    System/uartstdio.c \
    Packages/driverlib/adc.c \
    Packages/driverlib/aes.c \
    Packages/driverlib/can.c \
    Packages/driverlib/comp.c \
    Packages/driverlib/cpu.c \
    Packages/driverlib/crc.c \
    Packages/driverlib/des.c \
    Packages/driverlib/eeprom.c \
    Packages/driverlib/emac.c \
    Packages/driverlib/epi.c \
    Packages/driverlib/flash.c \
    Packages/driverlib/fpu.c \
    Packages/driverlib/gpio.c \
    Packages/driverlib/hibernate.c \
    Packages/driverlib/i2c.c \
    Packages/driverlib/interrupt.c \
    Packages/driverlib/lcd.c \
    Packages/driverlib/mpu.c \
    Packages/driverlib/onewire.c \
    Packages/driverlib/pwm.c \
    Packages/driverlib/qei.c \
    Packages/driverlib/shamd5.c \
    Packages/driverlib/ssi.c \
    Packages/driverlib/sw_crc.c \
    Packages/driverlib/sysctl.c \
    Packages/driverlib/sysexc.c \
    Packages/driverlib/systick.c \
    Packages/driverlib/timer.c \
    Packages/driverlib/uart.c \
    Packages/driverlib/udma.c \
    Packages/driverlib/usb.c \
    Packages/driverlib/watchdog.c \
    Packages/FreeRTOS/FreeRTOS/Source/croutine.c \
    Packages/FreeRTOS/FreeRTOS/Source/event_groups.c \
    Packages/FreeRTOS/FreeRTOS/Source/list.c \
    Packages/FreeRTOS/FreeRTOS/Source/queue.c \
    Packages/FreeRTOS/FreeRTOS/Source/tasks.c \
    Packages/FreeRTOS/FreeRTOS/Source/timers.c \
    Packages/FreeRTOS/FreeRTOS/Source/portable/GCC/ARM_CM4F/port.c \
    Packages/FreeRTOS/FreeRTOS/Source/portable/MemMang/heap_4.c

#libproject.a: $(libproject_a_SOURCES)
#find . -name *.o | xargs $(AR) rcs libproject.a 

export OBJCOPY=arm-none-eabi-objcopy
export MACHINE=armv7e-m
export CC=arm-none-eabi-gcc
CFLAGS += -march=$(MACHINE) -mcpu=cortex-m4 -mfloat-abi=hard -mfpu=fpv4-sp-d16
all: main.axf

clean:
	rm -vf main.axf*
	rm -vf project.bin*
	find . -name \*.o -print -delete
project.bin: $(patsubst %.c, %.o, $(libproject_a_SOURCES)) 
	$(CC) $(CFLAGS) -T link.ld -Wl,--nostdlib,--gc-sections,--start-group $(FREERTOS)/Source/*.o $(FREERTOS)/Source/portable/GCC/ARM_CM4F/*.o $(FREERTOS)/Source/portable/MemMang/*.o Packages/driverlib/*.o main.o System/*.o -Wl,--end-group -o project.bin
main.axf: project.bin
	$(OBJCOPY) -O binary -S -j .text project.bin main.axf

