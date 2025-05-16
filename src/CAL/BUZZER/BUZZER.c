#include "BUZZER.h"


void BUZZER_Init(uint8_t PORT_NUM)
{
		GPIO_INIT(PORTD_ID);//Initialize PORTD
		GPIO_REG_INIT(PORTD_ID,PORT_NUM,DIGITAL,0xFFFFFFFF); // Disable AFSEL and AMSEL and enable CR and Digital mode for any Port
	  GPIO_DIGITAL_config_MODE(PORTD_ID,PORT_NUM, output); // Enable DIR Output Digital where (Output is 3.3v)
}

void BUZZER_Enable(uint8_t PORT_NUM)
{
		GPIO_WRITE_config(PORTD_ID, PORT_NUM); //Enable 1 Pin only Depends on PORT_NUM
}

void BUZZER_Disable(uint8_t PORT_NUM)
{
		GPIO_CLEAR_DATA_R(PORTD_ID, PORT_NUM); //Disable 1 Pin only Depends on PORT_NUM
}
