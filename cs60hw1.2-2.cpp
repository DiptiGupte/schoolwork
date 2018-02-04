#include <iostream>
#include <string>
#include <cstdlib> 
using namespace std;

class Point
{
public:
    void set(int x, int y);
    void move(int x, int y);
    void rotate();
    int getX() const;
    int getY() const;
    
private:
    int xCor, yCor;
};

int main()
{
    Point p;
    int x1, y1, xMove, yMove;
    bool runAgain = true;
    char userAnswer;
    do
    {
        cout<<"enter a value for x: ";
        cin>>x1;
        cout<<"enter a value for y: ";
        cin>>y1;
        p.set(x1, y1);
        cout<<"("<<p.getX()<<","<<p.getY()<<")"<<endl;
        cout<<"how much do you want to move the x-value: ";
        cin>>xMove;
        cout<<"how much do you want to move the y-value: ";
        cin>>yMove;
        p.move(xMove, yMove);
        cout<<"("<<p.getX()<<","<<p.getY()<<")"<<endl;
        p.rotate();
        cout<<"rotation of point: ("<<p.getX()<<","<<p.getY()<<")"<<endl;
        cout<<"Do you want to make anoter point? (enter y or n): ";
        cin>>userAnswer;
        if(userAnswer == 'n')
        {
            runAgain = false;
        }
    }
    while(runAgain);
    
    return 0;
}

void Point::set(int x, int y)
{
    //member function that sets the private data after an object of this class is created
    xCor = x; 
    yCor = y;
}

void Point::move(int x, int y)
{
    //moves the point by an amount x and y
    xCor += x;
    yCor += y;
}

void Point::rotate()
{
    //rotate the point 90 degrees clockwise around the origin
    if((xCor > 0 && yCor > 0) || (xCor < 0 && yCor < 0))
    {
        int temp = xCor;
        xCor = -yCor;
        yCor = temp;
    }
    else if((xCor < 0 && yCor > 0) || (xCor > 0 && yCor < 0))
    {
        int temp = xCor;
        xCor = yCor;
        yCor = -temp;
    }
}

int Point:: getX() const
{
    //const inspector function to retreive current coordinate's x-value
    return xCor;
}

int Point::getY() const
{
    //const inspector function to retreive current coordinate's y-value
    return yCor;
}