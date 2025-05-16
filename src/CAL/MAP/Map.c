#include "Map.h"

float Minimum_Dis = 999999999;
//The first Column is Lat the Second Column is Long and the GPS_Getdistnace is Long,Lat take care
float Locations [Location_Numbers] [Lat_Long]=
										    {{3003.8774414,3116.8166504}
												,{3003.8493652,3116.8364258}
												,{3003.9125977,3116.7919922}
												,{3003.8251953,3116.8251953}
												,{3003.8168945313,3116.6950683594}
												,{3003.8659667969,3116.6779785156}
												,{3003.8095703,3116.7783203}
												};


char  Name_Locations [Location_Numbers] [Word_Size] =
																		  {"Faculty's Mosque"
																			,"Hall A & B      "
																			,"Faculty's Lib   "
																			,"Hall C & D      "
																			,"ICHEP-Building  "
																			,"Kharasana Build "
																			,"Luban's Workshop"
																			}; 
																		

uint8_t GPS_Searching(float current_long,float current_lat)
{
	uint8_t Nearest_Index =0;
	float Distance = 0;
	uint8_t i=0;
	while (i<Location_Numbers)
	{
		Distance = GPS_getDistance(current_long,current_lat,Locations[i][1],Locations[i][0]);
		if(Distance<=Minimum_Dis)
		{
			Minimum_Dis=Distance;
			Nearest_Index=i;
		}
		i++;
	}
	Minimum_Dis = 999999999;
	return Nearest_Index;
}

bool GPS_SearchingCheck(uint8_t Margain)
{
	if(Margain<=27)
	{
		return true;
	}
	else
	{
		return false;
	}
}

