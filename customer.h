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
        map<int,string> tokens;
        map<string, string> data;
    public:
        Customer();                                                                                // destructor
        Customer(string ID, string name, string phone, string email, string acNo, string currency);// constructor
        ~Customer();                                                                               // destructor
        void menuCustomer();                                                                       // menu to pick customer's function
        void readCustomer();                                                                       // Read customer data from file text
        void writeCustomer();                                                                      // Write customer data to file text
        
        void setID(string ID);                                                                     // set ID
        void setName(string name);                                                                 // set name
        void setPhone(string phone);                                                               // set phone
        void setEmail(string email);                                                               // set email
        void setAcNo(string acNo);                                                                 // set account number
        void setCurrency(string currency);                                                         // set currency

        string getID();                                                                            // get customer's ID
        string getName();                                                                          // get customer's name
        string getPhone();                                                                         // get customer's phone
        string getEmail();                                                                         // get customer's email
        string getAcNo();                                                                          // get customer's account number
        string getCurrency();                                                                      // get customer's currency

        void addCustomer();                                                                        // Add customer data to file text
        void updateCustomer();                                                                     // Update customer data to file text
        void deleteCustomer();                                                                     // Delete customer data to file text
        void searchCustomer();                                                                     // Search customer data to file text
        void displayCustomer();                                                                    // Display customer data to file text
        void CheckValidMail(string mail);                                                          // Money from customer
        void NoName();                                                                             // Money to customer
        void RoundMoney();                                                                         // Round money
        void TypeOfMail();                                                                         // Type of mail
        void TypeOfCurrency(string currency);                                                      // Type of Currency  
};
#endif