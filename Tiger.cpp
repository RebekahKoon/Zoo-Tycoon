/*********************************************************************
** Program name: project2
** Author:       Rebekah Koon
** Date:         7/12/19
** Description:  Implementation file for the Tiger class, which is
**               derived and inherits from the Animal class. Keeps 
**               track of a tiger's age, cost for buying a tiger,
**               number of babies, payoff, and cost for food.
*********************************************************************/

#include "Tiger.hpp"

/*********************************************************************
** Description: Default constructor for the Tiger class. Uses Animal
**              class to set age, cost, number of babies, payoff, 
**              and food cost.
*********************************************************************/
Tiger::Tiger(): Animal()
{
    cost = 10000;
    numberOfBabies = 1;
    payoff = .2 * cost;
}


/*********************************************************************
** Description: Member function calculateFeedingCost takes an integer
**              as a parameter representing the food's quality. 
**              Calculates the cost of food depending on the food's 
**              quality. Returns the cost for food.
*********************************************************************/
double Tiger::calculateFeedingCost(int foodQuality)
{
    double feedingCost;

    //Cheap food is half the price of regular food
    if (foodQuality == CHEAP)
    {
        //Tiger food is five times the price of base food
        feedingCost = .5 * (baseFoodCost * 5);
    }

    //Generic food is the regular price
    else if (foodQuality == GENERIC)
    {
        //Tiger food is five times the price of base food
        feedingCost = (baseFoodCost * 5);
    }

    //Premium food is twice the price of regular food
    else if (foodQuality == PREMIUM)
    {
        //Tiger food is five times the price of base food
        feedingCost = 2 * (baseFoodCost * 5);
    }

    return feedingCost;
}