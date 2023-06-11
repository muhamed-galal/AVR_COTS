/*
 * SevenSegment.c
 *
 *  Created on: Jun 11, 2023
 *      Author: Muham
 */


#include "../Common/defintion.h"
#include "../Common/std_types.h"
#include "../MCAL/DIO/DIO_Interface.h"
#include "util/delay.h"

#define SevenSeg_0 0x3F
#define SevenSeg_1 0x06
#define SevenSeg_2 0x5B
#define SevenSeg_3 0x4F
#define SevenSeg_4 0x66
#define SevenSeg_5 0x6D
#define SevenSeg_6 0x7D
#define SevenSeg_7 0x07
#define SevenSeg_8 0x7F
#define SevenSeg_9 0x6F
#define SevenSegArrSize 10


void main()
{

	u8 Counter_up;

	ErrState Res[5];
	/*Set PortC all Pins as Outputs*/
	Res[0]=DIO_ErrStateSetGroupDirection(DIO_GroupC,0xff);
	/*Set Group_D Pins 0,1 as Outputs*/
	Res[1]=DIO_ErrStateSetPinDirection(DIO_GroupD,Pin0,DIO_Output);
	Res[2]=DIO_ErrStateSetPinDirection(DIO_GroupD,Pin1,DIO_Output);



	/*Define The Seven Segment Elements to Array and using The Array Elements in for_loop*/
	u8 SevSeg_Arr[SevenSegArrSize]=
	{SevenSeg_0 ,
			SevenSeg_1 ,
			SevenSeg_2 ,
			SevenSeg_3 ,
			SevenSeg_4 ,
			SevenSeg_5 ,
			SevenSeg_6 ,
			SevenSeg_7 ,
			SevenSeg_8 ,
			SevenSeg_9 ,
	};

	while(1)
	{
		if(Res[0] == NoError)
		{
			for(Counter_up=0;Counter_up<100;Counter_up++)
			{

				for(u16 i=0;i<50;i++)
				{

				DIO_ErrStateSetPinValue(DIO_GroupD,Pin0,DIO_High);
				DIO_ErrStateSetPinValue(DIO_GroupD,Pin1,DIO_Low);

				DIO_ErrStateSetGroupValue(DIO_GroupC ,SevSeg_Arr[Counter_up % 10] );
				_delay_ms(10);

				DIO_ErrStateSetPinValue(DIO_GroupD,Pin1,DIO_High);
				DIO_ErrStateSetPinValue(DIO_GroupD,Pin0,DIO_Low);

				DIO_ErrStateSetGroupValue(DIO_GroupC ,SevSeg_Arr[Counter_up / 10] );
				_delay_ms(10);

				}

			}
		}
	}
}



