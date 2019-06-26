//*****************************************************************************
//
// hello.c - Simple hello world example.
//
// Copyright (c) 2012-2017 Texas Instruments Incorporated.  All rights reserved.
// Software License Agreement
// 
// Texas Instruments (TI) is supplying this software for use solely and
// exclusively on TI's microcontroller products. The software is owned by
// TI and/or its suppliers, and is protected under applicable copyright
// laws. You may not combine this software with "viral" open-source
// software in order to form a larger program.
// 
// THIS SOFTWARE IS PROVIDED "AS IS" AND WITH ALL FAULTS.
// NO WARRANTIES, WHETHER EXPRESS, IMPLIED OR STATUTORY, INCLUDING, BUT
// NOT LIMITED TO, IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
// A PARTICULAR PURPOSE APPLY TO THIS SOFTWARE. TI SHALL NOT, UNDER ANY
// CIRCUMSTANCES, BE LIABLE FOR SPECIAL, INCIDENTAL, OR CONSEQUENTIAL
// DAMAGES, FOR ANY REASON WHATSOEVER.
// 
// This is part of revision 2.1.4.178 of the EK-TM4C123GXL Firmware Package.
//
//*****************************************************************************

#include <stdint.h>
#include <stdbool.h>
#include "System/chip.h"
#include "driverlib/inc/hw_memmap.h"
#include "driverlib/inc/hw_types.h"
#include "driverlib/pin_map.h"
#include "driverlib/debug.h"
#include "driverlib/fpu.h"
#include "driverlib/gpio.h"
#include "driverlib/pin_map.h"
#include "driverlib/rom.h"
#include "driverlib/sysctl.h"
#include "driverlib/uart.h"
#include "System/uartstdio.h"

//*****************************************************************************
//
//! \addtogroup example_list
//! <h1>Hello World (hello)</h1>
//!
//! A very simple ``hello world'' example.  It simply displays ``Hello World!''
//! on the UART and is a starting point for more complicated applications.
//!
//! UART0, connected to the Virtual Serial Port and running at
//! 115,200, 8-N-1, is used to display messages from this application.
//
//*****************************************************************************

//*****************************************************************************
//
// The error routine that is called if the driver library encounters an error.
//
//*****************************************************************************
#ifdef DEBUG
void
__error__(char *pcFilename, uint32_t ui32Line)
{
}
#endif

//*****************************************************************************
//
// Configure the UART and its pins.  This must be called before UARTprintf().
//
//*****************************************************************************
void
ConfigureUART(void)
{
    //
    // Enable the GPIO Peripheral used by the UART.
    //
    SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOA);

    //
    // Enable UART0
    //
    SysCtlPeripheralEnable(SYSCTL_PERIPH_UART0);

    //
    // Configure GPIO Pins for UART mode.
    //
    GPIOPinConfigure(GPIO_PA0_U0RX);
    GPIOPinConfigure(GPIO_PA1_U0TX);
    GPIOPinTypeUART(GPIO_PORTA_BASE, GPIO_PIN_0 | GPIO_PIN_1);

    //
    // Initialize the UART for console I/O.
    //
    UARTConfigSetExpClk(UART0_BASE, system_clock, 115200, UART_CONFIG_WLEN_8 | UART_CONFIG_STOP_ONE | UART_CONFIG_PAR_NONE);
}
void puts(char* s)
{
	for(;*s != 0; s++)
	    UARTCharPut(UART0_BASE, *s);
}
//*****************************************************************************
//
// Print "Hello World!" to the UART on the evaluation board.
//
//*****************************************************************************
int
main(void)
{
    //volatile uint32_t ui32Loop;

    //
    // Enable lazy stacking for interrupt handlers.  This allows floating-point
    // instructions to be used within interrupt handlers, but at the expense of
    // extra stack usage.
    //
    //FPULazyStackingEnable();

    //
    // Set the clocking to run directly from the crystal.
    //

    //
    // Enable the GPIO port that is used for the on-board LED.
    //
    SysCtlPeripheralEnable(SYSCTL_PERIPH_GPION);

    //
    // Enable the GPIO pins for the LED (PF2 & PF3).
    //
    GPIOPinTypeGPIOOutput(GPIO_PORTN_BASE, GPIO_PIN_1);

    //
    // Initialize the UART.
    //
    ConfigureUART();
    
	while(!SysCtlPeripheralReady(SYSCTL_PERIPH_UART0))
	{
	}


    //
    // We are finished.  Hang around doing nothing.
    //
    while(1)
    {
        //
        // Hello!
        //
        puts("hello world!\n\0");
        //
        // Turn on the BLUE LED.
        //
        GPIOPinWrite(GPIO_PORTN_BASE, GPIO_PIN_1, GPIO_PIN_1);

        //
        // Delay for a bit.
        //
        SysCtlDelay(SysCtlClockGet());

        //
        // Turn off the BLUE LED.
        //
        GPIOPinWrite(GPIO_PORTN_BASE, GPIO_PIN_1, 0);

        //
        // Delay for a bit.
        //
        SysCtlDelay(SysCtlClockGet());
    }
}
