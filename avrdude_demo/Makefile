DEVICE     = atmega328p 
CLOCK      = 16000000UL
PROGRAMMER = arduino
PORT       = /dev/tty.usbmodem1421
BAUD       = 115200
FILENAME   = blink
COMPILE    = avr-gcc -Wall -Os -DF_CPU=$(CLOCK) -mmcu=$(DEVICE)

all: usb clean build upload

usb:
	ls /dev/cu.*
    
build:
	$(COMPILE) -c $(FILENAME).c -o $(FILENAME).o
	$(COMPILE) -o $(FILENAME).elf $(FILENAME).o
	avr-objcopy -j .text -j .data -O ihex $(FILENAME).elf $(FILENAME).hex
	avr-size --format=avr --mcu=$(DEVICE) $(FILENAME).elf

upload:
	avrdude -v -p $(DEVICE) -c $(PROGRAMMER) -P $(PORT) -b $(BAUD) -U flash:w:$(FILENAME).hex:i 

clean:
	rm *.o
	rm *.elf
	rm *.hex
