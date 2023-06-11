/*
 * ADC.c
 *
 *  Created on: Jun 11, 2023
 *      Author: Muham
 */


#include "../MCAL/DIO/DIO_Interface.h"
#include "../MCAL/ADC/ADC_Interface.h"


void main()
{
	DIO_ErrStateSetGroupDirection(DIO_GroupA,DIO_Input);
	DIO_ErrStateSetGroupDirection(DIO_GroupC,DIO_Output);

	char ADC_Reading;

	ADC_voidInit();

	while(1)
	{
		ADC_Reading=ADC_u8GetChannelReading(1);
		DIO_ErrStateSetGroupValue(DIO_GroupC,ADC_Reading);
	}
}
