CC = g++
CFLAGS = -Wall

all: p-utils

p-utils: main.cpp p-utils-lib.h
	$(CC) $(CFLAGS) -o p-utils

clean:
	rm *.o p-utils