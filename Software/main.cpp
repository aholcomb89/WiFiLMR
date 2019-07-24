#include "opus.h"
#include "FreeRTOSConfig.h"
#include "FreeRTOS.h"
#include "portable.h" // pvPortMalloc
#include "task.h"
#include "HAL/memory_map.h"
#include "HAL/rcc.h"
#include "HAL/gpio.h"
#include "HAL/lpuart.h"
#include "HAL/util.h"

void configureUART(void)
{
    HAL::RCC::enable(HAL::RCC::Device::GPIOA, true);
    HAL::GPIOA::setAltFunc(2, HAL::GPIOA::AltFunc::PA2_LPUART1_TX);
    HAL::GPIOA::setAltFunc(3, HAL::GPIOA::AltFunc::PA3_LPUART1_RX);
    HAL::GPIOA::setMode(2, HAL::GPIOA::Mode::Alt);
    HAL::GPIOA::setMode(3, HAL::GPIOA::Mode::Alt);
    HAL::GPIOA::setPullup(2, HAL::GPIOA::Pullup::Up);
    HAL::GPIOA::setPullup(3, HAL::GPIOA::Pullup::Up);
    HAL::RCC::enable(HAL::RCC::Device::LPUART1, true);
    HAL::LPUART::setBaudRate(115200);
    HAL::LPUART::enable(true);
    HAL::LPUART::enableTransmitter(true);
    while (1) {
        const char* foo = "HeLlO wOrLd\n";
        for (size_t i = 0; i < 12; i++) {
            HAL::LPUART::writeByte(foo[i]);
            delayLoop(100);
        }
    }
}

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
int
main(void)
{
    //
    // Enable the GPIO port that is used for the on-board LED.
    //
    HAL::RCC::enable(HAL::RCC::Device::GPIOB, true);
    HAL::GPIOB::setMode(13, HAL::GPIOB::Mode::Output);
    HAL::GPIOB::setOutput(13, true);
    configureUART();
    
    // xTaskCreate(opusBenchTask, "opusBench", 4000, NULL, 1, NULL);
    // UARTprintf("Starting!\r\n");
    // vTaskStartScheduler();
    
}
