/*
 * LCD16x2.h
 *
 *  Created on: Mar 22, 2025
 *      Author: windows 11
 */

#ifndef INC_LCD16X2_H_
#define INC_LCD16X2_H_

#include "main.h"



void delay_us(uint32_t us);       					//delay in us

void LCD_SendCMD(uint8_t cmd);						//sending command to LCD

void LCD_SendData(uint8_t data);					//send character to LCD

void LCD_Init();									//initialize LCD in 4-bit mode

void LCD_Clear();									//clear LCD

void LCD_SendStr(char* str);						//send string to LCD

void LCD_SetCursor(uint8_t row, uint8_t col);		//set the cursor to the desired row & column

void LCD_ShiftRight();								//shift the display to the right

void LCD_ShiftLeft();								//shift the display to the left


#endif /* INC_LCD16X2_H_ */
