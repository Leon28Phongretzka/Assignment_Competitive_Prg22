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
        string service;
        string feedback;
        string address;
    public:
        Customer();
        Customer(string ID, string name, string email, string phone, string bill, string currency, string service, string feedback, string address);
        ~Customer();
        
        void setID(string ID);
        void setName(string name);
        void setPhone(string phone);
        void setEmail(string email);
        void setBill(string bill);
        void setCurrency(string currency);
        void setService(string service);
        void setFeedback(string feedback);
        void setAddress(string address);

        string getID();
        string getName();
        string getPhone();
        string getEmail();
        string getBill();
        string getCurrency();
        string getService();
        string getFeedback();
        string getAddress();
};
unsigned long long BillStr_to_int(string bill);                                                       // convert account number from string to int
void ValidateEmail(string email);                                                                     // validate email
void quickSort(vector<Customer> &customer, int left, int right);                                       // quick sort   
void swap(Customer &a, Customer &b);                                                                  // swap
int partitionAsc(vector<Customer> &customer, int left, int right);                                        // partition
int partitionDesc(vector<Customer> &customer, int left, int right);                                       // partition
long long searchCustomer(vector<Customer> &customer, string bill);                                     // search customer by account number
long long SortBill(vector<Customer> &customer, int left, int right, string bill);                      // sort by account number     
void ExchangeCurrency();                                                                 // exchange currency                         
#endif