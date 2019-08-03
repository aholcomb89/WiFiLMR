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
    INT_DEFAULT_DECL(01),                      // The MPU fault handler
    INT_DEFAULT_DECL(02),                      // The bus fault handler
    INT_DEFAULT_DECL(03),                      // The usage fault handler
    0,                                      // Reserved
    0,                                      // Reserved
    0,                                      // Reserved
    0,                                      // Reserved
    vPortSVCHandler,                        // SVCall handler
    INT_DEFAULT_DECL(05),                      // Debug monitor handler
    0,                                      // Reserved
    xPortPendSVHandler,                     // The PendSV handler
    xPortSysTickHandler,                    // The SysTick handler
    FaultISR,                      // GPIO Port A
    INT_DEFAULT_DECL(06),                      // GPIO Port B
    INT_DEFAULT_DECL(07),                      // GPIO Port C
    INT_DEFAULT_DECL(08),                      // GPIO Port D
    INT_DEFAULT_DECL(09),                      // GPIO Port E
    INT_DEFAULT_DECL(10),                      // UART0 Rx and Tx
    INT_DEFAULT_DECL(11),                      // UART1 Rx and Tx
    INT_DEFAULT_DECL(12),                      // SSI Rx and Tx
    INT_DEFAULT_DECL(13),                      // I2C Master and Slave
    INT_DEFAULT_DECL(14),                      // PWM Fault
    INT_DEFAULT_DECL(15),                      // PWM Generator 0
    INT_DEFAULT_DECL(16),                      // PWM Generator 1
    INT_DEFAULT_DECL(17),                      // PWM Generator 2
    INT_DEFAULT_DECL(18),                      // Quadrature Encoder
    INT_DEFAULT_DECL(19),                      // ADC Sequence 0
    INT_DEFAULT_DECL(20),                      // ADC Sequence 1
    INT_DEFAULT_DECL(21),                      // ADC Sequence 2
    INT_DEFAULT_DECL(22),                      // ADC Sequence 3
    INT_DEFAULT_DECL(23),                      // Watchdog timer
    INT_DEFAULT_DECL(24),                      // Timer 0 subtimer A
    INT_DEFAULT_DECL(25),                      // Timer 0 subtimer B
    INT_DEFAULT_DECL(26),                      // Timer 1 subtimer A
    INT_DEFAULT_DECL(27),                      // Timer 1 subtimer B
    INT_DEFAULT_DECL(28),                      // Timer 2 subtimer A
    INT_DEFAULT_DECL(29),                      // Timer 2 subtimer B
    INT_DEFAULT_DECL(30),                      // Analog Comparator 0
    INT_DEFAULT_DECL(31),                      // Analog Comparator 1
    INT_DEFAULT_DECL(32),                      // Analog Comparator 2
    INT_DEFAULT_DECL(33),                      // System Control (PLL, OSC, BO)
    INT_DEFAULT_DECL(34),                      // FLASH Control
    INT_DEFAULT_DECL(35),                      // GPIO Port F
    INT_DEFAULT_DECL(36),                      // GPIO Port G
    INT_DEFAULT_DECL(37),                      // GPIO Port H
    INT_DEFAULT_DECL(38),                      // UART2 Rx and Tx
    INT_DEFAULT_DECL(39),                      // SSI1 Rx and Tx
    INT_DEFAULT_DECL(40),                      // Timer 3 subtimer A
    INT_DEFAULT_DECL(41),                      // Timer 3 subtimer B
    INT_DEFAULT_DECL(42),                      // I2C1 Master and Slave
    INT_DEFAULT_DECL(43),                      // CAN0
    INT_DEFAULT_DECL(44),                      // CAN1
    INT_DEFAULT_DECL(45),                      // Ethernet
    INT_DEFAULT_DECL(46),                      // Hibernate
    INT_DEFAULT_DECL(47),                      // USB0
    INT_DEFAULT_DECL(48),                      // PWM Generator 3
    INT_DEFAULT_DECL(49),                      // uDMA Software Transfer
    INT_DEFAULT_DECL(50),                      // uDMA Error
    INT_DEFAULT_DECL(51),                      // ADC1 Sequence 0
    INT_DEFAULT_DECL(52),                      // ADC1 Sequence 1
    INT_DEFAULT_DECL(53),                      // ADC1 Sequence 2
    INT_DEFAULT_DECL(54),                      // ADC1 Sequence 3
    INT_DEFAULT_DECL(55),                      // External Bus Interface 0
    INT_DEFAULT_DECL(56),                      // GPIO Port J
    INT_DEFAULT_DECL(57),                      // GPIO Port K
    INT_DEFAULT_DECL(58),                      // GPIO Port L
    INT_DEFAULT_DECL(59),                      // SSI2 Rx and Tx
    INT_DEFAULT_DECL(60),                      // SSI3 Rx and Tx
    INT_DEFAULT_DECL(61),                      // UART3 Rx and Tx
    INT_DEFAULT_DECL(62),                      // UART4 Rx and Tx
    INT_DEFAULT_DECL(63),                      // UART5 Rx and Tx
    INT_DEFAULT_DECL(64),                      // UART6 Rx and Tx
    INT_DEFAULT_DECL(65),                      // UART7 Rx and Tx
    INT_DEFAULT_DECL(66),                      // I2C2 Master and Slave
    INT_DEFAULT_DECL(67),                      // I2C3 Master and Slave
    INT_DEFAULT_DECL(68),                      // Timer 4 subtimer A
    INT_DEFAULT_DECL(69),                      // Timer 4 subtimer B
    INT_DEFAULT_DECL(70),                      // Timer 5 subtimer A
    INT_DEFAULT_DECL(71),                      // Timer 5 subtimer B
    INT_DEFAULT_DECL(72),                      // FPU
    0,                                      // Reserved
    0,                                      // Reserved
    INT_DEFAULT_DECL(73),                      // I2C4 Master and Slave
    INT_DEFAULT_DECL(74),                      // I2C5 Master and Slave
    INT_DEFAULT_DECL(75),                      // GPIO Port M
    INT_DEFAULT_DECL(76),                      // GPIO Port N
    0,                                      // Reserved
    INT_DEFAULT_DECL(77),                      // Tamper
    INT_DEFAULT_DECL(78),                      // GPIO Port P (Summary or P0)
    INT_DEFAULT_DECL(79),                      // GPIO Port P1
    INT_DEFAULT_DECL(79),                      // GPIO Port P2
    INT_DEFAULT_DECL(79),                      // GPIO Port P3
    INT_DEFAULT_DECL(79),                      // GPIO Port P4
    INT_DEFAULT_DECL(79),                      // GPIO Port P5
    INT_DEFAULT_DECL(79),                      // GPIO Port P6
    INT_DEFAULT_DECL(79),                      // GPIO Port P7
    INT_DEFAULT_DECL(79),                      // GPIO Port Q (Summary or Q0)
    INT_DEFAULT_DECL(79),                      // GPIO Port Q1
    INT_DEFAULT_DECL(79),                      // GPIO Port Q2
    INT_DEFAULT_DECL(79),                      // GPIO Port Q3
    INT_DEFAULT_DECL(79),                      // GPIO Port Q4
    INT_DEFAULT_DECL(79),                      // GPIO Port Q5
    INT_DEFAULT_DECL(79),                      // GPIO Port Q6
    INT_DEFAULT_DECL(79),                      // GPIO Port Q7
    INT_DEFAULT_DECL(79),                      // GPIO Port R
    INT_DEFAULT_DECL(79),                      // GPIO Port S
    INT_DEFAULT_DECL(79),                      // SHA/MD5 0
    INT_DEFAULT_DECL(79),                      // AES 0
    INT_DEFAULT_DECL(79),                      // DES3DES 0
    INT_DEFAULT_DECL(79),                      // LCD Controller 0
    INT_DEFAULT_DECL(79),                      // Timer 6 subtimer A
    INT_DEFAULT_DECL(79),                      // Timer 6 subtimer B
    INT_DEFAULT_DECL(79),                      // Timer 7 subtimer A
    INT_DEFAULT_DECL(79),                      // Timer 7 subtimer B
    INT_DEFAULT_DECL(79),                      // I2C6 Master and Slave
    INT_DEFAULT_DECL(79),                         // I2C7 Master and Slave
    INT_DEFAULT_DECL(79),                      // HIM Scan Matrix Keyboard 0
    INT_DEFAULT_DECL(79),                      // One Wire 0
    INT_DEFAULT_DECL(79),                      // HIM PS/2 0
    INT_DEFAULT_DECL(79),                      // HIM LED Sequencer 0
    INT_DEFAULT_DECL(79),                      // HIM Consumer IR 0
    INT_DEFAULT_DECL(79),                      // I2C8 Master and Slave
    INT_DEFAULT_DECL(79),                      // I2C9 Master and Slave
    INT_DEFAULT_DECL(79)                       // GPIO Port T
};
