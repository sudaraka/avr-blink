/* 02.c: input */

#include <avr/io.h>
#include <util/delay.h>

int main(void)
{
	DDRD &= 0xfb;
	DDRB = 0xff;

	PORTB = 0; // Reset
	PORTD |= 0x04;

	while(1) {
		if(PIND & 0x04) {
			PORTB = 1;
		}
		else {
			PORTB = 0;
		}
	}

	/*while(1) {*/
		/*for(pin = 1; pin <= (1 << 5); pin <<= 1) {*/
			/*PORTB = pin;*/
			/*_delay_ms(DELAY);*/
		/*}*/
		/*for(pin = (1 << 4); pin >= 1; pin >>= 1) {*/
			/*PORTB = pin;*/
			/*_delay_ms(DELAY);*/
		/*}*/

		/*PORTB = 0;*/
		/*_delay_ms(1000);*/
	/*}*/

	return 0;
}

