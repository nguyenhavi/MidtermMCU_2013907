/*
 * fsm_simple_button.c
 *
 *  Created on: Nov 5, 2022
 *      Author: HP
 */

#include "fsm_simple_button.h"
#include "normal_press.h"
#include "display7SEG.h"

//Button1 is RESET
//Button2 is INC
//Button3 is DEC

void fsm_simple_button_run(){
	switch(status){
		case INIT:
			display7SEG(counter);
			status = Normal;
			setTimer1(100);
			break;
		case Normal:
			display7SEG(counter);
			if(!HAL_GPIO_ReadPin(Button1_GPIO_Port, Button1_Pin)
					|| !HAL_GPIO_ReadPin(Button2_GPIO_Port, Button2_Pin)
					|| !HAL_GPIO_ReadPin(Button3_GPIO_Port, Button3_Pin)){
				status = Normal_Press;
				timeOut = 0;
			}
			if(timeOut >= 10){
				//in 10s, not do anything, turn into Timeout10s state
				status = Timeout10s;
			}
			if(timer1_flag == 1){
				setTimer1(100);
				timeOut++;
			}
			break;
		case Normal_Press:
			NormalPress();
			if(counterLongPress >= 3){
				//if press more than 3s, turn into Long_Press state
				status = Long_Press;
			}
			if(isButton1Release() && isButton2Release() && isButton3Release()){
				status = Normal;
				flag_inc = 0;
				flag_dec = 0;
				counterLongPress = 0;
			}
			if(timer1_flag == 1){
				if(isButton2Release() == 0){
					counterLongPress++;
					buttonPress = 2;
					flag_inc = 1;
				}
				if(isButton3Release() == 0){
					counterLongPress++;
					buttonPress = 3;
					flag_dec = 1;
				}
				setTimer1(100);
			}
			break;
		case Long_Press:
			display7SEG(counter);
			if(isButton2Release() && buttonPress == 2){
				flag_inc = 0;
				status = Normal;
				counterLongPress = 0;
				buttonPress = 0;
			}
			if(isButton3Release() && buttonPress == 3){
				flag_dec = 0;
				status = Normal;
				counterLongPress = 0;
				buttonPress = 0;
			}
			if(timer1_flag == 1){
				//Auto increase
				if(flag_inc == 1){
					counter++;
					if(counter >= 10){
						counter = 0;
					}
				}
				//Auto decrease
				if(flag_dec == 1){
					counter--;
					if(counter <= -1){
						counter = 9;
					}
				}
				setTimer1(100);
			}
			break;
		case Timeout10s:
			display7SEG(counter);
			//If any button is pressed, turn into Normal_Press state
			if(!HAL_GPIO_ReadPin(Button1_GPIO_Port, Button1_Pin)
					|| !HAL_GPIO_ReadPin(Button2_GPIO_Port, Button2_Pin)
					|| !HAL_GPIO_ReadPin(Button3_GPIO_Port, Button3_Pin)){
				status = Normal_Press;
			}
			if(timer1_flag == 1){
			//Count down counter variable
				counter--;
				if(counter <= 0){
					counter = 0;
				}
				setTimer1(100);
			}
			break;
		default:
			break;
	}

}
