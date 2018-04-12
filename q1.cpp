#include <iostream>
#include <stack>
#include <string>
#include <cctype>
#include <cstring>
#include <cstdlib>

using namespace std;

void infixToPrefix();
void prefixToInfix();

int main()
{
  infixToPrefix();
  prefixToInfix();
  return 0;
}

void infixToPrefix()
{
  string infix, temp = "";
  stack<char> c;

  cout<<"infix to prefix"<<endl;
  cout<<"enter infix expression with parentheses:"<<endl;
  getline(cin, infix);

  for(int i = infix.length() - 1; i >= 0; i--)
  {
    if(infix[i] == '+' || infix[i] == '-' || infix[i] == '/' || infix[i] == '*')
    {
      c.push(infix[i]);
    }
    else if(isalpha(infix[i]) || isdigit(infix[i]))
    {
      if(isdigit(infix[i]))
      {
        string num = "";
        while(isdigit(infix[i]) && i >=0)
        {
          num = num + infix[i];
          i--;
        }
        temp = temp + num + " ";
        i++;
      }
      else
      {
        temp = temp + infix[i] + " ";
      }
    }
    else if(infix[i] == '(')
    {
      if(i == 0)
      {
        temp = temp + c.top();
      }
      else
      {
        temp = temp + c.top() + " ";
      }
      c.pop();
    }
    else if(infix[i] == ' ' || infix[i] == ')')
    {
      continue;
    }
  }

  for(int j = temp.length() - 1; j >= 0; j--)
  {
    cout<<temp[j];
  }
  cout<<endl;
}

void prefixToInfix()
{
  string prefix, temp = "";
  stack<char> c;

  cout<<"prefix to infix"<<endl;
  cout<<"enter prefix expression."<<endl;
  cout<<"use parentheses and include spaces only between two expressions being evaluated together:"<<endl;
  getline(cin, prefix);

  for(int i = 0; i < prefix.length(); i++)
  {
    if(prefix[i] == '+' || prefix[i] == '-' || prefix[i] == '/' || prefix[i] == '*')
    {
      c.push(prefix[i]);
    }
    else if(isalpha(prefix[i]) || isdigit(prefix[i]) || prefix[i] == '(')
    {
      temp = temp + prefix[i];
    }
    else if(prefix[i] == ' ' || prefix[i] == ')')
    {
      if(!c.empty())
      {
        if(prefix[i] == ' ')
        {
          temp = temp + c.top();
        }
        else
        {
          temp = temp + prefix[i] + c.top();
        }
        c.pop();
      }
      else  //last )
      {
        temp = temp + prefix[i];
      }
    }
  }

  for(int j = 0; j < temp.length(); j++)
  {
    cout<<temp[j];
  }
  cout<<endl;
}
