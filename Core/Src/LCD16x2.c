/*
 * LCD16x2.c
 *
 *  Created on: Mar 22, 2025
 *      Author: windows 11
 */
#include <LCD16x2.h>


//-------create delay in micro seconds----------------
extern TIM_HandleTypeDef htim2;

void delay_us(uint32_t us)
{
	__HAL_TIM_SET_COUNTER(&htim2,0);
	while(__HAL_TIM_GET_COUNTER(&htim2) < us)
	{}

}






//-------Send command to LCD-------------------------
void LCD_SendCMD(uint8_t cmd)
{
	//Rs pin must be set to 0 for command
	HAL_GPIO_WritePin(RS_GPIO_Port, RS_Pin, GPIO_PIN_RESET);

	//RW pin must be set to 0 to write on LCD
	HAL_GPIO_WritePin(RW_GPIO_Port, RW_Pin, GPIO_PIN_RESET);




	//---send higher nibbles---------------
	uint8_t higher_nibble = (cmd >> 4);

	//send cmd to lcd pins
	HAL_GPIO_WritePin(D7_GPIO_Port, D7_Pin,( (higher_nibble>>3) & (0x01) ));
	HAL_GPIO_WritePin(D6_GPIO_Port, D6_Pin,( (higher_nibble>>2) & (0x01) ));
	HAL_GPIO_WritePin(D5_GPIO_Port, D5_Pin,( (higher_nibble>>1) & (0x01) ));
	HAL_GPIO_WritePin(D4_GPIO_Port, D4_Pin,( (higher_nibble>>0) & (0x01) ));

	//Toggle En pin to set the data
	HAL_GPIO_WritePin(En_GPIO_Port, En_Pin, GPIO_PIN_SET);
	delay_us(100);
	HAL_GPIO_WritePin(En_GPIO_Port, En_Pin, GPIO_PIN_RESET);
	delay_us(100);





	//---send lower nibbles----------------
	uint8_t lower_nibble = (cmd >> 0);

	//send cmd to lcd pins
	HAL_GPIO_WritePin(D7_GPIO_Port, D7_Pin,( (lower_nibble>>3) & (0x01) ));
	HAL_GPIO_WritePin(D6_GPIO_Port, D6_Pin,( (lower_nibble>>2) & (0x01) ));
	HAL_GPIO_WritePin(D5_GPIO_Port, D5_Pin,( (lower_nibble>>1) & (0x01) ));
	HAL_GPIO_WritePin(D4_GPIO_Port, D4_Pin,( (lower_nibble>>0) & (0x01) ));

	//Toggle En pin to set the data
	HAL_GPIO_WritePin(En_GPIO_Port, En_Pin, GPIO_PIN_SET);
	delay_us(100);
	HAL_GPIO_WritePin(En_GPIO_Port, En_Pin, GPIO_PIN_RESET);
	delay_us(100);
}







//-------send Data to LCD------------------------
void LCD_SendData(uint8_t data)
{
	//Rs pin must be set to 1 for data
	HAL_GPIO_WritePin(RS_GPIO_Port, RS_Pin, GPIO_PIN_SET);

	//RW pin must be set to 0 to write on LCD
	HAL_GPIO_WritePin(RW_GPIO_Port, RW_Pin, GPIO_PIN_RESET);




	//---send higher nibbles---------------
	uint8_t higher_nibble = (data >> 4);

	//send data to lcd pins
	HAL_GPIO_WritePin(D7_GPIO_Port, D7_Pin,( (higher_nibble>>3) & (0x01) ));
	HAL_GPIO_WritePin(D6_GPIO_Port, D6_Pin,( (higher_nibble>>2) & (0x01) ));
	HAL_GPIO_WritePin(D5_GPIO_Port, D5_Pin,( (higher_nibble>>1) & (0x01) ));
	HAL_GPIO_WritePin(D4_GPIO_Port, D4_Pin,( (higher_nibble>>0) & (0x01) ));

	//Toggle En pin to set the data
	HAL_GPIO_WritePin(En_GPIO_Port, En_Pin, GPIO_PIN_SET);
	delay_us(100);
	HAL_GPIO_WritePin(En_GPIO_Port, En_Pin, GPIO_PIN_RESET);
	delay_us(100);





	//---send lower nibbles----------------
	uint8_t lower_nibble = (data >> 0);

	//send data to lcd pins
	HAL_GPIO_WritePin(D7_GPIO_Port, D7_Pin,( (lower_nibble>>3) & (0x01) ));
	HAL_GPIO_WritePin(D6_GPIO_Port, D6_Pin,( (lower_nibble>>2) & (0x01) ));
	HAL_GPIO_WritePin(D5_GPIO_Port, D5_Pin,( (lower_nibble>>1) & (0x01) ));
	HAL_GPIO_WritePin(D4_GPIO_Port, D4_Pin,( (lower_nibble>>0) & (0x01) ));

	//Toggle En pin to set the data
	HAL_GPIO_WritePin(En_GPIO_Port, En_Pin, GPIO_PIN_SET);
	delay_us(100);
	HAL_GPIO_WritePin(En_GPIO_Port, En_Pin, GPIO_PIN_RESET);
	delay_us(100);
}








//-------initialize LCD-------------
void LCD_Init()
{
	HAL_Delay(100);			// wait 100ms for settle time

	//---Function Set-----------------
	LCD_SendCMD(0x02); 		//initialize LCD in 4-bit mode
	HAL_Delay(1);			//wait
	LCD_SendCMD(0x28);		//2 lines, 5x8 dots format display mode
	HAL_Delay(1);			//wait


	//---Display on/off---------------
	LCD_SendCMD(0x0C);		//display on
	HAL_Delay(1);			//wait


	//---Entry Mode-------------------
	LCD_SendCMD(0x06);		//increment cursor
	HAL_Delay(1);			//wait


	//---Clear Display----------------
	LCD_SendCMD(0x01);		//clear display
	HAL_Delay(1);			//wait
}








//-------Clear LCD------------------------
void LCD_Clear()
{
	LCD_SendCMD(0x01);		//clear display
}







//-------Send string to the LCD-------------
void LCD_SendStr(char* str)
{
	while(*str)
	{
		LCD_SendData(*str++);
	}
}







//-------Set Cursor-------------------------
void LCD_SetCursor(uint8_t row, uint8_t col)
{
	uint8_t address;

	if(row == 0)
	{
		address = 0x80 + col;	//First row
	}
	else						// if(row == 1)
	{
		address = 0xC0 + col;	//Second row
	}

	LCD_SendCMD(address);
}






//-------Shift LCD to Right--------------------
void LCD_ShiftRight()
{
	LCD_SendCMD(0x1C);
}





//-------Shift LCD to Left--------------------
void LCD_ShiftLeft()
{
	LCD_SendCMD(0x18);
}





