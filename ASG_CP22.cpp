#include <bits/stdc++.h>
#include "customer.cpp"
#include "ConsoleTable.cpp"
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
    ConsoleTable table{ "ID", "Name", "Email", "Phone", "Bill", "Currency"};
    
    table.setPadding(2);
    table.setStyle(0);

    for (size_t i = 0; i < customers.size(); i++)
    {
        table.addRow({ customers[i].getID(), customers[i].getName(), customers[i].getEmail(), customers[i].getPhone(), customers[i].getBill(), customers[i].getCurrency() });
    }
    cout << table;

}
int main()
{
    readCustomer(FILE_PATH);
    printCustomer();
    system("pause");
    return 0;
}
