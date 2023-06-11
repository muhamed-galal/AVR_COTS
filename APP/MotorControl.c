/*
 * MotorControl.c
 *
 *  Created on: Apr 18, 2023
 *      Author: Muham
 */

#include "std_types.h"
#include "../MCAL/GIE/GIE_interface.h"
#include "../MCAL/DIO/DIO_Interface.h"
#include "../HAL/LCD/Lcd_Interface.h"
#include "../HAL/KEYPAD/KPD_Interface.h"
#include "../MCAL/Timer/Timer_2/Timer2_Interface.h"
#include "util/delay.h"

Lcd_Info LCD1={DIO_GroupB,DIO_GroupB,DIO_GroupB,Pin2,Pin1,Pin0,DIO_GroupA};
KPD_INFO KP={DIO_GroupC,Pin0,DIO_GroupC,Pin1,DIO_GroupC,Pin2,DIO_GroupC,Pin3,DIO_GroupC,Pin4,DIO_GroupC,Pin5,DIO_GroupC,Pin6,DIO_GroupC,Pin7};
u8 array[5]={'0','0','%','\0'};
u8 pressed;
float speed=0;

void Fast_PWM(void);

void main(void)
{

	DIO_ErrStateSetPinDirection(DIO_GroupD,Pin7,DIO_Output);	// OC2 Pin

	TIMER2_voidInit();

	while(1)
	{
		pressed= KeyPad(&KP);
		if(pressed == '%')
		{
			Lcd_VoidInit(&LCD1);
			Lcd_VoidSendString("Enter The Speed",&LCD1);
			_delay_ms(500);
			Lcd_VoidInit(&LCD1);
			Lcd_VoidGoXY(&LCD1,0,0);
			Lcd_VoidSendString("Speed",&LCD1);
			Lcd_VoidGoXY(&LCD1,1,0);
			Lcd_VoidSendString(array,&LCD1);
			for(u8 count=0;count<2;count++)
			{
				pressed= KeyPad(&KP);
				if(pressed == '=') break;
				array[count]=pressed;
				Lcd_VoidInit(&LCD1);
				Lcd_VoidGoXY(&LCD1,0,0);
				Lcd_VoidSendString("Speed",&LCD1);
				Lcd_VoidGoXY(&LCD1,1,0);
				Lcd_VoidSendString(array,&LCD1);
			}
			speed= ((( array[0]-'0') * 10 + ( array[1]-'0'))*2.5);
			TIMER2_voidSetCallBachFn(&Fast_PWM);

		}

	}
}

void Fast_PWM(void)
{
	OCR2_REG =(unsigned char)speed;
}
