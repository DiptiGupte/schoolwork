#include <iostream>
#include <cstdlib>
#include <ctime>
#include <queue>
#include <map>
#include "multimapStudent.cpp"
#include <fstream>

using namespace std;

void officeHours(unsigned int& ot, unsigned int& aw, unsigned int& aq, multimap<string, string>& report);
bool probability();   //probability that a student will enter queue at some minute t
string randomName();
string randomTopic();

int main()
{
  ofstream of;
  of.open("report.txt");
  unsigned int ot = 0, aw = 0, aq = 0;
  multimap<string, string> r;
  srand((unsigned)time(NULL));
  for(int i = 0; i < 100; i++)
  {
    officeHours(ot, aw, aq, r);
  }
  aq = aq / 100;
  ot = ot / 100;
  aw = aw / 100;
  cout<<"Average time professor spent with each student: "<<aq<<" min."<<endl;
  cout<<"Average overtime: "<<ot<<" min."<<endl;
  cout<<"Average wait time: "<<aw<<" min."<<endl;

  multimap<string, string>::iterator i;
  string name;
  int count = 1;
  for(i = r.begin(); i != r.end(); i++)
  {
    //to get first name in list
    if(i == r.begin())
    {
      name = i->first;
      of<<name<<endl;
      of<<"\t"<<"topics asked:"<<endl;
      of<<"\t"<<"\t"<<i->second<<endl;
    }
    else
    {
      if(i->first == name)
      {
          of<<"\t"<<"\t"<<i->second<<endl;
          count++;
      }
      else  //different name came up
      {
        of<<"\t"<<"number of times student attended office hours: "<<count<<endl;
        of<<endl;
        count = 1;
        name = i->first;
        of<<name<<endl;
        of<<"\t"<<"topics asked:"<<endl;
        of<<"\t"<<"\t"<<i->second<<endl;
      }
    }
  }
  of.close();
  return 0;
}

void officeHours(unsigned int& ot, unsigned int& aw, unsigned int& aq, multimap<string, string>& report)
{
  //students who come to office hours
  priority_queue<Student, vector<Student>, ComparePriority> temp;
  //multimap<string, string> report; //<name, topic>
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
      unsigned int q, pr;
      q = rand() % 15 + 1;  //question length from 1 to 15 min
      pr = rand() % 20 + 1; //priority of student from 1 to 60
      string n = randomName();
      string to = randomTopic();
      Student s(t, q, pr, n, to);
      temp.push(s);
      report.insert(pair<string, string>(s.getName(), s.getTopic()));
    }
  }

  //inputing wait times into student objects
  priority_queue<Student, vector<Student>, ComparePriority> sQueue;
  unsigned int numOfStudents = 1;
  int wait = 0;
  unsigned int previous_arrival, previous_question_time, previous_wait;
  Student s2(0,0,0, "x", "t");
  while(!temp.empty())
  {
    s2 = temp.top();
    if(numOfStudents == 1)
    {
      previous_arrival = s2.arrivalTime();
      previous_question_time = s2.questionTime();
      previous_wait = wait;
      s2.waitTime(wait);
      sQueue.push(s2);
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
      sQueue.push(s2);
      temp.pop();
      numOfStudents++;
    }
  }

  unsigned int office_hour = 0, overtime = 0, averageWait = 0, averageQuestion = 0;
  Student s3(0,0,0, "x", "t");
  //first student
  s3 = sQueue.top();
  averageWait += s3.getWait();
  averageQuestion += s3.questionTime();
  office_hour += s3.questionTime() + s3.arrivalTime();
  sQueue.pop();
  //rest of queue
  while(!sQueue.empty())
  {
    s3 = sQueue.top();
    if(office_hour <= 60)
    {
      averageWait += s3.getWait();
      averageQuestion += s3.questionTime();
      office_hour += s3.questionTime();
      sQueue.pop();
    }
    else
    {
      averageWait = s3.getWait();
      averageQuestion += s3.questionTime();
      overtime += s3.questionTime();
      sQueue.pop();
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

string randomName()
{
  int x = rand() % 30 + 1;
  string stu = "Student " + to_string(x);
  return stu; //returns a random student from 1 to 30
}

string randomTopic()
{
  string topic[9] = {"arrays", "linked-lists", "stacks", "queues", "binary trees", "b-trees", "multimaps", "heaps", "priority queues"};
  int i = rand() % 9;
  return topic[i];
}
