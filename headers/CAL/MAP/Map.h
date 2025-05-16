#ifndef MAP_H
#define MAP_H

#include "GPS.h"
#include <stdint.h>
#include "stdbool.h"
#define Word_Size 20
#define Location_Numbers 7
#define Lat_Long 2


					
uint8_t GPS_Searching(float current_long,float current_lat);
bool GPS_SearchingCheck(uint8_t Margain);
#endif