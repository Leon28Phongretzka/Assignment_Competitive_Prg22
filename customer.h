#ifndef _CUSTOMER_H
#define _CUSTOMER_H
#include<iostream>
#include<fstream>
#include<string>
using namespace std;
class Customer
{
    private:
        string ID;
        string name;
        string phone;
        string email;
        string acNo;
        string currency;
        // vector<string> listCustomer;
        deque<string> listCustomer;
    public:
        Customer();                                                                                               // destructor
        void menuCustomer();                                                                                        // menu to pick customer's function
        void readCustomer();                                                                                        // Read customer data from file text
        void writeCustomer(ofstream &fout);                                                                         // Write customer data to file text
        void addCustomer();                                                                                         // Add customer data to file text
        void updateCustomer();                                                                                      // Update customer data to file text
        void deleteCustomer();                                                                                      // Delete customer data to file text
        void searchCustomer();                                                                                      // Search customer data to file text
        void displayCustomer();                                                                                     // Display customer data to file text
        void MoneyFromCus();                                                                                        // Money from customer
        void MoneyToCus();                                                                                          // Money to customer
        void RoundMoney();                                                                                          // Round money
        void TypeOfMail();                                                                                          // Type of mail
        void TypeOfCurrency();                                                                                      // Type of Currency  
};
#endif