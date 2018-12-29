#include <iostream>
#include <cstdio>
using namespace std;
int deg[501];
int edge[501][501];
int vis[501];
int n,m;
void dfs(int start)
{
  for(int i = start; i <= n; i++)
  {
    if(edge[start][i] == 1 && !vis[i])
    {
      vis[i] = 1;
      dfs(i);
    }
  }
}
int main()
{
  scanf("%d%d",&n,&m);
  for(int i = 0; i < m; i++)
  {
    int a,b;
    scanf("%d%d",&a,&b);
    edge[a][b] = edge[b][a] = 1;
    deg[a]++;
    deg[b]++;
  }
  vis[1] = 1;
  dfs(1);
  bool flag = true;
  int count = 0;
  for(int i = 1; i <= n; i++)
  {
    printf("%d",deg[i]);
    if(i < n)
      printf(" ");
    if(deg[i] % 2 == 1)
    {
      flag = false;
      count++;
    }
  }
  printf("\n");
  for(int i = 1; i <= n; i++)
  {
    if(vis[i] == 0)
    {
      printf("Non-Eulerian\n");
      return 0;
    }
  }
  if(flag)
  {
    printf("Eulerian\n");
  }
  else if(!flag && count == 2)
  {
    printf("Semi-Eulerian\n");
  }
  else
  {
    printf("Non-Eulerian\n");
  }
  return 0;
}
