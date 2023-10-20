/********************************************************/
/******** Author      : Martina Mofied Maurice *********/
/******** Date        : 20/10/2023            *********/
/******** version     : V1.0                 *********/
/******** Description : SSD_APP             *********/
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

void main(void){
	MDIO_voidInit();
	while(1){
	HSSD_voidDisplayAscending();
	_delay_ms(1000);
	HSSD_voidDisplayDescending();
	_delay_ms(1000);
	}

}
