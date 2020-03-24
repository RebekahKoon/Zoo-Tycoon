/*********************************************************************
** Program name: project2
** Author:       Rebekah Koon
** Date:         7/12/19
** Description:  Header file for the Menu class, which contains
**               functions for different menus related to project 2,
**               such as a menu to start the game, give animal prices,
**               purchase animals, buy food, and continue the game.
**               Adapted from menu function in project1.
*********************************************************************/

#ifndef MENU_HPP
#define MENU_HPP

#include <iostream>
#include "validInput.hpp"

using std::cout;
using std::cin;
using std::endl;

class Menu
{
    public:
        int startGame();
        void animalPrices();
        int purchaseAnimals(string, int);
        int chooseFoodQuality();
        int continueGame();
};

#endif