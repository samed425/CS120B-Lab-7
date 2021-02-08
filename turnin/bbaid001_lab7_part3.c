/*	Author: bbaid001
 *  Partner(s) Name: 
 *	Lab Section:
 *	Assignment: Lab #  Exercise #
 *	Exercise Description: [optional - include for your own benefit]
 *
 *	I acknowledge all content contained herein, excluding template or example
 *	code, is my own original work.
 *
 *	Demo Link: https://www.youtube.com/watch?v=pUmD_je5ye4
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
    unsigned char led;
    unsigned short temp;
    const unsigned short MAX = 0x03F8;
    ADC_init();
    while (1) {
	temp = ADC;
	if (temp >= MAX/2) { led = 0x01; }
	else { led = 0x00; }
	PORTB = led;
    }
    return 1;
}
