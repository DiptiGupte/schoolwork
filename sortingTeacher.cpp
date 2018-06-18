#include <iostream>
#include <string>
#include <fstream>
#include <map>

using namespace std;

class Teacher
{
public:
  Teacher(multimap<string, string> report);
  void printReport();   //for hw5
  void sort(ifstream& ifs, string column, string direction);
private:
  void printSortedName();
  void printSortedQuestion();
  multimap<string, string> r;
  string students[30];    //main function generates student names numbered 1 - 30
  string questionTopic[9];    //main funtion generates 9 different topics students can ask
};

Teacher::Teacher(multimap<string, string> report)
{
  r = report;
}

void Teacher::printReport()
{
  ofstream of;
  of.open("report.txt");
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
  of<<"\t"<<"number of times student attended office hours: "<<count<<endl;
  of<<endl;
  of.close();
}

void Teacher::sort(ifstream& ifs, string column, string direction)
{
  if(column == "students")
  {
    string name = "x", temp;
    int index = 0;
    //inputing names into array
    while(ifs >> temp)
    {
      if(temp == "Student1" || temp == "Student2" || temp == "Student3" || temp == "Student4" || temp == "Student5" || temp == "Student6" || temp == "Student7" || temp == "Student8" || temp == "Student9" || temp == "Student10"
          || temp == "Student11" || temp == "Student12" || temp == "Student13" || temp == "Student14" || temp == "Student15" || temp == "Student16" || temp == "Student17" || temp == "Student18" || temp == "Student19" || temp == "Student20"
          || temp == "Student21" || temp == "Student22" || temp == "Student23" || temp == "Student24" || temp == "Student25" || temp == "Student26" || temp == "Student27" || temp == "Student28" || temp == "Student29" || temp == "Student30")
      {
          if(temp == name)
          {
            continue;
          }
          else
          {
            name = temp;
            students[index] = name;
            index++;
          }
      }
    }
    //sorting
    for(int i = 1; i < 30; i++)
    {
      //finding posistion to insert
      int insertionIndex = i;
      for(int j = insertionIndex - 1; j >=0; j--)
      {
        int i1, i2;
        string s1 = students[j], s2 = students[i];
        if(s1.length() == 8)  //Student1 through Student9
        {
          s1 = s1.substr(7,1);
          i1 = stoi(s1, nullptr, 10);
        }
        else
        {
          s1 = s1.substr(7,2);
          i1 = stoi(s1, nullptr, 10);
        }
        if(s2.length() == 8)  //Student1 through Student9
        {
          s2 = s2.substr(7,1);
          i2 = stoi(s2, nullptr, 10);
        }
        else
        {
          s2 = s2.substr(7,2);
          i2 = stoi(s2, nullptr, 10);
        }
        if(direction == "ascending")
        {
          if(i1 > i2)
          {
            insertionIndex = j;
          }
        }
        else  //decending
        {
          if(i1 < i2)
          {
            insertionIndex = j;
          }
        }
      }
      //insertion
      string temp = students[i];
      for(int k = i; k > insertionIndex; k--)
      {
        students[k] = students[k - 1];
      }
      students[insertionIndex] = temp;
    }
    printSortedName();
  }
  else if(column == "question")
  {
    string temp;
    int index = 0;
    bool addToArray;
    //inputing questions into array
    while(ifs >> temp)
    {
      if(index == 9)
      {
        break;
      }
      addToArray = true;
      if(temp == "arrays" || temp == "linkedlists" || temp == "stacks" || temp == "queues" || temp == "binarytrees" || temp == "btrees" || temp == "multimaps" || temp == "heaps" || temp == "priorityqueues")
      {
        for(int i = 0; i < index; i++)
        {
          if(temp.compare(questionTopic[i]) == 0)
          {
            addToArray = false;
          }
        }
        if(addToArray)
        {
          questionTopic[index] = temp;
          index++;
        }
      }
    }
    //sorting
    for(int i = 1; i < 9; i++)
    {
      //finding posistion to insert
      int insertionIndex = i;
      for(int j = insertionIndex - 1; j >=0; j--)
      {
        int stringIndex = 0;
        string q1 = questionTopic[j], q2 = questionTopic[i];
        while(stringIndex < q1.length() && stringIndex < q2.length())
        {
          if(q1[stringIndex] != q2[stringIndex])
          {
            break;
          }
          stringIndex++;
        }
        if(direction == "ascending")
        {
          if(q1 > q2)
          {
            insertionIndex = j;
          }
        }
        else  //decending
        {
          if(q1 < q2)
          {
            insertionIndex = j;
          }
        }
      }
      //insertion
      string insert = questionTopic[i];
      for(int k = i; k > insertionIndex; k--)
      {
        questionTopic[k] = questionTopic[k - 1];
      }
      questionTopic[insertionIndex] = insert;
    }
    printSortedQuestion();
  }
}

void Teacher::printSortedName()
{
  ofstream of;
  of.open("sorted.txt");
  multimap<string, string>::iterator i;
  string name;
  int count = 1;
  for(int j = 0; j < 30; j++)
  {
    name = students[j];
    if(j == 0)
    {
      of<<name<<endl;
      of<<"\t"<<"topics asked:"<<endl;
    }
    else
    {
      of<<"\t"<<"number of times student attended office hours: "<<count<<endl;
      of<<endl;
      count = 1;
      name = students[j];
      of<<name<<endl;
      of<<"\t"<<"topics asked:"<<endl;
    }
    for(i = r.begin(); i != r.end(); i++)
    {
      if(i->first == name)
      {
        of<<"\t"<<"\t"<<i->second<<endl;
        count++;
      }
    }
    of<<"\t"<<"number of times student attended office hours: "<<count<<endl;
    of<<endl;
  }
  of.close();
}

void Teacher::printSortedQuestion()
{
  ofstream of;
  of.open("sorted.txt");
  multimap<string, string>::iterator i;
  string question;
  int count = 1;
  for(int j = 0; j < 9; j++)
  {
    question = questionTopic[j];
    if(j == 0)
    {
      of<<"Topic: "<<question<<endl;
      of<<"\t"<<"students who asked:"<<endl;
    }
    else
    {
      of<<"\t"<<"number of times topic was asked: "<<count<<endl;
      of<<endl;
      count = 1;
      question = questionTopic[j];
      of<<"Topic: "<<question<<endl;
      of<<"\t"<<"students who asked:"<<endl;
    }
    string student = "x";
    for(i = r.begin(); i != r.end(); i++)
    {
      if(i->second == question)
      {
        if(i->first != student)
        {
          of<<"\t"<<"\t"<<i->first<<endl;
          student = i->first;
        }
        count++;
      }
    }
  }
  of<<"\t"<<"number of times topic was asked: "<<count<<endl;
  of.close();
}
