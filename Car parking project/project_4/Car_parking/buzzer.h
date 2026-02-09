/*
 * buzzer.h
 *
 *  Created on: Oct 7, 2024
 *      Author: irene
 */

#ifndef BUZZER_H_
#define BUZZER_H_

#include "std_types.h"
/*******************************************************************************
 *                                Definitions                                  *
 *******************************************************************************/
#define BUZZER_PORT_ID     PORTC_ID
#define BUZZER_PIN_ID      PIN5_ID

/*******************************************************************************
 *                              Functions Prototypes                           *
 *******************************************************************************/

/*1. set pin of buzzer as output pin
 * 2. initialize  it to be 0
 */
void Buzzer_Init(void);
//SET pin of buzzer 1 ON
void Buzzer_on(void);

//SET pin of buzzer 0 OFF
void Buzzer_off(void);


#endif /* BUZZER_H_ */
