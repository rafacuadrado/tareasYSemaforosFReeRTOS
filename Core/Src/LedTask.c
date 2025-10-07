/*
 * LedTask.c
 *
 *  Created on: Oct 7, 2025
 *      Author: rafac
 */
#include "LedTask.h"
int led1=1;
int led2=2;

void createLedTask(){
	xTaskCreate(ledToggleTask, "ledToggleTask 1", 128, &led1, 1, NULL);
	xTaskCreate(ledToggleTask, "ledToggleTask 2", 128, &led2, 2, NULL);
	//xTaskCreate(ledToggleTask, "ledToggleTask 2", 128, &led2, 1, NULL);

}
/*
void ledToggleTaskej1(void * pargs){
	while(1){
		LED_Toggle(1);
		vTaskDelay(300);
	}
}*/
void ledToggleTaskej1b(void * pargs){
	while(1){
	int led=*(int*)pargs;
	if(led==1){
		LED_Toggle(1);
			vTaskDelay(300);
	}else{
		LED_Toggle(2);
		vTaskDelay(300);
	}
	}
}
void ledToggleTask(void * pargs){
	while(1){
	int led=*(int*)pargs;
	if(led==1){
		LED_Toggle(1);
			vTaskDelay(100);
	}else{
		LED_Toggle(2);
		vTaskDelay(300);
	}
	}
}
