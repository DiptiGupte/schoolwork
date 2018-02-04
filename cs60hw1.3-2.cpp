#include <iostream>
#include <cstdlib> 
using namespace std;

class GasPump
{
public:
    void display();
    void fuelPrice();
    void reset();
    void StartStopDispensing();
    void setPrice(double price);

private:
    double costPerGallon;
    double amountCharged;
    double gallonUsed;
};

int main()
{
    GasPump g;
    double cost;
    cout<<"enter the cost per gallon where you live: ";
    cin>>cost;
    g.reset();
    g.setPrice(cost);
    g.display();
    g.StartStopDispensing();
    g.fuelPrice();
    g.display();
    
    return 0;
}

void GasPump::display()
{
    cout<<"Gallons used: " << gallonUsed<<endl;
    cout<<"Amount charged: $" << amountCharged<<endl;
    cout<<"Cost per gallon: $" << costPerGallon<<"/g"<<endl;
}

void GasPump::fuelPrice()
{
    amountCharged = costPerGallon * gallonUsed;
}

void GasPump::reset()
{
    amountCharged = 0;
    gallonUsed = 0;
}

void GasPump::StartStopDispensing()
{
    char userInput;
    bool repeat = true;
    do
    {
        gallonUsed++;
        cout<<"You have used "<<gallonUsed<<" gallons. Do you want to continue? (type y/n): ";
        cin>>userInput;
        if(userInput == 'n')
        {
            repeat = false;
        }
    }
    while(repeat);
}

void GasPump::setPrice(double price)
{
    costPerGallon = price;
}