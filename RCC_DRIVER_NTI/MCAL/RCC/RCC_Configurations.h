/********************************************************/
/******** Author      : Martina Mofied Maurice *********/
/******** Date        : 31/10/2023            *********/
/******** version     : V1.0                 *********/
/******** Description : RCC_Configurations  *********/
/***************************************************/
#ifndef MCAL_RCC_RCC_CONFIGURATIONS_H_
#define MCAL_RCC_RCC_CONFIGURATIONS_H_

#define CLK_SOURCE     RCC_PLL

#ifdef CLK_SOURCE == RCC_PLL
#define PLL_SOURCE_TYPE   PLL_HSI_DIVIDED_2
#define PLL_PRESCALER     PLL_MUL_BY_6
#endif




#endif /* MCAL_RCC_RCC_CONFIGURATIONS_H_ */
