#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn = 1020;
const int inf = 999999999;
int dist[maxn];
int road[maxn][maxn];
int vis[maxn];
int n,m,k,ds;
int minDist = inf;
int totDist = 0;
int dijstra(int start)
{
  fill(vis,vis+maxn,0);
  minDist = inf;
  totDist = 0;
  vis[start] = 1;
  for(int i = 1; i <= m + n; i++)
    dist[i] = road[start][i];
  //fill(dist,dist+maxn,inf);
  //dist[start] = 0;
  for(int i = 1; i <= m + n - 1; i++)
  {
    int min = inf;
    int index = 0;
    for(int j = 1; j <= m + n; j++)
    {
      if(dist[j] < min && !vis[j])
      {
        min = dist[j];
        index = j;
      }
    }
    if(index == 0) return -1;
    vis[index] = 1;
    if(index <= n)
    {
      if(dist[index] < minDist)
        minDist = dist[index];
      if(dist[index] > ds)
        return -1;
      else
        totDist += dist[index];
    }
    for(int j = 1; j <= m + n; j++)
    {
      if(!vis[j] && dist[j] > dist[index] + road[index][j])
        dist[j] = dist[index] + road[index][j];
    }
  }
  return 1;
}
int main()
{
  scanf("%d%d%d%d",&n,&m,&k,&ds);
  for(int i = 1; i <= m + n; i++)
  {
    for(int j = 1; j <= m + n; j++)
    {
      road[i][j] = inf;
    }
  }
  fill(vis,vis+maxn,0);
  for(int i = 0; i < k; i++)
  {
    char p1[5],p2[5];
    int dis;
    int a = 0,b = 0;
    scanf("%s %s %d",p1,p2,&dis);
    if(p1[0] != 'G')
    {
      int j = 0;
      while(p1[j] != '\0')
        a = a * 10 + (int)(p1[j++] - '0');
    }
    else
    {
      int j = 1;
      while(p1[j] != '\0')
        a = a * 10 + (int)(p1[j++] - '0');
      a = n + a;
    }
    if(p2[0] != 'G')
    {
      int j = 0;
      while(p2[j] != '\0')
        b = b * 10 + (int)(p2[j++] - '0');
    }
    else
    {
      int j = 1;
      while(p2[j] != '\0')
        b = b * 10 + (int)(p2[j++] - '0');
      b = b + n;
    }
    road[a][b] = road[b][a] = dis;
  }
  int nowDist = -1;
  int nowTotDist = 0;
  bool flag = false;
  int idx = 0;
  for(int i = 1; i <= m; i++)
  {
    int res = dijstra(i+n);
    if(res == 1)
    {
      flag = true;
      if(nowDist < minDist)
      {
        nowDist = minDist;
        nowTotDist = totDist;
        idx = i;
      }
      else if(nowDist == minDist)
      {
        if(totDist < nowTotDist)
        {
          nowTotDist = totDist;
          idx = i;
        }
      }
    }
  }
  if(!flag)
    printf("No Solution\n");
  else
  {
    printf("G%d\n",idx);
    double mean = nowTotDist * 1.0 / n;
    double temp = (double)nowDist;
    printf("%.1lf %.1lf\n",temp,mean);
  }
  return 0;
}
