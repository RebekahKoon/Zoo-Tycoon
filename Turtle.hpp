/*********************************************************************
** Program name: project2
** Author:       Rebekah Koon
** Date:         7/12/19
** Description:  Header file for the Turtle class, which is derived
**               and inherits from the Animal class. Keeps track of
**               a turtle's age, cost for buying a turtle, number of
**               babies, payoff, and cost for food.
*********************************************************************/

#ifndef TURTLE_HPP
#define TURTLE_HPP

#include "Animal.hpp"

class Turtle: public Animal
{
    public:
        Turtle();
        virtual double calculateFeedingCost(int foodQuality);
};

#endif