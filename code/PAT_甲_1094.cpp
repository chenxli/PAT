#include <cstdio>
#include <iostream>
#include <vector>
#include <map>
using namespace std;
int generation[101];
map<int,vector<int> > mymap;

void dfs(int root)
{
  for(int i = 0; i < mymap[root].size(); i++)
  {
    generation[mymap[root][i]] = generation[root] + 1;
    dfs(mymap[root][i]);
  }
}
int main()
{
  int n,m;
  scanf("%d%d",&n,&m);
  for(int i = 0; i < m; i++)
  {
    int id,k;
    scanf("%d%d",&id,&k);
    for(int j = 0; j < k; j++)
    {
      int child;
      scanf("%d",&child);
      mymap[id].push_back(child);
    }
  }
  generation[1] = 1;
  dfs(1);
  int count[101] = {0};
  int max = 0;
  int max_gen = 0;
  for(int i = 1; i <= n; i++)
  {
    count[generation[i]]++;
    if(count[generation[i]] > max)
    {
      max = count[generation[i]];
      max_gen = generation[i];
    }
  }
  printf("%d %d\n",max,max_gen);
  return 0;
}
