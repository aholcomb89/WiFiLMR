#pragma once

extern "C" {
void inline __attribute__((naked))
delayLoop(uint32_t count) // actually about 3 cycles/loop
{
    __asm("subs    r0, #1\n"
          "bne     delayLoop\n"
          "bx      lr");
}
}

template<class Position>
constexpr inline size_t setClearBit(size_t curVal, Position position, bool set) {
    const auto flag = static_cast<size_t>(set);
    const size_t mask = (1 << static_cast<size_t>(position));
    return (curVal & ~mask) | (-flag & mask);
}