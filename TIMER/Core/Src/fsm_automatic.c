/*
 * fsm_automatic.c
 *
 *  Created on: Oct 9, 2022
 *      Author: Hong Phat
 */
#include "fsm_automatic.h"
void fsm_simple_buttons_run(){
	if(timer4_flag == 1){
		setTimer4(1000);
		HAL_GPIO_TogglePin(GPIOA,GPIO_PIN_5);
	}
	switch(status){
	case INIT:
		counter = 9;
		status = NORMAL;
	case NORMAL:
		if(timer3_flag == 1){
			setTimer1(1000);
			status = COUNT_DOWN;
		}
		display7SEG();
		if(button1_flag == 1){
			setTimer3(10000);
			//setTimer1(1000);
			status = RESET;
		}
		if(button2_flag == 1){
			setTimer3(10000);
			//setTimer1(1000);
			status = INC;
		}
		if(button3_flag== 1){
			setTimer3(10000);
			//setTimer1(1000);
			status = DEC;
		}
		if(ispressed(1) == 1){
			setTimer3(10000);
			setTimer2(1000);
			status = INC_LONGPRESS;
		}
		if(ispressed(2)){
			setTimer3(10000);
			setTimer2(1000);
			status = DEC_LONGPRESS;
		}
		break;
	case INC:
		if(button2_flag == 1){
			setTimer3(10000);
			//setTimer1(1000);
			button2_flag = 0;
			counter++;
			if(counter > 9 ) counter = 0;
			display7SEG();
		}
		if(timer3_flag == 1){
			setTimer1(1000);
			status = COUNT_DOWN;
		}
		if(button1_flag == 1){
			setTimer3(10000);
			//setTimer1(1000);
			status = RESET;
		}
		if(button3_flag== 1){
			setTimer3(10000);
			//setTimer1(1000);
			status = DEC;
		}
		if(ispressed(1) == 1){
			setTimer2(1000);
			setTimer3(10000);
			status = INC_LONGPRESS;
		}
		if(ispressed(2)){
			setTimer2(1000);
			setTimer3(10000);
			status = DEC_LONGPRESS;
		}
		break;
	case DEC:
		if(button3_flag == 1){
			setTimer3(10000);
			button3_flag = 0;
			counter--;
			if(counter < 0) counter = 9;
			display7SEG();
		}
		if(timer3_flag == 1){
			setTimer1(1000);
			status = COUNT_DOWN;
		}
		if(button1_flag == 1){
			status = RESET;
			setTimer3(10000);
		}
		if(button2_flag == 1){
			status = INC;
			setTimer3(10000);
		}
		if(ispressed(1) == 1){
					setTimer2(1000);
					setTimer3(10000);
					status = INC_LONGPRESS;
				}
				if(ispressed(2)){
					setTimer2(1000);
					setTimer3(10000);
					status = DEC_LONGPRESS;
				}
	case RESET:
		if(button1_flag== 1){
			button1_flag = 0;
			setTimer3(10000);
			//setTimer1(1000);
			counter = 0;
			display7SEG();
		}
		if(button2_flag == 1){
			status = INC;
			setTimer3(10000);
			setTimer1(1000);
		}
		if(button3_flag== 1){
			status = DEC;
			setTimer3(10000);
			setTimer1(1000);
		}
		if(ispressed(1) == 1){
			setTimer2(1000);
			setTimer3(10000);
			status = INC_LONGPRESS;
		}
		if(ispressed(2)){
			setTimer2(1000);
			setTimer3(10000);
			status = DEC_LONGPRESS;
		}
		break;
	case COUNT_DOWN:
		if(timer1_flag == 1){
			setTimer1(1000);
			counter--;
			display7SEG();
			if(counter == 0){
				timer3_flag = 0;
				status = NORMAL;
			}
		}
		break;
	default :
		break;
	}
}
void fsm_simple_buttons_run2(){
	switch(status){
	case INC_LONGPRESS:
		if(timer2_flag == 1){
			setTimer2(1000);
			counter = (counter+1)%10;
			display7SEG();
		}
		if(ispressed(1) == 0){
			setTimer3(10000);
			//setTimer1(1000);
			status = NORMAL;
			isButton2Pressed();
		}
		break;
	case DEC_LONGPRESS:
		if(timer2_flag == 1){
			setTimer2(1000);
			if(counter == 0) counter = 10;
			counter --;
			display7SEG();
		}
		if(ispressed(2) == 0){
			setTimer3(10000);
			//setTimer1(1000);
			status = NORMAL;
			isButton3Pressed();
		}
		break;
	default:
		break;
	}
}

