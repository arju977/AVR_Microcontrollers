/*
 * led_blink_using_timer0_delay.c
 *
 * Created: 23-03-2026 20:49:41
 * Author : HP
 */ 

#include <avr/io.h>
#define F_CPU 16000000UL

void delay_1s(void)
{
	// step 1 : load 0 to TCNT0
	TCNT0 = 0;
	
	// Step 2 : choose Normal mode : mode0
	TCCR0A &= ~((1 << WGM00) | (1 << WGM01));
	TCCR0B &= ~(1 << WGM02);
	
	// Step 3 : Choose the pre-scalar value - No prescaling
	TCCR0B &= ~((1 << CS02) | (1 << CS01));
	TCCR0B |= (1 << CS00);
	
	// step 4 : overflow calculation
	/*
		Fclk = 16MH = 16,000,000
		1 Tick = 1 / 16,000,000 = 62.5 ns
		256 ticks = 256 x 62.5 ns = 16 micro seconds -> 1 overflow -> 16x 10^-6
		for 1s = 1 / 16 micro seconds = 62500 overflow required for 1s delay
		
	*/
	for (uint16_t i = 0; i < 62500 ; i++)
	{
		while(!(TIFR0 & (1 << TOV0)));
		TIFR0 |= (1 << TOV0);			// Clearing the bit  by writing 1 to it
	}
}
int main(void)
{
    /* Replace with your application code */
	DDRB |= (1 << DDB2);			//PORT Config for led
	PORTB &= ~(1 << PB2);			// Making low during starting
    while (1) 
    {
		PORTB ^= (1 << PB2);
		delay_1s();
    }
}

