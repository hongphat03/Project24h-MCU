/*
 * fsm_manual.c
 *
 *  Created on: Oct 11, 2022
 *      Author: Hong Phat
 */

#include "fsm_manual.h"

void fsm_manual_run(){
	switch(status){
	case MAN_RED:
		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_7,1);
		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_6,1);
		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_5,0);
		if(timer1_flag==1){
			status = AUTO_RED;
			setTimer(500);
			//button1_flag = 0;
		}
		if(isButton1Pressed() == 1){
			//button1_flag=0;
			status = MAN_GREEN;
			setTimer(1000);
		}
		break;
	case MAN_GREEN:
		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_7,1);
		HAL_GPIO_WritePin(GPIOA,GPIO_PIN_6,0);
		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_5,1);
		if(timer1_flag==1){
			status = AUTO_GREEN;
			setTimer(500);
		}
		if(isButton1Pressed() == 1){
			//button1_flag=0;
			status = MAN_YELLOW;
			setTimer(1000);
		}
		break;
	case MAN_YELLOW:
		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_5,1);
		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_6,1);
		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_7,0);
		if(timer1_flag==1){
			status = AUTO_YELLOW;
			setTimer(500);
		}
		if(isButton1Pressed() == 1){
			//button1_flag=0;
			status = MAN_RED;
			setTimer(1000);
		}
		break;
	}
}
