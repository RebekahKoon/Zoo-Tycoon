/*********************************************************************
** Program name: project2
** Author:       Rebekah Koon
** Date:         7/12/19
** Description:  Implementation file for the Penguin class, which is
**               derived and inherits from the Animal class. Keeps 
**               track of a penguin's age, cost for buying a penguin,
**               number of babies, payoff, and cost for food.
*********************************************************************/

#include "Penguin.hpp"


/*********************************************************************
** Description: Default constructor for the Penguin class. Uses Animal
**              class to set age, cost, number of babies, payoff, 
**              and food cost.
*********************************************************************/
Penguin::Penguin(): Animal()
{
    cost = 1000;
    numberOfBabies = 5;
    payoff = .1 * cost;
}


/*********************************************************************
** Description: Member function calculateFeedingCost takes an integer
**              as a parameter representing the food's quality. 
**              Calculates the cost of food depending on the food's 
**              quality. Returns the cost for food.
*********************************************************************/
double Penguin::calculateFeedingCost(int foodQuality)
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