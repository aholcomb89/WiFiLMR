#pragma once
#include "lpuart.h"

namespace HAL
{
template<class Device, class... Devices>
class ClockDevice {
public:
    static void alertDevices() {
        Device::clockSpeedChanged();
        if constexpr (sizeof...(Devices) > 0) {
            ClockDevice<Devices...>::alertDevices();
        }
    }
};

using ClockDevices = ClockDevice<LPUART>;

} // namespace HAL
