#include <iostream>
#include <cctype>
#include <string> 

using namespace std;

int main()
{
    string str;
    cout<<"enter a sentence containing 100 characters or less:"<<endl;
    getline(cin, str);
    if(str.length() > 100)
    {
        cout<<"error: too many characters"<<endl;
    }
    else
    {
        int last = str.length();
        str[last - 1] = '.';
        for(int i =0; i < str.length(); i++)
        {
            if(i == 0)
            {
                str[i] = toupper(str[i]);
            }
            else
            {
                str[i] = tolower(str[i]);
            }

            if(i < str.length() - 1)
            {
                if(isspace(str[i]) && isspace(str[i + 1]))
                {
                    str.erase(i + 1, 1);
                }
            }
        }
        cout<<str<<endl;
        return 0;
    }
}