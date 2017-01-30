/*
 * lcdEKE.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: El-safi
 */

#include "lcdEKE.h"

 const U8_t port_data='B';   // to avoid multidefinition
 const U8_t control_data='C';

void EKE_LCD_INIT(void)
{
// configure portb  4 pins as output
  EKE_DIO_InitPin(port_data,4,output);
  EKE_DIO_InitPin(port_data,5,output);
  EKE_DIO_InitPin(port_data,6,output);
  EKE_DIO_InitPin(port_data,7,output);

// configure portc 2 pins RS EN
  EKE_DIO_InitPin(control_data,6,output);
  EKE_DIO_InitPin(control_data,7,output);

/*********         configure LCD         ***********/
  // wait to be on . send 8 bit commands as datasheet said
  _delay_ms(15);
  EKE_LCD_4BIT_Write_Init(0x30);
  _delay_ms(10);
  EKE_LCD_4BIT_Write_Init(0x30);
  _delay_us(150);
  EKE_LCD_4BIT_Write_Init(0x30);
  _delay_us(150);
  EKE_LCD_4BIT_Write_Init(0x20);  // this 4 bit style as datasheet said

 // LCD CONFIGURE mode 4 bit
  EKE_LCD_command(0x28);
 // go to first line 0 position
  EKE_LCD_command(0x80);
 // cursor off and no blink
  EKE_LCD_command(0x0c);
 // automatic increament and no display shift
  EKE_LCD_command(0x06);
 // clear lcd no display
	EKE_clear_lcd();


}
///////////////////////////////////////////////////////////////////////////////////////

void EKE_LCD_command(U8_t command)
{
// register select=0 to send command to LCD
   controlPort&=~(1<<RS);
// clear 4 pins in portb
   EKE_DIO_clearPin(port_data_name,4);
   EKE_DIO_clearPin(port_data_name,5);
   EKE_DIO_clearPin(port_data_name,6);
   EKE_DIO_clearPin(port_data_name,7);

// send 4 high bits
   if(command & 0x80)portData|=(1<<data_B_pin7);
   if(command & 0x40)portData|=(1<<data_B_pin6);
   if(command & 0x20)portData|=(1<<data_B_pin5);
   if(command & 0x10)portData|=(1<<data_B_pin4);

// now sending 4bits
   EKE_LCD_enable();

// clear 4 pins in portb
    EKE_DIO_clearPin(port_data_name,4);
    EKE_DIO_clearPin(port_data_name,5);
    EKE_DIO_clearPin(port_data_name,6);
    EKE_DIO_clearPin(port_data_name,7);

// send 4 low  bits
    if(command & 0x08)portData|=(1<<data_B_pin7);
    if(command & 0x04)portData|=(1<<data_B_pin6);
    if(command & 0x02)portData|=(1<<data_B_pin5);
    if(command & 0x01)portData|=(1<<data_B_pin4);

// now sending 4bits
   EKE_LCD_enable();
// wait for running the command
   _delay_us(300);
}

///////////////////////////////////////////////////////////////////////////////////////////
void EKE_LCD_data(U8_t data)
{
	// register select=1 to send data to LCD
	   controlPort|=(1<<RS);
	// clear 4 pins in portb
	   EKE_DIO_clearPin(port_data_name,4);
	   EKE_DIO_clearPin(port_data_name,5);
	   EKE_DIO_clearPin(port_data_name,6);
	   EKE_DIO_clearPin(port_data_name,7);

	// send 4 high bits
	   if(data & 0x80)portData|=(1<<data_B_pin7);
	   if(data & 0x40)portData|=(1<<data_B_pin6);
	   if(data & 0x20)portData|=(1<<data_B_pin5);
	   if(data & 0x10)portData|=(1<<data_B_pin4);

	// now sending 4bits
	   EKE_LCD_enable();

	// clear 4 pins in portb
	    EKE_DIO_clearPin(port_data_name,4);
	    EKE_DIO_clearPin(port_data_name,5);
	    EKE_DIO_clearPin(port_data_name,6);
	    EKE_DIO_clearPin(port_data_name,7);

	// send 4 low  bits
	    if(data & 0x08)portData|=(1<<data_B_pin7);
	    if(data & 0x04)portData|=(1<<data_B_pin6);
	    if(data & 0x02)portData|=(1<<data_B_pin5);
	    if(data & 0x01)portData|=(1<<data_B_pin4);

	// now sending 4bits
	   EKE_LCD_enable();
	// wait for running the command
	   _delay_us(300);

}

///////////////////////////////////////////////////////////////////////////////////////
void EKE_LCD_enable(void)
{
	controlPort|=(1<<EN);
	_delay_ms(1);
	controlPort&=~(1<<EN);
	_delay_ms(1);
}
///////////////////////////////////////////////////////////////////////////////////////////

void EKE_clear_lcd(void)
{
	EKE_LCD_command(0x01);
	_delay_ms(15);
}
////////////////////////////////////////////////////////////////////////////////////////////

void goToRowColumn(U8_t row,U8_t column)
{
	U8_t firstAddress[] = {0x80,0xC0,0x94,0xD4};

	 	EKE_LCD_command(firstAddress[row-1] + column-1);
	 	_delay_ms(10);
}
////////////////////////////////////////////////////////////////////////////////////////

void EKE_LCD_string(U8_t *str)
{
	U8_t i = 0;

	 	while(str[i]!=0)
	 	{
	 		EKE_LCD_data(str[i]);
	 		i++;
	 	}
}
///////////////////////////////////////////////////////////////////////////////////////

void EKE_LCD_intNumASCII(U16_t Number)
{
  char buffer[16]={0};
  itoa(Number,(char*)buffer,10);  // 10 to convert only to numbers more 10 will print litters
  EKE_LCD_string((U8_t*)buffer);
}
///////////////////////////////////////////////////////////////////////////////////////////
void EKE_LCD_4BIT_Write_Init ( U8_t temp)
{
  portData=temp;
 // register select=0 to send command to LCD
  controlPort&=~(1<<RS);
  EKE_LCD_enable();
}


/////////////////////////////////////////////////////////////////////////////


char *ftoa(char *buffer, double d, int precision)
{

	long wholePart = (long) d;

	// Deposit the whole part of the number.

	itoa(wholePart,buffer,10);

	// Now work on the faction if we need one.

	if (precision > 0) {

		// We do, so locate the end of the string and insert
		// a decimal point.

		char *endOfString = buffer;
		while (*endOfString != '\0') endOfString++;
		*endOfString++ = '.';

		// Now work on the fraction, be sure to turn any negative
		// values positive.

		if (d < 0) {
			d *= -1;
			wholePart *= -1;
		}

		double fraction = d - wholePart;
		while (precision > 0) {

			// Multipleby ten and pull out the digit.

			fraction *= 10;
			wholePart = (long) fraction;
			*endOfString++ = '0' + wholePart;

			// Update the fraction and move on to the
			// next digit.

			fraction -= wholePart;
			precision--;
		}

		// Terminate the string.

		*endOfString = '\0';
	}

   return buffer;
}
/////////////////////////////////////////////////////////////////////////////////////////////////
















