## Program name: project2
## Author:       Rebekah Koon
## Date:         7/12/19
## Description:  This program creates a game called Zoo Tycoon in which
##               users run their own zoo. After setting up the zoo, users
##               feed their animals. A random event happens after feeding
##               time. Users also have the option to buy a new animal at
##               the end of the day. The user's profits are then displayed.

project2: Animal.o Penguin.o Turtle.o Tiger.o NewAnimal.o Zoo.o Bank.o Menu.o validInput.o main.o
	g++ -g Animal.o Penguin.o Turtle.o Tiger.o NewAnimal.o Zoo.o Bank.o Menu.o validInput.o main.o -o project2

Animal.o: Animal.cpp Animal.hpp
	g++ -c Animal.cpp

Penguin.o: Penguin.cpp Penguin.hpp
	g++ -c Penguin.cpp

Turtle.o: Turtle.cpp Turtle.hpp
	g++ -c Turtle.cpp

Tiger.o: Tiger.cpp Tiger.hpp
	g++ -c Tiger.cpp

NewAnimal.o: NewAnimal.cpp NewAnimal.hpp
	g++ -c NewAnimal.cpp

Zoo.o: Zoo.cpp Zoo.hpp
	g++ -c Zoo.cpp

Bank.o: Bank.cpp Bank.hpp
	g++ -c Bank.cpp

Menu.o: Menu.cpp Menu.hpp
	g++ -c Menu.cpp

validInput.o: validInput.cpp validInput.hpp
	g++ -c validInput.cpp

main.o: main.cpp
	g++ -c main.cpp

clean:
	rm *.o project2