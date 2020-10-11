#pragma once
#include "gpio.h"

void isa_memw();
void isa_memr();
void isa_ior();
void isa_iow(uint32_t address, uint32_t data);

void isa_set_address(uint32_t address);
void isa_set_data(uint32_t data);
