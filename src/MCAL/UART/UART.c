#include <stdint.h>	
#include <stdio.h>	
#include "GPIO.h"
#include <stdbool.h>
#include "BIT_MATHS.h"
#include "tm4c123gh6pm.h"
#include "UART.h"

void UART_Init(){
	SET(SYSCTL_RCGCUART_R, 0x01);
	SET(SYSCTL_RCGCGPIO_R, 0x01);
	while(GET(SYSCTL_PRGPIO_R, 0x01) == 0);
	while(GET(SYSCTL_PRUART_R, 0x01) == 0);
	CLR(UART0_CTL_R, 0xFFFFFFFF);
	SET(UART0_CTL_R, 0x300);
	UART0_IBRD_R = 101;
	UART0_FBRD_R = 11;
	UART0_LCRH_R = 0x70;
	SET(UART0_CTL_R, 0x001);
	SET(GPIO_PORTA_AFSEL_R, 0x03);
	CLR(GPIO_PORTA_PCTL_R, 0x000000FF);
	SET(GPIO_PORTA_PCTL_R, 0x00000011);
	CLR(GPIO_PORTA_AMSEL_R, 0x3);
	SET(GPIO_PORTA_DEN_R, 0X3);
}

void UART_TX(uint8_t data){
	while(GET(UART0_FR_R, 0x20) != 0);
	UART0_DR_R = data;
}

 uint8_t UART_RX(){ 
 while((UART0_FR_R&0x10) != 0);
 return((uint8_t)(UART0_DR_R&0xFF));
 }
 
 void UART_TX_STRING(const char *str){
	while(*str)
		UART_TX(*str++);
 }
 
void UART_RX_STRING(char *str, uint32_t length){
	uint32_t i = 0;
	char c;
	while(i < (length - 1)){
		c = UART_RX();
		if(c == '\n' || c == '\r')
			break;
		str[i++] = c;
	}
	str[i] = '\0';
 }
void UART5_Init(){
	SET(SYSCTL_RCGCUART_R, 0x20);
	SET(SYSCTL_RCGCGPIO_R, 0x10);
	while(GET(SYSCTL_PRGPIO_R, 0x10) == 0);
	while(GET(SYSCTL_PRUART_R, 0x20) == 0);
	CLR(UART5_CTL_R, 0xFFFFFFFF);
	SET(UART5_CTL_R, 0x300);
	UART5_IBRD_R = 101;
	UART5_FBRD_R = 11;
	UART5_LCRH_R = 0x70;
	SET(GPIO_PORTE_AFSEL_R, 0x30);
	CLR(GPIO_PORTE_PCTL_R, 0x00FF0000);
	SET(GPIO_PORTE_PCTL_R, 0x00110000);
	CLR(GPIO_PORTE_AMSEL_R, 0x30);
	SET(GPIO_PORTE_DEN_R, 0X30);
	SET(UART5_CTL_R, 0x001);
}

void UART5_TX(uint8_t data){
	while(GET(UART5_FR_R, 0x20) != 0);
	UART0_DR_R = data;
}

 uint8_t UART5_RX(){ 
 while((UART5_FR_R&0x10) != 0);
 return((uint8_t)(UART5_DR_R&0xFF));
 }
 
 void UART5_TX_STRING(const char *str){
	while(*str)
		UART_TX(*str++);
 }
 
void UART5_RX_STRING(char *str, uint32_t length){
	uint32_t i = 0;
	char c;
	while(i < (length - 1)){
		c = UART_RX();
		if(c == '\n' || c == '\r')
			break;
		str[i++] = c;
	}
	str[i] = '\0';
 }

