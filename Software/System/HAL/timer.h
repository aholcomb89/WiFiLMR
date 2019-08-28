#pragma once

#include "device.h"

namespace HAL
{
enum class TimerRegisters {
    CR1     = 0x00,
    CR2     = 0x04,
    DIER    = 0x0C,
    SR      = 0x10,
    EGR     = 0x14,
    CNT     = 0x24,
    PSC     = 0x28,
    ARR     = 0x2C,
};


namespace TimerTraits
{
struct TIM6 {
    constexpr static size_t BaseAddr = 0x40001000ul;
};
} // namespace Traits

template <class Traits>
class Timer: protected Device<Timer<Traits>, TimerRegisters>
{
public:
    enum class MasterMode {
        Reset   = 0b000,
        Enable  = 0b001,
        Update  = 0b010
    };

    using Registers = TimerRegisters;
    constexpr static size_t BASE = Traits::BaseAddr;

    static void setOnePulseMode(bool isOneShot) {
        Timer::setRegBits(TimerRegisters::CR1,
                          static_cast<size_t>(CR1Bits::OPM),
                          isOneShot);
    }
    static void enable(bool isEnabled) {
        Timer::setRegBits(TimerRegisters::CR1,
                          static_cast<size_t>(CR1Bits::CEN),
                          isEnabled);
    }
    static void setPrescaler(uint16_t scalar) {
        Timer::setRegBits(TimerRegisters::PSC,
                          {
                              static_cast<size_t>(PSCBits::PSC_MSB),
                              static_cast<size_t>(PSCBits::PSC_LSB)
                          },
                          scalar);
    }
    static void setAutoReloadValue(uint16_t val) {
        Timer::setRegBits(TimerRegisters::ARR,
                          {
                              static_cast<size_t>(ARRBits::ARR_MSB),
                              static_cast<size_t>(ARRBits::ARR_LSB)
                          },
                          val);
    }
    static void enableUpdateInterrupt(bool enabled) {
        Timer::setRegBits(TimerRegisters::DIER,
                          DIERBits::UIE,
                          enabled);
    }
    static void setMasterMode(MasterMode mode) {
        Timer::setRegBits(TimerRegisters::CR2,
                          {
                              static_cast<size_t>(CR2Bits::MMS_MSB),
                              static_cast<size_t>(CR2Bits::MMS_LSB)
                          },
                          static_cast<size_t>(mode));
    }
private:
    enum class CR1Bits {
        UIFREMAP = 11,
        ARPE     =  7,
        OPM      =  3,
        URS      =  2,
        UDIS     =  1,
        CEN      =  0
    };
    enum class CR2Bits {
        MMS_MSB  =  6,
        MMS_LSB  =  4
    };
    enum class DIERBits {
        UDE      =  8,
        UIE      =  0
    };
    enum class UIFBits {
        UIF      =  0
    };
    enum class EGRBits {
        UG       =  0
    };
    enum class CNTBits {
        UIFCPY   = 31,
        CNT_MSB  = 15,
        CNT_LSB  =  0
    };
    enum class PSCBits {
        PSC_MSB  = 15,
        PSC_LSB  =  0
    };
    enum class ARRBits {
        ARR_MSB  = 15,
        ARR_LSB  =  0
    };
};

using TIM6 = Timer<TimerTraits::TIM6>;
} // namespace HAL
