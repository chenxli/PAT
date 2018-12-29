#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;
bool cmp(int a,int b)
{
  return a > b;
}
int main()
{
  int num;
  scanf("%d",&num);
  vector<int> v(num);
  for(int i = 0; i < num; i++)
  {
    scanf("%d",&v[i]);
  }
  sort(v.begin(),v.end(),cmp);
  int m = 0, n = 0;
  for(int i = 1; i * i <= num; i++)
  {
    if(num % i == 0)
    {
      n = i;
      m = num / i;
    }
  }
  // int** arr = new int* [m+1];
  // for(int i = 0; i < m + 1; i++)
  // {
  //   arr[i] = new int [n+1];
  // }
  int arr[m][n];
  for(int i = 0; i < m; i++)
  {
    for(int j = 0; j <n; j++)
       arr[i][j] = 0;
  }
  int k = 0;
  int i = 0,j = -1;
  while(k < v.size())
  {
    while(!arr[i][j+1] && j + 1 < n && k < v.size()) arr[i][++j] = v[k++];
    while(!arr[i+1][j] && i + 1 < m && k < v.size()) arr[++i][j] = v[k++];
    while(!arr[i][j-1] && j - 1 >= 0 && k < v.size()) arr[i][--j] = v[k++];
    while(!arr[i-1][j] && i - 1 >=0 && k < v.size()) arr[--i][j] = v[k++];
  }
  for(int x = 0; x < m; x++)
  {
    printf("%d",arr[x][0]);
    for(int y = 1; y < n; y++)
    {
      printf(" %d",arr[x][y]);
    }
    printf("\n");
  }
  return 0;
}
