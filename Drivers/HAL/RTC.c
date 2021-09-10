/*
 * RTC.c
 *
 * Created: 8/13/2021 10:20:15 PM
 *  Author: Maher
 */ 
#include "RTC.h"


extern unsigned char ticks = 0;
extern RTC_SRC SRC = AC_LINE;
extern unsigned long secs = 0;

//Timer Capture IRQ Handler
ISR(TIMER1_CAPT_vect){
#ifdef ATMEGA32A
	TIMSK &= ~(1 << TICIE1);//Disable ICU Interrupt
#else
	TIMSK1 &= ~(1 << ICIE1);//Disable ICU Interrupt
#endif
	if(ticks == AC_SecondsCounter){//1,2,3,(4), 0,1,2,3,4
		secs++;
		ticks = 0;
		SRC = AC_LINE;
	}
	++ticks;	
}


static void comparatorInit(void){
#ifdef ATMEGA32A
	DDRB &= (1 << 3); 
	PORTB &= (1 << 3); 
#else
	DIDR1 |= 3;			//Disable Digital Input Buffer for AIN0/1
#endif
	ACSR &= (1 << ACD);
	ACSR |= (1 << ACBG);	//Enable Bandgap Reference for AIN0
	_delay_us(70);			//Delay for Bandgap Reference to Stabilize
	ACSR |= (1 << ACIC);
}

static void comparatorDeInit(void){ 
	ACSR &= ~(1 << ACIE);
	ACSR |= (1 << ACD); // Disable Comparator
}


void AC_RTC(void){
	comparatorInit();
	ICP1Init();
}
