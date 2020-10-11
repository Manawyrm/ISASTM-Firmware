#include "debug.h"

void init_leds(void)
{



}


uint32_t address = 0x01; 
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

	printf("data: %04lx\n", address);

	address++;

	isa_iow(0x80, address);

	gpio_write(iopins[GPIO_LED5], 1);
	HAL_Delay(200);
	gpio_write(iopins[GPIO_LED5], 0);


	HAL_Delay(2000);

}

