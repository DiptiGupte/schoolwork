#include <iostream>

using namespace std;

double convertToMPH(int min, int sec);
double convertToMPH(double kph);

int main()
{
    int m, s;
    double tester1, tester2, k;
    char ans;
    
    do
    {
        
        cout<<"Enter min and sec per hour: ";
        cin>>m>>s;
        tester1 = convertToMPH(m, s);
        cout<<"That is "<<tester1<<" mph."<<endl;

        cout<<"Enter kph: ";
        cin>>k;
        tester2 = convertToMPH(k);
        
        cout<<"That is "<<tester2<<" mph."<<endl;
        cout<<"Test again? (y/n)";
        cin>>ans;
    }
    while(ans == 'y' || ans == 'Y');
    
    return 0;
}

double convertToMPH(int min, int sec)
{
    min = min + (sec/60.0);
    double mph = min / 60.0;
    return mph;
}

double convertToMPH(double kph)
{
    double mph = kph / 1.61;
    return mph;
}