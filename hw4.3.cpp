#include <iostream>
#include <cmath>

using namespace std;

void calculation(double a,double b,double c,double& A, double& P); 

int main()
{
    double side1, side2, side3;
    double area = 0;
    double perimeter = 0;
    cout<<"enter three sides: ";
    cin>>side1>>side2>>side3;
    calculation(side1, side2, side3, area, perimeter);
    if(area == -1 && perimeter == -1)
    {
        cout<<"invalid input"<<endl;
    }
    else
    {
        cout<<"area = "<<area<<endl;
        cout<<"perimeter = "<<perimeter<<endl;
    }
    return 0;
}

void calculation(double a,double b,double c,double& A, double& P)
{
    if((a + b > c) && (a + c > b) && (b + c > a))
    {
        double s = (a + b + c)/2;
        A = sqrt(s*(s-a)*(s-b)-(s-c));
        P = a + b + c;
    }
    else
    {
        A = -1;
        P = -1;
    }
}
