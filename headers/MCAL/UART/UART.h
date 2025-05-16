#ifndef UART_H_
#define UART_H_

#include <stdint.h>
#include <stdbool.h>


#define UART0_ID 0
#define UART1_ID 1
#define UART2_ID 2
#define UART3_ID 3
#define UART4_ID 4
#define UART5_ID 5
#define UART6_ID 6
#define UART7_ID 7


void UART_Init(void);
void UART_TX(uint8_t data);
uint8_t UART_RX(void);
void UART_TX_STRING(const char *str);
void UART_RX_STRING(char *str, uint32_t length);

void UART5_Init(void);
void UART5_TX(uint8_t data);
uint8_t UART5_RX(void);
void UART5_TX_STRING(const char *str);
void UART5_RX_STRING(char *str, uint32_t length);

#endif