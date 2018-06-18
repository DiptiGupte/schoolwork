#include <iostream>
#include <cstdlib>    //srand, rand
#include <ctime>   //time
#include <string>

using namespace std;

class Student
{
public:
  Student(int s, int q, int p, string n, string t);
  unsigned int questionTime();
  void enter(unsigned int s);
  unsigned int arrivalTime();
  void waitTime(unsigned int w);
  unsigned int getWait();
  unsigned int getPriority() const;
  string getName();
  string getTopic();
private:
  unsigned int question, start, wait, priority;
  string name, topic;
};

Student::Student(int s, int q, int p, string n, string t)
{
  start = s;
  question = q;
  priority = p;
  name = n;
  topic = t;
}

unsigned int Student::questionTime()
{
  return question;
}

void Student::enter(unsigned int s)
{
  start = s;
}

unsigned int Student::arrivalTime()
{
  return start;
}

void Student::waitTime(unsigned int w)
{
  wait = w;
}

unsigned int Student::getWait()
{
  return wait;
}

unsigned int Student::getPriority() const
{
  return priority;
}

string Student::getName()
{
  return name;
}

string Student::getTopic()
{
  return topic;
}

struct ComparePriority
{
  bool operator()(Student const& s1, Student const& s2)
    {
        return s1.getPriority() < s2.getPriority();
    }
};
