#include <util/delay.h>
#define F-CPU  12000000UL
#include "../LIB/BIT_MATH.h"
#include "../LIB/STD_TYPES.h"

#include "../MCAL/DIO/DIO_Interface.h"
#include "../MCAL/DIO/DIO_configuration.h"
#include "../MCAL/DIO/DIO_private.h"
#include "../MCAL/GLOBAL_INT/GLOBAL_INT_Configurations.h"
#include "../MCAL/GLOBAL_INT/GLOBAL_INT_Interface.h"
#include "../MCAL/GLOBAL_INT/GLOBAL_INT_Private.h"
#include "../MCAL/EXIT_INT_DRIVER_NTI/EXIT_INT_Configurations.h"
#include "../MCAL/EXIT_INT_DRIVER_NTI/EXIT_INT_Interface.h"
#include "../MCAL/EXIT_INT_DRIVER_NTI/EXIT_INT_Private.h"


#include "../HAL/KEYPAD/KEYPAD_Configurations.h"
#include "../HAL/KEYPAD/KEYPAD_Interface.h"
#include "../HAL/KEYPAD/KEYPAD_Private.h"
#include "../HAL/LCD/LCD_Configurations.h"
#include "../HAL/LCD/LCD_Interface.h"
#include "../HAL/LCD/LCD_Private.h"


void TOGGLENUMBER(void);
static u8	NUM=0;

void main (void){
	MDIO_voidInit();
//	MGI_voidEnable();


	MEXIT_voidConfig(EXIT1,FALLING_EDGE);
	//MEXIT_voidCallBack(EXIT1,TOGGLENUMBER);
	MEXIT_voidEnable(EXIT1);
	HLCD_voidInit();
	HLCD_voidSendNumber(NUM);


	while(1){
		 if(MDIO_u8GetPinValue(PORTD,PIN5)==0){
				  HLCD_voidSendCommand(DISPLAY_CLEAR);
				  while(MDIO_u8GetPinValue(PORTD,PIN5)==0);
					NUM--;
					HLCD_voidSendNumber(NUM);

		    }
		if(MEXIT_u8CheckFlag(EXIT1)==1)
		{	HLCD_voidSendCommand(DISPLAY_CLEAR);
		NUM++;
		HLCD_voidSendNumber(NUM);
		MEXIT_voidCLearFlag(EXIT1);
		}

	}




}

void TOGGLENUMBER(void){

	HLCD_voidSendCommand(DISPLAY_CLEAR);
	NUM++;
	HLCD_voidSendNumber(NUM);
	MEXIT_voidCLearFlag(EXIT1);


}
