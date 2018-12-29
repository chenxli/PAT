#include <iostream>
#include <cstdio>
#include <vector>
#include <cmath>
using namespace std;
int main()
{
  int n,m;
  cin>>n>>m;
  vector<int> sum(n+1,0);
  int minval = 100001;
  int first = 0;
  bool find = false;
  for(int i = 1; i<= n; i++)
  {
    scanf("%d",&sum[i]);
    sum[i] += sum[i-1];
    while(sum[i] - sum[first] > m)
    {
      minval = min(minval,sum[i] - sum[first]);
      first++;
    }
    if(sum[i] - sum[first] == m)
    {
      printf("%d-%d\n",first+1,i);
      find =true;
    }
  }
  if(!find)
  {
    int j = 0;
    for(int i = 1; i <= n; i++)
    {
      while(sum[i] - sum [j] > minval)
        j++;
      if(sum[i] - sum[j] == minval)
        printf("%d-%d\n",j+1,i);
    }
  }
  return  0;
}
