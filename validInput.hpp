/*********************************************************************
** Program name: project2
** Author:       Rebekah Koon
** Date:         7/12/19
** Description:  Header file for functions validInput, which takes in
**               two integers representing the minimum and maximum
**               values that can be entered. Determines if user input
**               is valid and returns the user's input as an integer.
**               Also contains another validInput function to see
**               if the user's input for an animal name is valid.
**               Adapted from my project 1 validInput function.
*********************************************************************/

#ifndef VALID_INPUT_HPP
#define VALID_INPUT_HPP

#include <iostream>
#include <string>
#include <cstdlib>
#include <algorithm>

using std::atoi;
using std::cin;
using std::cout;
using std::endl;
using std::getline;
using std::string;
using std::transform;

int validInput(int, int);
double validInput(double, double);
string validInput();

#endif