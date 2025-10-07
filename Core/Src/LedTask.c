/*
 * LedTask.c
 *
 *  Created on: Oct 7, 2025
 *      Author: rafac
 */
#include "LedTask.h"
void createLedTask(){
	xTaskCreate(ledToggleTask, "ledToggleTask 1", 128, NULL, 1, NULL);

}
void ledToggleTask(void * pargs){
	while(1){
	LED_Toggle(1);
	vTaskDelay(300);}
}
