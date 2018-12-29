#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;
int main()
{
  int n;
  cin>>n;
  int sum = 0;
  int d;
  vector<int> dis(n+1,0);
  for(int i = 0; i < n;i++)
  {
    cin>>d;
    dis[i+1] = sum;
    sum += d;
  }
  int m;
  cin>>m;
  while(m--)
  {
    int a,b,minlen;
    cin>>a>>b;
    if(a > b)
    {
      minlen = dis[a] - dis[b];
    }
    else
    {
      minlen = dis[b] - dis[a];
    }
    if(sum - minlen < minlen)
    {
      minlen = sum - minlen;
    }
    cout<<minlen<<endl;
  }
  return 0;
}
