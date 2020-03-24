/*********************************************************************
** Program name: project2
** Author:       Rebekah Koon
** Date:         7/12/19
** Description:  Header file for the Animal class. Keeps track of the
**               age, cost, payoff, and amount of babies born for an
**               animal. Also calculates the feeding cost of an animal
**               and checks to see whether an animal is an adult.
*********************************************************************/

#ifndef ANIMAL_HPP
#define ANIMAL_HPP

const int FOOD_COST_PER_ANIMAL = 10;

//Used to determine price of food for an animal
enum FoodType {CHEAP = 1, GENERIC = 2, PREMIUM = 3};

class Animal
{
    protected:
        int age;
        double cost;
        int numberOfBabies;
        int baseFoodCost;
        double payoff;
    
    public:
        Animal();

        int getAge();
        int getBabiesBorn();
        int getCost();
        double getPayoff();

        void setAge(int);
        bool isAdult();
        virtual double calculateFeedingCost(int foodQuality);
        
        Animal& operator++();
};

#endif