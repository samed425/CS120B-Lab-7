/*	Author: bbaid001
 *  Partner(s) Name: 
 *	Lab Section:
 *	Assignment: Lab #  Exercise #
 *	Exercise Description: [optional - include for your own benefit]
 *
 *	I acknowledge all content contained herein, excluding template or example
 *	code, is my own original work.
 *
 *	Demo Link: https://www.youtube.com/watch?v=9FEWOJb1GL4
 */
#include <avr/io.h>
#ifdef _SIMULATE_
#include "simAVRHeader.h"
#endif

void ADC_init() {
    ADCSRA |= (1 << ADEN) | (1 << ADSC) | (1 << ADATE);
}

int main(void) {
    DDRA = 0x00; PINA = 0xFF;
    DDRB = 0xFF; PINB = 0x00;
    DDRD = 0xFF; PIND = 0x00;
    unsigned char led_b;
    unsigned char led_d;
    unsigned short temp;
    ADC_init();
    while (1) {
	temp = ADC;
	led_b = (char) temp;
	led_d = (char)(temp >> 8);
	PORTB = led_b;
	PORTD = led_d;
    }
    return 1;
}
