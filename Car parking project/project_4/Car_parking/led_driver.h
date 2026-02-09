/*
 * led_driver.h
 *
 *  Created on: Oct 7, 2024
 *      Author: irene
 */

#ifndef LED_DRIVER_H_
#define LED_DRIVER_H_

#include "std_types.h"

/*******************************************************************************
 *                                Definitions                                  *
 *******************************************************************************/
#define LED_CONNECTION       postive_connnection
#define RED_LED_PORT_ID      PORTC_ID
#define RED_LED_PIN_ID       PIN0_ID
#define GREEN_LED_PORT_ID    PORTC_ID
#define GREEN_LED_PIN_ID     PIN1_ID
#define BLUE_LED_PORT_ID     PORTC_ID
#define BLUE_LED_PIN_ID      PIN2_ID

/*******************************************************************************
 *                               Types Declaration                             *
 *******************************************************************************/
typedef enum{
	postive_connnection,negative_connection
}led_connection;


typedef enum{
	red , green , blue
}LED_ID;

/*******************************************************************************
 *                              Functions Prototypes                           *
 *******************************************************************************/


/*1. Initialize direction of pins as output
 * 2. make LEDs off at beginning
 */
void LEDS_init(void);

/* make led on (High) based on led number
 * red=0  green=1  blue=2
 */
void LED_on(LED_ID ID);

/* make led on (High) based on led number
 * red=0  green=1  blue=2
 */
void LED_off(LED_ID ID);

#endif /* LED_DRIVER_H_ */
