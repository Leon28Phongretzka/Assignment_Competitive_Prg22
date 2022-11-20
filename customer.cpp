#include <bits/stdc++.h>
#include "customer.h"
#include "ConsoleTable.cpp"
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
bool ValidateEmail(string email)
{
    // check email use regex
    regex pattern("(\\w+)(\\.|_)?(\\w*)@(\\w+)(\\.(\\w+))+");   // regex pattern for email validation
    // w+ : one or more word character
    // (\\.|_)? : zero or one occurrence of . or _
    // (\\w*) : zero or more word character
    // @ : need @ after username
    // (\\w+) : one or more word character
    // (\\.(\\w+))+ : one or more occurrence of . and one or more word character
    if (regex_match(email, pattern))
    {
        cout << "Email is valid" << endl;
    }
    else
    {
        cout << "Email is invalid" << endl;
    }
}
// Validate ID
bool ValidateID(string ID)
{
    // check ID use regex
    // [0-9]{1} : 1 number
    // [0-9]{2} : 2 number
    // [0-9]{3} : 3 number
    // [0-9]{4} : 4 number
    regex pattern1("[0-9]{1}");   // regex pattern for ID validation
    regex pattern2("[0-9]{2}");   // regex pattern for ID validation
    regex pattern3("[0-9]{3}");   // regex pattern for ID validation
    while(regex_match(ID, pattern1) || regex_match(ID, pattern2) || regex_match(ID, pattern3))
    {
        // cout << "ID is valid" << endl;
        return true;
    }
}

// Validate Phone
bool ValidatePhone(string phone)
{
    // check phone use regex
    regex pattern("(\\+84|0)(\\d{9,10})");   // regex pattern for phone validation
    // (\\+84|0) : +84 or 0
    // (\\d{9,10}) : 9 or 10 digit
    while(regex_match(phone, pattern))
    {
        cout << "Phone is valid" << endl;
        return true;
    }
}
// Validate Currency



// add Customer to vector and update file after add
void AddCustomer(vector<Customer> &customers)
{
    // cout << customers.size() << endl;
    string ID, name, email, phone, bill, currency, service, feedback, address;
    cout << "Enter ID: ";
    cin >> ID;
    // if ID is not valid, ask user to enter again
    if(ValidateID(ID) == false)
    {
        cout << "Try to enter again: ";
        cin >> ID;
    }
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
    // ValidateEmail(email);
    cout << "Enter phone: ";
    cin >> phone;
    cout << "Enter currency: " << '\t';
        // Choose currency
        cout << "1. USD" << '\t';
        cout << "2. VND" << '\t';
        cout << "3. EUR" << '\t';
        cout << "4. GBP" << '\t';
        int choose_crc;
        cin >> choose_crc;
        switch (choose_crc)
        {
            case 1:
                currency = "USD";
                break;
            case 2:
                currency = "VND";
                break;
            case 3:
                currency = "EUR";
                break;
            case 4:
                currency = "GBP";
                break;
        }
    cout << "Enter Bill: ";
    cin >> bill;
    cout << "Enter service: ";
    cin >> service;
    cout << "Choose feedback: " << '\t';
    // Choose feedback
    cout << "1. 5*" << '\t';
    cout << "2. 4*" << '\t';
    cout << "3. 3*" << '\t';
    cout << "4. 2*" << '\t';
    cout << "5. 1*" << '\t';
    int choose_fb;
    cin >> choose_fb;
    switch (choose_fb)
    {
        case 1:
            feedback = "5*";
            break;
        case 2:
            feedback = "4*";
            break;
        case 3:
            feedback = "3*";
            break;
        case 4:
            feedback = "2*";
            break;
        case 5:
            feedback = "1*";
            break;
    }
    cout << "Enter address: ";
    cin.ignore();
    getline(cin, address);
    // Customer customer(ID, name, email, phone, bill, currency, service, feedback, address);
    customers.push_back(Customer(ID, name, email, phone, bill, currency, service, feedback, address));
    // Add new customer to file data1.txt
    // cout << customers.size() << endl;
    ofstream input(FILE_PATH);
    // Get the title line
    cout << customers.size() << endl;
    input << "ID" << setw(10) << "Name" << setw(30) << "Email" << setw(30) << "Phone" << setw(30) << "Bill" << setw(30) << "Currency" << setw(30) << "Service" << setw(30) << "Feedback" << setw(30) << "Address" << endl;
    for (int i = 0; i < customers.size(); i++)
    {
        // write data to file and set space between data to 30
        input << left << setw(10) << customers[i].getID() << setw(30) << customers[i].getName() << setw(30) << customers[i].getEmail() << setw(30) << customers[i].getPhone() << setw(30) << customers[i].getBill() << setw(30) << customers[i].getCurrency() << setw(30) << customers[i].getService() << setw(30) << customers[i].getFeedback() << setw(30) << customers[i].getAddress() << endl;
    }
    input.close();
    cout << customers[customers.size()-1] << endl;
}

// Edit customer to vector and update file after edit
void EditCustomer(vector<Customer> &customers)
{
    string ID, name, email, phone, bill, currency, service, feedback, address;
    cout << "Enter ID: ";
    cin >> ID;
    // if ID is not valid, ask user to enter again
    if(ValidateID(ID) == false)
    {
        cout << "Try to enter again: ";
        cin >> ID;
    }
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
            cout << "Enter currency: " << '\t';
            // Choose currency
            cout << "1. USD" << '\t';
            cout << "2. VND" << '\t';
            cout << "3. EUR" << '\t';
            cout << "4. GBP" << '\t';
            int choose_crc;
            cin >> choose_crc;
            switch (choose_crc)
            {
                case 1:
                    currency = "USD";
                    break;
                case 2:
                    currency = "VND";
                    break;
                case 3:
                    currency = "EUR";
                    break;
                case 4:
                    currency = "GBP";
                    break;
            }
            cout << "Enter Bill: ";
            cin >> bill;
            cout << "Enter service: ";
            cin >> service;
            cout << "Choose feedback: " << '\t';
            // Choose feedback
            cout << "1. 5*" << '\t';
            cout << "2. 4*" << '\t';
            cout << "3. 3*" << '\t';
            cout << "4. 2*" << '\t';
            cout << "5. 1*" << '\t';
            int choose_feedback;
            cin >> choose_feedback;
            switch (choose_feedback)
            {
                case 1:
                    feedback = "5*";
                    break;
                case 2:
                    feedback = "4*";
                    break;
                case 3:
                    feedback = "3*";
                    break;
                case 4:
                    feedback = "2*";
                    break;
                case 5:
                    feedback = "1*";
                    break;
            }
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
            input << "ID" << setw(10) << "Name" << setw(30) << "Email" << setw(30) << "Phone" << setw(30) << "Bill" << setw(30) << "Currency" << setw(30) << "Service" << setw(30) << "Feedback" << setw(30) << "Address" << endl;
            for (int i = 0; i < customers.size(); i++)
            {
                // write data to file and set space between data to 30
                input << left << setw(10) << customers[i].getID() << setw(30) << customers[i].getName() << setw(30) << customers[i].getEmail() << setw(30) << customers[i].getPhone() << setw(30) << customers[i].getBill() << setw(30) << customers[i].getCurrency() << setw(30) << customers[i].getService() << setw(30) << customers[i].getFeedback() << setw(30) << customers[i].getAddress() << endl;
            }
            input.close();
            // print customer after edit
            cout << customers[i] << endl;
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
            input << "ID" << setw(30) << "Name" << setw(30) << "Email" << setw(30) << "Phone" << setw(30) << "Bill" << setw(30) << "Currency" << setw(30) << "Service" << setw(30) << "Feedback" << setw(30) << "Address" << endl;
            for (int i = 0; i < customers.size(); i++)
            {
                // write data to file and set space between data to 30
                input << customers[i].getID() << setw(30) << customers[i].getName() << setw(30) << customers[i].getEmail() << setw(30) << customers[i].getPhone() << setw(30) << customers[i].getBill() << setw(30) << customers[i].getCurrency() << setw(30) << customers[i].getService() << setw(30) << customers[i].getFeedback() << setw(30) << customers[i].getAddress() << endl;
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

    input << left << setw(10) << "ID" << setw(30) << "Name" << setw(30) << "Email" << setw(30) << "Phone" << setw(30) << "Bill" << setw(30) << "Currency" << setw(30) << "Service" << setw(30) << "Feedback" << setw(30) << "Address" << endl;
    for (int i = 0; i < customers.size(); i++)
    {
        // write data to file and set space between data to 30
        input << left << setw(10) << customers[i].getID() << setw(30) << customers[i].getName() << setw(30) << customers[i].getEmail() << setw(30) << customers[i].getPhone() << setw(30) << customers[i].getBill() << setw(30) << customers[i].getCurrency() << setw(30) << customers[i].getService() << setw(30) << customers[i].getFeedback() << setw(30) << customers[i].getAddress() << endl;
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
    case 1: // search by ID
        for (int i = 0; i < customers.size(); i++)
        {
            if (customers[i].getID() == value)
            {
                result.push_back(customers[i]);
            }
        }
        break;
    case 2: // search by Name
        for (int i = 0; i < customers.size(); i++)
        {
            if (customers[i].getName() == value)
            {
                result.push_back(customers[i]);
            }
        }
        break;
    case 3: // search by Bill
        for (int i = 0; i < customers.size(); i++)
        {
            if (customers[i].getBill() == value)
            {
                result.push_back(customers[i]);
            }
        }
        break;
    case 4: // search by Phone
        for (int i = 0; i < customers.size(); i++)
        {
            if (customers[i].getPhone() == value)
            {
                result.push_back(customers[i]);
            }
        }
        break;
    case 5: // search by Service
        for (int i = 0; i < customers.size(); i++)
        {
            if (customers[i].getService() == value)
            {
                result.push_back(customers[i]);
            }
        }
        break;
    case 6: // search by Feedback
        for (int i = 0; i < customers.size(); i++)
        {
            if (customers[i].getFeedback() == value)
            {
                result.push_back(customers[i]);
            }
        }
        break;
    case 7: // search by Email
        for (int i = 0; i < customers.size(); i++)
        {
            if (customers[i].getEmail() == value)
            {
                result.push_back(customers[i]);
            }
        }
        break;
    }
    if (result.size() == 0)
    {
        cout << "No result found" << endl;
    }
    else
    {
        // cout << left << setw(10) << "ID" << setw(20) << "Name" << setw(20) << "Email" << setw(20) << "Phone" << setw(20) << "Bill" << setw(20) << "Currency" << setw(20) << "Service" << setw(20) << "Feedback" << setw(20) << "Address" << endl;
        // for (int i = 0; i < result.size(); i++)
        // {
        //     // print out all information of customer
        //     cout << left << setw(10) << result[i].getID() << setw(20) << result[i].getName() << setw(20) << result[i].getEmail() << setw(20) << result[i].getPhone() << setw(20) << result[i].getBill() << setw(20) << result[i].getCurrency() << setw(20) << result[i].getService() << setw(20) << result[i].getFeedback() << setw(20) << result[i].getAddress() << endl;
        // }
        ConsoleTable table{"ID", "Name", "Email", "Phone", "Bill", "Currency", "Service", "Feedback", "Address"};
        table.setPadding(2);
        table.setStyle(0);
        for (int i = 0; i < result.size(); i++)
        {
            table += {result[i].getID(), result[i].getName(), result[i].getEmail(), result[i].getPhone(), result[i].getBill(), result[i].getCurrency(), result[i].getService(), result[i].getFeedback(), result[i].getAddress()};
        }
        cout << table << endl;
        // return;
    }
    // In kết quả vào bảng ở thư viện ConsoleTable
}
ostream& operator<<(ostream& ofs, Customer& customers)
{
    ConsoleTable table{"ID", "Name", "Email", "Phone", "Bill", "Currency", "Service", "Feedback", "Address"};
    table.setPadding(2);
    table.setStyle(0);
    table+= {customers.getID(), customers.getName(), customers.getEmail(), customers.getPhone(), customers.getBill(), customers.getCurrency(), customers.getService(), customers.getFeedback(), customers.getAddress()};
    ofs << table;
    return ofs;
}