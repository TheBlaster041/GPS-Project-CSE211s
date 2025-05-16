#ifndef BUZZER_H
#define BUZZER_H
#define PORT0     0x01
#define PORT1     0x02
#define PORT2     0x04
#define PORT3     0x08
#define PORT4     0x10
#define PORT5     0x20
#define PORT6     0x40
#define PORT7     0x80

#include "GPIO.h"

void BUZZER_Init(uint8_t PORT_NUM);
void BUZZER_Enable(uint8_t PORT_NUM);
void BUZZER_Disable(uint8_t PORT_NUM);


#endif
