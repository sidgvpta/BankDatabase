#include "Customer.h"
#include <iostream>
#include <string>
using namespace std;

//constructors

Customer::Customer()
{
    lastName = firstName = address = "";
    customerID = 0;
    next = NULL;
    left = right = NULL;
}

Customer::Customer(string _lastName, string _firstName, int _customerID, string _address)
{
    lastName = _lastName;
    firstName = _firstName;
    customerID = _customerID;
    address = _address;
}

//methods

int Customer::customerCompare(Customer *newCustomer)
{
    int x;
    
    x = (customerID - newCustomer->customerID);
    
    return x;
}

void Customer::printCustomer()
{
    cout << customerID << " ";
    cout << lastName << " ";
    cout << firstName << " ";
    cout << address << " " << endl;
}

//destructor

Customer::~Customer()
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
