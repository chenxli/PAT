#include <cstdio>
#include <vector>
using namespace std;
int edge[501][501];
int cost[501][501];
int vis[501];
int minCost = 100000001;
int nowCost = 0;
int minDist = 100000001;
int nowDist = 0;
vector<int> ans;
vector<int> temp;
int n,m,s,d;
void dfs(int start)
{
  if(start == d)
  {
    if(nowDist < minDist)
    {
      minDist = nowDist;
      ans = temp;
      minCost = nowCost;
    }
    else if(nowDist == minDist)
    {
      if(nowCost < minCost)
      {
        ans = temp;
        minCost = nowCost;
      }
    }
    return;
  }
  for(int i = 0; i < n; i++)
  {
    if(edge[start][i] && vis[i] == 0)
    {
      nowDist += edge[start][i];
      vis[i] = 1;
      nowCost += cost[start][i];
      temp.push_back(i);
      dfs(i);
      nowDist -= edge[start][i];
      vis[i] = 0;
      nowCost -= cost[start][i];
      temp.pop_back();
    }
  }
}
int main()
{
  scanf("%d%d%d%d",&n,&m,&s,&d);
  for(int i = 0; i < m; i++)
  {
    int city1,city2,distance,Cost;
    scanf("%d%d%d%d",&city1,&city2,&distance,&Cost);
    edge[city1][city2] = edge[city2][city1] = distance;
    cost[city1][city2] = cost[city2][city1] = Cost;
  }
  vis[s] = 1;
  dfs(s);
  printf("%d ",s);
  for(int i = 0; i < ans.size(); i++)
  {
    printf("%d ",ans[i]);
  }
  printf("%d %d\n",minDist,minCost);
  return 0;
}
