#pragma once
#include "lpuart.h"
#include "spi.h"

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

using ClockDevices = ClockDevice<LPUART, SPI1, SPI2, SPI3>;

} // namespace HAL
