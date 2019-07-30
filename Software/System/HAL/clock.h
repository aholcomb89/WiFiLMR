#pragma once
#include <cstddef>
#include "units.h"

namespace HAL
{

class Clock
{
public:
    enum class Setting {
        LowSpeed, // 4 MHz, MSI direct (PLL off)
        FullSpeed, // 80 MHz, MSI -> PLL
    };

    static size_t speed();
    static void set(Setting setting);
private:
    static Setting s_currentSetting;
};

} // namespace HAL
