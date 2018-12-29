#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
  //观察规律
  int n;
  scanf("%d",&n);
  double sum = 0;
  for(int i = 0; i < n; i++)
  {
    double num;
    scanf("%lf",&num);
    sum += num * (i + 1) * (n- i);
  }
  printf("%.2lf\n",sum);
  return 0;
}
