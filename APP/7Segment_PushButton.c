/*
 * 7Segment_PushButton.c
 *
 *  Created on: Jun 12, 2023
 *      Author: Muham
 */


/*
 * main.c
 *
 *  Created on: Mar 23, 2023
 *      Author: Muham
 */

#include "defintion.h"
#include "std_types.h"
#include "../MCAL/DIO/DIO_Interface.h"



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
	u8 PushButton1;
	u8 PushButton2;
	u8 PushButton3;
	u8 Counter_up;
	u8 Counter_down;
	ErrState Res[10];

	/*Set PortC all Pins as Outputs*/
	Res[0]=DIO_ErrStateSetGroupDirection(DIO_GroupC,0xff);

	/*Set Group_A Pins 0,1,2 as inputs*/
	Res[1]=DIO_ErrStateSetPinDirection(DIO_GroupA,Pin0,DIO_Input);
	Res[2]=DIO_ErrStateSetPinDirection(DIO_GroupA,Pin1,DIO_Input);
	Res[3]=DIO_ErrStateSetPinDirection(DIO_GroupA,Pin2,DIO_Input);

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

		if (Res[1] == NoError && Res[2] == NoError && Res[3] == NoError )
		{
			Res[4]=DIO_ErrStateReadPinValue(DIO_GroupA,Pin0,&PushButton1); //Reading the value of PushButton 1 Pressed or Not
			Res[6]=DIO_ErrStateReadPinValue(DIO_GroupA,Pin2,&PushButton3);
			Res[5]=DIO_ErrStateReadPinValue(DIO_GroupA,Pin1,&PushButton2);

			if (Res[4] == NoError && Res[2] == NoError && Res[6] == NoError)
			{
				if (PushButton1 == Pressed )
				{
					for(Counter_up=0;Counter_up<10;Counter_up++)
					{
						DIO_ErrStateSetGroupValue(DIO_GroupC,SevSeg_Arr[Counter_up]);
						for(u32 check=0;check<100000;check++){}
						DIO_ErrStateReadPinValue(DIO_GroupA,Pin2,&PushButton3);
						if (PushButton3 == Pressed)
							break;
					}

				}
				else if (PushButton2 == Pressed)
				{
					for(int Counter_down=9;Counter_down>=0;Counter_down--)
					{
						DIO_ErrStateSetGroupValue(DIO_GroupC,SevSeg_Arr[Counter_down]);
						for(u32 check=0;check<100000;check++){}
						DIO_ErrStateReadPinValue(DIO_GroupA,Pin2,&PushButton3);
						if (PushButton3 == Pressed)
							break;
					}
				}

			}
		}
	}
}


