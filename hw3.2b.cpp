#include <iostream>
using namespace std;

int main(){
    int scoreSum = 0;
    int numberOfScores = 0;
    double average;
    int score;
    
    cout<<"Enter score (enter -1 when complete): ";
    cin>>score;
    while(score != -1)
    {
        while(score < -1 || score > 30)
        {
            cout<<"Invalid score. enter new score: ";
            cin>>score;
        }
        scoreSum += score;
        numberOfScores++;
        cout<<"Enter score (enter -1 when complete): ";
        cin>>score;
    }
    average = scoreSum/numberOfScores;
    cout<<"The average is "<<average<<endl;
    return 0;
}