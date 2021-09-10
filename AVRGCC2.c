/*
 * AVRGCC2.c
 *
 * Created: 8/13/2021 3:14:03 AM
 *  Author: Maher
 */ 

#include "Config.h"

#include "DateTime.h"
#include "RTC.h"
#include "Tasks.h"
#include "Timer0.h"
#include "Light.h"


int main(void){
	OS_Init();
	InitT0();
	initDisplay();
	initLight();
	
	OS_CreateTask(1, displayTask);
	OS_CreateTask(0, tickTask);
	OS_CreateTask(0,enableCompInt);
	OS_CreateTask(0,brightAdjust);
	
	AC_RTC();
	OS_Run();
	return 0;
}