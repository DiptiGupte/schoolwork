#include <iostream>
#include <cmath>
using namespace std;

double windChillIndex(double v, double t);

int main()
{
    double velocity, temp;
    cout<<"enter the wind speed in m/sec: ";
    cin>>velocity;
    cout<<"enter the temperature in degrees Celsius (temperature <=10): ";
    cin>>temp;
    
    cout<<"The wind chill index is "<<windChillIndex(velocity, temp)<<endl;
}

double windChillIndex(double v, double t)
{
    return (33 - ((10*sqrt(v) - v + 10.5)*(33 - t))/23.1);
}