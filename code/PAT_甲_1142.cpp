#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
int arr[201][201];
int n,m;
void func(vector<int> v)
{
  bool isClique = true;
  for(int i = 0; i < v.size(); i++)
  {
    for(int j = i+1; j < v.size(); j++)
    {
      if(arr[v[i]][v[j]] != 1)
      {
        isClique = false;
        printf("Not a Clique\n");
        return;
      }
    }
  }
  bool isMaximal = true;
  if(isClique)
  {
    for(int i = 1; i <= n; i++)
    {
      bool isExist = false;
      for(int k = 0; k < v.size(); k++)
      {
        if(v[k] == i)
        {
          isExist = true;
          break;
        }
      }
      if(!isExist)
      {
        bool isAllConnected = true;
        for(int j = 0; j < v.size(); j++)
        {
          if(arr[i][v[j]] != 1)
          {
            isAllConnected = false;
          }
        }
        if(isAllConnected)
        {
          isMaximal = false;
          printf("Not Maximal\n");
          return;
        }
      }
    }
  }
  if(isMaximal)
    printf("Yes\n");
}
int main()
{
  scanf("%d%d",&n,&m);
  for(int i = 0; i < m; i++)
  {
    int a,b;
    scanf("%d%d",&a,&b);
    arr[a][b] = arr[b][a] = 1;
  }
  int p;
  scanf("%d",&p);
  for(int i = 0; i < p; i++)
  {
    int k;
    scanf("%d",&k);
    vector<int> v;
    for(int j = 0; j < k; j++)
    {
      int num;
      scanf("%d",&num);
      v.push_back(num);
    }
    func(v);
  }
  return 0;
}
