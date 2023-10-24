/********************************************************/
/******** Author      : Martina Mofied Maurice *********/
/******** Date        : 22/10/2023            *********/
/******** version     : V1.0                 *********/
/******** Description : KEYPAD_APP          *********/
/***************************************************/


#include <util/delay.h>
#define F-CPU 12000000UL
#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_TYPES.h"

#include "../../MCAL/DIO/DIO_Interface.h"
#include "../../MCAL/DIO/DIO_configuration.h"
#include "../../MCAL/DIO/DIO_private.h"

#include "KEYPAD_Configurations.h"
#include "KEYPAD_Interface.h"
#include "KEYPAD_Private.h"

u8 KEYPAD_Au8RowsPins[ROWS_NUMBER] = ROW_PINS;
u8 KEYPAD_Au8ColsPins[COLS_NUMBER] = COL_PINS;
u8 KEYPAD_Au8Keys[ROWS_NUMBER][COLS_NUMBER] = KEYPAD_KEYS;

u8 HKEYPAD_u8GetPressedKeyMatrixMode(void){


	 u8 local_u8RowCounter, local_u8ColCounter, local_u8PinValue, local_u8KeyValue = KEY_NOT_PRESSED, local_u8Flag = FLAG_DOWN;

	    for (local_u8RowCounter = LOOP_START; local_u8RowCounter < ROWS_NUMBER; local_u8RowCounter++)
	    {

	        MDIO_voidSetPinValue(ROWS_PORT, KEYPAD_Au8RowsPins[local_u8RowCounter], PIN_LOW);
	        for (local_u8ColCounter = LOOP_START; local_u8ColCounter < COLS_NUMBER; local_u8ColCounter++)
	        {
	            local_u8PinValue = MDIO_u8GetPinValue(COLS_PORT, KEYPAD_Au8ColsPins[local_u8ColCounter]);
	            if (local_u8PinValue == PIN_LOW)
	            {
	                _delay_ms(DEBOUNCING_DELAY);
	                local_u8PinValue = MDIO_u8GetPinValue(COLS_PORT, KEYPAD_Au8ColsPins[local_u8ColCounter]);
	                while (local_u8PinValue == KEY_PRESSED)
	                {
	                    local_u8PinValue = MDIO_u8GetPinValue(COLS_PORT, KEYPAD_Au8ColsPins[local_u8ColCounter]);
	                }
	                local_u8Flag = FLAG_UP;
	                local_u8KeyValue=KEYPAD_Au8Keys[local_u8RowCounter][local_u8ColCounter];
	                break;
	            }
	        }
	        MDIO_voidSetPinValue(ROWS_PORT, KEYPAD_Au8RowsPins[local_u8RowCounter], PIN_HIGH);
	        if (local_u8Flag == FLAG_UP)
	        {
	            break;
	        }
	    }
	    return local_u8KeyValue;
}

u8 HKEYPAD_u8GetPressedKeyDirectMode(u8 A_u8ColPIN){

	 u8  local_u8PinValue;
        local_u8PinValue=MDIO_u8GetPinValue(COLS_PORT,A_u8ColPIN);

   	    return local_u8PinValue;
}


