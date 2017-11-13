#include <iostream>

using namespace std;

struct Fraction
{
    int numerator;
    int denominator;
};

void printFaction(Fraction f);
Fraction mult(Fraction f1, Fraction f2);
Fraction add(Fraction f1, Fraction f2);

int main()
{
    Fraction f1;
    f1.numerator = 3;
    f1.denominator = 4;
    
    Fraction f2;
    f2.numerator = 5;
    f2.denominator = 6;
    
    printFaction(mult(f1, f2));
    printFaction(add(f1, f2));
}

void printFaction(Fraction f)
{
   cout<<f.numerator<<"/"<<f.denominator<<endl; 
}

Fraction mult(Fraction f1, Fraction f2)
{
    Fraction multFract;
    multFract.numerator = f1.numerator * f2.numerator;
    multFract.denominator = f1.denominator * f2.denominator;
    return multFract;
}

Fraction add(Fraction f1, Fraction f2)
{
    Fraction addFract;
    f1.numerator = f1.numerator * f2.denominator;
    f2.numerator = f2.numerator * f1.denominator;
    addFract.numerator = f1.numerator + f2.numerator;
    addFract.denominator = f1.denominator * f2.denominator;
    return addFract;
}