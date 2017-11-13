#include <iostream>
#include <string>

using namespace std;

void input(int& hour, int& min);
void convertion(int& hour, char& amOrPm);
void output(int hour, int min, char amOrPm);

int main()
{
    int h = 0, m = 0;
    char am_pm = 'X';
    string doneWithComputation;
    do
    {
        input(h, m);
        convertion(h, am_pm);
        output(h, m, am_pm);
        cout<<"Do you want to repeat this computation(yes/no):";
        cin>>doneWithComputation;
    }
    while(doneWithComputation == "yes");
    return 0;
}

void input(int& hour, int& min)
{
    cout<<"enter the hour: ";
    cin>>hour;
    cout<<"enter the minutes: ";
    cin>>min;
}

void convertion(int& hour, char& amOrPm)
{
    if(hour <= 12)
    {
        amOrPm = 'A';
    }
    else
    {
        hour -= 12;
        amOrPm = 'P';
    }
        
}

void output(int hour, int min, char amOrPm)
{
    if(min < 10)
    {
        cout<<hour<<":0"<<min<<" "<<amOrPm<<endl;
    }
    else
    {
        cout<<hour<<":"<<min<<" "<<amOrPm<<endl;
    }
}