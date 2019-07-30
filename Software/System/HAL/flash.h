#pragma once
#include "device.h"
namespace HAL
{
enum class FlashRegisters {
    ACR     = 0x00,
};
class Flash: public Device<Flash, FlashRegisters>
{
public:
    constexpr const static size_t BASE = 0x40022000;

    static void setWaitStates(size_t waitStates) {
        Flash::setRegBits(FlashRegisters::ACR, {2, 0}, waitStates);
    }
};
} // namespace HAL
