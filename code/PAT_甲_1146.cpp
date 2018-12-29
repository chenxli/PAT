#include <cstdio>
#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
int edge[1001][1001];
int degree[1001];
bool isTopo(vector<int> v,int* deg)
{
  for(int i = 0; i < v.size(); i++)
  {
    if(deg[v[i]] == 0)
    {
      for(int j = 1; j <= v.size(); j++)
      {
        if(edge[v[i]][j])
          deg[j]--;
      }
    }
    else
        return false;
   }
  return true;
}
int main()
{
  int n,m;
  scanf("%d%d",&n,&m);
  for(int i = 0; i < m; i++)
  {
    int a,b;
    scanf("%d%d",&a,&b);
    edge[a][b] = 1;
    degree[b]++;
  }
  int k;
  scanf("%d",&k);
  vector<int> v;
  vector<int> cnt;
  for(int i = 0; i < k; i++)
  {
    v.clear();
    for(int j = 0; j < n; j++)
    {
        int point;
        scanf("%d",&point);
        v.push_back(point);
      }
     int arr[1001];
     memcpy(arr,degree,sizeof(degree));
     if(!isTopo(v,arr))
     {
        cnt.push_back(i);
     }
  }
  for(int i = 0; i < cnt.size(); i++)
  {
    if(i == 0)
      printf("%d",cnt[i]);
    else
      printf(" %d",cnt[i]);
  }
  return 0;
}
