#include <iostream>
using namespace std;
int main()
{
    double gallons, liters;
    cout << "Enter amount of gallons." << endl;
    cin >> gallons;
    liters = gallons * 3.78541; 
    cout << "That is equal to " << liters << " liters." << endl;	
    return 0;
}
