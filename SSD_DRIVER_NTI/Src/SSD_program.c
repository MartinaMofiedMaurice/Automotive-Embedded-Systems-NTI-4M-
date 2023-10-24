/********************************************************/
/******** Author      : Martina Mofied Maurice *********/
/******** Date        : 20/10/2023            *********/
/******** version     : V1.0                 *********/
/******** Description : SSD_Program         *********/
/***************************************************/

#include <util/delay.h>
#define F-CPU  8000000UL
#include "../Include/LIB/STD_TYPES.h"
#include "../Include/LIB/BIT_MATH.h"

#include "../Include/MCAL/DIO/DIO_Interface.h"
#include "../Include/MCAL/DIO/DIO_configuration.h"
#include "../Include/MCAL/DIO/DIO_private.h"

#include "../Include/HAL/SSD/SSD_Configuration.h"
#include "../Include/HAL/SSD/SSD_Interface.h"
#include "../Include/HAL/SSD/SSD_private.h"



void HSSD_voidDisplay(u8 A_u8number)
{switch(A_u8number)
{
case 0:
	MDIO_voidSetPortValue(SSD_PORT,ZERO);
	break;
case 1:
	MDIO_voidSetPortValue(SSD_PORT,ONE);
	break;
case 2:
	MDIO_voidSetPortValue(SSD_PORT,TWO);
	break;
case 3:
	MDIO_voidSetPortValue(SSD_PORT,THREE);
	break;
case 4:
	MDIO_voidSetPortValue(SSD_PORT,FOUR);
	break;
case 5:
	MDIO_voidSetPortValue(SSD_PORT,FIVE);
	break;
case 6:
	MDIO_voidSetPortValue(SSD_PORT,SIX);
	break;
case 7:
	MDIO_voidSetPortValue(SSD_PORT,SEVEN);
	break;
case 8:
	MDIO_voidSetPortValue(SSD_PORT,EIGHT);
	break;
case 9:
	MDIO_voidSetPortValue(SSD_PORT,NINE);
	break;
default:
	break;

}

}

void HSSD_voidDisplayByPort(u8 A_u8PortId,u8 A_u8number)
{switch(A_u8number)
{
case 0:
	MDIO_voidSetPortValue(A_u8PortId,ZERO);
	break;
case 1:
	MDIO_voidSetPortValue(A_u8PortId,ONE);
	break;
case 2:
	MDIO_voidSetPortValue(A_u8PortId,TWO);
	break;
case 3:
	MDIO_voidSetPortValue(A_u8PortId,THREE);
	break;
case 4:
	MDIO_voidSetPortValue(A_u8PortId,FOUR);
	break;
case 5:
	MDIO_voidSetPortValue(A_u8PortId,FIVE);
	break;
case 6:
	MDIO_voidSetPortValue(A_u8PortId,SIX);
	break;
case 7:
	MDIO_voidSetPortValue(A_u8PortId,SEVEN);
	break;
case 8:
	MDIO_voidSetPortValue(A_u8PortId,EIGHT);
	break;
case 9:
	MDIO_voidSetPortValue(A_u8PortId,NINE);
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
