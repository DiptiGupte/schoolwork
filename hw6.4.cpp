#include <iostream>
#include <cctype>
#include <string> 

using namespace std;

string removevowels(string s);

int main()
{
    string str, noVowels;
    cout<<"enter a sentence:"<<endl;
    getline(cin, str);
    noVowels = removevowels(str);
    cout<<noVowels<<endl;
}

string removevowels(string s)
{
    string newString;
    for(int i = 0; i < s.length(); i++)
    {
        if(s[i] != 'a' && s[i] != 'A' && s[i] != 'e' && s[i] != 'E' && s[i] != 'i' && s[i] != 'I' && s[i] != 'o' && s[i] != 'O' && s[i] != 'u' && s[i] != 'U')
        {
            newString += s[i];
        }
    }
    return newString;
}
