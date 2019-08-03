#pragma once
#include "device.h"

namespace HAL
{
enum class FPURegister
{
    CPACR = 0xED88,
    FPCCR = 0xEF34,
    FPCAR = 0xEF38,
};

class FPU: protected Device<FPU, FPURegister>
{
public:
    constexpr const static size_t BASE = 0xE0000000;
    static void enable(bool enable) {
        FPU::setRegBits(FPURegister::CPACR, {23, 20}, (enable ? 0b1111 : 0));
    }
};

} // namespace HAL
