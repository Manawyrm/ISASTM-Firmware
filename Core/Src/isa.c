#include "isa.h"

void isa_set_address(uint32_t address)
{
	GPIOE->BSRR = (address & 0b11111) << 2;
	GPIOE->BSRR = ((~(address & 0b11111)) << 2) << GPIO_NUMBER;

	address >>= 5;

	GPIOC->BSRR = (address & 0b11111111111) << 5;
	GPIOC->BSRR = ((~(address & 0b11111111111)) << 5) << GPIO_NUMBER;

	address >>= 11;

	GPIOI->BSRR = (address & 0b1111) << 8;
	GPIOI->BSRR = ((~(address & 0b1111)) << 8) << GPIO_NUMBER;
}

void isa_set_data(uint32_t data)
{
	GPIOI->BSRR = data & 0xFF;
	GPIOI->BSRR = (~(data & 0xFF)) << GPIO_NUMBER;
}

void isa_iow(uint32_t address, uint32_t data)
{
	isa_set_address(address); 

	//digitalWrite(PIN_ALE, HIGH);
	//digitalWrite(PIN_ALE, LOW);

	isa_set_data(data);
	//gpio_set(iopins[GPIO_DATA_DIR]);

	gpio_set(iopins[GPIO_IOW]);

	while (!gpio_read(iopins[GPIO_IO_CH_RDY]))
	{
	}

	gpio_reset(iopins[GPIO_IOW]);
	
	//gpio_reset(iopins[GPIO_DATA_DIR]);
}