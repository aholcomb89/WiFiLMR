#pragma once
#include "lpuart.h"

namespace HAL
{
template<class Device, class... Devices>
class ClockDevice {
public:
    static void alertDevices(size_t mhz) {
        Device::clockSpeedChanged(mhz);
        ClockDevices<Devices>::alertDevices(mhz);
    }
};

using ClockDevices = ClockDevice<LPUART>;

} // namespace HAL
