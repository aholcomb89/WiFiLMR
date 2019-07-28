#include <unistd.h>
#include <string.h>
#include <type_traits>

namespace picofmt
{
using OutputFunc = void (*)(const char*, size_t);

namespace types {
template<class IntType>
inline char toAscii(IntType val, size_t base) {
    if (val < 10) {
        return val + '0';
    } else if (val < 0x10) {
        return (val - 10) + 'a';
    }
    return 'X';
}

template <class IntType, size_t Base, std::enable_if_t<std::is_integral_v<IntType>, int> = 0>
struct IntFmt {
    constexpr IntFmt(IntType i, size_t fixedPlaces = 0)
        : value(i)
        , fixedPlaces(fixedPlaces) {}
    const IntType value;
    const size_t fixedPlaces;
};

template <class IntType>
constexpr IntFmt<IntType, 10> Int(IntType v) { return IntFmt<IntType, 10> (v); }

template <class IntType>
constexpr IntFmt<IntType, 16> Hex(IntType v) { return IntFmt<IntType, 16> (v); }

template <class PtrType>
constexpr IntFmt<size_t, 16> Ptr(PtrType v) { return IntFmt<size_t, 16>(reinterpret_cast<size_t>(v), sizeof(v) * 2); }

template <class IntType, size_t Base>
inline void formatType(OutputFunc out, IntFmt<IntType, Base> x)
{
    auto val = x.value;
    constexpr auto BITS_PER_BYTE = 8;
    constexpr auto LOG_10_2 = 3; // log10(2) * 10; estimate of how many chars/bit
    constexpr auto bufSize = (sizeof(val) * BITS_PER_BYTE * LOG_10_2) / 10 + 1;
    char buf[bufSize];
    auto place = 0u;
    do {
        place++;
        buf[bufSize - place] = toAscii(val % Base, Base);
        val /= Base;
    } while (val > 0);
    for (; place <= x.fixedPlaces; place++) {
        buf[bufSize - place] = '0';
    }
    out(&(buf[bufSize - place]), place);
}

template <class IntType, std::enable_if_t<std::is_integral_v<IntType>, int> = 0>
inline void formatType(OutputFunc out, IntType i)
{
    formatType(out, IntFmt<IntType, 10>(i));
}

inline void formatType(OutputFunc out, const char * x)
{
    out(x, strlen(x));
}

template <class PtrType, std::enable_if_t<std::is_pointer_v<PtrType> && !std::is_same_v<const char *, PtrType>, int> = 0>
inline void formatType(OutputFunc out, PtrType p)
{
    formatType(out, Ptr(p));
}
} // types

class Formatter
{
public:
    constexpr Formatter(OutputFunc out)
        : m_output(out) {}
    inline void printf(const char * format)
    {
        m_output(format, strlen(format));
    }
    template <class T, class... Ts>
    inline void printf(const char * format, T argument, Ts... arguments)
    {
        auto start = format;
        for (; *format != '\0'; format++) {
            if (*format == '%') {
                m_output(start, format - start);
                picofmt::types::formatType(m_output, argument);
                printf(format+1, arguments...);
                return;
            }
        }
        m_output(start, format - start);
    }
private:
    const OutputFunc m_output;
};
} // picofmt
