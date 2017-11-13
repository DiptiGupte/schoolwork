#include <iostream>
#include <cmath>
#include <string>

using namespace std;

double const GRAVITY = 6.673 * pow(10, -8);

double force(int m1,int m2,int d);

int main()
{
    int mass1, mass2, distance;
    double F;
    string doneWithCalculations;
    
    do
    {
        F = force(mass1, mass2, distance);
        cout<<"The force between the two masses is "<<F<<" dyne."<<endl;
        cout<<"Do you want to repeat this calculation (yes/no): ";
        cin>>doneWithCalculations;
    }
    while(doneWithCalculations == "yes");
}

double force(int m1,int m2,int d)
{
    cout<<"enter mass 1: ";
    cin>>m1;
    cout<<"enter mass 2: ";
    cin>>m2;
    cout<<"enter the distance between the two masses: ";
    cin>>d;
    return(GRAVITY * m1 * m2)/pow(d, 2);
}