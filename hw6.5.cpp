#include <iostream>
#include <cctype>
#include <string> 

using namespace std;

void stringToInt(string s);

int main()
{
    string str;
    int num;
    cout<<"enter a string: ";
    getline(cin, str);
    stringToInt(str);
    return 0;
}

void stringToInt(string s)
{
    for(int i = 0; i < s.length(); i++)
    {
        cout<<static_cast<int>(s[i]) - '0';
    }
    cout<<endl;
}