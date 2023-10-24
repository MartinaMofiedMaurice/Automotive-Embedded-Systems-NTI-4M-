
#ifndef HAL_LCD_LCD_PRIVATE_H_
#define HAL_LCD_LCD_PRIVATE_H_

/*Set CGRAM Address*/
#define SET_CGRAM_ADDRESS  (u8)(0x40)

/*Set DDRAM Address*/
#define SET_DDRAM_ADDRESS  (u8)(0x80)


#define FUNCTION_SET_4BITMODE_4LINE_5X7DOT  ((u8)0x28)


#define DIPLAY_OFF              ((u8)0X08)
#define DISPLAY_ON_CURSOR_OFF   ((u8)0X0E)
#define DISPLAY_ON_BLINK_OFF    ((u8)0X0C)

#define DISPLAY_CLEAR           ((u8)0x01)

#define ENTRY_MODE_SET          ((u8)0x06)
#define SHIFT_CURSOR            ((u8)0x1C)

#define RETURN_HOME              ((u8)0x02)

#define MOVE_CURSOR_RIGHT         ((u8)0x14)
#define MOVE_CURSOR_LEFT          ((u8) 0x10)



#endif /* HAL_LCD_LCD_PRIVATE_H_ */
