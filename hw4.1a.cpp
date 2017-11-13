#include <iostream>

using namespace std;

int main()
{
    for(int i = 0; i < 5; i++)
    {
        cout<<"start ";
        for(int j = 0; j < 8; j++)
        {
            if(j <= i)
            {
                cout<<"o";
            }
            else
            {
                cout<<"x";
            }
        }
        cout<<" end"<<endl;
    }
    return 0;
}