#include <iostream>

using namespace std;

int main()
{
    for(int i = 5; i < 10; i++)
    {
        cout<<"start ";
        for(int j = 5; j > 0; j--)
        {
            cout<<i*2<<" "<<j<<", "; 
        }
        cout<<" end"<<endl;
    }
    return 0;
}