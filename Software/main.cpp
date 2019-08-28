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

constexpr uint8_t operator"" _u8(unsigned long long value)
{
    return static_cast<uint8_t>(value);
}

void waveGenerator()
{
    constexpr static uint8_t sinWave[] = {128_u8,131_u8,134_u8,137_u8,140_u8,143_u8,146_u8,149_u8,152_u8,156_u8,159_u8,162_u8,
    165_u8,168_u8,171_u8,174_u8,176_u8,179_u8,182_u8,185_u8,188_u8,191_u8,193_u8,196_u8,199_u8,201_u8,204_u8,206_u8,209_u8,211_u8,213_u8,
    216_u8,218_u8,220_u8,222_u8,224_u8,226_u8,228_u8,230_u8,232_u8,234_u8,236_u8,237_u8,239_u8,240_u8,242_u8,243_u8,245_u8,246_u8,247_u8,
    248_u8,249_u8,250_u8,251_u8,252_u8,252_u8,253_u8,254_u8,254_u8,255_u8,255_u8,255_u8,255_u8,255_u8,256_u8,255_u8,255_u8,255_u8,255_u8,
    255_u8,254_u8,254_u8,253_u8,252_u8,252_u8,251_u8,250_u8,249_u8,248_u8,247_u8,246_u8,245_u8,243_u8,242_u8,240_u8,239_u8,237_u8,236_u8,
    234_u8,232_u8,230_u8,228_u8,226_u8,224_u8,222_u8,220_u8,218_u8,216_u8,213_u8,211_u8,209_u8,206_u8,204_u8,201_u8,199_u8,196_u8,193_u8,
    191_u8,188_u8,185_u8,182_u8,179_u8,176_u8,174_u8,171_u8,168_u8,165_u8,162_u8,159_u8,156_u8,152_u8,149_u8,146_u8,143_u8,140_u8,137_u8,
    134_u8,131_u8,128_u8,124_u8,121_u8,118_u8,115_u8,112_u8,109_u8,106_u8,103_u8,99_u8,96_u8,93_u8,90_u8,87_u8,84_u8,81_u8,79_u8,76_u8,73_u8,
    70_u8,67_u8,64_u8,62_u8,59_u8,56_u8,54_u8,51_u8,49_u8,46_u8,44_u8,42_u8,39_u8,37_u8,35_u8,33_u8,31_u8,29_u8,27_u8,25_u8,23_u8,21_u8,19_u8,18_u8,16_u8,
    15_u8,13_u8,12_u8,10_u8,9_u8,8_u8,7_u8,6_u8,5_u8,4_u8,3_u8,3_u8,2_u8,1_u8,1_u8,0_u8,0_u8,0_u8,0_u8,0_u8,0_u8,0_u8,0_u8,0_u8,0_u8,0_u8,1_u8,1_u8,2_u8,3_u8,3_u8,4_u8,5_u8,6_u8,7_u8,8_u8,
    9_u8,10_u8,12_u8,13_u8,15_u8,16_u8,18_u8,19_u8,21_u8,23_u8,25_u8,27_u8,29_u8,31_u8,33_u8,35_u8,37_u8,39_u8,42_u8,44_u8,46_u8,49_u8,51_u8,54_u8,56_u8,
    59_u8,62_u8,64_u8,67_u8,70_u8,73_u8,76_u8,79_u8,81_u8,84_u8,87_u8,90_u8,93_u8,96_u8,99_u8,103_u8,106_u8,109_u8,112_u8,115_u8,118_u8,121_u8,
    124_u8};
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
                             HAL::DMA1::WordSize::_8bits);
    HAL::DMA1::setPeripheralSize(HAL::DMA1::Channel::Chan3,
                                 HAL::DMA1::WordSize::_8bits);
    HAL::DMA1::setMemoryAutoIncrement(HAL::DMA1::Channel::Chan3, true);
    HAL::DMA1::setCircularMode(HAL::DMA1::Channel::Chan3, true);
    HAL::DMA1::setMemoryAddress(HAL::DMA1::Channel::Chan3,
                                const_cast<uint8_t*>(sinWave));
    HAL::DMA1::setItemCount(HAL::DMA1::Channel::Chan3, sizeof(sinWave)/sizeof(sinWave[0]));
    HAL::DMA1::setPeripheralAddress(HAL::DMA1::Channel::Chan3,
                                    const_cast<uint32_t*>(
                                        HAL::DAC::dataAddress(
                                            HAL::DAC::Alignment::Right8Bit)));
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
    waveGenerator();
    xTaskCreate(taskBlinky, "blinky", 20, nullptr, 1, nullptr);
    xTaskCreate(taskScreenThingy, "display", 20, nullptr, 1, nullptr);
    
    // xTaskCreate(opusBenchTask, "opusBench", 4000, NULL, 1, NULL);
    vTaskStartScheduler();
    spin();
}
