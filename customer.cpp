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
void Customer::menuCustomer()
{
    int choice;
    do
    {
        cout << "1. Add Customer" << endl;
        cout << "2. Update Customer" << endl;
        cout << "3. Delete Customer" << endl;
        cout << "4. Search Customer" << endl;
        cout << "5. Display Customer" << endl;
        cout << "6. Money from Customer" << endl;
        cout << "7. Money to Customer" << endl;
        cout << "8. Round money" << endl;
        cout << "9. Type of mail" << endl;
        cout << "10. Type of currency" << endl;
        cout << "0. Exit" << endl;
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
            MoneyFromCus();
            break;
        case 7:
            MoneyToCus();
            break;
        case 8:
            RoundMoney();
            break;
        case 9:
            TypeOfMail();
            break;
        case 10:
            TypeOfCurrency();
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
void Customer::MoneyFromCus()
{
    
}
void Customer::MoneyToCus()
{
    
}
void Customer::RoundMoney()
{
    
}
void Customer::TypeOfMail()
{
    
}
void Customer::TypeOfCurrency()
{
    
}

