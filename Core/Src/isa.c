#include "isa.h"

// Writes a value to the address bus
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

// Writes a value to the data bus
void isa_set_data(uint32_t data)
{
	GPIOI->BSRR = data & 0xFF;
	GPIOI->BSRR = (~(data & 0xFF)) << GPIO_NUMBER;
}

uint8_t isa_get_data()
{
	return GPIOI->IDR & 0xFF;
}

// Switches between input and output for the data pins
void isa_set_data_direction(uint32_t direction)
{
	if (direction)
	{
		GPIOI->MODER = (GPIOI->MODER & 0xFFFF0000) | 0x5555;
	}
	else
	{
		GPIOI->MODER = (GPIOI->MODER & 0xFFFF0000);
	}
}

// I/O 8bit Write
void isa_iow(uint32_t address, uint32_t data)
{
	gpio_write(iopins[GPIO_LED2], 1);
	isa_set_address(address); 

	//digitalWrite(PIN_ALE, HIGH);
	//digitalWrite(PIN_ALE, LOW);

	isa_set_data(data);
	isa_set_data_direction(1);
	gpio_level_direction_output(iopins[GPIO_DATA_DIR]);

	gpio_set(iopins[GPIO_IOW]);

	while (!gpio_read(iopins[GPIO_IO_CH_RDY]))
	{
	}

	gpio_reset(iopins[GPIO_IOW]);
	isa_set_data_direction(0);
	gpio_level_direction_input(iopins[GPIO_DATA_DIR]);
	gpio_write(iopins[GPIO_LED2], 0);
}

// I/O 8bit Read
uint8_t isa_ior(uint32_t address)
{
	gpio_write(iopins[GPIO_LED3], 1);
	uint8_t data = 0x00;

	isa_set_address(address); 

	//digitalWrite(PIN_ALE, HIGH);
	//digitalWrite(PIN_ALE, LOW);

	isa_set_data_direction(0);
	gpio_level_direction_input(iopins[GPIO_DATA_DIR]);

	gpio_set(iopins[GPIO_IOR]);

	while (!gpio_read(iopins[GPIO_IO_CH_RDY]))
	{
	}

	data = isa_get_data();

	gpio_reset(iopins[GPIO_IOR]);

	gpio_write(iopins[GPIO_LED3], 0);
	return data;
}

// Memory 8bit Write
void isa_memw(uint32_t address, uint32_t data)
{
	gpio_write(iopins[GPIO_LED4], 1);

	isa_set_data(data);
	isa_set_data_direction(1);
	gpio_level_direction_output(iopins[GPIO_DATA_DIR]);

	isa_set_address(address); 

	//digitalWrite(PIN_ALE, HIGH);
	//digitalWrite(PIN_ALE, LOW);

	gpio_set(iopins[GPIO_MEMW]);

	while (!gpio_read(iopins[GPIO_IO_CH_RDY]))
	{
	}

	gpio_reset(iopins[GPIO_MEMW]);
	isa_set_data_direction(0);
	gpio_level_direction_input(iopins[GPIO_DATA_DIR]);
	gpio_write(iopins[GPIO_LED4], 0);
}

// Memory 8bit Read
uint8_t isa_memr(uint32_t address)
{
	uint8_t data = 0x00;
	gpio_write(iopins[GPIO_LED5], 1);

	isa_set_address(address); 

	//digitalWrite(PIN_ALE, HIGH);
	//digitalWrite(PIN_ALE, LOW);

	isa_set_data_direction(0);
	gpio_level_direction_input(iopins[GPIO_DATA_DIR]);

	gpio_set(iopins[GPIO_MEMR]);

	while (!gpio_read(iopins[GPIO_IO_CH_RDY]))
	{
	}

	data = isa_get_data();

	gpio_reset(iopins[GPIO_MEMR]);
	gpio_write(iopins[GPIO_LED5], 0);

	return data;
}

void isa_reset()
{
	gpio_set(iopins[GPIO_RESET]);
	gpio_reset(iopins[GPIO_RESET]);
}