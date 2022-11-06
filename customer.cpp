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
Customer::Customer(string ID, string name, string email, string phone, string bill, string currency)
{
    this->ID = ID;
    this->name = name;
    this->phone = phone;
    this->email = email;
    this->bill = bill;
    this->currency = currency;
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
void ValidatePhone(string phone)
{
    // check phone use regex
    regex pattern("(\\+84|0)(\\d{9,10})");
    if (regex_match(phone, pattern))
    {
        cout << "Phone is valid" << endl;
    }
    else
    {
        cout << "Phone is invalid" << endl;
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
