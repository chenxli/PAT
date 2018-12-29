#include <cstdio>
#include <vector>
#include <set>
using namespace std;
int edge[201][201];
int n,m;
bool isHamilton(vector<int> v)
{
  int size = v.size();
  set<int> temp;
  if(size != n + 1)
    return false;
  if(v[0] != v[size-1] && size > 1)
    return false;
  for(int i = 0; i < size - 1; i++)
  {
    if(!edge[v[i]][v[i+1]])
      return false;
    if(temp.count(v[i]) != 0)
      return false;
    temp.insert(v[i]);
  }
  return true;
}
int main()
{
  scanf("%d%d",&n,&m);
  for(int i = 0; i < m; i++)
  {
    int a,b;
    scanf("%d%d",&a,&b);
    edge[a][b] = edge[b][a] = 1;
  }
  int k;
  scanf("%d",&k);
  for(int i = 0; i < k; i++)
  {
    int nn;
    scanf("%d",&nn);
    vector<int> v;
    for(int i = 0; i < nn; i++)
    {
      int vex;
      scanf("%d",&vex);
      v.push_back(vex);
    }
    if(isHamilton(v))
      printf("YES\n");
    else
      printf("NO\n");
  }
  return 0;
}
