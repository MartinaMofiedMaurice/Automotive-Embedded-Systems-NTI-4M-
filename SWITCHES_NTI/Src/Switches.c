/********************************************************/
/******** Author      : Martina Mofied Maurice *********/
/******** Date        : 20/10/2023            *********/
/******** version     : V1.0                 *********/
/******** Description : Switches_APP        *********/
/***************************************************/
#include "../Include/LIB/STD_TYPES.h"
#include "../Include/LIB/BIT_MATH.h"
#include "../Include/MCAL/DIO/DIO_Interface.h"
#include "../Include/MCAL/DIO/DIO_configuration.h"
#include "../Include/MCAL/DIO/DIO_private.h"
#include <util/delay.h>
#define F_CPU 8000000UL

void main(void){
	MDIO_voidInit();
	MDIO_voidSetPinDirection(PORTA,PIN0,PIN_INPUT);
	MDIO_voidSetPinValue(PORTA,PIN0,PIN_PULLUP);
	u8 Local_u8PinValue=0;
	while(1){
		Local_u8PinValue=MDIO_u8GetPinValue(PORTA,PIN0);
		if(Local_u8PinValue==1){
			MDIO_voidSetPinValue(PORTA,PIN1,PIN_HIGH);
		}
		else{
			MDIO_voidSetPinValue(PORTA,PIN1,PIN_LOW);
		}
	}
}
