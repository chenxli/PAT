#include <cstdio>
#include <cmath>
using namespace std;
int main()
{
  int num;
  scanf("%d",&num);
  int maxlen = 0;
  int first = 0;
  for(int i = 1; i <= 12; i++)
  {
    for(int j = 2; j < sqrt(num); j++)
    {
      int ans = 1;
      int temp = j;
      for(int k = 0; k < i; k++)
      {
        ans *= temp;
        temp++;
      }
      if(num % ans == 0)
      {
        if(i > maxlen)
        {
          maxlen = i;
          first = j;
        }
      }
    }
  }
  if(maxlen == 0)
  {
    printf("1\n%d\n",num);
  }
  else
  {
    printf("%d\n",maxlen);
    int cnt = 0;
    for(int i = 0; i < maxlen; i++)
    {
      if(cnt == 0)
      {
        printf("%d",first+i);
        cnt++;
      }
      else
        printf("*%d",first+i);
    }
    printf("\n");
  }
  return 0;
}
