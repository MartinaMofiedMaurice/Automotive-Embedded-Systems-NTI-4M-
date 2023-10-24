/*
 * EXIT_INT_Private.h
 *
 *  Created on: Oct 23, 2023
 *      Author: mtoty
 */

#ifndef MCAL_EXIT_INT_DRIVER_NTI_EXIT_INT_PRIVATE_H_
#define MCAL_EXIT_INT_DRIVER_NTI_EXIT_INT_PRIVATE_H_

#define MCUCR_REG  (*(volatile u8 *)0x55)
#define MCUCSR_REG  (*(volatile u8 *)0x54)
#define GICR_REG  (*(volatile u8 *)0x5B)
#define GIFR_REG  (*(volatile u8 *)0x5A)

#define EXIT0 PIN6
#define EXIT1 PIN7
#define EXIT2 PIN5




#endif /* MCAL_EXIT_INT_DRIVER_NTI_EXIT_INT_PRIVATE_H_ */
