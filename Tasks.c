/*
 * Tasks.c
 *
 * Created: 8/16/2021 11:24:21 PM
 *  Author: Maher
 */ 
#include "Tasks.h"

static unsigned char digit = 0;
static unsigned char * time_; 
static unsigned int light_AVG = 0;
static unsigned char duty = 0;
extern unsigned char ticks;
extern RTC_SRC SRC;
extern unsigned long secs;
extern unsigned int light_measure;
extern unsigned char samples;


unsigned char * x_display(unsigned long dis){//999999
	static unsigned char dis_[6] = {0};
	unsigned long tmp = 0;
	for (int x= 0; x < 6; x++){
		tmp = dis / 10;
		dis_[x] = dis - tmp*10;
		dis = tmp;
	}
	return dis_;
}


void displayTask(void){
	while (1){	
		time_ = inSecond(secs);
		//time_ = x_display(light_AVG);
		displayTimeDate(time_[digit], digit,TIME_MODE, AM, ALARM_OFF);
		if(++digit == 6){
				digit = 0;
		}
		OS_Delay(_2ms_TASK - duty);
		blankLEDs();
		OS_Delay(duty);				//Task To Be Executed Every 2ms (500Hz)
	}
}


void tickTask(void){
	while(1){
		if(SRC == EXT_OSC){
			secs++;						//Increase Seconds Numbers	
			ticks = 0;
		}else{
			SRC = EXT_OSC;
		}
		light_AVG = light_measure / samples;
		//300u is 2.5% delay, 1800u is 15% delay Duty = 1800 - (ADCH * 1500)/1024
		duty = (light_AVG * 10) / 255;
		light_measure = 0;
		samples = 0;
		OS_Delay(_1s_TASK);				//Task To Be Executed Every 1000ms = 1s 
	}
}

void enableCompInt(void){
	while(1){
#ifdef ATMEGA32A
		TIMSK |= (1 << TICIE1);//Enable ICU Interrupt
#else
		TIMSK1 |= (1 << ICIE1);//Enable ICU Interrupt
#endif
		OS_Delay(10);
	}
}

void brightAdjust(void){
	while(1){
		ADC_SOC();
		OS_Delay(60);				//Task To Be Executed Every 10ms = 0.1s 
	}
}