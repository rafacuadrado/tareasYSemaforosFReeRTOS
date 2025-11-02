/*
 * LedTask.c
 *
 *  Created on: Oct 7, 2025
 *      Author: rafac
 */
#include "LedTask.h"
int led1=1;
int led2=2;
TaskHandle_t taskHandler;

void createLedTask(){
	//xTaskCreate(ledToggleTask, "ledToggleTask 1", 128, &led1, 1,NULL);
	//xTaskCreate(ledToggleTask, "ledToggleTask 2", 128, &led2, 2, NULL);
	//xTaskCreate(ledToggleTask, "ledToggleTask 2", 128, &led2, 1, NULL);
	//xTaskCreate(ledToggleTask2, "ledToggleTask 1", 128, &led1, 1,NULL);
	xTaskCreate(animationLedTask, "ledToggleTask 1", 128,NULL, 1,NULL);
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
void animationLedTask(void * pargs){
	int res=0;
	while(1){

		  res = ReadJoy();
		  switch(res){
		  case 1:
			  xTaskCreate(animation1, "ledToggleTask 1", 128,NULL, 1,NULL);
		  case 2:
			  xTaskCreate(animation2, "ledToggleTask 1", 128,NULL, 1,NULL);

		  case 3:
			  xTaskCreate(animation3, "ledToggleTask 1", 128,NULL, 1,NULL);

		  case 4:
			  xTaskCreate(animation4, "ledToggleTask 1", 128,NULL, 1,NULL);

			  }
	}
}
void ledToggleTask2(void * pargs){
	while(1){
	int led=*(int*)pargs;
	if(led==1){
		LED_Toggle(1);
		vTaskDelay(100);
		LED_Toggle(1);
		vTaskDelay(100);
		LED_Toggle(1);
		vTaskDelay(100);
		LED_Toggle(1);
		vTaskDelay(100);
		LED_Toggle(1);
		vTaskDelay(100);
		xTaskCreate(ledToggleTask2, "ledToggleTask 2", 128, &led2, 2, NULL);
	}else{
		LED_Toggle(2);
		vTaskDelay(100);
		LED_Toggle(2);
		vTaskDelay(100);
		LED_Toggle(2);
		vTaskDelay(100);
		LED_Toggle(2);
		vTaskDelay(100);
		LED_Toggle(2);
		vTaskDelay(100);
		xTaskCreate(ledToggleTask2, "ledToggleTask 2", 128, &led1, 2, NULL);
	}


	vTaskDelete(NULL);

	}
	void animation1(void * pargs){
		LED_On(0);
		LED_On(1);
		LED_On(2);
		HAL_Delay(1500);
		LED_Off(0);
		LED_Off(1);
		LED_Off(2);
		vTaskDelete(NULL);
	}
	void animation2(void * pargs){
		LED_On(0);
		HAL_Delay(150);
		LED_On(1);
		HAL_Delay(150);
		LED_On(2);
		HAL_Delay(150);
		LED_Off(0);
		HAL_Delay(150);
		LED_Off(1);
		HAL_Delay(150);
		LED_Off(2);
	}
	void animation3(void * pargs){
		LED_On(0);
		HAL_Delay(500);
		LED_Off(0);
		LED_On(1);
		HAL_Delay(500);
		LED_Off(1);
		LED_On(2);
		HAL_Delay(500);
		LED_Off(2);
		vTaskDelete(NULL);

	}
	void animation4(void * pargs){
		for(int i = 0; i<25; i++){
			LED_On(0);
			LED_On(1);
			LED_On(2);
			HAL_Delay(150);
			LED_Off(0);
			LED_Off(1);
			LED_Off(2);
			HAL_Delay(150);
		}
		vTaskDelete(NULL);
	}
}

