#pragma once

#include "device.h"

namespace HAL
{
enum class SPIRegister
{
    CR1     = 0x00,
    CR2     = 0x04,
    SR      = 0x08,
    DR      = 0x0C,
    CRCPR   = 0x10,
    RXCRCR  = 0x14,
    TXCRCR  = 0x18
};

template <class Derived>
class SPI: public Device<Derived, SPIRegister>
{
public:
    enum class BaudDivisor {
        By2     = 0b000,
        By4     = 0b001,
        By8     = 0b010,
        By16    = 0b011,
        By32    = 0b100,
        By64    = 0b101,
        By128   = 0b110,
        By256   = 0b111
    };

    using Register = SPIRegister;

    static void setCPOL(bool idleAtHigh) { // 0 for idle at low, 1 for high
        SPI::setRegBits(SPIRegister::CR1, static_cast<size_t>(CR1Bits::CPOL), idleAtHigh);
    }

    static void setCPHA(bool secondEdge) { // 0 for first edge, 1 for second
        SPI::setRegBits(SPIRegister::CR1, static_cast<size_t>(CR1Bits::CPHA), secondEdge);
    }

    static void setBaudDivisor(BaudDivisor div) {
        SPI::setRegBits(SPIRegister::CR1,
                        {
                            static_cast<size_t>(CR1Bits::BR_MSB),
                            static_cast<size_t>(CR1Bits::BR_LSB)
                        },
                        div);
    }

    static void setMaster(bool isMaster) {
        SPI::setRegBits(SPIRegister::CR1, static_cast<size_t>(CR1Bits::MSTR), isMaster);
    }

    static void setDataSize(unsigned bits) {
        if (bits < 4 || bits > 16) {
            return; // out of range
        }
        bits--; // DS is off by one
        SPI::setRegBits(SPIRegister::CR2,
                        {
                            static_cast<size_t>(CR2Bits::DS_MSB),
                            static_cast<size_t>(CR2Bits::DS_LSB)
                        },
                        bits & 0b1111);
    }

    static uint32_t getTxFIFOLevel() {
        return SPI::getRegBits(SPIRegister::SR,
                              {
                                static_cast<size_t>(SRBits::FTLVL_MSB),
                                static_cast<size_t>(SRBits::FTLVL_LSB)
                              });
    }

    static bool getTxEmpty() {
        return SPI::getRegBits(SPIRegister::SR,
                               static_cast<size_t>(SRBits::TXE));
    }

    static void pioWrite(uint32_t word) {
        while (!getTxEmpty()) {};
        (*SPI::regAddr(SPIRegister::DR)) = word;
    }

    static void setEnable(bool enable) {
        SPI::setRegBits(SPIRegister::CR1,
                        static_cast<size_t>(CR1Bits::SPE),
                        enable);
    }

    static void setSSI(bool enable) {
        SPI::setRegBits(SPIRegister::CR1,
                        static_cast<size_t>(CR1Bits::SSI),
                        enable);
    }

    static void setSSM(bool enable) {
        SPI::setRegBits(SPIRegister::CR1,
                        static_cast<size_t>(CR1Bits::SSM),
                        enable);
    }

    static void setBaudRate(uint32_t baud) {
        s_savedBaud = baud;
        auto clk = Clock::speed();
        if (baud >= clk) {
            // requested a baud rate higher than system clock
            // set to max (div 2)
            setBaudDivisor(BaudDivisor::By2);
            return;
        }
        auto div = 0;
        do {
            baud <<= 1;
            div++;
        } while (clk > baud && div < 8);
        if (div >= 8) {
            // requested a baud rate too low to satisfy
            // set to min (div 256)
            setBaudDivisor(BaudDivisor::By256);
            return;
        }
        setBaudDivisor(static_cast<BaudDivisor>(div));
    }

    static void clockSpeedChanged() {
        if (HAL::RCC::isEnabled(Derived::RCC_DEVICE)) {
            setBaudRate(s_savedBaud);
        }
    }

private:
    enum class CR1Bits
    {
        BIDIMODE    = 15,
        BIDIOE      = 14,
        CRCEN       = 13,
        CRCNEXT     = 12,
        CRCL        = 11,
        RXONLY      = 10,
        SSM         = 9,
        SSI         = 8,
        LSBFIRST    = 7,
        SPE         = 6,
        BR_MSB      = 5,
        BR_LSB      = 3,
        MSTR        = 2,
        CPOL        = 1,
        CPHA        = 0
    };

    enum class CR2Bits {
        LDMA_TX = 14,
        LDMA_RX = 13,
        FRXTH   = 12,
        DS_MSB  = 11,
        DS_LSB  =  8,
        TXEIE   =  7,
        RXNEIE  =  6,
        ERRIE   =  5,
        FRF     =  4,
        NSSP    =  3,
        SSOE    =  2,
        TXDMAEN =  1,
        RXDMAEN =  0
    };

    enum class SRBits {
        FTLVL_MSB = 12,
        FTLVL_LSB = 11,
        FRLVL_MSB = 10,
        FRLVL_LSB =  9,
        FRE       =  8,
        BSY       =  7,
        OVR       =  6,
        MODF      =  5,
        CRCERR    =  4,
        TXE       =  1,
        RXNE      =  0
    };

    static inline uint32_t s_savedBaud = 0;
};

struct SPI1 : public SPI<SPI1>
{
    constexpr static size_t BASE = 0x40013000;
    constexpr static auto RCC_DEVICE = HAL::RCC::Device::SPI1;
};

struct SPI2 : public SPI<SPI2>
{
    constexpr static size_t BASE = 0x40003800;
    constexpr static auto RCC_DEVICE = HAL::RCC::Device::SPI2;
};

struct SPI3 : public SPI<SPI3>
{
    constexpr static size_t BASE = 0x40003C00;
    constexpr static auto RCC_DEVICE = HAL::RCC::Device::SPI3;
};

} // namespace HAL
