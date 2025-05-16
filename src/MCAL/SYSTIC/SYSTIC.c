#include "tm4c123gh6pm.h"
#include "stdint.h"
#define SYSTICK_CURRENT_CLR     0
#define SYSTICK_ENABLE_CLR      0
#define SYSTICK_ENABLE          0X05
#define SYSTICK_COUNT_FLAG      0X00010000
#define SYSTICK_Reload_MAX      0x00FFFFFF

void systic_init (void){
NVIC_ST_CTRL_R=SYSTICK_ENABLE_CLR; //disable timer
NVIC_ST_RELOAD_R=SYSTICK_Reload_MAX; //number counts
NVIC_ST_CURRENT_R=SYSTICK_CURRENT_CLR;
NVIC_ST_CTRL_R=SYSTICK_ENABLE; // enable timer
while((NVIC_ST_CTRL_R&SYSTICK_COUNT_FLAG)==0);
}
void Systick_Wait(uint32_t delay){
    NVIC_ST_RELOAD_R=delay-1; //number counts
    while((NVIC_ST_CTRL_R&SYSTICK_COUNT_FLAG)==0);
}
void Systick_Wait_ms(uint32_t delay){
unsigned long i ;
for (i=0;i<delay;i++)
{
    Systick_Wait(16000); //wait 1 milliseconds
}
}
void Systick_Wait_Ms(uint32_t delay){
unsigned long i ;
for (i=0;i<delay;i++)
{
    Systick_Wait(16); //wait 1 milliseconds
}
}
