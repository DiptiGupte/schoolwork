#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>

using namespace std;

void averageWordLength(ifstream& istream);

int main()
{
    ifstream in_stream;
    
    in_stream.open("84input.txt");
    if(in_stream.fail())
    {
        cout<<"input file opening failed"<<endl;
        exit(1);
    }
    averageWordLength(in_stream);
    in_stream.close();
    
    return 0;
}

void averageWordLength(ifstream& istream)
{
    string str;
    int wordCount = 1; 
    int charTotal = 0;
    while(getline(istream, str))
    {
        for(int i = 0; i < str.length(); i++)
        {
            if(str[i] == ' ' || str[i] == ',' || str[i] == '.')
            {
                wordCount++;
            }
            else
            {
                charTotal++;
            }
        }
    }
    cout<<"average word length: "<<charTotal/wordCount<<endl;
}