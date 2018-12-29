#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
bool cmp(int a,int b)
{
  return a > b;
}
int main()
{
  int nc,np;
  cin>>nc;
  vector<int> v1;
  vector<int> v2;
  while(nc--)
  {
    int a;
    scanf("%d",&a);
    v1.push_back(a);
  }
  cin>>np;
  while(np--)
  {
    int a;
    scanf("%d",&a);
    v2.push_back(a);
  }
  sort(v1.begin(),v1.end(),cmp);
  sort(v2.begin(),v2.end(),cmp);
  int sum = 0;
  int i;
  bool flag = false;
  for(i = 0; i < v2.size() && i < v1.size(); i++)
  {
    if(v1[i] < 0 || v2[i] < 0)
    {
      flag = true;
      break;
    }
    else
     sum += v1[i] * v2[i];
  }
  if(flag)
  {
    for(i = 1; v1[v1.size() - i] < 0 && v2[v2.size() - i] < 0; i++)
    {
      sum += v1[v1.size() - i] * v2[v2.size() - i];
    }
  }
  cout<<sum<<endl;
  return 0;
}
