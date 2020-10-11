#pragma once
#include "gpio.h"

uint8_t isa_ior(uint32_t address);
void isa_iow(uint32_t address, uint32_t data);
uint8_t isa_memr(uint32_t address);
void isa_memw(uint32_t address, uint32_t data);

void isa_set_address(uint32_t address);
void isa_set_data(uint32_t data);
void isa_set_data_direction(uint32_t direction);