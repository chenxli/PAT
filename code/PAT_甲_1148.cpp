#include <cstdio>
#include <cmath>
using namespace std;
int id[102];
int main()
{
  int n;
  scanf("%d",&n);
  for(int i = 1; i <= n; i++)
    scanf("%d",&id[i]);
  for(int i = 1; i < n; i++)
  {
    for(int j = i + 1; j <= n; j++)
    {
      int f1 = 0, f2 = 0;
      for(int k = 0; k <= n; k++)
      {
        int temp = abs(id[k]);
        //狼人i说谎
        if(k == i)
        {
          if((temp != j && id[k] < 0) || (temp == j && id[k] > 0))
           f1++;
        }
        //狼人j说谎
        if(k == j)
        {
          if((temp != i && id[k] < 0) || (temp == i && id[k] > 0))
           f1++;
        }
        //人类说谎
        if(k != i && k != j)
        {
          if(temp == i || temp == j)
          {
            if(id[k] > 0)
             f2++;
          }
          else
          {
            if(id[k] < 0)
              f2++;
          }
        }
      }
      if(f1 == 1 && f2 == 1)
      {
        printf("%d %d\n",i,j);
        return 0;
      }
    }
  }
  printf("No Solution\n");
  return 0;
}
