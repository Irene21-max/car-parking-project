/*
 * buzzer.c
 *
 *  Created on: Oct 7, 2024
 *      Author: irene
 */

#include "common_macros.h"
#include "gpio.h"
#include "buzzer.h"

/*1. set pin of buzzer as output pin
 * 2. initialize  it to be 0
 */
void Buzzer_Init(void){
	GPIO_setupPinDirection(BUZZER_PORT_ID,BUZZER_PIN_ID, PIN_OUTPUT);
	GPIO_writePin(BUZZER_PORT_ID, BUZZER_PIN_ID, LOGIC_LOW);
}

//SET pin of buzzer 1 ON
void Buzzer_on(void)
{
	GPIO_writePin(BUZZER_PORT_ID, BUZZER_PIN_ID, LOGIC_HIGH);
}

//SET pin of buzzer 0 OFF
void Buzzer_off(void)
{
	GPIO_writePin(BUZZER_PORT_ID, BUZZER_PIN_ID, LOGIC_LOW);
}
