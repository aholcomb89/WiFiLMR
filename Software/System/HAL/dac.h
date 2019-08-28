#pragma once

#include "device.h"

namespace HAL
{
enum class DACRegisters {
    CR      = 0x00,
    SWTRGR  = 0x04,
    DHR12R1 = 0x08,
    DHR12L1 = 0x0C,
    DHR8R1  = 0x10,
    DHR12R2 = 0x14,
    DHR12L2 = 0x18,
    DHR8R2  = 0x1C,
    DHR12RD = 0x20,
    DHR12LD = 0x24,
    DHR8RD  = 0x28,
    DOR1    = 0x2C,
    DOR2    = 0x30,
    SR      = 0x34,
    CCR     = 0x38,
    MCR     = 0x3C,
    SHSR1   = 0x40,
    SHSR2   = 0x44,
    SHHR    = 0x48,
    SHRR    = 0x4C
};

// The STM32L452 doesn't actually have a second DAC output channel, so this
// driver doesn't support it

class DAC : protected Device<DAC, DACRegisters>
{
public:
    enum class TriggerSource {
        TIM6_TRGO   = 0b000,
        TIM8_TRGO   = 0b001,
        TIM7_TRGO   = 0b010,
        TIM5_TRGO   = 0b011,
        TIM2_TRGO   = 0b100,
        TIM4_TRGO   = 0b101,
        EXTI9       = 0b110,
        SWTRIG      = 0b111
    };
    enum class Alignment {
        Right8Bit,
        Right12Bit,
        Left12Bit
    };

    constexpr static size_t BASE = 0x40007400;
    using Registers = DACRegisters;

    static void setDMAEnable(bool enabled) {
        setRegBits(DACRegisters::CR,
                   static_cast<size_t>(CRBits::DMAEN1),
                   enabled);
    }
    static void enable(bool enabled) {
        setRegBits(DACRegisters::CR,
                   static_cast<size_t>(CRBits::EN1),
                   enabled);
    }
    static void setTriggerEnable(bool enabled) {
        setRegBits(DACRegisters::CR,
                   static_cast<size_t>(CRBits::TEN1),
                   enabled);
    }
    static void setTriggerSource(TriggerSource src) {
        setRegBits(DACRegisters::CR,
                   {
                       static_cast<size_t>(CRBits::TSEL1_MSB),
                       static_cast<size_t>(CRBits::TSEL1_LSB)
                   },
                   static_cast<size_t>(src));
    }
    constexpr static volatile uint32_t * dataAddress(Alignment alignment) {
        switch (alignment) {
            case Alignment::Right8Bit:
                return regAddr(DACRegisters::DHR8R1);
            case Alignment::Right12Bit:
                return regAddr(DACRegisters::DHR12R1);
            case Alignment::Left12Bit:
                return regAddr(DACRegisters::DHR12L1);
        }
    }
private:
    enum class CRBits {
        CEN1        = 14,
        DMAUDRIE1   = 13,
        DMAEN1      = 12,
        MAMP1_MSB   = 11,
        MAMP1_LSB   =  8,
        TSEL1_MSB   =  5,
        TSEL1_LSB   =  3,
        TEN1        =  2,
        EN1         =  0
    };
};
} // namespace HAL
