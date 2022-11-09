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
unsigned long long Str_to_int(string str)
{
    unsigned long long result = 0;
    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] >= '0' && str[i] <= '9')
        {
            result = result * 10 + (str[i] - '0');
        }
    }
    return result;
}
int partitionAsc(vector<Customer> &customer, int left, int right, int opt)
{
    int i = left, j = right;
    Customer pivot = customer[(left + right) / 2];
    while (i <= j)
    {
        switch(opt)
        {
            case 1:
                if(Str_to_int(customer[i].getID()) < Str_to_int(pivot.getID()))
                {
                    i++;
                    swap(customer[i], customer[j]);
                }
                break;
            case 2:
                if(customer[i].getName() < pivot.getName())
                {
                    i++;
                    swap(customer[i], customer[j]);
                }
                break;
            case 3:
                if(customer[i].getEmail() < pivot.getEmail())
                {
                    i++;
                    swap(customer[i], customer[j]);
                }
                break;
            case 4:
                if(customer[i].getPhone() < pivot.getPhone())
                {
                    i++;
                    swap(customer[i], customer[j]);
                }
                break;
            case 5:
                if(Str_to_int(customer[i].getBill()) < Str_to_int(pivot.getBill()))
                {
                    i++;
                    swap(customer[i], customer[j]);
                }
                break;
            case 6:
                if(customer[i].getService() < pivot.getService())
                {
                    i++;
                    swap(customer[i], customer[j]);
                }
                break;
            case 7:
                if(customer[i].getFeedback() < pivot.getFeedback())
                {
                    i++;
                    swap(customer[i], customer[j]);
                }
                break;
        }
    }
    return i;
}
int partitionDesc(vector<Customer> &customer, int left, int right, int opt)
{
    int i = left, j = right;
    Customer pivot = customer[(left + right) / 2];
    while (i <= j)
    {
        switch(opt)
        {
            case 1:
                if(Str_to_int(customer[i].getID()) > Str_to_int(pivot.getID()))
                {
                    i++;
                    swap(customer[i], customer[j]);
                }
                break;
            case 2:
                if(customer[i].getName() > pivot.getName())
                {
                    i++;
                    swap(customer[i], customer[j]);
                }
                break;
            case 3:
                if(customer[i].getEmail() > pivot.getEmail())
                {
                    i++;
                    swap(customer[i], customer[j]);
                }
                break;
            case 4:
                if(customer[i].getPhone() > pivot.getPhone())
                {
                    i++;
                    swap(customer[i], customer[j]);
                }
                break;
            case 5:
                if(Str_to_int(customer[i].getBill()) > Str_to_int(pivot.getBill()))
                {
                    i++;
                    swap(customer[i], customer[j]);
                }
                break;
            case 6:
                if(customer[i].getService() > pivot.getService())
                {
                    i++;
                    swap(customer[i], customer[j]);
                }
                break;
            case 7:
                if(customer[i].getFeedback() > pivot.getFeedback())
                {
                    i++;
                    swap(customer[i], customer[j]);
                }
                break;
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

// Edit customer to vector and update file after edit
void EditCustomer(vector<Customer> &customers)
{
    string ID, name, email, phone, bill, currency, service, feedback, address;
    cout << "Enter ID: ";
    cin >> ID;
    // if ID not exist, return
    for (int i = 0; i < customers.size(); i++)
    {
        if (customers[i].getID() == ID)
        {
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
            customers[i].setName(name);
            customers[i].setEmail(email);
            customers[i].setPhone(phone);
            customers[i].setBill(bill);
            customers[i].setCurrency(currency);
            customers[i].setService(service);
            customers[i].setFeedback(feedback);
            customers[i].setAddress(address);
            // Edit customer to file data1.txt
            ofstream input(FILE_PATH);
            // Get the title line

            input << "ID" << '\t' << "Name" << setw(30) << "Email" << setw(30) << "Phone" << setw(30) << "Bill" << setw(30) << "Currency" << setw(30) << "Service" << setw(30) << "Feedback" << setw(30) << "Address" << endl;
            for (int i = 0; i < customers.size(); i++)
            {
                // write data to file and set space between data to 30
                input << customers[i].getID() << '\t' << customers[i].getName() << setw(30) << customers[i].getEmail() << setw(30) << customers[i].getPhone() << setw(30) << customers[i].getBill() << setw(30) << customers[i].getCurrency() << setw(30) << customers[i].getService() << setw(30) << customers[i].getFeedback() << setw(30) << customers[i].getAddress() << endl;
            }
            input.close();
            return;
        }
    }
}

// Delete customer to vector and update file after delete
void DeleteCustomerByID(vector<Customer> &customers)
{
    string ID;
    cout << "Enter ID: ";
    cin >> ID;
    // if ID not exist, return
    for (int i = 0; i < customers.size(); i++)
    {
        if (customers[i].getID() == ID)
        {
            customers.erase(customers.begin() + i);
            // Delete customer to file data1.txt
            ofstream input(FILE_PATH);
            // Get the title line

            input << "ID" << '\t' << "Name" << setw(30) << "Email" << setw(30) << "Phone" << setw(30) << "Bill" << setw(30) << "Currency" << setw(30) << "Service" << setw(30) << "Feedback" << setw(30) << "Address" << endl;
            for (int i = 0; i < customers.size(); i++)
            {
                // write data to file and set space between data to 30
                input << customers[i].getID() << '\t' << customers[i].getName() << setw(30) << customers[i].getEmail() << setw(30) << customers[i].getPhone() << setw(30) << customers[i].getBill() << setw(30) << customers[i].getCurrency() << setw(30) << customers[i].getService() << setw(30) << customers[i].getFeedback() << setw(30) << customers[i].getAddress() << endl;
            }
            input.close();
            return;
        }
    }
}
// Sort customer by any option
void SortCustomer(vector<Customer> &customers, int left, int right, int opt, bool isAscending)
{
    if(left < right)
    {
        int pv = isAscending ? partitionAsc(customers, left, right, opt) : partitionDesc(customers, left, right, opt);
        SortCustomer(customers, left, pv - 1, opt, isAscending);
        SortCustomer(customers, pv + 1, right, opt, isAscending);
    }
}

// Search customer by any option
void SearchCustomer(vector<Customer> &customers, int opt, string value)
{
    for (int i = 0; i < customers.size(); i++)
    {
        switch (opt)
        {
            // set wide 20
            case 1:
                if (customers[i].getID().find(value) != string::npos)
                {
                    cout << customers[i].getID() << setw(20) << customers[i].getName() << setw(20) << customers[i].getEmail() << setw(20) << customers[i].getPhone() << setw(20) << customers[i].getBill() << setw(20) << customers[i].getCurrency() << setw(20) << customers[i].getService() << setw(20) << customers[i].getFeedback() << setw(20) << customers[i].getAddress() << endl;
                }
                break;
            case 2:
                if (customers[i].getName().find(value) != string::npos)
                {
                    cout << customers[i].getID() << setw(20) << customers[i].getName() << setw(20) << customers[i].getEmail() << setw(20) << customers[i].getPhone() << setw(20) << customers[i].getBill() << setw(20) << customers[i].getCurrency() << setw(20) << customers[i].getService() << setw(20) << customers[i].getFeedback() << setw(20) << customers[i].getAddress() << endl;
                }
                break;
            case 3:
                if (customers[i].getEmail().find(value) != string::npos)
                {
                    cout << customers[i].getID() << setw(20) << customers[i].getName() << setw(20) << customers[i].getEmail() << setw(20) << customers[i].getPhone() << setw(20) << customers[i].getBill() << setw(20) << customers[i].getCurrency() << setw(20) << customers[i].getService() << setw(20) << customers[i].getFeedback() << setw(20) << customers[i].getAddress() << endl;
                }
                break;
            case 4:
                if (customers[i].getPhone().find(value) != string::npos)
                {
                    cout << customers[i].getID() << setw(20) << customers[i].getName() << setw(20) << customers[i].getEmail() << setw(20) << customers[i].getPhone() << setw(20) << customers[i].getBill() << setw(20) << customers[i].getCurrency() << setw(20) << customers[i].getService() << setw(20) << customers[i].getFeedback() << setw(20) << customers[i].getAddress() << endl;
                }
                break;
            case 5:
                if (customers[i].getBill().find(value) != string::npos)
                {
                    cout << customers[i].getID() << setw(20) << customers[i].getName() << setw(20) << customers[i].getEmail() << setw(20) << customers[i].getPhone() << setw(20) << customers[i].getBill() << setw(20) << customers[i].getCurrency() << setw(20) << customers[i].getService() << setw(20) << customers[i].getFeedback() << setw(20) << customers[i].getAddress() << endl;
                }
                break;
        }
    }
}






