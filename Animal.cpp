/*********************************************************************
** Program name: project2
** Author:       Rebekah Koon
** Date:         7/12/19
** Description:  Implementation file for the Animal class. Keeps track
**               of the age, cost, payoff, and amount of babies born
**               for an animal. Calculates the feeding cost of an
**               animal and checks to see if an animal is an adult.
*********************************************************************/

#include "Animal.hpp"


/*********************************************************************
** Description: Default constructor for the Animal class. Sets the
**              age to 1 and the base food cost for an animal.
*********************************************************************/
Animal::Animal()
{
    age = 0;
    cost = 0;
    numberOfBabies = 0;
    baseFoodCost = FOOD_COST_PER_ANIMAL;
    payoff = 0;
}


/*********************************************************************
** Description: Member function getAge returns the age of an animal.
*********************************************************************/
int Animal::getAge()
{
    return age;
}


/*********************************************************************
** Description: Member function getBabies born returns the number
**              of babies that an animal gives birth to.
*********************************************************************/
int Animal::getBabiesBorn()
{
    return numberOfBabies;
}


/*********************************************************************
** Description: Member function getCost returns the cost of an animal.
*********************************************************************/
int Animal::getCost()
{
    return cost;
}



/*********************************************************************
** Description: Member function getPayoff returns how much money an
**              animal makes at the zoo.
*********************************************************************/
double Animal::getPayoff()
{
    return payoff;
}


/*********************************************************************
** Description: Member function setAge takes an integer representing
**              an age as a parameter to set the age variable.
*********************************************************************/
void Animal::setAge(int ageIn)
{
    age = ageIn;
}


/*********************************************************************
** Description: Member function isAdult returns true if the animal
**              is an adult (3 or older) or false if a baby (less 
**              than 3).
*********************************************************************/
bool Animal::isAdult()
{
    bool adult;

    if (age >= 3)
    {
        adult = true;
    }

    else if (age < 3)
    {
        adult = false;
    }

    return adult;
}


/*********************************************************************
** Description: Member function calculateFeedingCost takes an integer
**              as a parameter representing the food's quality. 
**              Calculates cost of food depending on the food's 
**              quality. Returns the cost for food.
*********************************************************************/
double Animal::calculateFeedingCost(int foodQuality)
{
    double feedingCost;

    //Cheap food is half the cost of regular food
    if (foodQuality == CHEAP)
    {
        feedingCost = .5 * baseFoodCost;
    }

    //Generic food is the regular price
    else if (foodQuality == GENERIC)
    {
        feedingCost = baseFoodCost;
    }

    //Premium food is twice the cost of regular food
    else if (foodQuality == PREMIUM)
    {
        feedingCost = 2 * baseFoodCost;
    }

    return feedingCost;
}


/*********************************************************************
** Description: Overloads the ++ operator. Used to increase the age
**              of an animal by 1.
**              Source: https://www.learncpp.com/cpp-tutorial/97-
**              overloading-the-increment-and-decrement-operators/
*********************************************************************/
Animal& Animal::operator++()
{
    ++age;

    return *this;
}