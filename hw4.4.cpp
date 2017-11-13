#include <iostream>
#include <string>

using namespace std;

void weight();
void input_weight(int user_input, double& lb_kg, double& o_g);
void poundsToKilograms(double lb, double o, double& kg, double& g);
void kilogramsToPounds(double kg, double g, double& lb, double& o);
void output_weight(int user_input, double weight1, double weight2);

void length();
void input_length(int user_input, double& f_m, double& i_cm);
void feetToMeters(double f, double i, double& m, double& cm);
void metersToFeet(double m, double cm, double& ft, double& i);
void output_length(int user_input, double length1, double length2);

int main()
{
    int userInput;
    string doneWithComputation;
    
    do
    {
        cout<<"Do you want to convert between lengths or weights? \n"<<
        "Enter 1 for lengths and grams and 2 for weights: ";
        cin>>userInput;
        if(userInput == 1)
        {
            length();
        }
        else
        {
            weight();
        }
        cout<<"Do you want to repeat this computation(yes/no):";
        cin>>doneWithComputation;
    }
    while(doneWithComputation == "yes");
    return 0;
}

//weight calculations
void weight()
{
    double pounds = 0;
    double ounces = 0;
    double kilograms = 0;
    double grams = 0;
    int userInput;
    
    cout<<"Do you want to convert for pounds and ounces to kilograms and grams or vice versa? \n"<<
        "Enter 1 for pounds and ounces to kilograms and grams and 2 for kilograms and grams to pounds and ounces: ";
    cin>>userInput;
    if(userInput == 1)
    {
        input_weight(userInput, pounds, ounces);
        poundsToKilograms(pounds, ounces, kilograms, grams);
        output_weight(userInput, kilograms, grams);
    }
    else
    {
        input_weight(userInput,kilograms, grams);
        kilogramsToPounds(kilograms, grams, pounds, ounces);
        output_weight(userInput, pounds, ounces);
    }
}

void input_weight(int user_input, double& lb_kg, double& o_g)
{
    if(user_input == 1)
    {
        cout<<"enter amount of pounds: ";
        cin>>lb_kg;
        cout<<"enter amount of ounces: ";
        cin>>o_g;
    }
    else
    {
        cout<<"enter amount of kilograms: ";
        cin>>lb_kg;
        cout<<"enter amount of grams: ";
        cin>>o_g;
    }
}

void poundsToKilograms(double lb, double o, double& kg, double& g)
{
    kg = lb/2.2046;
    g = o / 16 / 2.2046 * 1000;
}

void kilogramsToPounds(double kg, double g, double& lb, double& o)
{
    lb = kg * 2.2046;
    o = g * 16 * 2.2046 / 1000;
}

void output_weight(int user_input, double weight1, double weight2)
{
    if(user_input == 1)
    {
        cout<<"That is equal to "<<weight1<<" kilograms and "<<weight2<<" grams."<<endl;
    }
    else
    {
        cout<<"That is equal to "<<weight1<<" pounds and "<<weight2<<" ounces."<<endl;
    }
}

//length calculations
void length()
{
    double feet = 0;
    double inches = 0;
    double meters = 0;
    double centimeters = 0;
    int userInput;
    
    cout<<"Do you want to convert for feet and inches to meters and centimeters or vice versa? \n"<<
        "Enter 1 for feet and inches to meters and centimeters and 2 for meters and centimeters to feet and inches: ";
    cin>>userInput;
    if(userInput == 1)
    {
        input_length(userInput,feet, inches);
        feetToMeters(feet, inches, meters, centimeters);
        output_length(userInput, meters, centimeters);
    }
    else
    {
        input_length(userInput,meters, centimeters);
        metersToFeet(meters, centimeters, feet, inches);
        output_length(userInput, feet, inches);
    }
}

void input_length(int user_input, double& f_m, double& i_cm)
{
    if(user_input == 1)
    {
        cout<<"enter amount of feet: ";
        cin>>f_m;
        cout<<"enter amount of inches: ";
        cin>>i_cm;
    }
    else
    {
        cout<<"enter amount of meters: ";
        cin>>f_m;
        cout<<"enter amount of centimeters: ";
        cin>>i_cm;
    }
}

void feetToMeters(double f, double i, double& m, double& cm)
{
    m = f * 0.3048;
    cm = i / 12 * 0.3048 * 100;
}

void metersToFeet(double m, double cm, double& ft, double& i)
{
    ft = m / 0.3048;
    i = cm * 12 / 0.3048 / 100;
}

void output_length(int user_input, double length1, double length2)
{
    if(user_input == 1)
    {
        cout<<"That is equal to "<<length1<<" meters and "<<length2<<" centimeters."<<endl;
    }
    else
    {
        cout<<"That is equal to "<<length1<<" feet and "<<length2<<" inches."<<endl;
    }
}