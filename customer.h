#ifndef _CUSTOMER_H
#define _CUSTOMER_H
#include<iostream>
#include<fstream>
#include<string>
#include<vector>

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
        string service;
        string feedback;
        string address;
    public:
        Customer();                                                                                                                                     // default constructor
        Customer(string ID, string name, string email, string phone, string bill, string currency, string service, string feedback, string address);    // constructor with parameters
        ~Customer();                                                                                                                                    // destructor
        
        void setID(string ID);                                                                                                                          // set ID
        void setName(string name);                                                                                                                      // set name
        void setPhone(string phone);                                                                                                                    // set phone
        void setEmail(string email);                                                                                                                    // set email
        void setBill(string bill);                                                                                                                      // set bill
        void setCurrency(string currency);                                                                                                              // set currency
        void setService(string service);                                                                                                                // set service
        void setFeedback(string feedback);                                                                                                              // set feedback
        void setAddress(string address);                                                                                                                // set address

        string getID();                                                                                                                                 // get ID
        string getName();                                                                                                                               // get name
        string getPhone();                                                                                                                              // get phone
        string getEmail();                                                                                                                              // get email
        string getBill();                                                                                                                               // get bill
        string getCurrency();                                                                                                                           // get currency
        string getService();                                                                                                                            // get service
        string getFeedback();                                                                                                                           // get feedback
        string getAddress();
        friend ostream& operator<<(ostream& out, Customer& customer);                                                                                   // operator << for writing to file
};
// General Functions
void swap(Customer &a, Customer &b);                                                                                                                    // swap 2 customers    
unsigned long long Str_to_int(string str);                                                                                                              // convert string to int                                                                
int partitionAsc(vector<Customer> &customer, int left, int right, int opt);                                                                             // partition for quick sort ascending
int partitionDesc(vector<Customer> &customer, int left, int right, int opt);                                                                            // partition for quick sort descending 

bool ValidateID(string ID);                                                                                                                            // validate ID
bool ValidatePhone(string phone);                                                                                                                      // validate phone
bool ValidateEmail(string email);                                                                                                                      // validate email
bool ValidateCurrency(string currency);                                                                                                                // validate currency
// Add, Edit, Delete Data
void AddCustomer(vector<Customer> &customers);                                                                                                          // add customer
void EditCustomer(vector<Customer> &customers);                                                                                                         // edit customer
void DeleteCustomerByID(vector<Customer> &customers);                                                                                                   // delete customer by ID
// Sort
void SortCustomer(vector<Customer> &customers, int left, int right, int opt, bool isAscending);                                                         // sort customer 
// Search  
void SearchCustomer(vector<Customer> &customers,  string value, int opt);                                                                               // search customer
// Additional
void ExchangeCurrency();                                                                                                                                // exchange currency
#endif