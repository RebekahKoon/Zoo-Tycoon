/*********************************************************************
** Program name: project2
** Author:       Rebekah Koon
** Date:         7/12/19
** Description:  Header file for the Penguin class, which is derived
**               and inherits from the Animal class. Keeps track of
**               a penguin's age, cost for buying a penguin, number of
**               babies, payoff, and cost for food.
*********************************************************************/

#ifndef PENGUIN_HPP
#define PENGUIN_HPP

#include "Animal.hpp"

class Penguin: public Animal
{
    public:
        Penguin();
        virtual double calculateFeedingCost(int foodQuality);
};
#endif