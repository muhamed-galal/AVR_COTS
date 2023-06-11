/*
 * EXTmain.c
 *
 *  Created on: Apr 16, 2023
 *      Author: Muham
 */

#include "std_types.h"
#include "../MCAL/DIO/DIO_Interface.h"
#include "../MCAL/EXTI/EXTI_interface.h"
#include "../MCAL/GIE/GIE_interface.h"


void INT0_ISR(void);

void main(void)
{
	DIO_ErrStateSetPinDirection(DIO_GroupD,Pin2,DIO_Input);
	DIO_ErrStateSetPinValue(DIO_GroupD,Pin2,DIO_High);
	DIO_ErrStateSetPinDirection(DIO_GroupA,Pin0,DIO_Output);

	EXTI_voidInt0Init();
	EXTI_u8Int0SetCallBack(&INT0_ISR);
	GIEvoidEnable();
	while(1)
	{

	}

}

void INT0_ISR(void)
{
	DIO_ErrStateSetPinValue(DIO_GroupA,Pin0,DIO_High);
}
