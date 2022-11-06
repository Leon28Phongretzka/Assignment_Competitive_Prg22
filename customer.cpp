#include<bits/stdc++.h>
#include"customer.h"
using namespace std;
Customer::Customer()
{
    ID = "";
    name = "";
    email = "";
    bill = "";
    currency = "";
    phone = "";
}
Customer::Customer(string ID, string name, string email, string phone, string bill, string currency, string service, string feedback, string address)
{
    this->ID = ID;
    this->name = name;
    this->email = email;
    this->bill = bill;
    this->currency = currency;
    this->phone = phone;
    this->service = service;
    this->feedback = feedback;
    this->address = address;
}
Customer::~Customer()
{
}
void Customer::setID(string ID)
{
    this->ID = ID;
}
void Customer::setName(string name)
{
    this->name = name;
}
void Customer::setPhone(string phone)
{
    this->phone = phone;
}
void Customer::setEmail(string email)
{
    this->email = email;
}
void Customer::setBill(string bill)
{
    this->bill = bill;
}
void Customer::setCurrency(string currency)
{
    this->currency = currency;
}
void Customer::setService(string service)
{
    this->service = service;
}
void Customer::setFeedback(string feedback)
{
    this->feedback = feedback;
}
void Customer::setAddress(string address)
{
    this->address = address;
}


string Customer::getID()
{
    return ID;
}
string Customer::getName()
{
    return name;
}
string Customer::getPhone()
{
    return phone;
}
string Customer::getEmail()
{
    return email;
}
string Customer::getBill()
{
    return bill;
}
string Customer::getCurrency()
{
    return currency;
}
string Customer::getService()
{
    return service;
}
string Customer::getFeedback()
{
    return feedback;
}
string Customer::getAddress()
{
    return address;
}


void ValidateEmail(string email)
{
    // check email use regex
    regex pattern("(\\w+)(\\.|_)?(\\w*)@(\\w+)(\\.(\\w+))+");
    if (regex_match(email, pattern))
    {
        cout << "Email is valid" << endl;
    }
    else
    {
        cout << "Email is invalid" << endl;
    }
}
void quickSort(vector<Customer> &arr, int left, int right)
{
    int i = left, j = right;
    Customer tmp;
    Customer pivot = arr[(left + right) / 2];
    /* partition */
    while (i <= j)
    {
        while (arr[i].getID() < pivot.getID())
            i++;
        while (arr[j].getID() > pivot.getID())
            j--;
        if (i <= j)
        {
            tmp = arr[i];
            arr[i] = arr[j];
            arr[j] = tmp;
            i++;
            j--;
        }
    };
    /* recursion */
    if (left < j)
        quickSort(arr, left, j);
    if (i < right)
        quickSort(arr, i, right);
}
void swap(Customer &a, Customer &b)
{
    Customer temp = a;
    a = b;
    b = temp;
}
