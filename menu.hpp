#include "customer.cpp"
vector<Customer> customers;
using namespace std;

void MainMenu();
void Search();
void Sort();
void subSort();
void aftSort();

void mainMenu()
{
    int choice;
    cout << "1. Search" << endl;
    cout << "2. Sort" << endl;
    cout << "3. Exit" << endl;

    do
    {
        cout << "Enter your choice: ";
        cin >> choice;
        if(choice < 1 || choice > 5)
        {
            cout << "Invalid choice" << endl;
        }
    } while ( choice < 1 || choice > 5);
    switch (choice)
    {
        case 1: 
    }
}