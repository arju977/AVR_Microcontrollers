/*
 * led_blink_1s_prescalar.c
 *
 * Created: 29-03-2026 16:18:13
 * Author : HP
 */ 

#include <avr/io.h>
#define F_CPU 16000000UL

void delay_1s(void)
{
	// step 1 : load 0 to TCNT0
	TCNT0 = 0;
	// Step 2 : choose Normal mode : mode0 
	TCCR0A &= ~((1 << WGM00 ) | (1 << WGM01));
	TCCR0B &= ~(1 << WGM02);
	// Step 3 : set the prescalar 1024
	TCCR0B |= ((1 << CS00) | (1 << CS02));
	TCCR0B &= ~(1 << CS01);
	
	// step 4 : overflow calculation
	/*
		Fclk = 16MH = 16,000,000
		16,000,000 / 1024 = 15,625
		1 Tick = 1 / 15,625 = 64 ms
		256 ticks = 256 x 64 ms = 16384 micro seconds -> 1 overflow -> 16384x 10^-6
		for 1s = 1 / 16384 micro seconds = 61 overflow required for 1s delay
		
	*/
	
	for (uint16_t i = 0; i<61 ; i++)
	{
		while (!(TIFR0 & (1 << TOV0)));		// Cheking the overflow 
		TIFR0 |= (1 << TOV0);				// Clearing the bit  by writing 1 to it
	}
}

int main(void)
{
    /* Replace with your application code */
	DDRB |= (1 << DDB2);			//PORT Config for led
	PORTB &= ~(1 << PB2);			// Making low during starting
    while (1) 
    {
		PORTB ^= (1 << PB2);		// Togglre the pin 
		delay_1s();					// Calling the delay fn
    }
}

