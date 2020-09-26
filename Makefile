# File:   Makefile
# Author: Daniel Watt
# Descr:  Makefile for Towers of Hanoi solver.

# Definitions.
CC = gcc
CFLAGS = -Wall -Wstrict-prototypes -Wextra -g
DEL = rm


# Default target.
all: towers_of_hanoi.out

towers_of_hanoi_functions.o: towers_of_hanoi_functions.c towers_of_hanoi_functions.h
	$(CC) -c $(CFLAGS) $< -o $@

towers_of_hanoi.o: towers_of_hanoi.c towers_of_hanoi_functions.h
	$(CC) -c $(CFLAGS) $< -o $@


towers_of_hanoi.out: towers_of_hanoi.o towers_of_hanoi_functions.o 
	$(CC) $(CFLAGS) $^ -o $@ -lm


# Target: clean project.
.PHONY: clean
clean:
	-$(DEL) *.o *.out *.hex

