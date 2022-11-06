#include <bits/stdc++.h>
#include "customer.cpp"
using namespace std;
vector<Customer> customers;
void readCustomer(string filePath)
{
    ifstream input(filePath);
    if (!input.is_open())
    {
        cout << "Error opening file" << endl;
        return;
    }
    string ID, name, email, phone, bill, currency, temp;
    map<size_t, string> rawData;
    size_t index = 1;
    getline(input, temp);
    while (getline(input, temp) && temp != "")
    {
        stringstream splitData(temp);
        string word;
        while (splitData >> word)
        {
            rawData[index++] = word;
        }
        ID = rawData[1];
        currency = rawData[index-1];
        bill = rawData[index - 2];
        phone = rawData[index - 3];
        email = rawData[index - 4];
        name = "";
        for (size_t i = 2; i < index - 4; i++)
        {
            name += rawData[i] + " ";
        }
        name.pop_back();
        customers.push_back(Customer(ID, name, email, phone, bill, currency));
        index = 1;
    }
    input.close();
}
void printCustomer()
{
    cout << "ID" << '\t' << "Name" << setw(25) << "Phone" << '\t' << '\t' << '\t' << "Email" << setw(35) << "Bill" << setw(25) << "Currency" << endl;
    for(int i = 0; i < customers.size(); i++)
    {
        cout << customers[i].getID() << '\t' << customers[i].getName() << setw(34-customers[i].getName().length()) << customers[i].getPhone() 
        << '\t' << '\t' << customers[i].getEmail() << setw(40-customers[i].getEmail().length()) << customers[i].getBill() << setw(25) << customers[i].getCurrency() << endl;

    }
}
int main()
{
    readCustomer(FILE_PATH);
    printCustomer();
    system("pause");
    return 0;
}
