#include <cstdio>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;
int father[10001];
int isRoot[10001];
void init()
{
  for(int i = 0; i < 10001; i++)
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
void Union(int a,int b)
{
  int x = findRoot(a);
  int y = findRoot(b);
  if(x >= y)
    father[x] = y;
  else
    father[y] = x;
}
int main()
{
  int n;
  scanf("%d",&n);
  init();
  set<int> sset;
  for(int i = 0; i < n; i++)
  {
    int k;
    scanf("%d",&k);
    vector<int> v;
    for(int j = 0; j < k; j++)
    {
      int bird;
      scanf("%d",&bird);
      sset.insert(bird);
      v.push_back(bird);
    }
    for(int j = 1; j < v.size(); j++)
    {
      Union(v[0],v[j]);
    }
  }
  set<int>::iterator it = sset.begin();
  for(; it != sset.end(); it++)
  {
    int id = *it;
    isRoot[findRoot(id)]++;
  }
  int ans = 0;
  for(int i = 0; i < 10001; i++)
  {
    if(isRoot[i])
      ans++;
  }
  printf("%d %d\n",ans,sset.size());
  int m;
  scanf("%d",&m);
  for(int i = 0; i < m; i++)
  {
    int a,b;
    scanf("%d%d",&a,&b);
    if(findRoot(a) == findRoot(b))
      printf("Yes\n");
    else
     printf("No\n");
  }
  return 0;
}
