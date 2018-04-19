#include <iostream>
#include <cstdlib>
#include <ctime>
#include <queue>
#include "student.cpp"

using namespace std;

void officeHours(unsigned int& ot, unsigned int& aw, unsigned int& aq);
bool probability();   //probability that a student will enter queue at some minute t

int main()
{
  unsigned int ot = 0, aw = 0, aq = 0;
  srand((unsigned)time(NULL));
  for(int i = 0; i < 5; i++)
  {
    officeHours(ot, aw, aq);
  }
  aq = aq / 5;
  ot = ot / 5;
  aw = aw / 5;
  cout<<"Average time professor spent with each student: "<<aq<<" min."<<endl;
  cout<<"Average overtime: "<<ot<<" min."<<endl;
  cout<<"Average wait time: "<<aw<<" min."<<endl;
  return 0;
}

void officeHours(unsigned int& ot, unsigned int& aw, unsigned int& aq)
{
  //students who come to office hours
  queue<Student> temp;
  bool p;
  for(unsigned int t = 1; t <= 60; t++)  //1 hour
  {
    p = probability();
    if(!p)  //probability returns false
    {
      continue;
    }
    else
    {
      unsigned int q;
      q = rand() % 15 + 1;  //question length from 1 to 15 min
      Student s(t, q);
      temp.push(s);
    }
  }

  //inputing wait times into student objects
  queue<Student> s_queue;
  unsigned int numOfStudents = 1;
  int wait = 0;
  unsigned int previous_arrival, previous_question_time, previous_wait;
  Student s2(0,0);
  while(!temp.empty())
  {
    s2 = temp.front();
    if(numOfStudents == 1)
    {
      previous_arrival = s2.arrivalTime();
      previous_question_time = s2.questionTime();
      previous_wait = wait;
      s2.waitTime(wait);
      s_queue.push(s2);
      temp.pop();
      numOfStudents++;

    }
    else
    {
      wait = previous_wait + previous_question_time - (s2.arrivalTime() - previous_arrival);
      if(wait <= 0)
      {
        wait = 0;
      }
      s2.waitTime(wait);
      previous_arrival = s2.arrivalTime();
      previous_question_time = s2.questionTime();
      previous_wait = wait;
      s_queue.push(s2);
      temp.pop();
      numOfStudents++;
    }
  }

  unsigned int office_hour = 0, overtime = 0, averageWait = 0, averageQuestion = 0;
  Student s3(0,0);
  //first student
  s3 = s_queue.front();
  averageWait += s3.getWait();
  averageQuestion += s3.questionTime();
  office_hour += s3.questionTime() + s3.arrivalTime();
  s_queue.pop();
  //rest of queue
  while(!s_queue.empty())
  {
    s3 = s_queue.front();
    if(office_hour <= 60)
    {
      averageWait += s3.getWait();
      averageQuestion += s3.questionTime();
      office_hour += s3.questionTime();
      s_queue.pop();
    }
    else
    {
      averageWait = s3.getWait();
      averageQuestion += s3.questionTime();
      overtime += s3.questionTime();
      s_queue.pop();
    }
  }
  if(office_hour > 60)
  {
    office_hour = office_hour - 60;
    overtime += office_hour;
  }
  averageQuestion = averageQuestion / numOfStudents;
  averageWait = averageWait / numOfStudents;
  ot += overtime;
  aw += averageWait;
  aq += averageQuestion;
  /*
  cout<<"Average time professor spent with each student: "<<averageQuestion<<" min."<<endl;
  cout<<"Overtime: "<<overtime<<" min."<<endl;
  cout<<"Average wait time: "<<averageWait<<" min."<<endl;
  cout<<"Number of students: "<<numOfStudents<<endl;
  cout<<ot<<" "<<aw<<" "<<aq<<endl;
  cout<<endl;
  */
}

bool probability()
{
  unsigned int temp = rand() % 4 + 1;  //1/4 probability that a student will come to office hours
  if(temp == 1)
  {
    return true;
  }
  return false;
}
