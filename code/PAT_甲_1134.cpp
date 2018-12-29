#include <cstdio>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;
struct edge
{
  int start,end;
};
int main()
{
  int n,m;
  scanf("%d%d",&n,&m);
  vector<edge> arr;
  for(int i = 0; i < m; i++)
  {
    int a,b;
    scanf("%d%d",&a,&b);
    edge e;
    e.start = a;
    e.end = b;
    arr.push_back(e);
  }
  int k;
  scanf("%d",&k);
  for(int i = 0; i < k; i++)
  {
    int len;
    scanf("%d",&len);
    set<int> temp;
    int found = 0;
    for(int j = 0; j < len; j++)
    {
      int num;
      scanf("%d",&num);
      temp.insert(num);
    }
    for(int j = 0; j < m; j++)
    {
      int a = arr[j].start;
      int b = arr[j].end;
      if(temp.count(a) != 0)
        found++;
      else if(temp.count(b) != 0)
        found++;
      // if(find(temp.begin(),temp.end(),a) != temp.end())
      //   found++;
      // else if(find(temp.begin(),temp.end(),b) != temp.end())
      //   found++;
    }
    if(found == m)
      printf("Yes\n");
    else
      printf("No\n");
  }
  return 0;
}
