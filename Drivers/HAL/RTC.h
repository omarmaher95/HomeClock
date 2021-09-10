/*
 * RTC.h
 *
 * Created: 8/13/2021 10:20:51 PM
 *  Author: Maher
 */ 


#ifndef RTC_H_
#define RTC_H_

#include "Timer1.h"

#define AC_SecondsCounter 60

typedef enum{AC_LINE, EXT_OSC}RTC_SRC;

void (*analog_CallBack)(void);
void AC_RTC(void);

#endif /* RTC_H_ */