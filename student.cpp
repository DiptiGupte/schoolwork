#include <iostream>
#include <cstdlib>    //srand, rand
#include <ctime>   //time

using namespace std;

class Student
{
public:
  Student(int x, int y);
  unsigned int questionTime();
  void enter(unsigned int x);
  unsigned int arrivalTime();
  void waitTime(unsigned int x);
  unsigned int getWait();
private:
  unsigned int q, start, w;
};

Student::Student(int x, int y)
{
  q = y;
  start = x;
}

unsigned int Student::questionTime()
{
  return q;
}

void Student::enter(unsigned int x)
{
  start = x;
}

unsigned int Student::arrivalTime()
{
  return start;
}

void Student::waitTime(unsigned int x)
{
  w = x;
}

unsigned int Student::getWait()
{
  return w;
}
