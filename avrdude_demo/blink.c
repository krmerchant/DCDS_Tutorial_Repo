#include <avr/io.h>
#include <util/delay.h>
#define BLINK_DELAY_MS 100

int main(void) {
    //Set pin 5 @ output
    DDRB |= _BV(DDB4);
    
    while(1) {
        
        //Switch on light
        PORTB |= _BV(PORTB4);
        _delay_ms(BLINK_DELAY_MS);
    
        //Swithc off light
        PORTB &= ~_BV(PORTB4);
        _delay_ms(BLINK_DELAY_MS);

    }

}
