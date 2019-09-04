#pragma once

#include "device.h"

namespace HAL
{
enum class DMARegisters {
    ISR     = 0x00,
    IFCR    = 0x04,
    CSELR   = 0xA8

};

namespace DMAChannelSelects
{
enum class DMA1 {
    Chan1_ADC1      = 0b0000,
    Chan1_TIM2_CH3  = 0b0100,
    Chan2_SPI1_RX   = 0b0001,
    Chan2_USART3_TX = 0b0010,
    Chan2_I2C3_TX   = 0b0011,
    Chan2_TIM2_UP   = 0b0100,
    Chan2_TIM3_CH3  = 0b0101,
    Chan2_TIM1_CH1  = 0b0111,
    Chan3_SPI_TX    = 0b0001,
    Chan3_USART3_RX = 0b0010,
    Chan3_I2C3_RX   = 0b0011,
    Chan3_TIM16_CH1 = 0b0100,
    Chan3_TIM16_UP  = 0b0100,
    Chan3_TIM3_CH4  = 0b0101,
    Chan3_TIM3_UP   = 0b0101,
    Chan3_TIM6_UP   = 0b0110,
    Chan3_DAC_CH1   = 0b0110,
    Chan3_TIM1_CH2  = 0b0111,
    Chan4_SPI2_RX   = 0b0001,
    Chan4_USART1_TX = 0b0010,
    Chan4_I2C2_TX   = 0b0011,
    Chan4_TIM7_UP   = 0b0101,
    Chan4_TIM1_CH4  = 0b0111,
    Chan4_TIM1_TRIG = 0b0111,
    Chan4_TIM1_COM  = 0b0111,
};

enum class DMA2 {
};
} // namespace DMA1ChannelSelects


template <size_t BaseAddr, class ChannelSelectsType>
class DMA : protected Device<DMA<BaseAddr, ChannelSelectsType>, DMARegisters>
{
public:
    enum class Channel {
        Chan1   = 1,
        Chan2   = 2,
        Chan3   = 3,
        Chan4   = 4,
        Chan5   = 5,
        Chan6   = 6,
        Chan7   = 7
    };
    enum class Priority {
        Low         = 0b00,
        Medium      = 0b01,
        High        = 0b10,
        VeryHigh    = 0b11
    };
    enum class WordSize {
        _8bits  = 0b00,
        _16bits = 0b01,
        _32bits = 0b10
    };
    enum class Direction {
        Peripheral2Mem = 0,
        Mem2Peripheral = 1
    };
    constexpr static size_t BASE = BaseAddr;
    using Registers = DMARegisters;
    using ChannelSelects = ChannelSelectsType;

    static void setMemToMemEnable(Channel channel, bool enabled) {
        DMA::setRegBits(channelReg(channel, ChannelReg::CCR),
                        static_cast<size_t>(CCRBits::MEM2MEM),
                        enabled);
    }
    static void setPriority(Channel channel, Priority priority) {
        DMA::setRegBits(channelReg(channel, ChannelReg::CCR),
                        {
                            static_cast<size_t>(CCRBits::PL_MSB),
                            static_cast<size_t>(CCRBits::PL_LSB)
                        },
                        static_cast<size_t>(priority));
    }
    static void setMemorySize(Channel channel, WordSize size) {
        DMA::setRegBits(channelReg(channel, ChannelReg::CCR),
                        {
                            static_cast<size_t>(CCRBits::MSIZE_MSB),
                            static_cast<size_t>(CCRBits::MSIZE_LSB)
                        },
                        static_cast<size_t>(size));
    }
    static void setPeripheralSize(Channel channel, WordSize size) {
        DMA::setRegBits(channelReg(channel, ChannelReg::CCR),
                        {
                            static_cast<size_t>(CCRBits::PSIZE_MSB),
                            static_cast<size_t>(CCRBits::PSIZE_LSB)
                        },
                        static_cast<size_t>(size));
    }
    static void setMemoryAutoIncrement(Channel channel, bool enabled) {
        DMA::setRegBits(channelReg(channel, ChannelReg::CCR),
                        static_cast<size_t>(CCRBits::MINC),
                        enabled);
    }
    static void setMemoryAddress(Channel channel, void * addr) {
        DMA::setRegBits(channelReg(channel, ChannelReg::CMAR),
                        {31, 0},
                        reinterpret_cast<size_t>(addr));
    }
    static void setPeripheralAutoIncrement(Channel channel, bool enabled) {
        DMA::setRegBits(channelReg(channel, ChannelReg::CCR),
                        static_cast<size_t>(CCRBits::PINC),
                        enabled);
    }
    static void setPeripheralAddress(Channel channel, void * addr) {
        DMA::setRegBits(channelReg(channel, ChannelReg::CPAR),
                        {31, 0},
                        reinterpret_cast<size_t>(addr));
    }
    static void enableChannel(Channel channel, bool enabled) {
        DMA::setRegBits(channelReg(channel, ChannelReg::CCR),
                        static_cast<size_t>(CCRBits::EN),
                        enabled);
    }
    static void setChannelSelection(Channel channel, ChannelSelects cs) {
        DMA::setRegBits(DMARegisters::CSELR,
                   channelSelectBits(channel),
                   static_cast<size_t>(cs));
    }
    static void setCircularMode(Channel channel, bool enabled) {
        DMA::setRegBits(channelReg(channel, ChannelReg::CCR),
                        static_cast<size_t>(CCRBits::CIRC),
                        enabled);
    }
    static void setItemCount(Channel channel, uint16_t itemCount) {
        DMA::setRegBits(channelReg(channel, ChannelReg::CNDTR),
                        {15, 0},
                        itemCount);
    }
    static void setDirection(Channel channel, Direction direction) {
        DMA::setRegBits(channelReg(channel, ChannelReg::CCR),
                        static_cast<size_t>(CCRBits::DIR),
                        static_cast<size_t>(direction));
    }
private:
    enum class ChannelReg {
        CCR     = 0x08,
        CNDTR   = 0x0C,
        CPAR    = 0x10,
        CMAR    = 0x14
    };
    enum class CCRBits {
        MEM2MEM     = 14,
        PL_MSB      = 13,
        PL_LSB      = 12,
        MSIZE_MSB   = 11,
        MSIZE_LSB   = 10,
        PSIZE_MSB   =  9,
        PSIZE_LSB   =  8,
        MINC        =  7,
        PINC        =  6,
        CIRC        =  5,
        DIR         =  4,
        TEIE        =  3,
        HTIE        =  2,
        TCIE        =  1,
        EN          =  0
    };
    // channel is 1-indexed
    constexpr static DMARegisters channelReg(Channel channel, ChannelReg reg) {
        return static_cast<DMARegisters>(
            static_cast<size_t>(reg) 
            + 0x14 
            * (static_cast<size_t>(channel) - 1));
    }
    constexpr static Bits channelSelectBits(Channel channel) {
        auto const lsb = (static_cast<unsigned>(channel) - 1) * 4;
        auto const msb = (static_cast<unsigned>(channel) * 4) - 1;
        return {msb, lsb};
    }
};

using DMA1 = DMA<0x40020000, DMAChannelSelects::DMA1>;
using DMA2 = DMA<0x40020400, DMAChannelSelects::DMA2>;

} // namespace HAL
