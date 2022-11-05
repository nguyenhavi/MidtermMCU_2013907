/*
 * normal_press.c
 *
 *  Created on: Nov 5, 2022
 *      Author: HP
 */

#include "normal_press.h"
#include "display7SEG.h"

void NormalPress(){
	display7SEG(counter);
	if(isButton1Pressed() == 1){
		counter = 0;
	}
	if(isButton2Pressed() == 1){
		counter++;
		if(counter >= 10){
			counter = 0;
		}
	}
	if(isButton3Pressed() == 1){
		counter--;
		if(counter <= -1){
			counter = 9;
		}
	}
}
