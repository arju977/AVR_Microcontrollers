/*
 * alter_led_blink.c
 *
 * Created: 19-03-2026 12:34:53
 * Author : HP
 */ 
#define F_CPU 16000000
#include <util/delay.h>
#include <avr/io.h>


int main(void)
{
	
	DDRD = 0b11111111;						// set the portD pins output
    /* Replace with your application code */
    while (1) 
    {
		PORTD = 0b01010101;					// set the pin 0,2,4,6 as high, other pins low
		_delay_ms(1500);
		PORTD = 0b10101010;					// set the pin 1,3,5,7 as high, other pins low
		_delay_ms(1500);
    }
}

