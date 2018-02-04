#include <iostream>
#include <string>
#include <cstdlib> 
using namespace std;

class CounterType
{
public:
    int count;
    int setCount(int num);
    int increaseCount();
    int decreaseCount();
    int currentCount();
    void output();
};

int main()
{
    CounterType c;
    int userInput, counter;
    cout<<"What do you want to set the counter to?"<<endl;
    cin>>userInput;
    counter = c.setCount(userInput);
    cout<<"The current count is ";
    c.output();
    cout<<endl;
    counter = c.increaseCount();
    cout<<"increase count: ";
    c.output();
    cout<<endl;
    counter = c.decreaseCount();
    cout<<"decrease count: ";
    c.output();
    cout<<endl;
    
    return 0;
}

int CounterType::setCount(int num)
{
    count = num;
    return count;
}

int CounterType::increaseCount()
{
    count++;
    return count;
}

int CounterType::decreaseCount()
{
    count--;
    return count;
}

int CounterType::currentCount()
{
    return count;
}

void CounterType::output()
{
    cout<<count;
}