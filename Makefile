SHELL = /bin/sh

CC=g++
CFLAGS=-Wall -Werror -c

all: COASt

COASt: COASt.o fileFunctions.o	helpers.o promptFunctions.o storyFunctions.o 
	$(CC) COASt.o fileFunctions.o helpers.o promptFunctions.o storyFunctions.o -o COASt

COASt.o: COASt.c++
	$(CC) COASt.c++ $(CFLAGS) 

helpers.o: helpers.c++
	$(CC) helpers.c++ $(CFLAGS) 

fileFunctions.o: fileFunctions.c++
	$(CC) fileFunctions.c++ $(CFLAGS) 

promptFunctions.o: promptFunctions.c++
	$(CC) promptFunctions.c++ $(CFLAGS) 

storyFunctions.o: storyFunctions.c++
	$(CC) storyFunctions.c++ $(CFLAGS) 

clean:
	rm -rf *o