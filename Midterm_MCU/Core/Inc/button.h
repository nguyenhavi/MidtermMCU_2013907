/*
 * button.h
 *
 *  Created on: Nov 4, 2022
 *      Author: HP
 */

#ifndef INC_BUTTON_H_
#define INC_BUTTON_H_

#include "main.h"

#define NORMAL_STATE GPIO_PIN_SET
#define PRESSED_STATE GPIO_PIN_RESET

int isButton1Pressed();
int isButton2Pressed();
int isButton3Pressed();

int isButton1Release();
int isButton2Release();
int isButton3Release();

void getKeyInput();

#endif /* INC_BUTTON_H_ */
