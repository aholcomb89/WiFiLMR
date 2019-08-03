#include <stdint.h>
#include <string.h>
#include "HAL/memory_map.h"
#include "FreeRTOSConfig.h"
#include "System/interrupts.h"

//Magic values provided by the benevolent linker
extern char __bss_start__;
extern char __bss_end__;
extern char _data;
extern char _edata;
extern char _etext;

void __attribute__((naked, noreturn)) spin()
{
    __asm("bl spin\n");
}

size_t system_clock = 0;
extern void main(void) __attribute__((noreturn));

void ResetISR()
{
    //Enable FPU
    //Zero fill the bss segment
    size_t bss_size = (size_t)&__bss_end__ - (size_t)&__bss_start__;
    memset(&__bss_start__, 0, bss_size);
    //Copy data values from flash to ram
    size_t data_size = (size_t)&_edata - (size_t)&_data;
    memcpy(&_data, &_etext, data_size);
    //Set the system clock speed
    // system_clock = SysCtlClockFreqSet(SYSCTL_XTAL_25MHZ |
    //                    SYSCTL_OSC_MAIN |
    //                    SYSCTL_USE_PLL |
    //                    SYSCTL_CFG_VCO_480, 120000000);
//__asm__ __volatile__ ("b.w _mainCRTStartup");
	main();
}

void NmiSR()
{
    spin();
}
void FaultISR()
{
    spin();
}

#if DEBUG_INTTABLE
#define INT_DEFAULT(ENTRY) \
void __attribute__((noreturn)) IntDefaultHandler_##ENTRY() \
{ \
    __asm("mov r1, #"#ENTRY"\n"); \
    spin(); \
}
#else
void __attribute__((noreturn)) IntDefaultHandler()
{
    spin();
}
#define INT_DEFAULT(x)
#endif

INT_DEFAULT(1);
INT_DEFAULT(2);
INT_DEFAULT(3);
INT_DEFAULT(4);
INT_DEFAULT(5);
INT_DEFAULT(6);
INT_DEFAULT(7);
INT_DEFAULT(8);
INT_DEFAULT(9);
INT_DEFAULT(10);
INT_DEFAULT(11);
INT_DEFAULT(12);
INT_DEFAULT(13);
INT_DEFAULT(14);
INT_DEFAULT(15);
INT_DEFAULT(16);
INT_DEFAULT(17);
INT_DEFAULT(18);
INT_DEFAULT(19);
INT_DEFAULT(20);
INT_DEFAULT(21);
INT_DEFAULT(22);
INT_DEFAULT(23);
INT_DEFAULT(24);
INT_DEFAULT(25);
INT_DEFAULT(26);
INT_DEFAULT(27);
INT_DEFAULT(28);
INT_DEFAULT(29);
INT_DEFAULT(30);
INT_DEFAULT(31);
INT_DEFAULT(32);
INT_DEFAULT(33);
INT_DEFAULT(34);
INT_DEFAULT(35);
INT_DEFAULT(36);
INT_DEFAULT(37);
INT_DEFAULT(38);
INT_DEFAULT(39);
INT_DEFAULT(40);
INT_DEFAULT(41);
INT_DEFAULT(42);
INT_DEFAULT(43);
INT_DEFAULT(44);
INT_DEFAULT(45);
INT_DEFAULT(46);
INT_DEFAULT(47);
INT_DEFAULT(48);
INT_DEFAULT(49);
INT_DEFAULT(50);
INT_DEFAULT(51);
INT_DEFAULT(52);
INT_DEFAULT(53);
INT_DEFAULT(54);
INT_DEFAULT(55);
INT_DEFAULT(56);
INT_DEFAULT(57);
INT_DEFAULT(58);
INT_DEFAULT(59);
INT_DEFAULT(60);
INT_DEFAULT(61);
INT_DEFAULT(62);
INT_DEFAULT(63);
INT_DEFAULT(64);
INT_DEFAULT(65);
INT_DEFAULT(66);
INT_DEFAULT(67);
INT_DEFAULT(68);
INT_DEFAULT(69);
INT_DEFAULT(70);
INT_DEFAULT(71);
INT_DEFAULT(72);
INT_DEFAULT(73);
INT_DEFAULT(74);
INT_DEFAULT(75);
INT_DEFAULT(76);
INT_DEFAULT(77);
INT_DEFAULT(78);
INT_DEFAULT(79);