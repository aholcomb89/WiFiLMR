#pragma once

#include "device.h"

namespace HAL
{
enum class GPIORegister: size_t
{
    MODER = 0x00,
    PUPDR = 0x0C,
    ODR   = 0x14,
    AFRL  = 0x20,
    AFRH  = 0x24,
};
template <size_t base>
struct GPIO: protected Device<GPIO<base>, GPIORegister>
{
    enum class Mode {
        Input  = 0b00,
        Output = 0b01,
        Alt    = 0b10,
        Analog = 0b11,
    };

    enum class Pullup {
        None = 0b00,
        Up   = 0b01,
        Down = 0b10,
    };

    enum class AltFunc {
        PA2_LPUART1_TX = 8u,
        PA3_LPUART1_RX = 8u,
    };

    using Register = GPIORegister;
    constexpr static const size_t BASE = base;

    static void setMode(size_t pin, Mode mode) {
        GPIO::setRegBits(Register::MODER, {pin * 2 + 1, pin * 2}, mode);
    }

    static void setOutput(size_t pin, bool enabled) {
        GPIO::setRegBits(Register::ODR, pin, enabled & 0x01);
    }

    static void setPullup(size_t pin, Pullup pup) {
        GPIO::setRegBits(Register::PUPDR, {pin * 2 + 1, pin * 2}, pup);
    }

    static void setAltFunc(size_t pin, AltFunc alt) {
        const auto reg = (pin > 7) ? Register::AFRH : Register::AFRL;
        GPIO::setRegBits(reg, {pin * 4 + 3, pin * 4}, alt);
    }
};

using GPIOA = GPIO<0x48000000>;
using GPIOB = GPIO<0x48000400>;

} // namespace HAL
