#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_TYPES.h"

#include "../DIO/DIO_Interface.h"
#include "../DIO/DIO_configuration.h"
#include "../DIO/DIO_private.h"

#include "EXIT_INT_Configurations.h"
#include "EXIT_INT_Interface.h"
#include "EXIT_INT_Private.h"
void(*PtrToFunc[3])(void);


void MEXIT_voidConfig(u8 A_u8EXIT,u8 A_u8SenseMode){
	switch(A_u8EXIT){
	case EXIT0:
		MCUCR_REG &= ~(SENSE_MODE<<EXTI0_SENSE_B1);
		MCUCR_REG |= (A_u8SenseMode<<EXTI0_SENSE_B1);
		break;
	case EXIT1:
		MCUCR_REG &= ~(SENSE_MODE<<EXTI1_SENSE_B1);
		MCUCR_REG |= (A_u8SenseMode<<EXTI1_SENSE_B1);
		break;
	case EXIT2:
		switch (A_u8SenseMode)
		{
		case FALLING_EXIT2EDGE: CLR_BIT(MCUCSR_REG,EXTI2_SENSE_B1); break;
		case RISING_EXIT2_EDGE:  SET_BIT(MCUCSR_REG,EXTI2_SENSE_B1); break;
		}
		break;
		default:
			break;
	}
}

void MEXIT_voidEnable(u8 A_u8EXIT)
{
	switch(A_u8EXIT){
	case EXIT0:
		SET_BIT(GICR_REG,EXIT0);
		break;
	case EXIT1:
		SET_BIT(GICR_REG,EXIT1);
		break;
	case EXIT2:
		SET_BIT(GICR_REG,EXIT2);
		break;
	default:
		break;
	}
}

void MEXIT_voidDisable(u8 A_u8EXIT)
{
	switch(A_u8EXIT){
	case EXIT0:
		CLR_BIT(GICR_REG,EXIT0);
		break;
	case EXIT1:
		CLR_BIT(GICR_REG,EXIT1);
		break;
	case EXIT2:
		CLR_BIT(GICR_REG,EXIT2);
		break;
	default:
		break;
	}
}

void MEXIT_voidCLearFlag(u8 A_u8EXIT){
	switch(A_u8EXIT){
	case EXIT0:
		SET_BIT(GIFR_REG,EXIT0);
		break;
	case EXIT1:
		SET_BIT(GIFR_REG,EXIT1);
		break;
	case EXIT2:
		SET_BIT(GIFR_REG,EXIT2);
		break;
	default:
		break;
	}

}

u8 MEXIT_u8CheckFlag(u8 A_u8EXIT){
	u8 LocalFlag;
	switch (A_u8EXIT){
	case EXIT0:
		LocalFlag=GET_BIT(GIFR_REG,EXIT0);
		break;
	case EXIT1:
		LocalFlag=GET_BIT(GIFR_REG,EXIT1);
		break;
	case EXIT2:
		LocalFlag=GET_BIT(GIFR_REG,EXIT2);
		break;
	default:
		LocalFlag = 0;
		break;
	}
	return LocalFlag;
}


void MEXIT_voidCallBack(u8 A_u8EXIT,void(*ptrToFunc)(void)){
	if(ptrToFunc !=NULL){
		switch(A_u8EXIT){
		case EXIT0:
			PtrToFunc[0]=ptrToFunc;
			break;
		case EXIT1:
			PtrToFunc[1]=ptrToFunc;
			break;
		case EXIT2:
			PtrToFunc[2]=ptrToFunc;
			break;
		default:
			break;
		}
	}
}
void __vector_1(void)  __attribute__((signal));
void __vector_1(void)
{
	if (PtrToFunc[0]!= NULL)
	{
		PtrToFunc[0]();
	}
}


void __vector_2(void)  __attribute__((signal));
void __vector_2(void)
{
	if (PtrToFunc[1]!= NULL)
	{
		PtrToFunc[1]();
	}
}

void __vector_3(void)  __attribute__((signal));
void __vector_3(void)
{
	if (PtrToFunc[2]!= NULL)
	{
		PtrToFunc[2]();
	}
}

