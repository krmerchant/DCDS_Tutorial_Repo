#include <stdio.h>

static unsigned char selector = 0x01;
static unsigned char bit=1;

void shift_bit(void);

int  main(int  argc,char **  argv) {
	int i = 0;
	while( i < 16) {

		shift_bit();
		i++;
	}


}

void shift_bit() {
	
	if( selector & bit) {
		fprintf(stdout, "ON\n");
	} else {
		
		fprintf(stdout, "OFF\n");

	}

	if (bit == 0x80) {
		bit = 0x01;
	} else {

		bit = bit<<0x01;
	}

}

