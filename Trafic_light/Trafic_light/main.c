/*
 * Trafic_light.c
 *
 * Created: 21-03-2026 11:00:27
 * Author : HP
 */ 
#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>

void Red();
void Yellow();
void Green();

int main(void)
{
    /* Replace with your application code */
	DDRD |= ((1<<DD0) | (1<<DD1) | (1<<DD2));		//Set the bit D0,D1,D2 as output
	
    while (1) 
    {
		Red();							//calling the red led function
		_delay_ms(5000);
		Yellow();						//calling the yellow led function
		_delay_ms(2000);
		Green();						//calling the green led function
		_delay_ms(5000);
    }
}

void Red()								//red led function
{
	PORTD |= (1<<PD0);					//set D0 bit as 1
	PORTD &= ~((1<<PD1),(1<<PD2) );		//set D1,D2 bit as 0
}

void Green()							//green led function
{
	PORTD |= (1<<PD2);					//set D2 bit as 1
	PORTD &= ~((1<<PD0),(1<<PD1) );		//set D0,D1 bit as 0
}

void Yellow()							//yellow led function
{
	PORTD |= (1<<PD1);					//set D1 bit as 1
	PORTD &= ~((1<<PD2),(1<<PD0) );		//set D0,D2 bit as 0
}

