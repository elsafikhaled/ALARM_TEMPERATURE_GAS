/*
 * EKE_I2C.h
 *
 *  Created on: ??�/??�/????
 *      Author: El-safi
 */



#ifndef EKE_I2C_H_
#define EKE_I2C_H_
#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#include "std_data_types_EKE.h"


void EKE_I2C_init(U16_t bitRate,U8_t interrEn,U16_t prescaler);

/*********************************************************************
 * Function    : void EKE_I2C_init(U16_t bitRate,U8_t interrEn,U16_t prescaler);
 *
 * DESCRIPTION : This function used to initialize  I2C data bus
 *
 * PARAMETERS  : U16_t bitRate,U8_t interrEn,U16_t prescaler
 *
 * Return Value: Void
 ***********************************************************************/

void EKE_I2C_start(void);

/*********************************************************************
 * Function    : void EKE_I2C_start();
 *
 * DESCRIPTION : This function used to Send Start Bit data bus
 *
 * PARAMETERS  : Void
 *
 * Return Value: Void
 *
 * Notes:
 ***********************************************************************/

void EKE_I2C_stop(void);
/*********************************************************************
 * Function    : void EKE_I2C_stop(void);
 *
 * DESCRIPTION : This function used to Send Stop Bit data bus
 *
 * PARAMETERS  : Void
 *
 * Return Value: Void
 *
 ***********************************************************************/

void EKE_I2C_write(U8_t DATA);
/*********************************************************************
 * Function    : void EKE_I2C_write(U8_t DATA);
 *
 * DESCRIPTION : This function used to Write One byte one I2C data bus
 *
 * PARAMETERS  : U8_t data : Data user want to send
 *
 * Return Value: Void
 *
 * Notes:
 ***********************************************************************/

U8_t EKE_I2C_read(U8_t ACK);

/*********************************************************************
 * Function    : U8_t EKE_I2C_read(U8_t ACK);
 *
 * DESCRIPTION : This function used to Read One byte one I2C data bus
 *
 * PARAMETERS  : BOOLEAN ACK : User want to use ACK or Not
 *
 * Return Value: Void
 *
 * Notes: ACK Parameter should be 1 0r 0
 ***********************************************************************/



#endif /* EKE_I2C_H_ */
