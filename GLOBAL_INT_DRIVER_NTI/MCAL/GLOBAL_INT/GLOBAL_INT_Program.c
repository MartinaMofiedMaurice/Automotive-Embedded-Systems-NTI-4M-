/*
 * GLOBAL_INT_Program.c
 *
 *  Created on: Oct 23, 2023
 *      Author: mtoty
 */


#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_TYPES.h"

 #include "../DIO/DIO_Interface.h"
#include "../DIO/DIO_configuration.h"
#include "../DIO/DIO_private.h"

#include "GLOBAL_INT_Configurations.h"
#include "GLOBAL_INT_Interface.h"
#include "GLOBAL_INT_Private.h"





void MGI_voidEnable(void){
	SET_BIT(GLOBAL_INT_REG,GLOBAL_INT_ENABLE_PIN);
}

void MGI_voidDisable(void){
	CLR_BIT(GLOBAL_INT_REG,GLOBAL_INT_ENABLE_PIN);
}

