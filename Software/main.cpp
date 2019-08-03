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
#include "logging.h"

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
    
    // xTaskCreate(opusBenchTask, "opusBench", 4000, NULL, 1, NULL);
    vTaskStartScheduler();
    spin();
}
