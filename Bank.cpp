/*********************************************************************
** Program name: project2
** Author:       Rebekah Koon
** Date:         7/12/19
** Description:  Implementation file for the Bank class, which is used
**               to track a bank account's balance. Has functions to
**               add or subtract money from the bank.
*********************************************************************/

#include "Bank.hpp"

/*********************************************************************
** Description: Default constructor for the Bank class, which sets the
**              bank account's balance to 100000.
*********************************************************************/
Bank::Bank()
{
    balance = 100000;
}


/*********************************************************************
** Description: Void member function withdrawMoney takes in a double
**              as a parameter for the amount to withdraw. Subtracts
**              this amount from the account balance.
*********************************************************************/
void Bank::withdrawMoney(double withdrawal)
{
    //Taking money out of account
    balance -= withdrawal;

    cout << fixed << showpoint << setprecision(2);
    cout << "Took out $" << withdrawal << " from account." << endl << endl;
}


/*********************************************************************
** Description: Void member function depositMoney takes in a double as
**              a parameter for the amount to deposit. Adds this
**              amount to the account balance.
*********************************************************************/
void Bank::depositMoney(double deposit)
{
    //Putting money into account
    balance += deposit;

    cout << fixed << showpoint << setprecision(2);
    cout << "Added $" << deposit << " to account." << endl ;

    cout << "New balance: $" << getBalance() << endl << endl;
}


/*********************************************************************
** Description: Member function getBalance returns the balance of 
**              a bank account.
*********************************************************************/
double Bank::getBalance()
{
    return balance;
}