#include <iostream>
#include <cstdio>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
int main()
{
  int n;
  scanf("%d",&n);
  vector<int> v;
  vector<int> res;
  map<int,int> mymap;
  for(int i = 0; i < n; i++)
  {
    int id1,id2;
    scanf("%d%d",&id1,&id2);
    mymap[id1] = id2;
    mymap[id2] = id1;
  }
  int m;
  scanf("%d",&m);
  for(int i = 0; i < m; i++)
  {
    int id;
    scanf("%d",&id);
    v.push_back(id);
  }
  for(int i = 0; i < m; i++)
  {
    int id = v[i];
    if(mymap.find(id) == mymap.end())
      res.push_back(id);
    else if(find(v.begin(),v.end(),mymap[id]) == v.end())
      res.push_back(id);
  }
  printf("%d\n",res.size());
  sort(res.begin(),res.end());
  for(int i = 0; i < res.size(); i++)
  {
    printf("%05d",res[i]);
    if(i != res.size() - 1)
    {
      printf(" ");
    }
  }
  return 0;
}
