/*
 * Config.h
 *
 * Created: 8/23/2021 11:45:16 PM
 *  Author: Maher
 */ 


#ifndef CONFIG_H_
#define CONFIG_H_

//#define ATMEGA32A

#ifdef ATMEGA32A
	#define F_CPU 8000000UL
#else
	#define F_CPU 6000000UL
#endif







#endif /* CONFIG_H_ */