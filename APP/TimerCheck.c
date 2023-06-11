///*
// * TimerCheck.c
// *
// *  Created on: Apr 12, 2023
// *      Author: Muham
// */
//
//
//
//void Fast_PWM(void)
//{
//	OCR2_REG = 0;
//	_delay_ms(2000);
//
//	OCR2_REG = 50;
//	_delay_ms(2000);
//
//	OCR2_REG = 100;
//	_delay_ms(2000);
//
//	OCR2_REG = 150;
//	_delay_ms(2000);
//
//	OCR2_REG = 200;
//	_delay_ms(2000);
//
//	OCR2_REG = 250;
//	_delay_ms(2000);
//
//}
//
//void Normal_Mode()
//{
//
//	static u16 Counter1,Counter2,Counter3;
//	Counter1++;
//	Counter2++;
//	Counter3++;
//
//	if(Counter1==1954)
//	{
//		TCNT2_REG=224;
//		Tog_Bit(PORTA,0);
//
//
//	}
//	if(Counter2==3907)
//	{
//		TCNT2_REG=224;
//		Tog_Bit(PORTA,1);
//		Counter2=0;
//	}
//	if(Counter3==7813)
//	{
//		TCNT2_REG=224;
//		Tog_Bit(PORTA,2);
//		Counter3=0;
//
//	}
//
//}
//
//
///**********************************Timer check **********************************************************
//
//	DIO_ErrStateSetPinDirection(DIO_GroupA,Pin0,DIO_Output);
//	DIO_ErrStateSetPinDirection(DIO_GroupD,Pin7,DIO_Output);	// OC2 Pin
//	DIO_ErrStateSetPinValue(DIO_GroupA,Pin0,DIO_High);
//
//	DIO_ErrStateSetPinDirection(DIO_GroupA,Pin1,DIO_Output);
//	DIO_ErrStateSetPinDirection(DIO_GroupA,Pin2,DIO_Output);
//
//	TIMER2_voidInit();
//
//	OCR2_REG = 250;
//
//	//TCNT2_REG=224;
//
//	TIMER2_voidSetCallBachFn(&CTC_Mode);
//
//	while(1)
//	{
//
//	}
// */
//
///*	digital clock if conditions
// * static u32 counter_1,counter_2,counter_3;
//counter_1++;
//counter_2++;
//counter_3++;
//
////Lcd_VoidGoXY(&LCD1,0,0);
////Lcd_VoidSendString(array,&LCD1);
//
//if(counter_1==125)
//{
//	static u32 Seconds1=1;
//	if(Seconds1<10)
//	{
//		array[7]=48+Seconds1;
//		Lcd_VoidGoXY(&LCD1,0,0);
//		Lcd_VoidSendString(array,&LCD1);
//	}
//	else if(Seconds1>=10 && Seconds1<60)
//	{
//		array[7]=48+(Seconds1%10);
//		array[6]=48+(Seconds1/10);
//		Lcd_VoidGoXY(&LCD1,0,0);
//		Lcd_VoidSendString(array,&LCD1);
//	}
//	counter_1=0;
//	Seconds1++;
//	if(Seconds1==60)
//	{
//		Seconds1=0;
//		array[6]='0';array[7]='0';
//	}
//}
//if(counter_2 == 125*60)
//{
//	static u32 Minutes1=1;
//	if(Minutes1<10)
//	{
//
//		array[4]=48+Minutes1;
//		Lcd_VoidGoXY(&LCD1,0,0);
//		Lcd_VoidSendString(array,&LCD1);
//	}
//	else if(Minutes1>=10 && Minutes1<60)
//	{
//		array[4]=48+(Minutes1%10);
//		array[3]=48+(Minutes1/10);
//		Lcd_VoidGoXY(&LCD1,0,0);
//		Lcd_VoidSendString(array,&LCD1);
//	}
//	counter_2=0;
//	Minutes1++;
//	if(Minutes1==60)
//	{
//		Minutes1=0;
//		array[3]='0';array[4]='0';
//
//	}
//}
//
//if(counter_3==125*3600)
//{
//	static u32 Hours1=1;
//	if(Hours1<10)
//	{
//
//		array[1]=48+Hours1;
//		Lcd_VoidGoXY(&LCD1,0,0);
//		Lcd_VoidSendString(array,&LCD1);
//	}
//	else if(Hours1>=10 && Hours1<24)
//	{
//		array[1]=48+Hours1%10;
//		array[0]=48+Hours1/10;
//		Lcd_VoidGoXY(&LCD1,0,0);
//		Lcd_VoidSendString(array,&LCD1);
//	}
//	counter_3=0;
//	Hours1++;
//	if(Hours1==24)
//	{
//		Hours1=0;
//		array[0]='0';array[1]='0';
//	}
//}*/
//
//#include "Bit_Math.h"
//#include "../MCAL/Timer/Timer_2/Timer2_Interface.h"
//#include "../MCAL/DIO/DIO_Interface.h"
//#include "../MCAL/ADC/ADC_Interface.h"
//#include "../HAL/LCD/LCD_Interface.h"
//#include <util/delay.h>
//
//#define Minutes_Place    3
//#define Seconds_Place    6
//#define First_line       0
//
//void CTC_Mode(void);
//
//
//Lcd_Info LCD1={DIO_GroupB,DIO_GroupB,DIO_GroupB,Pin2,Pin1,Pin0,DIO_GroupA};
//
//u8 array[10]={'0','0',':','0','0',':','0','0'};
//
//u8*ptr=array;
//
//void main ()
//{
//	//DIO_ErrStateSetPinDirection(DIO_GroupA,Pin0,DIO_Output);
//
//	Lcd_VoidInit(&LCD1);
//
//	//Lcd_VoidSendString(array,&LCD1);
//    TIMER2_voidInit();
//	OCR2_REG=250;
//
//	TIMER2_voidSetCallBachFn(&CTC_Mode);
//
//
//	while(1)
//	{
//
//	}
//}
//
//void CTC_Mode(void)
//{
//	static u32 counter_1,counter_2,counter_3;
//	counter_1++;
//	counter_2++;
//	counter_3++;
//
//	if(counter_1==1)
//	{
//		static u32 Seconds=1;
//		if(Seconds<10)
//		{
//			array[7]=48+Seconds;
//			Lcd_VoidGoXY(&LCD1,0,0);
//			Lcd_VoidSendString(array,&LCD1);
//
//		}
//		else if(Seconds>=10 && Seconds<60)
//		{
//			array[7]=48+(Seconds%10);
//			array[6]=48+(Seconds/10);
//			Lcd_VoidGoXY(&LCD1,0,0);
//			Lcd_VoidSendString(array,&LCD1);
//		}
//		counter_1=0;
//		Seconds++;
//		if(Seconds==60)
//		{
//			Seconds=0;
//		//	_delay_ms(1000);
//			array[6]='0';array[7]='0';
//		//	Lcd_VoidGoXY(&LCD1,0,0);
//			//Lcd_VoidSendString(array,&LCD1);
//		}
//	}
//	if(counter_2==1*60)
//	{
//		static u32 Minutes=1;
//		if(Minutes<10)
//		{
//			array[4]=48+Minutes;
//			Lcd_VoidGoXY(&LCD1,0,0);
//			Lcd_VoidSendString(array,&LCD1);
//		}
//		else if(Minutes>=10 && Minutes<60)
//		{
//			array[4]=48+(Minutes%10);
//			array[3]=48+(Minutes/10);
//			Lcd_VoidGoXY(&LCD1,0,0);
//			Lcd_VoidSendString(array,&LCD1);
//		}
//		counter_2=0;
//		Minutes++;
//		if(Minutes==60)
//		{
//			Minutes=0;
//		//	_delay_ms(1000);
//			array[3]='0';array[4]='0';
//		//	Lcd_VoidGoXY(&LCD1,0,0);
//		//	Lcd_VoidSendString(array,&LCD1);
//		}
//	}
//	if(counter_3==1*3600)
//	{
//		static u32 Hours=1;
//		if(Hours<10)
//		{
//			array[1]=48+Hours;
//			Lcd_VoidGoXY(&LCD1,0,0);
//			Lcd_VoidSendString(array,&LCD1);
//		}
//		else if(Hours>=10 && Hours<24)
//		{
//			array[1]=48+Hours%10;
//			array[0]=48+Hours/10;
//			Lcd_VoidGoXY(&LCD1,0,0);
//			Lcd_VoidSendString(array,&LCD1);
//		}
//		counter_3=0;
//		Hours++;
//		if(Hours==24)
//		{
//			Hours=0;
//		//	_delay_ms(1000);
//			array[0]='0';array[1]='0';
//		//	Lcd_VoidGoXY(&LCD1,0,0);
//		//	Lcd_VoidSendString(array,&LCD1);
//		}
//	}
//}
//
//
//
