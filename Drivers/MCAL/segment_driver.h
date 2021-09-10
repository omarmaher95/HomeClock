#ifndef SEG_DRV_
#define SEG_DRV_

#include "STDLib.h"



#define  SEGMENT_A_PIN		PA1
#define  SEGMENT_B_PIN		PA2
#define  SEGMENT_C_PIN		PB4
#define  SEGMENT_D_PIN		PB1
#define  SEGMENT_E_PIN		PB0
#define  SEGMENT_F_PIN		PA3
#define  SEGMENT_G_PIN		PA4
#define  SEGMENT_DOT_PIN	PA0

#define DISPLAY_COLON_PIN	PD6

#define DISPLAY_DIGIT_NUM	6

#define DISPLAY_DIGIT_1_PIN PB5
#define DISPLAY_DIGIT_2_PIN PD2
#define DISPLAY_DIGIT_3_PIN PD3
#define DISPLAY_DIGIT_4_PIN PD4
#define DISPLAY_DIGIT_5_PIN PD5
#define DISPLAY_DIGIT_6_PIN PD7

typedef union {
	struct {
        unsigned char dp : 1;
        unsigned char d : 1;
        unsigned char e : 1;
        unsigned char f : 1;
        unsigned char a : 1;
        unsigned char b : 1;
        unsigned char c : 1;
        unsigned char g : 1;
    }INV_segments;

    struct {
        unsigned char dp : 1;
        unsigned char a : 1;
        unsigned char b : 1;
        unsigned char c : 1;
        unsigned char d : 1;
        unsigned char e : 1;
        unsigned char f : 1;
        unsigned char g : 1;
    }segments;
    unsigned char SEG;
}LED_SEG;

typedef enum{COLON_OFF, COLON_ON}Colon;
	
typedef enum{DP_OFF, DP_ON}DP;

static LED_SEG Segments;
void initDisplay(void);
void display(unsigned char num, unsigned char led, Colon colon, DP dp);
void blankLEDs(void);



#endif