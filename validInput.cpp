/*********************************************************************
** Program name: project2
** Author:       Rebekah Koon
** Date:         7/12/19
** Description:  Source file for functions validInput, which takes in
**               two integers representing the minimum and maximum
**               values that can be entered. Determines if user input
**               is valid and returns the user's input as an integer.
**               Also contains another validInput function to see
**               if the user's input for an animal name is valid.
**               Adapted from my project 1 validInput function.
*********************************************************************/

#include "validInput.hpp"

/***********************************************************************
** Description: Function validInput takes as parameters two integers
**              representing the range an integer should be in. Checks 
**              to see if the string is an integer. If it is not a 
**              positive integer or within the specified range, asks 
**              user to reenter answer. If the integer is within range,
**              returns the string as an integer.
**              Source: adapted from my project 1 assignment.
***********************************************************************/
int validInput(int minNumber, int maxNumber)
{
    bool valid;
    int numberInt;
    string answer;

    do
    {
        getline(cin, answer);
        valid = true;

        //Checking to see if the string is a positive integer
        for (int i = 0; i < answer.length(); i++)
        {
            if (!isdigit(answer[i]))
            {
                valid = false;
            } 
        }

        if (valid)
        {
            //Converting to an integer to check if it's in the min/max range
            numberInt = atoi(answer.c_str());

            //Checking to see if the integer is between the min/max range
            if (numberInt < minNumber || numberInt > maxNumber)
            {
                valid = false;
            }
        }
        if (!valid)
        {
            cout << "Please only type integers from "
                 << minNumber << " to " << maxNumber << ": ";
        }
    } while (valid == false);

    return numberInt;
}


/***********************************************************************
** Description: validInput gets user input concerning the name of a new
**              animal. Asks user to reenter input if not valid. Returns
**              the user's answer after validating input.
**              Source: Adapted from project 1 validInput function
***********************************************************************/
string validInput()
{
    bool valid;
    string answer;

    do
    {
        getline(cin, answer);
        valid = true;

        //If string is empty
        if (answer.empty())
        {
            valid = false;
        }

        //If answer only contains whitespace
        if (answer.find_first_not_of(' ') == string::npos)
        {
            valid = false;
        }

        //Reentering if not valid
        if (!valid)
        {
            cout << "Please enter a name: ";
        }
    } while (valid == false);
    
    return answer;
}