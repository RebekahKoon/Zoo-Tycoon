/**********************************************************************
** Program name: project2
** Author:       Rebekah Koon
** Date:         7/12/19
** Description:  This program is a game in which the user runs a zoo.
**               Keeps track of the daily progress of the zoo over
**               one year. The program begins by first asking if the
**               user wants to play. If the game is played, user enters
**               how many of each animal (either 1 or 2) they want to
**               begin with. Extra credit has user input their own 
**               animal and its traits as well as food choices for
**               animals at the zoo. User feeds animals with one of
**               three choices for food. One random event occurs each
**               day where either an animal dies, babies are born, a
**               bonus amount of money is made, or no event occurs.
**               Totals profit made at the end of the day. User also
**               has choice to buy a new animal. After one day is over,
**               user can either continue to the next day or quit. If
**               a year has passed or user is out of money, the game
**               is over.
**********************************************************************/

#include "Menu.hpp"
#include "Zoo.hpp"

#include <iostream>
#include <iomanip>

using std::cin;
using std::cout;
using std::endl;

int main()
{
    Menu gameMenu;

    int choice;

    cout << "Note: Extra credit is implemented." << endl;
    cout << "Do you want to play Zoo Tycoon?" << endl;
    choice = gameMenu.startGame();

    //If user wants to play, starts the game
    while (choice == 1)
    {
        Zoo *zooTycoon = new Zoo;

        unsigned seed;
        seed = time(0);
        srand(seed);

        zooTycoon->playGame();

        cout << "Do you want to play again?" << endl;
        choice = gameMenu.startGame();

        delete zooTycoon;
    }

    cout << endl << "Goodbye!" << endl;

    return 0;
}