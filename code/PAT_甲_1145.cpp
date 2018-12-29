#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;
bool isPrime(int num)
{
  if(num == 1) return false;
  if(num == 2) return true;
  for(int i = 2; i * i <= num; i++)
  {
    if(num % i == 0)
      return false;
  }
  return true;
}
int main()
{
  int mSize,n,m;
  scanf("%d%d%d",&mSize,&n,&m);
  while(!isPrime(mSize)) mSize++;
  vector<int> v(mSize,0);
  for(int i = 0; i < n; i++)
  {
    int num;
    scanf("%d",&num);
    int index = num % mSize;
    int r = 1;
    bool find = false;
    if(v[index] == 0)
      v[index] = num;
    else
    {
      for(int j = 0; j < mSize; j++)
      {
        int idx = (index + j * j) % mSize;
        if(v[idx] == 0)
        {
          find = true;
          v[idx] = num;
          break;
        }
      }
      if(!find)
        printf("%d cannot be inserted.\n",num);
    }
  }
  int tot = 0;
  for(int i = 0; i < m; i++)
  {
    int num;
    scanf("%d",&num);
    int index = num % mSize;
    bool find = false;
    for(int j = 0; j < mSize; j++)
    {
      tot++;
      int idx = (index + j * j) % mSize;
      if(v[idx] == num || v[idx] == 0)//找到或者不存在
      {
        find = true;
        break;
      }
    }
    if(!find)
      tot++;
    }
  float time = tot * 1.0 / m;
  printf("%.1f\n",time);
  return 0;
}
