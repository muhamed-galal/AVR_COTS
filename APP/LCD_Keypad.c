/*
 * Keypad.c
 *
 *  Created on: Jun 11, 2023
 *      Author: Muham
 */

#include "../MCAL/DIO/DIO_Interface.h"
#include "../HAL/KEYPAD/KPD_Interface.h"
#include "../HAL/LCD/Lcd_Interface.h"

void main()
{
	u8 Arr[8]={0x00,
		  0x00,
		  0x11,
		  0x11,
		  0x1F,
		  0x1F,
		  0x04,
		  0x00};				//Send Special character
	u8 pressed;

	Lcd_Info lcd1 = {DIO_GroupB , DIO_GroupB , DIO_GroupB  , Pin2 , Pin1 , Pin0 , DIO_GroupA};
	KPD_INFO KP={DIO_GroupC,Pin0,DIO_GroupC,Pin1,DIO_GroupC,Pin2,DIO_GroupC,Pin3,DIO_GroupC,Pin4,DIO_GroupC,Pin5,DIO_GroupC,Pin6,DIO_GroupC,Pin7};

	Lcd_VoidInit(&lcd1);
	//	Lcd_VoidSendNumber(899965,&lcd1);
	Lcd_VoidSendSpecialChar(Arr,0,0,0,&lcd1);
	Lcd_VoidGoXY(&lcd1,line1,Coloum5);
	Lcd_VoidSendString("Galal",&lcd1);

	while(1)
	{
		pressed= KeyPad(&KP);
		Lcd_VoidSendChar(pressed,&lcd1);
		Lcd_VoidSendString("Galal ",&lcd1);
	}
}
