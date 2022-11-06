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
    string ID, name, email, phone, bill, currency, service, feedback, address, line;
    map<size_t, string> rawData;
    size_t index = 1;
    getline(input, line);
    while (getline(input, line) && line != "")
    {
        stringstream splitData(line);
        string word;
        while (splitData >> word)
        {
            rawData[index++] = word;
        }
        ID = rawData[1];

        int addressIndex = rawData.size();
        address = "";
        // address from the feedback to the end of the line
        for(size_t i = rawData.size(); i > 0 ; i--)
        {
            if(rawData[i][1] == '*') break;
            address = rawData[i] + " " + address;
            addressIndex--;
        }

        feedback = rawData[addressIndex];
    
        service = rawData[addressIndex - 1];
    
        currency = rawData[addressIndex - 2];
        
        bill = rawData[addressIndex - 3];
        
        phone = rawData[addressIndex - 4];

        email = rawData[addressIndex - 5];
        
        name = "";
        for(size_t i = 2; i <= addressIndex - 6; i++)
        {
            name += rawData[i] + " ";
        }
        name.pop_back();
        customers.push_back(Customer(ID, name, email, phone, bill, currency, service, feedback, address));
        index = 1;
    }
    input.close();
}
void printCustomer()
{
    ConsoleTable table{"ID", "Name", "Email", "Phone", "Bill", "Currency", "Service", "Feedback", "Address"};
    table.setPadding(2);
    table.setStyle(0);
    for (size_t i = 0; i < customers.size(); i++)
    {
        table += {customers[i].getID(), customers[i].getName(), customers[i].getEmail(), customers[i].getPhone(), customers[i].getBill(), customers[i].getCurrency(), customers[i].getService(), customers[i].getFeedback(), customers[i].getAddress()};
    }
    cout << table;

}
void ExchangeCurrency()
{
    // exchange all bill to USD with rate
    for (size_t i = 0; i < customers.size(); i++)
    {
        if (customers[i].getCurrency() == "USD")
        {
            continue;
        }
        else if (customers[i].getCurrency() == "VND")
        {
            customers[i].setBill(to_string(stof(customers[i].getBill()) / 23.000));
            customers[i].setCurrency("USD");
        }
        else if (customers[i].getCurrency() == "EUR")
        {
            customers[i].setBill(to_string(stof(customers[i].getBill()) * 1.18));
            customers[i].setCurrency("USD");
        }
        else if (customers[i].getCurrency() == "GBP")
        {
            customers[i].setBill(to_string(stof(customers[i].getBill()) * 1.31));
            customers[i].setCurrency("USD");
        } 
    }
}
int main()
{
    readCustomer(FILE_PATH);
    ExchangeCurrency();
    printCustomer();
    system("pause");
    return 0;
}
