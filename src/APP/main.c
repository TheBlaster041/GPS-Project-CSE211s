#include "LCD.h"
#include "GPIO.h"
#include "Map.h"
#include "systic_Test.h"
#include "UART.h"
#include <stdio.h>
#include "BUZZER.h"
#include "LED.h"

#define CHECK_DISTANCE GPS_getDistance(current_long,current_lat,LOCATION_LONG,LOCATION_LAT)
#define LOCATION_LONG  Locations[GPS_Searching(current_long,current_lat)][1]
#define LOCATION_LAT	 Locations[GPS_Searching(current_long,current_lat)][0]

extern float current_long,current_lat,speed;
extern char Name_Locations [Location_Numbers] [Word_Size];
extern float Locations [Location_Numbers] [Lat_Long];
int main(void)
{
		GPIO_INIT(PORTF_ID);
		LED_Init();
		BUZZER_Init(PORT7);
    systic_init();
    LCD_Init();
		UART5_Init();
    LCD_Print("Welcome",0);
    Systick_Wait_ms(2000);
    LCD_Print("Searching.....",0);
		Systick_Wait_ms(3000);
    while (1)
    {
				GPS_Read();
				GPS_getFormat();
			if((current_long!=0)&&(current_lat!=0))
			{
				LCD_Print("Nearest Location:",0);
				LCD_Print(Name_Locations[GPS_Searching(current_long,current_lat)],1);
			if(GPS_SearchingCheck(CHECK_DISTANCE))
				{
					BUZZER_Enable(PORT7);
					LED_Enable(GREEN);
					LED_Disable(RED);
				}
			else
				{
					BUZZER_Disable(PORT7);
					LED_Disable(GREEN);
					LED_Enable(RED);
				}
			}
					
		}
}
    
