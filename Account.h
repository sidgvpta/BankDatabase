#ifndef ___E3_Project__Account__
#define ___E3_Project__Account__

#include <stdio.h>
#include <iostream>
#include <string>
using namespace std;

class Account
{
public:
    
    //publicly declared variables
    int customerID;
    int accountID;
    int balance;
    
    ////LINKED LIST: next account pointer
    Account *next;
    
    //BINARY SEARCH TREE: left and right account pointers
    Account *left;
    Account *right;
    
    //contructors
    Account();
    Account(int _customerID, int _accountID, int _balance);
    
    //methods
    int accountCompare(Account *newAccount);
    
    //destructor
    ~Account();
    
};

#endif /* defined(___E3_Project__Account__) */
