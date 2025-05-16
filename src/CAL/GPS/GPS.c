#include "GPS.h"
#include "UART.h"
char GPS_logName[]="$GPRMC,";
char GPS_READ[80];
char GPS_Format [12] [20];
char *token;
float current_long,current_lat,speed;
//const double EARTH_RADIUS=6371000;
float Radian_Converter(float angle_deg)
{
	return (angle_deg * (PI/180.0));
}

float Degree_Converter(float angle_rad)
{
	int degree = (int)angle_rad /100;
	float minutes = angle_rad -(float)degree*100;
	return (degree + (minutes/60.0));
}
float GPS_getDistance(float Current_Long, float Current_Lat, float Dest_Long , float Dest_Lat)
{
	//getting angles
	float Current_Long_Rad = Radian_Converter(Degree_Converter(Current_Long));
	float Current_Lat_Rad= Radian_Converter(Degree_Converter(Current_Lat));
	float Dest_Long_Rad= Radian_Converter(Degree_Converter(Dest_Long));
	float Dest_Lat_Rad= Radian_Converter(Degree_Converter(Dest_Lat));
	
	//Getting Difference
	float Long_Diffe = Dest_Long_Rad - Current_Long_Rad;
	float Lat_Diffe = Dest_Lat_Rad - Current_Lat_Rad;
	
	//Calculate Distance
	float a = pow(sin(Lat_Diffe/2),2) + cos(Current_Lat_Rad)
		        *cos(Dest_Lat_Rad)*pow(sin(Long_Diffe/2),2);
	float c = 2 * atan2(sqrt(a),sqrt(1-a));
	float Distance = c * EARTH_RADIUS;
	return Distance;
}

void GPS_Read()
{
	char Recived_Char;
	char i = 0;
	char Recieved_Char;
	char flag=1; //Assuming Data is Valid
	//Check if The Reading is Valid due to the Output GPS
	//Where The Valid is $GPRMC, if Valid it will exit do-while if not valid flag =0 and will try again to compare
	do{
		flag=1;
		for(;i<7;i++)
		{
			if(UART5_RX()!=GPS_logName[i])
			{
				flag=0;
				break;
			}
		}
	
		}while(flag==0);
	
		Recived_Char=UART5_RX();
			strcpy(GPS_READ, ""); // Cleaning it from any garpage value
			i =0;

	while (Recieved_Char!='*') //Taking all outputs from GPS Into GPS_Read arrray
  {
    GPS_READ[i] = Recieved_Char;
    i++;
    Recieved_Char=UART5_RX();
  }
}
void GPS_getFormat ()
{
	//GPS_Format={Date,A,Lat,N,Long,E,Speed,XXXXX}
	char row_counter =0;
	token =strtok (GPS_READ,",");
	do{
		strcpy(GPS_Format[row_counter],token);
		token = strtok(NULL,",");
		row_counter++;
	}while(token!=NULL);
	if(strcmp(GPS_Format[1],"A")==0)
	{
		if(strcmp(GPS_Format[3],"N")==0) current_lat= atof(GPS_Format[2]);
		else current_lat= -atof(GPS_Format[2]);
		
		if(strcmp(GPS_Format[5],"E")==0) current_long= atof(GPS_Format[4]);
		else current_long= -atof(GPS_Format[4]);
	}
}
