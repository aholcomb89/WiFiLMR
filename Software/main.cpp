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
    xTaskCreate(taskScreenThingy, "display", 20, nullptr, 1, nullptr);
    
    // xTaskCreate(opusBenchTask, "opusBench", 4000, NULL, 1, NULL);
    vTaskStartScheduler();
    spin();
}
