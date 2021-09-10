/*
 * Timer0.c
 *
 * Created: 8/23/2021 11:42:06 PM
 *  Author: Maher
 */ 
#include "Timer0.h"

void InitT0(void)
{
	// Timer/Counter 0 initialization
	// Clock source: System Clock
	// Clock value: 125.000 kHz
	// Mode: Normal top=0xFF
	// OC0 output: Disconnected
#ifdef ATMEGA32A
	TCCR0 |= (1 << WGM01) | (1 << CS01) | (1 << CS00);
	// Timer(s)/Counter(s) Interrupt(s) initialization
	TIMSK = 0x02;
	OCR0 = 124;
#else
	TCCR0A |= (1 << WGM01) ;
	TCCR0B |= (1 << CS01);
	// Timer(s)/Counter(s) Interrupt(s) initialization
	TIMSK0 = 0x02;
	OCR0A = 124;
#endif	

	SREG |= (1 <<SREG_I);
}

ISR(TIMER0_COMPA_vect)
{
	// Place your code here
	// Transfer HW tick to OSA Kernel
	// To handle the required Delay
	OS_Timer();
}
