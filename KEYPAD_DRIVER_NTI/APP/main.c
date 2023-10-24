#include <util/delay.h>
#define F_CPU 12000000UL
#include "../LIB/BIT_MATH.h"
#include "../LIB/STD_TYPES.h"

#include "../MCAL/DIO/DIO_Interface.h"
#include "../MCAL/DIO/DIO_configuration.h"
#include "../MCAL/DIO/DIO_private.h"

#include "../HAL/KEYPAD/KEYPAD_Configurations.h"
#include "../HAL/KEYPAD/KEYPAD_Interface.h"
#include "../HAL/KEYPAD/KEYPAD_Private.h"
#include "../HAL/LCD/LCD_Configurations.h"
#include "../HAL/LCD/LCD_Interface.h"
#include "../HAL/LCD/LCD_Private.h"



void main (void){
	MDIO_voidInit();
	HLCD_voidInit();

	u8 LOCAL_PIN=KEY_NOT_PRESSED;
	u8 operand1, operand2 ,key,result=0 ;
	HLCD_voidSendString("NO1:");
	_delay_ms(100);
	while(1){

		while(LOCAL_PIN == KEY_NOT_PRESSED)
		{
			LOCAL_PIN=HKEYPAD_u8GetPressedKeyMatrixMode();

		}
		_delay_ms(250);
		if(LOCAL_PIN!=KEY_NOT_PRESSED){
			if(LOCAL_PIN == 'C'){
				HLCD_voidSendCommand(DISPLAY_CLEAR);
				break;
			}
			HLCD_voidSendData(LOCAL_PIN);
			operand1=LOCAL_PIN -'0';
			HLCD_voidGOTO(1,0);
			HLCD_voidSendString("NO2:");
			while(LOCAL_PIN == KEY_NOT_PRESSED)
			{
				LOCAL_PIN=HKEYPAD_u8GetPressedKeyMatrixMode();
			}
			_delay_ms(250);

			if(LOCAL_PIN!=KEY_NOT_PRESSED)
			{
				if(LOCAL_PIN == 'C'){
					HLCD_voidSendCommand(DISPLAY_CLEAR);
					break;
				}
				HLCD_voidSendData(LOCAL_PIN);
				operand2=LOCAL_PIN-'0';
				HLCD_voidGOTO(2,0);
				HLCD_voidSendString("OP:");
				while(LOCAL_PIN == KEY_NOT_PRESSED)
				{
					LOCAL_PIN=HKEYPAD_u8GetPressedKeyMatrixMode();


				}
				_delay_ms(250);

				if(LOCAL_PIN!=KEY_NOT_PRESSED)
				{
					if(LOCAL_PIN == 'C'){
						HLCD_voidSendCommand(DISPLAY_CLEAR);
						break;
					}
					HLCD_voidSendData(LOCAL_PIN);
					key=LOCAL_PIN;
					switch(key){
					case '+':
						result=operand1+operand2;
						HLCD_voidGOTO(3,0);
						HLCD_voidSendString("Result=");
						HLCD_voidGOTO(3,7);
						HLCD_voidSendNumber(result);
						break;
					case '-':
						result=operand1-operand2;
						HLCD_voidGOTO(3,0);
						HLCD_voidSendString("Result=");
						HLCD_voidGOTO(3,7);
						HLCD_voidSendNumber(result);
						break;
					case '*':
						result=operand1*operand2;
						HLCD_voidGOTO(3,0);
						HLCD_voidSendString("Result=");
						HLCD_voidGOTO(3,7);
						HLCD_voidSendNumber(result);
						break;
					case '/':
						if(operand2 !=0){
							result=operand1/operand2;
							HLCD_voidGOTO(3,0);
							HLCD_voidSendString("Result=");
							HLCD_voidGOTO(3,7);
							HLCD_voidSendNumber(result);
						}
						else {
							HLCD_voidGOTO(3,0);
							HLCD_voidSendString('Result= inf');
						}
						break;
					default:
						break;
					}


				}

			}

		}
	}




}

/*void SimpleCalculator(void){
	u8 LOCAL_PIN=KEY_NOT_PRESSED;
	u8 operand1, operand2 ,key,result=0 ;
	HLCD_voidSendString("NO1:");
	_delay_ms(100);

	while(LOCAL_PIN == KEY_NOT_PRESSED)
	{
		LOCAL_PIN=HKEYPAD_u8GetPressedKeyMatrixMode();
	}
	if(LOCAL_PIN!=KEY_NOT_PRESSED){
		if(LOCAL_PIN == 'C'){
			HLCD_voidSendCommand(DISPLAY_CLEAR);
			break;
		}
		HLCD_voidSendData(LOCAL_PIN);
		operand1=LOCAL_PIN -'0';
		HLCD_voidGOTO(1,0);
		HLCD_voidSendString("NO2:");
		while(LOCAL_PIN == KEY_NOT_PRESSED)
		{
			LOCAL_PIN=HKEYPAD_u8GetPressedKeyMatrixMode();
		}
		if(LOCAL_PIN!=KEY_NOT_PRESSED)
		{
			if(LOCAL_PIN == 'C'){
				HLCD_voidSendCommand(DISPLAY_CLEAR);
				break;
			}
			HLCD_voidSendData(LOCAL_PIN);
			operand2=LOCAL_PIN-'0';
			HLCD_voidGOTO(2,0);
			HLCD_voidSendString("OP:");
			while(LOCAL_PIN == KEY_NOT_PRESSED)
			{
				LOCAL_PIN=HKEYPAD_u8GetPressedKeyMatrixMode();
			}
			if(LOCAL_PIN!=KEY_NOT_PRESSED)
			{
				if(LOCAL_PIN == 'C'){
					HLCD_voidSendCommand(DISPLAY_CLEAR);
					break;
				}
				HLCD_voidSendData(LOCAL_PIN);
				key=LOCAL_PIN;
				switch(key){
				case '+':
					result=operand1+operand2;
					HLCD_voidGOTO(3,0);
					HLCD_voidSendString("Result=");
					HLCD_voidGOTO(3,7);
					HLCD_voidSendNumber(result);
					break;
				case '-':
					result=operand1-operand2;
					HLCD_voidGOTO(3,0);
					HLCD_voidSendString("Result=");
					HLCD_voidGOTO(3,7);
					HLCD_voidSendNumber(result);
					break;
				case '*':
					result=operand1*operand2;
					HLCD_voidGOTO(3,0);
					HLCD_voidSendString("Result=");
					HLCD_voidGOTO(3,7);
					HLCD_voidSendNumber(result);
					break;
				case '/':
					if(operand2 !=0){
						result=operand1/operand2;
						HLCD_voidGOTO(3,0);
						HLCD_voidSendString("Result=");
						HLCD_voidGOTO(3,7);
						HLCD_voidSendNumber(result);
					}
					else {
						HLCD_voidGOTO(3,0);
						HLCD_voidSendString('Result= inf');
					}
					break;
				default:
					break;
				}


			}

		}

	}
}
 */

void Task2(void){
	u8 LOCAL_PIN=KEY_NOT_PRESSED;
	LOCAL_PIN=HKEYPAD_u8GetPressedKeyMatrixMode();
	if(LOCAL_PIN!=KEY_NOT_PRESSED){
		if(LOCAL_PIN=='1'){
			HLCD_voidSendString("Martina");
		}
		else if(LOCAL_PIN=='2'){
			HLCD_voidGOTO(1,0);
			HLCD_voidSendString("Mofied");
		}
		else if(LOCAL_PIN=='3'){
			HLCD_voidGOTO(2,0);
			HLCD_voidSendString("Maurice");
		}
		else {

			HLCD_voidSendCommand(DISPLAY_CLEAR);
		}

	}
}
