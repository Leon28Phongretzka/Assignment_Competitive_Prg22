#ifndef _CUSTOMER_H
#define _CUSTOMER_H
#include<iostream>
#include<fstream>
#include<string>

using namespace std;

#define FILE_PATH "D:\\4.Code\\ASG_CP22\\data1.txt"
class Customer
{
    private:
        string ID;
        string name;
        string phone;
        string email;
        string bill;
        string currency;
    public:
        Customer();                                                                                     // destructor
        Customer(string ID, string name, string phone, string email, string bill, string currency);     // constructor
        ~Customer();                                                                                    // destructor                                                                         // Write customer data to file text
        
        void setID(string ID);                                                                          // set ID
        void setName(string name);                                                                      // set name
        void setPhone(string phone);                                                                    // set phone
        void setEmail(string email);                                                                    // set email
        void setBill(string bill);                                                                      // set account number
        void setCurrency(string currency);                                                              // set currency

        string getID();                                                                                 // get customer's ID
        string getName();                                                                               // get customer's name
        string getPhone();                                                                              // get customer's phone
        string getEmail();                                                                              // get customer's email
        string getBill();                                                                               // get customer's account number
        string getCurrency();                                                                           // get customer's currency 
};
unsigned long long BillStr_to_int(string bill);                                                       // convert account number from string to int
void ValidateEmail(string email);                                                                     // validate email
void quickSort(vector<Customer> &customer, int left, int right);                                       // quick sort   
void swap(Customer &a, Customer &b);                                                                  // swap
int partitionAsc(vector<Customer> &customer, int left, int right);                                        // partition
int partitionDesc(vector<Customer> &customer, int left, int right);                                       // partition
long long searchCustomer(vector<Customer> &customer, string bill);                                     // search customer by account number     
void CheckCurrency(string currency);                                                                 // check currency                         
#endif