/*
 * global.h
 *
 *  Created on: Oct 9, 2022
 *      Author: Hong Phat
 */
#include "software_timer.h"
#include "button.h"

#ifndef INC_GLOBAL_H_
#define INC_GLOBAL_H_

#define INIT			1
#define INIT9			2
#define NORMAL			3
#define INC				4
#define DEC				5
#define RESET			6
#define INC_LONGPRESS	 	7
#define	DEC_LONGPRESS	8

extern int counter;
extern int status;

//extern int status ;
//extern int status2;
//extern int timer_red;
//extern int timer_yellow;
//extern int timer_green;
//
//#define MAN_RED 12
//#define MAN_GREEN 13
//#define MAN_YELLOW 14


#endif /* INC_GLOBAL_H_ */
