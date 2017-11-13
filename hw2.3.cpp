#include <iostream>
#include <string>
using namespace std;

int main(){
    char day;
    cout<<"Enter the day of the week."<< endl;
    cin>>day;
    switch(day){
        case 'M':   //monday
            cout<<"CSCI 10 at 1:00, PHIL 11A at 2:15, MATH 12 at 4:45"<<endl;
            break;
        case 'T':   //tuesday
            cout<<"PHYS 2 at 12:10, CSCI 10 lab at 2:15"<<endl;
            break;
        case 'W':    //Wednesday
            cout<<"CSCI 10 at 1:00, PHIL 11A at 2:15, MATH 12 at 4:45"<<endl;
            break;
        case 'R':   //thursday
            cout<<"PHYS 2 at 12:10"<<endl;
            break;
        case 'F':   //friday
            cout<<"CSCI 10 at 1:00, PHIL 11A at 2:15, MATH 12 at 4:45"<<endl;
            break;
        default:
            cout<<"no classes today"<<endl;
    }
    return 0;
}