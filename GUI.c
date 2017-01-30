/*
 * GUI.c
 *
 *  Created on: ٢٨‏/٠١‏/٢٠١٧
 *      Author: El-safi
 */

#include "EEPROM.h"
#include "TbUart.h"
#include "AnalogDigital.h"
#include "lcdEKE.h"

int main(void){
              /*  local data types  */
//for TB and ADC
U8_t inf=0,ad=0x01;
U8_t TEMP=0,threshold=17,val='0',RET=0;
U8_t thresh_val[3]={0},index=0;
struct ANALOG setting={'A',1,1,1,64,0};
//for alarm
DDRD|=(1<<PD5);
PORTD&=~(1<<PD5);

/*     System initialization for GUI  */
 EEPROM_init();
 TbUart_init();
 ADC_init_EKE(setting);
 EKE_LCD_INIT();

while(1){
            val=TB_getchar_notWait();
switch(val){

case '0':
	//GET temperature value
    TEMP=((ADC_Read()*5)/10);
    //Store data in EEPROM
    EEPROM_Write((U8_t)ad,(U8_t)TEMP);
    inf=EEPROM_Read((U8_t)ad,(U8_t)1);
    //TB display
    TbUart_Send_stri((U8_t*)"Temperature is : ");
    TB_intNumASCII(inf);
    TbUart_Send_char('\n');

    //LCD display
    goToRowColumn(1,1);
    EKE_LCD_string((U8_t*)"Temperature:");
    goToRowColumn(1,13);
    EKE_LCD_intNumASCII((U8_t)inf);
    goToRowColumn(2,1);
    EKE_LCD_string((U8_t*)"Setting:TB-> S");

    //ALARM
      if(TEMP>=threshold){
    	   PORTD|=(1<<PD5);
    	  //LCD display
    	   EKE_clear_lcd();
    	   goToRowColumn(1,1);
           EKE_LCD_string((U8_t*)"Temperature:");
           goToRowColumn(1,13);
           EKE_LCD_intNumASCII((U8_t)inf);
   	       goToRowColumn(2,1);
           EKE_LCD_string((U8_t*)"Alarm ON");
           //TB display
           TbUart_Send_stri((U8_t*)"Alarm ON : ");
           TB_intNumASCII(inf);
           TbUart_Send_char('\n');
      }
      break;
case 'S':
    //TB threshold value
	while(1){

		           //LCD display
		    	   EKE_clear_lcd();
		    	   goToRowColumn(1,1);
		           EKE_LCD_string((U8_t*)"Threshold: ");
		           //TB display
		           TbUart_Send_stri((U8_t*)":Threshold: ");
		           //get threshold

                   for(index=0;index<2;index++){
		            thresh_val[index]=(U8_t)TbUart_get_char();
                    }
                    threshold=(U8_t)((thresh_val[0]-'0')*10+(thresh_val[1]-'0'));

		          // threshold=atoi((const char*)thresh_val);
		           //lcd
		           goToRowColumn(1,13);
		           EKE_LCD_intNumASCII((U8_t)threshold);
		   	       goToRowColumn(2,1);
		           EKE_LCD_string((U8_t*)"R:return");
                   RET=TbUart_get_char();
		           if(RET=='R'){
		        	   break;
		           }
	       }val='0',RET='0';
	         break;
}

}	return 0;

	}


