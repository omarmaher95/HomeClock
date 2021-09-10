//File includes dirivers for 7 segments

#include "segment_driver.h"

static void getDigit(unsigned char num, DP dp){
	unsigned char digit = 0;
	switch(num){
		case 0:
			//A,B,C,D,E,F is On
			digit = 0b00111111;
			break;
		case 1:
			digit = 0b00000110;
			break;
		case 2:
			digit = 0b01011011;
			break;
		case 3:
			digit = 0b01001111;
			break;
		case 4:
			digit = 0b01100110;
			break;
		case 5:
			digit = 0b01101101;
			break;
		case 6:
			digit = 0b01111101;
			break;
		case 7:
			digit = 0b00000111;
			break;
		case 8:
			digit = 0b01111111;
			break;
		case 9:
			digit = 0b01101111;
			break;
	}
#ifdef ATMEGA32A
	Segments.SEG = ~((digit << 1) | dp);
#else
	Segments.SEG = ((digit << 1) | dp);
#endif
}

void blankLEDs(void){
	//Disable LED 1
	PORTB &= ~(1 << DISPLAY_DIGIT_1_PIN); 
	//Disable LED 2:6
	PORTD &= ~((1 << DISPLAY_DIGIT_2_PIN) | (1 << DISPLAY_DIGIT_3_PIN) | (1 << DISPLAY_DIGIT_4_PIN) 
	| (1 << DISPLAY_DIGIT_5_PIN) | (1 << DISPLAY_DIGIT_6_PIN));
}

static void DisplaySegment(unsigned char LEDNumber){
	blankLEDs();
	//Set Pins to LOW to turn segments off
	PORTA &= ~((1 << SEGMENT_DOT_PIN) | (1 << SEGMENT_A_PIN) | (1 << SEGMENT_B_PIN) | (1 << SEGMENT_F_PIN) | (1 << SEGMENT_G_PIN));
	PORTB &= ~((1 << SEGMENT_C_PIN) | (1 << SEGMENT_D_PIN) | (1 << SEGMENT_E_PIN));
	_delay_us(5);
	if(LEDNumber != 6 && Segments.SEG != 0){
		PORTA |= (0xC0 & Segments.SEG)>>3 |(0x07 & Segments.SEG);
		PORTB |= (Segments.segments.e << PB0) | (Segments.segments.d << PB1) | (Segments.segments.c << PB4);
	}
	switch(LEDNumber){
		case 1:
			PORTB |= (1 << DISPLAY_DIGIT_1_PIN); //Enable LED 1
			break;
		case 2:
			PORTD |= (1 << DISPLAY_DIGIT_2_PIN); //Enable LED 2
			break;
		case 3:
			PORTD |= (1 << DISPLAY_DIGIT_3_PIN); //Enable LED 3
			break;
		case 4:
			PORTD |= (1 << DISPLAY_DIGIT_4_PIN); //Enable LED 4
			break;
		case 5:
			PORTD |= (1 << DISPLAY_DIGIT_5_PIN); //Enable LED 5
			break;
		case 6:
			PORTD |= (1 << DISPLAY_DIGIT_6_PIN); //Enable LED 6
			break;
	}
}

void initDisplay(void){
#ifdef ATMEGA32A
	//Set Pins to High to turn segments off
	PORTA |= ((1 << SEGMENT_DOT_PIN) | (1 << SEGMENT_A_PIN) | (1 << SEGMENT_B_PIN) | (1 << SEGMENT_F_PIN) | (1 << SEGMENT_G_PIN));
	PORTB |= ((1 << SEGMENT_C_PIN) | (1 << SEGMENT_D_PIN) | (1 << SEGMENT_E_PIN));	
#else
	//Set Pins to High to turn segments off
	PORTA &= ~((1 << SEGMENT_DOT_PIN) | (1 << SEGMENT_A_PIN) | (1 << SEGMENT_B_PIN) | (1 << SEGMENT_F_PIN) | (1 << SEGMENT_G_PIN));
	PORTB &= ~((1 << SEGMENT_C_PIN) | (1 << SEGMENT_D_PIN) | (1 << SEGMENT_E_PIN));	
#endif
	
	//Set Segments Pins to Output
	DDRA |= ((1 << SEGMENT_DOT_PIN) | (1 << SEGMENT_A_PIN) | (1 << SEGMENT_B_PIN) | (1 << SEGMENT_F_PIN) | (1 << SEGMENT_G_PIN));
	DDRB |= ((1 << SEGMENT_C_PIN) | (1 << SEGMENT_D_PIN) | (1 << SEGMENT_E_PIN));
	
	//Set LED 1 Pin Output
	DDRB |= (1 << DISPLAY_DIGIT_1_PIN); 
	//Set LEDs 2:6 Pins Output
	DDRD |= ((1 << DISPLAY_DIGIT_2_PIN) | (1 << DISPLAY_DIGIT_3_PIN) | (1 << DISPLAY_DIGIT_4_PIN) 
	| (1 << DISPLAY_DIGIT_5_PIN) | (1 << DISPLAY_DIGIT_6_PIN) | (1 << DISPLAY_COLON_PIN));
	
	blankLEDs();
}

void display(unsigned char num, unsigned char led, Colon colon, DP dp){
	//Colon LED Control
	PORTD &= ~(1 << PD6);
	PORTD |= (colon << PD6); 
	
	getDigit(num, dp);
	DisplaySegment(led);
}


