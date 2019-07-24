#pragma once
#include "device.h"
#include "clock.h"
#include "System/HAL/util.h"

namespace HAL
{
enum class LPUARTRegister
{
    CR1 = 0x00, // Control Register 1
    CR2 = 0x04, // Control Register 2
    CR3 = 0x08, // Control Register 3
    BRR = 0x0C, // Baud Rate Register
    RQR = 0x18, // Request Register
    ISR = 0x1C, // Interrupt & Status Register
    ICR = 0x20, // Interrupt Clear Register
    RDR = 0x24, // Receiver Data Register
    TDR = 0x28, // Transmit Data Register
};

class LPUART: protected Device<LPUART, LPUARTRegister>
{
public:
    constexpr const static size_t BASE = 0x40008000;
    static void enable(bool enable) {
        LPUART::setRegBits(LPUARTRegister::CR1,
            static_cast<size_t>(CR1Bits::UE),
            enable);
    }

    static void enableReceiver(bool enable) {
        LPUART::setRegBits(LPUARTRegister::CR1,
            static_cast<size_t>(CR1Bits::RE),
            enable);
    }

    static void enableTransmitter(bool enable) {
        LPUART::setRegBits(LPUARTRegister::CR1,
            static_cast<size_t>(CR1Bits::TE),
            enable);
    }

    static volatile bool transmitRegisterEmpty() {
        return LPUART::getRegBits(LPUARTRegister::ISR, static_cast<size_t>(ISRBits::TXE)) & 0b01;
    }

    static void writeByte(char byte_) {
        while (!transmitRegisterEmpty()) {};
        (*regAddr(LPUARTRegister::TDR)) = byte_;
    }

    static void setBaudRate(size_t baud) {
        s_savedBaudRate = baud;
        (*regAddr(LPUARTRegister::BRR)) = (256 * Clock::speed()) / baud;
    }

    static void clockSpeedChanged() {
        setBaudRate(s_savedBaudRate);
    }
private:
    enum class CR1Bits {
        UE      = 0x00, // UART Enable
        UESM    = 0x01, // UART Enable in Stop Mode
        RE      = 0x02, // Receiver Enable
        TE      = 0x03, // Transmitter Enable
        IDLEIE  = 0x04, // IDLE Interrupt Enable
        RXNEIE  = 0x05, // RXNE Interrupt Enable
        TCIE    = 0x06, // Transmission Complete Interrupt Enable
        TXEIE   = 0x07, // TXE Interrupt Enable
        PEIE    = 0x08, // PE Interrupt Enable
        PS      = 0x09, // Parity Selection
        PCE     = 0x0A, // Parity Control Enable
        WAKE    = 0x0B, // Receiver wakeup method
        M0      = 0x0C, // Word length
        MME     = 0x0D, // Mute Mode Enable
        CMIE    = 0x0E, // Character Match Interrupt Enable
    };
    enum class ISRBits {
        TXE     = 0x07, // Transmit data register Empty
    };
    static size_t s_savedBaudRate;
};
} // namespace HAL
