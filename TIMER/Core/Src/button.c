/*
 * button.c
 *
 *  Created on: Oct 11, 2022
 *      Author: Hong Phat
 */

/*
 * Button.c
 *
 *  Created on: Sep 27, 2022
 *      Author: Admin
 */
#include "Button.h"
#include "main.h"

int KeyReg0 = NORMAL_STATE;
int KeyReg1 = NORMAL_STATE;
int KeyReg2 = NORMAL_STATE;
int KeyReg3 = NORMAL_STATE;

int TimeOutForKeyPress =  100;
int button1_flag = 0;

int isButton1Pressed(){
	if(button1_flag == 1){
		button1_flag = 0;
		return 1;
	}
	return 0;
}
void subKeyProcess(){
	//TODO
	HAL_GPIO_TogglePin(GPIOA,GPIO_PIN_5);
	button1_flag = 1;
}

void getKeyInput(){
  KeyReg0 = KeyReg1;
  KeyReg1 = KeyReg2;
  KeyReg2 = HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_4);
  if ((KeyReg1 == KeyReg0) && (KeyReg1 == KeyReg2)){
	  if (KeyReg2 != KeyReg3){
		  KeyReg3 = KeyReg2;
		  if (KeyReg2 == PRESSED_STATE){
			TimeOutForKeyPress = 100;
			subKeyProcess();
		  }
    }else{
       TimeOutForKeyPress --;
        if (TimeOutForKeyPress == 0){
          KeyReg3 = NORMAL_STATE;
        }
    }
  }
}
