/********************************************************/
/******** Author      : Martina Mofied Maurice *********/
/******** Date        : 20/10/2023            *********/
/******** version     : V1.0                 *********/
/******** Description : SSD_Interface       *********/
/***************************************************/
#ifndef INCLUDE_HAL_SSD_SSD_INTERFACE_H_
#define INCLUDE_HAL_SSD_SSD_INTERFACE_H_

#define COM1_PORT PORTA
#define COM2_PORT PORTA
#define COM3_PORT PORTB
#define COM4_PORT PORTB

#define BCD_PORT  PORTB

#define ZERO  0b0000
#define ONE   0b0001
#define TWO   0b0010
#define THREE 0b0011
#define FOUR  0b0100
#define FIVE  0b0101
#define SIX   0b0110
#define SEVEN 0b0111
#define EIGHT 0b1000
#define NINE  0b1001

#define COM1 PIN3
#define COM2 PIN2
#define COM3 PIN5
#define COM4 PIN6

#define BCD0 PIN0
#define BCD1 PIN1
#define BCD2 PIN2
#define BCD3 PIN4

void HSSD_Init(u8 A_u8COM);
void HSSD_voidDisplay(u8 A_u8number);
void HSSD_voidDisplayByPort(u8 A_u8PortId,u8 A_u8number);
void HSSD_voidDisplayDescending(void);
void HSSD_voidDisplayAscending(void);
void HSSD_voidDisplayNumberByCom(u8 A_u8number,u8 A_u8COM);
#endif /* INCLUDE_HAL_SSD_SSD_INTERFACE_H_ */
