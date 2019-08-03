#include "System/interrupts.h"
#include "FreeRTOSConfig.h"

extern char __stack;

__attribute__ ((section(".isr_vector")))
void (* const int_vectors[])(void) =
{
    (void*)&__stack,                    // The initial stack pointer
    ResetISR,                               // The reset handler
    NmiSR,                                  // The NMI handler
    FaultISR,                               // The hard fault handler
    IntDefaultHandler_1,                      // The MPU fault handler
    IntDefaultHandler_2,                      // The bus fault handler
    IntDefaultHandler_3,                      // The usage fault handler
    0,                                      // Reserved
    0,                                      // Reserved
    0,                                      // Reserved
    0,                                      // Reserved
    vPortSVCHandler,                        // SVCall handler
    IntDefaultHandler_5,                      // Debug monitor handler
    0,                                      // Reserved
    xPortPendSVHandler,                     // The PendSV handler
    xPortSysTickHandler,                    // The SysTick handler
    FaultISR,                      // GPIO Port A
    IntDefaultHandler_6,                      // GPIO Port B
    IntDefaultHandler_7,                      // GPIO Port C
    IntDefaultHandler_8,                      // GPIO Port D
    IntDefaultHandler_9,                      // GPIO Port E
    IntDefaultHandler_10,                      // UART0 Rx and Tx
    IntDefaultHandler_11,                      // UART1 Rx and Tx
    IntDefaultHandler_12,                      // SSI Rx and Tx
    IntDefaultHandler_13,                      // I2C Master and Slave
    IntDefaultHandler_14,                      // PWM Fault
    IntDefaultHandler_15,                      // PWM Generator 0
    IntDefaultHandler_16,                      // PWM Generator 1
    IntDefaultHandler_17,                      // PWM Generator 2
    IntDefaultHandler_18,                      // Quadrature Encoder
    IntDefaultHandler_19,                      // ADC Sequence 0
    IntDefaultHandler_20,                      // ADC Sequence 1
    IntDefaultHandler_21,                      // ADC Sequence 2
    IntDefaultHandler_22,                      // ADC Sequence 3
    IntDefaultHandler_23,                      // Watchdog timer
    IntDefaultHandler_24,                      // Timer 0 subtimer A
    IntDefaultHandler_25,                      // Timer 0 subtimer B
    IntDefaultHandler_26,                      // Timer 1 subtimer A
    IntDefaultHandler_27,                      // Timer 1 subtimer B
    IntDefaultHandler_28,                      // Timer 2 subtimer A
    IntDefaultHandler_29,                      // Timer 2 subtimer B
    IntDefaultHandler_30,                      // Analog Comparator 0
    IntDefaultHandler_31,                      // Analog Comparator 1
    IntDefaultHandler_32,                      // Analog Comparator 2
    IntDefaultHandler_33,                      // System Control (PLL, OSC, BO)
    IntDefaultHandler_34,                      // FLASH Control
    IntDefaultHandler_35,                      // GPIO Port F
    IntDefaultHandler_36,                      // GPIO Port G
    IntDefaultHandler_37,                      // GPIO Port H
    IntDefaultHandler_38,                      // UART2 Rx and Tx
    IntDefaultHandler_39,                      // SSI1 Rx and Tx
    IntDefaultHandler_40,                      // Timer 3 subtimer A
    IntDefaultHandler_41,                      // Timer 3 subtimer B
    IntDefaultHandler_42,                      // I2C1 Master and Slave
    IntDefaultHandler_43,                      // CAN0
    IntDefaultHandler_44,                      // CAN1
    IntDefaultHandler_45,                      // Ethernet
    IntDefaultHandler_46,                      // Hibernate
    IntDefaultHandler_47,                      // USB0
    IntDefaultHandler_48,                      // PWM Generator 3
    IntDefaultHandler_49,                      // uDMA Software Transfer
    IntDefaultHandler_50,                      // uDMA Error
    IntDefaultHandler_51,                      // ADC1 Sequence 0
    IntDefaultHandler_52,                      // ADC1 Sequence 1
    IntDefaultHandler_53,                      // ADC1 Sequence 2
    IntDefaultHandler_54,                      // ADC1 Sequence 3
    IntDefaultHandler_55,                      // External Bus Interface 0
    IntDefaultHandler_56,                      // GPIO Port J
    IntDefaultHandler_57,                      // GPIO Port K
    IntDefaultHandler_58,                      // GPIO Port L
    IntDefaultHandler_59,                      // SSI2 Rx and Tx
    IntDefaultHandler_60,                      // SSI3 Rx and Tx
    IntDefaultHandler_61,                      // UART3 Rx and Tx
    IntDefaultHandler_62,                      // UART4 Rx and Tx
    IntDefaultHandler_63,                      // UART5 Rx and Tx
    IntDefaultHandler_64,                      // UART6 Rx and Tx
    IntDefaultHandler_65,                      // UART7 Rx and Tx
    IntDefaultHandler_66,                      // I2C2 Master and Slave
    IntDefaultHandler_67,                      // I2C3 Master and Slave
    IntDefaultHandler_68,                      // Timer 4 subtimer A
    IntDefaultHandler_69,                      // Timer 4 subtimer B
    IntDefaultHandler_70,                      // Timer 5 subtimer A
    IntDefaultHandler_71,                      // Timer 5 subtimer B
    IntDefaultHandler_72,                      // FPU
    0,                                      // Reserved
    0,                                      // Reserved
    IntDefaultHandler_73,                      // I2C4 Master and Slave
    IntDefaultHandler_74,                      // I2C5 Master and Slave
    IntDefaultHandler_75,                      // GPIO Port M
    IntDefaultHandler_76,                      // GPIO Port N
    0,                                      // Reserved
    IntDefaultHandler_77,                      // Tamper
    IntDefaultHandler_78,                      // GPIO Port P (Summary or P0)
    IntDefaultHandler_79,                      // GPIO Port P1
    IntDefaultHandler_79,                      // GPIO Port P2
    IntDefaultHandler_79,                      // GPIO Port P3
    IntDefaultHandler_79,                      // GPIO Port P4
    IntDefaultHandler_79,                      // GPIO Port P5
    IntDefaultHandler_79,                      // GPIO Port P6
    IntDefaultHandler_79,                      // GPIO Port P7
    IntDefaultHandler_79,                      // GPIO Port Q (Summary or Q0)
    IntDefaultHandler_79,                      // GPIO Port Q1
    IntDefaultHandler_79,                      // GPIO Port Q2
    IntDefaultHandler_79,                      // GPIO Port Q3
    IntDefaultHandler_79,                      // GPIO Port Q4
    IntDefaultHandler_79,                      // GPIO Port Q5
    IntDefaultHandler_79,                      // GPIO Port Q6
    IntDefaultHandler_79,                      // GPIO Port Q7
    IntDefaultHandler_79,                      // GPIO Port R
    IntDefaultHandler_79,                      // GPIO Port S
    IntDefaultHandler_79,                      // SHA/MD5 0
    IntDefaultHandler_79,                      // AES 0
    IntDefaultHandler_79,                      // DES3DES 0
    IntDefaultHandler_79,                      // LCD Controller 0
    IntDefaultHandler_79,                      // Timer 6 subtimer A
    IntDefaultHandler_79,                      // Timer 6 subtimer B
    IntDefaultHandler_79,                      // Timer 7 subtimer A
    IntDefaultHandler_79,                      // Timer 7 subtimer B
    IntDefaultHandler_79,                      // I2C6 Master and Slave
    IntDefaultHandler_79,                         // I2C7 Master and Slave
    IntDefaultHandler_79,                      // HIM Scan Matrix Keyboard 0
    IntDefaultHandler_79,                      // One Wire 0
    IntDefaultHandler_79,                      // HIM PS/2 0
    IntDefaultHandler_79,                      // HIM LED Sequencer 0
    IntDefaultHandler_79,                      // HIM Consumer IR 0
    IntDefaultHandler_79,                      // I2C8 Master and Slave
    IntDefaultHandler_79,                      // I2C9 Master and Slave
    IntDefaultHandler_79                       // GPIO Port T
};
