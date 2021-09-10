/*
 * ADC.h
 *
 * Created: 8/24/2021 12:03:45 AM
 *  Author: Maher
 */ 


#ifndef ADC_H_
#define ADC_H_

#include "STDLib.h"

void ADC_init(void);
void ADC_SOC(void);
void ADC_Enable(void);
void ADC_Disable(void);
unsigned char ADC_readData(void);



#endif /* ADC_H_ */