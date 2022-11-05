/*
 * fsm_automatic.c
 *
 *  Created on: Oct 9, 2022
 *      Author: Hong Phat
 */
#include "fsm_automatic.h"
void fsm_simple_buttons_run () {
		switch(status){
		case INIT9:
			counter = 10 ;
			setTimer(1000);
			status = NORMAL;
			break;
		case INIT0:
			counter = 1;
			setTimer(1000);
			status = NORMAL;
			break;
		case NORMAL:
			if(timer1_flag == 1){
				setTimer(1000);
				if(counter == 0){
					status = INIT9;
				}
				else{
				counter --;
				display7SEG();
				status = NORMAL;
				}
			}
			if( isButton1Pressed() == 1){
				status = INIT0;
			}
			if( button2_flag == 1){
				setTimer(1000);
				status = INC;
			}
			if(button3_flag == 1){
				setTimer(1000);
				status = DEC;
			}
			break;
		case INC:
				if(isButton2Pressed() == 1){
					counter++;
					if(counter == 10){
						counter = 0;
					}
					display7SEG();
					setTimer(1000);
				}
				else{
					if(timer1_flag == 1){
						status = NORMAL;
					}
				}
			break;
		case DEC:
			if(isButton3Pressed() == 1){
				counter--;
				if(counter == -1 ){
					counter = 9;
				}
				display7SEG();
			}
			else{
				if(timer1_flag == 1){
					status = NORMAL;
				}
			}
			break;
		default:
			break;

		}

}
