/********************************************************/
/******** Author      : Martina Mofied Maurice *********/
/******** Date        : 20/10/2023            *********/
/******** version     : V1.0                 *********/
/******** Description : SSD_APP             *********/
/***************************************************/
#include <util/delay.h>
#define F_CPU 12000000UL
#include "../LIB/BIT_MATH.h"
#include "../LIB/STD_TYPES.h"

#include "../MCAL/DIO/DIO_Interface.h"
#include "../MCAL/DIO/DIO_configuration.h"
#include "../MCAL/DIO/DIO_private.h"

#include "../HAL/SSD/SSD_Configuration.h"
#include "../HAL/SSD/SSD_Interface.h"
#include "../HAL/SSD/SSD_private.h"


u8 LSSD1=0,MSSD2=0,Flag=0;
s8 LSSD3=9,MSSD4=9;
void main(void){
	MDIO_voidInit();



	while(1)
	{


	}
}

void Task1(void){
	//Binary LEDs and Seven Segment numbers
	for(u8 i=0 ;i<=9;i++){
		HSSD_voidDisplayNumberByCom(i,COM1);
		MDIO_voidSetPinValue(PORTB,PIN7,GET_BIT(i,0));
		MDIO_voidSetPinValue(PORTA,PIN4,GET_BIT(i,1));
		MDIO_voidSetPinValue(PORTA,PIN5,GET_BIT(i,2));
		MDIO_voidSetPinValue(PORTA,PIN6,GET_BIT(i,3));
		_delay_ms(SSD_DELAY_TIME);
	}

}


void Task2(void){
	//Traffic light and 2 seven segment
	//Flag to change the Led every 30 count
			if(Flag == 0 )
			{
				MDIO_voidSetPinValue(PORTB,PIN7,PIN_HIGH);
				MDIO_voidSetPinValue(PORTA,PIN6,PIN_LOW);
				MDIO_voidSetPinValue(PORTA,PIN4,PIN_LOW);
			}
			else if(Flag==1 ){
				MDIO_voidSetPinValue(PORTB,PIN7,PIN_LOW);
				MDIO_voidSetPinValue(PORTA,PIN6,PIN_HIGH);
				MDIO_voidSetPinValue(PORTA,PIN4,PIN_LOW);
			}
			else if(Flag==2 ){
				MDIO_voidSetPinValue(PORTB,PIN7,PIN_LOW);
				MDIO_voidSetPinValue(PORTA,PIN6,PIN_LOW);
				MDIO_voidSetPinValue(PORTA,PIN4,PIN_HIGH);
				if(MSSD2==2 && LSSD1 ==9){
					Flag = 0;
				}
			}

			for(u8 i=0;i<=50;i++){
				HSSD_voidDisplayNumberByCom(LSSD1,COM3);
				_delay_ms(10);
				HSSD_voidDisplayNumberByCom(MSSD2,COM4);
				_delay_ms(10);

			}

			LSSD1++;
			if((LSSD1 > 9 ) )
			{
				LSSD1 = 0;
				MSSD2++;
				if(MSSD2==3)
				{
					Flag++;
					MSSD2 = 0;

				}

			}


}

void Task3(void){
	// 2 Seven segments counting up to 99 and 2 seven segments counting down from 99
	//COM1,2 counting up COM3,4 counting down

	for(u8 i=0;i<=100;i++){
		HSSD_voidDisplayNumberByCom(LSSD1,COM1);
		_delay_ms(10);
		HSSD_voidDisplayNumberByCom(LSSD3,COM3);
		_delay_ms(10);
		HSSD_voidDisplayNumberByCom(MSSD2,COM2);
		_delay_ms(10);
		HSSD_voidDisplayNumberByCom(MSSD4,COM4);
		_delay_ms(10);
	}
	LSSD1++;
	LSSD3--;

	if((LSSD1 > 9 && MSSD2<=9) &&  (LSSD3<0&&MSSD4>=0 ))
	{
		LSSD1 = 0;
		LSSD3=9;
		MSSD2++;
		MSSD4--;
	}
	else if((MSSD2>9)&&(MSSD4<0)){
		LSSD1 = 0;
		LSSD3=9;
		MSSD2 = 0;
		MSSD4=9;
	}
	_delay_ms(40);
}



