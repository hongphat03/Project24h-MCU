///*
// * fsm_manual.c
// *
// *  Created on: Oct 11, 2022
// *      Author: Hong Phat
// */
//
//#include "fsm_manual.h"
//
//void fsm_manual_run(){
//	switch(status){
//	case MAN_RED:
//		if(timer2_flag == 1){
//			setTimer2(5000);
//			HAL_GPIO_TogglePin(GPIOA,GPIO_PIN_3);
//			HAL_GPIO_TogglePin(GPIOA,GPIO_PIN_10);
//		}
//		if(isButton1Pressed() == 1){
//			setTimer2(5000);
//			status = MAN_YELLOW;
//		}
//		if(isButton2Pressed() == 1){
//			timer_red++;
//		}
//		if(isButton3Pressed() == 1){
//			//setTimer(timer_red);
//		}
//		break;
//	case MAN_YELLOW:
//			if(timer2_flag == 1){
//				setTimer2(5000);
//				HAL_GPIO_TogglePin(GPIOA,GPIO_PIN_4);
//				HAL_GPIO_TogglePin(GPIOA,GPIO_PIN_11);
//			}
//			if(isButton1Pressed() == 1){
//				setTimer2(5000);
//				status = MAN_GREEN;
//			}
//			if(isButton2Pressed() == 1){
//				timer_yellow++;
//			}
//			if(isButton3Pressed() == 1){
//			}
//			break;
//	case MAN_GREEN:
//		if(timer2_flag == 1){
//			setTimer2(5000);
//			HAL_GPIO_TogglePin(GPIOA,GPIO_PIN_5);
//			HAL_GPIO_TogglePin(GPIOA,GPIO_PIN_12);
//		}
//		if(isButton1Pressed() == 1){
//			status = AUTO_RED;
//			setTimer(timer_red);
//		}
//		if(isButton2Pressed() == 1){
//			timer_green++;
//		}
//		if(isButton3Pressed() == 1){
//			status = AUTO_RED;
//		}
//		break;
//	default:
//		break;
//	}
//}
