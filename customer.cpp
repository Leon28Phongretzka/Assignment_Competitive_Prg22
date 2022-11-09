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
    service = "";
    feedback = "";
    address = "";
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
// General
void swap(Customer &a, Customer &b)
{
    Customer temp = a;
    a = b;
    b = temp;
}
unsigned long long BillStr_to_int(string bill)
{
    unsigned long long bill_int = 0;
    for (int i = 0; i < bill.length(); i++)
    {
        bill_int = bill_int * 10 + (bill[i] - '0');
    }
    return bill_int;
}
int partitionAsc(vector<Customer> &customer, int left, int right)
{
    int i = left;
    int j = right;
    Customer pivot = customer[(left + right) / 2];
    while (i <= j)
    {
        while (BillStr_to_int(customer[i].getBill()) < BillStr_to_int(pivot.getBill()))
        {
            i++;
        }
        while (BillStr_to_int(customer[j].getBill()) > BillStr_to_int(pivot.getBill()))
        {
            j--;
        }
        if (i <= j)
        {
            swap(customer[i], customer[j]);
            i++;
            j--;
        }
    }
    return i;
}
int partitionDesc(vector<Customer> &customer, int left, int right)
{
    int i = left;
    int j = right;
    Customer pivot = customer[(left + right) / 2];
    while (i <= j)
    {
        while (BillStr_to_int(customer[i].getBill()) > BillStr_to_int(pivot.getBill()))
        {
            i++;
        }
        while (BillStr_to_int(customer[j].getBill()) < BillStr_to_int(pivot.getBill()))
        {
            j--;
        }
        if (i <= j)
        {
            swap(customer[i], customer[j]);
            i++;
            j--;
        }
    }
    return i;
}

// Validate Mail
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

// add Customer to vector and update file after add

void AddCustomer(vector<Customer> &customers)
{
    string ID, name, email, phone, bill, currency, service, feedback, address;
    cout << "Enter ID: ";
    cin >> ID;
    // if ID exist, return
    for (int i = 0; i < customers.size(); i++)
    {
        if (customers[i].getID() == ID)
        {
            cout << "ID is exist" << endl;
            return;
        }
    }
    cout << "Enter name: ";
    cin.ignore();
    getline(cin, name);
    cout << "Enter email: ";
    cin >> email;
    cout << "Enter phone: ";
    cin >> phone;
    cout << "Enter bill: ";
    cin >> bill;
    cout << "Enter currency: ";
    cin >> currency;
    cout << "Enter service: ";
    cin >> service;
    cout << "Enter feedback: ";
    cin >> feedback;
    cout << "Enter address: ";
    cin.ignore();
    getline(cin, address);
    Customer customer(ID, name, email, phone, bill, currency, service, feedback, address);
    customers.push_back(Customer(ID, name, email, phone, bill, currency, service, feedback, address));
    // Add new customer to file data1.txt
    ofstream input(FILE_PATH);
    // Get the title line

    input << "ID" << '\t' << "Name" << setw(30) << "Email" << setw(30) << "Phone" << setw(30) << "Bill" << setw(30) << "Currency" << setw(30) << "Service" << setw(30) << "Feedback" << setw(30) << "Address" << endl;
    for (int i = 0; i < customers.size(); i++)
    {
        // write data to file and set space between data to 30
        input << customers[i].getID() << '\t' << customers[i].getName() << setw(30) << customers[i].getEmail() << setw(30) << customers[i].getPhone() << setw(30) << customers[i].getBill() << setw(30) << customers[i].getCurrency() << setw(30) << customers[i].getService() << setw(30) << customers[i].getFeedback() << setw(30) << customers[i].getAddress() << endl;
    }
    
    input.close();
}

