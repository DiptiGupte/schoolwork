#include <iostream>
#include <cstdlib> 
using namespace std;

class Month
{
public:
    Month(char mOne, char mTwo, char mThree);
    Month(int mInt);
    Month();
    void outputMonthInt();
    void outputMonthLetter();
    Month nextMonth();
    
private:
    int month;
};

int main()
{
    cout<<"default constructor test:"<<endl;
    Month m;
    m.outputMonthInt();
    m.outputMonthLetter();
    
    int num;
    cout<<"constructor using int: "<<endl;
    cout<<"enter a month: ";
    cin>>num;
    Month m2(num);
    m2.outputMonthInt();
    m2.outputMonthLetter();
    Month next = m2.nextMonth();
    cout<<"next ";
    next.outputMonthInt();
    
    char one, two, three;
    cout<<"constructor using first three letters: "<<endl;
    cout<<"enter the first letter of the month (lower-cased): ";
    cin>>one;
    cout<<"enter the second letter of the month (lower-cased): ";
    cin>>two;
    cout<<"enter the last letter of the month (lower-cased): ";
    cin>>three;
    Month m3(one, two, three);
    m3.outputMonthInt();
    m3.outputMonthLetter();
    Month next2 = m3.nextMonth();
    cout<<"next ";
    next2.outputMonthLetter();
    
    return 0;
}

Month::Month(char mOne, char mTwo, char mThree)
{
    if(mOne == 'j' && mTwo == 'a' && mThree == 'n')
    {
        month = 1;
    }
    else if(mOne == 'f' && mTwo == 'e' && mThree == 'b')
    {
        month = 2;
    }
    else if(mOne == 'm' && mTwo == 'a' && mThree == 'r')
    {
        month = 3;
    }
    else if(mOne == 'a' && mTwo == 'p' && mThree == 'r')
    {
        month = 4;
    }
    else if(mOne == 'm' && mTwo == 'a' && mThree == 'y')
    {
        month = 5;
    }
    else if(mOne == 'j' && mTwo == 'u' && mThree == 'n')
    {
        month = 6;
    }
    else if(mOne == 'j' && mTwo == 'u' && mThree == 'l')
    {
        month = 7;
    }
    else if(mOne == 'a' && mTwo == 'u' && mThree == 'g')
    {
        month = 8;
    }
    else if(mOne == 's' && mTwo == 'e' && mThree == 'p')
    {
        month = 9;
    }
    else if(mOne == 'o' && mTwo == 'c' && mThree == 't')
    {
        month = 10;
    }
    else if(mOne == 'n' && mTwo == 'o' && mThree == 'v')
    {
        month = 11;
    }
    else if(mOne == 'd' && mTwo == 'e' && mThree == 'c')
    {
        month = 12;
    }
}

Month::Month(int mInt)
{
    month = mInt;
}

Month::Month()
{
    month = 1;
}

void Month::outputMonthInt()
{
    cout<<"month: "<<month<<endl; 
}

void Month::outputMonthLetter()
{
    if(month == 1)
    {
        cout<<"month: jan"<<endl; 
    }
    else if(month == 2)
    {
        cout<<"month: feb"<<endl; 
    }
    else if(month == 3)
    {
        cout<<"month: mar"<<endl; 
    }
    else if(month == 4)
    {
        cout<<"month: apr"<<endl; 
    }
    else if(month == 5)
    {
        cout<<"month: may"<<endl; 
    }
    else if(month == 6)
    {
        cout<<"month: jun"<<endl; 
    }
    else if(month == 7)
    {
        cout<<"month: jul"<<endl; 
    }
    else if(month == 8)
    {
        cout<<"month: aug"<<endl; 
    }
    else if(month == 9)
    {
        cout<<"month: sep"<<endl; 
    }
    else if(month == 10)
    {
        cout<<"month: oct"<<endl; 
    }
    else if(month == 11)
    {
        cout<<"month: nov"<<endl; 
    }
    else if(month == 12)
    {
        cout<<"month: dec"<<endl; 
    }
}

Month Month::nextMonth()
{
    if(month == 12)
    {
        return Month(1);
    }
    else
    {
        return Month(month + 1);
    }
}