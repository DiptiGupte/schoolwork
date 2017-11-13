#include <iostream>

using namespace std;

struct student
{
    double quiz1;
    double quiz2;
    double midterm;
    double finalExam;
    double percentQ1;
    double percentQ2;
    double percentM;
    double percentF;
};

void percentQuiz1(student& s);
void percentQuiz2(student& s);
void percentMidterm(student& s);
void percentFinal(student& s);
void averageAndLetter(student s);

int main()
{
    student stu;
    cout<<"Enter the score for the first quiz (out of 10): ";
    cin>>stu.quiz1;
    cout<<"Enter the score for the second quiz (out of 10): ";
    cin>>stu.quiz2;
    cout<<"Enter the score for the midterm (out of 100): ";
    cin>>stu.midterm;
    cout<<"Enter the score for the final (out of 100): ";
    cin>>stu.finalExam;
    
    cout<<"Student record: "<<endl;
    percentQuiz1(stu);
    percentQuiz2(stu);
    percentMidterm(stu);
    percentFinal(stu);
    averageAndLetter(stu);
}

void percentQuiz1(student& s)
{
    s.percentQ1 = (s.quiz1 / 10) * 100;
    cout<<"quiz 1: "<<s.percentQ1<<"%"<<endl;;
}

void percentQuiz2(student& s)
{
    s.percentQ2 = (s.quiz2 / 10) * 100;
    cout<<"quiz 2: "<<s.percentQ2<<"%"<<endl;;
}

void percentMidterm(student& s)
{
    s.percentM = (s.midterm / 100) * 100;
    cout<<"midterm: "<<s.percentM<<"%"<<endl;
}

void percentFinal(student& s)
{
    s.percentF = (s.finalExam / 100) * 100;
    cout<<"final: "<<s.percentF<<"%"<<endl;
}

void averageAndLetter(student s)
{
    double avg = (((s.percentQ1+s.percentQ2)/2)*.25)+(s.percentM*.25)+(s.percentF*.5);
    cout<<"average: "<<avg<<"%"<<endl;
    if(avg>=90)
    {
        cout<<"letter grade: A"<<endl;
    }
    else if(avg<90 && avg>=80)
    {
        cout<<"letter grade: B"<<endl;
    }
    else if(avg<80 && avg>=70)
    {
        cout<<"letter grade: C"<<endl;
    }
    else if(avg<70 && avg>=60)
    {
        cout<<"letter grade: D"<<endl;
    }
    else
    {
        cout<<"letter grade: F"<<endl;
    }
}