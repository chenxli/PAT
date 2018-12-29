#include <cstdio>
#include <vector>
#include <cmath>
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
  double sum = v[0];
  for(int i = 1; i < v.size(); i++)
  {
    sum = sum * 1.0 / 2 + v[i] * 1.0 / 2;
  }
  int res = sum;
  printf("%d\n",res);
  return 0;
}
