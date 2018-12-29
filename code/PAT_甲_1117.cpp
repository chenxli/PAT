#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
  int n;
  scanf("%d",&n);
  vector<int> v;
  for(int i = 0; i < n; i++)
  {
    int a;
    scanf("%d",&a);
    v.push_back(a);
  }
  sort(v.begin(),v.end());
  int E = v.size();
  while(E)
  {
    if(v[n-E] <= E)
      E--;
    else
     break;
  }
  printf("%d\n",E);
  return 0;
}
