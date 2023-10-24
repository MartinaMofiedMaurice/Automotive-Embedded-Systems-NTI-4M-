/*
 * EXIT_INT_Interface.h
 *
 *  Created on: Oct 23, 2023
 *      Author: mtoty
 */

#ifndef MCAL_EXIT_INT_DRIVER_NTI_EXIT_INT_INTERFACE_H_
#define MCAL_EXIT_INT_DRIVER_NTI_EXIT_INT_INTERFACE_H_

#define SENSE_MODE FALLING_EDGE
#define FALLING_EDGE 0b10
#define RISING_EDGE  0b11

#define SENSE_MODE_EXIT2 FALLING_EDGE
#define FALLING_EXIT2EDGE 0b0
#define RISING_EXIT2_EDGE  0b1

#define EXTI1_SENSE_B1   2
#define EXTI0_SENSE_B1   0
#define EXTI2_SENSE_B1   6

void MEXIT_voidConfig(u8 A_u8EXIT,u8 A_u8SenseMode);
void MEXIT_voidEnable(u8 A_u8EXIT);
void MEXIT_voidDisable(u8 A_u8EXIT);
void MEXIT_voidCLearFlag(u8 A_u8EXIT);
u8 MEXIT_u8CheckFlag(u8 A_u8EXIT);
void MEXIT_voidCallBack(u8 A_u8EXIT,void(*ptrToFunc)(void));
#endif /* MCAL_EXIT_INT_DRIVER_NTI_EXIT_INT_INTERFACE_H_ */
