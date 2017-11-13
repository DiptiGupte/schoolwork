#include <iostream>
#include <string>
using namespace std;

int main()
{
    string name;
    int age;
    double height;
    cout<<"What is your cousin's name?"<<endl;
    cin>>name;
    if(name == "Katie")
    {
        cout<<"Go to the Winchester Mystery House."<<endl;
    }
    else
    {
        cout<<"What is your cousin's age?"<<endl;
        cin>>age;
        cout<<"What is your cousin's height (in inches)?"<<endl;
        cin>>height;
        if(age > 12 && height >= 60)
        {
            cout<<"Go to Great America."<<endl;
        }
        else if(age > 12 && height < 60)
        {
            cout<<"Go to the mall."<<endl;
        }
        else if(age < 12 && height >= 60)
        {
            cout<<"Go to the carnival."<<endl;
        }
        else
        {
            cout<<"Go to Chuck E. Cheese."<<endl;
        }
    }
    return 0;
}