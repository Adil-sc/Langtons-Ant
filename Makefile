###
### @author - Adil Chaudhry <chaudhra@oregonstate.edu>
### @description - Makefile for Project1  
###

CFLAGS = -std=c++11

Project1: main.o Ant.o inputValidation.o Menu.o moveAnt.o printBoard.o
	g++ $(CFLAGS) main.o Ant.o inputValidation.o Menu.o moveAnt.o printBoard.o -o Project1


main.o: main.cpp
	g++ $(CFLAGS) -c main.cpp

Ant.o: Ant.cpp Ant.h
	g++ -c Ant.cpp
	
moveAnt.o: moveAnt.cpp moveAnt.h
	g++ -c moveAnt.cpp
	
printBoard.o: printBoard.cpp printBoard.h
	g++ -c printBoard.cpp
	
inputValidation.o: inputValidation.cpp inputValidation.h
	g++ -c inputValidation.cpp

Menu.o: Menu.cpp Menu.h
	g++ -c Menu.cpp
	

	
clean:
	rm *.o Project1