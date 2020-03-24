/*********************************************************************
** Program name: project2
** Author:       Rebekah Koon
** Date:         7/12/19
** Description:  Header file for the NewAnimal class, which is derived
**               and inherits from the Animal class. NewAnimal is an
**               animal selected by the user to put in the zoo. Keeps 
**               track of its age, cost for buying the new animal,
**               number of babies, payoff, and cost for food.
*********************************************************************/

#ifndef NEW_ANIMAL_HPP
#define NEW_ANIMAL_HPP

#include "Animal.hpp"
#include "validInput.hpp"

#include <string>
#include <iostream>

using std::cin;
using std::cout;
using std::endl;
using std::string;

class NewAnimal: public Animal
{
    private:
        string newAnimalName;
        double newAnimalFoodCost;
    public:
        NewAnimal();
        void pickNewAnimal();

        void setName(string);
        void setCost(double);
        void setBabies(int);
        void setFoodCost(double);
        void setPayoff(int);
        
        string getName();
        virtual double calculateFeedingCost(int);
};

#endif