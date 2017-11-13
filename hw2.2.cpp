#include <iostream>
#include <cmath>
using namespace std;
int main(){
    double a, b, c;		              //used Double 
    b=2;				     //put 2=b; 
    cout<<"Enter length of hypotenuse"<<endl;
    cin>>c;                                  //put endl
    cout<<"Enter length of a side"<<endl;    //put >> after cout
    cin>>a;
    double intermediate = pow(c, 2)-pow(a, 2);
    b = sqrt(intermediate);
    cout<<"Length of other side is:"<< b<<endl;    //didn't include << between the string and b
                                                   //put endline instead of endl
    return 0;
}
