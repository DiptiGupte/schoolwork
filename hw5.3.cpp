#include <iostream>
#include <cmath>

using namespace std;

double stddev(double a[], int size);

int main()
{
    double array[100], ans, userInput;
    int s = 0;
    cout<<"Enter a number (enter -1 when complete): ";
    cin>>userInput;
    while(userInput != -1)
    {
        array[s] = userInput;
        cout<<"Enter a number (enter -1 when complete): ";
        cin>>userInput;
        s++;
    }
    ans = stddev(array, s);
    cout<<"The standard deviation is "<<ans<<endl;
    return 0;
}

double stddev(double a[], int size)
{
    double sum = 0, m, S = 0, std_dev, differance;
    for(int i = 0; i < size; i++)
    {
        sum += a[i];
    }
    m = sum/size;
    for(int j = 0; j < size; j++)
    {
        differance = a[j] - m;
        S += pow(differance, 2);
    }
    std_dev = sqrt((S/size));
    return std_dev;
}