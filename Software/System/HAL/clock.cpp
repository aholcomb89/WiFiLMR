#include "units.h"
#include "clock.h"
#include "rcc.h"
#include "flash.h"
#include "clock_devices.h"

using namespace HAL;

Clock::Setting Clock::s_currentSetting = Clock::Setting::LowSpeed;

size_t Clock::speed()
{
    switch (s_currentSetting) {
        case Setting::LowSpeed:
            return 4_Mhz;
        case Setting::FullSpeed:
            return 80_Mhz;
    }
}

void Clock::set(Clock::Setting setting)
{
    switch (setting) {
        case Setting::LowSpeed:
            RCC::setSysClockSource(RCC::SysClockSource::MSI);
            Flash::setWaitStates(0);
            RCC::setPLLOn(false);
            RCC::setPLLSrc(RCC::PLLSrc::None);
            s_currentSetting = Setting::LowSpeed;
            ClockDevices::alertDevices();
            break;
        case Setting::FullSpeed:
            RCC::setPLLOn(false);
            while (RCC::getPLLReady()) {};
            RCC::setPLLSrc(RCC::PLLSrc::MSI);
            RCC::setPLLInputDivider(1);
            RCC::setMainPLLVCOMultiplier(40);
            RCC::setPLLPostDivider(RCC::PLLPostDivider::By2);
            RCC::setPLLOn(true);
            while (!(RCC::getPLLReady())) {};
            RCC::enableMainPLLOutput(true);
            Flash::setWaitStates(4);
            RCC::setSysClockSource(RCC::SysClockSource::PLL);
            s_currentSetting = Setting::FullSpeed;
            ClockDevices::alertDevices();
            break;
    }
}
