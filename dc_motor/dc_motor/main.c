/*
 * dc_motor.c
 *
 * Created: 19-03-2026 20:22:15
 * Author : HP
 */ 

#include <avr/io.h>
#define F_CPU 16000000UL
#include <util/delay.h>

int main(void)
{
	DDRD |= ((1<<DDD1) | (1<<DDD2));				// set pin 1,2 as output
    /* Replace with your application code */
    while (1) 
    {
		// dc motor to rotate clockwise direction
		PORTD |= (1<<PD1);				// pin1 high		
		PORTD &= ~(1<<PD2);				// pin2 low
		_delay_ms(5000);
		
		// dc motor to rotate anti-clockwise direction
		PORTD &= ~(1<<PD1);				// pin1 low			
		PORTD |= (1<<PD2);				// pin2 high
		_delay_ms(5000);
    }
}

