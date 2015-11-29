#include "Account.h"
#include <iostream>
#include <string>
using namespace std;

//contructors

Account::Account()
{
    customerID = accountID = balance = 0;
    next = NULL;
    left = right = NULL;
}

Account::Account(int _customerID, int _accountID, int _balance)
{
    customerID = _customerID;
    accountID = _accountID;
    balance = _balance;
}

//methods

int Account::accountCompare(Account *newAccount)
{
    int x;
    
    x = (accountID - newAccount->accountID);
    
    return x;
}

//destructor

Account::~Account()
{
    if (left != NULL)
    {
        delete left;
    }
    if (right != NULL)
    {
        delete right;
    }
}