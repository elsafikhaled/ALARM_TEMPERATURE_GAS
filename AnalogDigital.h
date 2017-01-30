/*
 * AnalogDigital.h
 *
 *  Created on: ٢٦‏/٠١‏/٢٠١٧
 *      Author: El-safi
 */

#ifndef ANALOGDIGITAL_H_
#define ANALOGDIGITAL_H_
#include <avr/io.h>
#include <avr/interrupt.h>
#include "std_data_types_EKE.h"


/*                  ***** ADC MODULE *****
 *
 *  pass the <struct ANALOG setting > to init function
 *
 *  get digital value.
 *
 *
 * **************************************************************************************/

struct ANALOG{
    U8_t  PORT;
	U8_t  ADC_EN:1;
    U8_t  ADC_NUM;
    U8_t  ADC_volt_ref:1;
    U8_t  ADC_divistion_factor;
    U8_t  Interr_EN:1;
};


enum CONFIGUR_PORT{
	OUTPUT=1,
	INPUT=0
};

/*          Default setting    */
//struct ANALOG setting={'A',1,0,1,64,0};


// ******************************************************************************

extern void PortName_init(U8_t charachter,U8_t pins);
/* Inputs:: U8_t charachter,U8_t pins
 *
 * FUN   :: to configure the I/O port
 *
 * ***********************************************/
extern void ADC_init_EKE(struct ANALOG  setting);
/*Inputs:: passe the structure of setting
 *
 * FUN  :: configure the ADC module
 *
 * **********************************************/
extern U16_t ADC_Read(void);
/*Ouputs:: return the 10 bits from conversion
 *
 * FUN  :: get digital value that equal analog value
 *
 * **********************************************/



#endif /* ANALOGDIGITAL_H_ */
