/*
 * joy_driver.c
 *
 *  Created on: Sep 30, 2025
 *      Author: rafa
 */

#include "stm32l4xx_hal.h"
uint8_t cont=0;
uint8_t antes = GPIO_PIN_SET;
uint8_t actual;



uint8_t ReadJoy(){

	//Queremos que cada vez que reciba un 0
	antes=actual;
	actual = HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_13);
	if(cont==4){
		cont=0;
	}
	if(actual!=antes&&actual==GPIO_PIN_RESET){
		cont++;
	}else{
		return 0;
	}



	return cont;
}
