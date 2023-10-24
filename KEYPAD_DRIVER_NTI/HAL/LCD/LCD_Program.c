/********************************************************/
/******** Author      : Martina Mofied Maurice *********/
/******** Date        : 21/10/2023            *********/
/******** version     : V1.0                 *********/
/******** Description : LCD_Program         *********/
/***************************************************/

#include <util/delay.h>
#define F-CPU 12000000UL
#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_TYPES.h"

#include "../../MCAL/DIO/DIO_Interface.h"
#include "../../MCAL/DIO/DIO_configuration.h"
#include "../../MCAL/DIO/DIO_private.h"

#include "LCD_Configurations.h"
#include "LCD_Interface.h"
#include "LCD_Private.h"


void HLCD_voidSendCommand(u8 A_u8Command){

		MDIO_voidSetPinValue(LCD_DATA_PORT, LCD_D4_PIN, GET_BIT(A_u8Command,4));
		MDIO_voidSetPinValue(LCD_DATA_PORT, LCD_D5_PIN, GET_BIT(A_u8Command,5));
		MDIO_voidSetPinValue(LCD_DATA_PORT, LCD_D6_PIN, GET_BIT(A_u8Command,6));
		MDIO_voidSetPinValue(LCD_DATA_PORT, LCD_D7_PIN, GET_BIT(A_u8Command,7));

		MDIO_voidSetPinValue(LCD_CONTROL_PORT,LCD_RS_PIN,PIN_LOW);
		_delay_ms(1);

		MDIO_voidSetPinValue(LCD_CONTROL_PORT,LCD_EN_PIN,PIN_HIGH);
		_delay_ms(1);

		MDIO_voidSetPinValue(LCD_CONTROL_PORT,LCD_EN_PIN,PIN_LOW);
		_delay_ms(1);


		MDIO_voidSetPinValue(LCD_DATA_PORT, LCD_D4_PIN, GET_BIT(A_u8Command,0));
		MDIO_voidSetPinValue(LCD_DATA_PORT, LCD_D5_PIN, GET_BIT(A_u8Command,1));
		MDIO_voidSetPinValue(LCD_DATA_PORT, LCD_D6_PIN, GET_BIT(A_u8Command,2));
		MDIO_voidSetPinValue(LCD_DATA_PORT, LCD_D7_PIN, GET_BIT(A_u8Command,3));


		MDIO_voidSetPinValue(LCD_CONTROL_PORT,LCD_EN_PIN,PIN_HIGH);
		_delay_ms(1);

		MDIO_voidSetPinValue(LCD_CONTROL_PORT,LCD_EN_PIN,PIN_LOW);
		_delay_ms(1);


}

void HLCD_voidSendData(u8 A_u8Data){

		MDIO_voidSetPinValue(LCD_DATA_PORT, LCD_D4_PIN, GET_BIT(A_u8Data,4));
		MDIO_voidSetPinValue(LCD_DATA_PORT, LCD_D5_PIN, GET_BIT(A_u8Data,5));
		MDIO_voidSetPinValue(LCD_DATA_PORT, LCD_D6_PIN, GET_BIT(A_u8Data,6));
		MDIO_voidSetPinValue(LCD_DATA_PORT, LCD_D7_PIN, GET_BIT(A_u8Data,7));

		MDIO_voidSetPinValue(LCD_CONTROL_PORT,LCD_RS_PIN,PIN_HIGH);
		_delay_ms(1);

		MDIO_voidSetPinValue(LCD_CONTROL_PORT,LCD_EN_PIN,PIN_HIGH);
		_delay_ms(1);

		MDIO_voidSetPinValue(LCD_CONTROL_PORT,LCD_EN_PIN,PIN_LOW);
		_delay_ms(1);


		MDIO_voidSetPinValue(LCD_DATA_PORT, LCD_D4_PIN, GET_BIT(A_u8Data,0));
		MDIO_voidSetPinValue(LCD_DATA_PORT, LCD_D5_PIN, GET_BIT(A_u8Data,1));
		MDIO_voidSetPinValue(LCD_DATA_PORT, LCD_D6_PIN, GET_BIT(A_u8Data,2));
		MDIO_voidSetPinValue(LCD_DATA_PORT, LCD_D7_PIN, GET_BIT(A_u8Data,3));


		MDIO_voidSetPinValue(LCD_CONTROL_PORT,LCD_EN_PIN,PIN_HIGH);
		_delay_ms(1);

		MDIO_voidSetPinValue(LCD_CONTROL_PORT,LCD_EN_PIN,PIN_LOW);
		_delay_ms(1);


}
void HLCD_voidSendString(char *str){
for(u8 i =0;str[i]!='\0';i++){
	HLCD_voidSendData(str[i]);
}
}



void HLCD_voidInit(void){
	_delay_ms(20);
	HLCD_voidSendCommand(0x33);
	HLCD_voidSendCommand(0x32);
	HLCD_voidSendCommand(FUNCTION_SET_4BITMODE_4LINE_5X7DOT);
	HLCD_voidSendCommand(DISPLAY_ON_CURSOR_OFF);
    HLCD_voidSendCommand(DISPLAY_CLEAR);
	HLCD_voidSendCommand(ENTRY_MODE_SET);
}

void HLCD_voidSendNumber(u32 A_u32Number){
	 u32 local_u32Number = 1;
	    if (A_u32Number == 0)
	    {
	        HLCD_voidSendData('0');
	    }
	    while (A_u32Number != 0)
	    {
	        local_u32Number = ((local_u32Number * 10) + (A_u32Number % 10));
	        A_u32Number = A_u32Number / 10;
	    }
	    while (local_u32Number != 1)
	    {
	        HLCD_voidSendData((local_u32Number % 10) + 48);
	        local_u32Number = local_u32Number / 10;
	    }
}

void HLCD_voidGOTO(u8 A_u8RowNo,u8 A_u8ColNo){
	u8 local_u8_DDRAM=0;
	switch(A_u8RowNo){
	case ROW1:
		local_u8_DDRAM=0x80+A_u8ColNo;
		break;
	case ROW2:
		local_u8_DDRAM=0xC0+A_u8ColNo;
		break;
	case ROW3:
		local_u8_DDRAM=0x94+A_u8ColNo;
		break;
	case ROW4:
		local_u8_DDRAM=0xD4+A_u8ColNo;
		break;
	default:
		break;
	}
	HLCD_voidSendCommand(local_u8_DDRAM|SET_DDRAM_ADDRESS);
}






