/*
 * led_driver.c
 *
 *  Created on: Oct 7, 2024
 *      Author: irene
 */


#include "common_macros.h"
#include "gpio.h"
#include "led_driver.h"

/*1. Initialize direction of pins as output
 * 2. make LEDs off at beginning
 */
void LEDS_init(void)
{
	GPIO_setupPinDirection(RED_LED_PORT_ID ,RED_LED_PIN_ID ,PIN_OUTPUT);
	GPIO_setupPinDirection(GREEN_LED_PORT_ID ,GREEN_LED_PIN_ID ,PIN_OUTPUT);
	GPIO_setupPinDirection(BLUE_LED_PORT_ID ,BLUE_LED_PIN_ID ,PIN_OUTPUT);
#if(LED_CONNECTION ==postive_connnection)
	GPIO_writePin(RED_LED_PORT_ID, RED_LED_PIN_ID, LOGIC_LOW);
	GPIO_writePin(GREEN_LED_PORT_ID, GREEN_LED_PIN_ID, LOGIC_LOW);
	GPIO_writePin(BLUE_LED_PORT_ID, BLUE_LED_PIN_ID, LOGIC_LOW);
#elif(LED_CONNECTION ==negative_connection)
	GPIO_writePin(RED_LED_PORT_ID, RED_LED_PIN_ID, LOGIC_HIGH);
	GPIO_writePin(GREEN_LED_PORT_ID, GREEN_LED_PIN_ID, LOGIC_HIGH);
	GPIO_writePin(BLUE_LED_PORT_ID, BLUE_LED_PIN_ID, LOGIC_HIGH);
#endif
}

/* make led on (High) based on led number
 * red=0  green=1  blue=2
 */
void LED_on(LED_ID ID){

#if	(LED_CONNECTION ==postive_connnection)
	if(ID==RED_LED_PIN_ID){
		GPIO_writePin(RED_LED_PORT_ID, RED_LED_PIN_ID, LOGIC_HIGH);
	}
	else if(ID==GREEN_LED_PIN_ID){
		GPIO_writePin(GREEN_LED_PORT_ID, GREEN_LED_PIN_ID, LOGIC_HIGH);
	}
	else if(ID==BLUE_LED_PIN_ID){
		GPIO_writePin(BLUE_LED_PORT_ID, BLUE_LED_PIN_ID, LOGIC_HIGH);
	}
	else{
		//do nothing
	}
#elif(LED_CONNECTION ==negative_connection)
	if(ID==RED_LED_PIN_ID){
			GPIO_writePin(RED_LED_PORT_ID, RED_LED_PIN_ID, LOGIC_LOW);
		}
		else if(ID==GREEN_LED_PIN_ID){
			GPIO_writePin(GREEN_LED_PORT_ID, GREEN_LED_PIN_ID, LOGIC_LOW);
		}
		else if(ID==BLUE_LED_PIN_ID){
			GPIO_writePin(BLUE_LED_PORT_ID, BLUE_LED_PIN_ID, LOGIC_LOW);
		}
		else{
			//do nothing
		}

#endif
}

/* make led on (High) based on led number
 * red=0  green=1  blue=2
 */
void LED_off(LED_ID ID){
#if	(LED_CONNECTION ==postive_connnection)
	if(ID==RED_LED_PIN_ID){
			GPIO_writePin(RED_LED_PORT_ID, RED_LED_PIN_ID, LOGIC_LOW);
		}
		else if(ID==GREEN_LED_PIN_ID){
			GPIO_writePin(GREEN_LED_PORT_ID, GREEN_LED_PIN_ID, LOGIC_LOW);
		}
		else if(ID==BLUE_LED_PIN_ID){
			GPIO_writePin(BLUE_LED_PORT_ID, BLUE_LED_PIN_ID, LOGIC_LOW);
		}
		else{
			//do nothing
		}
#elif(LED_CONNECTION ==negative_connection)
	     if(ID==RED_LED_PIN_ID){
				GPIO_writePin(RED_LED_PORT_ID, RED_LED_PIN_ID, LOGIC_HIGH);
			}
			else if(ID==GREEN_LED_PIN_ID){
				GPIO_writePin(GREEN_LED_PORT_ID, GREEN_LED_PIN_ID, LOGIC_HIGH);
			}
			else if(ID==BLUE_LED_PIN_ID){
				GPIO_writePin(BLUE_LED_PORT_ID, BLUE_LED_PIN_ID, LOGIC_HIGH);
			}
			else{
				//do nothing
			}
#endif
}
