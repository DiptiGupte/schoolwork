#include <iostream>
using namespace std;
int main()
{
    const double SWEETNER = 0.001;
    double amountForMouse, weightOfMouse, weightOfDieter, amountOfSweetner, amountOfSoda;

    cout<<"Enter the amount of artificial sweetener needed to kill a mouse, the weight of the mouse, and the weight at which you will stop dieting at." << endl;

    cin >> amountForMouse >> weightOfMouse >> weightOfDieter;

    amountOfSweetner=(weightOfDieter * amountForMouse) / weightOfMouse;

    amountOfSoda = amountOfSweetner / SWEETNER;
    
    cout<<"You can drink "<< amountOfSoda<<"amount of soda without dying."<<endl;
    return 0;
}
