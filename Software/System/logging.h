#pragma once
#include "HAL/lpuart.h"
#include "picofmt.h"
#include <utility>

namespace Log
{
void init(); // Call once before logging anything
inline void writeString(const char * buffer, size_t size)
{
    for (auto i = 0u; i < size; i++) {
        HAL::LPUART::writeByte(buffer[i]);
        delayLoop(100);
    }
}

template<class... Args>
void log(const char * format, Args... args)
{
    picofmt::Formatter fmt(writeString);
    fmt.printf(format, args...);
}

} // namespace Log
