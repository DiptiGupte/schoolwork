#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include <iomanip>

using namespace std;

void inputAndOutput(ifstream& istream, ofstream& ostream);
void copy(ifstream& i_stream, ofstream& o_stream);

int main()
{
    ifstream in_stream;
    ofstream out_stream;
    
    in_stream.open("83input.txt");
    if(in_stream.fail())
    {
        cout<<"input file opening failed"<<endl;
        exit(1);
    }
    
    out_stream.open("83output.txt");
    if(out_stream.fail())
    {
        cout<<"output file opening failed"<<endl;
        exit(1);
    }
    
    inputAndOutput(in_stream, out_stream);
    
    in_stream.close();
    out_stream.close();
    
    ifstream in_stream2;
    ofstream out_stream2;
    
    in_stream.open("83output.txt");
    if(in_stream.fail())
    {
        cout<<"input file opening failed"<<endl;
        exit(1);
    }
    
    out_stream.open("83input.txt");
    if(out_stream.fail())
    {
        cout<<"output file opening failed"<<endl;
        exit(1);
    }
    copy(in_stream2, out_stream2);
    return 0;
}

void inputAndOutput(ifstream& istream, ofstream& ostream)
{
    ostream<<setw(5)<<"This program get input from a file and outputs the students' information, as well as, the average test score of the students."<<endl; 
    ostream<<"\n";
    char next;
    string lastName, firstName;
    int score, count;
    double sum;
    while(!istream.eof())
    {
        sum = 0;
        count = 0;
        istream >> lastName;
        istream >> firstName;
        ostream<<lastName<<setw(5)<<firstName<<setw(5);
        
        do
        {
            istream>>score;
            ostream<<score<<setw(5);
            sum += score;
            count++;
            istream.get(next);
        }
        while(next != '\n' && (!istream.eof()));
        
        while(count < 10)
        {
            ostream<<"0"<<setw(5);
            count++;
        }
        
        ostream<<" average: "<<(sum/10)<<endl;
    }
}

void copy(ifstream& i_stream, ofstream& o_stream)
{
    char next;
    while(!i_stream.eof())
    {
        i_stream.get(next);
        o_stream << next;
    }
}