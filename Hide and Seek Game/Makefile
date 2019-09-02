# File:   Makefile
# Author: Anna-Kay Cressy, Kelly Esther Ling Ing Chan
# Date:   17 Oct 2018
# Descr:  Makefile for game

# Definitions.
CC = avr-gcc
CFLAGS = -mmcu=atmega32u2 -Os -Wall -Wstrict-prototypes -Wextra -g -I../../drivers/avr -I../../drivers -I../../utils
OBJCOPY = avr-objcopy
SIZE = avr-size
DEL = rm


# Default target.
all: game.out


# Compile: create object files from C source files.
game.o: game.c ../../drivers/avr/system.h ../../drivers/navswitch.h ../../utils/tinygl.h ../../utils/pacer.h ../../drivers/display.h ../../drivers/led.h ../../drivers/ledmat.h      signals.h movement.h positiondisplay.h encoder.h comparison.h endgamedisplay.h
	$(CC) -c $(CFLAGS) $< -o $@

pio.o: ../../drivers/avr/pio.c ../../drivers/avr/pio.h ../../drivers/avr/system.h
	$(CC) -c $(CFLAGS) $< -o $@

system.o: ../../drivers/avr/system.c ../../drivers/avr/system.h
	$(CC) -c $(CFLAGS) $< -o $@

timer.o: ../../drivers/avr/timer.c ../../drivers/avr/system.h ../../drivers/avr/timer.h
	$(CC) -c $(CFLAGS) $< -o $@

display.o: ../../drivers/display.c ../../drivers/avr/system.h ../../drivers/display.h ../../drivers/ledmat.h
	$(CC) -c $(CFLAGS) $< -o $@

ledmat.o: ../../drivers/ledmat.c ../../drivers/avr/pio.h ../../drivers/avr/system.h ../../drivers/ledmat.h
	$(CC) -c $(CFLAGS) $< -o $@

font.o: ../../utils/font.c ../../drivers/avr/system.h ../../utils/font.h
	$(CC) -c $(CFLAGS) $< -o $@

pacer.o: ../../utils/pacer.c ../../drivers/avr/system.h ../../drivers/avr/timer.h ../../utils/pacer.h
	$(CC) -c $(CFLAGS) $< -o $@

prescale.o: ../../drivers/avr/prescale.c ../../drivers/avr/prescale.h ../../drivers/avr/system.h
	$(CC) -c $(CFLAGS) $< -o $@

timer0.o: ../../drivers/avr/timer0.c ../../drivers/avr/bits.h ../../drivers/avr/prescale.h ../../drivers/avr/system.h ../../drivers/avr/timer0.h
	$(CC) -c $(CFLAGS) $< -o $@

ir_uart.o: ../../drivers/avr/ir_uart.c ../../drivers/avr/ir_uart.h ../../drivers/avr/pio.h ../../drivers/avr/system.h ../../drivers/avr/timer0.h ../../drivers/avr/usart1.h
	$(CC) -c $(CFLAGS) $< -o $@

usart1.o: ../../drivers/avr/usart1.c ../../drivers/avr/system.h ../../drivers/avr/usart1.h
	$(CC) -c $(CFLAGS) $< -o $@

tinygl.o: ../../utils/tinygl.c ../../drivers/avr/system.h ../../drivers/display.h ../../utils/font.h ../../utils/tinygl.h
	$(CC) -c $(CFLAGS) $< -o $@

navswitch.o: ../../drivers/navswitch.c ../../drivers/avr/delay.h ../../drivers/avr/pio.h ../../drivers/avr/system.h ../../drivers/navswitch.h
	$(CC) -c $(CFLAGS) $< -o $@

led.o: ../../drivers/led.c ../../drivers/avr/system.h ../../drivers/led.h
	$(CC) -c $(CFLAGS) $< -o $@

movement.o: movement.c movement.h ../../drivers/navswitch.h
	$(CC) -c $(CFLAGS) $< -o $@

encoder.o: encoder.c encoder.h movement.h
	$(CC) -c $(CFLAGS) $< -o $@

comparison.o: comparison.c comparison.h movement.h
	$(CC) -c $(CFLAGS) $< -o $@

endgamedisplay.o: endgamedisplay.c endgamedisplay.h ../../drivers/avr/system.h ../../drivers/ledmat.h
	$(CC) -c $(CFLAGS) $< -o $@

positiondisplay.o: positiondisplay.c positiondisplay.h ../../drivers/display.h
	$(CC) -c $(CFLAGS) $< -o $@

signals.o: signals.c signals.h ../../drivers/avr/system.h  ../../drivers/avr/ir_uart.h
	$(CC) -c $(CFLAGS) $< -o $@

gamestart.o: gamestart.c gamestart.h ../../drivers/avr/system.h ../../utils/tinygl.h ../../utils/font.h ../../utils/pacer.h ../../drivers/navswitch.h signals.h ../../drivers/avr/ir_uart.h ../../drivers/led.h
	$(CC) -c $(CFLAGS) $< -o $@


# Link: create output file (executable) from object files.
game.out: game.o pio.o system.o timer.o display.o ledmat.o font.o pacer.o tinygl.o movement.o positiondisplay.o gamestart.o ir_uart.o usart1.o timer0.o prescale.o signals.o navswitch.o led.o encoder.o comparison.o ledmat.o endgamedisplay.o
	$(CC) $(CFLAGS) $^ -o $@ -lm
	$(SIZE) $@


# Create hex file for programming from executable file.
game.hex: game.out
	$(OBJCOPY) -O ihex game.out game.hex


# Target: clean project.
.PHONY: clean
clean:
	-$(DEL) *.o *.out *.hex


# Target: program project.
.PHONY: program
program: game.hex
	dfu-programmer atmega32u2 erase; dfu-programmer atmega32u2 flash game.hex; dfu-programmer atmega32u2 start


