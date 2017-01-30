/*
 * EKE_I2C.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: El-safi
 */
#include "EKE_I2C.h"


void EKE_I2C_init(U16_t bitRate,U8_t interrEn,U16_t prescaler)
{
	// write bitrate, prescaler and enable the I2C module.
    TWSR=prescaler;
	TWBR=bitRate;
	TWCR=(1<<TWEN);

    // check interrupt
	if(interrEn==1)
	{
		TWCR|=(1<<TWIE);
	}
	else{TWCR&=~(1<<TWIE);}

}
// ///////////////////////////  MASTER  write control /////////////////////////////////////

                          /** start **/
void EKE_I2C_start(void)
{
	// to use TWI(I2C) as a master  must clear twint first and enable  the module and start bit on.
	TWCR=(1<<TWEN)|(1<<TWSTA)|(1<<TWINT);
	// check that bus is empty
	while(!(TWCR&(1<<TWINT)));

}
                      /** stop **/

void EKE_I2C_stop(void)
{
	// turn off clock and stop master operation
	TWCR=(1<<TWINT)|(1<<TWEN)|(1<<TWSTO);
}

                            /** Write **/

void EKE_I2C_write(U8_t DATA)
{   // buffer data
	TWDR=DATA;
	// start sending data
	TWCR=(1<<TWINT)|(1<<TWEN);
	// check data transfered
	while(!(TWCR&(1<<TWINT)));
}

// ////////////////////////////////          READ           ///////////////////////////////////////

U8_t EKE_I2C_read(U8_t ACK)
{
	// start recieving data
	TWCR=(1<<TWINT)|(1<<TWEN)|(ACK <<TWEA);
	// check data recieved
	while(!(TWCR&(1<<TWINT)));
    return TWDR;

}

// //////////////////////////////////////////////////////////////////////////////////////////////





