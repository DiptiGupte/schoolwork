#include <iostream>
using namespace std;

int main(){
    int scores[100];
    int numberOfScores = 0;
    double average, total;
    int highestScore = 0;
    int lowestScore = 30;
    
    cout<<"Enter score (enter -1 when complete): ";
    cin>>scores[numberOfScores];
    while(scores[numberOfScores] != -1)
    {
        while(scores[numberOfScores] < -1 || scores[numberOfScores] > 30)
        {
            cout<<"Invalid score. enter new score: ";
            cin>>scores[numberOfScores];
        }
        if(scores[numberOfScores] > highestScore)
        {
            highestScore = scores[numberOfScores];
        }
        if(scores[numberOfScores] < lowestScore)
        {
            lowestScore = scores[numberOfScores];
        }
        numberOfScores++;
        cout<<"Enter score (enter -1 when complete): ";
        cin>>scores[numberOfScores];
    }
    for(int i = 0; i < numberOfScores; i++)
    {
        total += scores[i];
    }
    average = total/numberOfScores;
    cout<<"The average is "<<average<<endl;
    cout<<"The highest score is "<<highestScore<<endl;
    cout<<"The lowest score is "<<lowestScore<<endl;
    return 0;
}