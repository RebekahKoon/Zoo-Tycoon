/*********************************************************************
** Program name: project2
** Author:       Rebekah Koon
** Date:         7/12/19
** Description:  Header file for the Zoo class. The Zoo class is used
**               to keep track of the zoo's progress. With each day in
**               one year, animals are fed, a random event occurs,
**               profits are calculated, and the player can buy a new
**               animal. If there is no money left, ends the game. If
**               money is left, player can choose to continue to a new
**               day or end the day.
*********************************************************************/

#ifndef ZOO_HPP
#define ZOO_HPP

#include <iostream>
#include <iomanip>
#include <string>
#include <cstdlib>
#include <ctime>

#include "Penguin.hpp"
#include "Turtle.hpp"
#include "Tiger.hpp"
#include "NewAnimal.hpp"
#include "Bank.hpp"
#include "Menu.hpp"
#include "validInput.hpp"

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::fixed;
using std::showpoint;
using std::setprecision;

//Used for buying an animal
enum AnimalSpecies {TURTLE = 1, PENGUIN = 2, TIGER = 3, NEW_ANIM = 4};

class Zoo
{
    private:
        //Max number of each animal in an exhibit
        int maxTurtles;
        int maxPenguins;
        int maxTigers;
        int maxNewAnimals;

        //Number of each animal currently in the zoo
        int numTurtles;
        int numPenguins;
        int numTigers;
        int numNewAnimals;

        Turtle *turtleList;
        Penguin *penguinList;
        Tiger *tigerList;
        NewAnimal *newAnimalList;

        string newAnimalName;

        Bank bankAccount;
        Menu gameMenu;

        void settingUpZoo();
        void ageAnimals(Animal *, int, int &, int &);
        int chooseFoodQuality();
        void buyAnimal();
        double animalProfits(Animal *, int);

        //Random event functions
        double randomEvent(int);
        void sicknessOccurs();
        double zooAttendanceBoom();
        void babyAnimalBorn();
        void noEvent();
        
        //Adding animals; default number added is 1, default age is 3
        void addTurtle(int = 1, int = 3);
        void addPenguin(int = 1, int = 3);
        void addTiger(int = 1, int = 3);
        void addNewAnimal(int = 1, int = 3);
    
    public:
        Zoo();
        void playGame();
        ~Zoo();
};

#endif