/*
 * Led_blink_test.c
 *
 * Created: 19-03-2026 12:14:08
 * Author : HP
 */ 

#include <avr/io.h>
#define F_CPU 1600000UL
#include <util/delay.h>

int main(void)
{
    /* Replace with your application code */
	
	DDRD = 0b0000100;				//PORT pin config - PIN2 output- this is hard code 
    while (1) 
    {
		//PORT pin2 high
		PORTD = 0b00000000;			//set the pin2 as low
		_delay_ms(1000);
		PORTD = 0b00000100;			//set the pin2 as high
		_delay_ms(1000);
    }
}

