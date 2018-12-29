#include <cstdio>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
using namespace std;
int father[1001];
void init()
{
  for(int i = 0; i < 1001; i++)
  {
    father[i] = i;
  }
}
int findRoot(int x)
{
  while(father[x] != x)
  {
    x = father[x];
  }
  return x;
}
void Union(int a, int b)
{
  int x = findRoot(a);
  int y = findRoot(b);
  if(x < y)
    father[y] = x;
  else
    father[x] = y;
}
int main()
{
  int n;
  scanf("%d",&n);
  init();
  vector<vector<int> > v(n+1);
  for(int i = 1; i <= n; i++)
  {
    int k;
    scanf("%d:",&k);
    for(int j = 0; j < k; j++)
    {
      int tmp;
      scanf("%d",&tmp);
      v[i].push_back(tmp);
    }
  }
  for(int i = 1; i <= n; i++)
  {
    for(int j = i + 1; j <= n; j++)
    {
      bool flag = false;
      for(int k = 0; k < v[i].size(); k++)
      {
        for(int t = 0; t < v[j].size(); t++)
        {
          if(v[i][k] == v[j][t])
          {
            Union(i,j);
            flag = true;
            break;
          }
        }
        if(flag)
          break;
      }
    }
  }
  map<int,int> mymap;
  for(int i = 1; i <= n; i++)
  {
    int fa = findRoot(i);
    mymap[fa]++;
  }
  map<int,int>::iterator it = mymap.begin();
  vector<int> vv;
  for(; it != mymap.end(); it++)
  {
    vv.push_back(it->second);
  }
  sort(vv.begin(),vv.end());
  printf("%d\n",vv.size());
  for(int i = vv.size() - 1; i >= 0; i--)
  {
    printf("%d",vv[i]);
    if(i > 0)
      printf(" ");
  }
  return 0;
}
