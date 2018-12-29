#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
int left_max[100001],right_min[100001];
int main()
{
  int n;
  scanf("%d",&n);
  vector<int> v;
  for(int i = 0; i < n; i++)
  {
    int val;
    scanf("%d",&val);
    v.push_back(val);
  }
  vector<int> vv;
  left_max[0] = v[0];
  for(int i = 1; i < v.size(); i++)
  {
    if(left_max[i-1] < v[i])
       left_max[i] = v[i];
    else
      left_max[i] = left_max[i-1];
  }
  right_min[v.size()-1] = v[v.size()-1];
  for(int i = v.size() - 2; i >= 0; i--)
  {
    if(v[i] < right_min[i+1])
      right_min[i] = v[i];
    else
      right_min[i] = right_min[i+1];
  }
  for(int i = 0; i < v.size(); i++)
  {
    if(v[i] >= left_max[i] && v[i] <= right_min[i])
      vv.push_back(v[i]);
  }
  sort(vv.begin(),vv.end());
  printf("%d\n",vv.size());
  for(int i = 0; i < vv.size(); i++)
  {
    if(i == 0)
      printf("%d",vv[i]);
    else
      printf(" %d",vv[i]);
  }
  printf("\n");
  return 0;
}
