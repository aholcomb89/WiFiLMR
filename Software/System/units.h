#pragma once
#include <cstddef>

constexpr size_t operator ""_MB(unsigned long long rawValue)
{
    return 1024 * 1024 * rawValue;
}