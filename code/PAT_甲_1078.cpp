#include <iostream>
#include <cstring>
#include <cstdio>
#include <cstdlib>
using namespace std;
bool isPrime(int n)
{
  if(n == 1) return false;
  if(n == 2) return true;
  for(int i = 2; i * i <= n; i++)
  {
    if(n % i == 0)
      return false;
  }
  return true;
}
int main()
{
  int maxSize,num;
  cin>>maxSize>>num;
  while(!isPrime(maxSize))
  {
    maxSize++;
  }
  int *arr = new int [maxSize];
  memset(arr,0,sizeof(int)*maxSize);
  int cnt = 0;
  for(int i = 0; i < num; i++)
  {
    int value;
    scanf("%d",&value);
    if(arr[value%maxSize] == 0)
    {
      arr[value%maxSize] = 1;
      if(cnt == 0)
      {
        printf("%d",value%maxSize);
        cnt = 1;
      }
      else
        printf(" %d",value%maxSize);
    }
    else
    {
      bool find = false;
      int pos = value % maxSize;
      for(int j = 1; j <= maxSize; j++)
      {
        int tmp = (pos + j * j) % maxSize;
        if(arr[tmp] == 0)
        {
          find = true;
          arr[tmp] = 1;
          printf(" %d",tmp);
          break;
        }
      }
      if(!find)
        printf(" -");
    }
  }
  printf("\n");
  return 0;
}
