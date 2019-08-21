#include "logging.h"
#include "HAL/rcc.h"
#include "HAL/gpio.h"
#include "HAL/lpuart.h"

void Log::init()
{
    HAL::RCC::enable(HAL::RCC::Device::GPIOA, true);
    HAL::GPIOA::setAltFunc(2, HAL::GPIOA::AltFunc::AF8); // LPUART1_TX
    HAL::GPIOA::setAltFunc(3, HAL::GPIOA::AltFunc::AF8); // LPUART1_RX
    HAL::GPIOA::setMode(2, HAL::GPIOA::Mode::Alt);
    HAL::GPIOA::setMode(3, HAL::GPIOA::Mode::Alt);
    HAL::GPIOA::setPullup(2, HAL::GPIOA::Pullup::Up);
    HAL::GPIOA::setPullup(3, HAL::GPIOA::Pullup::Up);
    HAL::RCC::enable(HAL::RCC::Device::LPUART1, true);
    HAL::LPUART::setBaudRate(115200);
    HAL::LPUART::enable(true);
    HAL::LPUART::enableTransmitter(true);
}
