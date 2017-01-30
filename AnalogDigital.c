/*
 * AnalogDigital.c
 *
 *  Created on: ٢٦‏/٠١‏/٢٠١٧
 *      Author: El-safi
 */
#include "AnalogDigital.h"

/*         ***   PORT CONFIGURATION FOR ADC MODULE       ***                           */
extern void PortName_init(U8_t charachter,U8_t pins){
// FILL FUNCTINO HERE
switch(charachter){

case 'a':
case 'A':
	  switch(pins){
	  case OUTPUT:
		  DDRA=0xff;break;
	  case INPUT:
		  DDRA=0x00;break;
	  }break;
case 'b':
case 'B':
	  switch(pins){
 	  case OUTPUT:
 		  DDRB=0xff;break;
	  case INPUT:
		  DDRB=0x00;break;
 	  }break;
case 'c':
case 'C':
	  switch(pins){
	  case OUTPUT:
	  	  DDRC=0xff;break;
	  case INPUT:
	  	  DDRC=0x00;break;
	  }break;
case 'd':
case 'D':
	   switch(pins){
	   case OUTPUT:
	  	  DDRD=0xff;break;
	   case INPUT:
	  	  DDRD=0x00;break;
	   }break;
default:
		break;
    }
}

/* **************** END OF FUNCTION ***********************  */

                 /*   ADC INITIALIZATION  */

extern void ADC_init_EKE(struct ANALOG  setting){

 // initialize port for ADC module
  PortName_init(setting.PORT,OUTPUT);

// TEST ADC enable
 if(setting.ADC_EN==1){
                            /* Configure all setting :: !! */
//Enable the ADC module
ADCSRA|=(1<<ADEN);
//Choose the voltage reference
      switch(setting.ADC_volt_ref){
         case 1://internal voltage
               ADMUX|=(1<<REFS0)|(1<<REFS1);break;
         case 0://External voltage source but don't forget the capacitor for noiseless
        	  ADMUX|=(1<<REFS0);break;
         default:break;
                                  }
//choose the division factor
      switch(setting.ADC_divistion_factor){
         case 2:
        	 ADCSRA|=(1<<ADPS0);break;
         case 4:
        	 ADCSRA|=(1<<ADPS1);break;
         case 8:
        	 ADCSRA|=(1<<ADPS1)|(1<<ADPS0);break;
         case 16:
        	 ADCSRA|=(1<<ADPS2);break;
         case 32:
        	 ADCSRA|=(1<<ADPS0)|(1<<ADPS2);break;
         case 64:
        	 ADCSRA|=(1<<ADPS2)|(1<<ADPS1);break;
         case 128:
        	 ADCSRA|=(1<<ADPS2)|(1<<ADPS1)|(1<<ADPS0);break;
         default:break;
                                         }
//Choose ADC Multiblixer number
      switch(setting.ADC_NUM){
        case 0:
        	ADMUX&=~(1<<MUX0)|(1<<MUX1)|(1<<MUX2)|(1<<MUX3)|(1<<MUX4);break;
        case 1:
        	ADMUX|=(1<<MUX0);break;
        case 2:
        	ADMUX|=(1<<MUX1);break;
        case 3:
        	ADMUX|=(1<<MUX1)|(1<<MUX0);break;
        case 4:
        	ADMUX|=(1<<MUX2);break;
        case 5:
        	ADMUX|=(1<<MUX2)|(1<<MUX0);break;
        case 6:
        	ADMUX|=(1<<MUX2)|(1<<MUX1);break;
        case 7:
        	ADMUX|=(1<<MUX2)|(1<<MUX1)|(1<<MUX0);break;
        default:break;
                             }
//Interrupt configuration
      if(setting.Interr_EN==1){
          ADCSRA|=(1<<ADIE);
          sei();
      }

      else if(setting.Interr_EN==0){
      	ADCSRA&=~(1<<ADIE);
    	ADCSRA|=(1<<ADIF);
      }

 }

 else if(setting.ADC_EN==0){
     ADMUX=0x00;
   }

}

/* *************************************************************************************** */
extern U16_t ADC_Read(void){
//start conversion
	ADCSRA|=(1<<ADSC);
//check if conversion completed then ADSC will return to zero again
    while(ADCSRA&(1<<ADSC));

	return ADC;
}

