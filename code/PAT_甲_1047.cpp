#include <iostream>
#include <cstdio>
#include <map>
#include <cstring>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
int main()
{
  int n,k;
  scanf("%d%d",&n,&k);
  map<int,vector<string> >  m;
  for(int i = 0; i < n; i++)
  {
    char ch[5];
    string id;
    int mm;
    scanf("%s %d",ch,&mm);
    id = string(ch);
    for(int j = 0; j < mm; j++)
    {
      int course;
      scanf("%d",&course);
      m[course].push_back(id);
    }
  }
  for(int i = 1; i <= k; i++)
  {
    printf("%d %d\n",i,m[i].size());
    sort(m[i].begin(),m[i].end());
    for(int j = 0; j <m[i].size(); j++)
    {
      printf("%s\n",m[i][j].c_str());
    }
  }
  return 0;
}
