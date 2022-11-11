#include<bits/stdc++.h>
#include"customer.h"
// #include "ConsoleTable.cpp"
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
// Sort customer by 5 fields: ID, Name, Bill, Service, Feedback. And update file after sort
void SortCustomer(vector<Customer> &customers, int left, int right, int opt, bool isAscending)
{
    // use switch
    switch (opt)
    {
    case 1:
        // sort by ID
        if (left < right)
        {
            int i = left, j = right;
            Customer pivot = customers[(left + right) / 2];
            while (i <= j)
            {
                if (isAscending)
                {
                    while (Str_to_int(customers[i].getID()) < Str_to_int(pivot.getID()))
                        i++;
                    while (Str_to_int(customers[j].getID()) > Str_to_int(pivot.getID()))
                        j--;
                }
                else
                {
                    while (Str_to_int(customers[i].getID()) > Str_to_int(pivot.getID()))
                        i++;
                    while (Str_to_int(customers[j].getID()) < Str_to_int(pivot.getID()))
                        j--;
                }
                if (i <= j)
                {
                    swap(customers[i], customers[j]);
                    i++;
                    j--;
                }
            }
            if (left < j)
                SortCustomer(customers, left, j, opt, isAscending);
            if (i < right)
                SortCustomer(customers, i, right, opt, isAscending);
        }
        break;
    case 2:
        // sort by Name
        if (left < right)
        {
            int i = left, j = right;
            Customer pivot = customers[(left + right) / 2];
            while (i <= j)
            {
                if (isAscending)
                {
                    while (customers[i].getName() < pivot.getName())
                        i++;
                    while (customers[j].getName() > pivot.getName())
                        j--;
                }
                else
                {
                    while (customers[i].getName() > pivot.getName())
                        i++;
                    while (customers[j].getName() < pivot.getName())
                        j--;
                }
                if (i <= j)
                {
                    swap(customers[i], customers[j]);
                    i++;
                    j--;
                }
            }
            if (left < j)
                SortCustomer(customers, left, j, opt, isAscending);
            if (i < right)
                SortCustomer(customers, i, right, opt, isAscending);
        }
        break;
    case 3:
        // convert bill to number and sort them
        if (left < right)
        {
            int i = left, j = right;
            Customer pivot = customers[(left + right) / 2];
            while (i <= j)
            {
                if (isAscending)
                {
                    while (Str_to_int(customers[i].getBill()) < Str_to_int(pivot.getBill()))
                        i++;
                    while (Str_to_int(customers[j].getBill()) > Str_to_int(pivot.getBill()))
                        j--;
                }
                else
                {
                    while (Str_to_int(customers[i].getBill()) > Str_to_int(pivot.getBill()))
                        i++;
                    while (Str_to_int(customers[j].getBill()) < Str_to_int(pivot.getBill()))
                        j--;
                }
                if (i <= j)
                {
                    swap(customers[i], customers[j]);
                    i++;
                    j--;
                }
            }
            if (left < j)
                SortCustomer(customers, left, j, opt, isAscending);
            if (i < right)
                SortCustomer(customers, i, right, opt, isAscending);
        }
        break;
    case 4:
        // convert 3 first character of service to number and sort them
        if (left < right)
        {
            int i = left, j = right;
            Customer pivot = customers[(left + right) / 2];
            while (i <= j)
            {
                if (isAscending)
                {
                    while (Str_to_int(customers[i].getService().substr(0, 3)) < Str_to_int(pivot.getService().substr(0, 3)))
                        i++;
                    while (Str_to_int(customers[j].getService().substr(0, 3)) > Str_to_int(pivot.getService().substr(0, 3)))
                        j--;
                }
                else
                {
                    while (Str_to_int(customers[i].getService().substr(0, 3)) > Str_to_int(pivot.getService().substr(0, 3)))
                        i++;
                    while (Str_to_int(customers[j].getService().substr(0, 3)) < Str_to_int(pivot.getService().substr(0, 3)))
                        j--;
                }
                if (i <= j)
                {
                    swap(customers[i], customers[j]);
                    i++;
                    j--;
                }
            }
            if (left < j)
                SortCustomer(customers, left, j, opt, isAscending);
            if (i < right)
                SortCustomer(customers, i, right, opt, isAscending);
        }
        break;
    case 5:
        // convert the first character of feedback and sort them
        if (left < right)
        {
            int i = left, j = right;
            Customer pivot = customers[(left + right) / 2];
            while (i <= j)
            {
                if (isAscending)
                {
                    while (Str_to_int(customers[i].getFeedback().substr(0, 1)) < Str_to_int(pivot.getFeedback().substr(0, 1)))
                        i++;
                    while (Str_to_int(customers[j].getFeedback().substr(0, 1)) > Str_to_int(pivot.getFeedback().substr(0, 1)))
                        j--;
                }
                else
                {
                    while (Str_to_int(customers[i].getFeedback().substr(0, 1)) > Str_to_int(pivot.getFeedback().substr(0, 1)))
                        i++;
                    while (Str_to_int(customers[j].getFeedback().substr(0, 1)) < Str_to_int(pivot.getFeedback().substr(0, 1)))
                        j--;
                }
                if (i <= j)
                {
                    swap(customers[i], customers[j]);
                    i++;
                    j--;
                }
            }
            if (left < j)
                SortCustomer(customers, left, j, opt, isAscending);
            if (i < right)
                SortCustomer(customers, i, right, opt, isAscending);
        }
    }
    // save the sorted list to file data1.txt
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

// Search customer by 7 fields: ID, Name, Bill, Phone, Service, Feedback, Email
// use linear to search and return information of customer

void SearchCustomer(vector<Customer> &customers, string value, int opt)
{
    // get the information of customer and print it out
    vector<Customer> result;
    switch (opt)
    {
    case 1:
        // search by ID
        for (int i = 0; i < customers.size(); i++)
        {
            if (customers[i].getID() == value)
            {
                result.push_back(customers[i]);
            }
        }
        break;
    case 2:
        // search by Name
        for (int i = 0; i < customers.size(); i++)
        {
            if (customers[i].getName() == value)
            {
                result.push_back(customers[i]);
            }
        }
        break;
    case 3:
        // search by Bill
        for (int i = 0; i < customers.size(); i++)
        {
            if (customers[i].getBill() == value)
            {
                result.push_back(customers[i]);
            }
        }
        break;
    case 4:
        // search by Phone
        for (int i = 0; i < customers.size(); i++)
        {
            if (customers[i].getPhone() == value)
            {
                result.push_back(customers[i]);
            }
        }
        break;
    case 5:
        // search by Service
        for (int i = 0; i < customers.size(); i++)
        {
            if (customers[i].getService() == value)
            {
                result.push_back(customers[i]);
            }
        }
        break;
    case 6:
        // search by Feedback
        for (int i = 0; i < customers.size(); i++)
        {
            if (customers[i].getFeedback() == value)
            {
                result.push_back(customers[i]);
            }
        }
        break;
    case 7:
        // search by Email
        for (int i = 0; i < customers.size(); i++)
        {
            if (customers[i].getEmail() == value)
            {
                result.push_back(customers[i]);
            }
        }
        break;
    }
    // print the result
    if (result.size() == 0)
    {
        cout << "No result found" << endl;
    }
    else
    {
        cout << "ID" << '\t' << "Name" << setw(30) << "Email" << setw(30) << "Phone" << setw(30) << "Bill" << setw(30) << "Currency" << setw(30) << "Service" << setw(30) << "Feedback" << setw(30) << "Address" << endl;
        for (int i = 0; i < result.size(); i++)
        {
            // print out all information of customer
            cout << result[i].getID() << '\t' << result[i].getName() << setw(30) << result[i].getEmail() << setw(30) << result[i].getPhone() << setw(30) << result[i].getBill() << setw(30) << result[i].getCurrency() << setw(30) << result[i].getService() << setw(30) << result[i].getFeedback() << setw(30) << result[i].getAddress() << endl;
        }
    }
}







