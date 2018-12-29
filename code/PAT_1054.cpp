#include <iostream>
#include <cstdio>
#include <map>
#include <string>
using namespace std;
int main()
{
  int n,m;
  cin>>n>>m;
  map<int,int> Map;
  int max = -1;
  int val;
  for(int i = 0; i < m; i++)
  {
     for(int j = 0; j < n; j++)
     {
       int s;
       scanf("%d",&s);
       Map[s]++;
       if(Map[s] > max)
        {
          max = Map[s];
          val = s;
        }
     }
  }
  cout<<val<<endl;
  return 0;
}
