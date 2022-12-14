#include <bits/stdc++.h>
#include "customer.cpp"
// #include "ConsoleTable.cpp"
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
        
        address = "";
        while (rawData[index - 1][1] != '*' )
        {
            address = rawData[index - 1] + " " + address;
            index--;
            if (rawData[index - 1][1] == '*')
                break;
        }
        ID = rawData[1];
        feedback = rawData[index - 1];
        service = rawData[index - 2];
        currency = rawData[index - 3];
        bill = rawData[index - 4];
        phone = rawData[index - 5];
        email = rawData[index - 6];
        name = "";
        for(size_t i = 2; i < index - 6; i++)
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
    // exchange all bill to USD with rate, setprecision(3) to show 3 decimal places
    for (size_t i = 0; i < customers.size(); i++)
    {
        if (customers[i].getCurrency() == "USD")
        {
            customers[i].setBill(to_string(stof(customers[i].getBill()) * 1));
        }
        else if (customers[i].getCurrency() == "VND")
        {
            // if the bill has more than 6 digits, it will be multiply by 1000 to get the correct value
            if (customers[i].getBill().length() > 7)
            {
                customers[i].setBill(to_string(stof(customers[i].getBill()) * 1000 / 23.000));
            }
            else
            {
                customers[i].setBill(to_string(stof(customers[i].getBill()) / 23.000));
            }
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
        else if (customers[i].getCurrency() == "RUB")
        {
            customers[i].setBill(to_string(stof(customers[i].getBill()) * 0.014));
            customers[i].setCurrency("USD");
        }
    }
}
void SortMenu(vector<Customer> &customers)
{
    // readCustomer(FILE_PATH);
    int opt;
    // Sort by ID, Name, Bill, Service, Feedback
    cout << "1. Sort by Ascending ID" << endl;
    cout << "2. Sort by Ascending Name" << endl;
    cout << "3. Sort by Ascending Bill" << endl;
    cout << "4. Sort by Ascending Service" << endl;
    cout << "5. Sort by Ascending Feedback" << endl;
    cout << "6. Sort by Descending ID" << endl;
    cout << "7. Sort by Descending Name" << endl;
    cout << "8. Sort by Descending Bill" << endl;
    cout << "9. Sort by Descending Service" << endl;
    cout << "10. Sort by Descending Feedback" << endl;
    cout << "0. Back to main menu" << endl;
    cout << "Enter your option: ";
    cin >> opt;
    switch(opt)
    {
        case 1:
            SortCustomer(customers, 0, customers.size() - 1, 1, true);
            break;
        case 2:
            SortCustomer(customers, 0, customers.size() - 1, 2, true);
            break;
        case 3:
            ExchangeCurrency();
            SortCustomer(customers, 0, customers.size() - 1, 3, true);
            break;
        case 4:
            SortCustomer(customers, 0, customers.size() - 1, 4, true);
            break;
        case 5:
            SortCustomer(customers, 0, customers.size() - 1, 5, true);
            break;
        case 6:
            SortCustomer(customers, 0, customers.size() - 1, 1, false);
            break;
        case 7:
            SortCustomer(customers, 0, customers.size() - 1, 2, false);
            break;
        case 8:
            ExchangeCurrency();
            SortCustomer(customers, 0, customers.size() - 1, 3, false);
            break;
        case 9:
            SortCustomer(customers, 0, customers.size() - 1, 4, false);
            break;
        case 10:
            SortCustomer(customers, 0, customers.size() - 1, 5, false);
            break;
        case 0:
            return;
    }
    cout << endl;
    cout << "Sort successfully!" << endl;
    // update file
    ofstream input(FILE_PATH);
    input << left << setw(10) << "ID" << setw(30) << "Name" << setw(30) << "Email" << setw(30) << "Phone" << setw(30) << "Bill" << setw(30) << "Currency" << setw(30) << "Service" << setw(30) << "Feedback" << setw(30) << "Address" << endl;
    for (int i = 0; i < customers.size(); i++)
    {
        // write data to file and set space between data to 30
        input << left << setw(10) << customers[i].getID() << setw(30) << customers[i].getName() << setw(30) << customers[i].getEmail() << setw(30) << customers[i].getPhone() << setw(30) << customers[i].getBill() << setw(30) << customers[i].getCurrency() << setw(30) << customers[i].getService() << setw(30) << customers[i].getFeedback() << setw(30) << customers[i].getAddress() << endl;
    }
    input.close();
    // read data from file after update
    // print data
    // printCustomer(customers);
}
void SearchMenu(vector<Customer> &customers)
{
    // Search Customer by ID, Name, Bill, Phone, Service, Feedback, Email
    // Print if found
    // Print not found if not found
    // readCustomer(FILE_PATH);
    int opt;
    string keyword;
    cout << "1. Search by ID" << endl;
    cout << "2. Search by Name" << endl;
    cout << "3. Search by Bill" << endl;
    cout << "4. Search by Phone" << endl;
    cout << "5. Search by Service" << endl;
    cout << "6. Search by Feedback" << endl;
    cout << "7. Search by Email" << endl;
    cout << "0. Back to main menu" << endl;
    cout << "Enter your option: ";
    cin >> opt;
    switch(opt)
    {
        case 1:
            cout << "Enter ID: ";
            cin >> keyword;
            SearchCustomer(customers, keyword, 1);
            
            break;
        case 2:
            cout << "Enter Name: ";
            cin.ignore();
            getline(cin, keyword);
            SearchCustomer(customers, keyword, 2);
            break;
        case 3:
            cout << "Enter Bill: ";
            cin >> keyword;
            SearchCustomer(customers, keyword, 3);
            break;
        case 4:
            cout << "Enter Phone: ";
            cin >> keyword;
            SearchCustomer(customers, keyword, 4);
            break;
        case 5:
            cout << "Enter Service: ";
            cin >> keyword;
            SearchCustomer(customers, keyword, 5);
            break;
        case 6:
            cout << "Enter Feedback: ";
            cin >> keyword;
            SearchCustomer(customers, keyword, 6);
            break;
        case 7:
            cout << "Enter Email: ";
            cin >> keyword;
            SearchCustomer(customers, keyword, 7);
            break;
        case 0:
            return;
    }
}
void Menu(vector<Customer> &customers)
{
    // create table to choose option
    int opt;
    cout << "---- SRC by Tran Nam Phong - B20DCVT288 ----" << endl;
    cout << "1. Add new customer" << endl;
    cout << "2. Edit customer" << endl;
    cout << "3. Delete customer" << endl;
    cout << "4. Sort customer" << endl;
    cout << "5. Search customer" << endl;
    cout << "0. Exit" << endl;
    cout << "Enter your choice: ";
    cin >> opt;
    switch (opt)
    {
        case 1:
            AddCustomer(customers);
            break;
        case 2:
            EditCustomer(customers);
            break;
        case 3:
            DeleteCustomerByID(customers);
            break;
        // case 4 is menu sort
        case 4:
            SortMenu(customers);
            printCustomer();
            break;
        // case 5 is menu search
        case 5:
            SearchMenu(customers);
            break;
        case 0:
            exit(0);
            break;
        default:
            cout << "Invalid option" << endl;
            break;
    }
    Menu(customers);
}
int main()
{
    readCustomer(FILE_PATH);
    Menu(customers);
    // General
    // AddCustomer(customers);
    // EditCustomer(customers);
    // DeleteCustomerByID(customers);
    // ExchangeCurrency();
    // Sort
    // SortCustomer(customers, 0, customers.size() - 1, 5, true);
    // Search
    // SearchCustomer(customers, "Leon Goretzka", 2);
    // printCustomer();
    system("pause");
    return 0;
}
