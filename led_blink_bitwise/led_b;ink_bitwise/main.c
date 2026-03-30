/*
 * led_b;ink_bitwise.c
 *
 * Created: 17-03-2026 20:11:10
 * Author : HP
 */ 

#define F_CPU 1600000000UL
#include <avr/io.h>
#include <util/delay.h>

int main(void)
{
    /* Replace with your application code */
	DDRD |= ((1<<DD1) | (1<<DD3))					//setting the pin1 & pin3 as OUTPUT using bit wise operation
    while (1) 
    {
		PORTD |= ((1<<PD3) | (1 << PD1));			// set the pin 1,3 as high
		_delay_ms(1000);
		PORTD &= ~((1<<PD3) | (1<< PD1));			// set the pin 1,3 as low
		_delay_ms(1000);
    }
}

