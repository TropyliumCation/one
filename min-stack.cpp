#include <bits/stdc++.h>
using namespace std;

class MinStack
{
public:
 stack<long long int> s;
 long long minm;
 MinStack()
 {
  minm = LLONG_MAX;
 }

 void push(int val)
 {
  long long int x = val;
  if (s.empty())
  {
   minm = val;
   s.push(val);
  }
  else if (val >= minm)
  {
   s.push(val);
  }
  else
  {
   s.push(x + (x - minm));
   minm = val;
  }
 }

 void pop()
 {

  if (s.empty())
   return;
  else if (s.top() < minm)
  {
   minm = 2 * minm - s.top();
  }
  s.pop();
 }

 int top()
 {

  if (s.top() >= minm)
   return int(s.top());
  else
   return int(minm);
 }

 int getMin() { return int(minm); }
};