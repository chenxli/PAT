#include <iostream>
#include <cstdio>
#include <vector>
#include <map>
#include <cstdio>
using namespace std;
int main()
{
  int n,k;
  cin>>n>>k;
  int v[100005] = {0};
  for(int i = 0; i < n; i++)
  {
    int temp;
    scanf("%d",&temp);
    v[temp]++;
  }
  for(int i = 1; i < k; i++)
  {
    if(v[i] > 0 && v[k-i] > 0)
    {
      cout<<i<<" "<<k-i<<endl;
      return 0;
    }
  }
  cout<<"No Solution"<<endl;
  return 0;
}
