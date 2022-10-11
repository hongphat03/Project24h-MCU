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
		if(timer1_flag==1){
			status = AUTO_RED;
			setTimer(5000);
			button1_flag = 0;
		}
		if(button1_flag == 1){
			button1_flag=0;
			status = MAN_GREEN;
			setTimer(10000);
		}
		break;
	case MAN_GREEN:
		if(timer1_flag==1){
			status = AUTO_GREEN;
			setTimer(5000);
		}
		if(button1_flag == 1){
			button1_flag=0;
			status = MAN_YELLOW;
			setTimer(10000);
		}
		break;
	case MAN_YELLOW:
		if(timer1_flag==1){
			status = AUTO_YELLOW;
			setTimer(5000);
		}
		if(button1_flag == 1){
			button1_flag=0;
			status = MAN_RED;
			setTimer(10000);
		}
		break;
	}
}
