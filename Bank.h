#ifndef ___E3_Project__Bank__
#define ___E3_Project__Bank__

#include <stdio.h>
#include "Customer.h"
#include "Account.h"
#include <iostream>
#include <string>
using namespace std;

class Bank
{
private:
    
    //LINKED LIST: CUSTOMERS
    Customer *chead;
    int ccurrentlyInList;
    int ccomparisonsLL;
    
    //BINARY SEARCH TREE: CUSTOMERS
    Customer *croot;
    int ccomparisonsBST;
    
        //BST private search function
    Customer* privateSearchCustomer(Customer *x, int _customerID);
    
    //LINKED LIST: ACCOUNTS
    Account *ahead;
    int acurrentlyInList;
    int acomparisons;
    int totalaccountsbalance;
    
    //BINARY SEARCH TREE: ACCOUNTS
    Account *aroot;
    
public:
    
    //default constructor
    Bank();
    
    
    //LINKED LIST: CUSTOMER METHODS
    int getccurrentlyInList();
    void addCustomer(Customer *_newCustomer);
    void search(int _customerID);
    int getNumberOfComparisonsLL();
        //void write(string fn);
        //void writeCustomer(Customer *x);
    
    
    //BINARY SEARCH TREE: CUSTOMER METHODS
    void addCustomerBST(Customer *_newCustomer);
    Customer* publicSearchCustomer(int _customerID);
    int getNumberOfComparisonsBST();
    
    
    //LINKED LIST: ACCOUNT METHODS
    int getTotalAccountsBalance();
    int getacurrentlyInList();
    void addAccount(Account *_newAccount);
    
    
    //BINARY SEARCH TREE: ACCOUNT METHODS
    void addAccountBST(Account *_newAccount);
    
    //destructor
    ~Bank();
};

#endif /* defined(___E3_Project__Bank__) */
