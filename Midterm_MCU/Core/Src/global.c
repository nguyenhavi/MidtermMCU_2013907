/*
 * global.c
 *
 *  Created on: Nov 4, 2022
 *      Author: HP
 */

#include "software_timer.h"
#include "button.h"
#include "main.h"
#include "global.h"

int counter = 7;

int flag_inc = 0;
int flag_dec = 0;

int status = INIT;

int buttonPress = 2;

int timeOut = 0;
int counterLongPress = 0;
