#include "Bank.h"
#include "Customer.h"
#include "Account.h"
#include <iostream>
#include <string>
using namespace std;

//default constructor
Bank::Bank()
{
    chead = croot = NULL;
    ahead = aroot = NULL;
    
    ccurrentlyInList = acurrentlyInList = 0;
    
    ccomparisons = acomparisons = 0;
    
    totalaccountsbalance = 0;
}

//LINKED LIST: CUSTOMER METHODS
int Bank::getccurrentlyInList()
{
    return ccurrentlyInList;
}

int Bank::getacurrentlyInList()
{
    return acurrentlyInList;
}

int Bank::getTotalAccountsBalance()
{
    return totalaccountsbalance;
}

void Bank::addCustomer(Customer *_newCustomer)
{
    if ((chead == NULL) || (_newCustomer->customerCompare(chead) <= 0))
    {
        _newCustomer->next = chead;
        chead = _newCustomer;
            //cout << "Customer successfully added as new head." << endl;
            //_newCustomer->printCustomer();
        ccurrentlyInList++;
        return;
    }
    
    Customer *ccurrent = chead;
    
    while (((ccurrent->next) != NULL) && ((_newCustomer->customerCompare(ccurrent->next)) > 0))
    {
        ccurrent = ccurrent->next;
            //cout << "Finding insertion position..." << endl;
    }
    
    _newCustomer->next = ccurrent->next;
    ccurrent->next = _newCustomer;
        //cout << "Customer added successfully." << endl;
        //_newCustomer->printCustomer();
    ccurrentlyInList++;
}

/*
 void Bank::writeCustomer(Customer *x)
 {
 x->printCustomer();
 }
 */

void Bank::search(int _customerID)
{
    bool check = false;
    Customer *current = chead;
    
    while ((current->next) != NULL)
    {
        if ((current->customerID) == _customerID)
        {
            cout << "Customer found. Details:" << endl;
            check = true;
            current->printCustomer();
            return;
        }
        else
        {
            current = current->next;
        }
    }
    if (check == false)
    {
        cout << "ERROR: Invalid Customer ID." << endl;
    }
}

//BINARY SEARCH TREE: CUSTOMER METHODS
void Bank::addCustomerBST(Customer *_newCustomer)
{
    Customer *current;
    Customer *previous;
    
    if (croot == NULL)
    {
        croot = _newCustomer;
            //cout << "Customer added successfully as new root." << endl;
        ccurrentlyInList++;
    }
    
    else
    {
        current = croot;
        previous = NULL;
        
        while (current != NULL)
        {
            previous = current;
            
            if ((_newCustomer->customerCompare(current)) > 0)
            {
                current = current->right;
            }
            else
            {
                current = current ->left;
            }
        }
        
        if ((_newCustomer->customerCompare(previous)) > 0)
        {
            previous->right = _newCustomer;
                //cout << "Customer added successfully." << endl;
            ccurrentlyInList++;
        }
        else
        {
            previous->left = _newCustomer;
                //cout << "Customer added successfully." << endl;
            ccurrentlyInList++;
        }
    }
}

Customer *Bank::privateSearchCustomer(Customer *_x, int _customerID) //helper method
{
    if (_x == NULL)
    {
        return NULL;
    }
    
    if (_x->customerID == _customerID)
    {
        return _x;
    }
    
    if (_customerID < _x->customerID)
    {
        return privateSearchCustomer(_x->left, _customerID);
    }
    
    return privateSearchCustomer(_x->right, _customerID);
}


Customer* Bank::publicSearchCustomer(int _customerID)
{
    return privateSearchCustomer(croot, _customerID);
}

//LINKED LIST: ACCOUNT METHODS
void Bank::addAccount(Account *_newAccount)
{
    if ((ahead == NULL) || (_newAccount->accountCompare(ahead) <= 0))
    {
        _newAccount->next = ahead;
        ahead = _newAccount;
            //cout << "Account successfully added as new head." << endl;
            //_newAccount->printAccount();
        totalaccountsbalance = totalaccountsbalance + (_newAccount->balance);
        acurrentlyInList++;
        return;
    }
    
    Account *acurrent = ahead;
    
    while (((acurrent->next) != NULL) && ((_newAccount->accountCompare(acurrent->next)) > 0))
    {
        acurrent = acurrent->next;
            //cout << "Finding insertion position..." << endl;
    }
    
    _newAccount->next = acurrent->next;
    acurrent->next = _newAccount;
        //cout << "Account added successfully." << endl;
        //_newAccount->printAccount();
    totalaccountsbalance = totalaccountsbalance + (_newAccount->balance);
    acurrentlyInList++;
}

//BINARY SEARCH TREE: ACCOUNT METHODS
void Bank::addAccountBST(Account *_newAccount)
{
    Account *current;
    Account *previous;
    
    if (aroot == NULL)
    {
        aroot = _newAccount;
        totalaccountsbalance = totalaccountsbalance + (_newAccount->balance);
        acurrentlyInList++;
    }
    
    else
    {
        current = aroot;
        previous = NULL;
        
        while (current != NULL)
        {
            previous = current;
            
            if ((_newAccount->accountCompare(current)) > 0)
            {
                current = current->right;
            }
            else
            {
                current = current ->left;
            }
        }
        
        if ((_newAccount->accountCompare(previous)) > 0)
        {
            previous->right = _newAccount;
            totalaccountsbalance = totalaccountsbalance + (_newAccount->balance);
            acurrentlyInList++;
        }
        else
        {
            previous->left = _newAccount;
            totalaccountsbalance = totalaccountsbalance + (_newAccount->balance);
            acurrentlyInList++;
        }
    }

}

//destructor
Bank::~Bank()
{
    while (chead != NULL)
    {
        Customer *current;
        current = chead->next;
        delete chead;
        chead = current;
    }
}
