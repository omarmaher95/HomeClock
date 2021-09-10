/*
 * ADC.c
 *
 * Created: 8/24/2021 12:03:56 AM
 *  Author: Maher
 */ 
#include "ADC.h"

//Switch off ADC by clearing ADEN bit before entering power saving mode
void ADC_init(void){
	/*External Reference at AVCC
	Left Adjusted Result to read ADCH only
	Read ADC6*/
	ADMUX |= (1 << REFS0) | (ADC6D) | (1 << ADLAR); 
	//Prescaler is 64 for 93750 Hz
	ADCSRA |= (1 << ADPS1) | (1 << ADPS2);
	//Disable Digital Input Buffer for Power Saving
	DIDR0 |= (1 << ADC6D);
	//Enable Interrupt for EOC
	ADCSRA |= (1 << ADIE);
	//Enable ADC
	ADC_Enable();
}

void ADC_SOC(void){
	//ADC Start Of Conversion
	ADCSRA |= (1 << ADSC);	
}

void ADC_Enable(void){
	ADCSRA |= (1 << ADEN);
}

void ADC_Disable(void){
	ADCSRA &= ~(1 << ADEN);
}

unsigned char ADC_readData(void){
	return ADCH;
}


