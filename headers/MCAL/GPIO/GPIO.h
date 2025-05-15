#ifndef GPIO_HEADER
#define GPIO_HEADER

#include<stdint.h>

#define PORTA_ID 0
#define PORTB_ID 1
#define PORTC_ID 2
#define PORTD_ID 3
#define PORTE_ID 4
#define PORTF_ID 5

#define PIN_0    0
#define PIN_1    1
#define PIN_2    2
#define PIN_3    3
#define PIN_4    4
#define PIN_5    5
#define PIN_6    6
#define PIN_7    7


#define low 0
#define high 0

#define input 0
#define output 1

#define pull_down 0
#define pull_up 1
#define floating 2


void MCAL_GPIO_INIT(uint8_t GPIO_SEL); //clock
void MCAL_GPIO_DIGITAL_INIT(uint8_t GPIO_SEL,uint8_t pin); //enable pin as digital i/p
void MCAL_GPIO_DIGITAL_PIN_MODE(uint8_t GPIO_SEL,  uint8_t pin, uint8_t Mode, uint8_t Polarity);


void MCAL_GPIO_WRITE_PIN(uint8_t GPIO_SEL, uint8_t pin, uint8_t data); //write
uint8_t MCAL_GPIO_READ_PIN(uint8_t GPIO_SEL, uint8_t pin); //read
void MCAL_GPIO_TOGGLE_PIN(uint8_t GPIO_SEL, uint8_t pin);







#endif

