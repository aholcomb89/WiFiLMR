#pragma once
#include <utility>
#include "device.h"
// AHB2 peripheral clock enable register (RCC_AHB2ENR)
#define GPIOAEN 0b01
#define GPIOBEN 0b10

// APB1 peripheral clock enable register 2 (RCC_APB1ENR2)
#define LPUART1EN 0b01

namespace HAL
{
enum class RCCRegister: size_t
{
    AHB1RSTR    = 0x28,
    AHB2RSTR    = 0x2C,
    AHB3RSTR    = 0x30,
    APB1RSTR1   = 0x38,
    APB1RSTR2   = 0x3C,
    APB2RSTR    = 0x40,
    AHB1ENR     = 0x48,
    AHB2ENR     = 0x4C,
    AHB3ENR     = 0x50,
    APB1ENR1    = 0x58,
    APB1ENR2    = 0x5C,
    APB2ENR     = 0x60,

    FirstReset = AHB1RSTR,
    FirstEnable = AHB1ENR,
};
class RCC: protected Device<RCC, RCCRegister>
{
public:
    enum class Device {
        GPIOA,
        GPIOB,
        LPUART1,
    };
    constexpr static const size_t BASE = 0x40021000;

    static void reset(Device dev, bool asserted) {
        auto [reg, bit] = resetOfDevice(dev);
        RCC::setRegBits(reg, bit, asserted);
    }
    static void enable(Device dev, bool enabled) {
        auto [reg, bit] = enableOfDevice(dev);
        RCC::setRegBits(reg, bit, enabled);
    }
private:
    static constexpr std::pair<RCCRegister, size_t> resetOfDevice(Device dev) {
        switch (dev) {
            case Device::GPIOA:
                return {RCCRegister::AHB2RSTR, 0};
            case Device::GPIOB:
                return {RCCRegister::AHB2RSTR, 1};
            case Device::LPUART1:
                return {RCCRegister::APB1RSTR2, 0};
        }
    }
    static constexpr std::pair<RCCRegister, size_t> enableOfDevice(Device dev) {
        auto [resetReg, bit] = resetOfDevice(dev);
        const auto offset = static_cast<size_t>(RCCRegister::FirstEnable)
                          - static_cast<size_t>(RCCRegister::FirstReset);
        const auto reg = static_cast<size_t>(resetReg) + offset;
        return {static_cast<RCCRegister>(reg), bit};
    }
};
} // namespace HAL
