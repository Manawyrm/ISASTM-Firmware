#pragma once
#include "stm32h7xx_hal.h"
#include "gpio.h"
#include "isa.h"
#include <stdio.h>

void init_leds(void);
void switch_leds();