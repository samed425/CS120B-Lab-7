/*	Author: bbaid001
 *  Partner(s) Name: 
 *	Lab Section:
 *	Assignment: Lab #  Exercise #
 *	Exercise Description: [optional - include for your own benefit]
 *
 *	I acknowledge all content contained herein, excluding template or example
 *	code, is my own original work.
 *
 *	Demo Link: 
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
	if (temp > (MAX * 7) / 8) { led = 0xFF; }
	else if (temp > (MAX * 6) / 8) { led = 0x7F; }
	else if (temp > (MAX * 5) / 8) { led = 0x3F; }
	else if (temp > (MAX * 4) / 8) { led = 0x1F; }
	else if (temp > (MAX * 3) / 8) { led = 0x0F; }
	else if (temp > (MAX * 2) / 8) { led = 0x07; }
	else if (temp > (MAX) / 8) { led = 0x03; }
	else if (temp > 0) { temp = 0x01; }
	else { temp = 0x00; }
	PORTB = led;

    }
    return 1;
}
