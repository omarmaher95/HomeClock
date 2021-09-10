/*
 * Light.c
 *
 * Created: 8/28/2021 10:22:27 AM
 *  Author: Maher
 */ 

#include "Light.h"

extern unsigned int light_measure = 0;
extern unsigned char samples = 0;

ISR(ADC_vect){
	light_measure += ADC_readData();
	samples++;
}

void initLight(void){
	ADC_init();
}
