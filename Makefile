SHELL = /bin/sh

CC=g++
CFLAGS=-Wall -Werror -c

all: COASt

COASt: COASt.o fileFunctions.o	helpers.o promptFunctions.o storyFunctions.o 
	$(CC) COASt.o fileFunctions.o helpers.o promptFunctions.o storyFunctions.o -o COASt

COASt.o: COASt.c++
	$(CC) $(CFLAGS) COASt.c++

helpers.o: helpers.c++
	$(CC) $(CFLAGS) helpers.c++

fileFunctions.o: fileFunctions.c++
	$(CC) $(CFLAGS) fileFunctions.c++ 

promptFunctions.o: promptFunctions.c++
	$(CC) $(CFLAGS) promptFunctions.c++

storyFunctions.o: storyFunctions.c++
	$(CC) $(CFLAGS) storyFunctions.c++

clean:
	rm -rf *o