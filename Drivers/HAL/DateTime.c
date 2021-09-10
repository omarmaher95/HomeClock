/*
 * DateTime.c
 *
 * Created: 8/13/2021 5:55:50 PM
 *  Author: Maher
 */ 

#include "DateTime.h"

unsigned char * inSecond(unsigned int sec) {
	unsigned char seconds = 0;
	unsigned char minutes = 0;
	unsigned char hours = 0;
	
	if(sec > MAX_DAY_SEC){
		sec = 0;
	}
	
	hours = sec/3600;
	minutes = (sec - hours*3600)/60;
	seconds = sec - hours*3600 - minutes*60;
	
	time[1] = (seconds / 10);
	time[0] = seconds - time[1] * 10;

	time[3] = (minutes / 10);
	time[2] = minutes- time[3] * 10;
	
	time[5] = (hours / 10);
	time[4] = hours - time[5] * 10; 
	
	return time;
}


void displayTimeDate(unsigned char time_date, unsigned char digit,DateTime dt,PM_AM pm_am, ALARM alarm){
	unsigned char dp = dt;
	if (digit == 0){
		dp = pm_am;
	}else if (digit == 5){
		dp = alarm;
	}
	display(time_date, digit + 1, !dt, dp);
}

