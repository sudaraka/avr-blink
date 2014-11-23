/* 01.c: blink the Arduino */

#include <avr/io.h>
#include <util/delay.h>

#define DELAY 100

int main(void)
{
	uint8_t pin = 13;

	DDRB = 0xff;
	PORTB = 0; // Reset

	while(1) {
		for(pin = 1; pin <= (1 << 5); pin <<= 1) {
			PORTB = pin;
			_delay_ms(DELAY);
		}
		for(pin = (1 << 4); pin >= 1; pin >>= 1) {
			PORTB = pin;
			_delay_ms(DELAY);
		}

		PORTB = 0;
		_delay_ms(1000);
	}

	return 0;
}

