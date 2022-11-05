/*
 * global.h
 *
 *  Created on: Nov 4, 2022
 *      Author: HP
 */

#ifndef INC_GLOBAL_H_
#define INC_GLOBAL_H_

#include "software_timer.h"
#include "button.h"
#include "main.h"

#define TIMER_FOR_KEYPRESS 200
#define INIT 			0
#define Normal_Press 	1
#define Long_Press		2
#define Timeout10s		3
#define Normal			4

extern int counter;

extern int status;

extern int flag_inc;
extern int flag_dec;

extern int timeOut;
extern int counterLongPress;
extern int buttonPress;

#endif /* INC_GLOBAL_H_ */
