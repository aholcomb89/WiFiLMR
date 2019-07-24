#pragma once

// LPUART

#define BASE_LPUART         (volatile uint8_t*)(0x40008000)
#define LPUART_CR1          (volatile uint32_t*)(BASE_LPUART + 0x00)
#define LPUART_CR2          (volatile uint32_t*)(BASE_LPUART + 0x04)
#define LPUART_CR3          (volatile uint32_t*)(BASE_LPUART + 0x08)
#define LPUART_BRR          (volatile uint32_t*)(BASE_LPUART + 0x0C)
#define LPUART_ISR          (volatile uint32_t*)(BASE_LPUART + 0x1C)
#define LPUART_TDR          (volatile uint32_t*)(BASE_LPUART + 0x28)

// GPIO
#define BASE_GPIOA          (volatile uint8_t*)(0x48000000)
#define GPIOA_MODER         (volatile uint32_t*)(BASE_GPIOA + 0x00)
#define GPIOA_PUPDR         (volatile uint32_t*)(BASE_GPIOA + 0x0C)
#define GPIOA_AFRL          (volatile uint32_t*)(BASE_GPIOA + 0x20)

#define BASE_GPIOB          (volatile uint8_t*)(0x48000400)
#define GPIOB_MODER         (volatile uint32_t*)(BASE_GPIOB + 0x00)
#define GPIOB_PUPDR         (volatile uint32_t*)(BASE_GPIOB + 0x0C)
#define GPIOB_ODR           (volatile uint32_t*)(BASE_GPIOB + 0x14)
#define GPIOB_AFRL          (volatile uint32_t*)(BASE_GPIOB + 0x20)
#define GPIOB_AFRH          (volatile uint32_t*)(BASE_GPIOB + 0x24)

// Clock control
#define BASE_RCC            (volatile uint8_t*)(0x40021000)
#define RCC_AHB2RSTR        (volatile uint32_t*)(BASE_RCC + 0x2C)
#define RCC_AHB2ENR         (volatile uint32_t*)(BASE_RCC + 0x4C)
#define RCC_APB1ENR2        (volatile uint32_t*)(BASE_RCC + 0x5C)