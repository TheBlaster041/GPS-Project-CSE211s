#ifndef LED_H
#define LED_H
#define RED    		0x02 //0b00000010 Pin 1
#define BLUE    	0x04 //0b00000100 Pin 2
#define GREEN   	0x08 //0b00001000 Pin 3
#define PIN1_2_3  0x0E //PIN1,2,3
#include "GPIO.h"


void LED_Init();
void LED_Enable(uint8_t Color);
void LED_Disable(uint8_t Color);


#endif
