#include <iostream>
#include <cstdio>
#include <map>
using namespace std;
int main()
{
  int n;
  scanf("%d",&n);
  map<int,int> mapping;
  for(int i = 0; i < n; i++)
  {
    int a;
    scanf("%d",&a);
    if(a > 0)
      mapping[a] = 1;
  }
  int x = 1;
  while(mapping.find(x) != mapping.end())
  {
    x++;
  }
  printf("%d\n",x);
  return 0;
}
