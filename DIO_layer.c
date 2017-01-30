/*
 * DIO_layer.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: El-safi
 */

#include "DIO_layer.h"

/**************************   all  port  *****************************************/

U8_t EKE_DIO_InitPort(U8_t portName,U8_t value)

{
	U8_t status=1;

	switch(portName)
	{
	  case 'a':
	  case 'A':
		       DDRA=value;break;
	  case 'b':
	  case 'B':
		       DDRB=value;break;
	  case 'c':
	  case 'C':
	 		   DDRC=value;break;
	  case 'd':
	  case 'D':
	 		   DDRD=value;break;
	  default:
		       status= FAILURE;
	}

	return (status);
}

                           /********************************/
U8_t EKE_DIO_writePort(U8_t portName,U8_t value)
{
	U8_t status=1;

		switch(portName)
		{
		  case 'a':
		  case 'A':
			       PORTA=value;break;
		  case 'b':
		  case 'B':
			       PORTB=value;break;
		  case 'c':
		  case 'C':
		 		   PORTC=value;break;
		  case 'd':
		  case 'D':
		 		   PORTD=value;break;
		  default:
			       status= FAILURE;
		}

		return (status);
}
                   /***************************************/

U8_t EKE_DIO_readPort(U8_t portName)
{
	U8_t status=1;

			switch(portName)
			{
			  case 'a':
			  case 'A':
				       status=PINA;break;
			  case 'b':
			  case 'B':
			           status=PINB;break;
			  case 'c':
			  case 'C':
			           status=PINC;break;
			  case 'd':
			  case 'D':
			           status=PIND;break;
			  default:
				       status= FAILURE;
			}

			return (status);
}
/***************************************************** stop ************************************************************/



/************************** initialize pin *********************************************************************************/

U8_t EKE_DIO_InitPin (U8_t PortName, U8_t PinNumber,U8_t Direction)
{
	U8_t status =1;
	 switch(PortName)
	 {
	   case 'a':
	   case 'A':
		        switch(Direction)
		        {
		           case input:
		                        DDRA&=~(1<<PinNumber);break;
		           case output:
		        	            DDRA|=(1<<PinNumber);break;
		           default :
		        	            break;

		        }break;
	   case 'b':
	   case 'B':
		        switch(Direction)
		        {
		       	   case input:
                               DDRB&=~(1<<PinNumber);break;
		           case output:
       	                       DDRB|=(1<<PinNumber);break;
		       		  default :
		          	            break;

		        }break;


	  case 'c':
	  case 'C':
		 	   switch(Direction)
		 	   {
		 		  case input:
                              DDRC&=~(1<<PinNumber);break;

		 		  case output:
	                          DDRC|=(1<<PinNumber);break;
		 		     default :
		 		          	   break;
		 	   }break;


      case 'd':
	  case 'D':
		 	   switch(Direction)
		 	   {
		 		 case input:
                              DDRD&=~(1<<PinNumber);break;
		         case output:
	                          DDRD|=(1<<PinNumber);break;
		 			 default :
		 				       break;

		 	   }break;

	 }

	return status;
}


U8_t EKE_DIO_setPin (U8_t PortName, U8_t PinNumber)
{
	U8_t status;

	if(PinNumber>7 ||PinNumber<0)
	{
		status=FAILURE;
	}
	else
	{

		 status =1;

	 switch(PortName)
	 {
	   case 'a':
	   case 'A':
		         PORTA|=(1<<PinNumber);break;

	   case 'b':
	   case 'B':
		         PORTB|=(1<<PinNumber);break;

	   case 'c':
	   case 'C':
	             PORTC|=(1<<PinNumber);break;

       case 'd':
	   case 'D':
	             PORTD|=(1<<PinNumber);break;

	   default:
		        status=FAILURE;

	 }

	}
	return status;
}



U8_t EKE_DIO_clearPin (U8_t PortName, U8_t PinNumber)
{
	U8_t status;

	if(PinNumber>7 ||PinNumber<0)
	{
		status=FAILURE;
	}
	else
	{

		 status =1;

	 switch(PortName)
	 {
	   case 'a':
	   case 'A':
		         PORTA&=~(1<<PinNumber);break;

	   case 'b':
	   case 'B':
		         PORTB&=~(1<<PinNumber);break;

	   case 'c':
	   case 'C':
	             PORTC&=~(1<<PinNumber);break;

       case 'd':
	   case 'D':
	             PORTD&=~(1<<PinNumber);break;

	   default:
		        status=FAILURE;

	 }

	}
	return status;
}



