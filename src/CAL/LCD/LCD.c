#include "LCD.h"
#include "tm4c123gh6pm.h"
#include "systic_Test.h"
#include "stdint.h"
#include "GPIO.h"
#include "BIT_MATHS.h"
//LCD is in 8 bits mode
static void PULSE_GENERATOR(void) //Static due to using it in this file only
{
    GPIO_WRITE_config(PORTA_ID,0x20); //Enable Pin5 (E)
    Systick_Wait_Ms(1);
    GPIO_CLEAR_DATA_R(PORTA_ID,0x20); //Disable Pin5 (E)
    Systick_Wait_Ms(1);
}


void  LCD_Init(void)
{
    Systick_Wait_ms(50);
    GPIO_INIT(PORTA_ID); 
    GPIO_REG_INIT(PORTA_ID,PIN3TO5,DIGITAL,0x00FFF000); //Initializing PORT A PINS FROM 3 TO 5 (FOR PIN3(RS=0),PIN4(RW=0) AND PIN5(E=0))
    GPIO_DIGITAL_config_MODE(PORTA_ID,PIN3TO5,output);
    GPIO_CLEAR_DATA_R(PORTA_ID,PIN3TO5); 
    GPIO_INIT(PORTB_ID);
    GPIO_REG_INIT(PORTB_ID,PIN0TO7,DIGITAL,0xFFFFFFFF);//Initializing PORT B PINS FROM 0 TO 7 (FOR DATA)
    GPIO_DIGITAL_config_MODE(PORTB_ID,PIN0TO7,output);
    GPIO_CLEAR_DATA_R(PORTB_ID,PIN0TO7);
    LCD_START(); //Starting Display without Cursor
    Systick_Wait_ms(1);
    LCD_SETUP(); //Setting the LED Display to 8bit mode
    Systick_Wait_ms(1);
    LCD_CLEAR(); //Clear Display
    Systick_Wait_ms(10);
    LCD_MOVECURSOR(); // Getting into first Position of the Row and when we write the character the cursor moves
    Systick_Wait_ms(1);

}

void LCD_Cmd(uint8_t cmd)
{
    GPIO_CLEAR_DATA_R(PORTA_ID,0x08) ; // RS = 0, RW = 0 Set Pin3 RS to 0 (Instruction Mode)
    GPIO_CLEAR_DATA_R(PORTB_ID,0xFF);
    GPIO_WRITE_config(PORTB_ID,cmd);
    PULSE_GENERATOR();
    Systick_Wait_ms(1); 
}

void LCD_SendChar(uint8_t Char)
{
    GPIO_WRITE_config(PORTA_ID,0x08); // RS = 1, RW = 0 Set Pin3 RS to 1 (Data Mode)
    GPIO_CLEAR_DATA_R(PORTB_ID,0xFF);
    GPIO_WRITE_config(PORTB_ID,Char);
    PULSE_GENERATOR();
    Systick_Wait_ms(1);   
}

void LCD_Print (const char * Data,uint8_t row)
{
   if(!row)
   {
        LCD_MOVECURSOR_UPPER();
		Systick_Wait_ms(1); 
   }
   else
   {
        LCD_MOVECURSOR_LOWER();
		Systick_Wait_ms(1); 
   }        
    while ((*Data)!='\0')
    {
        LCD_SendChar(*Data);
        Systick_Wait_ms(1);
        Data++;
    }
}

