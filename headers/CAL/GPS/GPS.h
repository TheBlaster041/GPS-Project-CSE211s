#include <math.h>
#include <string.h>
#include <stdlib.h>

#define PI 3.14159265358979323846
#define EARTH_RADIUS 6371000;


float Radian_Converter(float angle_deg);
float Degree_Converter(float angle_rad);
float GPS_getDistance(float Current_Long, float Current_Lat, float Dest_Long , float Dest_Lat);
void GPS_Read();
void GPS_getFormat ();