/********************************************************/
/******** Author      : Martina Mofied Maurice *********/
/******** Date        : 20/10/2023            *********/
/******** version     : V1.0                 *********/
/******** Description : SSD_Program         *********/
/***************************************************/


#include <util/delay.h>
#define F-CPU 12000000UL
#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_TYPES.h"

#include "../../MCAL/DIO/DIO_Interface.h"
#include "../../MCAL/DIO/DIO_configuration.h"
#include "../../MCAL/DIO/DIO_private.h"

#include "SSD_Configuration.h"
#include "SSD_private.h"
#include "SSD_Interface.h"



void HSSD_Init(u8 A_u8COM){
if(A_u8COM==COM1)
		{MDIO_voidSetPinValue(COM1_PORT,COM1,PIN_LOW);
		MDIO_voidSetPinValue(COM2_PORT,COM2,PIN_HIGH);
		MDIO_voidSetPinValue(COM3_PORT,COM3,PIN_HIGH);
		MDIO_voidSetPinValue(COM4_PORT,COM4,PIN_HIGH);}

else if(A_u8COM==COM2)
{	MDIO_voidSetPinValue(COM1_PORT,COM1,PIN_HIGH);
		MDIO_voidSetPinValue(COM2_PORT,COM2,PIN_LOW);
		MDIO_voidSetPinValue(COM3_PORT,COM3,PIN_HIGH);
		MDIO_voidSetPinValue(COM4_PORT,COM4,PIN_HIGH);}

else if(A_u8COM==COM3)
		{MDIO_voidSetPinValue(COM1_PORT,COM1,PIN_HIGH);
		MDIO_voidSetPinValue(COM2_PORT,COM2,PIN_HIGH);
		MDIO_voidSetPinValue(COM3_PORT,COM3,PIN_LOW);
		MDIO_voidSetPinValue(COM4_PORT,COM4,PIN_HIGH);}
else if(A_u8COM==COM4)
	{MDIO_voidSetPinValue(COM1_PORT,COM1,PIN_HIGH);
		MDIO_voidSetPinValue(COM2_PORT,COM2,PIN_HIGH);
		MDIO_voidSetPinValue(COM3_PORT,COM3,PIN_HIGH);
		MDIO_voidSetPinValue(COM4_PORT,COM4,PIN_LOW);}



}
void HSSD_voidDisplay(u8 A_u8number)
{switch(A_u8number)
{
case 0:
	MDIO_voidSetPinValue(BCD_PORT,PIN0,PIN_LOW);
	MDIO_voidSetPinValue(BCD_PORT,PIN1,PIN_LOW);
	MDIO_voidSetPinValue(BCD_PORT,PIN2,PIN_LOW);
	MDIO_voidSetPinValue(BCD_PORT,PIN4,PIN_LOW);
	break;
case 1:
	MDIO_voidSetPinValue(BCD_PORT,PIN0,PIN_HIGH);
	MDIO_voidSetPinValue(BCD_PORT,PIN1,PIN_LOW);
	MDIO_voidSetPinValue(BCD_PORT,PIN2,PIN_LOW);
	MDIO_voidSetPinValue(BCD_PORT,PIN4,PIN_LOW);
	break;
case 2:
	MDIO_voidSetPinValue(BCD_PORT,PIN0,PIN_LOW);
	MDIO_voidSetPinValue(BCD_PORT,PIN1,PIN_HIGH);
	MDIO_voidSetPinValue(BCD_PORT,PIN2,PIN_LOW);
	MDIO_voidSetPinValue(BCD_PORT,PIN4,PIN_LOW);
	break;
case 3:
	MDIO_voidSetPinValue(BCD_PORT,PIN0,PIN_HIGH);
	MDIO_voidSetPinValue(BCD_PORT,PIN1,PIN_HIGH);
	MDIO_voidSetPinValue(BCD_PORT,PIN2,PIN_LOW);
	MDIO_voidSetPinValue(BCD_PORT,PIN4,PIN_LOW);
	break;
case 4:
	MDIO_voidSetPinValue(BCD_PORT,PIN0,PIN_LOW);
	MDIO_voidSetPinValue(BCD_PORT,PIN1,PIN_LOW);
	MDIO_voidSetPinValue(BCD_PORT,PIN2,PIN_HIGH);
	MDIO_voidSetPinValue(BCD_PORT,PIN4,PIN_LOW);
	break;
case 5:
	MDIO_voidSetPinValue(BCD_PORT,PIN0,PIN_HIGH);
	MDIO_voidSetPinValue(BCD_PORT,PIN1,PIN_LOW);
	MDIO_voidSetPinValue(BCD_PORT,PIN2,PIN_HIGH);
	MDIO_voidSetPinValue(BCD_PORT,PIN4,PIN_LOW);
	break;
case 6:
	MDIO_voidSetPinValue(BCD_PORT,PIN0,PIN_LOW);
	MDIO_voidSetPinValue(BCD_PORT,PIN1,PIN_HIGH);
	MDIO_voidSetPinValue(BCD_PORT,PIN2,PIN_HIGH);
	MDIO_voidSetPinValue(BCD_PORT,PIN4,PIN_LOW);
	break;
case 7:
	MDIO_voidSetPinValue(BCD_PORT,PIN0,PIN_HIGH);
	MDIO_voidSetPinValue(BCD_PORT,PIN1,PIN_HIGH);
	MDIO_voidSetPinValue(BCD_PORT,PIN2,PIN_HIGH);
	MDIO_voidSetPinValue(BCD_PORT,PIN4,PIN_LOW);
	break;
case 8:
	MDIO_voidSetPinValue(BCD_PORT,PIN0,PIN_LOW);
	MDIO_voidSetPinValue(BCD_PORT,PIN1,PIN_LOW);
	MDIO_voidSetPinValue(BCD_PORT,PIN2,PIN_LOW);
	MDIO_voidSetPinValue(BCD_PORT,PIN4,PIN_HIGH);
	break;
case 9:
	MDIO_voidSetPinValue(BCD_PORT,PIN0,PIN_HIGH);
	MDIO_voidSetPinValue(BCD_PORT,PIN1,PIN_LOW);
	MDIO_voidSetPinValue(BCD_PORT,PIN2,PIN_LOW);
	MDIO_voidSetPinValue(BCD_PORT,PIN4,PIN_HIGH);
	break;
default:
	break;

}

}
void HSSD_voidDisplayNumberByCom(u8 A_u8number,u8 A_u8COM){
	switch(A_u8COM){
	case COM1:
		MDIO_voidSetPinValue(COM1_PORT,COM1,PIN_LOW);
		MDIO_voidSetPinValue(COM2_PORT,COM2,PIN_HIGH);
		MDIO_voidSetPinValue(COM3_PORT,COM3,PIN_HIGH);
		MDIO_voidSetPinValue(COM4_PORT,COM4,PIN_HIGH);
		switch(A_u8number)
		{
		case 0:
			MDIO_voidSetPinValue(BCD_PORT,PIN0,PIN_LOW);
			MDIO_voidSetPinValue(BCD_PORT,PIN1,PIN_LOW);
			MDIO_voidSetPinValue(BCD_PORT,PIN2,PIN_LOW);
			MDIO_voidSetPinValue(BCD_PORT,PIN4,PIN_LOW);
			break;
		case 1:
			MDIO_voidSetPinValue(BCD_PORT,PIN0,PIN_HIGH);
			MDIO_voidSetPinValue(BCD_PORT,PIN1,PIN_LOW);
			MDIO_voidSetPinValue(BCD_PORT,PIN2,PIN_LOW);
			MDIO_voidSetPinValue(BCD_PORT,PIN4,PIN_LOW);
			break;
		case 2:
			MDIO_voidSetPinValue(BCD_PORT,PIN0,PIN_LOW);
			MDIO_voidSetPinValue(BCD_PORT,PIN1,PIN_HIGH);
			MDIO_voidSetPinValue(BCD_PORT,PIN2,PIN_LOW);
			MDIO_voidSetPinValue(BCD_PORT,PIN4,PIN_LOW);
			break;
		case 3:
			MDIO_voidSetPinValue(BCD_PORT,PIN0,PIN_HIGH);
			MDIO_voidSetPinValue(BCD_PORT,PIN1,PIN_HIGH);
			MDIO_voidSetPinValue(BCD_PORT,PIN2,PIN_LOW);
			MDIO_voidSetPinValue(BCD_PORT,PIN4,PIN_LOW);
			break;
		case 4:
			MDIO_voidSetPinValue(BCD_PORT,PIN0,PIN_LOW);
			MDIO_voidSetPinValue(BCD_PORT,PIN1,PIN_LOW);
			MDIO_voidSetPinValue(BCD_PORT,PIN2,PIN_HIGH);
			MDIO_voidSetPinValue(BCD_PORT,PIN4,PIN_LOW);
			break;
		case 5:
			MDIO_voidSetPinValue(BCD_PORT,PIN0,PIN_HIGH);
			MDIO_voidSetPinValue(BCD_PORT,PIN1,PIN_LOW);
			MDIO_voidSetPinValue(BCD_PORT,PIN2,PIN_HIGH);
			MDIO_voidSetPinValue(BCD_PORT,PIN4,PIN_LOW);
			break;
		case 6:
			MDIO_voidSetPinValue(BCD_PORT,PIN0,PIN_LOW);
			MDIO_voidSetPinValue(BCD_PORT,PIN1,PIN_HIGH);
			MDIO_voidSetPinValue(BCD_PORT,PIN2,PIN_HIGH);
			MDIO_voidSetPinValue(BCD_PORT,PIN4,PIN_LOW);
			break;
		case 7:
			MDIO_voidSetPinValue(BCD_PORT,PIN0,PIN_HIGH);
			MDIO_voidSetPinValue(BCD_PORT,PIN1,PIN_HIGH);
			MDIO_voidSetPinValue(BCD_PORT,PIN2,PIN_HIGH);
			MDIO_voidSetPinValue(BCD_PORT,PIN4,PIN_LOW);
			break;
		case 8:
			MDIO_voidSetPinValue(BCD_PORT,PIN0,PIN_LOW);
			MDIO_voidSetPinValue(BCD_PORT,PIN1,PIN_LOW);
			MDIO_voidSetPinValue(BCD_PORT,PIN2,PIN_LOW);
			MDIO_voidSetPinValue(BCD_PORT,PIN4,PIN_HIGH);
			break;
		case 9:
			MDIO_voidSetPinValue(BCD_PORT,PIN0,PIN_HIGH);
			MDIO_voidSetPinValue(BCD_PORT,PIN1,PIN_LOW);
			MDIO_voidSetPinValue(BCD_PORT,PIN2,PIN_LOW);
			MDIO_voidSetPinValue(BCD_PORT,PIN4,PIN_HIGH);
			break;
		default:
			break;

		}


		break;
	case COM2:
		MDIO_voidSetPinValue(COM1_PORT,COM1,PIN_HIGH);
		MDIO_voidSetPinValue(COM2_PORT,COM2,PIN_LOW);
		MDIO_voidSetPinValue(COM3_PORT,COM3,PIN_HIGH);
		MDIO_voidSetPinValue(COM4_PORT,COM4,PIN_HIGH);
		switch(A_u8number)
		{
		case 0:
			MDIO_voidSetPinValue(BCD_PORT,PIN0,PIN_LOW);
			MDIO_voidSetPinValue(BCD_PORT,PIN1,PIN_LOW);
			MDIO_voidSetPinValue(BCD_PORT,PIN2,PIN_LOW);
			MDIO_voidSetPinValue(BCD_PORT,PIN4,PIN_LOW);
			break;
		case 1:
			MDIO_voidSetPinValue(BCD_PORT,PIN0,PIN_HIGH);
			MDIO_voidSetPinValue(BCD_PORT,PIN1,PIN_LOW);
			MDIO_voidSetPinValue(BCD_PORT,PIN2,PIN_LOW);
			MDIO_voidSetPinValue(BCD_PORT,PIN4,PIN_LOW);
			break;
		case 2:
			MDIO_voidSetPinValue(BCD_PORT,PIN0,PIN_LOW);
			MDIO_voidSetPinValue(BCD_PORT,PIN1,PIN_HIGH);
			MDIO_voidSetPinValue(BCD_PORT,PIN2,PIN_LOW);
			MDIO_voidSetPinValue(BCD_PORT,PIN4,PIN_LOW);
			break;
		case 3:
			MDIO_voidSetPinValue(BCD_PORT,PIN0,PIN_HIGH);
			MDIO_voidSetPinValue(BCD_PORT,PIN1,PIN_HIGH);
			MDIO_voidSetPinValue(BCD_PORT,PIN2,PIN_LOW);
			MDIO_voidSetPinValue(BCD_PORT,PIN4,PIN_LOW);
			break;
		case 4:
			MDIO_voidSetPinValue(BCD_PORT,PIN0,PIN_LOW);
			MDIO_voidSetPinValue(BCD_PORT,PIN1,PIN_LOW);
			MDIO_voidSetPinValue(BCD_PORT,PIN2,PIN_HIGH);
			MDIO_voidSetPinValue(BCD_PORT,PIN4,PIN_LOW);
			break;
		case 5:
			MDIO_voidSetPinValue(BCD_PORT,PIN0,PIN_HIGH);
			MDIO_voidSetPinValue(BCD_PORT,PIN1,PIN_LOW);
			MDIO_voidSetPinValue(BCD_PORT,PIN2,PIN_HIGH);
			MDIO_voidSetPinValue(BCD_PORT,PIN4,PIN_LOW);
			break;
		case 6:
			MDIO_voidSetPinValue(BCD_PORT,PIN0,PIN_LOW);
			MDIO_voidSetPinValue(BCD_PORT,PIN1,PIN_HIGH);
			MDIO_voidSetPinValue(BCD_PORT,PIN2,PIN_HIGH);
			MDIO_voidSetPinValue(BCD_PORT,PIN4,PIN_LOW);
			break;
		case 7:
			MDIO_voidSetPinValue(BCD_PORT,PIN0,PIN_HIGH);
			MDIO_voidSetPinValue(BCD_PORT,PIN1,PIN_HIGH);
			MDIO_voidSetPinValue(BCD_PORT,PIN2,PIN_HIGH);
			MDIO_voidSetPinValue(BCD_PORT,PIN4,PIN_LOW);
			break;
		case 8:
			MDIO_voidSetPinValue(BCD_PORT,PIN0,PIN_LOW);
			MDIO_voidSetPinValue(BCD_PORT,PIN1,PIN_LOW);
			MDIO_voidSetPinValue(BCD_PORT,PIN2,PIN_LOW);
			MDIO_voidSetPinValue(BCD_PORT,PIN4,PIN_HIGH);
			break;
		case 9:
			MDIO_voidSetPinValue(BCD_PORT,PIN0,PIN_HIGH);
			MDIO_voidSetPinValue(BCD_PORT,PIN1,PIN_LOW);
			MDIO_voidSetPinValue(BCD_PORT,PIN2,PIN_LOW);
			MDIO_voidSetPinValue(BCD_PORT,PIN4,PIN_HIGH);
			break;
		default:
			break;

		}


			break;
	case COM3:
		MDIO_voidSetPinValue(COM1_PORT,COM1,PIN_HIGH);
		MDIO_voidSetPinValue(COM2_PORT,COM2,PIN_HIGH);
		MDIO_voidSetPinValue(COM3_PORT,COM3,PIN_LOW);
		MDIO_voidSetPinValue(COM4_PORT,COM4,PIN_HIGH);
		switch(A_u8number)
		{
		case 0:
			MDIO_voidSetPinValue(BCD_PORT,PIN0,PIN_LOW);
			MDIO_voidSetPinValue(BCD_PORT,PIN1,PIN_LOW);
			MDIO_voidSetPinValue(BCD_PORT,PIN2,PIN_LOW);
			MDIO_voidSetPinValue(BCD_PORT,PIN4,PIN_LOW);
			break;
		case 1:
			MDIO_voidSetPinValue(BCD_PORT,PIN0,PIN_HIGH);
			MDIO_voidSetPinValue(BCD_PORT,PIN1,PIN_LOW);
			MDIO_voidSetPinValue(BCD_PORT,PIN2,PIN_LOW);
			MDIO_voidSetPinValue(BCD_PORT,PIN4,PIN_LOW);
			break;
		case 2:
			MDIO_voidSetPinValue(BCD_PORT,PIN0,PIN_LOW);
			MDIO_voidSetPinValue(BCD_PORT,PIN1,PIN_HIGH);
			MDIO_voidSetPinValue(BCD_PORT,PIN2,PIN_LOW);
			MDIO_voidSetPinValue(BCD_PORT,PIN4,PIN_LOW);
			break;
		case 3:
			MDIO_voidSetPinValue(BCD_PORT,PIN0,PIN_HIGH);
			MDIO_voidSetPinValue(BCD_PORT,PIN1,PIN_HIGH);
			MDIO_voidSetPinValue(BCD_PORT,PIN2,PIN_LOW);
			MDIO_voidSetPinValue(BCD_PORT,PIN4,PIN_LOW);
			break;
		case 4:
			MDIO_voidSetPinValue(BCD_PORT,PIN0,PIN_LOW);
			MDIO_voidSetPinValue(BCD_PORT,PIN1,PIN_LOW);
			MDIO_voidSetPinValue(BCD_PORT,PIN2,PIN_HIGH);
			MDIO_voidSetPinValue(BCD_PORT,PIN4,PIN_LOW);
			break;
		case 5:
			MDIO_voidSetPinValue(BCD_PORT,PIN0,PIN_HIGH);
			MDIO_voidSetPinValue(BCD_PORT,PIN1,PIN_LOW);
			MDIO_voidSetPinValue(BCD_PORT,PIN2,PIN_HIGH);
			MDIO_voidSetPinValue(BCD_PORT,PIN4,PIN_LOW);
			break;
		case 6:
			MDIO_voidSetPinValue(BCD_PORT,PIN0,PIN_LOW);
			MDIO_voidSetPinValue(BCD_PORT,PIN1,PIN_HIGH);
			MDIO_voidSetPinValue(BCD_PORT,PIN2,PIN_HIGH);
			MDIO_voidSetPinValue(BCD_PORT,PIN4,PIN_LOW);
			break;
		case 7:
			MDIO_voidSetPinValue(BCD_PORT,PIN0,PIN_HIGH);
			MDIO_voidSetPinValue(BCD_PORT,PIN1,PIN_HIGH);
			MDIO_voidSetPinValue(BCD_PORT,PIN2,PIN_HIGH);
			MDIO_voidSetPinValue(BCD_PORT,PIN4,PIN_LOW);
			break;
		case 8:
			MDIO_voidSetPinValue(BCD_PORT,PIN0,PIN_LOW);
			MDIO_voidSetPinValue(BCD_PORT,PIN1,PIN_LOW);
			MDIO_voidSetPinValue(BCD_PORT,PIN2,PIN_LOW);
			MDIO_voidSetPinValue(BCD_PORT,PIN4,PIN_HIGH);
			break;
		case 9:
			MDIO_voidSetPinValue(BCD_PORT,PIN0,PIN_HIGH);
			MDIO_voidSetPinValue(BCD_PORT,PIN1,PIN_LOW);
			MDIO_voidSetPinValue(BCD_PORT,PIN2,PIN_LOW);
			MDIO_voidSetPinValue(BCD_PORT,PIN4,PIN_HIGH);
			break;
		default:
			break;

		}


			break;
	case COM4:
		MDIO_voidSetPinValue(COM1_PORT,COM1,PIN_HIGH);
		MDIO_voidSetPinValue(COM2_PORT,COM2,PIN_HIGH);
		MDIO_voidSetPinValue(COM3_PORT,COM3,PIN_HIGH);
		MDIO_voidSetPinValue(COM4_PORT,COM4,PIN_LOW);
		switch(A_u8number)
		{
		case 0:
			MDIO_voidSetPinValue(BCD_PORT,PIN0,PIN_LOW);
			MDIO_voidSetPinValue(BCD_PORT,PIN1,PIN_LOW);
			MDIO_voidSetPinValue(BCD_PORT,PIN2,PIN_LOW);
			MDIO_voidSetPinValue(BCD_PORT,PIN4,PIN_LOW);
			break;
		case 1:
			MDIO_voidSetPinValue(BCD_PORT,PIN0,PIN_HIGH);
			MDIO_voidSetPinValue(BCD_PORT,PIN1,PIN_LOW);
			MDIO_voidSetPinValue(BCD_PORT,PIN2,PIN_LOW);
			MDIO_voidSetPinValue(BCD_PORT,PIN4,PIN_LOW);
			break;
		case 2:
			MDIO_voidSetPinValue(BCD_PORT,PIN0,PIN_LOW);
			MDIO_voidSetPinValue(BCD_PORT,PIN1,PIN_HIGH);
			MDIO_voidSetPinValue(BCD_PORT,PIN2,PIN_LOW);
			MDIO_voidSetPinValue(BCD_PORT,PIN4,PIN_LOW);
			break;
		case 3:
			MDIO_voidSetPinValue(BCD_PORT,PIN0,PIN_HIGH);
			MDIO_voidSetPinValue(BCD_PORT,PIN1,PIN_HIGH);
			MDIO_voidSetPinValue(BCD_PORT,PIN2,PIN_LOW);
			MDIO_voidSetPinValue(BCD_PORT,PIN4,PIN_LOW);
			break;
		case 4:
			MDIO_voidSetPinValue(BCD_PORT,PIN0,PIN_LOW);
			MDIO_voidSetPinValue(BCD_PORT,PIN1,PIN_LOW);
			MDIO_voidSetPinValue(BCD_PORT,PIN2,PIN_HIGH);
			MDIO_voidSetPinValue(BCD_PORT,PIN4,PIN_LOW);
			break;
		case 5:
			MDIO_voidSetPinValue(BCD_PORT,PIN0,PIN_HIGH);
			MDIO_voidSetPinValue(BCD_PORT,PIN1,PIN_LOW);
			MDIO_voidSetPinValue(BCD_PORT,PIN2,PIN_HIGH);
			MDIO_voidSetPinValue(BCD_PORT,PIN4,PIN_LOW);
			break;
		case 6:
			MDIO_voidSetPinValue(BCD_PORT,PIN0,PIN_LOW);
			MDIO_voidSetPinValue(BCD_PORT,PIN1,PIN_HIGH);
			MDIO_voidSetPinValue(BCD_PORT,PIN2,PIN_HIGH);
			MDIO_voidSetPinValue(BCD_PORT,PIN4,PIN_LOW);
			break;
		case 7:
			MDIO_voidSetPinValue(BCD_PORT,PIN0,PIN_HIGH);
			MDIO_voidSetPinValue(BCD_PORT,PIN1,PIN_HIGH);
			MDIO_voidSetPinValue(BCD_PORT,PIN2,PIN_HIGH);
			MDIO_voidSetPinValue(BCD_PORT,PIN4,PIN_LOW);
			break;
		case 8:
			MDIO_voidSetPinValue(BCD_PORT,PIN0,PIN_LOW);
			MDIO_voidSetPinValue(BCD_PORT,PIN1,PIN_LOW);
			MDIO_voidSetPinValue(BCD_PORT,PIN2,PIN_LOW);
			MDIO_voidSetPinValue(BCD_PORT,PIN4,PIN_HIGH);
			break;
		case 9:
			MDIO_voidSetPinValue(BCD_PORT,PIN0,PIN_HIGH);
			MDIO_voidSetPinValue(BCD_PORT,PIN1,PIN_LOW);
			MDIO_voidSetPinValue(BCD_PORT,PIN2,PIN_LOW);
			MDIO_voidSetPinValue(BCD_PORT,PIN4,PIN_HIGH);
			break;
		default:
			break;

		}


			break;
	default:
		break;
	}
}

void HSSD_voidDisplayAscending(void)
{
u8 local_u8ArrOfNumbers[10]={ZERO,ONE,TWO,THREE,FOUR,FIVE,SIX,SEVEN,EIGHT,NINE};
for(u8 i=0;i<10;i++)
{
	HSSD_voidDisplay(local_u8ArrOfNumbers[i]);
	_delay_ms(SSD_DELAY_TIME);

}
}

void HSSD_voidDisplayDescending(void)
{
u8 local_u8ArrOfNumbers[10]={ZERO,ONE,TWO,THREE,FOUR,FIVE,SIX,SEVEN,EIGHT,NINE};
for(u8 i=9;i>=0;i--)
{
	HSSD_voidDisplay(local_u8ArrOfNumbers[i]);
	_delay_ms(SSD_DELAY_TIME);

}
}

void HSSD_TurnOff(u8 A_u8COM){
	if(A_u8COM==COM1)
			{MDIO_voidSetPinValue(COM1_PORT,COM1,PIN_HIGH);
			MDIO_voidSetPinValue(COM2_PORT,COM2,PIN_HIGH);
			MDIO_voidSetPinValue(COM3_PORT,COM3,PIN_HIGH);
			MDIO_voidSetPinValue(COM4_PORT,COM4,PIN_HIGH);}

	else if(A_u8COM==COM2)
	{	MDIO_voidSetPinValue(COM1_PORT,COM1,PIN_HIGH);
			MDIO_voidSetPinValue(COM2_PORT,COM2,PIN_HIGH);
			MDIO_voidSetPinValue(COM3_PORT,COM3,PIN_HIGH);
			MDIO_voidSetPinValue(COM4_PORT,COM4,PIN_HIGH);}

	else if(A_u8COM==COM3)
			{MDIO_voidSetPinValue(COM1_PORT,COM1,PIN_HIGH);
			MDIO_voidSetPinValue(COM2_PORT,COM2,PIN_HIGH);
			MDIO_voidSetPinValue(COM3_PORT,COM3,PIN_HIGH);
			MDIO_voidSetPinValue(COM4_PORT,COM4,PIN_HIGH);}
	else if(A_u8COM==COM4)
		{MDIO_voidSetPinValue(COM1_PORT,COM1,PIN_HIGH);
			MDIO_voidSetPinValue(COM2_PORT,COM2,PIN_HIGH);
			MDIO_voidSetPinValue(COM3_PORT,COM3,PIN_HIGH);
			MDIO_voidSetPinValue(COM4_PORT,COM4,PIN_HIGH);}

}
