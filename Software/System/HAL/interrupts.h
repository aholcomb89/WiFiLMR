#pragma once

namespace HAL
{
class Interrupts
{
public:
    enum class ISR {
        Reset           = 0x00000004,
        NMI             = 0x00000008,
        HardFault       = 0x0000000C,
        MemManage       = 0x00000010,
        BusFault        = 0x00000014,
        UsageFault      = 0x00000018,
        SVCall          = 0x0000002C,
        PendSV          = 0x00000038,
        SysTick         = 0x0000003C,
        WWDG            = 0x00000040,
        PVD_PVM         = 0x00000044,
        RTC_TAMP_STAMP  = 0x00000048,
        RTC_WKUP        = 0x0000004C,
        FLASH           = 0x00000050,
        RCC             = 0x00000054, // Datasheet errata: given as 0x5C
        EXT0            = 0x00000058, // Datasheet errata: given as 0x5C
        EXT1            = 0x0000005C,
        EXT2            = 0x00000060,
        EXT3            = 0x00000064,
        EXT4            = 0x00000068,
        DMA1_CH1        = 0x0000006C,
        DMA1_CH2        = 0x00000070,
        DMA1_CH3        = 0x00000074,
        DMA1_CH4        = 0x00000078,
        DMA1_CH5        = 0x0000007C,
        DMA1_CH6        = 0x00000080,
        DMA1_CH7        = 0x00000084,
        ADC1_2          = 0x00000088,
        CAN1_TX         = 0x0000008C,
        CAN1_RX0        = 0x00000090,
        CAN1_RX1        = 0x00000094,
        CAN1_SCE        = 0x00000098,
        EXTI9_5         = 0x0000009C,
        TIM1_BRK_TIM15  = 0x000000A0,
        TIM1_UP_TIM16   = 0x000000A4,
        TIM1_TRG_COM    = 0x000000A8,
        TIM1_CC         = 0x000000AC,
        TIM2            = 0x000000B0,
        TIM3            = 0x000000B4,
        I2C1_EV         = 0x000000BC,
        I2C1_ER         = 0x000000C0,
        I2C2_EV         = 0x000000C4,
        I2C2_ER         = 0x000000C8,
        SPI1            = 0x000000CC,
        SPI2            = 0x000000D0,
        USART1          = 0x000000D4,
        USART2          = 0x000000D8,
        USART3          = 0x000000DC,
        EXTI15_10       = 0x000000E0,
        RTC_ALARM       = 0x000000E4,
        SDMMC1          = 0x00000104,
        SPI3            = 0x0000010C,
        UART4           = 0x00000110,
        TIM6_DACUNDER   = 0x00000118,
        TIM7            = 0x0000011C,
        DMA2_CH1        = 0x00000120,
        DMA2_CH2        = 0x00000124,
        DMA2_CH3        = 0x00000128,
        DMA2_CH4        = 0x0000012C,
        DMA2_CH5        = 0x00000130,
        DFSDM1_FLT0     = 0x00000134,
        DFSDM1_FLT1     = 0x00000138,
        COMP            = 0x00000140,
        LPTIM1          = 0x00000144,
        LPTIM2          = 0x00000148,
        USB_FS          = 0x0000014C,
        DMA2_CH6        = 0x00000150,
        DMA2_CH7        = 0x00000154,
        LPUART1         = 0x00000158,
        QUADSPI         = 0x0000015C,
        I2C3_EV         = 0x00000160,
        I2C3_ER         = 0x00000164,
        SAI1            = 0x00000168,
        SWPMI1          = 0x00000170,
        TSC             = 0x00000174,
        LCD             = 0x00000178,
        AES             = 0x0000017C,
        RNG             = 0x00000180,
        FPU             = 0x00000184,
        CRS             = 0x00000188,
        I2C_EV          = 0x0000018C,
        I2C_ER          = 0x00000190
    };

    template <class Callable>
    static void setISR(ISR slot, Callable isr) {
        static_cast<volatile void()>(slot) = isr;
    }
};

} // namespace HAL
