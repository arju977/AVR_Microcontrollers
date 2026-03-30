/*
 * pull_up_switch_led.c
 *
 * Created: 21-03-2026 20:15:44
 * Author : HP
 */ 

#include <avr/io.h>
#define F_CPU 16000000UL
#include <util/delay.h>

int main(void)
{
	DDRD &= ~(1<<DDD2);			// config the pin D2 as input 
	PORTD |= (1 << PD2);		// enabling internal pull-up
	DDRC |= (1<<DDC2);			// config the pin C2 as output
    
	// for activating the internal pull-up first set as input the give high value 
    while (1) 
    {
		// check if the switch is pressed
		if (!(PIND & (1<<PIND2)))		//not operator to reverse the current value
		{
			PORTC ^=(1<<PC2);	
			while(!(PIND & (1 << PIND2)));			//polling method
		}
		/*else
		{
			PORTC &= ~(1<<PC2);
			
		}
		*/
    }
}

