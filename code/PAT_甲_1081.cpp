#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;
int gcd(int a, int b)
{
  if(a < b)
  {
    int tmp = a;
    a = b;
    b = tmp;
  }
  if(b == 0)
     return a;
  else
     return gcd(b,a%b);
 }
int main()
{
  int n;
  scanf("%d",&n);
  long long pre_num = 0;
  long long pre_den = 0;
  long long temp1;
  long long temp2;
  for(int i = 0; i < n ; i++)
  {
    long int a,b;
    scanf("%ld/%ld",&a,&b);
    if(i == 0)
    {
      pre_num = a;
      pre_den = b;
      int k = gcd(abs(a),abs(b));
      if(k != 0)
      {
        pre_num /= k;
        pre_den /= k;
      }
    }
    else
    {
      temp1 = pre_num;
      temp2 = pre_den;
      pre_num = temp1 * b + temp2 * a;
      pre_den = temp2 * b;
      int k = gcd(abs(pre_num),abs(pre_den));
      if(k != 0)
      {
        pre_num /= k;
        pre_den /= k;
      }
    }
  }
  if(pre_num == 0)
  {
    printf("0\n");
    return 0;
  }
  if(pre_num / pre_den > 0)
  {
    if(pre_num % pre_den == 0)
    {
       printf("%ld",pre_num / pre_den);
    }
    else
       printf("%ld ",pre_num / pre_den);
  }
  else if(pre_num / pre_den < 0)
  {
    if(pre_num % pre_den == 0)
    {
      printf("%ld",pre_num / pre_den);
    }
    else
      printf("%ld ",pre_num / pre_den);
    pre_num = abs(pre_num);
    pre_den = abs(pre_den);
  }
  long int x = pre_num - pre_num / pre_den * pre_den;
  long int y = pre_den;
  if(x != 0)
  {
    int k = gcd(x,y);
    printf("%ld/%ld\n",x/k,y/k);
  }
  else
     printf("\n");
  return 0;
}
