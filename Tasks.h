/*
 * Tasks.h
 *
 * Created: 8/16/2021 11:25:51 PM
 *  Author: Maher
 */ 


#ifndef TASKS_H_
#define TASKS_H_

#include "DateTime.h"
#include "RTC.h"
#include "Timer1.h"
#include "OSAcfg.h"
#include "Light.h"

#include "osa.h"

#ifndef ATMEGA32A

#define _2ms_TASK	12
#define _1s_TASK	6000

#else

#define _2ms_TASK	2
#define _1s_TASK	1000

#endif



void displayTask(void);
void tickTask(void);
void brightAdjust(void);
void enableCompInt(void);
#endif /* TASKS_H_ */