# Makefile: Arduino Atmega328p

# Program
PROG = 01

# Device
MCU = atmega2560
F_CPU = 16000000UL

# Connection
USB = ttyACM0
#BAUD_RATE = 57600
BAUD_RATE = 115200

# Compiler
CC = avr-gcc
CFLAGS = -Wall -mmcu=$(MCU) -DF_CPU=$(F_CPU)

# Linker
OBJCPY = avr-objcopy
OBJCPYFLAGS = -O ihex -R .eeprom

# Loader
LOADER = sudo avrdude
#LOADERFLAGS = -c arduino -p $(MCU) -b $(BAUD_RATE) -P /dev/$(USB)
LOADERFLAGS = -c stk500v2 -p $(MCU) -b $(BAUD_RATE) -P /dev/$(USB)


all: $(PROG).hex
	$(LOADER) $(LOADERFLAGS) -U flash:w:$<


%.hex: %.o
	$(OBJCPY) $(OBJCPYFLAGS) $< $@


.c.o:
	$(CC) $(CFLAGS) -o $*.o $<

