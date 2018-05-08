#include <iostream>
#include <cstdlib>    //srand, rand
#include <ctime>   //time

using namespace std;

class Student
{
public:
  Student(int s, int q, int p);
  unsigned int questionTime();
  void enter(unsigned int s);
  unsigned int arrivalTime();
  void waitTime(unsigned int w);
  unsigned int getWait();
  unsigned int getPriority() const;
private:
  unsigned int question, start, wait, priority;
};

//bool operator<(const Student lhs, const Student rhs);

Student::Student(int s, int q, int p)
{
  start = s;
  question = q;
  priority = p;
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
/*
bool operator<(const Student& lhs, const Student& rhs)
{
  return lhs.getPriority() < rhs.getPriority();
}
*/

struct ComparePriority
{
    bool operator()(Student const& s1, Student const& s2)
    {
        return s1.getPriority() < s2.getPriority();
    }
};
