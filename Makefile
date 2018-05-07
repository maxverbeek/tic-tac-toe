CC=gcc
CFLAGS=-g -Wall

INCLUDE=io.h minimax.h
OBJECTS=main.o io.o minimax.o

remakerun: clean build
	./game

build: ${OBJECTS} ${INCLUDE}
	${CC} ${CFLAGS} -o game ${OBJECTS}

clean: 
	rm -f *.o
	rm -f game
