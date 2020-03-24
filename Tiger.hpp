/*********************************************************************
** Program name: project2
** Author:       Rebekah Koon
** Date:         7/12/19
** Description:  Header file for the Tiger class, which is derived
**               and inherits from the Animal class. Keeps track of
**               a tiger's age, cost for buying a tiger, number of
**               babies, payoff, and cost for food.
*********************************************************************/


#ifndef TIGER_HPP
#define TIGER_HPP

#include "Animal.hpp"

class Tiger: public Animal
{
    public:
        Tiger();
        virtual double calculateFeedingCost(int foodQuality);
};

#endif