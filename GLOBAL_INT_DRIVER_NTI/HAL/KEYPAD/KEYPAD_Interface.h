/*
 * KEYPAD_Interface.h
 *
 *  Created on: Oct 22, 2023
 *      Author: mtoty
 */

#ifndef HAL_KEYPAD_KEYPAD_INTERFACE_H_
#define HAL_KEYPAD_KEYPAD_INTERFACE_H_

#define ROWS_PORT       PORTC
#define COLS_PORT       PORTD


#define ROW1_PIN       PIN5
#define ROW2_PIN       PIN4
#define ROW3_PIN       PIN3
#define ROW4_PIN       PIN2

#define COL1_PIN       PIN7
#define COL2_PIN       PIN6
#define COL3_PIN       PIN5
#define COL4_PIN       PIN3

u8 HKEYPAD_u8GetPressedKeyMatrixMode(void);

u8 HKEYPAD_u8GetPressedKeyDirectMode(u8 A_u8ColPIN);

#endif /* HAL_KEYPAD_KEYPAD_INTERFACE_H_ */
