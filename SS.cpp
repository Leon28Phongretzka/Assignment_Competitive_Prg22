#include <bits/stdc++.h>
using namespace std;
int main()
{
    ifstream file;
    file.open("D:\\4.Code\\ASG_CP22\\data1.txt");
    // read infor from file data1.txt
    string info; 
    getline(file, info);
    // use deque to store data
    deque<string> listCustomer;
    while(getline(file, info))
    {
        stringstream ss;
        ss << info;
        map<int,string> tokens;
        size_t index=1;
        // Split the string into tokens
        while (ss >> info)
        {
            tokens[index++] = info;
        }
        // Print the tokens
        // for (auto &token : tokens)
        // {
        //     cout << token.second << " ";
        // }
        // cout << index << endl;
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
        // cout << ID << " " << name << " " << phone << " " << mail << " " << amount << " " << currency << endl;
        Customer cus(ID, name, mail, phone, amount, currency);
        listCustomer.push_back(cus);
    }
    system("pause");
}
