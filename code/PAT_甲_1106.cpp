#include <cstdio>
#include <vector>
#include <cmath>
#include <map>
#include <algorithm>
using namespace std;
map<int,vector<int>> v;
int minLen = 100001;
int nowLen = 0;
int counts = 0;
int n;
void dfs(int start)
{
  if(v[start].size() == 0)
  {
    if(nowLen < minLen)
    {
      minLen = nowLen;
      counts = 1;
    }
    else if(nowLen == minLen)
      counts++;
    return;
  }
  for(int i = 0; i < v[start].size(); i++)
  {
    nowLen++;
    dfs(v[start][i]);
    nowLen--;
  }
}
int main()
{
  double price,r;
  scanf("%d%lf%lf",&n,&price,&r);
  for(int i = 0; i < n; i++)
  {
    int k;
    scanf("%d",&k);
    for(int j = 0; j < k; j++)
    {
      int child;
      scanf("%d",&child);
      v[i].push_back(child);
    }
  }
  dfs(0);
  double minPrice = price * pow((1+r/100.0),minLen);
  printf("%.4lf %d\n",minPrice,counts);
  return 0;
}
