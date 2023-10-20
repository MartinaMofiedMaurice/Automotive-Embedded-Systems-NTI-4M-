/********************************************************/
/******** Author      : Martina Mofied Maurice *********/
/******** Date        : 20/10/2023            *********/
/******** version     : V1.0                 *********/
/******** Description : DIO_APP             *********/
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
	while(1){
	 MDIO_voidSetPinValue(PORTA,PIN0,PIN_HIGH);
	 MDIO_voidSetPinValue(PORTA,PIN1,PIN_LOW);
	 MDIO_voidSetPinValue(PORTA,PIN2,PIN_LOW);
	 MDIO_voidSetPinValue(PORTA,PIN3,PIN_LOW);
	 _delay_ms(1000);
	 MDIO_voidSetPinValue(PORTA,PIN0,PIN_LOW);
	 MDIO_voidSetPinValue(PORTA,PIN1,PIN_HIGH);
	 MDIO_voidSetPinValue(PORTA,PIN2,PIN_LOW);
	 MDIO_voidSetPinValue(PORTA,PIN3,PIN_LOW);
	 _delay_ms(1000);
	 MDIO_voidSetPinValue(PORTA,PIN0,PIN_LOW);
	 MDIO_voidSetPinValue(PORTA,PIN1,PIN_LOW);
	 MDIO_voidSetPinValue(PORTA,PIN2,PIN_HIGH);
	 MDIO_voidSetPinValue(PORTA,PIN3,PIN_LOW);
	 _delay_ms(1000);
	 MDIO_voidSetPinValue(PORTA,PIN0,PIN_LOW);
	 MDIO_voidSetPinValue(PORTA,PIN1,PIN_LOW);
	 MDIO_voidSetPinValue(PORTA,PIN2,PIN_LOW);
	 MDIO_voidSetPinValue(PORTA,PIN3,PIN_HIGH);
	 _delay_ms(1000);
	}
}
