#include "opus.h"
#include "FreeRTOSConfig.h"
#include "FreeRTOS.h"
#include "portable.h" // pvPortMalloc
#include "task.h"
#include "HAL/memory_map.h"
#include "HAL/rcc.h"
#include "HAL/gpio.h"
#include "HAL/clock.h"
#include "HAL/fpu.h"
#include "HAL/spi.h"
#include "HAL/timer.h"
#include "HAL/dac.h"
#include "HAL/dma.h"
#include "logging.h"
#include "units.h"


static opus_int16 samples[160];
static uint8_t output[4000];
uint16_t srand(void)
{
    static uint16_t state = 0xACE1u;
    uint16_t bit = bit = ((state >> 0) ^ (state >> 2) ^ (state >> 3) ^ (state >> 5));
    state = (state >> 1) | (bit << 15);
    return state;
}
extern "C" {
void *opus_alloc_scratch (size_t size)
{
   /* Scratch space doesn't need to be cleared */
   return pvPortMalloc(size);
}
}
// void opusBenchTask(void *pvParameters)
// {
//     OpusEncoder *encoder = reinterpret_cast<OpusEncoder*>(pvPortMalloc(opus_encoder_get_size(1)));
//     OpusDecoder *decoder = reinterpret_cast<OpusDecoder*>(pvPortMalloc(opus_decoder_get_size(1)));
//     int ret = opus_encoder_init(encoder, 8000, 1, OPUS_APPLICATION_VOIP);
//     ret |= opus_decoder_init(decoder, 8000, 1);
//     if (ret != OPUS_OK) {
//         UARTprintf("Ooops! Opus fucked up\r\n");
//         while (1) {};
//     }
//     opus_encoder_ctl(encoder, OPUS_SET_COMPLEXITY(0));
//     opus_encoder_ctl(encoder, OPUS_SET_MAX_BANDWIDTH(OPUS_BANDWIDTH_NARROWBAND));
//     //
//     // We are finished.  Hang around doing nothing.
//     //
//     while(1)
//     {
//         for (size_t i = 0; i < sizeof(samples)/sizeof(samples[0]); i++) {
//             samples[i] = srand();
//         }
//         TickType_t startTime = xTaskGetTickCount();
//         int bytes = opus_encode(encoder, samples, sizeof(samples)/sizeof(samples[0]), output, sizeof(output));
//         TickType_t endTime = xTaskGetTickCount();

//         UARTprintf("Encoded 20ms of audio in %dms to get %d bytes\r\n", endTime - startTime, bytes);

//         startTime = xTaskGetTickCount();
//         bytes = opus_decode(decoder, output, bytes, samples, sizeof(samples)/sizeof(samples[0]), 0);
//         endTime = xTaskGetTickCount();

//         UARTprintf("Decoded 20ms of audio in %dms\r\n", endTime - startTime);

//         //
//         // Turn on the BLUE LED.
//         //
//         GPIOPinWrite(GPIO_PORTN_BASE, GPIO_PIN_1, GPIO_PIN_1);

//         //
//         // Delay for a bit.
//         //
//         // vTaskDelay(pdMS_TO_TICKS(1000));
//         //
//         // Turn off the BLUE LED.
//         //
//         GPIOPinWrite(GPIO_PORTN_BASE, GPIO_PIN_1, 0);

//         //
//         // Delay for a bit.
//         //
//         // vTaskDelay(pdMS_TO_TICKS(1000));
//     }
// }

void taskBlinky(void */*pvParameters*/)
{
    HAL::RCC::enable(HAL::RCC::Device::GPIOB, true);
    HAL::GPIOB::setMode(13, HAL::GPIOB::Mode::Output);
    auto isOn = true;
    while (1) {
        HAL::GPIOB::setOutput(13, isOn);
        isOn = !isOn;
        vTaskDelay(pdMS_TO_TICKS(1000));
    }
}

void taskScreenThingy(void */*pvParameters*/)
{
    // Enable GPIOB and SPI1
    HAL::RCC::enable(HAL::RCC::Device::GPIOB, true);
    HAL::RCC::enable(HAL::RCC::Device::SPI1, true);
    HAL::GPIOB::setAltFunc(3, HAL::GPIOB::AltFunc::AF5); // SPI_SCK
    HAL::GPIOB::setAltFunc(4, HAL::GPIOB::AltFunc::AF5); // SPI_MISO
    HAL::GPIOB::setAltFunc(5, HAL::GPIOB::AltFunc::AF5); // SPI_MOSI
    HAL::GPIOB::setPullup(3, HAL::GPIOB::Pullup::Up);
    HAL::GPIOB::setPullup(4, HAL::GPIOB::Pullup::Up);
    HAL::GPIOB::setPullup(5, HAL::GPIOB::Pullup::Up);
    HAL::GPIOB::setMode(3, HAL::GPIOB::Mode::Alt);
    HAL::GPIOB::setMode(4, HAL::GPIOB::Mode::Alt);
    HAL::GPIOB::setMode(5, HAL::GPIOB::Mode::Alt);
    // Set SPI1 for 10MHz, CPOL=1, CPHA=1
    // HAL::SPI1::setBaudRate(4_Mhz);
    HAL::SPI1::setBaudDivisor(HAL::SPI1::BaudDivisor::By256);
    HAL::SPI1::setSSM(true);
    HAL::SPI1::setSSI(true);
    HAL::SPI1::setCPOL(true);
    HAL::SPI1::setCPHA(true);
    HAL::SPI1::setMaster(true);
    HAL::SPI1::setDataSize(16);
    HAL::SPI1::setEnable(true);
    while (true) {
        for (uint32_t i = 0u; i < 4096; i++) {
            HAL::SPI1::pioWrite(i);
        }
        Log::log("Completed an iteration\r\n");
        vTaskDelay(pdMS_TO_TICKS(1000));
    }
}

constexpr uint16_t operator"" _u16(unsigned long long value)
{
    return static_cast<uint16_t>(value);
}

void waveGenerator(void * /*pvParameters*/)
{
    constexpr static uint16_t sinWave[] = {2048_u16, 2098_u16, 2148_u16, 2198_u16, 2248_u16, 2298_u16, 2348_u16, 2398_u16, 2447_u16, 2496_u16, 2545_u16, 2594_u16, 2642_u16, 2690_u16, 2737_u16, 2785_u16, 2831_u16, 2877_u16, 2923_u16, 2968_u16, 3013_u16, 3057_u16, 3100_u16, 3143_u16, 3185_u16, 3227_u16, 3267_u16, 3307_u16, 3347_u16, 3385_u16, 3423_u16, 3460_u16, 3496_u16, 3531_u16, 3565_u16, 3598_u16, 3631_u16, 3662_u16, 3692_u16, 3722_u16, 3750_u16, 3778_u16, 3804_u16, 3829_u16, 3854_u16, 3877_u16, 3899_u16, 3920_u16, 3940_u16, 3958_u16, 3976_u16, 3992_u16, 4007_u16, 4021_u16, 4034_u16, 4046_u16, 4056_u16, 4065_u16, 4073_u16, 4080_u16, 4086_u16, 4090_u16, 4093_u16, 4095_u16, 4095_u16, 4095_u16, 4093_u16, 4090_u16, 4086_u16, 4080_u16, 4073_u16, 4065_u16, 4056_u16, 4046_u16, 4034_u16, 4021_u16, 4007_u16, 3992_u16, 3976_u16, 3958_u16, 3940_u16, 3920_u16, 3899_u16, 3877_u16, 3854_u16, 3829_u16, 3804_u16, 3778_u16, 3750_u16, 3722_u16, 3692_u16, 3662_u16, 3631_u16, 3598_u16, 3565_u16, 3531_u16, 3496_u16, 3460_u16, 3423_u16, 3385_u16, 3347_u16, 3307_u16, 3267_u16, 3227_u16, 3185_u16, 3143_u16, 3100_u16, 3057_u16, 3013_u16, 2968_u16, 2923_u16, 2877_u16, 2831_u16, 2785_u16, 2737_u16, 2690_u16, 2642_u16, 2594_u16, 2545_u16, 2496_u16, 2447_u16, 2398_u16, 2348_u16, 2298_u16, 2248_u16, 2198_u16, 2148_u16, 2098_u16, 2048_u16, 1997_u16, 1947_u16, 1897_u16, 1847_u16, 1797_u16, 1747_u16, 1697_u16, 1648_u16, 1599_u16, 1550_u16, 1501_u16, 1453_u16, 1405_u16, 1358_u16, 1310_u16, 1264_u16, 1218_u16, 1172_u16, 1127_u16, 1082_u16, 1038_u16, 995_u16, 952_u16, 910_u16, 868_u16, 828_u16, 788_u16, 748_u16, 710_u16, 672_u16, 635_u16, 599_u16, 564_u16, 530_u16, 497_u16, 464_u16, 433_u16, 403_u16, 373_u16, 345_u16, 317_u16, 291_u16, 266_u16, 241_u16, 218_u16, 196_u16, 175_u16, 155_u16, 137_u16, 119_u16, 103_u16, 88_u16, 74_u16, 61_u16, 49_u16, 39_u16, 30_u16, 22_u16, 15_u16, 9_u16, 5_u16, 2_u16, 0_u16, 0_u16, 0_u16, 2_u16, 5_u16, 9_u16, 15_u16, 22_u16, 30_u16, 39_u16, 49_u16, 61_u16, 74_u16, 88_u16, 103_u16, 119_u16, 137_u16, 155_u16, 175_u16, 196_u16, 218_u16, 241_u16, 266_u16, 291_u16, 317_u16, 345_u16, 373_u16, 403_u16, 433_u16, 464_u16, 497_u16, 530_u16, 564_u16, 599_u16, 635_u16, 672_u16, 710_u16, 748_u16, 788_u16, 828_u16, 868_u16, 910_u16, 952_u16, 995_u16, 1038_u16, 1082_u16, 1127_u16, 1172_u16, 1218_u16, 1264_u16, 1310_u16, 1358_u16, 1405_u16, 1453_u16, 1501_u16, 1550_u16, 1599_u16, 1648_u16, 1697_u16, 1747_u16, 1797_u16, 1847_u16, 1897_u16, 1947_u16, 1997_u16};
    // Enable all devices required
    HAL::RCC::enable(HAL::RCC::Device::TIM6, true);
    HAL::RCC::enable(HAL::RCC::Device::GPIOA, true);
    HAL::RCC::enable(HAL::RCC::Device::DAC1, true);
    HAL::RCC::enable(HAL::RCC::Device::DMA1, true);

    // Configure free-running timer (which will trigger the DAC)
    // Clock after timer prescaler = fck / (PSC + 1)
    HAL::TIM6::setPrescaler(80); // 1 MHz
    HAL::TIM6::setAutoReloadValue(10000); // 100 Hz
    HAL::TIM6::setMasterMode(HAL::TIM6::MasterMode::Update);

    // Configure DMA
    HAL::RCC::enable(HAL::RCC::Device::DMA1, true);
    HAL::DMA1::setMemorySize(HAL::DMA1::Channel::Chan3,
                             HAL::DMA1::WordSize::_16bits);
    HAL::DMA1::setPeripheralSize(HAL::DMA1::Channel::Chan3,
                                 HAL::DMA1::WordSize::_16bits);
    HAL::DMA1::setMemoryAutoIncrement(HAL::DMA1::Channel::Chan3, true);
    HAL::DMA1::setCircularMode(HAL::DMA1::Channel::Chan3, true);
    HAL::DMA1::setMemoryAddress(HAL::DMA1::Channel::Chan3,
                                const_cast<uint16_t*>(sinWave));
    HAL::DMA1::setItemCount(HAL::DMA1::Channel::Chan3, sizeof(sinWave)/sizeof(sinWave[0]));
    HAL::DMA1::setPeripheralAddress(HAL::DMA1::Channel::Chan3,
                                    const_cast<uint32_t*>(
                                        HAL::DAC::dataAddress(
                                            HAL::DAC::Alignment::Right12Bit)));
    HAL::DMA1::setDirection(HAL::DMA1::Channel::Chan3, HAL::DMA1::Direction::Mem2Peripheral);
    HAL::DMA1::setChannelSelection(HAL::DMA1::Channel::Chan3,
                                   HAL::DMA1::ChannelSelects::Chan3_DAC_CH1);
    HAL::DMA1::enableChannel(HAL::DMA1::Channel::Chan3, true);

    // Configure output pin PA4 as DAC1_OUTPUT_1
    HAL::GPIOA::setMode(4, HAL::GPIOA::Mode::Analog);

    // Configure DAC
    HAL::DAC::setTriggerSource(HAL::DAC::TriggerSource::TIM6_TRGO);
    HAL::DAC::setTriggerEnable(true);
    HAL::DAC::setDMAEnable(true);
    HAL::DAC::enable(true);

    // Start TIM6
    HAL::TIM6::enable(true);
    while (1) {
        // HAL::DAC::softwareTrigger();
        Log::log("DOR value: %\r\n", picofmt::types::Hex(*(volatile uint32_t*)(0x4000742C)));
        vTaskDelay(pdMS_TO_TICKS(10));
    }
}

extern "C" {
extern void spin();
}

void main(void)
{
    Log::init();
    HAL::Clock::set(HAL::Clock::Setting::FullSpeed);
    Log::log("Booting...\r\n");
    HAL::FPU::enable(true);
    Log::log("Clock speed: %Mhz\r\n", HAL::Clock::speed());
    Log::log("Starting FreeRTOS\r\n");
    xTaskCreate(taskBlinky, "blinky", 20, nullptr, 1, nullptr);
    // xTaskCreate(taskScreenThingy, "display", 20, nullptr, 1, nullptr);
    xTaskCreate(waveGenerator, "wavegen", 100, nullptr, 1, nullptr);
    // xTaskCreate(opusBenchTask, "opusBench", 4000, NULL, 1, NULL);
    vTaskStartScheduler();
    spin();
}
