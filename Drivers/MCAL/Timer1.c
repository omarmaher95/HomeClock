/*
 * Timer1.c
 *
 * Created: 8/14/2021 2:01:05 AM
 *  Author: Maher
 */ 
#include "Timer1.h"

//Enable Timer
static void Timer1Init(void){
	TCCR1B |= (1 << CS10);//Select Clock with no Prescaler
}

//Function to Initialize Input Capture for Analog Comparator
void ICP1Init(void){
	Timer1Init();
	TCCR1B |= (1 << ICNC1);//Enable Noise Canceler
	TCCR1B |= (1 << ICES1);//Rising Edge Detection
#ifdef ATMEGA32A
	TIMSK |= (1 << TICIE1);//Enable ICU Interrupt
#else
	TIMSK1 |= (1 << ICIE1);//Enable ICU Interrupt
#endif
	
}