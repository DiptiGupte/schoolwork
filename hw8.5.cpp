#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>

using namespace std;

void fixer(ifstream& istream, ofstream& ostream);

int main()
{
    ifstream in_stream;
    ofstream out_stream;
    
    in_stream.open("85input.txt");
    if(in_stream.fail())
    {
        cout<<"input file opening failed"<<endl;
        exit(1);
    }
    
    out_stream.open("85output.txt");
    if(out_stream.fail())
    {
        cout<<"output file opening failed"<<endl;
        exit(1);
    }

    fixer(in_stream, out_stream);
    in_stream.close();
    out_stream.close();
    
    return 0;
}

void fixer(ifstream& istream, ofstream& ostream)
{
    string str;
    while(getline(istream, str))
    {
        for(int i = 0; i < str.length(); i++)
        {
            if(str[i] == ' ')
            {
                if(str[i - 1] == 'n' && str[i - 2] == 'i' && str[i - 3] == 'c')
                {
                    str[i + 1] = '>';
                    str[i + 2] = '>';
                }
                else if(str[i - 1] == 't' && str[i - 2] == 'u' && str[i - 3] == 'o' && str[i - 4] == 'c')
                {
                    str[i + 1] = '<';
                    str[i + 2] = '<';
                }
            }
            ostream<<str[i];
        }
    }
}