/*
 * lcdEKEconfig.h
 *
 *  Created on: ??�/??�/????
 *      Author: El-safi
 */



#ifndef LCDEKECONFIG_H_
#define LCDEKECONFIG_H_



#include <avr/io.h>
#include <util/delay.h>
#include <stdlib.h>
#include "DIO_layer.h"



 /***************   data on PORTB CONFIGURATION ******************************/
#define portData             PORTB
#define port_data_name      'B'
#define data_B_pin4          PB4
#define data_B_pin5          PB5
#define data_B_pin6          PB6
#define data_B_pin7          PB7

/***************  CONTROL ON  PORTC CONFIGURATION *******************************/
#define controlPort          PORTC
#define port_control_name    'C'
#define RS                   PC6
#define EN                   PC7
/*
 *  #define RW               PC5
 *                          >>in my case I only write to lcd
 *                            so it is connected to GND.
 *                          >>TO READ from it. connect it to high signal or Vcc  +5 .
 */
/**********************************************************************************/

extern const U8_t port_data;
extern const U8_t control_data;











#endif /* LCDEKECONFIG_H_ */
