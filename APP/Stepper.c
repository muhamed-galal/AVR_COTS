/*
 * Stepper.c
 *
 *  Created on: Jun 11, 2023
 *      Author: Muham
 */

#include "../MCAL/DIO/DIO_Interface.h"
#include "util/delay.h"
#include "../HAL/Stepper_Motor/Stepper_Interface.h"

void main ()
{

Stper_info Stepper1 = {DIO_GroupC,Pin0,Pin1,Pin2,Pin3,8,CW};

	Stepper_StErrStateInit(&Stepper1);
	Stepper_StErrStateControlMotorRotate(&Stepper1,60);


//motor control directions with proteus

DIO_ErrStateSetPinDirection(DIO_GroupA ,Pin0 ,DIO_Output);
DIO_ErrStateSetPinDirection(DIO_GroupA ,Pin1 ,DIO_Output);
DIO_ErrStateSetPinDirection(DIO_GroupA ,Pin2 ,DIO_Output);
DIO_ErrStateSetPinDirection(DIO_GroupA ,Pin3 ,DIO_Output);
while(1)
{
	for(int i=0;i<5;i++)
	{
		DIO_ErrStateSetPinValue(DIO_GroupA,Pin0,DIO_High);
		DIO_ErrStateSetPinValue(DIO_GroupA,Pin1,DIO_Low);
		DIO_ErrStateSetPinValue(DIO_GroupA,Pin2,DIO_Low);
		DIO_ErrStateSetPinValue(DIO_GroupA,Pin3,DIO_High);

		_delay_ms(1000);
	}

	for(int i=0;i<5;i++)
	{
		DIO_ErrStateSetPinValue(DIO_GroupA,Pin0,DIO_Low);
		DIO_ErrStateSetPinValue(DIO_GroupA,Pin1,DIO_High);
		DIO_ErrStateSetPinValue(DIO_GroupA,Pin2,DIO_High);
		DIO_ErrStateSetPinValue(DIO_GroupA,Pin3,DIO_Low);
		_delay_ms(1000);
	}

}
}
