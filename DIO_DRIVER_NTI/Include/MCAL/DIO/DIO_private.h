/********************************************************/
/******** Author      : Martina Mofied Maurice *********/
/******** Date        : 20/10/2023            *********/
/******** version     : V1.0                 *********/
/******** Description : DIO_Private         *********/
/***************************************************/

#ifndef INCLUDE_MCAL_DIO_DIO_PRIVATE_H_
#define INCLUDE_MCAL_DIO_DIO_PRIVATE_H_

#define PORTA_REG (*(volatile u8 *)0X3B)
#define DDRA_REG (*(volatile u8 *)0X3A)
#define PINA_REG (*(volatile u8 *)0X39)

#define PORTB_REG (*(volatile u8 *)0X38)
#define DDRB_REG (*(volatile u8 *)0X37)
#define PINB_REG (*(volatile u8 *)0X36)

#define PORTC_REG (*(volatile u8 *)0X35)  //7ot el adderess dah feh pointer w b3den e3mel derefrenace 3ashan akteb fih
#define DDRC_REG (*(volatile u8 *)0X34)
#define PINC_REG (*(volatile u8 *)0X33)

#define PORTD_REG (*(volatile u8 *)0X32)
#define DDRD_REG (*(volatile u8 *)0X31)
#define PIND_REG (*(volatile u8 *)0X30)



#endif /* INCLUDE_MCAL_DIO_DIO_PRIVATE_H_ */
