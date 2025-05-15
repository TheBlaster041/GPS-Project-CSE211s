#ifndef SYSTIC_H
#define SYSTIC_H

#define SYSTICK_CURRENT_CLR     0
#define SYSTICK_ENABLE_CLR      0
#define SYSTICK_ENABLE          0X05
#define SYSTICK_COUNT_FLAG      0X00010000
#define SYSTICK_Reload_MAX      0x00FFFFFF


void systic_init (void);
void Systick_Wait(uint32_t delay);
void Systick_Wait_ms(uint32_t delay);
void Systick_Wait_Ms(uint32_t delay);

#endif
