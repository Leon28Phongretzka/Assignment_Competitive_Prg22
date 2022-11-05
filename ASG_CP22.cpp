#include <bits/stdc++.h>
// #include "customer.cpp"
using namespace std;
int main()
{
    ifstream file;
    file.open("D:\\4.Code\\ASG_CP22\\data1.txt");
    // read infor from file data1.txt
    string info; 
    getline(file, info);
    // use map to store data
    map<string, string> data;
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
        // use map data to store data
        data[to_string(ID)] = name;
        // set wide between name and email
        int wide = 30 - name.length();
        // cout << wide << endl;
        data[to_string(ID)] += string(wide, ' ');
        data[to_string(ID)] = data[to_string(ID)] + mail + '\t' + phone + '\t' + amount + '\t' + currency;
    }
    // print data
    for (auto &i : data)
    {
        cout << i.first << "\t" << i.second << endl;
    }
    system("pause");
    return 0;
}
