#include<bits/stdc++.h>
#include"customer.h"
using namespace std;
Customer::Customer()
{
    ID = "";
    name = "";
    email = "";
    acNo = "";
    currency = "";
    phone = "";
}
void Customer::readCustomer()
{
    ifstream file;
    file.open("D:\\4.Code\\ASG_CP22\\data1.txt");
    // read infor from file data1.txt
    string info; 
    getline(file, info);
    while(getline(file, info))
    {
        stringstream ss;
        ss << info;
        size_t index=1;
        // Split the string into tokens
        while (ss >> info)
        {
            tokens[index++] = info;
        }
        long long ID = stoll(tokens[1]);
        string currency = tokens[index-1];
        string amount = tokens[index-2];
        string phone = tokens[index-3];
        string mail = tokens[index-4];
        string name = "";
        for (int i = 2; i < index-4; i++)
        {
            name += tokens[i];
        }
        // use map data to store data
        data[to_string(ID)] = name;
        // set wide between name and email
        int wide = 30 - name.length();
        // cout << wide << endl;
        data[to_string(ID)] += string(wide, ' ');
        data[to_string(ID)] = data[to_string(ID)] + mail + '\t' + phone + '\t' + amount + '\t' + currency;
    }
}
void Customer::writeCustomer()
{
    // write infor to file data1.txt
    for (auto &i : data)
    {
        cout << i.first << "\t" << i.second << endl;
    }
}
Customer::Customer(string ID, string name, string phone, string email, string acNo, string currency)
{
    this->ID = ID;
    this->name = name;
    this->phone = phone;
    this->email = email;
    this->acNo = acNo;
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
void Customer::setAcNo(string acNo)
{
    this->acNo = acNo;
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
string Customer::getAcNo()
{
    return acNo;
}
string Customer::getCurrency()
{
    return currency;
}
void Customer::menuCustomer()
{
    int choice;
    do
    {
        cout << "1. Add Customer" << '\t' << '\t' << "6. Check Mail" << endl;
        cout << "2. Update Customer" << '\t' << "7. Money to Customer" << endl;
        cout << "3. Delete Customer" << '\t' << "8. Round Money" << endl;
        cout << "4. Search Customer" << '\t' << "9. Type of Mail" << endl;
        cout << "5. Display Customer" << '\t' << "10. Type of Currency" << endl;
        cout << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            addCustomer();
            break;
        case 2:
            updateCustomer();
            break;
        case 3:
            deleteCustomer();
            break;
        case 4:
            searchCustomer();
            break;
        case 5:
            displayCustomer();
            break;
        case 6:
            CheckValidMail(string email);
            break;
        case 7:
            NoName();
            break;
        case 8:
            RoundMoney();
            break;
        case 9:
            TypeOfMail();
            break;
        case 10:
            TypeOfCurrency(string currency);
            break;
        case 0:
            cout << "Exit" << endl;
            break;
        default:
            cout << "Invalid choice" << endl;
            break;
        }
    } while (choice != 0);
}
void Customer::addCustomer()
{
    // add customer to file data1.txt
    ofstream file;
    file.open("D:\\4.Code\\ASG_CP22\\data1.txt", ios::app);
    file << "ID\tName\tEmail\tPhone\tAmount\tCurrency" << endl;
    file << ID << "\t" << name << "\t" << email << "\t" << phone << "\t" << acNo << "\t" << currency << endl;
    file.close();
}
void Customer::updateCustomer()
{
    
}
void Customer::deleteCustomer()
{
    
}
void Customer::searchCustomer()
{
    
}
void Customer::displayCustomer()
{
    
}
void Customer::CheckValidMail(string email)
{
    // check valid mail use regex
    regex pattern("(\\w+)(\\.|_)?(\\w*)@(\\w+)(\\.(\\w+))+");
    if (regex_match(email, pattern))
    {
        cout << "Valid email" << endl;
    }
    else
    {
        cout << "Invalid email" << endl;
    }
}
void Customer::NoName()
{
    
}
void Customer::RoundMoney()
{
    
}
void Customer::TypeOfMail()
{
    
}
void Customer::TypeOfCurrency(string currency)
{
    // check type of currency in file data1.txt
    if (currency == "USD")
    {
        cout << "Dollar" << endl;
    }
    else if (currency == "VND")
    {
        cout << "Viet Nam Dong" << endl;
    }
    else if (currency == "EURO")
    {
        cout << "€" << endl;
    }
    else if (currency == "GBP")
    {
        cout << " £" << endl;
    }
}

