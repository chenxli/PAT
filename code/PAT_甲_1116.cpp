#include <cstdio>
#include <iostream>
using namespace std;
int vis[10001] = {0};
int arr[10001] = {0};
bool isPrime(int n)
{
  if(n == 1) return false;
  if(n == 2) return true;
  for(int i =2; i*i <= n; i++)
  {
    if(n % i == 0)
      return false;
  }
  return true;
}

int main()
{
  int n;
  scanf("%d",&n);
  for(int i = 0; i < n; i++)
  {
    int id;
    scanf("%d",&id);
    arr[id] = i + 1;
  }
  int m;
  scanf("%d",&m);
  for(int i = 0; i < m; i++)
  {
    int id;
    scanf("%d",&id);
    if(vis[id] == 0)
    {
      if(arr[id] == 0)
        printf("%04d: Are you kidding?\n",id);
      else if(arr[id] == 1)
        {
          printf("%04d: Mystery Award\n",id);
          vis[id] = 1;
        }
      else if(isPrime(arr[id]))
        {
          printf("%04d: Minion\n",id);
          vis[id] = 1;
        }
      else
        {
          printf("%04d: Chocolate\n",id);
          vis[id]=1;
        }
    }
    else
    {
      printf("%04d: Checked\n",id);
    }
  }
  return 0;
}
