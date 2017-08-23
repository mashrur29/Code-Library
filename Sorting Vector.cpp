#include<bits/stdc++.h>
using namespace std;
vector<int>a;

bool myfunction(int i,int j)
{
    return (i<j);
}

struct myclass
{
    bool operator() (int i,int j) {return (i<j);}
}myobject;

int main()
{
  int p;
  for(int i=0;i<5;i++)
  {
      cin>>p;
      a.push_back(p);
  }
   sort(a.begin(),a.end(),myfunction); /* using function as comp */
  // sort(a.begin(),a.end());  /* using default comparison operator */
  // sort(a.begin(),a.end(),myobject); /* using object as comp */
  for(int i=0;i<5;i++)
  {
      cout<<a[i]<<" ";
  }
  return 0;
}
