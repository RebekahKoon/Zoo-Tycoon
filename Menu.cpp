/*********************************************************************
** Program name: project2
** Author:       Rebekah Koon
** Date:         7/12/19
** Description:  Implemenation file for the Menu class, which contains
**               functions for different menus related to project 2,
**               such as a menu to start the game, give animal prices,
**               purchase animals, buy food, and continue the game.
**               Adapted from menu function in project1.
*********************************************************************/

#include "Menu.hpp"


/*********************************************************************
** Description: Member function startGame asks the user whether they
**              want to play Zoo Tycoon. Returns 1 if the user wants
**              to play or 2 if they want to quit.
*********************************************************************/
int Menu::startGame()
{
    bool validChoice;
    int choice;
    const int CHOICE_MIN = 1,
              CHOICE_MAX = 2;

    cout << "1. Play the Game" << endl;
    cout << "2. Quit" << endl << endl;
    cout << "Please enter either 1 or 2 to perform your choice: ";

    //Calling validInput to see if the user entered 1 or 2
    choice = validInput(CHOICE_MIN, CHOICE_MAX);

    return choice;
}


/*********************************************************************
** Description: Void member function animalPrices lists the prices for
**              each animal being sold.
*********************************************************************/
void Menu::animalPrices()
{
    cout << "One turtle cost $100." << endl;
    cout << "One penguin cost $1,000." << endl;
    cout << "One tiger cost $10,000." << endl;
}


/*********************************************************************
** Description: Member function purchaseAnimals takes in the new 
**              animal's name and cost as parameters. Asks the user if
**              they want to buy a new animal. Returns the player's
**              choice as an integer.
*********************************************************************/
int Menu::purchaseAnimals(string newAnimName, int newAnimalCost)
{
    bool validChoice;
    int choice;
    const int CHOICE_MIN = 1,
              CHOICE_MAX = 5;

    cout << "Do you want to purchase a new animal?" << endl;

    //Listing prices of each animal
    animalPrices();
    cout << "One " << newAnimName << " costs $" << newAnimalCost << "."
         << endl << endl;
    
    cout << "1. Purchase a turtle." << endl;
    cout << "2. Purchase a penguin." << endl;
    cout << "3. Purchase a tiger." << endl;
    cout << "4. Purchase a " << newAnimName << "." << endl;
    cout << "5. Do not purchase a new animal." << endl << endl;
    cout << "Please enter your choice (either 1-5): ";

    //Calling validInput to see if the user entered 1 or 2
    choice = validInput(CHOICE_MIN, CHOICE_MAX);

    return choice;
}


/*********************************************************************
** Description: Member function foodQuality asks the user what type
**              of food the animals should be fed. Returns the user's
**              choice as an integer.
*********************************************************************/
int Menu::chooseFoodQuality()
{
    int choice;
    const int CHOICE_MIN = 1,
              CHOICE_MAX = 3;

    cout << "The food choices are: " << endl;
    cout << "1. Cheap food: Half price, but sickness is more likely." << endl;
    cout << "2. Generic food: Ordinary food, no effect on health." << endl;
    cout << "3. Premium: Twice the cost, but healthier for animals." << endl;
    cout << endl << "Please enter your choice (either 1-3): ";

    choice = validInput(CHOICE_MIN, CHOICE_MAX);

    //Determining what kind of food will be fed to the animals
    if (choice == 1)
    {
        cout << "The animals will be fed with the cheap food brand." << endl;
    }

    else if (choice == 2)
    {
        cout << "The animals will be fed with the generic food brand." << endl;
    }

    else if (choice == 3)
    {
        cout << "The animals will be fed with the premium food brand." << endl;
    }

    return choice;
}


/*********************************************************************
** Description: Member function continueGame asks the user if they 
**              want to continue to a new day. Returns 1 if the user
**              wants to continue or 2 if they want to quit.
*********************************************************************/
int Menu::continueGame()
{
    bool validChoice;
    int choice;
    const int CHOICE_MIN = 1,
              CHOICE_MAX = 2;

    cout << "Do you want to continue to a new day?" << endl;
    cout << "1. Start a new day" << endl;
    cout << "2. Quit playing" << endl << endl;
    cout << "Please enter either 1 or 2 to perform your choice: ";

    //Calling validInput to see if the user entered 1 or 2
    choice = validInput(CHOICE_MIN, CHOICE_MAX);

    return choice;
}