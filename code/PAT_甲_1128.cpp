#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;
bool isvalid(vector<int> v)
{
  for(int i = 0; i < v.size(); i++)
  {
    for(int k = 1; k + i < v.size(); k++)
    {
      if(v[i] == v[k+i] - k || v[i] == v[i+k] + k || v[i] == v[k+i])
        return false;
    }
  }
  return true;
}
int main()
{
  int n;
  scanf("%d",&n);
  while(n--)
  {
    vector<int> v;
    int m;
    scanf("%d",&m);
    for(int i = 0; i < m; i++)
    {
      int a;
      scanf("%d",&a);
      v.push_back(a);
    }
    if(isvalid(v))
      printf("YES\n");
    else
      printf("NO\n");
  }
}
