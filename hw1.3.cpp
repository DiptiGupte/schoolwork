#include <iostream>
using namespace std;
int main()
{
    double pounds, mets, min, caloriesBurned, kilogram;

    cout << "Enter your weight in pounds, the number of METS for an activity and the number of minutes spent on that activity."<< endl;

    cin >> pounds >> mets >> min;

    kilogram = pounds * 2.2;

    caloriesBurned = 0.0175 * mets * kilogram;

    cout << "You burned about " << caloriesBurned << "calories." << endl;
    return 0;
}
