/*tration on how to redirect stdio to UART. 
 *
 * http://appelsiini.net/2011/simple-usart-with-avr-libc
 *
 * To compile and upload run: make clean; make; make program;
 * Connect to serial with: screen /dev/tty.usbserial-*
 *
 * Copyright 2011 Mika Tuupola
 * Licensed under the MIT license:
 *   http://www.opensource.org/licenses/mit-license.php
 *
 */
 
#include <stdio.h>
#include <avr/io.h>
#include "uart.h"
#include <util/delay.h>

#define BLINK_DELAY 10000
int main(void) {    

	//set up serial communication
    uart_init();
    stdout = &uart_output;
    stdin  = &uart_input;
    
	//set pin as input
	DDRB  = 0x00;
	PORTB = 0x00;	            


	

    while(1) {
    	

		fprintf(stdout, "Sensor reading:/n");
		_delay_ms(1000);
	}

        
    return 0;
}
