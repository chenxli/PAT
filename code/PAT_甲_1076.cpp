//算法笔记
#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;
const int MAXV = 1010;
struct Node
{
  int id;
  int layer;
};
vector<Node> adj[MAXV];
bool inq[MAXV] = {false};
int bfs(int s,int l)
{
  int numForward = 0;
  queue<Node> q;
  Node start;
  start.id = s;
  start.layer = 0;
  q.push(start);
  inq[start.id] = true;
  while(!q.empty())
  {
    Node topNode = q.front();
    q.pop();
    int u = topNode.id;
    for(int i = 0; i < adj[u].size(); i++)
    {
      Node next = adj[u][i];
      next.layer = topNode.layer + 1;
      if(inq[next.id] == false && next.layer <= l)
      {
        q.push(next);
        inq[next.id] = true;
        numForward++;
      }
    }
  }
  return numForward;
}
int main()
{
  Node user;
  int n,l,numFollow,idFollow;
  scanf("%d%d",&n,&l);
  for(int i = 1; i <= n; i++)
  {
    user.id = i;
    scanf("%d",&numFollow);
    for(int j = 0; j < numFollow; j++)
    {
      scanf("%d",&idFollow);
      adj[idFollow].push_back(user);
    }
  }
  int numQuery,s;
  scanf("%d",&numQuery);
  for(int i = 0; i < numQuery; i++)
  {
    memset(inq,false,sizeof(inq));
    scanf("%d",&s);
    int numForward = bfs(s,l);
    printf("%d\n",numForward);
  }
  return 0;
}
// #include <iostream>
// #include <cstdio>
// #include <vector>
// #include <queue>
// #include <cstring>
// using namespace std;
// int user[1005][1005];
// int vis[1005];
// int n,l;
// int level[1005];
// int bfs(int queryId)
// {
//   int res = 0;
//   queue<int> q;
//   q.push(queryId);
//   vis[queryId] = 1;
//   while(!q.empty())
//   {
//     int first = q.front();
//     q.pop();
//     for(int i = 1; i <= n; i++)
//     {
//       if(user[i][first] == 1 && vis[i] == 0 && level[first] + 1 <= l)
//       {
//         vis[i] = 1;
//         level[i] = level[first] + 1;
//         q.push(i);
//         res++;
//       }
//     }
//   }
//   return res;
// }
// int main() {
//   scanf("%d %d",&n,&l);
//   for(int i = 1; i <= n; i++)
//   {
//     int m;
//     scanf("%d",&m);
//     for(int j = 0; j < m; j++)
//     {
//       int follow;
//       scanf("%d",&follow);
//       user[i][follow] = 1;
//     }
//   }
//   int num;
//   scanf("%d",&num);
//   for(int i = 0; i < num; i++)
//   {
//     int id;

//     scanf("%d",&id);
//     memset(level,0,sizeof(level));
//     memset(vis,0,sizeof(vis));
//     int res = bfs(id);
//     printf("%d\n",res);
//   }
//   return 0;
// }
