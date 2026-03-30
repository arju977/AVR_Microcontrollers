/*
 * input_switch.c
 *
 * Created: 19-03-2026 20:53:28
 * Author : HP
 */ 

#include <avr/io.h>
#define F_CPU 16000000UL
#include <util/delay.h>


int main(void)
{
    /* Replace with your application code */
	DDRD &= ~(1 << DDD4);					// set the pin4 as input
	DDRC |= (1<<DDC1);						// set the pin1 as output
    while (1) 
    {
		if (PIND & (1<< PIND4))				// checking the pin4 gets input from switch
		
		{
			PORTC |= (1<<PC1);				// pin1 as high
		}
		else
		{
			PORTC &= ~(1 << PC1);			// pin1 as low	
		}
    }
}

