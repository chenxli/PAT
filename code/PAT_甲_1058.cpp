#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
  int g1,s1,k1,g2,s2,k2,g3,s3,k3;
  scanf("%d.%d.%d %d.%d.%d",&g1,&s1,&k1,&g2,&s2,&k2);
  if(k1 + k2 < 29)
    k3 = k1 + k2;
  else
    k3 = (k1 + k2) % 29;
  if((k1 + k2) / 29 + s1 + s2 < 17)
      s3 = s1 + s2 + (k1 + k2) / 29;
  else
      s3 = ((k1 + k2) / 29 + s1 + s2) % 17;
   g3 = g1 + g2 + ((k1 + k2) / 29 + s1 + s2) / 17;
  printf("%d.%d.%d\n",g3,s3,k3);
  return 0;
}
