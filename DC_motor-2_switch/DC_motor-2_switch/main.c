/*
 * DC_motor-2_switch.c
 *
 * Created: 22-03-2026 21:31:48
 * Author : HP
 */ 

#include <avr/io.h>
#define F_CPU 16000000UL
#include <util/delay.h>

int main(void)
{
    /* Replace with your application code */
	DDRD |= ((1 << DDD1) | (1 << DDD0));
	DDRC &= ~((1 << DDC2) | (1 << DDC3));
	PORTC |= ((1 << PORTC2) | (1 << PORTC3));
    while (1) 
    {
		if (!(PINC & (1 << PINC3)))
		{
			PORTD ^=((1<<PORTD0) | (PORTD1));
			while(!(PIND & (1 << PIND2)));
		}
		if (PINC & (1 << PINC2))
		{
			
		}
    }
}

