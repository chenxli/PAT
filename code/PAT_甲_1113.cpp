#include <cstdio>
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
    int val;
    scanf("%d",&val);
    v.push_back(val);
  }
  sort(v.begin(),v.end());
  int sum1 = 0, sum2 = 0;
  for(int i = 0; i < n / 2; i++)
  {
    sum1 += v[i];
  }
  for(int i = n / 2; i < n; i++)
  {
    sum2 += v[i];
  }
  if(n % 2 == 0)
  {
    printf("0 %d\n",sum2-sum1);
  }
  else
  {
    printf("1 %d\n",sum2-sum1);
  }
  return 0;
}
