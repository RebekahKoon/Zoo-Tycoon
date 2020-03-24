/*********************************************************************
** Program name: project2
** Author:       Rebekah Koon
** Date:         7/12/19
** Description:  Header file for the Bank class, which is used to 
**               track a bank account's balance. Has functions to add
**               or subtract money from the bank.
*********************************************************************/

#ifndef BANK_HPP
#define BANK_HPP

#include <iostream>
#include <iomanip>

using std::cout;
using std::endl;
using std::fixed;
using std::showpoint;
using std::setprecision;

class Bank
{
    private:
        double balance;
    
    public:
        Bank();
        void withdrawMoney(double withdrawl);
        void depositMoney(double deposit);
        double getBalance();
};

#endif