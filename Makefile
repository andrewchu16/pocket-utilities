CC = g++
CFLAGS = -Wall

all: p-utils

%.o: src/%.cpp # include/%.h
	$(CC) -c $^ -Iinclude

p-utils: p-utils-lib.o big_int.o error.o src/main.cpp
	$(CC) $(CFLAGS) -o $@ $^ -Iinclude

clean:
	rm *.o p-utils