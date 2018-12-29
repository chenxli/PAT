#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;
int main()
{
  int d,n;
  scanf("%d%d",&d,&n);
  vector<int> v;
  v.push_back(d);
  for(int i = 1; i < n; i++)
  {
    vector<int> temp;
    temp.push_back(v[0]);
    int count = 1;
    for(int j = 1; j < v.size(); j++)
    {
      if(v[j] == v[j-1])
        count++;
      else
      {
        temp.push_back(count);
        temp.push_back(v[j]);
        count = 1;
      }
    }
    temp.push_back(count);
    v.clear();
    v = temp;
    temp.clear();
  }
  for(int i = 0; i < v.size(); i++)
  {
    printf("%d",v[i]);
  }
  return 0;
}
