#pragma once
#include <utility>
#include "device.h"
#include "units.h"
#include "logging.h"


namespace HAL
{
enum class RCCRegister: size_t
{
    CR          = 0x00,
    CFGR        = 0x08,
    PLLCFGR     = 0x0C,
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
    CSR         = 0x94,

    FirstReset = AHB1RSTR,
    FirstEnable = AHB1ENR,
};
class RCC: protected Device<RCC, RCCRegister>
{
public:
    enum class Device {
        DAC1,
        DMA1,
        DMA2,
        GPIOA,
        GPIOB,
        GPIOC,
        GPIOD,
        GPIOE,
        GPIOH,
        LPUART1,
        SPI1,
        SPI2,
        SPI3,
        TIM1,
        TIM2,
        TIM3,
        TIM6,
        TIM7,
        TIM15,
        TIM16,
    };

    enum class MsiRangeReg {
        CSR = 0b00,
        CR  = 0b01
    };

    enum class MsiRange {
        _100khz = 0b0000,
        _200khz = 0b0001,
        _400khz = 0b0010,
        _800khz = 0b0011,
        _1Mhz   = 0b0100,
        _2Mhz   = 0b0101,
        _4Mhz   = 0b0110,
        _8Mhz   = 0b0111,
        _16Mhz  = 0b1000,
        _24Mhz  = 0b1001,
        _32Mhz  = 0b1010,
        _48Mhz  = 0b1011
    };

    enum class SysClockSource {
        MSI   = 0b00,
        HSI16 = 0b01,
        HSE   = 0b10,
        PLL   = 0b11
    };

    enum class PLLPostDivider {
        By2   = 0b00,
        By4   = 0b01,
        By6   = 0b10,
        By8   = 0b11
    };

    enum class PLLSrc {
        None  = 0b00,
        MSI   = 0b01,
        HSI16 = 0b10,
        HSE   = 0b11
    };

    constexpr static size_t toMhz(MsiRange range) {
        switch (range) {
            case MsiRange::_100khz:
                return 100_khz;
            case MsiRange::_200khz:
                return 200_khz;
            case MsiRange::_400khz:
                return 400_khz;
            case MsiRange::_800khz:
                return 800_khz;
            case MsiRange::_1Mhz:
                return 1_Mhz;
            case MsiRange::_2Mhz:
                return 2_Mhz;
            case MsiRange::_4Mhz:
                return 4_Mhz;
            case MsiRange::_8Mhz:
                return 8_Mhz;
            case MsiRange::_16Mhz:
                return 16_Mhz;
            case MsiRange::_24Mhz:
                return 24_Mhz;
            case MsiRange::_32Mhz:
                return 32_Mhz;
        }
    }

    constexpr static const size_t BASE = 0x40021000;

    // Control Register (CR)

    static bool getPLLReady() {
        return RCC::getRegBits(RCCRegister::CR, 25);
    }

    static bool getPLLOn() {
        return RCC::getRegBits(RCCRegister::CR, 24);
    }

    static void setPLLOn(bool on) {
        RCC::setRegBits(RCCRegister::CR, 24, on);
    }

    static MsiRange getMsiRangeFromCR() {
        return static_cast<MsiRange>(RCC::getRegBits(RCCRegister::CR, {7, 4}));
    }

    static MsiRangeReg getMsiRangeReg() {
        return static_cast<MsiRangeReg>(RCC::getRegBits(RCCRegister::CR, 3));
    }

    // Configuration Register (CFGR)
    static SysClockSource getSysClockSource() {
        return static_cast<SysClockSource>(RCC::getRegBits(RCCRegister::CFGR, {3, 2}));
    }

    static void setSysClockSource(SysClockSource src) {
        RCC::setRegBits(RCCRegister::CFGR, {1, 0}, src);
    }

    // PLL Configuration Register (PLLCFGR)
    static PLLPostDivider getPLLPostDivider() {
        return static_cast<PLLPostDivider>(RCC::getRegBits(RCCRegister::PLLCFGR, {26, 25}));
    }

    static void setPLLPostDivider(PLLPostDivider div) {
        RCC::setRegBits(RCCRegister::PLLCFGR, {26, 25}, div);
    }

    static void enableMainPLLOutput(bool isEnabled) {
        if (getSysClockSource() != SysClockSource::PLL) {
            RCC::setRegBits(RCCRegister::PLLCFGR, 24, isEnabled);
        } else {
            Log::log("Error: enableMainPLL called while SYSCLK is PLL\r\n");
        }
    }

    static size_t getMainPLLVCOMultiplier() {
        return RCC::getRegBits(RCCRegister::PLLCFGR, {14, 8});
    }

    static void setMainPLLVCOMultiplier(size_t mult) {
        if (mult >= 8 && mult <= 86) {
            RCC::setRegBits(RCCRegister::PLLCFGR, {14, 8}, mult);
        } else {
            Log::log("Error: set PLLN with invalid value: %", mult);
        }
    }

    static size_t getPLLInputDivider() {
        return RCC::getRegBits(RCCRegister::PLLCFGR, {6, 4}) + 1;
    }

    static void setPLLInputDivider(size_t divider) {
        if (divider > 0 && divider <= 8) {
            RCC::setRegBits(RCCRegister::PLLCFGR, {6, 4}, divider - 1);
        } else {
            Log::log("Error: set PLLM with invalid value: %", divider);
        }
    }

    static PLLSrc getPLLSrc() {
        return static_cast<PLLSrc>(RCC::getRegBits(RCCRegister::PLLCFGR, {1, 0}));
    }

    static void setPLLSrc(PLLSrc src) {
        RCC::setRegBits(RCCRegister::PLLCFGR, {1, 0}, src);
    }

    // Reset Registers (*RSTR)
    static void reset(Device dev, bool asserted) {
        auto [reg, bit] = resetOfDevice(dev);
        RCC::setRegBits(reg, bit, asserted);
    }

    // Enable Registers (*ENR*)
    static void enable(Device dev, bool enabled) {
        auto [reg, bit] = enableOfDevice(dev);
        RCC::setRegBits(reg, bit, enabled);
    }

    static bool isEnabled(Device dev) {
        auto [reg, bit] = enableOfDevice(dev);
        return RCC::getRegBits(reg, bit);
    }

    // Control & Status Register (CSR)
    static MsiRange getMsiRangeFromCSR() {
        return static_cast<MsiRange>(RCC::getRegBits(RCCRegister::CSR, {11, 8}));
    }

    // Helpers
    static size_t getPLLSrcFreq() {
        switch (getPLLSrc()) {
            case PLLSrc::None:
                return 0;
            case PLLSrc::MSI:
                return toMhz(getMSIRange());
            case PLLSrc::HSI16:
                return 0; // not implemented
            case PLLSrc::HSE:
                return 0; // not implemented
        }
    }

    static size_t getPLLOutputFreq() {
        const auto vcoInput = getPLLSrcFreq() / getPLLInputDivider();
        const auto vcoOutput = vcoInput * getMainPLLVCOMultiplier();
        const auto postDivider = (static_cast<size_t>(getPLLPostDivider()) + 1) * 2;
        return (vcoOutput == 0) ? 0 : vcoOutput / postDivider;
    }

    static MsiRange getMSIRange() {
        switch (getMsiRangeReg()) {
            case MsiRangeReg::CR:
                return getMsiRangeFromCR();
            case MsiRangeReg::CSR:
                return getMsiRangeFromCSR();
        }
    }

private:
    static constexpr std::pair<RCCRegister, size_t> resetOfDevice(Device dev) {
        switch (dev) {
            case Device::DAC1:
                return {RCCRegister::APB1RSTR1, 29};
            case Device::DMA1:
                return {RCCRegister::AHB1RSTR, 0};
            case Device::DMA2:
                return {RCCRegister::AHB1RSTR, 1};
            case Device::GPIOA:
                return {RCCRegister::AHB2RSTR, 0};
            case Device::GPIOB:
                return {RCCRegister::AHB2RSTR, 1};
            case Device::GPIOC:
                return {RCCRegister::AHB2RSTR, 2};
            case Device::GPIOD:
                return {RCCRegister::AHB2RSTR, 3};
            case Device::GPIOE:
                return {RCCRegister::AHB2RSTR, 4};
            case Device::GPIOH:
                return {RCCRegister::AHB2RSTR, 7};
            case Device::LPUART1:
                return {RCCRegister::APB1RSTR2, 0};
            case Device::SPI1:
                return {RCCRegister::APB2RSTR, 12};
            case Device::SPI2:
                return {RCCRegister::APB1RSTR1, 14};
            case Device::SPI3:
                return {RCCRegister::APB1RSTR1, 15};
            case Device::TIM1:
                return {RCCRegister::APB2RSTR, 11};
            case Device::TIM2:
                return {RCCRegister::APB1RSTR1, 0};
            case Device::TIM3:
                return {RCCRegister::APB1RSTR1, 1};
            case Device::TIM6:
                return {RCCRegister::APB1RSTR1, 4};
            case Device::TIM7:
                return {RCCRegister::APB1RSTR1, 5};
            case Device::TIM15:
                return {RCCRegister::APB2RSTR, 16};
            case Device::TIM16:
                return {RCCRegister::APB2RSTR, 17};
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
