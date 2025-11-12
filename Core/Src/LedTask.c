/*
 * LedTask.c
 *
 *  Created on: Oct 7, 2025
 *      Author: rafac
 */
#include "LedTask.h"
#include "joy_driver.h"
int led1=1;
int led2=2;
int clave=0;
TaskHandle_t taskHandler[5];


void createLedTask(){
	//xTaskCreate(ledToggleTask, "ledToggleTask 1", 128, &led1, 1,NULL);
	//xTaskCreate(ledToggleTask, "ledToggleTask 2", 128, &led2, 2, NULL);
	//xTaskCreate(ledToggleTask, "ledToggleTask 2", 128, &led2, 1, NULL);
	//xTaskCreate(ledToggleTask2, "ledToggleTask 1", 128, &led1, 1,NULL);
	// Ej 4
	//xTaskCreate(animationLedTask1, "animaciones sin tareas", 128,NULL, 1,NULL);
	// Ej 5
	xTaskCreate(animationLedTask2, "animaciones con tareas", 128,NULL, 1,NULL);
}
void createButtonTask(){
	xTaskCreate(buttonTask, "testBotón", 128,NULL, 1,NULL);
	xTaskCreate(animation1Task, "animación 1", 128, NULL,1,&taskHandler[1]);
	xTaskCreate(animation2Task, "animación 1", 128, NULL,1,&taskHandler[2]);
	xTaskCreate(animation3Task, "animación 1", 128, NULL,1,&taskHandler[3]);
	xTaskCreate(animation4Task, "animación 1", 128, NULL,1,&taskHandler[4]);


}
void buttonTask(void * pargs){

	while(1){
		clave=ReadJoy();
		if(clave!=0){
			xTaskNotifyGive(taskHandler[clave]);
		}
	}
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

void animationLedTask1(void * pargs){
	int res=0;
	while(1){
		res = ReadJoy();
			  switch(res){
				  case 1:
					  animation1();
					  break;
				  case 2:
					  animation2();
				  	  break;
				  case 3:
					  animation3();
					  break;
				  case 4:
					  animation4();
					  break;
			  }
	}
}
void animationLedTask2(void * pargs){
	int res=0;
	while(1){

		  res = ReadJoy();
		  switch(res){
		  case 1:
			  xTaskCreate(animation1Task, "ledToggleTask 1", 128,&led1, 1,NULL);
			  break;
		  case 2:
			  xTaskCreate(animation2Task, "ledToggleTask 1", 128,&led1, 1,NULL);
			  break;
		  case 3:
			  xTaskCreate(animation3Task, "ledToggleTask 1", 128,&led1, 1,NULL);
			  break;
		  case 4:
			  xTaskCreate(animation4Task, "ledToggleTask 1", 128,&led1, 1,NULL);
			  break;
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

	}}
void animation1(void){
	LED_On(0);
	LED_On(1);
	LED_On(2);
	HAL_Delay(1500);
	LED_Off(0);
	LED_Off(1);
	LED_Off(2);
	//vTaskDelete(NULL);
}
void animation2(void){
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
	//vTaskDelete(NULL);
}
void animation3(void){
	LED_On(0);
	HAL_Delay(500);
	LED_Off(0);
	LED_On(1);
	HAL_Delay(500);
	LED_Off(1);
	LED_On(2);
	HAL_Delay(500);
	LED_Off(2);
	//vTaskDelete(NULL);

}
void animation4(void){

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
	//vTaskDelete(NULL);
}

	void animation1Task(void * pargs){
		while(1)
		{
		ulTaskNotifyTake(pdTRUE, portMAX_DELAY);

		/*LED_On(0);
		LED_On(1);
		LED_On(2);
		HAL_Delay(1500);
		LED_Off(0);
		LED_Off(1);
		LED_Off(2);*/
		animation1();
		}
	}
	void animation2Task(void * pargs){
		while(1){
		ulTaskNotifyTake(pdTRUE, portMAX_DELAY);

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
	}
	void animation3Task(void * pargs){
		while(1){ulTaskNotifyTake(pdTRUE, portMAX_DELAY);

		LED_On(0);
		HAL_Delay(500);
		LED_Off(0);
		LED_On(1);
		HAL_Delay(500);
		LED_Off(1);
		LED_On(2);
		HAL_Delay(500);
		LED_Off(2);
		}

	}
	void animation4Task(void * pargs){
		while(1){
			ulTaskNotifyTake(pdTRUE, portMAX_DELAY);
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
		}


	}


