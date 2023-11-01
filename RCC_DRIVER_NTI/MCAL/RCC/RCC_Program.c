/********************************************************/
/******** Author      : Martina Mofied Maurice *********/
/******** Date        : 31/10/2023            *********/
/******** version     : V1.0                 *********/
/******** Description : RCC_Program         *********/
/***************************************************/

#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_TYPES.h"

#include "RCC_Interface.h"
#include "RCC_Private.h"
#include "RCC_Configurations.h"

void RCC_voidInitSysClock(void){
#if CLK_SOURCE == RCC_HSI
	RCC_CONTROL_REG->HSI_ON=1;
	RCC_CONTROL_REG->HSITRIM=0b10000;
	RCC_CLKCONFIG_REG->SW=0b00;
#elif CLK_SOURCE == RCC_HSECRYSTAL
	RCC_CONTROL_REG->HSE_ON=1;
	RCC_CONTROL_REG->HSE_BYP=0;
	RCC_CLKCONFIG_REG->SW=0b01;
#elif CLK_SOURCE == RCC_HSERC
	RCC_CONTROL_REG->HSE_ON=1;
	RCC_CONTROL_REG->HSE_BYP=1;
	RCC_CLKCONFIG_REG->SW=0b01;
#elif CLK_SOURCE == RCC_PLL
#if PLL_SOURCE_TYPE == PLL_HSI_DIVIDED_2
	RCC_CONTROL_REG->HSI_ON=1;
	RCC_CONTROL_REG->PLL_ON=1;
	RCC_CONTROL_REG->HSITRIM=0b10000;
	RCC_CLKCONFIG_REG->SW=0b10;
#elif PLL_SOURCE_TYPE == PLL_HSE
	RCC_CONTROL_REG->HSE_ON=1;
	RCC_CONTROL_REG->PLL_ON=1;
	RCC_CLKCONFIG_REG->PLL_SRC=1;

	RCC_CLKCONFIG_REG->SW=0b10;
#elif PLL_SOURCE_TYPE == PLL_HSE_DIVIDED_2
	RCC_CONTROL_REG->HSE_ON=1;
	RCC_CONTROL_REG->PLL_ON=1;
	RCC_CLKCONFIG_REG->PLL_XTPRE=1;
	RCC_CLKCONFIG_REG->SW=0b10;


#endif
}
void RCC_voidEnableClock(u8 A_u8BusID,u8 A_u8PerID){
	if(A_u8PerID<=31)
	{
		switch(A_u8BusID)
		{
		case RCC_AHB :
			SET_BIT(RCC_AHBENABLE_REG,A_u8PerID);
			break;
		case RCC_APB1 :
			SET_BIT(RCC_APB1ENABLE_REG,A_u8PerID);
			break;
		case RCC_APB2 :
			SET_BIT(RCC_APB2ENABLE_REG,A_u8PerID);
			break;
		default:
			/*ERROR*/
			break;

		}
	}
	else
	{
		/*ERROR*/
	}
}
