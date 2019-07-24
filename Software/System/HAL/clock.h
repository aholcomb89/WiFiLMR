#pragma once
#include <cstddef>

namespace HAL
{

class Clock
{
public:
    constexpr static size_t speed() { return 4000000u; }
};

} // namespace HAL
