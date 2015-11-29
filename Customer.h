#ifndef ___E3_Project__Customer__
#define ___E3_Project__Customer__

#include <stdio.h>
#include <iostream>
#include <string>
using namespace std;

class Customer
{
public:
    
    //publicly declared variables
    string lastName;
    string firstName;
    int customerID;
    string address;
    
    //LINKED LIST: next customer pointer
    Customer *next;
    
    //BINARY SEARCH TREE: left and right customer pointers
    Customer *left;
    Customer *right;
    
    //constructors
    Customer();
    Customer(string _lastName, string _firstName, int _customerID, string _address);
    
    //methods
    int customerCompare(Customer *newCustomer);
    void printCustomer();
    
    //destructor
    ~Customer();
    
};

#endif /* defined(___E3_Project__Customer__) */
