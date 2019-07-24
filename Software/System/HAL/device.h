#pragma once
#include <cstdint>
#include "System/units.h"

namespace HAL
{
struct Bits
{
    constexpr explicit Bits(size_t bit)
        : MSB(bit)
        , LSB(bit) {};
    constexpr Bits(size_t msb, size_t lsb)
        : MSB(msb)
        , LSB(lsb) {};
    const size_t MSB;
    const size_t LSB;

    constexpr uint32_t size() {
        return MSB - LSB + 1;
    }

    constexpr uint32_t mask() {
        return (~(~0u << size())) << LSB;
    }
};

template <class Derived, class RegType>
class Device
{
protected:
    template <class Value>
    static inline volatile void setRegBits(RegType reg, size_t bit, Value value) {
        if constexpr (Derived::BASE < (PERIPH_BASE + 1_MB)) {
            const auto addr = Device::bitBandedRegBit(reg, bit);
            *addr = static_cast<size_t>(value);
        } else {
            setRegBits(reg, Bits(bit), value);
        }
    }

    template <class Value>
    static inline volatile void setRegBits(RegType reg, Bits bits, Value value) {
        const auto shiftedVal = static_cast<uint32_t>(value) << bits.LSB;
        const auto addr = Device::regAddr(reg);
        *addr = (*addr & ~bits.mask()) | shiftedVal;
    }

    static inline volatile size_t getRegBits(RegType reg, size_t bit) {
        if constexpr (Derived::BASE < (PERIPH_BASE + 1_MB)) {
            const auto addr = Device::bitBandedRegBit(reg, bit);
            return *addr;
        } else {
            return getRegBits(reg, Bits(bit));
        }
    }

    static inline volatile size_t getRegBits(RegType reg, Bits bits) {
        const auto addr = Device::regAddr(reg);
        return (*addr) & bits.mask();
    }

    static volatile uint32_t* regAddr(RegType reg) {
        return reinterpret_cast<uint32_t*>(Derived::BASE + static_cast<size_t>(reg));
    }
private:
    constexpr const static size_t PERIPH_BASE          = 0x40000000;
    constexpr const static size_t PERIPH_BIT_BAND_BASE = 0x42000000;
private:
    static volatile uint32_t* bitBandedRegBit(RegType reg, size_t bitIndex) {
        const auto byteOffset = (Derived::BASE - PERIPH_BASE)
                              + static_cast<size_t>(reg)
                              + (bitIndex >> 3);
        bitIndex = bitIndex % 8;
        return reinterpret_cast<volatile uint32_t*>(PERIPH_BIT_BAND_BASE + (32 * byteOffset) + (4 * bitIndex));
    }
};
} // namespace HAL
