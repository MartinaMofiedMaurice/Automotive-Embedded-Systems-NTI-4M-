/*
 * LCD_Interface.h
 *
 *  Created on: Oct 21, 2023
 *      Author: mtoty
 */

#ifndef HAL_LCD_LCD_INTERFACE_H_
#define HAL_LCD_LCD_INTERFACE_H_

#define LCD_CONTROL_PORT PORTA
#define LCD_DATA_PORT    PORTB

#define LCD_RS_PIN       PIN3
#define LCD_EN_PIN       PIN2

#define LCD_D4_PIN       PIN0
#define LCD_D5_PIN       PIN1
#define LCD_D6_PIN       PIN2
#define LCD_D7_PIN       PIN4


void HLCD_voidSendCommand(u8 A_u8Command);
void HLCD_voidSendData(u8 A_u8Data);
void HLCD_voidInit(void);
void HLCD_voidSendNumber(u32 A_u32Number);
void HLCD_voidGOTO(u8 A_u8RowNo,u8 A_u8ColNo);
void HLCD_voidSendString(char *str);
#endif /* HAL_LCD_LCD_INTERFACE_H_ */
