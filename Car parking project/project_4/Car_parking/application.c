/*
 * application.c
 *
 *  Created on: Oct 12, 2024
 *      Author: irene
 */

#include "lcd.h"
#include "buzzer.h"
#include "led_driver.h"
#include "ultrasonic.h"
#include <avr/io.h> /* To use the SREG register */
#include <util/delay.h>

#define D  250

void LEDS_update(uint16 check_distance){
	if(check_distance>20){
		LED_off(red);
		LED_off(blue);
		LED_off(green);

	}
	else if(check_distance>=16 && check_distance<=20){
		LED_on(red);
		LED_off(green);
		LED_off(blue);
	}
	else if (check_distance>=11 && check_distance<=15){
		LED_on(red);
		LED_on(green);
		LED_off(blue);
	}
	else if(check_distance>=6 && check_distance<=10){
		LED_on(red);
		LED_on(blue);
		LED_on(green);
	}
	else if(check_distance<=5){
		LED_on(red);
		LED_on(blue);
		LED_on(green);
		_delay_ms(250);
		LED_off(red);
		LED_off(green);
		LED_off(blue);
		_delay_ms(250);
	}
}

void Buzzer_update(uint16 check_distance){
	if(check_distance>=0 && check_distance<=5){
		Buzzer_on();
		_delay_ms(250);
		Buzzer_off();
	}
	else{
		Buzzer_off();
	}
}

void  LCD_update(uint16 check_distance){
	if(check_distance<=5){
		LCD_moveCursor(0,11);
		LCD_intgerToString(check_distance);
		LCD_moveCursor(1,6);
		LCD_displayString("Stop");
	}
	else if (check_distance>=6){
		LCD_moveCursor(0,11);
		if(check_distance<10){
			LCD_intgerToString(check_distance);
			LCD_displayString(" ");
		}
		else if(check_distance>=10){
			LCD_intgerToString(check_distance);
		}
		LCD_moveCursor(1,6);
		LCD_displayString("     ");
	}
}

int main(void){
	uint16 distance=0;
		/*LCD initialization*/
		LCD_init();


		/* Enable Global Interrupt I-Bit */
		SREG |= (1<<7);

		/*LEDs initialization*/
		LEDS_init();

		/*Buzzer initialization*/
		Buzzer_Init();

		/*moving cursor in specific location in first row*/
		LCD_moveCursor(0,1);

		LCD_displayString("Distance=   cm");

		/*ultrasonic initialization*/
		Ultrasonic_init();

		while(1)
		{
		distance=Ultrasonic_readDistance();

		_delay_ms(D);

		LEDS_update(distance);
		Buzzer_update(distance);
		LCD_update(distance);

	}
}

