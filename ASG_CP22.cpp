#include <bits/stdc++.h>
#include "customer.cpp"
using namespace std;
int main()
{
    Customer cus;
    cus.readCustomer();
    cus.writeCustomer();
    cout << "Press any key in the menu to continue: " << endl;
    cus.menuCustomer();
    system("pause");
    return 0;
}
