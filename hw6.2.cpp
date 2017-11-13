#include <iostream>
#include <cctype>
#include <string> 

using namespace std;

int main()
{
    string str;
    char letter[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
    int wordCount = 0, count[26], index = 0;
    
    cout<<"enter a sentence:"<<endl;
    getline(cin, str);
    
    for(int k = 0; k < 26; k++)
    {
        count[k] = 0;
    }
    
    for(int i = 0; i < str.length(); i++)
    {
        if(isspace(str[i]) || ispunct(str[i])) 
        {
            wordCount++;
        }
        else
        {
            str[i] = tolower(str[i]);
            while(str.at(i) != letter[index])
            {
                index++;
            }
            count[index]++;
            index = 0;
        }
    }
    
    cout<<wordCount<<" words"<<endl;
    for(int j = 0; j < 26; j++)
    {
        if(count[j] != 0)
        {
            cout<<count[j]<<"\t"<<letter[j]<<endl;
        }
    }
    return 0;
}