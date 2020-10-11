#pragma once
#include "stm32h7xx_hal.h"

#define ARRAY_SIZE(x) (sizeof(x) / sizeof(*(x)))

struct iopin
{
	GPIO_TypeDef  *port;
	uint32_t pin;
	uint32_t mode;
	uint32_t flags; 
};

#define GPIO_LED1 0
#define GPIO_LED2 1
#define GPIO_LED3 2
#define GPIO_LED4 3
#define GPIO_LED5 4
#define GPIO_ADDRESS_DIR 5
#define GPIO_ADDRESS_OE 6
#define GPIO_DATA_DIR 7
#define GPIO_DATA_OE 8
#define GPIO_CONTROL1_DIR 9
#define GPIO_CONTROL1_OE 10
#define GPIO_CONTROL2_DIR 11
#define GPIO_CONTROL2_OE 12
#define GPIO_CONTROL3_DIR 13
#define GPIO_CONTROL3_OE 14
#define GPIO_SPARE1_DIR 15
#define GPIO_SPARE1_OE 16
#define GPIO_SPARE2_DIR 17
#define GPIO_SPARE2_OE 18
#define GPIO_IRQ_DIR 19
#define GPIO_IRQ_OE 20
#define GPIO_DACK3 21
#define GPIO_CLK 22
#define GPIO_NOWS 23
#define GPIO_DRQ1 24
#define GPIO_IRQ2 25
#define GPIO_DRQ3 26
#define GPIO_ALE 27
#define GPIO_REFRESH 28
#define GPIO_MEMW 29
#define GPIO_MEMR 30
#define GPIO_IOW 31
#define GPIO_IOR 32
#define GPIO_IRQ3 33
#define GPIO_A5 34
#define GPIO_A6 35
#define GPIO_A7 36
#define GPIO_A8 37
#define GPIO_A9 38
#define GPIO_A10 39
#define GPIO_A11 40
#define GPIO_A12 41
#define GPIO_A13 42
#define GPIO_A14 43
#define GPIO_A15 44
#define GPIO_AEN 45
#define GPIO_IRQ7 46
#define GPIO_IRQ4 47
#define GPIO_IRQ5 48
#define GPIO_IRQ6 49
#define GPIO_A0 50
#define GPIO_A1 51
#define GPIO_A2 52
#define GPIO_A3 53
#define GPIO_A4 54
#define GPIO_DRQ2 55
#define GPIO_IO_CH_CK 56
#define GPIO_IO_CH_RDY 57
#define GPIO_RESET 58
#define GPIO_DACK2 59
#define GPIO_DACK1 60
#define GPIO_TC 61
#define GPIO_D0 62
#define GPIO_D1 63
#define GPIO_D2 64
#define GPIO_D3 65
#define GPIO_D4 66
#define GPIO_D5 67
#define GPIO_D6 68
#define GPIO_D7 69
#define GPIO_A16 70
#define GPIO_A17 71
#define GPIO_A18 72
#define GPIO_A19 73

#define GPIO_FLAG_DEFAULT_ACTIVE 0x01
#define GPIO_FLAG_ACTIVE_LOW 0x02
#define GPIO_FLAG_PULL_UP 0x04
#define GPIO_FLAG_PULL_DOWN 0x08

#define GPIO_NUMBER           (16U)

extern const struct iopin iopins[];

void init_isastm();
void gpio_write(const struct iopin, const uint8_t value);
void gpio_set(const struct iopin iopin);
void gpio_reset(const struct iopin iopin);
uint8_t gpio_read(const struct iopin iopin);