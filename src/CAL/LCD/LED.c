#include "LED.h"

void LED_Init()
{
		GPIO_INIT(PORTF_ID);//Initialize PORTF
		GPIO_REG_INIT(PORTF_ID, PIN1_2_3 , DIGITAL ,0xFFFFFFFF); // Disable AFSEL and AMSEL and enable CR and Digital mode for pin 1,2,3 (RED,BLUE,GREEN)
	  GPIO_DIGITAL_config_MODE(PORTF_ID ,PIN1_2_3, output); // Enable DIR Output Digital where (Output is 3.3v)
}

void LED_Enable(uint8_t Color)
{
		GPIO_WRITE_config(PORTF_ID, Color); //Enable 1 Pin only Depends on Color
}

void LED_Disable(uint8_t Color)
{
		GPIO_CLEAR_DATA_R(PORTF_ID, Color); //Disable 1 Pin only Depends on Color
}

