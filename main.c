/*
 * main.c
 *
 *  Created on: Jul 22, 2025
 *      Author: Ahmed Oraby
 */
#include "../LIB/BIT_MATH.h"
#include "../LIB/STD_TYPES.h"

#include "../MCAL/DIO/DIO.h"
#include "../MCAL/ADC/ADC.h"

#include "../HAL/LED/LED.h"
#include "../HAL/PB/PB.h"
#include "../HAL/KP/KP.h"
#include "../HAL/LCD/LCD.h"
#include "../HAL/Buzzer/Buzzer.h"
#include "../HAL/SEVEN_SEG/SEVEN_SEG.h"
u8 AlAF[]={ 0x06, 0x04, 0x0E, 0x00, 0x04, 0x04, 0x04, 0x04 };
u8 MEM[]={ 0x00, 0x00, 0x00, 0x1F, 0x05, 0x07, 0x00, 0x00 };
u8 HAA[]={ 0x00, 0x00, 0x0E, 0x02, 0x1F, 0x00, 0x00, 0x00 };
u8 DAL[]= { 0x00, 0x00, 0x01, 0x01, 0x07, 0x00, 0x00, 0x00 };


#include <util/delay.h>

u16 Current_temp=0;       //Current temperature
u16 temp_Value=0;
u8 Set_value =0;    // Set temperature
u8 SET_TEMP=0;
u8 x=9;
void temp_fun (void)
{
	Current_temp = ADC_ReadDataUsingInterrupt()*0.25 ;
}



void main (void)
{
	LCD_Init() ;
	LCD_WriteString("Set Temp:") ;
	ADC_init(ADC_REFERANCE_INTERNAL) ;
	ADC_CallBack(temp_fun) ;

	KP_Init       (DIO_PORTB) ;

	LED_Init (DIO_PORTD,DIO_PIN3);
	LED_Init (DIO_PORTD,DIO_PIN4);

	while (1)
	{
		SET_TEMP= KP_GetValue (DIO_PORTB ) ;
		if(SET_TEMP >= '0' && SET_TEMP <= '9')
		{
			if(x < 11)
			{
				LCD_Move_Cursor (0,x);
				LCD_WriteData(SET_TEMP) ;
				if(x==10)
				{
					Set_value *=10;
				}
				x++;
				SET_TEMP -= '0';
				Set_value += SET_TEMP;
			}
		}
		else if(SET_TEMP == 'C')
		{
			LCD_Clear_Display();
			LCD_WriteString("Set Temp:") ;
			x=9;
			Set_value=0;
		}
		else{}

		LCD_Move_Cursor(1, 0) ;
		ADC_StartConversion(ADC_CHANNEL0) ;
		Current_temp = ADC_ReadDataUsingPolling()*0.25 ;
		temp_Value = Current_temp;
		LCD_WriteData((Current_temp/100)+'0') ;
		Current_temp = Current_temp%100 ;
		LCD_WriteData((Current_temp/10)+'0') ;
		Current_temp = Current_temp%10 ;
		LCD_WriteData(Current_temp+'0') ;

		if(temp_Value < Set_value)
		{
			LED_On(DIO_PORTD,DIO_PIN3);
			LED_Off(DIO_PORTD,DIO_PIN4);
		}
		else if(temp_Value == Set_value)
		{
			LED_Off(DIO_PORTD,DIO_PIN3);
			LED_Off(DIO_PORTD,DIO_PIN4);
		}
		else
		{
			LED_Off(DIO_PORTD,DIO_PIN3);
			LED_On(DIO_PORTD,DIO_PIN4);
		}

	}



}


