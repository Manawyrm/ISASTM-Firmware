#include "debug.h"

void init_leds(void)
{



}


uint32_t address = 0x00000; 
void switch_leds()
{
/*
	HAL_GPIO_WritePin(GPIOG, GPIO_PIN_9, GPIO_PIN_SET);
    HAL_GPIO_WritePin(GPIOG, GPIO_PIN_10, GPIO_PIN_RESET);

    HAL_Delay(500);

	HAL_GPIO_WritePin(GPIOG, GPIO_PIN_10, GPIO_PIN_SET);
    HAL_GPIO_WritePin(GPIOG, GPIO_PIN_9, GPIO_PIN_RESET);
    HAL_Delay(500);

	HAL_GPIO_WritePin(GPIOG, GPIO_PIN_11, GPIO_PIN_SET);
    HAL_GPIO_WritePin(GPIOG, GPIO_PIN_10, GPIO_PIN_RESET);
        HAL_Delay(500);

	HAL_GPIO_WritePin(GPIOG, GPIO_PIN_12, GPIO_PIN_SET);
    HAL_GPIO_WritePin(GPIOG, GPIO_PIN_11, GPIO_PIN_RESET);
    HAL_Delay(500);

	HAL_GPIO_WritePin(GPIOG, GPIO_PIN_13, GPIO_PIN_SET);
    HAL_GPIO_WritePin(GPIOG, GPIO_PIN_12, GPIO_PIN_RESET);
*/




/*	uint8_t data = isa_memr(address);
	//isa_iow(0x80, data);
	printf("%c", data);
	//printf("address: %04lx data: %02x\r\n", address, data);
	address++;
*/

	gpio_write(iopins[GPIO_LED5], 1);
	 HAL_Delay(200);
	gpio_write(iopins[GPIO_LED5], 0);
	HAL_Delay(200);
	/*if (address == 0xFFFFF)
	{
		while(1) { HAL_Delay(200);}
	}*/
}

