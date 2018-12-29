#include<iostream>
#include<cstring>
using namespace std;
bool vis[1001]={0};
bool break_down[1001]={0};
int road[1001][1001]={0};
int n,m,k;
void dfs(int start)
{
  vis[start]=1;
    for(int j=1;j<=n;j++)
    {
      if(road[start][j]!=0&&vis[j]==0&&break_down[j]==0)
       {
         vis[j]=1;
         dfs(j);
       }
    }
}
int main()
{
  cin>>n>>m>>k;
  for(int i=0;i<m;i++)
  {
    int a,b;
    cin>>a>>b;
    road[a][b]=road[b][a]=1;
  }
  for(int i=0;i<k;i++)
  {
    int con;
    cin>>con;
    break_down[con]=1;
    int count=-1;
    for(int i=1;i<=n;i++)
    {
      if(break_down[i]==0)
      {
        if(vis[i]==0)
        {
          dfs(i);
          count++;
        }
      }
    }
    break_down[con]=0;
    memset(vis,0,sizeof(vis));
    cout<<count<<endl;
  }
  return 0;
}
