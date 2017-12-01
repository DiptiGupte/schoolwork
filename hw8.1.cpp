#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;

void merge(ifstream& istream1, ifstream& istream2, ofstream& ostream);

int main()
{
    ifstream input1, input2;
    ofstream output;
    
    input1.open("81odds.txt");
    if(input1.fail())
    {
        cout<<"input file opening failed"<<endl;
        exit(1);
    }
    input2.open("81evens.txt");
    if(input.fail())
    {
        cout<<"input file opening failed"<<endl;
        exit(1);
    }
    output.open("81output.txt");
    if(output.fail())
    {
        cout<<"output file opening failed"<<endl;
        exit(1);
    }
    
    merge(input1, input2, output);
    
    return 0;
}

void merge(ifstream& istream1, ifstream& istream2, ofstream& ostream)
{
    int nums[100];
    int i = 0;
    while(istream1>>nums[i])
    {
        i++;
    }
    while(istream2>>nums[i])
    {
        i++;
    }
    istream1.close();
    istream2.close();
    
    for(int j = i; j >= 0; j--)
    {
        for(int k = 0; k < j - 1; k++)
        {
            if(nums[k] > nums[k + 1])
            {
                int temp = nums[k];
                nums[k] = nums[k + 1];
                nums[k + 1] = temp;
            }
        }
    }
    
    for(int l = 0; l < i; l++)
    {
        ostream<<nums[l]<<endl;
    }
    ostream.close();
}