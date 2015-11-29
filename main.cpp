#include "Bank.h"
#include "Customer.h"
#include "Account.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
    Bank bank1; //this bank uses linked lists for its customers and accounts.
    
    cout << "--BANK DATABASE IMPLEMENTED USING LINKED LISTS--" << endl << endl;
    
    //CUSTOMER LINKED LIST
    
    ifstream in1;
    in1.open("customers0.txt");
    if (in1.fail())
    {
        cout << "unable to open customers0.txt" << endl;
        return 0;
    }
    while (!in1.eof())
    {
        Customer *newCustomer = new Customer();
        in1 >> (newCustomer -> customerID) >> (newCustomer -> lastName);
        in1 >> (newCustomer -> firstName) >> (newCustomer -> address);
        
        bank1.addCustomer(newCustomer);
    }
    in1.close();
    
    int totalcustomers = bank1.getccurrentlyInList();
    
    cout << "Total number of customers: " << totalcustomers << endl;
    
    
    //ACCOUNT LINKED LIST
    
    
    ifstream in2;
    in2.open("accounts0.txt");
    if (in2.fail())
    {
        cout << "unable to open accounts0.txt" << endl;
        return 0;
    }
    while (!in2.eof())
    {
        Account *newAccount = new Account();
        in2 >> (newAccount -> accountID) >> (newAccount -> customerID);
        in2 >> (newAccount -> balance);
        
        bank1.addAccount(newAccount);
    }
    in2.close();
    
    int totalaccounts = bank1.getacurrentlyInList();
    
    cout << "Total number of accounts: " << totalaccounts << endl;
    
    int totalbalance = bank1.getTotalAccountsBalance();
    
    cout << "Total Accounts Balance: " << totalbalance << " cents" << endl;
    
    int customerIDSearch;
    cout << "Enter Customer ID: ";
    cin >> customerIDSearch;
    bank1.search(customerIDSearch); //this search function calls the printCustomer() function within it.
    
    
    //----------------------------------------------------------------------------------------
    //----------------------------------------------------------------------------------------
    
    
    Bank bank2; //this bank uses binary search trees for its customers and accounts.
    
    cout << endl << "--BANK DATABASE IMPLEMENTED USING BINARY SEARCH TREES--" << endl << endl;
    
    //CUSTOMER BINARY SEARCH TREE
    
    ifstream in3;
    in3.open("customers0.txt");
    if (in3.fail())
    {
        cout << "unable to open customers0.txt" << endl;
        return 0;
    }
    while (!in3.eof())
    {
        Customer *newCustomer = new Customer();
        in3 >> (newCustomer -> customerID) >> (newCustomer -> lastName);
        in3 >> (newCustomer -> firstName) >> (newCustomer -> address);
        
        
            //The following two lines of code prints out the details of every customer added (used for debugging purposes)
        
            //cout << newCustomer->customerID << " " << newCustomer->lastName << " ";
            //cout << newCustomer->firstName << " " <<newCustomer->address << endl;
        
        bank2.addCustomerBST(newCustomer);
    }
    in3.close();
    
    totalcustomers = bank2.getccurrentlyInList();
    
    cout << "Total number of customers: " << totalcustomers << endl;
    
    
    //ACCOUNT BINARY SEARCH TREE
    
    
    ifstream in4;
    in4.open("accounts0.txt");
    if (in4.fail())
    {
        cout << "unable to open accounts0.txt" << endl;
        return 0;
    }
    while (!in4.eof())
    {
        Account *newAccount = new Account();
        in4 >> (newAccount -> accountID) >> (newAccount -> customerID);
        in4 >> (newAccount -> balance);
        
        bank2.addAccountBST(newAccount);
    }
    in4.close();
    
    totalaccounts = bank2.getacurrentlyInList();
    
    cout << "Total number of accounts: " << totalaccounts << endl;
    
    totalbalance = bank2.getTotalAccountsBalance();
    
    cout << "Total Accounts Balance: " << totalbalance << " cents" << endl;
    
    
    cout << "Enter Customer ID: ";
    cin >> customerIDSearch;
    Customer *search = bank2.publicSearchCustomer(customerIDSearch);
    if ((bank2.publicSearchCustomer(customerIDSearch)) == NULL)
    {
        cout << "ERROR: Invalid Customer ID." << endl;
    }
    else
    {
        search->printCustomer();
    }
    
    return 0;
}
