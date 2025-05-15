#ifndef LCD_H
#define LCD_H

#include "tm4c123gh6pm.h"
#include <stdint.h>
#define SET_8BITS               0x38 //8bit - 2 Rows 5 x 8 Dots format display
#define SET_4BITS               0x28 //4bit - 2 Rows 5 x 8 Dots format display
#define CURSOR_OFF              0x0C
#define CURSOR_ON               0x0E
#define CLEAR                   0x01
#define ENTRY_MODE              0x06
#define PIN0TO7                 0xFF
#define PIN3TO5                 0x38
#define LOWER_LINE              0xC0
#define UPPER_LINE              0x80
#define UNLOCK_PORT             0x4C4F434B
#define LCD_SETUP()             LCD_Cmd(SET_8BITS)
#define LCD_CLEAR()             LCD_Cmd(CLEAR)
#define LCD_START()             LCD_Cmd(CURSOR_OFF)
#define LCD_MOVECURSOR()        LCD_Cmd(ENTRY_MODE)
#define LCD_MOVECURSOR_UPPER()  LCD_Cmd(UPPER_LINE)
#define LCD_MOVECURSOR_LOWER()  LCD_Cmd(LOWER_LINE)

static void PULSE_GENERATOR(void);
void LCD_Init(void);
void LCD_Cmd(uint8_t cmd);
void LCD_SendChar(uint8_t Char);
void LCD_Print (const char * Data,uint8_t row);


#endif
