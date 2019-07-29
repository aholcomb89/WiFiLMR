#pragma once
#include <cstddef>

constexpr size_t operator ""_MB(unsigned long long rawValue)
{
    return 1024 * 1024 * rawValue;
}

constexpr size_t operator ""_khz(unsigned long long rawValue)
{
    return 1000 * rawValue;
}

constexpr size_t operator ""_Mhz(unsigned long long rawValue)
{
    return 1000_khz * rawValue;
}
