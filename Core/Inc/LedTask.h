/*
 * LedTask.h
 *
 *  Created on: Oct 7, 2025
 *      Author: rafac
 */

#ifndef SRC_LEDTASK_H_
#define SRC_LEDTASK_H_
#include "stm32l4xx_hal.h"
#include "FreeRTOS.h"
#include "task.h"
#include "led_driver.h"
#include "joy_driver.h"
void createLedTask();
void createButtonTask();
void buttonTask(void * pargs);
void ledToggleTask(void * pargs);
void ledToggleTask2(void * pargs);
void animationLedTask2(void * pargs);
void animationLedTask1(void * pargs);
void animation1(void);
void animation2(void);
void animation3(void);
void animation4(void);

void animation1Task(void * pargs);
void animation2Task(void * pargs);
void animation3Task(void * pargs);
void animation4Task(void * pargs);


#endif /* SRC_LEDTASK_H_ */
