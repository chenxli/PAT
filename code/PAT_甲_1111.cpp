#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
const int inf = 99999999;
int dis[510],Time[510],e[510][510],w[510][510],dispre[510],weight[510];
int vis[510];
vector<int> dispath,Timepath,temppath,Timepre[510];
int st,fin,minnode = inf;
void dfsdispath(int v)
{
  dispath.push_back(v);
//  printf("%d ",v);
  if(v == st) return;
  dfsdispath(dispre[v]);
}
void dfsTimepath(int v)
{
  temppath.push_back(v);
  if(v == st)
  {
    if(temppath.size() < minnode)
    {
      minnode = temppath.size();
      Timepath = temppath;
    }
  }
  for(int i = 0; i < Timepre[v].size(); i++)
    dfsTimepath(Timepre[v][i]);
  temppath.pop_back();
}
int main()
{
  fill(dis,dis+510,inf);
  fill(Time,Time+510,inf);
  fill(weight,weight+510,inf);
  fill(e[0],e[0]+510*510,inf);
  fill(w[0],w[0]+510*510,inf);
  int n,m;
  scanf("%d%d",&n,&m);
  int a,b,flag,len,t;
  for(int i = 0; i < m; i++)
  {
    scanf("%d%d%d%d%d",&a,&b,&flag,&len,&t);
    e[a][b] = len;
    w[a][b] = t;
    if(flag != 1)
    {
      e[b][a] = len;
      w[b][a] = t;
    }
  }
  scanf("%d%d",&st,&fin);
  dis[st] = 0;
  weight[st] = 0;
  //Dijsktra
  for(int i = 0; i < n; i++)
    dispre[i] = i;
  for(int i = 0; i < n; i++)
  {
    int u = -1,minn = inf;
    for(int j = 0; j < n; j++)
    {
      if(!vis[j] && dis[j] < minn)
      {
        minn = dis[j];
        u = j;
      }
    }
    if(u == -1) break;
    vis[u] = 1;
    for(int j = 0; j < n; j++)
    {
      if(!vis[j] && e[u][j] != inf)
      {
        if(e[u][j] + dis[u] < dis[j])
        {
          dis[j] = e[u][j] + dis[u];
          dispre[j] = u;
          weight[j] = weight[u] + w[u][j];
        }
        else if(e[u][j] + dis[u] == dis[j] && weight[u] + w[u][j] < weight[j])
        {
          weight[j] = weight[u] + w[u][j];
          dispre[j] = u;
        }
      }
    }
  }
  dfsdispath(fin);
  Time[st] = 0;
  fill(vis,vis+510,0);
  for(int i = 0; i < n; i++)
  {
    int u = -1,minn = inf;
    for(int j = 0; j < n; j++)
    {
      if(!vis[j] && minn > Time[j])
      {
        u = j;
        minn = Time[j];
      }
    }
    if(u == -1) break;
    vis[u] = 1;
    for(int j = 0; j < n; j++)
    {
      if(!vis[j] && w[u][j] != inf)
      {
        if(Time[u] + w[u][j] < Time[j])
        {
          Time[j] = Time[u] + w[u][j];
          Timepre[j].clear();
          Timepre[j].push_back(u);
        }
        else if(Time[u] + w[u][j] == Time[j])
        {
          Timepre[j].push_back(u);
        }
      }
    }
  }
  dfsTimepath(fin);
  printf("Distance = %d",dis[fin]);
  if(dispath == Timepath)
    printf("; Time = %d: ",Time[fin]);
  else
  {
    printf(": ");
    for(int i = dispath.size() - 1; i >= 0; i--)
    {
      printf("%d",dispath[i]);
      if(i != 0)  printf(" -> ");
    }
    printf("\nTime = %d: ",Time[fin]);
  }
  for(int i = Timepath.size() - 1; i >= 0; i--)
  {
    printf("%d",Timepath[i]);
    if(i != 0)  printf(" -> ");
  }
  return 0;
}
