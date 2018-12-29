#include <iostream>
#include <set>
#include <cstdio>
#include <map>
using namespace std;
int main()
{
  int n;
  cin>>n;
  map<int,set<int> > MAP;
  for(int i = 1; i <= n; i++)
  {
    int m;
    scanf("%d",&m);
    for(int j = 0; j < m; j++)
    {
      int ele;
      scanf("%d",&ele);
      if(MAP[i].count(ele) == 0)
        MAP[i].insert(ele);
    }
  }
  int k;
  cin>>k;
  for(int i = 0; i < k; i++)
  {
    int a,b;
    scanf("%d %d",&a,&b);
    int len1 = MAP[a].size();
    int len2 = MAP[b].size();
    int Nc = 0,Nt = 0;
    set<int>::iterator it = MAP[a].begin();
    while(it != MAP[a].end())
    {
      if(MAP[b].find((*it))!= MAP[b].end())
        Nc++;
      it++;
    }
    Nt = len1 + len2 - Nc;
    printf("%.1lf%%\n",Nc * 100.0 / Nt);
  }
  return 0;
}
