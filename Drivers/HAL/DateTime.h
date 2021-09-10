/*
 * DateTime.h
 *
 * Created: 8/13/2021 5:56:23 PM
 *  Author: Maher
 */ 


#ifndef DATETIME_H_
#define DATETIME_H_

#include "segment_driver.h"

#define MAX_DAY_SEC 86400

typedef enum{TIME_MODE, DATE_MODE}DateTime;
typedef enum{AM, PM}PM_AM;
typedef enum{ALARM_OFF, ALARM_ON}ALARM;

static unsigned char time[DISPLAY_DIGIT_NUM] = {0};

unsigned char *  inSecond(unsigned int seconds);
void displayTimeDate(unsigned char time_date, unsigned char digit,DateTime dt, PM_AM pm_am,ALARM alarm);

#endif /* INCFILE1_H_ */