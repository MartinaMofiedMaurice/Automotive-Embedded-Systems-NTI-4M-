/*
 * KEYPAD_Configurations.h
 *
 *  Created on: Oct 22, 2023
 *      Author: mtoty
 */

#ifndef HAL_KEYPAD_KEYPAD_CONFIGURATIONS_H_
#define HAL_KEYPAD_KEYPAD_CONFIGURATIONS_H_

#define KEYPAD_MODE      DIRECTMODE

#define DIRECTMODE       0
#define MATRIX_MODE      1



#define ROWS_NUMBER   4
#define COLS_NUMBER   4

#define  KEYPAD_ARR


#define KEY_NOT_PRESSED 255

#define DEBOUNCING_DELAY 150

#define KEYPAD_KEYS                 \
			{{'1', '2', '3', '+'},  \
            {'4', '5', '6', '_'},   \
            {'7', '8', '9', '*'},   \
            {'C', '0', '=', '/'}}

#define ROW_PINS {ROW1_PIN, ROW2_PIN, ROW3_PIN,ROW4_PIN}
#define COL_PINS {COL1_PIN, COL2_PIN, COL3_PIN, COL4_PIN}



#endif /* HAL_KEYPAD_KEYPAD_CONFIGURATIONS_H_ */
