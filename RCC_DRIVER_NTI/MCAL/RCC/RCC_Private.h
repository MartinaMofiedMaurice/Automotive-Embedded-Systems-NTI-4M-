/********************************************************/
/******** Author      : Martina Mofied Maurice *********/
/******** Date        : 31/10/2023            *********/
/******** version     : V1.0                 *********/
/******** Description : RCC_PRIVATE         *********/
/***************************************************/
#ifndef MCAL_RCC_RCC_PRIVATE_H_
#define MCAL_RCC_RCC_PRIVATE_H_

typedef struct{
	u32 HSI_ON     :1;
	u32 HSI_RDY    :1;
	u32            :1;
	u32 HSITRIM    :5;
	u32 HSICAL     :8;
	u32 HSE_ON     :1;
	u32 HSE_RDY    :1;
	u32 HSE_BYP    :1;
	u32 CSS_ON     :1;
	u32            :4;
	u32 PLL_ON     :1;
	u32 PLL_RDY    :1;
	u32            :6;
}RCC_CR;

#define RCC_CONTROL_REG          (((volatile RCC_CR*)0x40021000))
/**************************************************************/
typedef struct{
	u32 SW         :2;
	u32 SW_STAUTS  :2;
	u32 HPRE       :4;
	u32 PPRE1      :3;
	u32 PPRE2      :3;
	u32 ADCPRE     :2;
	u32 PLL_SRC    :1;
	u32 PLL_XTPRE  :1;
	u32 PLL_MUL    :4;
	u32 USB_PRE    :1;
	u32            :1;
	u32 MCO        :3;
	u32            :5;
}RCC_CFGR;

#define SYSCLK_MCO            0b100
#define MCO_HSI_CLOCK         0b101
#define MCO_HSE_CLOCK         0b110
#define MCO_PLL_DIVIDED_2     0b111

#define PLL_MUL_BY_2       0b0000
#define PLL_MUL_BY_3       0b0001
#define PLL_MUL_BY_4       0b0010
#define PLL_MUL_BY_5       0b0011
#define PLL_MUL_BY_6       0b0100
#define PLL_MUL_BY_7       0b0101
#define PLL_MUL_BY_8       0b0110
#define PLL_MUL_BY_9       0b0111
#define PLL_MUL_BY_10      0b1000
#define PLL_MUL_BY_11      0b1001
#define PLL_MUL_BY_12      0b1010
#define PLL_MUL_BY_13      0b1011
#define PLL_MUL_BY_14      0b1100
#define PLL_MUL_BY_15      0b1101
#define PLL_MUL_BY_16      0b1110
#define PLL_MUL1_BY_16     0b1111

#define APB_NOT_DIVIDED     0b000
#define APB_DIVIDED_2       0b100
#define APB_DIVIDED_4       0b101
#define APB_DIVIDED_8       0b110
#define APB_DIVIDED_16      0b111

#define AHB_NOT_DIVIDED        0b0000
#define AHB_DIVIDED_2          0b1000
#define AHB_DIVIDED_4          0b1001
#define AHB_DIVIDED_8          0b1010
#define AHB_DIVIDED_16         0b1011
#define AHB_DIVIDED_64         0b1100
#define AHB_DIVIDED_128        0b1101
#define AHB_DIVIDED_256        0b1110
#define AHB_DIVIDED_512        0b1111

#define RCC_CLKCONFIG_REG        (((volatile RCC_CFGR*)0x40021004))
/**************************************************************/
#define RCC_CLKINT_REG           (*((volatile u32*)0x40021008))
/**************************************************************/
#define RCC_APB2RES_REG          (*((volatile u32*)0x4002100C))
/**************************************************************/
#define RCC_APB1RES_REG          (*((volatile u32*)0x40021010))
/**************************************************************/
#define RCC_AHBENABLE_REG        (*((volatile u32*)0x40021014))
/**************************************************************/
#define RCC_APB2ENABLE_REG       (*((volatile u32*)0x40021018))
/**************************************************************/
#define RCC_APB1ENABLE_REG       (*((volatile u32*)0x4002101C))
/**************************************************************/
#define RCC_BACKUPCONTRL_REG     (*((volatile u32*)0x40021020))
/**************************************************************/
#define RCC_ACONTROLSTATUS_REG   (*((volatile u32*)0x40021024))
/**************************************************************/
#define	RCC_HSI				0
#define	RCC_HSECRYSTAL		1
#define	RCC_HSERC			2
#define	RCC_PLL				3
/**************************************************************/
#define	PLL_HSI_DIVIDED_2		0
#define	PLL_HSE				    1
#define	PLL_HSE_DIVIDED_2		2
/**************************************************************/




#endif /* MCAL_RCC_RCC_PRIVATE_H_ */
