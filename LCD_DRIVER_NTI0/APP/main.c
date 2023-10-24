/********************************************************/
/******** Author      : Martina Mofied Maurice *********/
/******** Date        : 21/10/2023            *********/
/******** version     : V1.0                 *********/
/******** Description : LCD_APP             *********/
/***************************************************/

#include <util/delay.h>
#define F-CPU 12000000UL
#include "../LIB/BIT_MATH.h"
#include "../LIB/STD_TYPES.h"

#include "../MCAL/DIO/DIO_Interface.h"
#include "../MCAL/DIO/DIO_configuration.h"
#include "../MCAL/DIO/DIO_private.h"


#include "../HAL/LCD/LCD_Configurations.h"
#include "../HAL/LCD/LCD_Interface.h"
#include "../HAL/LCD/LCD_Private.h"
u8 ROW_FLAG=0;
u8 COl_FLAG=0;
void main(void){
	MDIO_voidInit();
	HLCD_voidInit();
	while(1){

		HLCD_voidGOTO(ROW_FLAG,COl_FLAG);
		HLCD_voidSendData('M');
		_delay_ms(1000);
		HLCD_voidSendCommand(DISPLAY_CLEAR);
		COl_FLAG++;

		if(ROW_FLAG==3 || (COl_FLAG<=6 && COl_FLAG>3) || (COl_FLAG<=12 && COl_FLAG>9) || (COl_FLAG<=18 && COl_FLAG>15)){
			ROW_FLAG--;

		}
		else{
			ROW_FLAG++;

		}


		if(COl_FLAG==20){
			ROW_FLAG=0;
			COl_FLAG=0;
		}


	}


}
