#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>

using namespace std;

struct StudentInfo
{
    string firstName;
    string lastName;
    int quiz[10];
    double average;
};

void inputAndOutput(ifstream& istream, ofstream& ostream);

int main()
{
    ifstream in_stream;
    in_stream.open("82input.txt");
    if(in_stream.fail())
    {
        cout<<"input file opening failed"<<endl;
        exit(1);
    }
    ofstream out_stream;
    out_stream.open("82output.txt");
    if(out_stream.fail())
    {
        cout<<"output file opening failed"<<endl;
        exit(1);
    }
    inputAndOutput(in_stream, out_stream);
    return 0;
}

void inputAndOutput(ifstream& istream, ofstream& ostream)
{
    StudentInfo s[1000];
    int i = 0;
    while(istream>>s[i].firstName)
    {
        istream>>s[i].lastName;
        for(int j = 0; j < 10; j++)
        {
            istream>>s[i].quiz[j];
        }
        int sum = 0;
        for(int m = 0; m < 10; m++)
        {
            sum += s[i].quiz[m];
        }
        s[i].average = sum/10;
        i++;
    }
    istream.close();
    
    for(int k = 0; k<i; k++)
    {
        ostream<<s[k].firstName<<" "<<s[k].lastName<<" ";
        for(int l = 0; l < 10; l++)
        {
            ostream<<s[k].quiz[l]<<" ";
        }
        ostream<<"average: "<<s[k].average<<endl;
    }
    ostream.close();
}