#include <iostream>
#include <cstdio>
#include <vector>
#include <cmath>
#include <map>
using namespace std;
map<int,vector<int>> mymap;
int max_level = 0;
int n;
int level[100001];
void dfs(int root)
{
  if(mymap[root].size() == 0)//叶子
  {
    if(level[root] > max_level)
      max_level = level[root];
  }
  for(int i = 0; i < mymap[root].size(); i++)
  {
    int child = mymap[root][i];
    level[child] = level[root] + 1;
    dfs(child);
  }
}
int main()
{
  double p,r;
  scanf("%d %lf %lf",&n,&p,&r);
  int root;
  for(int i = 0; i < n; i++)
  {
    int father;
    scanf("%d",&father);
    if(father == -1)
      root = i;
    else
      mymap[father].push_back(i);
  }
  dfs(root);
  int count = 0;
  for(int i = 0; i < n; i++)
  {
    if(level[i] == max_level)
      count++;
  }
  double price = p * pow(1+r*0.01,max_level);
  printf("%.2lf %d\n",price,count);
  return 0;
}
