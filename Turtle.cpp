/*********************************************************************
** Program name: project2
** Author:       Rebekah Koon
** Date:         7/12/19
** Description:  Implementation file for the Turtle class, which is
**               derived and inherits from the Animal class. Keeps 
**               track of a turtle's age, cost for buying a turtle,
**               number of babies, payoff, and cost for food.
*********************************************************************/

#include "Turtle.hpp"


/*********************************************************************
** Description: Default constructor for the Turtle class. Uses Animal
**              class to set age, cost, number of babies, payoff, 
**              and food cost.
*********************************************************************/
Turtle::Turtle(): Animal()
{
    cost = 100;
    numberOfBabies = 10;
    payoff = .05 * cost;
}


/*********************************************************************
** Description: Member function calculateFeedingCost takes an integer
**              as a parameter representing the food's quality. 
**              Calculates the cost of food depending on the food's 
**              quality. Returns the cost for food.
*********************************************************************/
double Turtle::calculateFeedingCost(int foodQuality)
{
    double feedingCost;

    //Cheap food is half the cost of regular food
    if (foodQuality == CHEAP)
    {
        //Turtle food is half the cost of base food
        feedingCost = .5 * (baseFoodCost * .5);
    }

    //Generic food is the regular price
    else if (foodQuality == GENERIC)
    {
        //Turtle food is half the cost of base food
        feedingCost = (baseFoodCost * .5);
    }

    //Premium food is twice the cost of regular food
    else if (foodQuality == PREMIUM)
    {
        //Turtle food is half the cost of base food
        feedingCost = 2 * (baseFoodCost * .5);
    }

    return feedingCost;
}